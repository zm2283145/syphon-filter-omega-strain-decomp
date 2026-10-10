#include "types.h"
typedef struct { int a; int b; } E2Key;
typedef struct { int id; char list[4]; } E2Motion;
extern int func_00198B40(void*);
extern void* func_00198B30(void*, int);
extern void* func_00198B20(void*);
extern E2Key* MotionGroup_GetKey(E2Key*, void*);
extern E2Key* func_0018A700(E2Key*, int);
extern void MotionGroup_CopyPair(E2Key*, E2Key*);
int func_00198A20(E2Motion* m, E2Key* key) {
    E2Key cur;
    E2Key t1;
    E2Key t0;
    E2Key* k;
    if (func_00198B40(m->list) == 1) {
        k = MotionGroup_GetKey(&t1, func_00198B20(func_00198B30(m->list, 0)));
    } else {
        k = func_0018A700(&t0, m->id);
    }
    MotionGroup_CopyPair(&cur, k);
    return key->a == cur.a && key->b == cur.b;
}