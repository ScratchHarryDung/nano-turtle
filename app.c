//libary for the led
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_gpio.h"

//button libary
#include "sl_simple_button_instances.h"
#include "app_log.h"
#include "sl_simple_led_instances.h"

/***************************************************************************//**
 * @file
 * @brief Top level application functions
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

/***************************************************************************//**
 * Initialize application.
 ******************************************************************************/
void app_init(void)
{
}

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void)
{
}



//Button

//void sl_button_on_change(const sl_button_t *handle)
// {
//   if (sl_button_get_state(handle) == SL_SIMPLE_BUTTON_PRESSED){
//       if(&sl_button_btn0 == handle) {
//           app_log("Button is pressed\n");
//           GPIO_PinModeSet(gpioPortC, 1, gpioModePushPull, 0);
//       }
//   }
//
//   if (sl_button_get_state(handle) == SL_SIMPLE_BUTTON_RELEASED){
//       if(&sl_button_btn0 == handle) {
//           app_log("Button is released\n");
//       }
//   }
//
// }

void gpio()
{
    CHIP_Init();

    CMU_ClockEnable(cmuClock_GPIO, true);

    while (1) {
      // Do not remove this call: Silicon Labs components process action routine
      // must be called from the super loop.



      //LED ON/OFF


        // Led blinking

        GPIO_PinModeSet(gpioPortC, 1, gpioModePushPull, 1);
        GPIO_PinModeSet(gpioPortC, 2, gpioModePushPull, 1);
        GPIO_PinModeSet(gpioPortC, 3, gpioModePushPull, 1);
        GPIO_PinModeSet(gpioPortC, 0, gpioModePushPull, 1);

        for(volatile long i=0; i<100000000; i+=100);

        GPIO_PinModeSet(gpioPortC, 1, gpioModePushPull, 0);
        GPIO_PinModeSet(gpioPortC, 2, gpioModePushPull, 0);
        GPIO_PinModeSet(gpioPortC, 3, gpioModePushPull, 0);

        for(volatile long i=0; i<100000000; i+=100);
    }
}

