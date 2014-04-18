/* ###################################################################
**     Filename    : Events.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2014-03-21, 10:55, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
**
** ###################################################################*/
/*!
** @file Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Led_Blue.h"
#include "LEDpin1.h"
#include "BitIoLdd1.h"
#include "SysTick.h"
#include "Led_Green.h"
#include "LEDpin2.h"
#include "BitIoLdd2.h"
#include "Led_Red.h"
#include "LEDpin3.h"
#include "BitIoLdd3.h"
#include "VREG_EN.h"
#include "BitIoLdd4.h"
#include "RESET.h"
#include "BitIoLdd5.h"
#include "CSn.h"
#include "BitIoLdd6.h"
#include "GPIO0.h"
#include "BitIoLdd7.h"
#include "FIFO.h"
#include "BitIoLdd8.h"
#include "CCA.h"
#include "BitIoLdd10.h"
#include "SFD.h"
#include "BitIoLdd11.h"
#include "GPIO5.h"
#include "BitIoLdd12.h"
#include "ACCEL.h"
#include "GI2C1.h"
#include "WAIT1.h"
#include "I2C1.h"
#include "CsIO1.h"
#include "IO1.h"
#include "FIFOP.h"
#include "ExtIntLdd1.h"
#include "TPM0.h"
#include "USBD_CDC.h"
#include "USB0.h"
#include "CDC1.h"
#include "Tx1.h"
#include "Rx1.h"
#include "CS1.h"
#include "CS2.h"
#include "SPI.h"
#include "SMasterLdd1.h"

#ifdef __cplusplus
extern "C" {
#endif 


#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __Events_H*/
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.08]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/

void fifop_interrupt(void);
/*
** ===================================================================
**     Event       :  fifop_interrupt (module Events)
**
**     Component   :  FIFOP [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
