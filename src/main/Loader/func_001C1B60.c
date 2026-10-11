#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct PopReader_1C1B60 { int unk0; int size; unsigned int base; char* cur; };
struct Sky_1C1B60 { char pad[0x90]; int count; };
extern "C" {
extern char D_0049EE88[];
extern char D_0049F000[];
extern char D_0049F018[];
extern char D_0048B2F8[];
extern char D_004FFC90[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void Object_Register(void* o);
int Pop_FindTag(PopReader_1C1B60* r, int tag);
Sky_1C1B60* func_001C5E50(void* p, void* a, int arc, PopReader_1C1B60* r, int n);
void func_00165E60(void* a, char* name, int x);
void* func_001698C0(void);
int sprintf(char* buf, const char* fmt, ...);
int Archive_Open(void* a, char* name, int b, int c);
}
extern "C" void Loader_InitSkybox(void* a0, void* a1, PopReader_1C1B60* r, void* arc)
{
    if ((unsigned char)Pop_FindTag(r, 0x3A594B53)) {
        char name[128];
        int h;
        int n;
        func_00165E60(func_001698C0(), D_0049F000, 0);
        sprintf(name, D_0049F018, D_0048B2F8, D_004FFC90, D_004FFC90);
        h = Archive_Open(arc, name, 0, 0);
        n = *(int*)r->cur;
        r->cur += 4;
        while (n) {
            Sky_1C1B60* p;
            {
                AllocGuard g;
                p = (Sky_1C1B60*)Mem_Alloc(0, 0x94, D_0049EE88, 0x3F3);
            }
            if (p)
                p = func_001C5E50(p, a1, h, r, n);
            Object_Register(p);
            n -= p->count;
        }
    }
}