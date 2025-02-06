/*
    digital_speaker: 
    this module contains anything related to the speaker side of the project. 
*/
#define _DIGITAL_SPEAKER_C_ 

/*
    includes 
*/
#include "./SiLABS/c8051F000.h" 
#include "digital_speaker.h" 

/*
    routine prototypes 
*/
void vTimer1_ISR(void); 
static void vFrequencyChange(void);

/*
    sbit defintions 
*/
sbit            SPEAKER     = P1^0; 

/*
    global variables 
*/
unsigned char   count       = COUNT_MIN; 
unsigned char   count_lead  = COUNT_MIN+1; 
bit             INC_DEC     = INC; 
unsigned int    count_ISR   = ISR_COUNT;        // 500  

/*
    routines 
*/
/*
    vTimer1_ISR: 
    services the timer 1 interrupt, which in this case, toggle SPEAKER bit 
    after 100us*count. count_lead equality defines frequency of toggle and is 
    directly changed with vFrequencyChange routine.   
*/
void vTimer1_ISR(void) interrupt TIMER1_INT{ 

    if(!(--count_ISR)){                 // 100us*ISR_COUNT=50ms 
        count_ISR=ISR_COUNT;            // reset ISR run counter 
        vFrequencyChange();             // change freq after above duration
    }                   

    count++;                            // 100us increment

    if (count==count_lead){
        SPEAKER=~SPEAKER;               // toggle speaker (on/off)
        count=COUNT_MIN;                // reset 100us increment counter
    }

}

/*
    vFrequencyChange: 
    changes count_lead global variable, effectively increasing/decreasing 
    frequency of the tone. this will produce siren sound effect.  

*/
static void vFrequencyChange(void){ 

    if(INC_DEC){ 
        count_lead++;                   // effectively decreases frequency 

        // go into decrement
        if(count_lead==COUNT_MAX){ 
            count_lead--;
            INC_DEC=DEC; 
        }

    }
    else{ 
        count_lead--;                   // effectively increases frequency 

        // go into increment 
        if(count_lead==COUNT_MIN){ 
            count_lead++; 
            INC_DEC=INC; 
        }

    }

} 



