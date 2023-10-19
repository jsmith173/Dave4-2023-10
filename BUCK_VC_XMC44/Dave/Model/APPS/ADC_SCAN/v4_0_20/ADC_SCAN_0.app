<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="ADC_SCAN" URI="http://resources/4.0.20/app/ADC_SCAN/0" description="Provides configurations for the scan request source of VADC." version="4.0.20" minDaveVersion="4.0.0" instanceLabel="ADC_SCAN_0" appLabel="" containingProxySignal="true">
  <upwardMapList xsi:type="ResourceModel:RequiredApp" href="../../BUCK_VC_FIX_FQ/v4_1_4/BUCK_VC_FIX_FQ_0.app#//@requiredApps.7"/>
  <properties provideInit="true" sharable="true"/>
  <virtualSignals name="scan_to_global" URI="http://resources/4.0.20/app/ADC_SCAN/0/vs_adc_scan_scanglobal" hwSignal="global_signal" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="scan_select" URI="http://resources/4.0.20/app/ADC_SCAN/0/vs_adc_scan_scan2channel" hwSignal="select" hwResource="//@hwResources.0" visible="true">
    <upwardMapList xsi:type="ResourceModel:Connections" href="../../BUCK_VC_FIX_FQ/v4_1_4/BUCK_VC_FIX_FQ_0.app#//@connections.8"/>
  </virtualSignals>
  <virtualSignals name="iclass_select" URI="http://resources/4.0.20/app/ADC_SCAN/0/vs_adc_scan_iclass2channel" hwSignal="ch_class_sel" hwResource="//@hwResources.1" visible="true">
    <upwardMapList xsi:type="ResourceModel:Connections" href="../../BUCK_VC_FIX_FQ/v4_1_4/BUCK_VC_FIX_FQ_0.app#//@connections.10"/>
  </virtualSignals>
  <virtualSignals name="group_selection" URI="http://resources/4.0.20/app/ADC_SCAN/0/vs_adc_scan_scan2config" hwSignal="req" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="trigger_input" URI="http://resources/4.0.20/app/ADC_SCAN/0/vs_adc_scan_greqtr0sel" hwSignal="greqtr1sel" hwResource="//@hwResources.0" visible="true">
    <upwardMapList xsi:type="ResourceModel:Connections" href="../../BUCK_VC_FIX_FQ/v4_1_4/BUCK_VC_FIX_FQ_0.app#//@connections.13"/>
  </virtualSignals>
  <virtualSignals name="gating_input" URI="http://resources/4.0.20/app/ADC_SCAN/0/vs_adc_scan_greqgt0sel" hwSignal="greqgt1sel" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="event_scan_source" URI="http://resources/4.0.20/app/ADC_SCAN/0/vs_adc_scan_sourceevent" hwSignal="sev" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="sr_interrupt_signal" URI="http://resources/4.0.20/app/ADC_SCAN/0/vs_nvic_signal_src" hwSignal="signal_in" hwResource="//@hwResources.2" required="false" visible="true"/>
  <virtualSignals name="class_select" URI="http://resources/4.0.20/app/ADC_SCAN/0/vs_adc_scan_classselect_out" hwSignal="class_sel" hwResource="//@hwResources.0"/>
  <virtualSignals name="scan_iclass_select" URI="http://resources/4.0.20/app/ADC_SCAN/0/vs_adc_scan_classselect_in" hwSignal="scan_class_sel" hwResource="//@hwResources.1"/>
  <requiredApps URI="http://resources/4.0.20/app/ADC_SCAN/0/appres_global_adc" requiredAppName="GLOBAL_ADC" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../GLOBAL_ADC/v4_0_22/GLOBAL_ADC_0.app#/"/>
  </requiredApps>
  <requiredApps URI="http://resources/4.0.20/app/ADC_SCAN/0/appres_cpu" requiredAppName="CPU_CTRL_XMC4" required="false" requiringMode="SHARABLE"/>
  <hwResources name="Scan" URI="http://resources/4.0.20/app/ADC_SCAN/0/hwres_vadc_scan" resourceGroupUri="peripheral/vadc/*/group/*/scan" mResGrpUri="peripheral/vadc/*/group/*/scan">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/VADC/VADC_0.dd#//@provided.29"/>
  </hwResources>
  <hwResources name="Scan Class" URI="http://resources/4.0.20/app/ADC_SCAN/0/hwres_vadc_sgrpclass" resourceGroupUri="peripheral/vadc/*/group/*/class/*" mResGrpUri="peripheral/vadc/*/group/*/class/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/VADC/VADC_0.dd#//@provided.22"/>
  </hwResources>
  <hwResources name="Source Event Interrupt" URI="http://resources/4.0.20/app/ADC_SCAN/0/hwres_nvicnode_srcevt" resourceGroupUri="" required="false" mResGrpUri="peripheral/cpu/0/nvic/interrupt/*"/>
  <connections URI="http://resources/4.0.20/app/ADC_SCAN/0/http://resources/4.0.20/app/ADC_SCAN/0/vs_adc_scan_sourceevent/http://resources/4.0.20/app/ADC_SCAN/0/vs_nvic_signal_src" systemDefined="true" sourceSignal="event_scan_source" targetSignal="sr_interrupt_signal" required="false" srcVirtualSignal="//@virtualSignals.6" targetVirtualSignal="//@virtualSignals.7"/>
  <connections URI="http://resources/4.0.20/app/ADC_SCAN/0/http://resources/4.0.20/app/ADC_SCAN/0/vs_adc_scan_classselect_out/http://resources/4.0.20/app/ADC_SCAN/0/vs_adc_scan_classselect_in" systemDefined="true" sourceSignal="class_select" targetSignal="scan_iclass_select" srcVirtualSignal="//@virtualSignals.8" targetVirtualSignal="//@virtualSignals.9"/>
  <connections URI="http://resources/4.0.20/app/ADC_SCAN/0/http://resources/4.0.20/app/ADC_SCAN/0/vs_adc_scan_to_global_signal/http://resources/4.0.20/app/ADC_SCAN/0/vs_adc_scan_scanglobal" systemDefined="true" sourceSignal="global_signal" targetSignal="scan_to_global" targetVirtualSignal="//@virtualSignals.0" proxySrcVirtualSignalUri="http://resources/4.0.22/app/GLOBAL_ADC/0/vs_global_adc_global" containingProxySignal="true">
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../GLOBAL_ADC/v4_0_22/GLOBAL_ADC_0.app#//@virtualSignals.0"/>
    <srcVirtualSignal href="../../GLOBAL_ADC/v4_0_22/GLOBAL_ADC_0.app#//@virtualSignals.0"/>
  </connections>
</ResourceModel:App>
