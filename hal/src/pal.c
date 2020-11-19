#include <avr/io.h>

#include <hal/pal.h>

void pal_init(const pal_config_t *config)
{
#ifdef PORTA
    PORTA = config->porta.out;
    DDRA = config->porta.dir;
#endif

#ifdef PORTB
    PORTB = config->portb.out;
    DDRB = config->portb.dir;
#endif

#ifdef PORTC
    PORTC = config->portc.out;
    DDRC = config->portc.dir;
#endif

#ifdef PORTD
    PORTD = config->portd.out;
    DDRD = config->portd.dir;
#endif

#ifdef PORTE
    PORTE = config->porte.out;
    DDRE = config->porte.dir;
#endif

#ifdef PORTF
    PORTF = config->portf.out;
    DDRF = config->portf.dir;
#endif

#ifdef PORTG
    PORTG = config->portg.out;
    DDRG = config->portg.dir;
#endif
#ifdef PORTH
    PORTH = config->porth.out;
    DDRH = config->porth.dir;
#endif

#ifdef PORTJ
    PORTJ = config->portj.out;
    DDRJ = config->portj.dir;
#endif

#ifdef PORTK
    PORTK = config->portk.out;
    DDRK = config->portk.dir;
#endif

#ifdef PORTL
    PORTL = config->portl.out;
    DDRL = config->portl.dir;
#endif
}

int pal_read_pad(ioportid_t port, uint8_t pad)
{
    return (port->in >> pad) & 0x01;
}

void pal_set_pad(ioportid_t port, uint8_t pad)
{
    port->out |= 1 << pad;
}

void pal_clear_pad(ioportid_t port, uint8_t pad)
{
    port->out &= ~(1 << pad);
}

void pal_toggle_pad(ioportid_t port, uint8_t pad)
{
    port->out ^= 1 << pad;
}

void pal_write_pad(ioportid_t port, uint8_t pad, uint8_t val)
{
    port->out = val ? port->out | (1 << pad) :
       port->out & ~(1 << pad);
}

void pal_set_pad_dir(ioportid_t port, uint8_t pad, uint8_t dir)
{
    port->dir = dir ? port->dir | (1 << pad) :
       port->dir & ~(1 << pad);
}

