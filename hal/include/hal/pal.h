#ifndef HAL_PAL
#define HAL_PAL

#include <halconf.h>

#if (HAL_USE_PAL == TRUE)

#include <stdint.h>

#include <avr/io.h>

typedef struct {
    uint8_t out;
    uint8_t dir;
} avr_gpio_setup_t;

typedef struct {
    volatile uint8_t in;
    volatile uint8_t dir;
    volatile uint8_t out;
} avr_gpio_registers_t;

typedef struct {
#ifdef PORTA
    avr_gpio_setup_t porta;
#endif
#ifdef PORTB
    avr_gpio_setup_t portb;
#endif
#ifdef PORTC
    avr_gpio_setup_t portc;
#endif
#ifdef PORTD
    avr_gpio_setup_t portd;
#endif
#ifdef PORTE
    avr_gpio_setup_t porte;
#endif
#ifdef PORTF
    avr_gpio_setup_t portf;
#endif
#ifdef PORTG
    avr_gpio_setup_t portg;
#endif
#ifdef PORTH
    avr_gpio_setup_t porth;
#endif
#ifdef PORTJ
    avr_gpio_setup_t portj;
#endif
#ifdef PORTK
    avr_gpio_setup_t portk;
#endif
#ifdef PORTL
    avr_gpio_setup_t portl;
#endif
} pal_config_t;

typedef volatile avr_gpio_registers_t *ioportid_t;

#ifdef PORTA
#define IOPORT1     ((volatile avr_gpio_registers_t *)&PINA)
#endif

#ifdef PORTB
#define IOPORT2     ((volatile avr_gpio_registers_t *)&PINB)
#endif

#ifdef PORTC
#define IOPORT3     ((volatile avr_gpio_registers_t *)&PINC)
#endif

#ifdef PORTD
#define IOPORT4     ((volatile avr_gpio_registers_t *)&PIND)
#endif

#ifdef PORTE
#define IOPORT5     ((volatile avr_gpio_registers_t *)&PINE)
#endif

#ifdef PORTF
#define IOPORT6     ((volatile avr_gpio_registers_t *)&PINF)
#endif

#ifdef PORTG
#define IOPORT7     ((volatile avr_gpio_registers_t *)&PING)
#endif

#ifdef PORTH
#define IOPORT8     ((volatile avr_gpio_registers_t *)&PINH)
#endif

#ifdef PORTJ
#define IOPORT9     ((volatile avr_gpio_registers_t *)&PINJ)
#endif

#ifdef PORTK
#define IOPORT10    ((volatile avr_gpio_registers_t *)&PINK)
#endif

#ifdef PORTL
#define IOPORT11    ((volatile avr_gpio_registers_t *)&PINL)
#endif

extern const pal_config_t pal_default_config;

extern void pal_init(const pal_config_t *config);

extern int pal_read_pad(ioportid_t port, uint8_t pad);

extern void pal_set_pad(ioportid_t port, uint8_t pad);

extern void pal_clear_pad(ioportid_t port, uint8_t pad);

extern void pal_toggle_pad(ioportid_t port, uint8_t pad);

extern void pal_write_pad(ioportid_t port, uint8_t pad, uint8_t val);

extern void pal_set_pad_dir(ioportid_t port, uint8_t pad, uint8_t dir);

#endif /* HAL_USE_PAL */

#endif /* HAL_PAL */

