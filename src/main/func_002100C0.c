#include "types.h"
#include "net_write_one_word.h"

typedef struct { char pad[0x24]; unsigned char value; } Atm002100C0;

void cAtmosphericEffectMsg_v04(Atm002100C0* self)
{
    NetW1_write32(self->value);
}