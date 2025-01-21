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
unsigned int count_ISR=0;               // ISR runs every 250us

/*
    routines 
*/
/*
    vTimer1_ISR: 
    services the timer 1 interrupt, which in this case, toggle SPEAKER bit 
    after 250us*2=500us. 
*/
void vTimer1_ISR(void) interrupt TIMER1_INT{

    if(INC_DEC){

        count++;                        // 250us increment 

        if(count==count_lead){          // tone frequency change 
            count_lead++; 
            SPEAKER=~SPEAKER;           // toggle speaker (on/off) 
            count=COUNT_MIN;            // reset 250us increment counter 

            // go into decrement
            if(count_lead==COUNT_MAX+1){ 
                count_lead--; 
                count=COUNT_MAX+1; 
                INC_DEC=DEC; 
            }

        }

    }
    else { 

        count--;                        // 250us decrement 

        if(count==count_lead){ 
            count_lead--; 
            SPEAKER=~SPEAKER;           // toggle speaker (on/off) 
            count=COUNT_MAX;            // reset 250us decrement counter

            // go into increment 
            if(count_lead==COUNT_MIN){ 
                count_lead++; 
                count=COUNT_MIN;  
                INC_DEC=INC; 
            }

        }

    }

}

/*
    vFrequencyChange: 


*/
void vFrequencyChange(void){ 

    

} 


/*
    vTimer1_ISR: 
    services the timer 1 interrupt, which in this case, toggle SPEAKER bit 
    after 250us*2=500us. 

void vTimer1_ISR(void) interrupt TIMER1_INT{

    if(INC_DEC){

        count++;                        // 250us increment 

        if(count==count_lead){          // tone frequency change 
            count_lead++; 
            SPEAKER=~SPEAKER;           // toggle speaker (on/off) 
            count=COUNT_MIN;            // reset 250us increment counter 

            // go into decrement
            if(count_lead==COUNT_MAX+1){ 
                count_lead--; 
                count=COUNT_MAX+1; 
                INC_DEC=DEC; 
            }

        }

    }
    else { 

        count--;                        // 250us decrement 

        if(count==count_lead){ 
            count_lead--; 
            SPEAKER=~SPEAKER;           // toggle speaker (on/off) 
            count=COUNT_MAX;            // reset 250us decrement counter

            // go into increment 
            if(count_lead==COUNT_MIN){ 
                count_lead++; 
                count=COUNT_MIN;  
                INC_DEC=INC; 
            }

        }

    }

}
*/
