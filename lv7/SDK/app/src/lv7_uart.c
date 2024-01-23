#include <stdio.h>
#include "xparameters.h"
#include "xil_types.h"

void print(char *str);

int main()
{
	u8 data;

	while(1)
	{
		//*********************************************TO DO 1*************************************************//
		//*********************************Primiti 1 bajt podataka putem UART-a********************************//

			data = XUartLite_RecvByte(XPAR_RS232_UART_1_BASEADDR);
		//*****************************************************************************************************//

		printf("Primljeni podatak je: %d, a ispisan kao character: %c\r\n", data, data);
	}

    return 0;
}
