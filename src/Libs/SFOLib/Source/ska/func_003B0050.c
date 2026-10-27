#pragma cplusplus on

#include "types.h"

/* Find the first list entry matching key; 0 if none. */
typedef struct { int w[1]; } It_3B0050;
typedef struct { unsigned char pad[0x6C]; int list; } Obj_3B0050;

extern "C" {
void cLList_cSkaTransPlaybackPtr_Begin(It_3B0050* out, void* list);
void cLList_cSkaTransPlaybackPtr_End(It_3B0050* out, void* list);
bool opNe_cLListIteratorR_cLListIteratorR_8(It_3B0050* a, It_3B0050* b);
int* cLListIterator_cSkaTransPlaybackPtr_opMul(It_3B0050* it);
void cLListIterator_cSkaTransPlaybackPtr_opInc(It_3B0050* it);
int cSkaTransPlayback_CheckId(int entry, void* key);
}

extern "C" int cSkaSwitch_GetTransPlayback(void* key, Obj_3B0050* o)
{
    It_3B0050 it;
    It_3B0050 end;
    for (cLList_cSkaTransPlaybackPtr_Begin(&it, &o->list); (cLList_cSkaTransPlaybackPtr_End(&end, &o->list), opNe_cLListIteratorR_cLListIteratorR_8(&it, &end)); cLListIterator_cSkaTransPlaybackPtr_opInc(&it)) {
        if (cSkaTransPlayback_CheckId(*cLListIterator_cSkaTransPlaybackPtr_opMul(&it), key))
            return *cLListIterator_cSkaTransPlaybackPtr_opMul(&it);
    }
    return 0;
}