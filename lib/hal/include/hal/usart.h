#ifndef HAL_USART_H
#define HAL_USART_H

#include <halconf.h>

#if (HAL_USE_USART == TRUE)

#include <stdint.h>
#include <utils/queue.h>

typedef struct hal_usart_driver usart_driver_t;

typedef struct hal_usart_config usart_config_t;

struct hal_usart_config {
    uint32_t speed;
};

struct hal_usart_driver {
    const usart_config_t *config;

    queue_t *oq;
    queue_t *iq;
};

#if (AVR_UART_USE_USART1 == TRUE)
extern usart_driver_t USARTD1;
#endif

#if (AVR_UART_USE_USART2 == TRUE)
extern usart_driver_t USARTD2;
#endif

#if (AVR_UART_USE_USART3 == TRUE)
extern usart_driver_t USARTD3;
#endif

#if (AVR_UART_USE_USART4 == TRUE)
extern usart_driver_t USARTD4;
#endif

extern void usart_init(usart_driver_t *uartp, const usart_config_t *config);

extern int usart_read(usart_driver_t *uartp, char *buf, int size);

extern int usart_write(usart_driver_t *uartp, char *buf, int size);

#endif /* HAL_USE_USART */

#endif /* HAL_USART_H*/

