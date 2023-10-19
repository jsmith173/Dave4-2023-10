<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="HRPWM" URI="http://resources/4.1.22/app/HRPWM/0" description="PWM APP using one slice of CCU8 and HRC, with external events, dead time and high resolution positioning support, to generate up to 2 PWM outputs." mode="NOTSHARABLE" version="4.1.22" minDaveVersion="4.3.2" instanceLabel="HRPWM_0" appLabel="" containingProxySignal="true">
  <upwardMapList xsi:type="ResourceModel:RequiredApp" href="../../BUCK_VC_FIX_FQ/v4_1_4/BUCK_VC_FIX_FQ_0.app#//@requiredApps.14"/>
  <properties provideInit="true"/>
  <virtualSignals name="ccu8_global_signal" URI="http://resources/4.1.22/app/HRPWM/0/vs_ccu8_cc8_slice_global" hwSignal="global_signal" hwResource="//@hwResources.0"/>
  <virtualSignals name="hrc_global_signal" URI="http://resources/4.1.22/app/HRPWM/0/vs_ccu8_cc8_hrpwm_hrc_global" hwSignal="global_signal" hwResource="//@hwResources.1"/>
  <virtualSignals name="event_period_match" URI="http://resources/4.1.22/app/HRPWM/0/vs_ccu8_cc8_period_match_interrupt" hwSignal="pmus_omds" hwResource="//@hwResources.0" visible="true">
    <upwardMapList xsi:type="ResourceModel:Connections" href="../../BUCK_VC_FIX_FQ/v4_1_4/BUCK_VC_FIX_FQ_0.app#//@connections.13"/>
  </virtualSignals>
  <virtualSignals name="event_ch1_cmp_match" URI="http://resources/4.1.22/app/HRPWM/0/vs_ccu8_cc8_ch1_compare_match_interrupt" hwSignal="cmd1s_cmu1s" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="event_ch2_cmp_match" URI="http://resources/4.1.22/app/HRPWM/0/vs_ccu8_cc8_ch2_compare_match_interrupt" hwSignal="cmd2s_cmu2s" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="event_0" URI="http://resources/4.1.22/app/HRPWM/0/vs_event0_interrupt" hwSignal="e0as" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="event_1" URI="http://resources/4.1.22/app/HRPWM/0/vs_event1_interrupt" hwSignal="e1as" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="event_2" URI="http://resources/4.1.22/app/HRPWM/0/vs_event2_interrupt" hwSignal="e2as" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="timer_st" URI="http://resources/4.1.22/app/HRPWM/0/vs_ccu8_cc8_st" hwSignal="st" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="timer_st1" URI="http://resources/4.1.22/app/HRPWM/0/vs_ccu8_cc8_sta" hwSignal="sta" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="timer_st2" URI="http://resources/4.1.22/app/HRPWM/0/vs_ccu8_cc8_stb" hwSignal="stb" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="ext_event0" URI="http://resources/4.1.22/app/HRPWM/0/vs_ccu8_cc8_gp0_unsync" hwSignal="gp0_unsync" hwResource="//@hwResources.0"/>
  <virtualSignals name="ext_event1" URI="http://resources/4.1.22/app/HRPWM/0/vs_ccu8_cc8_gp1_unsync" hwSignal="gp1_unsync" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="ext_event2" URI="http://resources/4.1.22/app/HRPWM/0/vs_ccu8_cc8_gp2_unsync" hwSignal="gp2_unsync" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="mcm_input_0" URI="http://resources/4.1.22/app/HRPWM/0/vs_ccu8_cc8_mci0" hwSignal="mci0" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="mcm_input_1" URI="http://resources/4.1.22/app/HRPWM/0/vs_ccu8_cc8_mci1" hwSignal="mci1" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="mcm_input_2" URI="http://resources/4.1.22/app/HRPWM/0/vs_ccu8_cc8_mci2" hwSignal="mci2" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="mcm_input_3" URI="http://resources/4.1.22/app/HRPWM/0/vs_ccu8_cc8_mci3" hwSignal="mci3" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="mcss_input" URI="http://resources/4.1.22/app/HRPWM/0/vs_ccu8_cc8_mcss" hwSignal="mcss" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="hrc_set0" URI="http://resources/4.1.22/app/HRPWM/0/vs_hrpwm_hrc_set_0" hwSignal="set_0" hwResource="//@hwResources.1"/>
  <virtualSignals name="hrc_clear0" URI="http://resources/4.1.22/app/HRPWM/0/vs_hrpwm_hrc_clear_0" hwSignal="clear_0" hwResource="//@hwResources.1"/>
  <virtualSignals name="hrc_set1" URI="http://resources/4.1.22/app/HRPWM/0/vs_hrpwm_hrc_set_1" hwSignal="set_1" hwResource="//@hwResources.1" visible="true"/>
  <virtualSignals name="hrc_clear1" URI="http://resources/4.1.22/app/HRPWM/0/vs_hrpwm_hrc_clear_1" hwSignal="clear_1" hwResource="//@hwResources.1" visible="true"/>
  <virtualSignals name="QOUT" URI="http://resources/4.1.22/app/HRPWM/0/vs_hrpwm_hrc_qout" hwSignal="qout" hwResource="//@hwResources.1" visible="true"/>
  <virtualSignals name="hrc_out0" URI="http://resources/4.1.22/app/HRPWM/0/vs_ccu8_cc8_hrout0" hwSignal="hrout0" hwResource="//@hwResources.1" visible="true"/>
  <virtualSignals name="hrc_out1" URI="http://resources/4.1.22/app/HRPWM/0/vs_ccu8_cc8_hrout1" hwSignal="hrout1" hwResource="//@hwResources.1" visible="true"/>
  <virtualSignals name="Out - HRPWM OUT0 PAD" URI="http://resources/4.1.22/app/HRPWM/0/vs_port_hrout0" hwSignal="pad" hwResource="//@hwResources.2"/>
  <virtualSignals name="Out - HRPWM OUT1 PAD" URI="http://resources/4.1.22/app/HRPWM/0/vs_port_hrout1" hwSignal="pad" hwResource="//@hwResources.3" required="false"/>
  <virtualSignals name="HRPWM OUT0_signal" URI="http://resources/4.1.22/app/HRPWM/0/__pin_vs_port_hrout0" hwSignal="pin" hwResource="//@hwResources.4"/>
  <virtualSignals name="HRPWM OUT1_signal" URI="http://resources/4.1.22/app/HRPWM/0/__pin_vs_port_hrout1" hwSignal="pin" hwResource="//@hwResources.5"/>
  <requiredApps URI="http://resources/4.1.22/app/HRPWM/0/hrpwm_app_global_ccu8_cc8" requiredAppName="GLOBAL_CCU8" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../GLOBAL_CCU8/v4_1_14/GLOBAL_CCU8_0.app#/"/>
  </requiredApps>
  <requiredApps URI="http://resources/4.1.22/app/HRPWM/0/hrpwm_app_global_hrpwm" requiredAppName="GLOBAL_HRPWM" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../GLOBAL_HRPWM/v4_0_14/GLOBAL_HRPWM_0.app#/"/>
  </requiredApps>
  <hwResources name="CC8 Config" URI="http://resources/4.1.22/app/HRPWM/0/hwres_ccu8_cc8_slice" resourceGroupUri="peripheral/ccu8/0/cc8/*" mResGrpUri="peripheral/ccu8/0/cc8/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/CCU80/CCU80_0.dd#//@provided.0"/>
  </hwResources>
  <hwResources name="HRC" URI="http://resources/4.1.22/app/HRPWM/0/hwres_hrpwm_hrc" resourceGroupUri="peripheral/hrpwm/*/hrc/*" mResGrpUri="peripheral/hrpwm/*/hrc/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/HRPWM0/HRPWM0_0.dd#//@provided.14"/>
  </hwResources>
  <hwResources name="HRPWM OUT0" URI="http://resources/4.1.22/app/HRPWM/0/hwres_port_hrout0" resourceGroupUri="port/p/*/pad/*" mResGrpUri="port/p/*/pad/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/Port0/Port0_0.dd#//@provided.6"/>
  </hwResources>
  <hwResources name="HRPWM OUT1" URI="http://resources/4.1.22/app/HRPWM/0/hwres_port_hrout1" resourceGroupUri="" required="false" mResGrpUri="port/p/*/pad/*"/>
  <hwResources name="HRPWM OUT0" URI="http://resources/4.1.22/app/HRPWM/0/__pin_hwres_port_hrout0" resourceGroupUri="devicepackage/0/97" constraintType="GLOBAL_RESOURCE" mResGrpUri="devicepackage/0/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/DEVICEPACKAGE/DEVICEPACKAGE_0.dd#//@provided.0"/>
  </hwResources>
  <hwResources name="HRPWM OUT1" URI="http://resources/4.1.22/app/HRPWM/0/__pin_hwres_port_hrout1" resourceGroupUri="" required="false" mResGrpUri="devicepackage/0/*"/>
  <connections URI="http://resources/4.1.22/app/HRPWM/0/http://resources/4.1.22/app/HRPWM/0/vs_ccu8_cc8_global/http://resources/4.1.22/app/HRPWM/0/vs_ccu8_cc8_slice_global" systemDefined="true" sourceSignal="ccu8_global" targetSignal="ccu8_global_signal" targetVirtualSignal="//@virtualSignals.0" proxySrcVirtualSignalUri="http://resources/4.1.14/app/GLOBAL_CCU8/0/vs_global_ccu8_globalsignal" containingProxySignal="true">
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../GLOBAL_CCU8/v4_1_14/GLOBAL_CCU8_0.app#//@virtualSignals.0"/>
    <srcVirtualSignal href="../../GLOBAL_CCU8/v4_1_14/GLOBAL_CCU8_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.1.22/app/HRPWM/0/http://resources/4.1.22/app/HRPWM/0/vs_ccu8_cc8_global/http://resources/4.1.22/app/HRPWM/0/vs_ccu8_cc8_hrpwm_global" systemDefined="true" sourceSignal="ccu8_global" targetSignal="global_signal" proxySrcVirtualSignalUri="http://resources/4.1.14/app/GLOBAL_CCU8/0/vs_global_ccu8_globalsignal" proxyTargetVirtualSignalUri="http://resources/4.0.14/app/GLOBAL_HRPWM/0/vs_global_hrpwm_globalsignal" containingProxySignal="true">
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../GLOBAL_CCU8/v4_1_14/GLOBAL_CCU8_0.app#//@virtualSignals.0"/>
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../GLOBAL_HRPWM/v4_0_14/GLOBAL_HRPWM_0.app#//@virtualSignals.0"/>
    <srcVirtualSignal href="../../GLOBAL_CCU8/v4_1_14/GLOBAL_CCU8_0.app#//@virtualSignals.0"/>
    <targetVirtualSignal href="../../GLOBAL_HRPWM/v4_0_14/GLOBAL_HRPWM_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.1.22/app/HRPWM/0/http://resources/4.1.22/app/HRPWM/0/vs_ccu8_cc8_hrpwm_global/http://resources/4.1.22/app/HRPWM/0/vs_ccu8_cc8_hrpwm_hrc_global" systemDefined="true" sourceSignal="global_signal" targetSignal="hrc_global_signal" targetVirtualSignal="//@virtualSignals.1" proxySrcVirtualSignalUri="http://resources/4.0.14/app/GLOBAL_HRPWM/0/vs_global_hrpwm_globalsignal" containingProxySignal="true">
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../GLOBAL_HRPWM/v4_0_14/GLOBAL_HRPWM_0.app#//@virtualSignals.0"/>
    <srcVirtualSignal href="../../GLOBAL_HRPWM/v4_0_14/GLOBAL_HRPWM_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.1.22/app/HRPWM/0/http://resources/4.1.22/app/HRPWM/0/vs_ccu8_cc8_global_sync_start/http://resources/4.1.22/app/HRPWM/0/vs_ccu8_cc8_gp0_unsync" systemDefined="true" sourceSignal="ccu8_global_start" targetSignal="ext_event0" targetVirtualSignal="//@virtualSignals.11" proxySrcVirtualSignalUri="http://resources/4.1.14/app/GLOBAL_CCU8/0/vs_global_ccu8_gsc_enable" containingProxySignal="true">
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../GLOBAL_CCU8/v4_1_14/GLOBAL_CCU8_0.app#//@virtualSignals.2"/>
    <srcVirtualSignal href="../../GLOBAL_CCU8/v4_1_14/GLOBAL_CCU8_0.app#//@virtualSignals.2"/>
  </connections>
  <connections URI="http://resources/4.1.22/app/HRPWM/0/http://resources/4.1.22/app/HRPWM/0/vs_ccu8_cc8_global_sync_start/http://resources/4.1.22/app/HRPWM/0/vs_ccu8_cc8_gp1_unsync" systemDefined="true" sourceSignal="ccu8_global_start" targetSignal="ext_event1" required="false" targetVirtualSignal="//@virtualSignals.12" proxySrcVirtualSignalUri="http://resources/4.1.14/app/GLOBAL_CCU8/0/vs_global_ccu8_gsc_enable" containingProxySignal="true">
    <srcVirtualSignal href="../../GLOBAL_CCU8/v4_1_14/GLOBAL_CCU8_0.app#//@virtualSignals.2"/>
  </connections>
  <connections URI="http://resources/4.1.22/app/HRPWM/0/http://resources/4.1.22/app/HRPWM/0/vs_ccu8_cc8_global_sync_start/http://resources/4.1.22/app/HRPWM/0/vs_ccu8_cc8_gp2_unsync" systemDefined="true" sourceSignal="ccu8_global_start" targetSignal="ext_event2" required="false" targetVirtualSignal="//@virtualSignals.13" proxySrcVirtualSignalUri="http://resources/4.1.14/app/GLOBAL_CCU8/0/vs_global_ccu8_gsc_enable" containingProxySignal="true">
    <srcVirtualSignal href="../../GLOBAL_CCU8/v4_1_14/GLOBAL_CCU8_0.app#//@virtualSignals.2"/>
  </connections>
  <connections URI="http://resources/4.1.22/app/HRPWM/0/http://resources/4.1.22/app/HRPWM/0/vs_ccu8_cc8_sta/http://resources/4.1.22/app/HRPWM/0/vs_hrpwm_hrc_set_0" systemDefined="true" sourceSignal="timer_st1" targetSignal="hrc_set0" srcVirtualSignal="//@virtualSignals.9" targetVirtualSignal="//@virtualSignals.19"/>
  <connections URI="http://resources/4.1.22/app/HRPWM/0/http://resources/4.1.22/app/HRPWM/0/vs_ccu8_cc8_sta/http://resources/4.1.22/app/HRPWM/0/vs_hrpwm_hrc_clear_0" systemDefined="true" sourceSignal="timer_st1" targetSignal="hrc_clear0" srcVirtualSignal="//@virtualSignals.9" targetVirtualSignal="//@virtualSignals.20"/>
  <connections URI="http://resources/4.1.22/app/HRPWM/0/http://resources/4.1.22/app/HRPWM/0/vs_ccu8_cc8_sta/http://resources/4.1.22/app/HRPWM/0/vs_hrpwm_hrc_set_1" systemDefined="true" sourceSignal="timer_st1" targetSignal="hrc_set1" required="false" srcVirtualSignal="//@virtualSignals.9" targetVirtualSignal="//@virtualSignals.21"/>
  <connections URI="http://resources/4.1.22/app/HRPWM/0/http://resources/4.1.22/app/HRPWM/0/vs_ccu8_cc8_sta/http://resources/4.1.22/app/HRPWM/0/vs_hrpwm_hrc_clear_1" systemDefined="true" sourceSignal="timer_st1" targetSignal="hrc_clear1" required="false" srcVirtualSignal="//@virtualSignals.9" targetVirtualSignal="//@virtualSignals.22"/>
  <connections URI="http://resources/4.1.22/app/HRPWM/0/http://resources/4.1.22/app/HRPWM/0/vs_ccu8_cc8_hrout0/http://resources/4.1.22/app/HRPWM/0/vs_port_hrout0" systemDefined="true" sourceSignal="hrc_out0" targetSignal="Out - HRPWM OUT0 PAD" srcVirtualSignal="//@virtualSignals.24" targetVirtualSignal="//@virtualSignals.26"/>
  <connections URI="http://resources/4.1.22/app/HRPWM/0/http://resources/4.1.22/app/HRPWM/0/vs_ccu8_cc8_hrout1/http://resources/4.1.22/app/HRPWM/0/vs_port_hrout1" systemDefined="true" sourceSignal="hrc_out1" targetSignal="Out - HRPWM OUT1 PAD" required="false" srcVirtualSignal="//@virtualSignals.25" targetVirtualSignal="//@virtualSignals.27"/>
  <connections URI="http://resources/4.1.22/app/HRPWM/0/http://resources/4.1.22/app/HRPWM/0/vs_port_hrout0/http://resources/4.1.22/app/HRPWM/0/__pin_vs_port_hrout0" systemDefined="true" sourceSignal="Out - HRPWM OUT0 PAD" targetSignal="HRPWM OUT0_signal" srcVirtualSignal="//@virtualSignals.26" targetVirtualSignal="//@virtualSignals.28"/>
  <connections URI="http://resources/4.1.22/app/HRPWM/0/http://resources/4.1.22/app/HRPWM/0/__pin_vs_port_hrout0/http://resources/4.1.22/app/HRPWM/0/vs_port_hrout0" systemDefined="true" sourceSignal="HRPWM OUT0_signal" targetSignal="Out - HRPWM OUT0 PAD" srcVirtualSignal="//@virtualSignals.28" targetVirtualSignal="//@virtualSignals.26"/>
  <connections URI="http://resources/4.1.22/app/HRPWM/0/http://resources/4.1.22/app/HRPWM/0/vs_port_hrout1/http://resources/4.1.22/app/HRPWM/0/__pin_vs_port_hrout1" systemDefined="true" sourceSignal="Out - HRPWM OUT1 PAD" targetSignal="HRPWM OUT1_signal" srcVirtualSignal="//@virtualSignals.27" targetVirtualSignal="//@virtualSignals.29"/>
  <connections URI="http://resources/4.1.22/app/HRPWM/0/http://resources/4.1.22/app/HRPWM/0/__pin_vs_port_hrout1/http://resources/4.1.22/app/HRPWM/0/vs_port_hrout1" systemDefined="true" sourceSignal="HRPWM OUT1_signal" targetSignal="Out - HRPWM OUT1 PAD" srcVirtualSignal="//@virtualSignals.29" targetVirtualSignal="//@virtualSignals.27"/>
</ResourceModel:App>
