#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct Node_DC60 { int pad0; Node_DC60* next; void* val; };
struct It_DC60 { Node_DC60* n; };
struct E_DC60 { int a; };
struct Perc_DC60 { char pad[0x30]; char map[4]; char hdr[4]; char* first; };
extern "C" {
extern char D_0049C650[];
void Mem_Free(int pool, void* allocation, char* file, int line);
void func_0016BB80(E_DC60* out, void* map);
void func_0016BBA0(E_DC60* out, void* map);
void func_0016BB90(It_DC60* out, E_DC60* in);
void ObjectList_EraseRange(int* out, void* map, char** first, char** last);
}
static inline void Free_DC60(void* v)
{
    AllocGuard g;
    Mem_Free(0, v, D_0049C650, 0x235);
}
static inline void Begin0_DC60(It_DC60* out, void* map) { E_DC60 t; func_0016BBA0(&t, map); func_0016BB90(out, &t); }
static inline void End0_DC60(It_DC60* out, void* map) { E_DC60 t; func_0016BB80(&t, map); func_0016BB90(out, &t); }
static inline void Begin_DC60(It_DC60* out, void* map) { Begin0_DC60(out, map); }
static inline void End_DC60(It_DC60* out, void* map) { End0_DC60(out, map); }
static inline void Erase_DC60(Perc_DC60* self)
{
    int res;
    char* first;
    char* last;
    last = self->hdr;
    first = self->first;
    ObjectList_EraseRange(&res, self->map, &first, &last);
}
typedef struct It_DC60 It_DC60;
typedef struct E_DC60 E_DC60;
typedef struct Perc_DC60 Perc_DC60;
#pragma cplusplus off
void NpcPerception_Clear(Perc_DC60* self)
{
    It_DC60 it;
    It_DC60 b;
    It_DC60 end;
    Begin_DC60(&b, self->map);
    it = b;
    while (End_DC60(&end, self->map), it.n != end.n) {
        Free_DC60(it.n->val);
        it.n = it.n->next;
    }
    Erase_DC60(self);
}

