<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="GLOBAL_HRPWM" URI="http://resources/4.0.14/app/GLOBAL_HRPWM/0" description="APP initializes HRPWM global register set configuration" version="4.0.14" minDaveVersion="4.0.0" instanceLabel="GLOBAL_HRPWM_0" appLabel="">
  <upwardMapList xsi:type="ResourceModel:RequiredApp" href="../../HRPWM/v4_1_22/HRPWM_0.app#//@requiredApps.1"/>
  <properties singleton="true" provideInit="true" sharable="true"/>
  <virtualSignals name="global_signal" URI="http://resources/4.0.14/app/GLOBAL_HRPWM/0/vs_global_hrpwm_globalsignal" hwSignal="global_signal" hwResource="//@hwResources.0">
    <upwardMapList xsi:type="ResourceModel:Connections" href="../../HRPWM/v4_1_22/HRPWM_0.app#//@connections.1"/>
    <upwardMapList xsi:type="ResourceModel:Connections" href="../../HRPWM/v4_1_22/HRPWM_0.app#//@connections.2"/>
  </virtualSignals>
  <requiredApps URI="http://resources/4.0.14/app/GLOBAL_HRPWM/0/appres_clock_0" requiredAppName="CLOCK_XMC4" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../CLOCK_XMC4/v4_0_24/CLOCK_XMC4_0.app#/"/>
  </requiredApps>
  <hwResources name="Global" URI="http://resources/4.0.14/app/GLOBAL_HRPWM/0/hwres_global_hrpwm_module" resourceGroupUri="peripheral/hrpwm/*/global" mResGrpUri="peripheral/hrpwm/*/global">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/HRPWM0/HRPWM0_0.dd#//@provided.13"/>
  </hwResources>
</ResourceModel:App>
