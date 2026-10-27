#pragma opt_common_subs off
#include "types.h"
typedef struct { void* p; int id; } H_198D00;
typedef struct L_198D00 { int pad0; struct L_198D00* next; void* item; } L_198D00;
typedef struct { L_198D00* n; } It_198D00;
typedef struct { int raw; } RIt_198D00;
extern void std_list_deleter_voidPtr_begin_void_2(RIt_198D00* out, void* self);
extern void std_list_deleter_voidPtr_end_void_2(RIt_198D00* out, void* self);
extern void std_list_cSkaPlaybackGroupPtr_generic_iterator_1_ctor(It_198D00* out, int raw);
extern void cSkaPlaybackGroup_GetId(H_198D00* out, void* item);
extern int cSkaPlaybackGroupId_opEq(void* key, H_198D00* h);
void* cSkaPlaybackList_FindPlaybackGroup(void* self, void* key)
{
    It_198D00 b;
    It_198D00 d;
    RIt_198D00 a;
    RIt_198D00 c;
    H_198D00 h;
    void* r = 0;
    L_198D00* it;
    L_198D00* end;
    std_list_deleter_voidPtr_begin_void_2(&a, self);
    std_list_cSkaPlaybackGroupPtr_generic_iterator_1_ctor(&b, a.raw);
    it = b.n;
    std_list_deleter_voidPtr_end_void_2(&c, self);
    std_list_cSkaPlaybackGroupPtr_generic_iterator_1_ctor(&d, c.raw);
    end = d.n;
    for (; it != end; it = it->next) {
        cSkaPlaybackGroup_GetId(&h, it->item);
        if (cSkaPlaybackGroupId_opEq(key, &h)) {
            r = it->item;
            break;
        }
    }
    return r;
}
