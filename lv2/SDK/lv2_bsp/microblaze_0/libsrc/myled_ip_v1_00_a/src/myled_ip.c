/*****************************************************************************
* Filename:          D:\DRS\LV2_Milicevic_Istvanic\EDK/drivers/myled_ip_v1_00_a/src/myled_ip.c
* Version:           1.00.a
* Description:       myled_ip Driver Source File
* Date:              Thu Oct 26 07:34:24 2023 (by Create and Import Peripheral Wizard)
*****************************************************************************/


/***************************** Include Files *******************************/

#include "myled_ip.h"

/************************** Function Definitions ***************************/

void SetLEDValue(int vrijednost) {
	MYLED_IP_mWriteReg(0xC3600000,0, vrijednost);
}
