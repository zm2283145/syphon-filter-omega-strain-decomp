#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct PopReader_1C3210 { int unk0; int size; unsigned int base; char* cur; };
extern "C" {
extern char D_0049EE88[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void Object_Register(void* o);
int Pop_FindTag(PopReader_1C3210* r, int tag);
void* cNIEventOBJ_ctor(void* p, void* x, PopReader_1C3210* r);
void func_002390A0(PopReader_1C3210* r);
void func_00165E60(void* a, char* name, int x);
void* func_001698C0(void);
}
extern "C" void Loader_InitNIEventObjects(void* a0, PopReader_1C3210* r, void* x)
{
    func_002390A0(r);
    if ((unsigned char)Pop_FindTag(r, 0x3A45494E)) {
        int n;
        n = *(int*)r->cur;
        r->cur += 4;
        if (n) {
            int i;
            int mis;
            func_00165E60(func_001698C0(), "Initializing NI Event Objects...", 0);
            for (i = 0; i < n; i++) {
                void* p;
                {
                    AllocGuard g;
                    p = Mem_Alloc(0, 0x1C0, D_0049EE88, 0x1DE);
                }
                if (p)
                    p = cNIEventOBJ_ctor(p, x, r);
                Object_Register(p);
            }
            mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
            if (mis)
                r->cur += 4 - mis;
        }
    }
}