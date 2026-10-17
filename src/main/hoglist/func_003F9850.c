#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct Elem3F98 { char name[0x14C]; unsigned char loaded; char pad14D[0x168 - 0x14D]; unsigned char busy; char pad169[0x170 - 0x169]; };
struct Node3F98 { Node3F98* prev; Node3F98* next; Elem3F98 data; };
struct List3F98 { int x0; Node3F98 sentinel; };
struct Pool3F98 { char pad[0x164]; int heap; };
struct FEnt3F98 { int d[0x27]; };
extern "C" {
extern char D_004BE1F0[];
void* func_003F9520(void*);
void* func_003F95E0(Node3F98** out, void* v);
void* func_003F95F0(List3F98*);
int String_CompareNoCase(void*, char*);
void func_0036D630(void*);
void func_0036D5D0(void*, int);
void func_003F9B30(Node3F98** out, List3F98* l, Node3F98** pos, Elem3F98* v);
void* func_0036E540(void* entry, const char* name, void* handle, int extra);
int FileMan_FindMember(void*);
int FileMan_GetSize(void*);
void* Mem_Alloc(int pool, int size, char* file, int line);
int FileMan_LoadMemberSync(void*, char**, int);
void func_0036D540(void*, char*, char*, int);
void* FileMan_Release(void*, int);
}
static inline Node3F98* EndN(List3F98* l) { Node3F98* r; func_003F95E0(&r, func_003F95F0(l)); return r; }
static inline void Ins(List3F98* l, Elem3F98* v) { Node3F98* ins; Node3F98* pos; pos = &l->sentinel; func_003F9B30(&ins, l, &pos, v); }
extern "C" Elem3F98* func_003F9850(List3F98* self, char* name, Pool3F98* pool)
{
    char* buf;
    int heap;
    FEnt3F98 e;
    Elem3F98 tmp;
    Node3F98* n;
    Elem3F98* el;
    n = ((Node3F98*)func_003F9520(&self->sentinel))->next;
    while (n != EndN(self)) {
        if (String_CompareNoCase(&n->data, name) == 0 && n->data.loaded) {
            return &n->data;
        }
        n = n->next;
    }
    func_0036D630(&tmp);
    Ins(self, &tmp);
    func_0036D5D0(&tmp, -1);
    el = &self->sentinel.prev->data;
    func_0036E540(&e, name, pool, 0);
    FileMan_FindMember(&e);
    heap = pool->heap;
    {
        int size = FileMan_GetSize(&e);
        char* p;
        {
            AllocGuard g;
            p = (char*)Mem_Alloc(heap, size, D_004BE1F0, 0x2A);
        }
        buf = p;
    }
    FileMan_LoadMemberSync(&e, &buf, 0);
    func_0036D540(el, name, buf, pool->heap);
    el->busy = 0;
    FileMan_Release(&e, -1);
    return el;
}
