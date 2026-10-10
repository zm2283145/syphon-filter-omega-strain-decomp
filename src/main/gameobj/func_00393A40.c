#include "types.h"
typedef struct RgSub { char p[0x8]; char a[0x10]; char b[0x18]; char c[0x18]; } RgSub;
typedef struct RgFlag { char p[0xC]; unsigned char on; } RgFlag;
typedef struct RgObj {
    int one; float f4; char p8[0xC]; int z14; char p18[4]; float s1c; int arg; void* model;
    unsigned char b28, b29; char p2a[0x42]; char col6c[0xC]; char col78[0x10]; char p88[0x18]; char rootA0[4];
} RgObj;
typedef struct RgT1 { char p[0x48]; } RgT1;
typedef struct RgT2 { char p[0x8]; } RgT2;
extern float D_00493470;
extern void func_00393F10(void*);
extern void func_00393CE0(void*);
extern void ScalarCollection_Init(void*);
extern void func_00393C90(void*);
extern void func_00393C70(void*);
extern void func_003AF2D0(void*);
extern void func_00393C60(void*, void*);
extern void* func_00393C50(void*);
extern void RootCollection_InitFromModel(void*, void*);
extern void func_00393BD0(RgT1*, float);
extern void* func_00393BC0(void*);
extern void func_00393BB0(void*, void*, RgT1*);
extern void func_001AEF70(RgT1*, int);
extern void func_00393BA0(RgT2*);
extern void* func_00393B90(void*);
extern void func_00393B80(void*, void*, RgT2*);
extern void func_001AEF20(RgT2*, int);
RgObj* func_00393A40(RgObj* o, int arg, void* model)
{
    RgSub* sub;
    RgFlag* fl;
    o->one = 1;
    o->f4 = D_00493470;
    o->z14 = 0;
    o->s1c = 1.0f;
    o->arg = arg;
    sub = (RgSub*)&o->model;
    o->model = model;
    o->b28 = 0;
    o->b29 = 0;
    func_00393F10(sub->a);
    func_00393CE0(sub->b);
    func_00393CE0(sub->c);
    ScalarCollection_Init(o->col6c);
    func_00393C90(o->col78);
    fl = (RgFlag*)o->p88;
    func_00393C70(fl);
    fl->on = 1;
    func_003AF2D0(o->rootA0);
    if (model) {
        func_00393C60(&o->model, model);
        RootCollection_InitFromModel(o->rootA0, func_00393C50(model));
        {
            RgT1 t1;
            func_00393BD0(&t1, 0.0f);
            func_00393BB0(o->col78, func_00393BC0(model), &t1);
            func_001AEF70(&t1, -1);
        }
        {
            RgT2 t2;
            func_00393BA0(&t2);
            func_00393B80(o->p88, func_00393B90(model), &t2);
            func_001AEF20(&t2, -1);
        }
    }
    return o;
}