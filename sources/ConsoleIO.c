/** ###################################################################
 **     Filename    : CsIO1.c
 **     Processor   : MKL25Z128VLK4
 **     Component   : ConsoleIO
 **     Version     : Component 01.001, Driver 01.00, CPU db: 3.00.000
 **     Compiler    : GNU C Compiler
 **     Abstract    :
 **         This component generates low-level methods for redirecting console I/O to the selected UART.
 **         These methods are typically used by printf()/scanf() methods.
 **
 **     Copyright : 1997 - 2012 Freescale Semiconductor, Inc. All Rights Reserved.
 **
 **     http      : www.freescale.com
 **     mail      : support@freescale.com
 ** ###################################################################*/

#include "ConsoleIO.h"
#include <stdarg.h>
#include "UART0_PDD.h"
/*
 ** ===================================================================
 **     Method      :  __read_console
 **
 ** ===================================================================
 */
int
__read_console(__file_handle handle, unsigned char* buffer, size_t * count)
{
  size_t CharCnt = 0x00;

  (void) handle; /* Parameter is not used, suppress unused argument warning */
  for (; *count > 0x00; --*count)
    {
      /* Clear error flags */
      UART0_PDD_ClearInterruptFlags(UART0_BASE_PTR, 0x1FU);
      if ((UART0_PDD_ReadInterruptStatusReg(UART0_BASE_PTR) & UART0_S1_RDRF_MASK)
          == 0x00)
        { /* Any data in receiver buffer */
          if (CharCnt != 0x00)
            { /* No, at least one char received? */
              break; /* Yes, return received char(s) */
            }
          else
            { /* Wait until a char is received */
              while ((UART0_PDD_ReadInterruptStatusReg(UART0_BASE_PTR)
                  & UART0_S1_RDRF_MASK) == 0x00)
                {
                };
            }
        }
      CharCnt++; /* Increase char counter */
      /* Save character received by UARTx device into the receive buffer */
      *buffer = (unsigned char) UART0_PDD_GetChar8(UART0_BASE_PTR);
      /* Stop reading if CR (Ox0D) character is received */
      if (*buffer == 0x0DU)
        { /* New line character (CR) received ? */
          *buffer = '\n'; /* Yes, convert LF to '\n' char. */
          break; /* Stop loop and return received char(s) */
        }
      buffer++; /* Increase buffer pointer */
    }
  *count = CharCnt;
  return (__no_io_error);
}

/*
 ** ===================================================================
 **     Method      :  CsIO1___write_console (component ConsoleIO)
 **
 **     Description :
 **         __write_console
 **         This method is internal. It is used by Processor Expert only.
 ** ===================================================================
 */
int
__write_console(__file_handle handle, unsigned char* buffer, size_t* count)
{
  size_t CharCnt = 0x00;

  (void) handle; /* Parameter is not used, suppress unused argument warning */
  for (; *count > 0x00; --*count)
    {
      /* Wait until UART is ready for saving a next character into the transmit buffer */
      while ((UART0_PDD_ReadInterruptStatusReg(UART0_BASE_PTR)
          & UART0_S1_TDRE_MASK) == 0)
        {
        };
      if (*buffer == '\n')
        {
          /* Send '\r'(0x0D) before each '\n'(0x0A). */
          /* Save a character into the transmit buffer of the UART0 device */
          UART0_PDD_PutChar8(UART0_BASE_PTR, 0x0DU);
          /* Wait until UART is ready for saving a next character into the transmit buffer */
          while ((UART0_PDD_ReadInterruptStatusReg(UART0_BASE_PTR)
              & UART0_S1_TDRE_MASK) == 0)
            {
            };
        }
      /* Save a character into the transmit buffer of the UART0 device */
      UART0_PDD_PutChar8(UART0_BASE_PTR, (unsigned char)*buffer);
      buffer++; /* Increase buffer pointer */
      CharCnt++; /* Increase char counter */
    }
  *count = CharCnt;
  return (__no_io_error);
}

/*
 ** ===================================================================
 **     Method      :  CsIO1___close_console (component ConsoleIO)
 **
 **     Description :
 **         __close_console
 **         This method is internal. It is used by Processor Expert only.
 ** ===================================================================
 */
int
__close_console(__file_handle handle)
{
  (void) handle; /* Parameter is not used, suppress unused argument warning */
  return (__no_io_error);
}

/*
 ** ===================================================================
 **     Method      :  ConsoleIO_Init
 **
 ** ===================================================================
 */
void
ConsoleIO_Init()
{
  /* SIM_SCGC4: UART0=1 */
  SIM_SCGC4 |= SIM_SCGC4_UART0_MASK;
  /* PORTA_PCR1: ISF=0,MUX=2 */
  PORTA_PCR1 = (uint32_t) ((PORTA_PCR1 & (uint32_t) ~0x01000500UL)
      | (uint32_t) 0x0200UL);
  /* PORTA_PCR2: ISF=0,MUX=2 */
  PORTA_PCR2 = (uint32_t) ((PORTA_PCR2 & (uint32_t) ~0x01000500UL)
      | (uint32_t) 0x0200UL);
  UART0_PDD_EnableTransmitter(UART0_BASE_PTR, PDD_DISABLE);
  /* Disable transmitter. */
  UART0_PDD_EnableReceiver(UART0_BASE_PTR, PDD_DISABLE);
  /* Disable receiver. */
  /* UART0_C1: LOOPS=0,DOZEEN=0,RSRC=0,M=0,WAKE=0,ILT=0,PE=0,PT=0 */
  UART0_C1 = 0x00U; /*  Set the C1 register */
  /* UART0_C3: R8T9=0,R9T8=0,TXDIR=0,TXINV=0,ORIE=0,NEIE=0,FEIE=0,PEIE=0 */
  UART0_C3 = 0x00U; /*  Set the C3 register */
  /* UART0_S2: LBKDIF=0,RXEDGIF=0,MSBF=0,RXINV=0,RWUID=0,BRK13=0,LBKDE=0,RAF=0 */
  UART0_S2 = 0x00U; /*  Set the S2 register */
  UART0_PDD_SetClockSource(UART0_BASE_PTR, UART0_PDD_PLL_FLL_CLOCK);
  UART0_PDD_SetBaudRate(UART0_BASE_PTR, 313U);
  /* Set the baud rate register. */
  UART0_PDD_SetOversamplingRatio(UART0_BASE_PTR, 3U);
  UART0_PDD_EnableSamplingOnBothEdges(UART0_BASE_PTR, PDD_ENABLE);
  UART0_PDD_EnableTransmitter(UART0_BASE_PTR, PDD_ENABLE);
  /* Enable transmitter */
  UART0_PDD_EnableReceiver(UART0_BASE_PTR, PDD_ENABLE);
  /* Enable receiver */
}
