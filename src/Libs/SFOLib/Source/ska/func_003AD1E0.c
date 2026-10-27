#pragma cplusplus on

#include "types.h"

/* Look up the entry matching key and return its info block (or a blank one). */
typedef struct { int w[1]; } It_3AD1E0;
typedef struct { int a; int b; unsigned char c; } Info_3AD1E0;
typedef struct { unsigned char pad[0x20]; Info_3AD1E0 info; } Ent_3AD1E0;

extern "C" {
void cArray_cString_REnd(It_3AD1E0* out, void* map);
void func_00198B60(It_3AD1E0* out, void* map);
bool opNe_cConstLListIteratorR_cConstLListIteratorR(It_3AD1E0* a, It_3AD1E0* b);
Ent_3AD1E0** cConstLListIterator_cSkaPlaybackGroupPtr_opMul(It_3AD1E0* it);
void cConstLListIterator_cSkaPlaybackGroupPtr_opInc(It_3AD1E0* it);
int cSkaPlaybackGroup_CheckId(Ent_3AD1E0* e, void* key);
}

extern "C" Info_3AD1E0* func_003AD1E0(void* map, void* key)
{
    Ent_3AD1E0* found = 0;
    It_3AD1E0 it;
    It_3AD1E0 end;
    Info_3AD1E0 blank;
    cArray_cString_REnd(&it, map);
    func_00198B60(&end, map);
    for (; opNe_cConstLListIteratorR_cConstLListIteratorR(&it, &end); cConstLListIterator_cSkaPlaybackGroupPtr_opInc(&it)) {
        if (cSkaPlaybackGroup_CheckId(*cConstLListIterator_cSkaPlaybackGroupPtr_opMul(&it), key)) {
            found = *cConstLListIterator_cSkaPlaybackGroupPtr_opMul(&it);
            break;
        }
    }
    if (found)
        return &found->info;
    blank.a = 0;
    blank.b = 0;
    blank.c = 0;
    return &blank;
}