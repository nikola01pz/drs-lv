#include <stdio.h>
#include "xparameters.h"
#include "xgpio.h"
#include "myled_ip.h"
#include "myaddsub_ip.h"

void print(char *str);

int main()
{
    XGpio switches;
    int switchesValue;

    XGpio_Initialize(&switches, XPAR_DIP_SWITCHES_8BITS_DEVICE_ID);
    XGpio_SetDataDirection(&switches, 1, 0xffffffff);

    int first;
    int second;
	//***********************************************TO DO*************************************************//
	//**************Postaviti vrijednost maske mydataseparator_ip komponenete na 0b11**********************//


	//*****************************************************************************************************//

    while(1)
    {
    	switchesValue = XGpio_DiscreteRead(&switches, 1);
    	xil_printf("Stanje sklopki je 0x%x hex / %d dec\r\n",switchesValue, switchesValue);

    	first = switchesValue % 16;
    	second = switchesValue / 16;

    	MYADDSUB_IP_mWriteReg(0xC5000000, 0, first+second);
    }

    return 0;
}
