
/**
 * @file dma_ch.h
 * @date 2021-01-08
 *
 * NOTE:
 * This file is generated by DAVE. Any manual modification done to this file will be lost when the code is regenerated.
 *
 * @cond
 ***********************************************************************************************************************
 * DMA_CH v4.1.10 - Perform single and multi-block data transfer using the GPDMA module
 *
 * Copyright (c) 2015-2020, Infineon Technologies AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,are permitted provided that the
 * following conditions are met:
 *
 *   Redistributions of source code must retain the above copyright notice, this list of conditions and the  following
 *   disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *   following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *   Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
 *   products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * To improve the quality of the software, users are encouraged to share modifications, enhancements or bug fixes
 * with Infineon Technologies AG (dave@infineon.com).
 ***********************************************************************************************************************
 *
 * Change History
 * --------------
 *
 * 2015-02-20:
 *     - Initial version <br>
 *
 * 2015-04-15:
 *     - Handle src/dst address updates with new APIs in DMA LLD <br>
 *     - Documentation updates <br>
 *
 * 2015-05-20:
 *     - Some of the functions are now static inline <br>
 *     - Type changes in formal arguments <br>
 *
 * 2015-06-20:
 *     - Added new API DMA_CH_Reload() <br>
 * 
 * 2015-11-12:
 *     - Updated the example code for DMA_CH_Reload() API.
 *
 * 2021-01-08:
 *     - Modified check for minimum XMCLib version
 *
 * @endcond
 */
 
#ifndef DMA_CH_H
#define DMA_CH_H

/***********************************************************************************************************************
 * HEADER FILES
 **********************************************************************************************************************/

#include "xmc_dma.h"

#include "DAVE_Common.h"
#include "GLOBAL_DMA/global_dma.h"

/**********************************************************************************************************************
 * MACROS
 **********************************************************************************************************************/
#define DMA_CH_XMC_LIB_MAJOR_VERSION 2
#define DMA_CH_XMC_LIB_MINOR_VERSION 0
#define DMA_CH_XMC_LIB_PATCH_VERSION 0

#if !((XMC_LIB_MAJOR_VERSION > DMA_CH_XMC_LIB_MAJOR_VERSION) ||\
      ((XMC_LIB_MAJOR_VERSION == DMA_CH_XMC_LIB_MAJOR_VERSION) && (XMC_LIB_MINOR_VERSION > DMA_CH_XMC_LIB_MINOR_VERSION)) ||\
      ((XMC_LIB_MAJOR_VERSION == DMA_CH_XMC_LIB_MAJOR_VERSION) && (XMC_LIB_MINOR_VERSION == DMA_CH_XMC_LIB_MINOR_VERSION) && (XMC_LIB_PATCH_VERSION >= DMA_CH_XMC_LIB_PATCH_VERSION)))
#error "DMA_CH requires XMC Peripheral Library v2.0.0 or higher"
#endif

/**********************************************************************************************************************
 * ENUMERATIONS
 **********************************************************************************************************************/

/**
 * @ingroup DMA_CH_enumerations
 * @{
 */
  
/**
 * @brief Describe return status of DMA_CH APP functions
 */
typedef enum DMA_CH_STATUS_t
{
  DMA_CH_STATUS_SUCCESS = 0U, /**< DMA operation successful */
  DMA_CH_STATUS_FAILURE,      /**< DMA operation failure */
  DMA_CH_STATUS_CHANNEL_BUSY  /**< DMA channel busy */
} DMA_CH_STATUS_t;

/**
 * @}
 */
 
/**********************************************************************************************************************
 * DATA STRUCTURES
 **********************************************************************************************************************/
 
/**
 * @ingroup DMA_CH_datastructures
 * @{
 */

/**
 * @brief DMA channel configuration structure
 */
typedef struct DMA_CH_CONFIG
{
  XMC_DMA_CH_CONFIG_t ch_config; /**< A pointer to DMA channel configuration */
  XMC_DMA_CH_EVENT_HANDLER_t callback; /**< User callback for DMA events */
  uint32_t events; /**< DMA events */
} DMA_CH_CONFIG_t;

/**
 * @brief DMA_CH APP structure
 */
typedef struct DMA_CH_t
{
  GLOBAL_DMA_t *const dma_global; /**< A pointer to GLOBAL_DMA handle structure */
  DMA_CH_CONFIG_t *const config; /**< A pointer to DMA_CH configuration structure */
  void (*reload)(struct DMA_CH_t *obj);
  uint8_t ch_num; /**< Channel number */
} DMA_CH_t;

/**
 * @}
 */

/* Support for C++ */
#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************************************************************
 * API PROTOTYPES
 **********************************************************************************************************************/
 
/**
 * @ingroup DMA_CH_apidoc
 * @{
 */

/**
 * @brief Get DMA_CH APP version
 * @return DAVE_APP_VERSION_t APP version details (major, minor and patch number)
 *
 * \par<b>Description: </b><br>
 * The function can be used to check application software compatibility with a
 * specific version of the APP.
 *
 * Example Usage:
 *
 * @code
 * #include "DAVE.h"
 *
 * int main(void)
 * {
 *   DAVE_APP_VERSION_t version;
 *
 *   // Initialize DMA_CH APP. The GLOBAL_DMA APP
 *   // is initialized in the DMA_CH initialization
 *   // routine
 *   DAVE_Init();
 *
 *   version = DMA_CH_GetAppVersion();
 *   if (version.major != 4U)
 *   {
 *     // Probably, not the right version.
 *   }
 *
 *   // More code here
 *   while(1)
 *   {
 *   }
 *   return (0);
 * }
 * @endcode<BR> </p>
 */
DAVE_APP_VERSION_t DMA_CH_GetAppVersion(void);

/**
 * @brief Enable DMA channel
 * @param obj A pointer to DMA_CH_t, pointing to the DMA_CH handle configuration
 * @return None
 *
 * \par<b>Description: </b><br>
 * The function enables a DMA channel. All DMA transactions are triggered when the
 * channels are enabled.
 *
 * Example Usage:
 *
 * @code
 * #include "DAVE.h"
 *
 * int main(void)
 * {
 *   DAVE_STATUS_t status;
 *
 *   status = DAVE_Init();
 *
 *   if (status == DAVE_STATUS_SUCCESS)
 *   {
 *     DMA_CH_Enable(&DMA_CH_0);
 *   }
 *   else
 *   {
 *     // Something went wrong.
 *     while (1U);
 *   }
 *
 *   // More code here.
 *   while (1U);
 *
 *   return 1;
 * }
 * @endcode<BR> </p>
 */
__STATIC_INLINE void DMA_CH_Enable(DMA_CH_t *const obj)
{
  XMC_ASSERT("DMA_CH_Enable: NULL DMA_CH_t object", (obj != NULL));

  XMC_DMA_CH_Enable(obj->dma_global->dma, obj->ch_num);
}

/**
 * @brief Disable DMA channel
 * @param obj A pointer to DMA_CH_t, pointing to the DMA_CH handle configuration
 * @return None
 *
 * \par<b>Description: </b><br>
 * The function disables a DMA channel. All DMA transactions are stopped when the
 * channels are disabled.
 *
 * Example Usage:
 *
 * @code
 * #include "DAVE.h"
 *
 * //
 * // The configuration structures DMA_CH_0_CONFIG & DMA_CH_0 must look like this:
 * //
 * // DMA_CH_CONFIG_t DMA_CH_0_CONFIG =
 * // {
 * //   {
 * //     {
 * //       .enable_interrupt = true, // Interrupts enabled
 * //       .dst_transfer_width = XMC_DMA_CH_TRANSFER_WIDTH_32, // Destination transfer width
 * //       .src_transfer_width = XMC_DMA_CH_TRANSFER_WIDTH_32, // Source transfer width
 * //       .dst_address_count_mode = XMC_DMA_CH_ADDRESS_COUNT_MODE_INCREMENT, // Destination address count mode
 * //       .src_address_count_mode = XMC_DMA_CH_ADDRESS_COUNT_MODE_INCREMENT, // Source address count mode
 * //       .dst_burst_length = XMC_DMA_CH_BURST_LENGTH_1, // Destination burst length
 * //       .src_burst_length = XMC_DMA_CH_BURST_LENGTH_1, // Source burst length
 * //       .enable_src_gather = false, // Source gather enabled?
 * //       .enable_dst_scatter = false, // Destination scatter enabled?
 * //       .transfer_flow = XMC_DMA_CH_TRANSFER_FLOW_M2M_DMA, // Transfer flow
 * //     },
 * //     .block_size = 16U, // Block size
 * //     .transfer_type = XMC_DMA_CH_TRANSFER_TYPE_MULTI_BLOCK_SRCADR_CONTIGUOUS_DSTADR_RELOAD, // Transfer type
 * //     .priority = XMC_DMA_CH_PRIORITY_0, // Priority level
 * //     .src_handshaking = XMC_DMA_CH_SRC_HANDSHAKING_SOFTWARE, // Source handshaking
 * //     .dst_handshaking = XMC_DMA_CH_DST_HANDSHAKING_SOFTWARE  // Destination handshaking
 * //   },
 * //   user_event_handler,
 * //   XMC_DMA_CH_EVENT_ERROR | XMC_DMA_CH_EVENT_BLOCK_TRANSFER_COMPLETE | XMC_DMA_CH_EVENT_TRANSFER_COMPLETE
 * // };
 * //
 * // DMA_CH_t DMA_CH_0 =
 * // {
 * //   .dma_global = &GLOBAL_DMA_0, // Which DMA_GLOBAL instance?
 * //   .config = &DMA_CH_0_CONFIG, // Channel configuration
 * //   .ch_num = 0U, // Channel number
 * // };
 *
 * uint32_t tx_buf[256];
 * uint32_t rx_buf[256];
 *
 * volatile uint8_t xfer_cmplt_cb = 0, block_count = 0;
 * volatile uint8_t dma_error_cb = 0;
 * volatile uint8_t xfer_block_cmplt = 0;
 * volatile uint8_t src_xfer_cmplt = 0;
 * volatile uint8_t dest_xfer_cmplt = 0;
 * volatile uint8_t multi_block = 0;
 *
 * void user_event_handler (XMC_DMA_CH_EVENT_t event)
 * {
 *   DMA_CH_t *dma_ch;
 *   dma_ch = &DMA_CH_0;
 *
 *   // Check and update the volatile flags
 *   event = XMC_DMA_CH_GetEventStatus(dma_ch->dma_global->dma, dma_ch->ch_num);
 *   if ((event & XMC_DMA_CH_EVENT_ERROR) != 0)
 *   {
 *     dma_error_cb = 1;
 *   }
 *   else if ((event & XMC_DMA_CH_EVENT_TRANSFER_COMPLETE) != 0)
 *   {
 *     xfer_cmplt_cb = 1;
 *     if (multi_block)
 *     {
 *       block_count++;
 *       DMA_CH_Disable(dma_ch);
 *     }
 *   }
 *   else if ((event & XMC_DMA_CH_EVENT_BLOCK_TRANSFER_COMPLETE) != 0)
 *   {
 *     xfer_block_cmplt = 1;
 *     block_count++;
 *     if (block_count == 3)
 *     {
 *       XMC_DMA_CH_RequestLastMultiblockTransfer(dma_ch->dma_global->dma, dma_ch->ch_num);
 *     }
 *   }
 *   else if ((event & XMC_DMA_CH_EVENT_SRC_TRANSACTION_COMPLETE) != 0)
 *   {
 *     src_xfer_cmplt = 1;
 *   }
 *   else if ((event & XMC_DMA_CH_EVENT_DST_TRANSACTION_COMPLETE) != 0)
 *   {
 *     dest_xfer_cmplt = 1;
 *   }
 * }
 *
 * int main (void)
 * {
 *   DAVE_STATUS_t status;
 *   uint8_t i = 0;
 *
 *   status = DAVE_Init();
 *
 *   for(i = 0; i < 100; i++)
 *   {
 *     tx_buf[i] = i;
 *   }
 *
 *   if (status == DAVE_STATUS_SUCCESS)
 *   {
 *     DMA_CH_Enable(&DMA_CH_0);
 *   }
 *   else
 *   {
 *     while(1U);
 *   }
 *
 *   while (1U);
 *
 *   return 1;
 * }
 * @endcode<BR> </p>
 */
__STATIC_INLINE void DMA_CH_Disable(DMA_CH_t *const obj)
{
  XMC_ASSERT("DMA_CH_Disable: NULL DMA_CH_t object", (obj != NULL));

  XMC_DMA_CH_Disable(obj->dma_global->dma, obj->ch_num);
}

/**
 * @brief Check if a DMA channel is enabled
 * @param obj A pointer to DMA_CH_t, pointing to the DMA_CH handle configuration
 * @return bool "true" if enabled, "false" otherwise
 *
 * \par<b>Description: </b><br>
 * The function checks if the given DMA channel is enabled.
 *
 * Example Usage:
 *
 * @code
 * #include "DAVE.h"
 *
 * int main(void)
 * {
 *   DAVE_STATUS_t status;
 *
 *   status = DAVE_Init();
 *
 *   if (status == DAVE_STATUS_SUCCESS)
 *   {
 *     if (DMA_CH_IsEnabled(&DMA_CH_0) == false)
 *     {
 *       DMA_CH_Enable(&DMA_CH_0);
 *     }
 *   }
 *   else
 *   {
 *     // Something went wrong.
 *     while (1U);
 *   }
 *
 *   // More code here.
 *   while (1U);
 *
 *   return 1;
 * }
 * @endcode<BR> </p>
 */
__STATIC_INLINE bool DMA_CH_IsEnabled(DMA_CH_t *const obj)
{
  XMC_ASSERT("DMA_CH_IsEnabled: NULL DMA_CH_t object", (obj != NULL));

  return XMC_DMA_CH_IsEnabled(obj->dma_global->dma, obj->ch_num);
}

/**
 * @brief Suspend DMA channel
 * @param obj A pointer to DMA_CH_t, pointing to the DMA_CH handle configuration
 * @return None
 *
 * \par<b>Description: </b><br>
 * The function suspends the DMA channel
 *
 * Example Usage:
 *
 * @code
 * #include "DAVE.h"
 *
 * uint32_t tx_buf[4096];
 * uint32_t rx_buf[4096];
 *
 * volatile uint8_t xfer_cmplt_cb = 0;
 * volatile uint8_t dma_error_cb = 0;
 * volatile uint8_t xfer_block_cmplt = 0;
 *
 * void dma_ch_event_handler (XMC_DMA_CH_EVENT_t e)
 * {
 *   uint32_t event = 0;
 *   DMA_CH_t *dma_ch;
 *
 *   dma_ch = &DMA_CH_0;
 *
 *   // Check and update the volatile flags
 *   event = XMC_DMA_CH_GetEventStatus(dma_ch->dma_global->dma, dma_ch->ch_num);
 *   if ((event & XMC_DMA_CH_EVENT_ERROR) != 0)
 *   {
 *     dma_error_cb = 1;
 *   }
 *   else if((event & XMC_DMA_CH_EVENT_TRANSFER_COMPLETE) != 0)
 *   {
 *     xfer_cmplt_cb = 1;
 *   }
 *   else if ((event & XMC_DMA_CH_EVENT_BLOCK_TRANSFER_COMPLETE) != 0)
 *   {
 *     xfer_block_cmplt = 1;
 *   }
 * }
 *
 * int main (void)
 * {
 *   uint32_t dma_ch_susp_res_xfer_status = 0;
 *
 *   xfer_cmplt_cb = 0;
 *   dma_error_cb = 0;
 *
 *   //
 *   // Do 16k- 4bytes single transfer. Enable channel and suspend before it hits
 *   // the xfer complete callback.
 *   //
 *   // Later, check if suspended and then resume the transfer
 *   //
 *
 *   // The user must then configure block size as 4095 and the
 *   // transfer width as XMC_DMA_CH_TRANSFER_WIDTH_32 in the UI.
 *
 *   // Enable the channel
 *   if (!DMA_CH_IsEnabled(&DMA_CH_0))
 *   {
 *     DMA_CH_Enable(&DMA_CH_0);
 *   }
 *
 *   if ((xfer_cmplt_cb == 0) && (dma_error_cb == 0))
 *   {
 *     // Suspend the channel
 *     DMA_CH_Suspend(&DMA_CH_0);
 *
 *     // Is channel suspended?
 *     if (!DMA_CH_IsSuspended(&DMA_CH_0))
 *     {
 *       dma_ch_susp_res_xfer_status++;
 *     }
 *     // Resume the channel
 *     DMA_CH_Resume(&DMA_CH_0);
 *   }
 *   else
 *   {
 *     dma_ch_susp_res_xfer_status++;
 *   }
 *
 *   while ((xfer_cmplt_cb == 0) && (dma_error_cb == 0));
 *
 *   if (xfer_cmplt_cb)
 *   {
 *     xfer_cmplt_cb = 0;
 *     // Compare the contents of source and destination memory
 *     if (memcmp(tx_buf, rx_buf, DMA_CH_0.config->ch_config.block_size) != 0)
 *     {
 *       dma_ch_susp_res_xfer_status++;
 *     }
 *   }
 *   else
 *   {
 *     dma_ch_susp_res_xfer_status++;
 *     dma_error_cb = 0;
 *   }
 *
 *   if (!dma_ch_susp_res_xfer_status)
 *   {
 *     // Success!
 *   }
 *   else
 *   {
 *     // Failed, something went wrong.
 *   }
 * }
 * @endcode<BR> </p>
 */
__STATIC_INLINE void DMA_CH_Suspend(DMA_CH_t *const obj)
{
  XMC_ASSERT("DMA_CH_Suspend: NULL DMA_CH_t object", (obj != NULL));

  XMC_DMA_CH_Suspend(obj->dma_global->dma, obj->ch_num);
}

/**
 * @brief Resume DMA channel
 * @param obj A pointer to DMA_CH_t, pointing to the DMA_CH handle configuration
 * @return None
 *
 * \par<b>Description: </b><br>
 * The function resumes the DMA channel
 *
 * Example Usage:
 *
 * @code
 * #include "DAVE.h"
 *
 * uint32_t tx_buf[4096];
 * uint32_t rx_buf[4096];
 *
 * volatile uint8_t xfer_cmplt_cb = 0;
 * volatile uint8_t dma_error_cb = 0;
 * volatile uint8_t xfer_block_cmplt = 0;
 *
 * void dma_ch_event_handler (XMC_DMA_CH_EVENT_t e)
 * {
 *   uint32_t event = 0;
 *   DMA_CH_t *dma_ch;
 *
 *   dma_ch = &DMA_CH_0;
 *
 *   // Check and update the volatile flags
 *   event = XMC_DMA_CH_GetEventStatus(dma_ch->dma_global->dma, dma_ch->ch_num);
 *   if ((event & XMC_DMA_CH_EVENT_ERROR) != 0)
 *   {
 *     dma_error_cb = 1;
 *   }
 *   else if((event & XMC_DMA_CH_EVENT_TRANSFER_COMPLETE) != 0)
 *   {
 *     xfer_cmplt_cb = 1;
 *   }
 *   else if ((event & XMC_DMA_CH_EVENT_BLOCK_TRANSFER_COMPLETE) != 0)
 *   {
 *     xfer_block_cmplt = 1;
 *   }
 * }
 *
 * int main (void)
 * {
 *   uint32_t dma_ch_susp_res_xfer_status = 0;
 *
 *   xfer_cmplt_cb = 0;
 *   dma_error_cb = 0;
 *
 *   //
 *   // Do 16k- 4bytes single transfer. Enable channel and suspend before it hits
 *   // the xfer complete callback.
 *   //
 *   // Later, check if suspended and then resume the transfer
 *   //
 *
 *   // The user must then configure block size as 4095 and the
 *   // transfer width as XMC_DMA_CH_TRANSFER_WIDTH_32 in the UI.
 *
 *   // Enable the channel
 *   if (!DMA_CH_IsEnabled(&DMA_CH_0))
 *   {
 *     DMA_CH_Enable(&DMA_CH_0);
 *   }
 *
 *   if ((xfer_cmplt_cb == 0) && (dma_error_cb == 0))
 *   {
 *     // Suspend the channel
 *     DMA_CH_Suspend(&DMA_CH_0);
 *
 *     // Is channel suspended?
 *     if (!DMA_CH_IsSuspended(&DMA_CH_0))
 *     {
 *       dma_ch_susp_res_xfer_status++;
 *     }
 *     // Resume the channel
 *     DMA_CH_Resume(&DMA_CH_0);
 *   }
 *   else
 *   {
 *     dma_ch_susp_res_xfer_status++;
 *   }
 *
 *   while ((xfer_cmplt_cb == 0) && (dma_error_cb == 0));
 *
 *   if (xfer_cmplt_cb)
 *   {
 *     xfer_cmplt_cb = 0;
 *     // Compare the contents of source and destination memory
 *     if (memcmp(tx_buf, rx_buf, DMA_CH_0.config->ch_config.block_size) != 0)
 *     {
 *       dma_ch_susp_res_xfer_status++;
 *     }
 *   }
 *   else
 *   {
 *     dma_ch_susp_res_xfer_status++;
 *     dma_error_cb = 0;
 *   }
 *
 *   if (!dma_ch_susp_res_xfer_status)
 *   {
 *     // Success!
 *   }
 *   else
 *   {
 *     // Failed, something went wrong.
 *   }
 * }
 * @endcode<BR> </p>
 */
__STATIC_INLINE void DMA_CH_Resume(DMA_CH_t *const obj)
{
  XMC_ASSERT("DMA_CH_Resume: NULL DMA_CH_t object", (obj != NULL));

  XMC_DMA_CH_Resume(obj->dma_global->dma, obj->ch_num);
}

/**
 * @brief Check if a DMA channel is suspended
 * @param obj A pointer to DMA_CH_t, pointing to the DMA_CH handle configuration
 * @return bool "true" if suspended, "false" otherwise
 *
 * \par<b>Description: </b><br>
 * The function checks if a DMA channel is suspended
 *
 * Example Usage:
 *
 * @code
 * #include "DAVE.h"
 *
 * uint32_t tx_buf[4096];
 * uint32_t rx_buf[4096];
 *
 * volatile uint8_t xfer_cmplt_cb = 0;
 * volatile uint8_t dma_error_cb = 0;
 * volatile uint8_t xfer_block_cmplt = 0;
 *
 * void dma_ch_event_handler (XMC_DMA_CH_EVENT_t e)
 * {
 *   uint32_t event = 0;
 *   DMA_CH_t *dma_ch;
 *
 *   dma_ch = &DMA_CH_0;
 *
 *   // Check and update the volatile flags
 *   event = XMC_DMA_CH_GetEventStatus(dma_ch->dma_global->dma, dma_ch->ch_num);
 *   if ((event & XMC_DMA_CH_EVENT_ERROR) != 0)
 *   {
 *     dma_error_cb = 1;
 *   }
 *   else if((event & XMC_DMA_CH_EVENT_TRANSFER_COMPLETE) != 0)
 *   {
 *     xfer_cmplt_cb = 1;
 *   }
 *   else if ((event & XMC_DMA_CH_EVENT_BLOCK_TRANSFER_COMPLETE) != 0)
 *   {
 *     xfer_block_cmplt = 1;
 *   }
 * }
 *
 * int main (void)
 * {
 *   uint32_t dma_ch_susp_res_xfer_status = 0;
 *
 *   xfer_cmplt_cb = 0;
 *   dma_error_cb = 0;
 *
 *   //
 *   // Do 16k- 4bytes single transfer. Enable channel and suspend before it hits
 *   // the xfer complete callback.
 *   //
 *   // Later, check if suspended and then resume the transfer
 *   //
 *
 *   // The user must then configure block size as 4095 and the
 *   // transfer width as XMC_DMA_CH_TRANSFER_WIDTH_32 in the UI.
 *
 *   // Enable the channel
 *   if (!DMA_CH_IsEnabled(&DMA_CH_0))
 *   {
 *     DMA_CH_Enable(&DMA_CH_0);
 *   }
 *
 *   if ((xfer_cmplt_cb == 0) && (dma_error_cb == 0))
 *   {
 *     // Suspend the channel
 *     DMA_CH_Suspend(&DMA_CH_0);
 *
 *     // Is channel suspended?
 *     if (!DMA_CH_IsSuspended(&DMA_CH_0))
 *     {
 *       dma_ch_susp_res_xfer_status++;
 *     }
 *     // Resume the channel
 *     DMA_CH_Resume(&DMA_CH_0);
 *   }
 *   else
 *   {
 *     dma_ch_susp_res_xfer_status++;
 *   }
 *
 *   while ((xfer_cmplt_cb == 0) && (dma_error_cb == 0));
 *
 *   if (xfer_cmplt_cb)
 *   {
 *     xfer_cmplt_cb = 0;
 *     // Compare the contents of source and destination memory
 *     if (memcmp(tx_buf, rx_buf, DMA_CH_0.config->ch_config.block_size) != 0)
 *     {
 *       dma_ch_susp_res_xfer_status++;
 *     }
 *   }
 *   else
 *   {
 *     dma_ch_susp_res_xfer_status++;
 *     dma_error_cb = 0;
 *   }
 *
 *   if (!dma_ch_susp_res_xfer_status)
 *   {
 *     // Success!
 *   }
 *   else
 *   {
 *     // Failed, something went wrong.
 *   }
 * }
 * @endcode<BR> </p>
 */
 __STATIC_INLINE bool DMA_CH_IsSuspended(DMA_CH_t *const obj)
 {
   XMC_ASSERT("DMA_CH_IsSuspended: NULL DMA_CH_t object", (obj != NULL));

   return XMC_DMA_CH_IsSuspended(obj->dma_global->dma, obj->ch_num);
 }

/**
 * @brief DMA_CH initialization routine
 * @param obj A pointer to ::DMA_CH_t, pointing to the configuration parameters
 * @return DMA_CH_STATUS_t
 *
 * \par<b>Description: </b><br>
 * The function initializes the requested DMA channel and enables DMA events
 * The function is automatically called from within DAVE_Init();  An explicit
 * call to this function is not always required.
 * Note: In case the user wants to change the channel configuration, the user
 * must manipulate the generated configuration structure and initialize
 * the DMA_CH again by using DMA_CH_Init(). <br>
 * Note: Should there be changes in the DMA channel configuration parameters,
 * (for reconfiguration) changes shall first be made in the configuration structure.
 * DMA_CH_Init() shall then be invoked to cement the changes in the parameters. <br>
 * Post the DMA_CH_Init() invocation, DMA_CH_SetSourceAddress(),
 * DMA_CH_SetBlockSize() and DMA_CH_SetDestinationAddress() shall be
 * explicitly invoked.
 *
 * Example Usage:
 *
 * @code
 * #include "DAVE.h"
 *
 * int main(void)
 * {
 *   // Initialize DMA_CH APP:
 *   // DMA_CH_Init() is called from within DAVE_Init().
 *   //
 *   // DMA_CH_Init() takes a reference to DMA_CH_t as the *only*
 *   // actual parameter, defined in dma_ch_conf.c. The structure
 *   // contains all GUI user configuration.
 *
 *   DAVE_Init();
 *
 *   // More code here
 *   while(1)
 *   {
 *   }
 *   return (0);
 * }
 * @endcode<BR> </p>
 */
DMA_CH_STATUS_t DMA_CH_Init(DMA_CH_t *const obj);

/**
 * @brief Trigger source request
 * @param obj A pointer to ::DMA_CH_t, pointing to the configuration parameters
 * @param type Parameter of type ::XMC_DMA_CH_TRANSACTION_TYPE_t indicating transfer type
 * @param last A bool value indicating if the call must initiate the final source request
 * @return None
 *
 * \par<b>Description: </b><br>
 * This function is a simple wrapper around the low-level-driver function
 * XMC_DMA_CH_TriggerSourceRequest(). It can be used for GPDMA transfers involving
 * a peripheral in software handshaking mode viz. Peripheral -> memory and peripheral
 * -> peripheral. It would typically be used in a source peripheral's event
 * callback function to trigger the source request.
 *
 * Example Usage:
 *
 * @code
 * #include "DAVE.h"
 *
 * volatile uint8_t adc_counter = 0;
 *
 * int main(void)
 * {
 *   DAVE_Init();
 *
 *   // The user shall configure the DMA for a peripheral to memory
 *   // transaction (e.g. ADC -> Memory DMA transaction) with the peripheral
 *   // as the flow controller. These options shall be set in the GUI of
 *   // the DMA_CH APP.
 *
 *   DMA_CH_Init(&DMA_CH_0);
 *
 *   XMC_DMA_CH_SetSourceAddress(DMA_CH_0.dma_global->dma,DMA_CH_0.ch_num,(uint32_t)&(ADC_MEASUREMENT_Channel_A.group_handle->RES[ADC_MEASUREMENT_Channel_A.ch_handle->result_reg_number]));
 *
 *   if (!DMA_CH_IsEnabled(&DMA_CH_0))
 *   {
 *     DMA_CH_Enable(&DMA_CH_0);
 *   }
 *
 *   // Start ADC conversion
 *	 ADC_MEASUREMENT_StartConversion(&ADC_MEASUREMENT_0);
 *
 *	 while (1);
 *	 return 0;
 * }
 *
 * void adc_measurement_handler(void)
 * {
 *   // We're essentially transferring 10 ADC
 *   // result values.
 *   if(adc_counter < 10)
 *   {
 *     if(adc_counter == 9)
 *     {
 *       DMA_CH_TriggerSourceRequest(&DMA_CH_0, XMC_DMA_CH_TRANSACTION_TYPE_SINGLE, true);
 *     }
 *     else
 *     {
 *       XMC_DMA_CH_TriggerSourceRequest(DMA_CH_0.dma_global->dma, DMA_CH_0.ch_num, XMC_DMA_CH_TRANSACTION_TYPE_BURST, false);
 *     }
 *     adc_counter++;
 *   }
 * }
 * @endcode<BR> </p>
 */
__STATIC_INLINE void DMA_CH_TriggerSourceRequest(DMA_CH_t *const obj, const XMC_DMA_CH_TRANSACTION_TYPE_t type, bool last)
{
  XMC_DMA_CH_TriggerSourceRequest(obj->dma_global->dma, obj->ch_num, type, last);
}

/**
 * @brief Trigger destination request
 * @param obj A pointer to ::DMA_CH_t, pointing to the configuration parameters
 * @param type Parameter of type ::XMC_DMA_CH_TRANSACTION_TYPE_t indicating transfer type
 * @param last A bool value indicating if the call must initiate the final destination request
 * @return None
 *
 * \par<b>Description: </b><br>
 * This function is a simple wrapper around the low-level-driver function
 * XMC_DMA_CH_TriggerSourceRequest(). It can be used for GPDMA transfers involving
 * a peripheral in software handshaking mode viz. Memory -> peripheral and peripheral
 * -> peripheral. It is typically used in a destination peripheral's event callback
 * function to trigger the destination request.
 *
 * Example Usage:
 *
 * @code
 * #include "DAVE.h"
 *
 * volatile uint8_t block_count = 0;
 *
 * // Memory -> Peripheral (like UART) - peripheral
 * // flow controller.
 *
 * int main(void)
 * {
 *   DAVE_Init();
 *
 *   DMA_CH_Init(&DMA_CH_0);
 *
 *   // Set destination address here
 *   // (which could be the UART transmit buffer for
 *   // a memory to peripheral transfer).
 *   //
 *   // Assume that the UART APP is already instantiated in
 *   // DAVE. Also, the source address is assumed to be set
 *   // in the GUI.
 *   XMC_DMA_CH_SetDestinationAddress(DMA_CH_0.dma_global->dma, DMA_CH_0.ch_num, (uint32_t)&(UART_0.channel->TBUF[0]));
 *
 *   if (!DMA_CH_IsEnabled(&DMA_CH_0))
 *   {
 *     DMA_CH_Enable(&DMA_CH_0);
 *   }
 *
 *   // Assume the UART APP is already instantiated in the DAVE project
 *   XMC_USIC_CH_TriggerServiceRequest(UART_0.channel, UART_0.dynamic->tx_sr);
 *
 *   while (1);
 *
 *   return 0;
 * }
 *
 * void uart_tx_callback_0(void)
 * {
 *   block_count++;
 *
 *   if (block_count == 4)
 *   {
 *     DMA_CH_TriggerDestinationRequest(&DMA_CH_0, XMC_DMA_CH_TRANSACTION_TYPE_SINGLE, true);
 *     DMA_CH_RequestLastMultiblockTransfer(&DMA_CH_0);
 *   }
 *   else
 *   {
 *     XMC_DMA_CH_TriggerDestinationRequest(DMA_CH_0.dma_global->dma, DMA_CH_0.ch_num, XMC_DMA_CH_TRANSACTION_TYPE_BURST, false);
 *   }
 * }
 * @endcode<BR> </p>
 */
__STATIC_INLINE void DMA_CH_TriggerDestinationRequest(DMA_CH_t *const obj,
                                                      const XMC_DMA_CH_TRANSACTION_TYPE_t type,
                                                      bool last)
{
  XMC_DMA_CH_TriggerDestinationRequest(obj->dma_global->dma, obj->ch_num, type, last);
}

/**
 * @brief Trigger last multi-block transfer
 * @param obj A pointer to ::DMA_CH_t, pointing to the configuration parameters
 * @return None
 *
 * \par<b>Description: </b><br>
 * The function is a wrapper around the function XMC_DMA_CH_RequestLastMultiblockTransfer()
 * in the DMA low-level-driver. The function is used signal the end of multi-block
 * DMA transfer. It clears the RELOAD_SRC and RELOAD_DST bits of the CFGL register
 * to keep the source and destination addresses from getting updated. The function
 * is typically used in an event handler to signal that the next block getting
 * transferred is the last block in the transfer sequence.
 *
 * Example Usage:
 *
 * @code
 * #include "DAVE.h"
 *
 * volatile uint8_t block_count = 0;
 *
 * // Memory -> Peripheral (like UART) - peripheral
 * // flow controller.
 *
 * int main(void)
 * {
 *   DAVE_Init();
 *
 *   DMA_CH_Init(&DMA_CH_0);
 *
 *   // Set destination address here
 *   // (which could be the UART transmit buffer for
 *   // a memory to peripheral transfer).
 *   //
 *   // Assume that the UART APP is already instantiated in
 *   // DAVE. Also, the source address is assumed to be set
 *   // in the GUI.
 *   XMC_DMA_CH_SetDestinationAddress(DMA_CH_0.dma_global->dma, DMA_CH_0.ch_num, (uint32_t)&(UART_0.channel->TBUF[0]));
 *
 *   if (!DMA_CH_IsEnabled(&DMA_CH_0))
 *   {
 *     DMA_CH_Enable(&DMA_CH_0);
 *   }
 *
 *   // Assume the UART APP is already instantiated in the DAVE project
 *   XMC_USIC_CH_TriggerServiceRequest(UART_0.channel, UART_0.dynamic->tx_sr);
 *
 *   while (1);
 *
 *   return 0;
 * }
 *
 * void uart_tx_callback_0(void)
 * {
 *   block_count++;
 *
 *   if (block_count == 4)
 *   {
 *     DMA_CH_TriggerDestinationRequest(&DMA_CH_0, XMC_DMA_CH_TRANSACTION_TYPE_SINGLE, true);
 *     DMA_CH_RequestLastMultiblockTransfer(&DMA_CH_0);
 *   }
 *   else
 *   {
 *     XMC_DMA_CH_TriggerDestinationRequest(DMA_CH_0.dma_global->dma, DMA_CH_0.ch_num, XMC_DMA_CH_TRANSACTION_TYPE_BURST, false);
 *   }
 * }
 * @endcode<BR> </p>
 */
__STATIC_INLINE void DMA_CH_RequestLastMultiblockTransfer(DMA_CH_t *const obj)
{
  XMC_DMA_CH_RequestLastMultiblockTransfer(obj->dma_global->dma, obj->ch_num);
}

/**
 * @brief Set DMA source address
 * @param obj A pointer to ::DMA_CH_t, pointing to the configuration parameters
 * @param addr Source address
 * @return None
 *
 * \par<b>Description: </b><br>
 * The function can be used to set the source address for a DMA transaction.
 * Use this function to set source address post the initial GUI initialization.
 *
 * Example Usage:
 *
 * @code
 * #include "DAVE.h"
 *
 * uint32_t tx_buf[256];
 *
 * int main(void)
 * {
 *   DAVE_Init();
 *
 *   DMA_CH_Init(&DMA_CH_0);
 *
 *   XMC_DMA_CH_SetSourceAddress(DMA_CH_0.dma_global->dma, DMA_CH_0.ch_num, (uint32_t)&tx_buf[0]);
 *
 *   if (!DMA_CH_IsEnabled(&DMA_CH_0))
 *   {
 *     DMA_CH_Enable(&DMA_CH_0);
 *   }
 * }
 * @endcode<BR> </p>
 */
__STATIC_INLINE void DMA_CH_SetSourceAddress(DMA_CH_t *const obj, uint32_t addr)
{
  XMC_DMA_CH_SetSourceAddress(obj->dma_global->dma, obj->ch_num, addr);
}

/**
 * @brief Set DMA destination address
 * @param obj A pointer to ::DMA_CH_t, pointing to the configuration parameters
 * @param addr Destination address
 * @return None
 *
 * \par<b>Description: </b><br>
 * The function can be used to set the destination address for a DMA transaction.
 * Use this function to set destination address post the initial GUI initialization.
 *
 * Example Usage:
 *
 * @code
 * #include "DAVE.h"
 *
 * uint32_t tx_buf[256];
 * uint32_t rx_buf[256];
 *
 * int main(void)
 * {
 *   DAVE_Init();
 *
 *   DMA_CH_Init(&DMA_CH_0);
 *
 *   XMC_DMA_CH_SetSourceAddress(DMA_CH_0.dma_global->dma, DMA_CH_0.ch_num, (uint32_t)&tx_buf[0]);
 *   // Make sure you have an instance of the UART APP.
 *   // Otherwise, the compiler will complain.
 *   XMC_DMA_CH_SetDestinationAddress(DMA_CH_0.dma_global->dma, DMA_CH_0.ch_num, (uint32_t)&(UART_0.channel->TBUF[0]));
 *
 *   if (!DMA_CH_IsEnabled(&DMA_CH_0))
 *   {
 *     DMA_CH_Enable(&DMA_CH_0);
 *   }
 * }
 * @endcode<BR> </p>
 */
__STATIC_INLINE void DMA_CH_SetDestinationAddress(DMA_CH_t *const obj, uint32_t addr)
{
  XMC_DMA_CH_SetDestinationAddress(obj->dma_global->dma, obj->ch_num, addr);
}

/**
 * @brief Set DMA block size
 * @param obj A pointer to ::DMA_CH_t, pointing to the configuration parameters
 * @param block_size Block size to set
 * @return None
 *
 * \par<b>Description: </b><br>
 * The function is used to set block size for the DMA transfer.
 * Use this function to set block size post the initial GUI initialization.
 *
 * Example Usage:
 *
 * @code
 * #include "DAVE.h"
 *
 * int main(void)
 * {
 *   DAVE_Init();
 *
 *   DMA_CH_Init(&DMA_CH_0);
 *
 *   // Set block size
 *   DMA_CH_SetBlockSize(&DMA_CH_0, 1);
 *
 *   if (!DMA_CH_IsEnabled(&DMA_CH_0))
 *   {
 *     DMA_CH_Enable(&DMA_CH_0);
 *   }
 * }
 * @endcode<BR> </p>
 */
__STATIC_INLINE void DMA_CH_SetBlockSize(DMA_CH_t *const obj, uint32_t block_size)
{
  XMC_DMA_CH_SetBlockSize(obj->dma_global->dma, obj->ch_num, block_size);
}

/**
 * @brief Reload the initial DMA configuration
 * @param obj A pointer to ::DMA_CH_t, pointing to the configuration parameters
 * @return None
 *
 * \par<b>Description: </b><br>
 * The function is used to reconfigure the DMA channel with initial configurations.
 *
 * Example Usage:
 *
 * @code
 * #include "DAVE.h"
 *
 * uint32_t tx_buf[64];
 * uint32_t rx_buf[64];
 * uint32_t *src_ptr = tx_buf;
 * uint32_t *dest_ptr = rx_buf;
 * volatile uint8_t single_block_count = 0;
 *
 * int main(void)
 * {
 *   uint32_t count = 0;
 *   //This will initialize DMA with block_size-16, src_addr- &tx_buf[0] and dest_addr- &rx_buf[0]
 *   DAVE_Init();
 *
 *   //fill the src buffer
 *   for(count = 0;count < 64;count++)
 *   {
 *     tx_buf[count] = (count+1);
 *   }
 *   //set src_addr,dest_addr,block_size different from the initialization values
 *   DMA_CH_SetSourceAddress(&DMA_CH_0,(uint32_t)&tx_buf[32]);
 *   DMA_CH_SetDestinationAddress(&DMA_CH_0,(uint32_t)&rx_buf[32]);
 *   DMA_CH_SetBlockSize(&DMA_CH_0,8);
 *
 *   //Do the transfer
 *   if(!DMA_CH_IsEnabled(&DMA_CH_0))
 *   {
 *     DMA_CH_Enable(&DMA_CH_0);
 *   }
 *   while(1);
 * }
 * // Callback defined in DMA_CH Interrupt Settings UI
 * void user_event_handler(XMC_DMA_CH_EVENT_t event)
 * {
 *   if((event & XMC_DMA_CH_EVENT_TRANSFER_COMPLETE) != 0)
 *   {
 *     single_block_count++;
 *     if(single_block_count == 1)
 *     {
 *       DMA_CH_Reload(&DMA_CH_0);
 *       DMA_CH_Enable(&DMA_CH_0);
 *     }
 *   }
 * }
 *
 * @endcode<BR> </p>
 */
__STATIC_INLINE void DMA_CH_Reload(DMA_CH_t *const obj)
{
	obj->reload(obj);
}

/**
 * @}
 */

/* Support for C++ */
#ifdef __cplusplus
}
#endif

#include "dma_ch_extern.h"

#endif /* DMA_CH_H */
