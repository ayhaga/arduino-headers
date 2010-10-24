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

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

/* watchdog change routines */
#define wdt_disable()\
    cli();\
    wdt_clear_flag();\
    wdt_reset_disable();\

#define wdt_enable(clock)\
    cli();\
    wdt_reset();\
    wdt_clear_flag();\
    wdt_reset_enable();\
    wdt_change_d##clock();\

#define wdt_change_clock(clock)\
    cli();\
    wdt_clear_flag();\
    wdt_clock_d##clock();\

#define wdt_reset() __asm__ __volatile__ ("wdr")

static inline void
wdt_reset_enable() { WDTCR |= _BV(WDE); }

static inline void
wdt_reset_disable() 
{ 
    WDTCR |= (_BV(WDCE) | _BV(WDE));
    WDTCR &= ~_BV(WDE);
}

static inline void
wdt_clear_flag() { MCUSR &= ~_BV(WDRF); }

/* watchdog interrupts */
#define wdt_interrupt() ISR(WDT_vect)

static inline void
wdt_interrupt_enable()  { WDTCR |= _BV(WDIE); }
static inline void
wdt_interrupt_disable() { WDTCR &= ~(_BV(WDIE)); }

/* prescaler settings */
static inline void
wdt_clock_d2() 
{
    WDTCR = (WDTCR & ~(_BV(WDP3) | _BV(WDP2) |  _BV(WDP1) | _BV(WDP0)));
}

static inline void
wdt_clock_d4() 
{
    WDTCR = (WDTCR & ~(_BV(WDP3) | _BV(WDP2) |  _BV(WDP1))) | _BV(WDP0);
}

static inline void
wdt_clock_d8() 
{
    WDTCR = (WDTCR & ~(_BV(WDP3) | _BV(WDP2) |  _BV(WDP0))) | _BV(WDP1);
}

static inline void
wdt_clock_d16() 
{
    WDTCR = (WDTCR & ~(_BV(WDP3) | _BV(WDP2))) |  _BV(WDP1) | _BV(WDP0);
}

static inline void
wdt_clock_d32() 
{
    WDTCR = (WDTCR & ~(_BV(WDP3) | _BV(WDP1) |  _BV(WDP0))) | _BV(WDP2);
}

static inline void
wdt_clock_d64() 
{
    WDTCR = (WDTCR & ~(_BV(WDP3) | _BV(WDP1))) |  _BV(WDP2) | _BV(WDP0);
}

static inline void
wdt_clock_d128() 
{
    WDTCR = (WDTCR & ~(_BV(WDP3) | _BV(WDP0))) |  _BV(WDP2) | _BV(WDP1);
}

static inline void
wdt_clock_d256() 
{
    WDTCR = (WDTCR & ~(_BV(WDP3))) | _BV(WDP2) |  _BV(WDP1) | _BV(WDP0);
}

static inline void
wdt_clock_d512() 
{
    WDTCR = (WDTCR & ~(_BV(WDP2) | _BV(WDP1) |  _BV(WDP0))) | _BV(WDP3);
}

static inline void
wdt_clock_d1024() {
    WDTCR = (WDTCR & ~(_BV(WDP2) | _BV(WDP1))) | _BV(WDP3) | _BV(WDP0);
}

#endif

