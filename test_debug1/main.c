/*
 * main.c
 *
 *  Created on: 2023 Oct 19 09:56:44
 *  Author: Attila
 */




#include "DAVE.h"                 //Declarations from DAVE Code Generation (includes SFR declaration)

/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. It is responsible for
 * invoking the APP initialization dispatcher routine - DAVE_Init() and hosting the place-holder for user application
 * code.
 */

int a1, a[16];

void test1(void)
{
	a1=a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8];
	a1=a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8];
	a1=a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8];
	a1=a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8];
}

int main(void)
{
  DAVE_STATUS_t status;

  status = DAVE_Init();           /* Initialization of DAVE APPs  */

  if (status != DAVE_STATUS_SUCCESS)
  {
    /* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
    XMC_DEBUG("DAVE APPs initialization failed\n");

    while(1U)
    {

    }
  }

  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U)
  {
   test1();
   test1();
   test1();

  }
  
  while (1) ;
}
