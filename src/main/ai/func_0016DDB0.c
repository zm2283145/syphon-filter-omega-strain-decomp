#pragma cplusplus on
#include "types.h"
typedef struct { char pad[0xC]; int serial; char pad10[0x48]; int f58; } Tgt_DDB0;
typedef struct { char pad[0x10]; char pos[0x2A]; unsigned char b3A; } Rec_DDB0;
typedef struct { char pad[8]; Rec_DDB0* val; } Node_DDB0;
typedef struct {
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 1;
    unsigned char b7 : 1;
} Flags_DDB0;
typedef struct {
    char pad[0x1C];
    int prio;
    Flags_DDB0 flags;
    char pad21[0xF];
    char map[0x10];
    Tgt_DDB0* target;
    int serial;
} Perc_DDB0;
extern "C" char g_TargetVisMgr[];
extern "C" void NpcPerception_FindRecord(Node_DDB0** out, void* map, Tgt_DDB0* key);
extern "C" void func_0016BB80(Node_DDB0** out, void* map);
extern "C" void func_0016BB90(Node_DDB0** out, Node_DDB0** in);
extern "C" void NpcPerception_SetLastKnown(Perc_DDB0* self, Tgt_DDB0* t, void* pos, int f);
extern "C" void TargetVis_Register(void* mgr, Tgt_DDB0* t);
extern "C" void NpcPerception_SetTarget(Perc_DDB0* self, Tgt_DDB0* t, int prio)
{
    Node_DDB0* it;
    Node_DDB0* end;
    int def;
    Node_DDB0* tmp;
    Tgt_DDB0* cur;
    {
        bool isNull;
        bool ok;
        Tgt_DDB0* c;
        c = self->target;
        isNull = !c;
        ok = true;
        if (!isNull) if (c->serial != self->serial) ok = false;
        cur = ok ? c : 0;
    }
    if (t == cur && t)
        return;
    if (prio < self->prio)
        return;
    self->target = t;
    self->serial = *(t ? &t->serial : (def = -1, &def));
    self->prio = prio;
    int v = 0;
    self->flags.b3 = v;
    self->flags.b4 = v;
    self->flags.b0 = v;
    self->flags.b1 = v;
    self->flags.b2 = v;
    self->flags.b2 = v;
    self->flags.b6 = v;
    if (t) {
        NpcPerception_FindRecord(&it, self->map, t);
        func_0016BB80(&tmp, self->map);
        func_0016BB90(&end, &tmp);
        if (it != end) {
            self->flags.b3 = it->val->b3A;
            NpcPerception_SetLastKnown(self, t, it->val->pos, 0);
        }
        if (t->f58 == 0)
            TargetVis_Register(g_TargetVisMgr, t);
    }
}
