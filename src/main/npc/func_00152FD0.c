#include "types.h"
typedef struct { char pad[0xC]; int serial; char pad10[0x1C]; unsigned char f2C; unsigned char f2D; unsigned char f2E; } Tgt_52FD0;
typedef struct { char pad[0xC]; int id; char pad10[0x114]; Tgt_52FD0* target; int serial; } Src_52FD0;
typedef struct { char pad[0x30]; Tgt_52FD0* f30; char pad34[0x10]; int mode; char pad48[0xAC]; int fF4; char padF8[0xB4]; void* perc; } Npc_52FD0;
extern void NpcPerception_AddAwareness(void* p, void* src, int kind, float amt);
extern unsigned char func_0025AC00(Src_52FD0* s);
extern void NpcAi_RequestAction(Npc_52FD0* n, int a, int b, float t);
extern unsigned char NpcAi_RequestMode(int* p, int v, int pri);
static inline void Notice_52FD0(Npc_52FD0* self, Src_52FD0* src)
{
    Tgt_52FD0* t;
    unsigned char ok;
    unsigned char isNull;
    Tgt_52FD0* p;
    t = src->target;
    isNull = !t;
    ok = 1;
    if (!isNull)
        if (t->serial != src->serial)
            ok = 0;
    p = ok ? t : 0;
    if (p) {
        int v = p->f2D && p->f2C && !p->f2E;
        if (v) {
            if ((isNull || t->serial == src->serial ? t : 0) != self->f30)
                NpcPerception_AddAwareness(self->perc, p, 2, 0.0f);
        }
    }
}
void cNPC_v32(Npc_52FD0* self, int kind, Src_52FD0* src, float amt)
{
    if (!src)
        return;
    if ((unsigned char)kind == 5) {
        if (self->mode != 10) {
            Notice_52FD0(self, src);
            if (func_0025AC00(src) == 3) {
                NpcAi_RequestAction(self, 8, 0, 5.0f);
                return;
            }
            if (NpcAi_RequestMode(&self->mode, 10, 50))
                self->fF4 = src->id;
        }
    } else {
        NpcPerception_AddAwareness(self->perc, src, kind, amt);
    }
}


