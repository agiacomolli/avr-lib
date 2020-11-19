#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <avr/io.h>
#include <avr/interrupt.h>

#include <hal/spi.h>

#if 0
#include <hal/usart.h>
#endif

#define DUMMY_SPI_SEND_VALUE    0xFF

spi_driver_t SPID1;

ISR(SPI_STC_vect) {
    spi_driver_t *spip = &SPID1;

#if 0
    char buf[256];

    usart_puts("SPI interrupt\r\n");

    sprintf(buf, "\trxbuf: %p\r\n", spip->rxbuf);
    usart_puts(buf);
    sprintf(buf, "\ttxbuf: %p\r\n", spip->txbuf);
    usart_puts(buf);
    sprintf(buf, "\texidx: %d\r\n", spip->exidx);
    usart_puts(buf);
    sprintf(buf, "\texbytes: %d\r\n", spip->exbytes);
    usart_puts(buf);
    sprintf(buf, "\tdone: %d\r\n", spip->done);
    usart_puts(buf);
#endif

    /* A new value has arrived, store it if we are interested in it. */
    if (spip->rxbuf) {
        spip->rxbuf[spip->exidx] = SPDR;

#if 0
        sprintf(buf, "\tspdr: %d\r\n", spip->rxbuf[spip->exidx]);
        usart_puts(buf);
#endif
    }

    /* Check if we are done. If not, send the next byte. */
    if (++(spip->exidx) >= spip->exbytes) {
        spip->done = 1;
    } else {
        /* If there is a buffer with values to be send, then use it. If not,
           send a dummy value. */
        if (spip->txbuf) {
            SPDR = spip->txbuf[spip->exidx];
        } else {
            SPDR = DUMMY_SPI_SEND_VALUE;
        }
    }
}

int spi_init(spi_driver_t *spip, const spi_config_t *config)
{
    if (spip == NULL)
        return -1;

    if (config == NULL)
        return -1;

    spip->config = config;

    /* TODO: Verificar se é necessário definir a direção dos pinos
             na inicialização do driver. */

    /* Habilita o clock do SPI utilizando o Power Reduction Register. */
    PRR0 &= ~(1 << PRSPI);

    /* Habilita o módulo SPI como master com prescaler Fosc/16. */
    SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);

    SPSR = (1 << SPI2X);

    /* Dummy reads before enabling interrupt. */
    (void) SPSR;
    (void) SPDR;

    /* Enable SPI interrupts. */
    SPCR |= 1 << SPIE;

    return 0;
}

#if 0
static void spi_select(spi_driver_t *spip)
{
    (void) spip;

    PORTB &= ~(1 << 0);
}

static void spi_unselect(spi_driver_t *spip)
{
    (void) spip;

    PORTB |= 1 << 0;
}
#endif

int spi_exchange(spi_driver_t *spip, int n, void *txbuf, void *rxbuf)
{
    spip->txbuf = txbuf;
    spip->rxbuf = rxbuf;
    spip->exidx = 0;
    spip->exbytes = n;

    spip->done = 0;

    SPDR = (spip->txbuf ? spip->txbuf[0] : DUMMY_SPI_SEND_VALUE);

    /* TODO: Adicionar timeout. */
    while (!spip->done);

    return 0;
}

int spi_read(spi_driver_t *spip, int n, void *buf)
{
    int ret;

    ret = spi_exchange(spip, n, NULL, (uint8_t *) buf);

    return ret;
}

int spi_write(spi_driver_t *spip, int n, void *buf)
{
    int ret;

    ret = spi_exchange(spip, n, (uint8_t *) buf, NULL);

    return ret;
}

