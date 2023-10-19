/*********************************************************************************************************************
* DAVE APP Name : BUCK_VC_FIX_FQ       APP Version: 4.1.4
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
 * 2015-10-15:
 *     - Number of samples for XMC1x device is set as 8
 *
 * 2015-10-16:
 *     - Voltage gain constant calculation is corrected when Vin is not measured
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
#include "buck_vc_fix_fq.h"

/***********************************************************************************************************************
 * MACROS
 **********************************************************************************************************************/

/* Control loop for BUCK_VC_FIX_FQ_0 */
void BUCK_VC_FIX_FQ_0_Control_Loop_ISR(void)
{ 
  /* Stores High Resolution compare value calculated by control loop */
  uint8_t  hr_compare_value;

  /* Stores CCU compare value calculated by control loop */
  uint16_t ccu_compare_value;
            
  /* PWM phase 0 handle pointer */
  HRPWM_t* hrpwm_app0_ptr = BUCK_VC_FIX_FQ_0.hrpwm_handle_array[0];
            
  /* Get ADC measured Vout result */
  BUCK_VC_FIX_FQ_0.buck_vout  = (float) XMC_VADC_GROUP_GetResult(VADC_G0, 4U);
                
    /* Controller */
    CONTROL_LIB_3P3ZFloat(BUCK_VC_FIX_FQ_0.typeIII);
        
    ccu_compare_value = (uint16_t) (((uint32_t) BUCK_VC_FIX_FQ_0.typeIII->out) >> 8U);
                
    /* Set compare value for CC8 phase 0 */
    XMC_CCU8_SLICE_SetTimerCompareMatchChannel1(hrpwm_app0_ptr->ccu8_slice_ptr, ccu_compare_value);
            
    /* Compare value calculation for HRPWM phase 0 */
    hr_compare_value = (uint8_t) (((((uint32_t) BUCK_VC_FIX_FQ_0.typeIII->out) && 0xFF) * hrpwm_app0_ptr->hr_cr_max) >> 8U);

    /* Set compare value for HRPWM phase 0 */
    XMC_HRPWM_HRC_SetCompare1(hrpwm_app0_ptr->hrc_slice_ptr, hr_compare_value);
            
    /* Transfer phase 0 compare value from shadow register to actual register */
    XMC_CCU8_EnableShadowTransfer(hrpwm_app0_ptr->ccu8_module_ptr, hrpwm_app0_ptr->shadow_txfr_msk);
            
} /* end of Control loop */
