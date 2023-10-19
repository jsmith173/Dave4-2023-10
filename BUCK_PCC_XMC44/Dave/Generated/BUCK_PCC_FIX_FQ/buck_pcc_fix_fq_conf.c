/*********************************************************************************************************************
* DAVE APP Name : BUCK_PCC_FIX_FQ       APP Version: 4.1.4
*
* NOTE:
* This file is generated by DAVE. Any manual modification done to this file will be lost when the code is regenerated.
*********************************************************************************************************************/

/**
 * @cond
 ***********************************************************************************************************************
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
 *   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
 *   disclaimer in the documentation and/or other materials provided with the distribution.
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
 * 2015-10-08:
 *     - Initial version for DAVEv4
 *
 * 2015-10-16:
 *     - Over limit & Under limit values are corrected
 * 
 * 2016-01-18:
 *     - APP handle structure is modified
 *
 * @endcond
 *
 */

/***********************************************************************************************************************
 * HEADER FILES
 **********************************************************************************************************************/
#include "buck_pcc_fix_fq.h"
#include "xmc_vadc.h"

/**********************************************************************************************************************
* DATA STRUCTURES
**********************************************************************************************************************/

/******************** Start of BUCK_PCC_FIX_FQ instance - BUCK_PCC_FIX_FQ_0 ********************/
    
/* VADC result register configuration handle */
XMC_VADC_RESULT_CONFIG_t BUCK_PCC_FIX_FQ_0_Vout_ResultConfig =
{
  .wait_for_read_mode            = (uint32_t) false,
  .part_of_fifo                  = (uint32_t) false,
  .event_gen_enable              = (uint32_t) true
};
    
XMC_VADC_CHANNEL_CONFIG_t BUCK_PCC_FIX_FQ_0_Vout_ChannelConfig =
{
  .input_class                   = (uint32_t) XMC_VADC_CHANNEL_CONV_GROUP_CLASS0,    /* ICLASS 0 selected */
  .result_reg_number             = 4U,                          /* GxRES[4U] selected */
  .alias_channel                 = (int8_t) -1,                                      /* ALIAS is Disabled */
};
            
/* ADC scan entry configuration handle */
ADC_SCAN_ENTRY_t BUCK_PCC_FIX_FQ_0_ADC_SCAN_0_Scan_Entry_Vout =
{
  .channel_number                = (uint8_t) 6U,
  .ch_event_notification         = false,
  .rs_event_notification         = false,
  .adc_event_callback            = NULL
};
                
BUCK_PCC_FIX_FQ_ADCConfig_t BUCK_PCC_FIX_FQ_0_ADCConfig =
{
  .adc_mode                      = BUCK_PCC_FIX_FQ_ADC_MODE_SCAN,  
  .result_reg_handle             = &BUCK_PCC_FIX_FQ_0_Vout_ResultConfig,
  
  .channel_handle_array          = {
                                    &BUCK_PCC_FIX_FQ_0_Vout_ChannelConfig,
                                    NULL,
                                    NULL,
                                    NULL,
                                    NULL,
                                    NULL,
                                    NULL
                                  },
    
  .scan_entry_handle_array       = {
                                    &BUCK_PCC_FIX_FQ_0_ADC_SCAN_0_Scan_Entry_Vout,
                                    NULL,
                                    NULL,
                                    NULL,
                                    NULL,
                                    NULL,
                                    NULL
                                   },
        
  .result_register_num_array     = {4U, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
  .channel_num_array             = {6U, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}  
};
    
BUCK_PCC_FIX_FQ_PWMConfig_t BUCK_PCC_FIX_FQ_0_PWMConfig =
{
  .no_of_phases                  = BUCK_PCC_FIX_FQ_NUM_OF_PHASES_1,
  .phase_timer_val               = {0U, 0U, 0U},
  .ccu8_output_passive_level     = XMC_GPIO_OUTPUT_LEVEL_LOW,
  .synch_converter               = false
};

BUCK_PCC_FIX_FQ_IntConfig_t BUCK_PCC_FIX_FQ_0_InterruptConfig =
{
  .node                          = (IRQn_Type)19,
  .priority                      = 1U,  
  .subpriority                   = 0U,
  .vout_result_ev_srline         = XMC_VADC_SR_GROUP_SR1
};
                
const BUCK_PCC_FIX_FQ_CONFIG_t BUCK_PCC_FIX_FQ_0_config =
{
  .adc_vout_enable               = true,
  .adc_vin_enable                = false,
  .adc_iout1_enable              = false,
  .adc_iout2_enable              = false,
  .adc_iout3_enable              = false,
  .adc_udef_enable               = false,

  .vin_sw_protection             = false,
  .vout_sw_protection            = false,
  .iout1_sw_protection           = false,
  .iout2_sw_protection           = false,
  .iout3_sw_protection           = false,
  .volt_control_rate             = 1U,
  .filter                        = BUCK_PCC_FIX_FQ_FILTER_TYPE_II,
  .interrupt_event               = BUCK_PCC_FIX_FQ_INTERRUPT_VOUT_RESULT_EVENT,
    
  .vout                          = 2047.5f,
  .vin                           = 3116.6672f,
  .gain_vout                     = 0.5f,
  .gain_vin                      = 0.2093f,
  .gain_iout1                    = 1.0f,
  .gain_iout2                    = 1.0f,
  .gain_iout3                    = 1.0f,

  .vout_high_limit               = 2457.0f,
  .vin_high_limit                = 3740.0007f,
  .iout1_high_limit              = 2481.818f,
  .iout2_high_limit              = 2481.818f,
  .iout3_high_limit              = 2481.818f,

  .vout_low_limit                = 1433.25f,
  .vin_low_limit                 = 2493.3337f,
  .iout1_low_limit               = 12.409091f,
  .iout2_low_limit               = 12.409091f,
  .iout3_low_limit               = 12.409091f, 
  .dac_start_value               = 310U,
  .soft_start_enable             = false, 
  .blanking                      = true,
  .filter_comparator             = false,
  .slope_compensation            = true,
};

CONTROL_LIB_2P2Z_DATA_FLOAT_t BUCK_PCC_FIX_FQ_0_typeII =
{
  .fdbk_ptr                      = &BUCK_PCC_FIX_FQ_0.buck_vout,
  .ref_ptr                       = &BUCK_PCC_FIX_FQ_0.vout_reference,

  .coeff_b0                      = 1.1122064229842763f,
  .coeff_b1                      = 0.05538305897225312f,
  .coeff_b2                      = -1.0568233640120233f,
  .coeff_a1                      = 1.833333333333f,
  .coeff_a2                      = -0.833333333333f,      

  .out_limit_max                 = 1023.0f,
  .out_limit_imin                = -1023.0f,
  .out_limit_min                 = 155.0f,

  .m_k                           = 0.0f,

  .x_0                           = 0.0f,
  .x_1                           = 0.0f,
  .y_0                           = 0.0f,
  .y_1                           = 0.0f,

  .out                           = 0.0f,
};
            
BUCK_PCC_FIX_FQ_t BUCK_PCC_FIX_FQ_0 =
{
  .config                        = &BUCK_PCC_FIX_FQ_0_config,
  .adc_config                    = &BUCK_PCC_FIX_FQ_0_ADCConfig,
  .pwm_config                    = &BUCK_PCC_FIX_FQ_0_PWMConfig,  
  .state                         = BUCK_PCC_FIX_FQ_STATE_UNINITIALIZED,
    
  .interrupt_config              = &BUCK_PCC_FIX_FQ_0_InterruptConfig, 
  .vout_reference                = 2047.5f, 
  .typeII                        = &BUCK_PCC_FIX_FQ_0_typeII,
        
  .group_ptr_array               = {
                                    VADC_G0,
                                    NULL,
                                    NULL,
                                    NULL,
                                    NULL,
                                    NULL,
                                    NULL
                                   },
    
  .adc_scan_app_handle_array     = {
                                    &ADC_SCAN_0,
                                    NULL,
                                    NULL,
                                    NULL,
                                    NULL,
                                    NULL,
                                    NULL
                                   },
        
  .hrpwm_handle_array            = {&HRPWM_0, NULL, NULL},
  .csg_handle_array              = {&COMP_SLOPE_GEN_0, NULL, NULL},
        
};
/******************** End of BUCK_PCC_FIX_FQ instance - BUCK_PCC_FIX_FQ_0 ********************/
    
