#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct PopReader_1C3390 { int unk0; int size; unsigned int base; char* cur; };
extern "C" {
extern char D_0049EE88[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void Object_Register(void* o);
int Pop_FindTag(PopReader_1C3390* r, int tag);
void* cSoundGOBJ_ctor(void* p, PopReader_1C3390* r, int flag);
void func_00165E60(void* a, char* name, int x);
void* func_001698C0(void);
}
extern "C" void Loader_InitSoundGOBJs(void* a0, PopReader_1C3390* r)
{
    if ((unsigned char)Pop_FindTag(r, 0x3A444E53)) {
        int n;
        n = *(int*)r->cur;
        r->cur += 4;
        if (n) {
            int i;
            int mis;
            func_00165E60(func_001698C0(), "Initializing SoundGOBJs...", 0);
            for (i = 0; i < n; i++) {
                int kind;
                void* p;
                kind = *(int*)r->cur;
                r->cur += 4;
                {
                    AllocGuard g;
                    p = Mem_Alloc(0, 0x200, D_0049EE88, 0x1BB);
                }
                if (p)
                    p = cSoundGOBJ_ctor(p, r, kind != 1);
                Object_Register(p);
            }
            mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
            if (mis)
                r->cur += 4 - mis;
        }
    }
}