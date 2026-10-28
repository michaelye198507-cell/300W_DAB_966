//##############################################################################
//
// FILE:  uinv_main.c
//
// TITLE: This is the main file for the solution, following is the
//         <solution>.c -> solution source file
//         <solution>.h -> solution header file
//         <solution>_settings.h -> solution general settings
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

//
// Included Files
//
#include "board.h"
#include "device.h"
#include "c2000ware_libraries.h"
#include "packbalance_hal.h"
#include "packbalance.h"


// typedefs
//
//
typedef union 
{
  enum 
  {
    noTrip = 0,
    primOverCurrentTrip = 1,
    secOverCurrentTrip = 2,
    primOverVoltageTrip = 3,
    secOverVoltageTrip = 4,
    primTankOverCurrentTrip = 5,
  } PACKBALANCE_TripFlag_Enum;
  int32_t pad;
} PACKBALANCE_TripFlag_EnumType;

PACKBALANCE_TripFlag_EnumType PACKBALANCE_TripFlag;

typedef union 
{
  enum 
  {
    powerFlow_PrimToSec = PACKBALANCE_POWER_FLOW_PRIM_SEC,
    powerFlow_SecToPrim = PACKBALANCE_POWER_FLOW_SEC_PRIM,

  } PACKBALANCE_PowerFlowState_Enum;
  int32_t pad;
} PACKBALANCE_PowerFlowState_EnumType;

PACKBALANCE_PowerFlowState_EnumType PACKBALANCE_powerFlowStateActive, PACKBALANCE_powerFlowState;

//
// Main
//
void main(void) {

  //
  // Initialize device clock and peripherals
  //
  Device_init();

  //
  // Disable pin locks and enable internal pull-ups.
  //
  Device_initGPIO();

  //
  // Initialize PIE and clear PIE registers. Disables CPU interrupts.
  //
  Interrupt_initModule();

  //
  // Initialize the PIE vector table with pointers to the shell Interrupt
  // Service Routines (ISR).
  //
  Interrupt_initVectorTable();

  //
  // PinMux and Peripheral Initialization
  //
  SysCtl_disablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);
  Board_init();
  SRCDB_initGlobalVariables();

  //
  // C2000Ware Library initialization
  //
  C2000Ware_libraries_init();
  SysCtl_enablePeripheral(SYSCTL_PERIPH_CLK_TBCLKSYNC);

  //
  // Enable Global Interrupt (INTM) and real time interrupt (DBGM)
  //
  EINT;
  ERTM;

  while (1) 
  {
      if( (PACK_start == 0U)||(Pack_clearTrip == 0U) )
      {
      EPWM_forceTripZoneEvent(PACK_EPWM1_BASE, EPWM_TZ_FORCE_EVENT_OST);
      EPWM_forceTripZoneEvent(PACK_EPWM2_BASE, EPWM_TZ_FORCE_EVENT_OST);
      }
      PACK_start = 1U;
  }
}

__interrupt void INT_PACK_EPWM6_ISR(void)
{

    //GPIO_writePin(myGPIO0, 1);

  isrTicker_Test++;

  if(Pack_clearTrip == 1U)//enable PWM
  {
      PACK_HAL_clearPWMTripFlags(PACK_EPWM1_BASE);
      PACK_HAL_clearPWMTripFlags(PACK_EPWM2_BASE);

      if(Phaseshift_angle <= 0.1)
      {

       //   Phaseshift_angle=Phaseshift_angle+0.000001;

      }

  }

  PACK_runGiGvLoop();

  // Clear INT flag for this timer
  //
  EPWM_clearEventTriggerInterruptFlag(PACK_EPWM6_BASE);
  //
  // Acknowledge this interrupt to receive more interrupts from group 3
  //
  Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP3);


  EINT;
  //GPIO_writePin(myGPIO0, 0);
}

//
// End of File
//
