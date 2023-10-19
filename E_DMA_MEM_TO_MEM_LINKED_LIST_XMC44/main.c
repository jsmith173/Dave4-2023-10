/*
 * main.c
 *
 *  Created on: 2022 Jun 17 07:09:48
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

#define BLOCK_SIZE 16
#define N_BLOCK 2

// Transmit and receive buffers
int tx_buf_arr0[BLOCK_SIZE], tx_buf_arr1[BLOCK_SIZE];
int rx_buf_arr0[BLOCK_SIZE], rx_buf_arr1[BLOCK_SIZE];
int rx_check_arr[BLOCK_SIZE];
int *rx_check = (int *)rx_check_arr;

// Other convenient globals
volatile int xfer_cmplt_cb = 0, block_count = 0;
volatile int dma_error_cb = 0;
volatile int xfer_block_cmplt = 0;
volatile int src_xfer_cmplt = 0;
volatile int dest_xfer_cmplt = 0;
volatile int multi_block = 0, single_block_count=0;
int a, b, error=0, ticks=0;

XMC_DMA_LLI_t lli0, lli1;
int* top_lli = (int*)&lli0;

#define TICKS_PER_SECOND 1000

int main(void)
{
  DAVE_STATUS_t status;
  int i, j, k;

  for (i = 0; i < BLOCK_SIZE; i++) {
   tx_buf_arr0[i] = i;
  }
  for (i = 0; i < BLOCK_SIZE; i++) {
   tx_buf_arr1[i] = 100+i;
  }
  for (i = 0; i < BLOCK_SIZE; i++) {
   rx_check_arr[i] = 100+i;
  }

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
  DMA_CH_t* dma_ch;
  dma_ch = &DMA_CH_0;
  XMC_DMA_t* dma = dma_ch->dma_global->dma;
  GPDMA_CH_t* ch = &dma[dma_ch->ch_num];
  
  XMC_DMA_LLI_t* p_lli = &lli0;

  p_lli->src_addr = &tx_buf_arr0[0];  
  p_lli->dst_addr = &rx_buf_arr0[0];  
  p_lli->llp = &lli1;
  p_lli->control = ch->CTLL;
  p_lli->block_size = ch->CTLH;
  
  p_lli = &lli1;
  p_lli->src_addr = &tx_buf_arr1[0];  
  p_lli->dst_addr = &rx_buf_arr1[0];  
  p_lli->llp = 0;
  p_lli->control = ch->CTLL;
  p_lli->block_size = ch->CTLH;
  
 
  SysTick_Config(SystemCoreClock / TICKS_PER_SECOND);
  while(!ticks);
  
  DMA_CH_Enable(&DMA_CH_0);
  while(1U)
  {

  }
}

void SysTick_Handler(void)
{
  ticks++;
}

void user_event_handler (XMC_DMA_CH_EVENT_t event)
{
  DMA_CH_t *dma_ch;
  int i;

  dma_ch = &DMA_CH_0;

  if((event & XMC_DMA_CH_EVENT_TRANSFER_COMPLETE) != 0)
  {
    single_block_count++;
    if(single_block_count == 1)
    {
      for (i = 0; i < BLOCK_SIZE; i++) {
	   a = rx_buf_arr1[i]; 
	   b = rx_check_arr[i]; 
	   if (a != b) 
		   error = 1;
      }		   
	  if (!error)
       DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_0);
    }
  }
}
