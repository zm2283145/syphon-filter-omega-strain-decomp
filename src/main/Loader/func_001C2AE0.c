#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct PopReader_1C2AE0 { int version; int size; unsigned int base; char* cur; };
struct Ctl_1C2AE0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Refresh();
    char pad[0x3C];
    char region[0x10];
    unsigned char dirty;
};
struct Gen_1C2AE0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void Attach(int x);
    char pad[0x4C];
    Ctl_1C2AE0* ctl;
};
extern "C" {
extern char D_0049EE88[];
extern char D_0049F110[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void Object_Register(void* o);
int Pop_FindTag(PopReader_1C2AE0* r, int tag);
Gen_1C2AE0* cGenerator_ctor(void* p, PopReader_1C2AE0* r);
void func_00165E60(void* a, char* name, int x);
void* func_001698C0(void);
void* LosRegion_FindGlobal(void* region);
void ZoneMgr_Associate(void* reg, Gen_1C2AE0* g, int a, int b);
}
extern "C" void Loader_LoadGeneratorDefs(void* a0, PopReader_1C2AE0* r)
{
    if ((unsigned char)Pop_FindTag(r, 0x3A4E4547)) {
        int n;
        int i;
        int mis;
        n = *(int*)r->cur;
        r->cur += 4;
        func_00165E60(func_001698C0(), D_0049F110, 0);
        for (i = 0; i < n; i++) {
            Gen_1C2AE0* p;
            {
                AllocGuard g;
                p = (Gen_1C2AE0*)Mem_Alloc(0, 0xD4, D_0049EE88, 0x250);
            }
            if (p)
                p = cGenerator_ctor(p, r);
            Object_Register(p);
            if (r->version < 0x32) {
                Ctl_1C2AE0* c = p->ctl;
                void* reg;
                if (c->dirty)
                    c->Refresh();
                reg = LosRegion_FindGlobal(c->region);
                if (reg)
                    ZoneMgr_Associate(reg, p, 1, 0);
                else
                    p->Attach(1);
            }
        }
        mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
        if (mis)
            r->cur += 4 - mis;
    }
}