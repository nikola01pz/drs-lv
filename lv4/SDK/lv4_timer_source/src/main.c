/*
 * lv4_timer_source.c
 *
 *  Created on: 30. 11. 2023.
 *      Author: student
 */

#include <stdio.h>
//***********************************************TO DO 1*************************************************//
//*******************Uklju�iti datoteke xparameters.h, xtmrctr.h, xintc.h i xgpio.h**********************//
#include "xparameters.h"
#include "xtmrctr.h"
#include "xintc.h"
#include "xgpio.h"
//******************************************************************************************************//

//definiranje konstante za redni broj timera koji se koristi (unutar timer komponente postoje dva timera)
#define TIMER_CNTR_0 0

//***********************************************TO DO 2************************************************//
//*****************************Postaviti vrijednost konstante RESET_VALUE*******************************//
#define RESET_VALUE 49999998

//******************************************************************************************************//

/********************* Prototipi funkcija *************************/
int TmrCtrIntrInit(XIntc* IntcInstancePtr,
 XTmrCtr* TmrInstancePtr,
 u16 TimerDeviceId,
 u16 IntcDeviceId,
 u16 IntrSourceId,
 u8 TmrCtrNumber);

void TimerCounterHandler(void *CallBackRef, u8 TmrCtrNumber);

//***********************************************TO DO 3*************************************************//
//*****Deklarirati varijable InterruptController (XIntc), TimerCounterInst (XTmrCtr) i leds (XGpio)******//
XIntc InterruptController;
XTmrCtr TimerCounterInst;
XGpio leds;

//******************************************************************************************************//

//***********************************************TO DO 4************************************************//
//***************************Deklarirati globalnu varijablu TimerExpired********************************//
volatile int TimerExpired;

//******************************************************************************************************//

int main(void)
{
	print("-- Start of the program! --\r\n");

	int Status;

	//***********************************************TO DO 5************************************************//
	//************************Inicijalizirati kontroler za komunikaciju s LE diodama************************//
	XGpio_Initialize(&leds, XPAR_GPIO_1_DEVICE_ID);

	XGpio_SetDataDirection(&leds, 1, 0);

	//******************************************************************************************************//

	//Poziv funkcije za inicijalizaciju timera i upravlja�a prekidima
	Status = TmrCtrIntrInit(&InterruptController,
							&TimerCounterInst,
							XPAR_DELAY_DEVICE_ID,
							XPAR_INTC_0_DEVICE_ID,
							XPAR_INTC_0_TMRCTR_0_VEC_ID,
							TIMER_CNTR_0);

	if (Status != XST_SUCCESS){
		return XST_FAILURE;
	}

	//***********************************************TO DO 6***********************************************//
	//******************************************Pokrenuti timer********************************************//
	XTmrCtr_Start(&TimerCounterInst, TIMER_CNTR_0);

	//*****************************************************************************************************//

	while (1) {

	}

	print("-- End of the program! --\r\n");
	return XST_SUCCESS;
}

/********************************************************************/
/**
* Inicijalizacija timera i upravlja�a prekidima.
* Funkcija prima sljede�e parametre:
*
* @paramIntcInstancePtr - pokaziva� na varijablu tipa XIntc,
* @paramTmrCtrInstancePtr - pokaziva� na varijablu tipa XTmrCtr,
* @paramTimerDeviceId - vrijednost konstante XPAR_<TmrCtr_instance>_DEVICE_ID iz datoteke xparameters.h,
* @paramIntcDeviceId - vrijednost konstante XPAR_<Intc_instance>_DEVICE_ID iz datoteke xparameters.h,
* @paramIntrSourceId - vrijednost konstante XPAR_<INTC_instance>_<TmrCtr_instance>_INTERRUPT_INTR iz datoteke xparameters.h,
* @paramTmrCtrNumber - redni broj timera koji se inicijalizira.
*
* @returnXST_SUCCESS ako je inicijalizacija uspje�na, a u suprotno funkcija vra�a XST_FAILURE
*
*********************************************************************/
int TmrCtrIntrInit(XIntc* IntcInstancePtr,
 XTmrCtr* TmrCtrInstancePtr,
 u16 TimerDeviceId,
 u16 IntcDeviceId,
 u16 IntrSourceId,
 u8 TmrCtrNumber)
{
	int Status;

	print("Init STARTED\r\n");

	//***********************************************TO DO 7************************************************//
	//**********Inicijalizirati timer, povratnu vrijednost funkcije spremiti u varijablu Status************//
	Status = XTmrCtr_Initialize(TmrCtrInstancePtr, XPAR_DELAY_DEVICE_ID);

	//*****************************************************************************************************//
	if (Status != XST_SUCCESS) {
		print("Timer Initialize FAILED\r\n");
		return XST_FAILURE;
	}
	print("Timer Initialize SUCCESS\r\n");

	//**********************************************TO DO 8*************************************************//
	//****Inicijalizirati upravlja� prekidima, povratnu vrijednost funkcije spremiti u varijablu Status****//
	Status = XIntc_Initialize(IntcInstancePtr, XPAR_INTC_0_DEVICE_ID);

	//*****************************************************************************************************//
	if (Status != XST_SUCCESS) {
		print("Intc Initialize FAILED\r\n");
		return XST_FAILURE;
	}
	print("Intc Initialize SUCCESS\r\n");

	/*
	 * Povezivanje upravlja�a prekida s rukovateljem prekida koji se
	 * poziva kada se dogodi prekid. Rukovatelj prekida obavlja
	 * specifi�ne zadatke vezane za rukovanje prekidima.
	 */
	Status = XIntc_Connect(IntcInstancePtr, IntrSourceId,
	 (XInterruptHandler)XTmrCtr_InterruptHandler,
	 (void *)TmrCtrInstancePtr);

	if (Status != XST_SUCCESS) {
		print("Intc Connect FAILED\r\n");
		return XST_FAILURE;
	}
	print("Intc Connect SUCCESS\r\n");

	//***********************************************TO DO 9******************************+****************//
	//***Postaviti mod rada upravlja�a prekida, povratnu vrijednost funkcije spremiti u varijablu Status***//
	Status = XIntc_Start(IntcInstancePtr, XIN_REAL_MODE);

	//*****************************************************************************************************//
	if (Status != XST_SUCCESS) {
		print("Intc Start FAILED\r\n");
		return XST_FAILURE;
	}
	print("Intc Start SUCCESS\r\n");

	//**********************************************TO DO 10******************************+****************//
	//*********************************Omogu�iti rad upravlja�a prekidima**********************************//
	XIntc_Enable(IntcInstancePtr, IntrSourceId);

	//*****************************************************************************************************//

	//Omogu�avanje microblaze prekida.
	microblaze_enable_interrupts();

	/*
	 * Postavljanje prekidne rutine koja �e biti pozvana kada se dogodi prekid
	 * od strane timera. Kao parametri predaju se pokaziva� na komponentu za
	 * koju se postavlja prekidna rutina, naziv prekidne rutine (funkcije)
	 * i pointer na timer, kako bi prekidna rutina mogla pristupiti timeru.
	 */
	XTmrCtr_SetHandler(TmrCtrInstancePtr,
	 TimerCounterHandler,
	 TmrCtrInstancePtr);

	//**********************************************TO DO 11******************************+****************//
	//*************************************Postaviti postavke timera***************************************//
	//************Omogu�iti prekide, omogu�iti auto reload, odabrati brojanje prema dolje******************//
	XTmrCtr_SetOptions(TmrCtrInstancePtr, TmrCtrNumber, XTC_INT_MODE_OPTION | XTC_AUTO_RELOAD_OPTION | XTC_DOWN_COUNT_OPTION);

	//*****************************************************************************************************//

	//**********************************************TO DO 12******************************+****************//
	//********************************Postaviti po�etnu vrijednost timera**********************************//
	XTmrCtr_SetResetValue(TmrCtrInstancePtr, TmrCtrNumber, RESET_VALUE);

	//*****************************************************************************************************//

	print("Init FINISHED\r\n");
	return XST_SUCCESS;
}

/*
 * Prekidna rutina koja se poziva kada timer generira prekid.
 * Funkcija prima pokaziva� na void parametar CallBackRef
 * koji se cast-a na pokaziva� tipa XTmrCtr.
 * Ovaj parametar je napravljen kako bi se pokazao na�in na
 * koji se unutar prekidne rutine mo�e pristupiti timer
 * komponenti i njenim funkcijama.
*/
void TimerCounterHandler(void *CallBackRef, u8 TmrCtrNumber)
{
	print("Interrupt Handler!\r\n");

	XTmrCtr *InstancePtr = (XTmrCtr *)CallBackRef;

	//**********************************************TO DO 13***********************************************//
	//*************************Deklarirati varijable timeMS (int) i uCount (uint)**************************//
	int timeMS;
	uint uCount;

	//************************************************************************************+****************//

	//**********************************************TO DO 14***********************************************//
	//*****************Brojati prekide i vrijednost prikazati na LE diodama razvojnog sustava**************//
	TimerExpired = TimerExpired +1;
	XGpio_DiscreteWrite(&leds, 1, TimerExpired);

	//*****************************************************************************************************//

	//**********************************************TO DO 15***********************************************//
	//******Dohvatiti vrijednost broja�a, izra�unati vrijeme u ms i vrijednost poslati preko UART-a********//
	uCount = XTmrCtr_GetValue(InstancePtr, TmrCtrNumber);
	timeMS = (uCount+2)/50000; // jer je 50000 000 i gore je 1000(ms)
	xil_printf("Elapsed time: %d ms\tcount: %d\r\n", timeMS, uCount);
	//************************************************************************************+****************//
}

