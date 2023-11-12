#include <stdio.h>
#include "xparameters.h"
#include "xgpio.h"
#include "myled_ip.h"
#include "mydataseparator_ip.h"

void print(char *str);

int main()
{
    XGpio switches;
    int switchesValue;

    XGpio buttons;
    int buttonsValue;

    XGpio_Initialize(&switches, XPAR_DIP_SWITCHES_8BITS_DEVICE_ID);
    XGpio_SetDataDirection(&switches, 1, 0xffffffff);

    XGpio_Initialize(&buttons, XPAR_PUSH_BUTTONS_4BITS_DEVICE_ID);
    XGpio_SetDataDirection(&buttons, 1, 0xffff);

	//***********************************************TO DO*************************************************//
	//**************Postaviti vrijednost maske mydataseparator_ip komponenete na 0b11**********************//


	//*****************************************************************************************************//

    while(1)
    {
    	switchesValue = XGpio_DiscreteRead(&switches, 1);
    	xil_printf("Stanje sklopki je 0x%x hex / %d dec\r\n",switchesValue, switchesValue);

    	buttonsValue = XGpio_DiscreteRead(&buttons, 1);
    	buttonsValue = buttonsValue%4;
    	xil_printf("Stanje buttons je 0x%x hex / %d dec\r\n",buttonsValue, buttonsValue);
    	MYLED_IP_mWriteReg(0xC3600000, 0, switchesValue);
    	MYDATASEPARATOR_IP_mWriteReg(0xCDE00000, 0, buttonsValue);
    }

    return 0;
}
