#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct Obj_229D30 { void* vt; char pad04[0x28]; char m2C[0xC]; void* buf; };
extern "C" {
extern "C" void func_0012ECE0();
extern "C" void func_0012ECF0();
extern "C" void func_0012ED00();
extern "C" void func_0012ED10();
extern "C" void func_0012ED20();
extern "C" void func_0012ED30();
extern "C" void func_0012ED40();
extern "C" void func_0012ED50();
extern "C" void func_001383D0();
extern "C" void func_003CACA0();
extern "C" void func_003CB1E0();
extern "C" void func_003CB1F0();
extern void * const D_004DB810[];
extern char D_004A6308[];
void Mem_Free(int pool, void* p, char* file, int line);
void func_00229EB0(void* p);
void func_00229B40(Obj_229D30* o, void* m);
void func_0040F570(void);
void func_00137670(void* p, int f);
void func_003CAD70(void* p, int f);
void operator_delete(void* p);
}
extern "C" Obj_229D30* func_00229D30(Obj_229D30* o, short flag)
{
    if (o) {
        o->vt = ((char*)D_004DB810);
        if (o->buf) {
            func_00229EB0(o->buf);
            {
                void* p = o->buf;
                AllocGuard g;
                Mem_Free(0, p, D_004A6308, 0x5C);
            }
            o->buf = 0;
        }
        func_00229B40(o, o->m2C);
        func_0040F570();
        if (o->m2C)
            func_00137670(o->m2C, -1);
        func_003CAD70(o, 0);
        if (flag > 0)
            operator_delete(o);
    }
    return o;
}
void * const D_004DB810[16] = { (void*)0x0, (void*)0x0, (void*)func_00229D30, (void*)func_003CACA0, (void*)func_0012ECE0, (void*)func_0012ECF0, (void*)func_001383D0, (void*)func_0012ED00, (void*)func_0012ED10, (void*)func_0012ED20, (void*)func_0012ED30, (void*)func_0012ED40, (void*)func_0012ED50, (void*)func_003CB1E0, (void*)func_003CB1F0, (void*)0x0 };
