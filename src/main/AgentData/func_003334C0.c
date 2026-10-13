#include "types.h"
#pragma opt_strength_reduction off

typedef struct RangeDef4C0 {
    int key;
    int unk04;
    int start;
    int len;
    int value;
    int unk14;
} RangeDef4C0;

typedef struct RangeTable4C0 {
    int unk00;
    int count;
    RangeDef4C0* data;
    int unk0C;
} RangeTable4C0;

typedef struct RangeRec4C0 {
    signed char flag;
    char pad01[0x13];
} RangeRec4C0;

typedef struct RangeRecVec4C0 {
    int unk00;
    int count;
    RangeRec4C0* data;
    int unk0C;
} RangeRecVec4C0;

typedef struct Agent4C0 {
    char pad00[0xAA8];
    RangeRecVec4C0 recs[5];
} Agent4C0;

typedef struct Out4C0 {
    int text;
    int key;
    signed char flag;
    int value;
    int unk10;
} Out4C0;

typedef struct OutVec4C0 {
    int unk00;
    int count;
    Out4C0* data;
} OutVec4C0;

extern RangeTable4C0 D_00532A70[5];
extern void func_00299510(OutVec4C0* v);
extern int Loc_GetTextById(int id);
extern int func_00339270(OutVec4C0* v, Out4C0* pos, int n, Out4C0* value);

void func_003334C0(Agent4C0* self, unsigned char type, OutVec4C0* out)
{
    RangeRecVec4C0* recs = &self->recs[type];
    int i;
    func_00299510(out);
    for (i = 0; i < recs->count; i++) {
        Out4C0 e;
        RangeDef4C0* d = &D_00532A70[type].data[i];
        signed char flag;
        int value;
        int key;
        value = d->value;
        key = d->key;
        flag = recs->data[i].flag;
        e.text = Loc_GetTextById(key);
        e.key = key;
        e.flag = flag;
        e.value = value;
        e.unk10 = 0;
        func_00339270(out, &out->data[out->count], 1, &e);
    }
}
