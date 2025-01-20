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
unsigned char count=0; 

/*
    routines 
*/
/*
    vTimer1_ISR: 
    services the timer 1 interrupt, which in this case, toggle SPEAKER bit 
    after 250us*2=500us. 
*/
void vTimer1_ISR(void) interrupt TIMER1_INT{

    count++;                            // 250us increment 

    if(count==2){ 
        count=0;                        // reset 250us increment counter 
        SPEAKER=~SPEAKER;               // toggle speaker (on/off) 
    }

}



