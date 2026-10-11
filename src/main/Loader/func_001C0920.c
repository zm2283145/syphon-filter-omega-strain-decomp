#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct PopReader_1C0920 { int unk0; int size; unsigned int base; char* cur; };
extern "C" {
extern char D_0049EE88[];
extern char D_0049EEE0[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void Object_Register(void* o);
int Pop_FindTag(PopReader_1C0920* r, int tag);
void* Camera_ConstructStream(void* p, PopReader_1C0920* r);
void func_00165E60(void* a, char* name, int x);
void* func_001698C0(void);
}
extern "C" void Loader_InitPopulatedCameras(void* a0, PopReader_1C0920* r)
{
    if (r->cur) {
        int mis;
        func_00165E60(func_001698C0(), D_0049EEE0, 0);
        mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
        if (mis)
            r->cur += 4 - mis;
        if ((unsigned char)Pop_FindTag(r, 0x3A4D4143)) {
            int n;
            int i = 0;
            n = *(int*)r->cur;
            r->cur += 4;
            for (; i < n; i++) {
                void* p;
                {
                    AllocGuard g;
                    p = Mem_Alloc(0, 0xCF0, D_0049EE88, 0x5C5);
                }
                if (p)
                    p = Camera_ConstructStream(p, r);
                Object_Register(p);
            }
        }
    }
}