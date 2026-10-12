#pragma cplusplus on
#include "types.h"
struct W_002AFDC0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual int IsA(char* type);
};
struct S_002AFDC0 {
    char pad0[0x160]; W_002AFDC0* p160; W_002AFDC0* p164; W_002AFDC0* p168; W_002AFDC0* p16C;
};
extern "C" char D_004ABC80[];
extern "C" char D_004ABC90[];
extern "C" char D_004ABCA0[];
static void * const dat_0048BCD8[2] = { (void*)D_004ABC80, (void*)0x0 };
static void * const dat_0048BCE0[2] = { (void*)D_004ABC90, (void*)0x0 };
static void * const dat_0048BCE8[2] = { (void*)D_004ABCA0, (void*)0x0 };
extern "C" {
extern char* D_0048BCF8;
extern char D_004A9870[];
extern char D_004A7520[];
void func_0033F250(S_002AFDC0* self);
void* func_0041DB80(S_002AFDC0* self, char* name);
void func_0041C0D0(W_002AFDC0* w, int a);
}
static inline W_002AFDC0* FindAs_002AFDC0(S_002AFDC0* self, char* name, char* type)
{
    W_002AFDC0* w = (W_002AFDC0*)func_0041DB80(self, name);
    return (w && w->IsA(type)) ? w : 0;
}
extern "C" void func_002AFDC0(S_002AFDC0* self)
{
    func_0033F250(self);
    self->p164 = FindAs_002AFDC0(self, *(char**)dat_0048BCD8, D_004A9870);
    self->p168 = FindAs_002AFDC0(self, *(char**)dat_0048BCE0, D_004A9870);
    self->p16C = FindAs_002AFDC0(self, *(char**)dat_0048BCE8, D_004A9870);
    self->p160 = FindAs_002AFDC0(self, D_0048BCF8, D_004A7520);
    if (self->p160)
        func_0041C0D0(self->p160, 1);
}

