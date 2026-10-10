#include "types.h"
typedef struct { char pad[0x44]; struct { char pad[0x22]; unsigned short count; } *info; } E2Model;
typedef struct { char pad[8]; E2Model** models; } E2ModelTable;
typedef struct { int a; int b; } E2List;
typedef struct {
    float rate;
    E2List list;
    char pad0c[4];
    int f10;
    float f14;
    int f18;
    int model;
    int count;
} E2WaterSub;
typedef struct {
    int f0;
    int f4;
    char pad08[0x38];
    int f40;
    char pad44[0x24];
    int f68;
    char pad6c[4];
    E2WaterSub sub;
} E2WaterFx;
extern int* func_00236F20(int);
extern void List_Init(E2List*);
extern E2ModelTable* D_00539248;
#pragma opt_propagation off
E2WaterFx* WaterFxRecord_Construct(E2WaterFx* s) {
    E2WaterSub* sub;
    float z;
    s->f4 = -2;
    s->f0 = 0;
    s->f40 = 0;
    s->f68 = *func_00236F20(0x28);
    sub = &s->sub;
    sub->rate = 0.0375f;
    List_Init(&sub->list);
    sub->model = *func_00236F20(0x27);
    z = 0.0f;
    sub->count = D_00539248->models[sub->model]->info->count;
    sub->f10 = 0;
    sub->f14 = z - z;
    sub->f18 = 0;
    return s;
}