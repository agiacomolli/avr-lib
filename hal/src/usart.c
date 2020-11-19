#include <stdio.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include <hal/usart.h>

#if (AVR_UART_USE_USART1 == TRUE)
usart_driver_t USARTD1;

char usart1_oq_buf[128];
char usart1_iq_buf[128];

queue_t usart1_oq;
queue_t usart1_iq;
#endif

#if (AVR_UART_USE_USART2 == TRUE)
usart_driver_t USARTD2;

char usart2_oq_buf[128];
char usart2_iq_buf[128];

queue_t usart2_oq;
queue_t usart2_iq;
#endif

#if (AVR_UART_USE_USART3 == TRUE)
usart_driver_t USARTD3;

char usart3_oq_buf[128];
char usart3_iq_buf[128];

queue_t usart3_oq;
queue_t usart3_iq;
#endif

#if (AVR_UART_USE_USART4 == TRUE)
usart_driver_t USARTD4;

char usart4_oq_buf[128];
char usart4_iq_buf[128];

queue_t usart4_oq;
queue_t usart4_iq;
#endif

static unsigned short compute_baudrate(uint32_t baud)
{
    /* Define a taxa de comunicação (pg 203). */
    return (unsigned short)((F_CPU / 16) / (baud) - 1);
}

#if (AVR_UART_USE_USART1 == TRUE)
ISR(USART0_RX_vect)
{
    usart_driver_t *usartp = &USARTD1;

    /* Discards data if queue is full. */
    if (usartp->iq->count == usartp->iq->capacity) {
        (void) UDR0;
        return;
    }

    usartp->iq->tail++;
    usartp->iq->count++;

    usartp->iq->buf[usartp->iq->tail % usartp->iq->capacity] = UDR0;

#if 0
    uint8_t sra;

    sra = UCSR0A;

    //if (sra & ((1 << DOR0) | (1 << UPE0) | (1 << FE0)))
    //    set_error(sra, &SD1);

    /* TODO: adicionar ao buffer circular e atualizar os índices. */
#endif
}

ISR(USART0_UDRE_vect)
{
    usart_driver_t *usartp = &USARTD1;

    /* Stop send if queue is empty. */
    if (usartp->oq->count == 0) {
        UCSR0B &= ~(1 << UDRIE0);
        return;
    }

    usartp->oq->count--;
    usartp->oq->head++;
    UDR0 = usartp->oq->buf[usartp->oq->head % usartp->oq->capacity];
}

static void usart0_init(usart_driver_t *usartp)
{
    unsigned short ubrr;

    ubrr = compute_baudrate(usartp->config->speed);

    /* Configura a taxa de comunicação nos registradores. */
    UBRR0H = ubrr >> 8;
    UBRR0L = ubrr;

    /* Habilita o módulo de envio e recepção de dados da USART0. */
    UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);

    /* Configura transmissão assíncrona, sem paridade,
       com 1 bit de parada e 8 bits de dados. */
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}
#endif

#if (AVR_UART_USE_USART2 == TRUE)
ISR(USART1_RX_vect)
{
    usart_driver_t *usartp = &USARTD2;

    /* Discards data if queue is full. */
    if (usartp->iq->count == usartp->iq->capacity) {
        (void) UDR1;
        return;
    }

    usartp->iq->tail++;
    usartp->iq->count++;

    usartp->iq->buf[usartp->iq->tail % usartp->iq->capacity] = UDR1;
}

ISR(USART1_UDRE_vect)
{
    usart_driver_t *usartp = &USARTD2;

    /* Stop send if queue is empty. */
    if (usartp->oq->count == 0) {
        UCSR1B &= ~(1 << UDRIE1);
        return;
    }

    usartp->oq->count--;
    usartp->oq->head++;
    UDR1 = usartp->oq->buf[usartp->oq->head % usartp->oq->capacity];
}

static void usart1_init(usart_driver_t *usartp)
{
    unsigned short ubrr;

    ubrr = compute_baudrate(usartp->config->speed);

    /* Configura a taxa de comunicação nos registradores. */
    UBRR1H = ubrr >> 8;
    UBRR1L = ubrr;

    /* Habilita o módulo de envio e recepção de dados da USART0. */
    UCSR1B = (1 << RXEN1) | (1 << TXEN1) | (1 << RXCIE1);

    /* Configura transmissão assíncrona, sem paridade,
       com 1 bit de parada e 8 bits de dados. */
    UCSR1C = (1 << UCSZ11) | (1 << UCSZ10);
}
#endif

#if (AVR_UART_USE_USART3 == TRUE)
ISR(USART2_RX_vect)
{
    usart_driver_t *usartp = &USARTD3;

    /* Discards data if queue is full. */
    if (usartp->iq->count == usartp->iq->capacity) {
        (void) UDR2;
        return;
    }

    usartp->iq->tail++;
    usartp->iq->count++;

    usartp->iq->buf[usartp->iq->tail % usartp->iq->capacity] = UDR2;
}

ISR(USART2_UDRE_vect)
{
    usart_driver_t *usartp = &USARTD3;

    /* Stop send if queue is empty. */
    if (usartp->oq->count == 0) {
        UCSR2B &= ~(1 << UDRIE2);
        return;
    }

    usartp->oq->count--;
    usartp->oq->head++;
    UDR2 = usartp->oq->buf[usartp->oq->head % usartp->oq->capacity];
}

static void usart2_init(usart_driver_t *usartp)
{
    unsigned short ubrr;

    ubrr = compute_baudrate(usartp->config->speed);

    /* Configura a taxa de comunicação nos registradores. */
    UBRR2H = ubrr >> 8;
    UBRR2L = ubrr;

    /* Habilita o módulo de envio e recepção de dados da USART2. */
    UCSR2B = (1 << RXEN2) | (1 << TXEN2) | (1 << RXCIE2);

    /* Configura transmissão assíncrona, sem paridade,
       com 1 bit de parada e 8 bits de dados. */
    UCSR2C = (1 << UCSZ21) | (1 << UCSZ20);
}
#endif

#if (AVR_UART_USE_USART4 == TRUE)
ISR(USART3_RX_vect)
{
    usart_driver_t *usartp = &USARTD4;

    /* Discards data if queue is full. */
    if (usartp->iq->count == usartp->iq->capacity) {
        (void) UDR3;
        return;
    }

    usartp->iq->tail++;
    usartp->iq->count++;

    usartp->iq->buf[usartp->iq->tail % usartp->iq->capacity] = UDR3;
}

ISR(USART3_UDRE_vect)
{
    usart_driver_t *usartp = &USARTD4;

    /* Stop send if queue is empty. */
    if (usartp->oq->count == 0) {
        UCSR3B &= ~(1 << UDRIE3);
        return;
    }

    usartp->oq->count--;
    usartp->oq->head++;
    UDR3 = usartp->oq->buf[usartp->oq->head % usartp->oq->capacity];
}

static void usart3_init(usart_driver_t *usartp)
{
    unsigned short ubrr;

    ubrr = compute_baudrate(usartp->config->speed);

    /* Configura a taxa de comunicação nos registradores. */
    UBRR3H = ubrr >> 8;
    UBRR3L = ubrr;

    /* Habilita o módulo de envio e recepção de dados da USART3. */
    UCSR3B = (1 << RXEN3) | (1 << TXEN3) | (1 << RXCIE3);

    /* Configura transmissão assíncrona, sem paridade,
       com 1 bit de parada e 8 bits de dados. */
    UCSR3C = (1 << UCSZ31) | (1 << UCSZ30);
}
#endif

void usart_init(usart_driver_t *usartp, const usart_config_t *config)
{
    usartp->config = config;

#if (AVR_UART_USE_USART1 == TRUE)
    if (usartp == &USARTD1) {
        usartp->oq = &usart1_oq;
        usartp->iq = &usart1_iq;

        queue_init(usartp->oq, usart1_oq_buf, 128);
        queue_init(usartp->iq, usart1_iq_buf, 128);

        usart0_init(usartp);
    }
#endif

#if (AVR_UART_USE_USART2 == TRUE)
    if (usartp == &USARTD2) {
        usartp->oq = &usart2_oq;
        usartp->iq = &usart2_iq;

        queue_init(usartp->oq, usart2_oq_buf, 128);
        queue_init(usartp->iq, usart2_iq_buf, 128);

        usart1_init(usartp);
    }
#endif

#if (AVR_UART_USE_USART3 == TRUE)
    if (usartp == &USARTD3) {
        usartp->oq = &usart3_oq;
        usartp->iq = &usart3_iq;

        queue_init(usartp->oq, usart3_oq_buf, 128);
        queue_init(usartp->iq, usart3_iq_buf, 128);

        usart2_init(usartp);
    }
#endif

#if (AVR_UART_USE_USART4 == TRUE)
    if (usartp == &USARTD4) {
        usartp->oq = &usart4_oq;
        usartp->iq = &usart4_iq;

        queue_init(usartp->oq, usart4_oq_buf, 128);
        queue_init(usartp->iq, usart4_iq_buf, 128);

        usart3_init(usartp);
    }
#endif
}

int usart_read(usart_driver_t *uartp, char *buf, int size)
{
    int i;

    cli();
    i = queue_read(uartp->iq, buf, size);
    sei();

    return i;
}

int usart_write(usart_driver_t *uartp, char *buf, int size)
{
    int i;

    /* TODO: Verificar se é necessário. */
    //_delay_ms(10);

    cli();
    i = queue_write(uartp->oq, buf, size);
    sei();

    if (i == 0)
        return 0;

#if (AVR_UART_USE_USART1 == TRUE)
    if (uartp == &USARTD1) {
        UCSR0B |= (1 << UDRIE0);
    }
#endif

#if (AVR_UART_USE_USART2 == TRUE)
    if (uartp == &USARTD2) {
        UCSR1B |= (1 << UDRIE1);
    }
#endif

#if (AVR_UART_USE_USART3 == TRUE)
    if (uartp == &USARTD3) {
        UCSR2B |= (1 << UDRIE2);
    }
#endif

#if (AVR_UART_USE_USART4 == TRUE)
    if (uartp == &USARTD4) {
        UCSR3B |= (1 << UDRIE3);
    }
#endif

    return i;
}

