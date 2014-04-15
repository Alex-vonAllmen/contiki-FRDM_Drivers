/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2014-03-21, 10:55, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file ProcessorExpert.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup ProcessorExpert_module ProcessorExpert module documentation
**  @{
*/         
/* MODULE ProcessorExpert */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
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
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END ProcessorExpert */
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
