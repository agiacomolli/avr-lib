#include <hal/pal.h>

#include "board.h"

#if HAL_USE_PAL == TRUE

const pal_config_t pal_default_config = {
#ifdef PORTA
    { VAL_PORTA, VAL_DDRA },
#endif
#ifdef PORTB
    { VAL_PORTB, VAL_DDRB },
#endif
#ifdef PORTC
    { VAL_PORTC, VAL_DDRC },
#endif
#ifdef PORTD
    { VAL_PORTD, VAL_DDRD },
#endif
#ifdef PORTE
    { VAL_PORTE, VAL_DDRE },
#endif
#ifdef PORTF
    { VAL_PORTF, VAL_DDRF },
#endif
#ifdef PORTG
    { VAL_PORTG, VAL_DDRG },
#endif
#ifdef PORTH
    { VAL_PORTH, VAL_DDRH },
#endif
#ifdef PORTJ
    { VAL_PORTJ, VAL_DDRJ },
#endif
#ifdef PORTK
    { VAL_PORTK, VAL_DDRK },
#endif
#ifdef PORTL
    { VAL_PORTL, VAL_DDRL },
#endif
};

#endif /* HAL_USE_PAL == TRUE */

void board_init(void)
{
    pal_init(&pal_default_config);

    /* External interrupts setup, all disabled initially. */
    EICRA  = 0x00;
    EICRB  = 0x00;
    EIMSK  = 0x00;
}

