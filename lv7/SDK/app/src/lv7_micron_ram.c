#include <stdio.h>
#include "xparameters.h"

void print(char *str);

int main()
{
	int i;
	int address;
	int data;

    //*********************************************TO DO 1*************************************************//
    //**************Spremiti 10 vrijednosti na odgovarajuæe adrese u Micron RAM memoriji*******************//
    for(i = 0; i < 10; i++)
    {
    	address = XPAR_MICRON_RAM_MEM0_BASEADDR+i*4;
    	Xil_Out32LE(address, i);
    }
    //*****************************************************************************************************//

    //*********************************************TO DO 2*************************************************//
    //**************Proèitati 10 podataka s odgovarajuæih adresa u Micron RAM memoriji*********************//
    for(i = 0; i < 10; i++)
    {
    	address = XPAR_MICRON_RAM_MEM0_BASEADDR+i*4;
    	data = Xil_In32LE(address);

    	xil_printf("Na memorijskoj adresi 0x%x spremljen je podatak %d\r\n", address, data);
    }
    //*****************************************************************************************************//

    return 0;
}
