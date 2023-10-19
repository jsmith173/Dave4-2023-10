<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="COMP_SLOPE_GEN" URI="http://resources/4.0.10/app/COMP_SLOPE_GEN/0" description="CSG APP generates PWM using comparator and slope generator &#xA; This APP requires GLOBAL_CCU8 consuming kernal 0" mode="NOTSHARABLE" version="4.0.10" minDaveVersion="4.0.0" instanceLabel="COMP_SLOPE_GEN_0" appLabel="" containingProxySignal="true">
  <upwardMapList xsi:type="ResourceModel:RequiredApp" href="../../BUCK_PCC_FIX_FQ/v4_1_4/BUCK_PCC_FIX_FQ_0.app#//@requiredApps.23"/>
  <properties provideInit="true"/>
  <virtualSignals name="global_signal" URI="http://resources/4.0.10/app/COMP_SLOPE_GEN/0/vs_csg_global" hwSignal="global_signal" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="ext_switch_blank" URI="http://resources/4.0.10/app/COMP_SLOPE_GEN/0/vs_csg_ext_switch" hwSignal="ext_switch" hwResource="//@hwResources.0" visible="true">
    <upwardMapList xsi:type="ResourceModel:Connections" href="../../BUCK_PCC_FIX_FQ/v4_1_4/BUCK_PCC_FIX_FQ_0.app#//@connections.70"/>
  </virtualSignals>
  <virtualSignals name="ext_clamp_control" URI="http://resources/4.0.10/app/COMP_SLOPE_GEN/0/vs_csg_ext_clamp_control" hwSignal="ext_clamp_control" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="ext_slope_start" URI="http://resources/4.0.10/app/COMP_SLOPE_GEN/0/vs_csg_slope_start" hwSignal="slope_start" hwResource="//@hwResources.0" visible="true">
    <upwardMapList xsi:type="ResourceModel:Connections" href="../../BUCK_PCC_FIX_FQ/v4_1_4/BUCK_PCC_FIX_FQ_0.app#//@connections.71"/>
  </virtualSignals>
  <virtualSignals name="event_comp_out_rise_fall" URI="http://resources/4.0.10/app/COMP_SLOPE_GEN/0/vs_csg_crs_cfs" hwSignal="crs_cfs" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="event_clamp_state_enter" URI="http://resources/4.0.10/app/COMP_SLOPE_GEN/0/vs_csg_cse" hwSignal="cse" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="comp_out_to_hrc" URI="http://resources/4.0.10/app/COMP_SLOPE_GEN/0/vs_csg_comp_out_to_hrc" hwSignal="gsc_comp" hwResource="//@hwResources.0" visible="true">
    <upwardMapList xsi:type="ResourceModel:Connections" href="../../BUCK_PCC_FIX_FQ/v4_1_4/BUCK_PCC_FIX_FQ_0.app#//@connections.72"/>
  </virtualSignals>
  <virtualSignals name="comp_out_cyo" URI="http://resources/4.0.10/app/COMP_SLOPE_GEN/0/vs_csg_comp_out_cyo" hwSignal="cno" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="comp_input_A" URI="http://resources/4.0.10/app/COMP_SLOPE_GEN/0/vs_csg_cina" hwSignal="cina" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="comp_input_B" URI="http://resources/4.0.10/app/COMP_SLOPE_GEN/0/vs_csg_cinb" hwSignal="cinb" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="comp_input_pin" URI="http://resources/4.0.10/app/COMP_SLOPE_GEN/0/vs_port_cmp_input" hwSignal="pad" hwResource="//@hwResources.1"/>
  <virtualSignals name="CSG COMP INPUT_signal" URI="http://resources/4.0.10/app/COMP_SLOPE_GEN/0/__pin_vs_port_cmp_input" hwSignal="pin" hwResource="//@hwResources.2"/>
  <requiredApps URI="http://resources/4.0.10/app/COMP_SLOPE_GEN/0/csg_app_global_ccu8_cc8" requiredAppName="GLOBAL_CCU8" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../GLOBAL_CCU8/v4_1_14/GLOBAL_CCU8_0.app#/"/>
  </requiredApps>
  <requiredApps URI="http://resources/4.0.10/app/COMP_SLOPE_GEN/0/csg_app_global_hrpwm" requiredAppName="GLOBAL_HRPWM" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../GLOBAL_HRPWM/v4_0_14/GLOBAL_HRPWM_0.app#/"/>
  </requiredApps>
  <hwResources name="CSG" URI="http://resources/4.0.10/app/COMP_SLOPE_GEN/0/hwres_csg_slice" resourceGroupUri="peripheral/hrpwm/*/csg/*" mResGrpUri="peripheral/hrpwm/*/csg/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/HRPWM0/HRPWM0_0.dd#//@provided.0"/>
  </hwResources>
  <hwResources name="CSG COMP INPUT" URI="http://resources/4.0.10/app/COMP_SLOPE_GEN/0/hwres_port_cmp_input" resourceGroupUri="port/p/*/pad/*" mResGrpUri="port/p/*/pad/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/Port1/Port1_1.dd#//@provided.0"/>
  </hwResources>
  <hwResources name="CSG COMP INPUT" URI="http://resources/4.0.10/app/COMP_SLOPE_GEN/0/__pin_hwres_port_cmp_input" resourceGroupUri="devicepackage/0/79" constraintType="GLOBAL_RESOURCE" mResGrpUri="devicepackage/0/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/DEVICEPACKAGE/DEVICEPACKAGE_0.dd#//@provided.1"/>
  </hwResources>
  <connections URI="http://resources/4.0.10/app/COMP_SLOPE_GEN/0/http://resources/4.0.10/app/COMP_SLOPE_GEN/0/vs_ccu8_cc8_global/http://resources/4.0.10/app/COMP_SLOPE_GEN/0/vs_hrpwm_global" systemDefined="true" sourceSignal="ccu8_global" targetSignal="global_signal" proxySrcVirtualSignalUri="http://resources/4.1.14/app/GLOBAL_CCU8/0/vs_global_ccu8_globalsignal" proxyTargetVirtualSignalUri="http://resources/4.0.14/app/GLOBAL_HRPWM/0/vs_global_hrpwm_globalsignal" containingProxySignal="true">
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../GLOBAL_CCU8/v4_1_14/GLOBAL_CCU8_0.app#//@virtualSignals.0"/>
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../GLOBAL_HRPWM/v4_0_14/GLOBAL_HRPWM_0.app#//@virtualSignals.0"/>
    <srcVirtualSignal href="../../GLOBAL_CCU8/v4_1_14/GLOBAL_CCU8_0.app#//@virtualSignals.0"/>
    <targetVirtualSignal href="../../GLOBAL_HRPWM/v4_0_14/GLOBAL_HRPWM_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.10/app/COMP_SLOPE_GEN/0/http://resources/4.0.10/app/COMP_SLOPE_GEN/0/vs_hrpwm_global/http://resources/4.0.10/app/COMP_SLOPE_GEN/0/vs_csg_global" systemDefined="true" sourceSignal="global_signal" targetSignal="global_signal" targetVirtualSignal="//@virtualSignals.0" proxySrcVirtualSignalUri="http://resources/4.0.14/app/GLOBAL_HRPWM/0/vs_global_hrpwm_globalsignal" containingProxySignal="true">
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../GLOBAL_HRPWM/v4_0_14/GLOBAL_HRPWM_0.app#//@virtualSignals.0"/>
    <srcVirtualSignal href="../../GLOBAL_HRPWM/v4_0_14/GLOBAL_HRPWM_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.10/app/COMP_SLOPE_GEN/0/http://resources/4.0.10/app/COMP_SLOPE_GEN/0/vs_port_cmp_input/http://resources/4.0.10/app/COMP_SLOPE_GEN/0/vs_csg_cina" systemDefined="true" sourceSignal="comp_input_pin" targetSignal="comp_input_A" srcVirtualSignal="//@virtualSignals.10" targetVirtualSignal="//@virtualSignals.8"/>
  <connections URI="http://resources/4.0.10/app/COMP_SLOPE_GEN/0/http://resources/4.0.10/app/COMP_SLOPE_GEN/0/vs_port_cmp_input/http://resources/4.0.10/app/COMP_SLOPE_GEN/0/vs_csg_cinb" systemDefined="true" sourceSignal="comp_input_pin" targetSignal="comp_input_B" required="false" srcVirtualSignal="//@virtualSignals.10" targetVirtualSignal="//@virtualSignals.9"/>
  <connections URI="http://resources/4.0.10/app/COMP_SLOPE_GEN/0/http://resources/4.0.10/app/COMP_SLOPE_GEN/0/vs_port_cmp_input/http://resources/4.0.10/app/COMP_SLOPE_GEN/0/__pin_vs_port_cmp_input" systemDefined="true" sourceSignal="comp_input_pin" targetSignal="CSG COMP INPUT_signal" srcVirtualSignal="//@virtualSignals.10" targetVirtualSignal="//@virtualSignals.11"/>
  <connections URI="http://resources/4.0.10/app/COMP_SLOPE_GEN/0/http://resources/4.0.10/app/COMP_SLOPE_GEN/0/__pin_vs_port_cmp_input/http://resources/4.0.10/app/COMP_SLOPE_GEN/0/vs_port_cmp_input" systemDefined="true" sourceSignal="CSG COMP INPUT_signal" targetSignal="comp_input_pin" srcVirtualSignal="//@virtualSignals.11" targetVirtualSignal="//@virtualSignals.10"/>
</ResourceModel:App>
