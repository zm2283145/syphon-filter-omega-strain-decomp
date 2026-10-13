#include "types.h"
#pragma opt_strength_reduction off

typedef struct RangeDef070 {
    int key;
    int unk04;
    int start;
    int len;
    int value;
    int unk14;
} RangeDef070;

typedef struct RangeTable070 {
    int unk00;
    int count;
    RangeDef070* data;
    int unk0C;
} RangeTable070;

typedef struct RangeRec070 {
    char pad[0x14];
} RangeRec070;

typedef struct RangeRecVec070 {
    int unk00;
    int count;
    RangeRec070* data;
    int unk0C;
} RangeRecVec070;

typedef struct DosDef070 {
    const char* name;
    int unk04;
    int need;
    int id;
    char pad10[0x14];
} DosDef070;

typedef struct DosDefVec070 {
    int unk00;
    int count;
    DosDef070* data;
} DosDefVec070;

typedef struct Agent070 {
    char pad00[0xAA8];
    RangeRecVec070 recs[5];
    char padAF8[0xB50 - 0xAF8];
    DosDef070* dossier;
} Agent070;

extern RangeTable070 D_00532A70[5];
extern DosDefVec070 D_00532B50;
extern void func_00335350(Agent070* self, RangeRec070* rec, RangeDef070* def, int x);
extern void AgentData_ApplyReachedRatings(Agent070* self, int x);
extern int AgentData_TotalPoints(Agent070* self);
extern void AgentData_UnlockById(Agent070* self, int id);

void AgentData_AwardPass(Agent070* self, int x)
{
    int t;
    int pts;
    DosDefVec070* dv;
    int i;
    RangeRecVec070* rv;
    int j;
    Agent070* p;
    RangeTable070* tb;
    p = self;
    tb = D_00532A70;
    for (t = 0; t < 5; t++, p = (Agent070*)((char*)p + 16), tb++) {
        rv = &p->recs[0];
        for (j = 0; j < rv->count; j++) {
            func_00335350(self, &rv->data[j], &tb->data[j], x);
        }
    }
    AgentData_ApplyReachedRatings(self, x);
    pts = AgentData_TotalPoints(self);
    dv = &D_00532B50;
    for (i = 0; i < dv->count; i++) {
        if (pts >= dv->data[i].need) {
            AgentData_UnlockById(self, dv->data[i].id);
            self->dossier = &dv->data[i];
        }
    }
}