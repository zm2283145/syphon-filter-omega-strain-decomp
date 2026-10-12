#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct PopReader_1C2CB0 { int version; int size; unsigned int base; char* cur; };
struct TerList_1C2CB0 { int a, b, c; unsigned char d; };
struct Ter_1C2CB0 { char pad[0x1C]; void* reg; };
struct Level_1C2CB0 { char pad[0xC]; TerList_1C2CB0* ters; };
extern "C" {
extern char D_0049EE88[];
extern char D_0049F018[];
extern char D_0048B2F8[];
extern char D_004FFC90[];
extern void* D_004FFD48;
void* Mem_Alloc(int pool, int size, char* file, int line);
int Pop_FindTag(PopReader_1C2CB0* r, int tag);
void func_00165E60(void* a, char* name, int x);
void* func_001698C0(void);
int sprintf(char* buf, const char* fmt, ...);
int Archive_Open(void* a, char* name, int b, int c);
void func_001C2F40(TerList_1C2CB0* l);
Ter_1C2CB0* Terrain_Construct(void* p, PopReader_1C2CB0* r, void* a1, int h);
void ObjRegistry_AppendRecursive(void* reg, Ter_1C2CB0* t);
void func_001C2F20(TerList_1C2CB0* l, Ter_1C2CB0** item);
}
extern "C" void Pop_LoadTER(Level_1C2CB0* l, void* a1, PopReader_1C2CB0* r, void* arc)
{
    if ((unsigned char)Pop_FindTag(r, 0x3A524554)) {
        Ter_1C2CB0* item[1];
        int n;
        char name[128];
        int h;
        TerList_1C2CB0* list;
        int i;
        int mis;
        n = *(int*)r->cur;
        r->cur += 4;
        func_00165E60(func_001698C0(), "Initializing Terrain Data...", 0);
        sprintf(name, D_0049F018, D_0048B2F8, D_004FFC90, D_004FFC90);
        h = Archive_Open(arc, name, 0, 0);
        {
            AllocGuard g;
            list = (TerList_1C2CB0*)Mem_Alloc(0, 0x10, D_0049EE88, 0x230);
        }
        if (list) {
            func_001C2F40(list);
            list->d = 1;
        }
        l->ters = list;
        for (i = 0; i < n; i++) {
            Ter_1C2CB0* t;
            {
                AllocGuard g;
                t = (Ter_1C2CB0*)Mem_Alloc(0, 0x260, D_0049EE88, 0x233);
            }
            if (t)
                t = Terrain_Construct(t, r, a1, h);
            item[0] = t;
            void* reg = D_004FFD48;
            t->reg = reg;
            ObjRegistry_AppendRecursive(reg, t);
            func_001C2F20(l->ters, item);
        }
        mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
        if (mis)
            r->cur += 4 - mis;
    }
}