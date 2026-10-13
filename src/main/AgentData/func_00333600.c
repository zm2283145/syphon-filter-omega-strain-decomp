#include "types.h"
#pragma opt_strength_reduction off

typedef struct Rating600 {
    int key;
    int unk04;
    unsigned char stat;
    char pad09[3];
    int min;
    int need;
    int value;
} Rating600;

typedef struct RatingVec600 {
    int unk00;
    int count;
    Rating600* data;
} RatingVec600;

typedef struct Agent600 {
    char pad00[0x08];
    int stats[1];
} Agent600;

typedef struct Out600 {
    int text;
    int key;
    signed char flag;
    int value;
    int pct;
} Out600;

typedef struct OutVec600 {
    int unk00;
    int count;
    Out600* data;
} OutVec600;

extern RatingVec600 D_00532AD0;
extern void func_00299510(OutVec600* v);
extern int Loc_GetTextById(int id);
extern signed char* func_00333790(void* bits, int i);
extern int func_00339270(OutVec600* v, Out600* pos, int n, Out600* value);

void func_00333600(Agent600* self, OutVec600* out)
{
    int i;
    func_00299510(out);
    for (i = 0; i < D_00532AD0.count; i++) {
        Out600 e;
        int pct;
        signed char flag;
        int value;
        int key;
        Rating600* r = &D_00532AD0.data[i];
        int v = self->stats[r->stat];
        int need = r->need;
        pct = 0;
        if (v >= need) {
            pct = 100;
        } else if (r->min < v) {
            pct = (v - r->min) * 100 / (need - r->min);
        }
        value = r->value;
        flag = *func_00333790(&self->stats[700], i);
        key = r->key;
        e.text = Loc_GetTextById(key);
        e.key = key;
        e.flag = flag;
        e.value = value;
        e.pct = pct;
        func_00339270(out, &out->data[out->count], 1, &e);
    }
}

