#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct PopReader_1C1CE0 { int unk0; int size; unsigned int base; char* cur; };
extern "C" {
extern char D_0049EE88[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void Object_Register(void* o);
int Pop_FindTag(PopReader_1C1CE0* r, int tag);
void* func_001C59D0(void* p, PopReader_1C1CE0* r);
void func_00165E60(void* a, char* name, int x);
void* func_001698C0(void);
}
extern "C" void Loader_LoadParticles(void* a0, PopReader_1C1CE0* r)
{
    func_00165E60(func_001698C0(), "Loading Particles...", 0);
    if ((unsigned char)Pop_FindTag(r, 0x3A524C50)) {
        int mis;
        mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
        if (mis)
            r->cur += 4 - mis;
        {
        int n;
        int i = 0;
        n = *(int*)r->cur;
        r->cur += 4;
        for (; i < n; i++) {
            void* p;
            {
                AllocGuard g;
                p = Mem_Alloc(0, 0x74, D_0049EE88, 0x3C9);
            }
            if (p)
                p = func_001C59D0(p, r);
            Object_Register(p);
        }
        }
    }
}