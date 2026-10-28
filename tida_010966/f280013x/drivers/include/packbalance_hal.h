//##############################################################################
//
// FILE:   packbalance_hal.h
//
// TITLE:  Abstraction layer for peripheral specific functions
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

#ifndef PACKBALANCE_HAL_H_
#define PACKBALANCE_HAL_H_

#include "board.h"
#include "device.h"

#pragma FUNC_ALWAYS_INLINE(PACK_HAL_clearPWMTripFlags)
static inline void PACK_HAL_clearPWMTripFlags(uint32_t base)
{
    //
    // clear all the configured trip sources for the PWM module
    //
    EPWM_clearTripZoneFlag(base,
                           ( EPWM_TZ_INTERRUPT_OST |
                             EPWM_TZ_INTERRUPT_CBC |
                             EPWM_TZ_INTERRUPT_DCAEVT1 )
                           );
}

#endif /* PACKBALANCE_HAL_H_ */
