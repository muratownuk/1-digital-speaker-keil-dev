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
sbit SPEAKER = P1^0; 

/*
    global variables 
*/
unsigned char count=COUNT_MIN; 
unsigned char count_lead=COUNT_MIN+1;
bit INC_DEC = INC;
unsigned int count_ISR=ISR_COUNT;       // ISR runs every 250us

/*
    routines 
*/
/*
    vTimer1_ISR: 
    services the timer 1 interrupt, which in this case, toggle SPEAKER bit 
    after 250us*count. count_lead equality defines frequency of toggle and is 
    directly changed with vFrequencyChange routine.   
*/
void vTimer1_ISR(void) interrupt TIMER1_INT{

    if(!(--count_ISR))                  // 250us*ISR_COUNT=25ms  
        vFrequencyChange();             // change freq after above duration   

    if(INC_DEC){ 

        count++;                        // 250us increment 

        if(count==count_lead){ 
            SPEAKER=~SPEAKER;           // toggle speaker (on/off) 
            count=COUNT_MIN;            // reset 250us increment counter 
        }

    }
    else { 

        count--;                        // 250us decrement 

        if(count==count_lead){ 
            SPEAKER=~SPEAKER;           // toggle speaker (on/off) 
            count=COUNT_MAX;            // reset 250us decrement counter
        }

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
        if(count_lead==COUNT_MAX+1){ 
            count_lead-=2;
            count=COUNT_MAX;  
            INC_DEC=DEC; 
        }

    }
    else{ 
        count_lead--;                   // effectively increases frequency 

        // go into increment 
        if(count_lead==COUNT_MIN){ 
            count_lead++; 
            count=COUNT_MIN; 
            INC_DEC=INC; 
        }

    }

} 
