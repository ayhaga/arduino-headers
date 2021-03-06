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

#ifndef _ARDUINO_SERIAL_H
#define _ARDUINO_SERIAL_H

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#define BAUD_PRESCALE(baud) (((F_CPU / (baud * 8UL))) - 1)

/* baud settings */
static inline void
serial_baud_2400()
{
	UCSR0A = (UCSR0A & ~(_BV(FE0) | _BV(DOR0) | _BV(UPE0)))
	       | _BV(U2X0);
	UBRR0 = BAUD_PRESCALE(2400);
}

static inline void
serial_baud_4800()
{
	UCSR0A = (UCSR0A & ~(_BV(FE0) | _BV(DOR0) | _BV(UPE0)))
	       | _BV(U2X0);
	UBRR0 = BAUD_PRESCALE(4800);
}

static inline void
serial_baud_9600()
{
	UCSR0A &= ~(_BV(FE0) | _BV(DOR0) | _BV(UPE0) | _BV(U2X0));
	UBRR0 = BAUD_PRESCALE(9600);
}

static inline void
serial_baud_14400()
{
	UCSR0A = (UCSR0A & ~(_BV(FE0) | _BV(DOR0) | _BV(UPE0)))
	       | _BV(U2X0);
	UBRR0 = BAUD_PRESCALE(14400);
}

static inline void
serial_baud_19200()
{
	UCSR0A &= ~(_BV(FE0) | _BV(DOR0) | _BV(UPE0) | _BV(U2X0));
	UBRR0 = BAUD_PRESCALE(19200);
}

static inline void
serial_baud_28800()
{
	UCSR0A = (UCSR0A & ~(_BV(FE0) | _BV(DOR0) | _BV(UPE0)))
	       | _BV(U2X0);
	UBRR0 = BAUD_PRESCALE(28800);
}

static inline void
serial_baud_38400()
{
	UCSR0A &= ~(_BV(FE0) | _BV(DOR0) | _BV(UPE0) | _BV(U2X0));
	UBRR0 = BAUD_PRESCALE(38400);
}

static inline void
serial_baud_57600()
{
	UCSR0A = (UCSR0A & ~(_BV(FE0) | _BV(DOR0) | _BV(UPE0)))
	       | _BV(U2X0);
	UBRR0 = BAUD_PRESCALE(57600);
}

static inline void
serial_baud_250k()
{
	UCSR0A &= ~(_BV(FE0) | _BV(DOR0) | _BV(UPE0) | _BV(U2X0));
	UBRR0 = BAUD_PRESCALE(250000);
}

static inline void
serial_baud_500k()
{
	UCSR0A &= ~(_BV(FE0) | _BV(DOR0) | _BV(UPE0) | _BV(U2X0));
	UBRR0 = BAUD_PRESCALE(500000);
}

/* bit size */
static inline void
serial_bits_5()
{
	UCSR0B &= ~(_BV(UCSZ02));
	UCSR0C = UCSR0C & ~(_BV(UCSZ01) | _BV(UCSZ00));
}

static inline void
serial_bits_6()
{
	UCSR0B &= ~(_BV(UCSZ02));
	UCSR0C = (UCSR0C & ~(_BV(UCSZ01))) | _BV(UCSZ00);
}

static inline void
serial_bits_7()
{
	UCSR0B &= ~(_BV(UCSZ02));
	UCSR0C = (UCSR0C & ~(_BV(UCSZ00))) | _BV(UCSZ01);
}

static inline void
serial_bits_8()
{
	UCSR0B &= ~(_BV(UCSZ02));
	UCSR0C = UCSR0C | _BV(UCSZ01) | _BV(UCSZ00);
}

static inline void
serial_bits_9()
{
	UCSR0B |= _BV(UCSZ02);
	UCSR0C = UCSR0C | _BV(UCSZ01) | _BV(UCSZ00);
}

/* parity */
static inline void
serial_parity_off()
{
	UCSR0C = UCSR0C & ~(_BV(UPM01) | _BV(UPM00));
}

static inline void
serial_parity_even()
{
	UCSR0C = (UCSR0C & ~(_BV(UPM00))) | _BV(UPM01);
}

static inline void
serial_parity_odd()
{
	UCSR0C = UCSR0C | _BV(UPM01) | _BV(UPM00);
}

/* stop bits */
static inline void
serial_stopbits_1() { UCSR0C &= ~(_BV(USBS0)); }
static inline void
serial_stopbits_2() { UCSR0C |= _BV(USBS0); }

/* combined mode settings */
static inline void
serial_mode_8n1()
{
	UCSR0B &= ~(_BV(UCSZ02));
	UCSR0C = (UCSR0C & ~(_BV(UPM01) | _BV(UPM00) | _BV(USBS0)))
	       | _BV(UCSZ01) | _BV(UCSZ00);
}

static inline void
serial_mode_8e1()
{
	UCSR0B &= ~(_BV(UCSZ02));
	UCSR0C = (UCSR0C & ~(_BV(UPM00) | _BV(USBS0)))
	       | _BV(UPM01) | _BV(UCSZ01) | _BV(UCSZ00);
}

static inline void
serial_mode_8o1()
{
	UCSR0B &= ~(_BV(UCSZ02));
	UCSR0C = (UCSR0C & ~(_BV(USBS0)))
	       | _BV(UPM01) | _BV(UPM00) | _BV(UCSZ01) | _BV(UCSZ00);
}

static inline void
serial_mode_8n2()
{
	UCSR0B &= ~(_BV(UCSZ02));
	UCSR0C = (UCSR0C & ~(_BV(UPM01) | _BV(UPM00)))
	       | _BV(USBS0) | _BV(UCSZ01) | _BV(UCSZ00);
}

static inline void
serial_mode_8e2()
{
	UCSR0B &= ~(_BV(UCSZ02));
	UCSR0C = (UCSR0C & ~(_BV(UPM00)))
	       | _BV(UPM01) | _BV(USBS0) | _BV(UCSZ01) | _BV(UCSZ00);
}

static inline void
serial_mode_8o2()
{
	UCSR0B &= ~(_BV(UCSZ02));
	UCSR0C = UCSR0C
	       | _BV(UPM01) | _BV(UPM00) | _BV(USBS0) | _BV(UCSZ01) | _BV(UCSZ00);
}

/* receiver and transmitter */
static inline void
serial_receiver_enable()     { UCSR0B |= _BV(RXEN0); }
static inline void
serial_receiver_disable()    { UCSR0B &= ~(_BV(RXEN0)); }
static inline void
serial_transmitter_enable()  { UCSR0B |= _BV(TXEN0); }
static inline void
serial_transmitter_disable() { UCSR0B &= ~(_BV(TXEN0)); }

/* interrupts */
static inline void
serial_interrupt_dre_enable()  { UCSR0B |= _BV(UDRIE0); }
static inline void
serial_interrupt_dre_disable() { UCSR0B &= ~(_BV(UDRIE0)); }
static inline uint8_t
serial_interrupt_dre_enabled() { return UCSR0B & _BV(UDRIE0); }
static inline void
serial_interrupt_rx_enable()   { UCSR0B |= _BV(RXCIE0); }
static inline void
serial_interrupt_rx_disable()  { UCSR0B &= ~(_BV(RXCIE0)); }
static inline uint8_t
serial_interrupt_rx_enabled()  { return UCSR0B & _BV(RXCIE0); }
static inline void
serial_interrupt_tx_enable()   { UCSR0B |= _BV(TXCIE0); }
static inline void
serial_interrupt_tx_disable()  { UCSR0B &= ~(_BV(TXCIE0)); }
static inline uint8_t
serial_interrupt_tx_enabled()  { return UCSR0B & _BV(TXCIE0); }

#define serial_interrupt_dre()       ISR(USART_UDRE_vect)
#define serial_interrupt_dre_naked() ISR(USART_UDRE_vect, ISR_NAKED)
#define serial_interrupt_dre_empty() EMPTY_INTERRUPT(USART_UDRE_vect)
#define serial_interrupt_rx()        ISR(USART_RX_vect)
#define serial_interrupt_rx_naked()  ISR(USART_RX_vect, ISR_NAKED)
#define serial_interrupt_rx_empty()  EMPTY_INTERRUPT(USART_RX_vect)
#define serial_interrupt_tx()        ISR(USART_TX_vect)
#define serial_interrupt_tx_naked()  ISR(USART_TX_vect, ISR_NAKED)
#define serial_interrupt_tx_empty()  EMPTY_INTERRUPT(USART_TX_vect)

static inline uint8_t
serial_readable()       { return UCSR0A & _BV(RXC0); }
static inline uint8_t
serial_read()           { return UDR0; }
static inline uint8_t
serial_writeable()      { return UCSR0A & _BV(UDRE0); }
static inline void
serial_write(uint8_t c) { UDR0 = c; }

#endif
