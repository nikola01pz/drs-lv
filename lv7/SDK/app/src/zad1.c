#include <stdio.h>
#include "xparameters.h"
#include "xil_types.h"
#include "xgpio.h"

void print(char *str);

int main()
{
	u8 data;
    XGpio switches;
    int switchesValue;
	int address;

    XGpio_Initialize(&switches, XPAR_DIP_SWITCHES_8BITS_DEVICE_ID);
    XGpio_SetDataDirection(&switches, 1, 0xFFFFFFFF);

	while(1)
	{
		data = XUartLite_RecvByte(XPAR_RS232_UART_1_BASEADDR);
		switchesValue = XGpio_DiscreteRead(&switches, 1);

		address = XPAR_MICRON_RAM_MEM0_BASEADDR+switchesValue*4;
		Xil_Out32LE(address, switchesValue);

		xil_printf("Primljeni podatak je: %d, a ispisan kao character: %c na adresi: %x\r\n", data, data, address);

	}

    return 0;
}