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

extern void cArray_Record_Begin(ObjectiveRow** out, ObjectiveRowVec* v);
extern void cArray_Record_End(ObjectiveRow** out, ObjectiveRowVec* v);
extern int cArray_Record_Iterator_opNe(ObjectiveRow** a, ObjectiveRow** b);
extern ObjectiveRow* cArray_Record_Iterator_opMul(ObjectiveRow** it);
extern ObjectiveRow** cArray_Record_Iterator_opInc(ObjectiveRow** it);
extern int AgentData_TestObjectiveBit(unsigned int* bits, int index);
extern ObjectiveRow** std_vector_deleter_RatingRecord_data(ObjectiveRowVec* v);
extern void func_00296FA0(TpList* l);
extern void AgentData_GetAwardRows(TpAgent* self, unsigned char kind, TpList* l);
extern void* func_00299360(TpList* l, short deleteFlag);

static inline int TpNeq(ObjectiveRow* a, ObjectiveRow* b) { return !(a == b); }

static inline int TpCompleted(TpAgent* self) {
    int sum = 0;
    ObjectiveRow* it;
    ObjectiveRow* end;
    cArray_Record_Begin(&it, &D_005329F0);
    cArray_Record_End(&end, &D_005329F0);
    while (cArray_Record_Iterator_opNe(&it, &end)) {
        if (AgentData_TestObjectiveBit(self->objectiveBits, cArray_Record_Iterator_opMul(&it)->index))
            sum += cArray_Record_Iterator_opMul(&it)->points;
        cArray_Record_Iterator_opInc(&it);
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
    p = *std_vector_deleter_RatingRecord_data(&D_00532AD0);
    e = *std_vector_deleter_RatingRecord_data(&D_00532AD0) + D_00532AD0.count;
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



