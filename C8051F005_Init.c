/*
    C8051F005_Init: 
    this module contains all the initialization/configuration routines for     
    this project (device C8051F005). 
*/
#define _C8051F005_INIT_C_ 

/*
    includes 
*/
#include "./SiLABS/c8051F000.h"
#include "on_off.h"
#include "C8051F005_Init.h"

/*
    function prototypes 
*/
void vWatchdog(bit status); 
void vPort_Init(void); 
void vTimer1_Init(void); 

/*
    routines 
*/
/*
    vWatchdog:
    turn watchdog timer ON or OFF.

    parameters: status
        bit status: 
        pass ON(1) or OFF(0) to keep watchdog ON or OFF, respectively. 
    return    : none
*/
void vWatchdog(bit status){
    
    if(status==ON)
        return;                         // watchdog is enabled on power-on
    else{
        WDTCN=0xDE;                     // disable watchdog timer
        WDTCN=0xAD;
    }

}

/*
    vPort_Init: 
    crossbar enabled (XBARE), weak pull-ups enabled. 
    port 1 configuration: P1.0 output push-pull, P1.1-7 output open-drain. 
    port 1 initialize: P1.0 to low. everything else high and input-mode. 

    parameters: none
    return    : none
*/
void vPort_Init(void){
        
    XBR2|=0x40;                         // WEAKPUD=0, XBARE=1 
    PRT1CF|=0x01;                       // P1.0 push-pull, P1.1-7 open-drain 
    P1&=~0x01;                          // toggle P1.0 to low (SPEAKER) 
    
}

/*
    vTimer1_Init:
    timer 1 clock select SYSCLK/12 (T1M=0 - default); 
    TMOD: GATE1=0, C/T1=0, T1M1-0=10, timer 1 in mode 2; 
    timer 1 high byte loaded (for ~100us), reload value; 
    ET1=1, timer 1 interrupts enabled; 
    
*/
void vTimer1_Init(void){ 
    
    TMOD|=0x20;                         // timer 1 mode 2 
    TH1=0xF0;                           // Timer 1 reload value
    ET1=1;                              // timer 1 interrupt enable 
    TL1=TH1;                            // first initialization of timer 1 
    
}


