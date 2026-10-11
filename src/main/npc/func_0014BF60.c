#pragma cplusplus on
#include "types.h"
struct Bits_0014BF60 {
    int w[8];
    bool test(int n) const { return (w[n / 32] >> (n & 31)) & 1; }
    void set(int n) { w[n / 32] |= 1 << (n & 31); }
    void reset(int n) { w[n / 32] &= ~(1 << (n & 31)); }
};
typedef struct { char pad[0x7C]; int id; } Obj_0014BF60;
typedef struct { char pad[0xBC]; Bits_0014BF60 bits; } NPC_0014BF60;
extern "C" void cNPC_v7C(NPC_0014BF60* self, Obj_0014BF60* o)
{
    int id = o->id;
    if (!self->bits.test(id)) self->bits.set(id);
}