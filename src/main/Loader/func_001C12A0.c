#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct PopReader_1C12A0 { int unk0; int size; unsigned int base; char* cur; };
extern "C" {
extern char D_0049EE88[];
extern void* D_004FFBD4;
void* Mem_Alloc(int pool, int size, char* file, int line);
void Object_Register(void* o);
int Pop_FindTag(PopReader_1C12A0* r, int tag);
void* cEnvSettings_ctor(void* p, PopReader_1C12A0* r);
void func_00165E60(void* a, char* name, int x);
void* func_001698C0(void);
void func_001C1440(void* list, void** item);
int func_001723F0(void* list);
void** func_00172360(void* list, int i);
void func_001781A0(void* list, void* item);
}
extern "C" void Loader_InitEnvironmentSettings(void* a0, PopReader_1C12A0* r)
{
    int mis;
    int n;
    void* list;
    int i;
    func_00165E60(func_001698C0(), "Initializing Environment Settings...", 0);
    mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
    if (mis)
        r->cur += 4 - mis;
    Pop_FindTag(r, 0x3A564E45);
    n = *(int*)r->cur;
    r->cur += 4;
    list = D_004FFBD4;
    for (i = 0; i < n; i++) {
        void* p;
        {
            AllocGuard g;
            p = Mem_Alloc(0, 0xA8, D_0049EE88, 0x4F3);
        }
        if (p)
            p = cEnvSettings_ctor(p, r);
        void* item[1];
        item[0] = p;
        func_001C1440(list, item);
        Object_Register(p);
    }
    func_001781A0(list, func_001723F0(list) ? 0 : *func_00172360(list, 0));
}