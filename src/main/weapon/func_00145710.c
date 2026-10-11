#include "types.h"
typedef struct { char pad[0x41C]; int refs; } R_5710;
typedef struct { char pad[0xCC]; unsigned char cc; char pad2[0x108 - 0xCD]; unsigned char x108; char pad3[0x138 - 0x109]; unsigned char count; char mode; char pad4[2]; R_5710* res; } E_5710;
typedef struct { char pad[0x14]; E_5710* e; } S_5710;
extern void func_00147150(S_5710* self, E_5710* e, R_5710** out, int idx, int z, int cc, int x108);
void func_00145710(S_5710* self, int idx, char mode)
{
    E_5710* e = &self->e[idx];
    e->count++;
    if (e->res)
        e->res->refs++;
    if (e->count < 2) {
        e->mode = mode;
        if (!e->res) {
            func_00147150(self, e, &e->res, idx, 0, e->cc, e->x108);
            if (e->res)
                e->res->refs++;
        }
    }
}