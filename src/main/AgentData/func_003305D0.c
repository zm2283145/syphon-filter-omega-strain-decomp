#include "types.h"
#include "AgentData_types.h"

typedef struct TpRec {
    int unk00;
    int unk04;
    unsigned char flag;
    char pad09[0x14 - 0x09];
} TpRec;

typedef struct TpList {
    int unk0;
    int count;
    TpRec* data;
    unsigned char flag;
} TpList;

typedef struct TpTable {
    int unk0;
    int count;
    ObjectiveRow* data;
    int unkC;
} TpTable;

typedef struct TpAgent {
    char pad00[0x08];
    int stats[14];
    int unk40;
    int unk44;
    char pad48[0x84 - 0x48];
    unsigned int objectiveBits[8];
} TpAgent;

extern ObjectiveRowVec D_005329F0;
extern TpTable D_00532A70[5];
extern ObjectiveRowVec D_00532AD0;

extern void func_003308D0(ObjectiveRow** out, ObjectiveRowVec* v);
extern void func_003308B0(ObjectiveRow** out, ObjectiveRowVec* v);
extern int func_00330830(ObjectiveRow** a, ObjectiveRow** b);
extern ObjectiveRow* func_003308A0(ObjectiveRow** it);
extern ObjectiveRow** func_00330850(ObjectiveRow** it);
extern int AgentData_TestObjectiveBit(unsigned int* bits, int index);
extern ObjectiveRow** func_00330820(ObjectiveRowVec* v);
extern void func_00296FA0(TpList* l);
extern void AgentData_GetAwardRows(TpAgent* self, unsigned char kind, TpList* l);
extern void* func_00299360(TpList* l, short deleteFlag);

static inline int TpNeq(ObjectiveRow* a, ObjectiveRow* b) { return !(a == b); }

static inline int TpCompleted(TpAgent* self) {
    int sum = 0;
    ObjectiveRow* it;
    ObjectiveRow* end;
    func_003308D0(&it, &D_005329F0);
    func_003308B0(&end, &D_005329F0);
    while (func_00330830(&it, &end)) {
        if (AgentData_TestObjectiveBit(self->objectiveBits, func_003308A0(&it)->index))
            sum += func_003308A0(&it)->points;
        func_00330850(&it);
    }
    return sum;
}

int AgentData_TotalPoints(TpAgent* self) {
    int total = 0;
    ObjectiveRow* p;
    ObjectiveRow* e;
    int i;
    TpTable* t;
    total += TpCompleted(self);
    p = *func_00330820(&D_00532AD0);
    e = *func_00330820(&D_00532AD0) + D_00532AD0.count;
    for (; TpNeq(p, e); p++) {
        if (self->stats[*(unsigned char*)&p->unk08] >= p->unk10)
            total += p->index;
    }
    for (i = 0, t = D_00532A70; i < 5; i++, t++) {
        TpList l;
        int j;
        func_00296FA0(&l);
        l.flag = 1;
        AgentData_GetAwardRows(self, i, &l);
        for (j = 0; j < l.count; j++) {
            if (l.data[(unsigned)j].flag)
                total += t->data[(unsigned)j].points;
        }
        func_00299360(&l, 0);
    }
    total += self->unk40 * 5;
    total += self->unk44 * 5;
    return total;
}



