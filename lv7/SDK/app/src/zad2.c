#include <stdio.h>
#include "xparameters.h"
#include "xil_types.h"
#include "xgpio.h"

void print(char *str);

int main()
{
	u8 data = 0, temp = 0;
	int address;
	int i = 1;

	while(data != 13){
		data = XUartLite_RecvByte(XPAR_RS232_UART_1_BASEADDR);

		address = XPAR_MICRON_RAM_MEM0_BASEADDR+i*4;

		Xil_Out32LE(address, data);
		xil_printf("Primljeni podatak je: %d spremljeno na adresu: %x\r\n", data, address);
		i++;
	}
	i = 1;
	Xil_Out32LE(XPAR_MICRON_RAM_MEM0_BASEADDR, i-1);

	while(temp != 13){
		address = XPAR_MICRON_RAM_MEM0_BASEADDR+i*4;
		temp = Xil_In32LE(address);
		xil_printf("%c \r\n", temp);
		i++;
	}

    return 0;
}
