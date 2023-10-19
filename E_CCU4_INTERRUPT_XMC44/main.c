/*
 * main.c
 *
 *  Created on: 2022 Feb 22 14:41:58
 *  Author: Attila
 */




#include <DAVE.h>                 //Declarations from DAVE Code Generation (includes SFR declaration)

/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. It is responsible for
 * invoking the APP initialization dispatcher routine - DAVE_Init() and hosting the place-holder for user application
 * code.
 */

int main(void)
{
  DAVE_STATUS_t status;

  status = DAVE_Init();           /* Initialization of DAVE APPs  */

  if(status != DAVE_STATUS_SUCCESS)
  {
    /* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
    XMC_DEBUG("DAVE APPs initialization failed\n");

    while(1U)
    {

    }
  }

  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  DIGITAL_IO_SetOutputLow(&DIGITAL_IO_0);
  GLOBAL_CCU4_SyncStartTriggerHigh(GLOBAL_CCU4_CCUCON_Msk);
  while(1U)
  {

  }
}

void PeriodMatchHandler(void)
{
 DIGITAL_IO_ToggleOutput(&DIGITAL_IO_0); 
}

