//##############################################################################
//
// FILE:   packbalance_user_settings.h
//
// TITLE:  Contains user level parameters settings
//
//#############################################################################
// $TI Release: TIDA_010966 v1.00.00.00 $
// $Release Date: Sun Aug  2 16:35:51 UTC 2026 $
// $Copyright:
// Copyright (C) 2026 Texas Instruments Incorporated - http://www.ti.com/
//
// ALL RIGHTS RESERVED
// $
//#############################################################################

#ifndef PACKBALANCE_USER_SETTINGS_H_
#define PACKBALANCE_USER_SETTINGS_H_

#define Pack_ADC_PU_SCALE_FACTOR  ((float32_t)0.000244140625)
#define PRI_CURRENT_REF 1.0f
#define PRI_VOLTAGE_REF 24.0f
#define INITIAL_PRD 400U
#define VOLTAGE_RATIO 2.0f
#define ZVS_COEFFICIENT 0.8f

#ifndef PI
#define PI ((float32_t)3.141592653589)
#endif

#define Pack_IPRIM_ADCRESULTREGBASE ADCARESULT_BASE
#define Pack_IPRIM_ADCREAD_0 ADC_readResult(Pack_IPRIM_ADCRESULTREGBASE, Pack_balance_IPRIM_ADC_SOC_NO_0)
#define Pack_IPRIM_ADCREAD_1 ADC_readResult(Pack_IPRIM_ADCRESULTREGBASE, Pack_balance_IPRIM_ADC_SOC_NO_1)
#define Pack_IPRIM_ADCREAD_2 ADC_readResult(Pack_IPRIM_ADCRESULTREGBASE, Pack_balance_IPRIM_ADC_SOC_NO_2)
#define Pack_IPRIM_ADCREAD_3 ADC_readResult(Pack_IPRIM_ADCRESULTREGBASE, Pack_balance_IPRIM_ADC_SOC_NO_3)
#define Pack_IPRIM_ADCREAD_4 ADC_readResult(Pack_IPRIM_ADCRESULTREGBASE, Pack_balance_IPRIM_ADC_SOC_NO_4)
#define Pack_IPRIM_ADCREAD_5 ADC_readResult(Pack_IPRIM_ADCRESULTREGBASE, Pack_balance_IPRIM_ADC_SOC_NO_5)
#define Pack_IREF_ADCREAD_6 ADC_readResult(Pack_IPRIM_ADCRESULTREGBASE, Pack_balance_IREF_ADC_SOC_NO_6)

#define Pack_IPRIM_ADCREAD ((Pack_IPRIM_ADCREAD_0 + Pack_IPRIM_ADCREAD_1 + Pack_IPRIM_ADCREAD_2 + Pack_IPRIM_ADCREAD_3 + Pack_IPRIM_ADCREAD_4 + Pack_IPRIM_ADCREAD_5) * (1.0 / 6.0))
#define Pack_IREF_ADCREAD (Pack_IREF_ADCREAD_6)

#define Pack_VPRIM_ADCRESULTREGBASE ADCCRESULT_BASE
#define Pack_VPRIM_ADCREAD_0 ADC_readResult(Pack_VPRIM_ADCRESULTREGBASE, Pack_balance_VPRIM_ADC_SOC_NO_0)
#define Pack_VPRIM_ADCREAD_1 ADC_readResult(Pack_VPRIM_ADCRESULTREGBASE, Pack_balance_VPRIM_ADC_SOC_NO_1)
#define Pack_VPRIM_ADCREAD_2 ADC_readResult(Pack_VPRIM_ADCRESULTREGBASE, Pack_balance_VPRIM_ADC_SOC_NO_2)
#define Pack_VPRIM_ADCREAD_3 ADC_readResult(Pack_VPRIM_ADCRESULTREGBASE, Pack_balance_VPRIM_ADC_SOC_NO_3)
#define Pack_VPRIM_ADCREAD_4 ADC_readResult(Pack_VPRIM_ADCRESULTREGBASE, Pack_balance_VPRIM_ADC_SOC_NO_4)
#define Pack_VPRIM_ADCREAD_5 ADC_readResult(Pack_VPRIM_ADCRESULTREGBASE, Pack_balance_VPRIM_ADC_SOC_NO_5)

#define Pack_VSEC_ADCREAD_6 ADC_readResult(Pack_VPRIM_ADCRESULTREGBASE, Pack_balance_VSEC_ADC_SOC_NO_6)
#define Pack_VSEC_ADCREAD_7 ADC_readResult(Pack_VPRIM_ADCRESULTREGBASE, Pack_balance_VSEC_ADC_SOC_NO_7)
#define Pack_VSEC_ADCREAD_8 ADC_readResult(Pack_VPRIM_ADCRESULTREGBASE, Pack_balance_VSEC_ADC_SOC_NO_8)
#define Pack_VSEC_ADCREAD_9 ADC_readResult(Pack_VPRIM_ADCRESULTREGBASE, Pack_balance_VSEC_ADC_SOC_NO_9)
#define Pack_VSEC_ADCREAD_10 ADC_readResult(Pack_VPRIM_ADCRESULTREGBASE, Pack_balance_VSEC_ADC_SOC_NO_10)
#define Pack_VSEC_ADCREAD_11 ADC_readResult(Pack_VPRIM_ADCRESULTREGBASE, Pack_balance_VSEC_ADC_SOC_NO_11)

#define Pack_VPRIM_ADCREAD ((Pack_VPRIM_ADCREAD_0 + Pack_VPRIM_ADCREAD_1 + Pack_VPRIM_ADCREAD_2 + Pack_VPRIM_ADCREAD_3 + Pack_VPRIM_ADCREAD_4 + Pack_VPRIM_ADCREAD_5) * (1.0 / 6.0))

#define Pack_VSEC_ADCREAD ((Pack_VSEC_ADCREAD_6 + Pack_VSEC_ADCREAD_7 + Pack_VSEC_ADCREAD_8 + Pack_VSEC_ADCREAD_9 + Pack_VSEC_ADCREAD_10 + Pack_VSEC_ADCREAD_11) * (1.0 / 6.0))

#endif /* PACKBALANCE_USER_SETTINGS_H_ */
