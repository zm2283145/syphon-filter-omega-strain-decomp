#pragma cplusplus on
#include "types.h"
struct W_002ABF40 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void SetCount(int n, int a);
};
struct S_002ABF40 : W_002ABF40 {
    char pad4[0x90 - 4]; char* f90[7]; unsigned char bAC; char padAD[3]; W_002ABF40* pB0;
};
struct T_002ABF40 { int count; int ids[3]; };
extern "C" {
extern T_002ABF40 D_0048BC60[];
extern char* D_0048BC40[];
extern char D_004AB9D0[];
void func_004248C0(void* w, int i, char* s);
void func_00426510(void* w, int i, int a, char* s);
}
extern "C" void func_002ABF40(S_002ABF40* self, unsigned char idx)
{
    int n;
    int i;
    T_002ABF40* t;
    t = &D_0048BC60[idx];
    n = t->count;
    self->SetCount(n, 0);
    self->pB0->SetCount(n, 1);
    for (i = 0; i < n; i++) {
        int id = t->ids[i];
        func_004248C0(self, i, D_0048BC40[id]);
        func_004248C0(self->pB0, i, D_0048BC40[id]);
        func_00426510(self->pB0, i, 0, self->f90[id] ? self->f90[id] : D_004AB9D0);
    }
    self->bAC = idx;
}




