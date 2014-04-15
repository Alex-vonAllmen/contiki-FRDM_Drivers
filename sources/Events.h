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
#include "GPIO1.h"
#include "BitIoLdd8.h"
#include "GPIO2.h"
#include "BitIoLdd9.h"
#include "GPIO3.h"
#include "BitIoLdd10.h"
#include "GPIO4.h"
#include "BitIoLdd11.h"
#include "GPIO5.h"
#include "BitIoLdd12.h"
#include "SM1.h"
#include "SMasterLdd1.h"
#include "MMA1.h"
#include "GI2C1.h"
#include "WAIT1.h"
#include "I2C1.h"
#include "CsIO1.h"
#include "IO1.h"

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

void SM1_OnRxChar(void);
/*
** ===================================================================
**     Event       :  SM1_OnRxChar (module Events)
**
**     Component   :  SM1 [SynchroMaster]
**     Description :
**         This event is called after a correct character is received.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void SM1_OnTxChar(void);
/*
** ===================================================================
**     Event       :  SM1_OnTxChar (module Events)
**
**     Component   :  SM1 [SynchroMaster]
**     Description :
**         This event is called after a character is transmitted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void SM1_OnError(void);
/*
** ===================================================================
**     Event       :  SM1_OnError (module Events)
**
**     Component   :  SM1 [SynchroMaster]
**     Description :
**         This event is called when a channel error (not the error
**         returned by a given method) occurs. The errors can be read
**         using <GetError> method.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
