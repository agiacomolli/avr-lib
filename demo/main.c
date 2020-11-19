#include <stdio.h>
#include <string.h>
#include <avr/io.h>
#include <util/delay.h>

#include <board.h>

#include <hal/pal.h>
#include <hal/spi.h>
#include <hal/usart.h>

const usart_config_t usart_cfg = {
    .speed = 9600,
};

int main(void)
{
    int c;
    char buf[32];

    cli();

    board_init();

    usart_init(&USARTD1, &usart_cfg);
    usart_init(&USARTD3, &usart_cfg);

    sei();

    while (1) {
        c = usart_read(&USARTD1, buf, 32);
        if (c > 0) {
            usart_write(&USARTD3, buf, c);
        }

        c = usart_read(&USARTD3, buf, 32);
        if (c > 0) {
            usart_write(&USARTD1, buf, c);
        }

        _delay_ms(50);
    }

    return 0;
}

