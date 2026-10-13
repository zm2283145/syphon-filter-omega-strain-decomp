#include "types.h"
typedef struct { char pad[0xC]; int serial; char pad10[0x3C]; int type; } Tgt_552B0;
typedef struct { Tgt_552B0* target; int serial; } Hdl_552B0;
typedef struct { char pad[0x40]; Hdl_552B0 h; } Ai_552B0;
typedef struct { char pad[0x158]; unsigned char f158; char pad159[0x53]; Ai_552B0* ai; } Npc_552B0;
extern int D_0049D010;
extern Tgt_552B0* ActorRef_Copy(Hdl_552B0* h);
unsigned char NpcAlert_SearchAllowed(Npc_552B0* self)
{
    unsigned char r = 1;
    unsigned char ok;
    int isNull;
    Tgt_552B0* t;
    Ai_552B0* ai;
    if (!self->f158)
        r = 0;
    ai = self->ai;
    t = ai->h.target;
    isNull = !t;
    ok = 1;
    if (!isNull)
        if (t->serial != ai->h.serial)
            ok = 0;
    if (ok ? t : 0) {
        Tgt_552B0* p = ActorRef_Copy(&ai->h);
        if (p->type != D_0049D010)
            r = 0;
    }
    return r;
}
