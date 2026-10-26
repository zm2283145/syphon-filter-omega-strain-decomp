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
void* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_11(void*);
void* std_list_deleter_cHogFile_generic_iterator_ctor(Node3F98** out, void* v);
void* std_list_deleter_cHogFile_tail(List3F98*);
int String_CompareNoCase(void*, char*);
void cHogFile_ctor(void*);
void cHogFile_dtor(void*, int);
void std_list_deleter_cHogFile_insert(Node3F98** out, List3F98* l, Node3F98** pos, Elem3F98* v);
void* cFileMan_ctor_charP_cHogFileR_bool(void* entry, const char* name, void* handle, int extra);
int FileMan_FindMember(void*);
int FileMan_GetSize(void*);
void* Mem_Alloc(int pool, int size, char* file, int line);
int FileMan_LoadMemberSync(void*, char**, int);
void Hog_OpenInMemory(void*, char*, char*, int);
void* FileMan_Release(void*, int);
}
static inline Node3F98* EndN(List3F98* l) { Node3F98* r; std_list_deleter_cHogFile_generic_iterator_ctor(&r, std_list_deleter_cHogFile_tail(l)); return r; }
static inline void Ins(List3F98* l, Elem3F98* v) { Node3F98* ins; Node3F98* pos; pos = &l->sentinel; std_list_deleter_cHogFile_insert(&ins, l, &pos, v); }
extern "C" Elem3F98* cHogList_OpenFromHog(List3F98* self, char* name, Pool3F98* pool)
{
    char* buf;
    int heap;
    FEnt3F98 e;
    Elem3F98 tmp;
    Node3F98* n;
    Elem3F98* el;
    n = ((Node3F98*)details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_11(&self->sentinel))->next;
    while (n != EndN(self)) {
        if (String_CompareNoCase(&n->data, name) == 0 && n->data.loaded) {
            return &n->data;
        }
        n = n->next;
    }
    cHogFile_ctor(&tmp);
    Ins(self, &tmp);
    cHogFile_dtor(&tmp, -1);
    el = &self->sentinel.prev->data;
    cFileMan_ctor_charP_cHogFileR_bool(&e, name, pool, 0);
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
    Hog_OpenInMemory(el, name, buf, pool->heap);
    el->busy = 0;
    FileMan_Release(&e, -1);
    return el;
}
