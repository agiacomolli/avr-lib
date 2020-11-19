#ifndef BOARD_H
#define BOARD_H

#define IOPORT2_LEDR            5
#define IOPORT2_LEDG            6
#define IOPORT2_LEDB            7

/*
 * PA0  IN
 * PA1  IN
 * PA2  IN
 * PA3  IN
 * PA4  IN
 * PA5  IN
 * PA6  IN
 * PA7  IN
 */
#define VAL_DDRA    0x00    /* 0000 0000 */
#define VAL_PORTA   0x00

/*
 * PB0  IN
 * PB1  IN
 * PB2  IN
 * PB3  IN
 * PB4  IN
 * PB5  IN
 * PB6  IN
 * PB7  IN
 */
#define VAL_DDRB    0x00    /* 0000 0000 */
#define VAL_PORTB   0x08

/*
 * PC0  IN
 * PC1  IN
 * PC2  IN
 * PC3  IN
 * PC4  IN
 * PC5  IN
 * PC6  IN
 * PC7  IN
 */
#define VAL_DDRC    0x00    /* 0000 0000 */
#define VAL_PORTC   0xFF

/*
 * PD0  IN
 * PD1  IN
 * PD2  IN
 * PD3  IN
 * PD4  IN
 * PD5  IN
 * PD6  IN
 * PD7  IN
 */
#define VAL_DDRD    0x00    /* 0000 0000 */
#define VAL_PORTD   0x1F

/*
 * PE0  IN      USART0_RX   RX0
 * PE1  OUT     USART0_TX   TX0
 * PE2  IN
 * PE3  IN
 * PE4  IN
 * PE5  IN
 * PE6  IN
 * PE7  IN
 */
#define VAL_DDRE    0x02    /* 0000 0010 */
#define VAL_PORTE   0xFF

/*
 * PF0  IN
 * PF1  IN
 * PF2  IN
 * PF3  IN
 * PF4  IN
 * PF5  IN
 * PF6  IN
 * PF7  IN
 */
#define VAL_DDRF    0x00    /* 1111 1111 */
#define VAL_PORTF   0xFF

/*
 * PG0  IN
 * PG1  IN
 * PG2  IN
 * PG3  IN
 * PG4  IN
 * PG5  IN
 * PG6  IN
 * PG7  IN
 */
#define VAL_DDRG    0x00    /* 0000 0000 */
#define VAL_PORTG   0xFC

/*
 * PH0  IN      USART_RX    RX2
 * PH1  OUT     USART_TX    TX2
 * PH2  IN
 * PH3  IN
 * PH4  IN
 * PH5  IN
 * PH6  IN
 * PH7  IN
 */
#define VAL_DDRH    0x02    /* 0000 0010 */
#define VAL_PORTH   0xFF

/*
 * PJ0  IN
 * PJ1  IN
 * PJ2  IN
 * PJ3  IN
 * PJ4  IN
 * PJ5  IN
 * PJ6  IN
 * PJ7  IN
 */
#define VAL_DDRJ    0x00    /* 0000 0000 */
#define VAL_PORTJ   0xFF

/*
 * PK0  IN
 * PK1  IN
 * PK2  IN
 * PK3  IN
 * PK4  IN
 * PK5  IN
 * PK6  IN
 * PK7  IN
 */
#define VAL_DDRK    0x00    /* 0000 0000 */
#define VAL_PORTK   0xFF

/*
 * PL0  IN
 * PL1  IN
 * PL2  IN
 * PL3  IN
 * PL4  IN
 * PL5  IN
 * PL6  IN
 * PL7  IN
 */
#define VAL_DDRL    0x00    /* 0000 0000 */
#define VAL_PORTL   0xFF

extern void board_init(void);

#endif /* BOARD_H */

