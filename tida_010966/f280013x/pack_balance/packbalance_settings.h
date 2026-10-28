//##############################################################################
//
// FILE:   packbalance_settings.h
//
// TITLE: This is the settings.h file, which contains all the project level
//        parameter settings
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

#ifndef PACKBALANCE_SETTINGS_H_
#define PACKBALANCE_SETTINGS_H_

#include "DCLF32.h"
#define SRCDB_GI DCL_DF13
#define SRCDB_GV DCL_DF13
#define SRCDB_GI_IMMEDIATE_RUN DCL_runDF13_C2
#define SRCDB_GI_PRECOMPUTE_RUN DCL_runDF13_C3
#define SRCDB_GV_IMMEDIATE_RUN DCL_runDF13_C2
#define SRCDB_GV_PRECOMPUTE_RUN DCL_runDF13_C3

#define SRCDB_GI1_2P2Z_A1    (float32_t) -1.0
#define SRCDB_GI1_2P2Z_A2    (float32_t) 0.0
#define SRCDB_GI1_2P2Z_A3    (float32_t) 0.0000000000
#define SRCDB_GI1_2P2Z_B0    (float32_t) 0.011
#define SRCDB_GI1_2P2Z_B1    (float32_t) -0.009
#define SRCDB_GI1_2P2Z_B2    (float32_t) 0.0
#define SRCDB_GI1_2P2Z_B3    (float32_t) 0.0000000000

#define SRCDB_GV1_2P2Z_A1    (float32_t) -1.0
#define SRCDB_GV1_2P2Z_A2    (float32_t) 0.0
#define SRCDB_GV1_2P2Z_A3    (float32_t) 0.0000000000
#define SRCDB_GV1_2P2Z_B0    (float32_t) 0.02
#define SRCDB_GV1_2P2Z_B1    (float32_t) 0
#define SRCDB_GV1_2P2Z_B2    (float32_t) 0.0
#define SRCDB_GV1_2P2Z_B3    (float32_t) 0.0000000000

#define SRCDB_GI_OUT_MAX   ((float32_t)150)
#define SRCDB_GI_OUT_MIN   ((float32_t)-100)
#define SRCDB_GV_OUT_MAX   ((float32_t)80)
#define SRCDB_GV_OUT_MIN   ((float32_t)-80)

//
// Control mode
// 1 -> Voltage
// 2 -> Current
// 3 -> Debug
//
#define PACKBALANCE_VOLTAGE_MODE 1
#define PACKBALANCE_CURRENT_MODE 2
#define PACKBALANCE_DEBUG_MODE 0

//
// Power flow
// 1 -> PRIM to SEC
// 2 -> SEC to PRIM
//
#define PACKBALANCE_POWER_FLOW_PRIM_SEC 1
#define PACKBALANCE_POWER_FLOW_SEC_PRIM 2

//
// Build configuration
// 1 ->  Open Loop Check
// 2 ->  Closed Loop Check
//
#define PACKBALANCE_OPEN_LOOP_BUILD 1
#define PACKBALANCE_CLOSED_LOOP_BUILD 2

// PACKBALANCE LAB
// Power Flow from Primary -> Secondary
// 1 -> Open loop check for PWM drivers,
// 2 -> Closed loop check with current loop,
// 3 -> Closed loop check with voltage loop
//
// Power Flow from Secondary -> Primary
// 4 -> Open loop check for PWM driver,
// 5 -> Closed loop check with current loop,
// 6 -> Closed loop check with voltage loop

#define PACKBALANCE_LAB 6

#if PACKBALANCE_LAB == 1//Forward 24-48 openloop debug
#define PACKBALANCE_POWER_FLOW PACKBALANCE_POWER_FLOW_PRIM_SEC
#define PACKBALANCE_INCR_BUILD PACKBALANCE_OPEN_LOOP_BUILD
#define PACKBALANCE_WORK_MODE PACKBALANCE_DEBUG_MODE
#endif

#if PACKBALANCE_LAB == 2//Forward 24-48 closeloop current mode
#define PACKBALANCE_POWER_FLOW PACKBALANCE_POWER_FLOW_PRIM_SEC
#define PACKBALANCE_INCR_BUILD PACKBALANCE_CLOSED_LOOP_BUILD
#define PACKBALANCE_WORK_MODE PACKBALANCE_CURRENT_MODE
#endif

#if PACKBALANCE_LAB == 3//Forward 24-48 closeloop voltage mode
#define PACKBALANCE_POWER_FLOW PACKBALANCE_POWER_FLOW_PRIM_SEC
#define PACKBALANCE_INCR_BUILD PACKBALANCE_CLOSED_LOOP_BUILD
#define PACKBALANCE_WORK_MODE PACKBALANCE_VOLTAGE_MODE
#endif

#if PACKBALANCE_LAB == 4//reverse 48-24 openloop debug
#define PACKBALANCE_POWER_FLOW PACKBALANCE_POWER_FLOW_SEC_PRIM
#define PACKBALANCE_INCR_BUILD PACKBALANCE_OPEN_LOOP_BUILD
#define PACKBALANCE_WORK_MODE PACKBALANCE_DEBUG_MODE
#endif

#if PACKBALANCE_LAB == 5//reverse 48-24 closeloop current mode
#define PACKBALANCE_POWER_FLOW PACKBALANCE_POWER_FLOW_SEC_PRIM
#define PACKBALANCE_INCR_BUILD PACKBALANCE_CLOSED_LOOP_BUILD
#define PACKBALANCE_WORK_MODE PACKBALANCE_CURRENT_MODE
#endif

#if PACKBALANCE_LAB == 6//reverse 48-24 closeloop voltage mode
#define PACKBALANCE_POWER_FLOW PACKBALANCE_POWER_FLOW_SEC_PRIM
#define PACKBALANCE_INCR_BUILD PACKBALANCE_CLOSED_LOOP_BUILD
#define PACKBALANCE_WORK_MODE PACKBALANCE_VOLTAGE_MODE
#endif

#endif /* PACKBALANCE_SETTINGS_H_ */
