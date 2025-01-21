#ifndef _DIGITAL_SPEAKER_H_ 
    #define _DIGITAL_SPEAKER_H_ 

    /*
        defines 
    */ 
    #define     TIMER1_INT  3 
    #define     DEC         0 
    #define     INC         1 
    #define     COUNT_MAX   10 
    #define     COUNT_MIN   0 

    #ifndef _DIGITAL_SPEAKER_C_
        
        // function prototypes (for external use) 
        extern void vTimer1_ISR(void); 

    #endif

#endif 



