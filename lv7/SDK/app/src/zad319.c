#include <stdio.h>
#include "xparameters.h"
#include "xgpio.h"

void print(char *str);

int main()
{
    XGpio switches, leds;
    int switchesValue;

    //*********************************************TO DO 1*************************************************//
    //*****************Inicijalizirati GPIO kontroler za komunikaciju sa sklopkama*************************//
    XGpio_Initialize(&switches, XPAR_DIP_SWITCHES_8BITS_DEVICE_ID);
    XGpio_SetDataDirection(&switches, 1, 0xFFFFFFFF);
    //*****************************************************************************************************//

    //*********************************************TO DO 2*************************************************//
    //*****************Inicijalizirati GPIO kontroler za komunikaciju sa LE diodama************************//
    XGpio_Initialize(&leds, XPAR_LEDS_8BITS_DEVICE_ID);
    XGpio_SetDataDirection(&leds, 1, 0xFFFFFFFF);

    //*****************************************************************************************************//

    while(1)
    {
    	//*********************************************TO DO 3*************************************************//
    	//****************Pročitati stanje sklopki i spremiti u varijablu switchesValue************************//
    	switchesValue = XGpio_DiscreteRead(&switches, 1);

    	//*****************************************************************************************************//
    	xil_printf("Stanje sklopki je %d\r\n", switchesValue);

    	//*********************************************TO DO 4*************************************************//
		//****************Vrijednost sklopki prosljediti na LE diode razvojnog sustava*************************//
    	XGpio_DiscreteWrite(&leds, 1, switchesValue);

		//*****************************************************************************************************//
    }

    return 0;
}
