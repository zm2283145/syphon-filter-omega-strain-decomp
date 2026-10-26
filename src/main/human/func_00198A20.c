#include "types.h"
typedef struct { int a; int b; } E2Key;
typedef struct { int id; char list[4]; } E2Motion;
extern int cArray_cSkaPlaybackItem_Size(void*);
extern void* cArray_cSkaPlaybackItem_opIndex(void*, int);
extern void* cSkaPlaybackItem_GetAnimation(void*);
extern E2Key* MotionGroup_GetKey(E2Key*, void*);
extern E2Key* cSkaPlaybackGroupId_ctor_int(E2Key*, int);
extern void MotionGroup_CopyPair(E2Key*, E2Key*);
int cSkaPlaybackGroup_CheckId(E2Motion* m, E2Key* key) {
    E2Key cur;
    E2Key t1;
    E2Key t0;
    E2Key* k;
    if (cArray_cSkaPlaybackItem_Size(m->list) == 1) {
        k = MotionGroup_GetKey(&t1, cSkaPlaybackItem_GetAnimation(cArray_cSkaPlaybackItem_opIndex(m->list, 0)));
    } else {
        k = cSkaPlaybackGroupId_ctor_int(&t0, m->id);
    }
    MotionGroup_CopyPair(&cur, k);
    return key->a == cur.a && key->b == cur.b;
}