#ifndef HAL_SPI_H
#define HAL_SPI_H

#include <halconf.h>

#if (HAL_USE_SPI == TRUE)

#include <stdint.h>

typedef struct hal_spi_driver spi_driver_t;

typedef struct hal_spi_config spi_config_t;

typedef void (*spicallback_t)(spi_driver_t *spip);

struct hal_spi_config {
    /* Ponteiro para a função de callback. */
    spicallback_t end_cb;

    /* Porta do chip select. */
    int ssport;

    /* Pino do chip select. */
    int sspad;
};

struct hal_spi_driver {
    /* Ponteiro para a estrutura de configuração do driver. */
    const spi_config_t  *config;

    /* Ponteiro para o buffer com os dados de saída. */
    uint8_t *txbuf;

    /* Ponteiro para o buffer onde os dados recebidos são armazenados. */
    uint8_t *rxbuf;

    /* Número de bytes que serão enviados. */
    int exbytes;

    /* Índice atual para o buffer de envio dos dados. */
    int exidx;

    /* Flag que indica o fim da transmissão. */
    volatile int done;
};

/* Instância do driver. */
extern spi_driver_t SPID1;

extern int spi_init(spi_driver_t *spip, const spi_config_t *config);

extern int spi_read(spi_driver_t *spip, int n, void *buf);

extern int spi_write(spi_driver_t *spip, int n, void *buf);

extern int spi_exchange(spi_driver_t *spip, int n, void *txbuf, void *rxbuf);

#endif /* HAL_USE_SPI */

#endif /* HAL_SPI_H */

