// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define SERIAL_USART_FULL_DUPLEX   // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN B6     // USART TX pin
#define SERIAL_USART_RX_PIN B7     // USART RX pin

#define QUICK_TAP_TERM 250
#define TAPPING_TERM 250
#define COMBO_TERM 25
#define PERMISSIVE_HOLD
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#define BOOTMAGIC_ROW 0
#define BOOTMAGIC_COLUMN 1

#define BOOTMAGIC_ROW_RIGHT 0
#define BOOTMAGIC_COLUMN_RIGHT 10
/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
