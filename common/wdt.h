/*
 * This file is part of arduino-headers.
 *
 * arduino-headers is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or(at your option) any later version.
 *
 * arduino-headers is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with arduino-headers.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _ARDUINO_WDT_H
#define _ARDUINO_WDT_H

#include <avr/wdt.h>
#include <avr/interrupt.h>

#if defined(WDTCSR)
#  define _WDT_REG  WDTCSR
#else
#  define _WDT_REG  WDTCR
#endif

static inline void wdt_interrupt_enable()  { _WDT_REG |= _BV(WDIE); }
static inline void wdt_interrupt_disable() { _WDT_REG &= ~_BV(WDIE); }

#define wdt_interrupt() ISR(WDT_vect)

#endif
