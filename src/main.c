/*
 * main implementation: use this 'C' sample to create your own application
 *
 */


#include "derivative.h" /* include peripheral declarations SSKEAZN64M2 */
#include "nvic.h"
#include "ics.h"
#include "printf.h"
#include "uart.h"
#include "gpio.h"

int main(void)
{
#define COUNTER_LIMIT 100

    /* Perform processor initialization */
	ICS_ConfigType ICS_set={0};		/* Declaration of ICS_setup structure */
	ICS_set.u8ClkMode=ICS_CLK_MODE_FEI;
	ICS_set.bdiv=0;
	ICS_Init(&ICS_set);             /*Initialization of clock at 48Mhz, Bus clock at 24Mhz*/


	UART_ConfigType UART_Config={{0}};

	UART_Config.sctrl1settings.bits.bM=0;  	/* 8 bit mode*/
	UART_Config.sctrl1settings.bits.bPe=0;	/* No hardware parity generation or checking*/
	UART_Config.bSbns=0;					/* One stop bit*/
	UART_Config.sctrl2settings.bits.bRe=1;	/* Enable Receiver*/
	UART_Config.sctrl2settings.bits.bTe=1;	/* Enable Transmitter*/
	UART_Config.u32SysClkHz = DEFAULT_SYSTEM_CLOCK;   	/* Bus clock in Hz*/
	UART_Config.u32Baudrate = 115200;     	/* UART baud rate */

	UART_Init(UART0,&UART_Config);			/*Initialization of UART utilities*/
    SIM_PINSEL |= SIM_PINSEL_UART0PS_MASK;  // SPI on PTE


    OUTPUT_CLEAR(PTD,PTD0);	// INB
    CONFIG_PIN_AS_GPIO(PTD,PTD0,OUTPUT);

    UART_PutChar(UART0,'A');
	//printf("\nRunning the FRDM_KEA64_PWT project.\n");

        int counter = 0;
        uint32_t cc_delay=0;

        for(;;) {       
            counter++;

        	printf("\nRunning the UART0 project.\n");
            //UART_PutChar(UART0,'A');
            OUTPUT_TOGGLE(PTD,PTD0);
            for (cc_delay=0;cc_delay<0xfffff;cc_delay++);

            if(counter > COUNTER_LIMIT) {
                counter = 0;
            }
        }

    /* to avoid the warning message for GHS: statement is unreachable*/
#if defined (__ghs__)
#pragma ghs nowarning 111
#endif
#if defined (__ICCARM__)
#pragma diag_suppress=Pe111
#endif
	return 0;
}
