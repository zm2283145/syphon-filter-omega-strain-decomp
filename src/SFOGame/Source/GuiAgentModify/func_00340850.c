#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"

class Vis {
public:
    VPAD2(a) virtual void v2(); virtual void Show(); virtual void Hide();
};
struct Wid { char pad[0x44]; Vis* vis; };
typedef struct { __int128 q; char pad[0x10]; } Ent;
typedef struct { char pad[0xE0]; Ent e[1]; } Tbl;
struct Self {
    char pad0[0x8C];
    Tbl* tbl;
    char pad90[0x114 - 0x90];
    int idx[6];
    Wid* w[6];
    char pad144[0x14C - 0x144];
    Wid* grp[2];
};
extern "C" {
extern __int128 g_AgentPartCache;
extern __int128 D_0055DE00;
void GuiAgentModify_TattooPatchesLockout(Self* self);
}

static inline long KEq(__int128 b, __int128 a, __int128 m)
{
    __int128 t, r;
    asm {
        pand t, m, b
        pand r, m, a
        pceqw r, r, t
        ppach r, r, r
    }
    return r;
}

static inline long Match(Self* self, int k)
{
    return KEq(g_AgentPartCache, self->tbl->e[self->idx[k]].q, D_0055DE00);
}

void GuiAgentModify_TattooPatchesLockout(Self* self)
{
    int n = 0;
    if (Match(self, 0) == -1) self->w[0]->vis->Hide(); else { self->w[0]->vis->Show(); n++; }
    if (Match(self, 1) == -1) self->w[1]->vis->Hide(); else { self->w[1]->vis->Show(); n++; }
    if (Match(self, 2) == -1) self->w[2]->vis->Hide(); else { self->w[2]->vis->Show(); n++; }
    if (n) self->grp[0]->vis->Show(); else self->grp[0]->vis->Hide();
    n = 0;
    if (Match(self, 3) == -1) self->w[3]->vis->Hide(); else { self->w[3]->vis->Show(); n++; }
    if (Match(self, 4) == -1) self->w[4]->vis->Hide(); else { self->w[4]->vis->Show(); n++; }
    if (Match(self, 5) == -1) self->w[5]->vis->Hide(); else { self->w[5]->vis->Show(); n++; }
    if (n) self->grp[1]->vis->Show(); else self->grp[1]->vis->Hide();
}
