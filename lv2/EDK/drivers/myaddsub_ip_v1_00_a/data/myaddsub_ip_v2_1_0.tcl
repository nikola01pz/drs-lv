##############################################################################
## Filename:          D:\DRS\LV2_Milicevic_Istvanic\EDK/drivers/myaddsub_ip_v1_00_a/data/myaddsub_ip_v2_1_0.tcl
## Description:       Microprocess Driver Command (tcl)
## Date:              Thu Oct 26 09:54:07 2023 (by Create and Import Peripheral Wizard)
##############################################################################

#uses "xillib.tcl"

proc generate {drv_handle} {
  xdefine_include_file $drv_handle "xparameters.h" "myaddsub_ip" "NUM_INSTANCES" "DEVICE_ID" "C_BASEADDR" "C_HIGHADDR" 
}
