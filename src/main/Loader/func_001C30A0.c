#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct PopReader_1C30A0 { int unk0; int size; unsigned int base; char* cur; };
extern "C" {
extern char D_0049EE88[];
extern char D_0049F150[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void Object_Register(void* o);
int Pop_FindTag(PopReader_1C30A0* r, int tag);
void* cNIEventLight_ctor(void* p, PopReader_1C30A0* r);
void func_00165E60(void* a, char* name, int x);
void* func_001698C0(void);
}
extern "C" void Loader_InitNIEventLights(void* a0, PopReader_1C30A0* r)
{
    if ((unsigned char)Pop_FindTag(r, 0x3A4C494E)) {
        int n;
        n = *(int*)r->cur;
        r->cur += 4;
        if (n) {
            int i;
            int mis;
            func_00165E60(func_001698C0(), D_0049F150, 0);
            for (i = 0; i < n; i++) {
                void* p;
                {
                    AllocGuard g;
                    p = Mem_Alloc(0, 0x1B0, D_0049EE88, 0x1FE);
                }
                if (p)
                    p = cNIEventLight_ctor(p, r);
                Object_Register(p);
            }
            mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
            if (mis)
                r->cur += 4 - mis;
        }
    }
}