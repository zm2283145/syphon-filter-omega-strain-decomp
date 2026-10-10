#include "types.h"

typedef struct TmpB0 {
    char b[0xB0];
} TmpB0;

typedef struct ObjB0 {
    char pad[0xB0];
    int unkB0;
    char sub[4];
} ObjB0;

extern void AnimRoot_ConstructBase(TmpB0*);
extern void func_003B6CB0(ObjB0*, TmpB0*);
extern void func_003BA260(void*);

/* Constructor: initializes from a default temporary and sets up the sub-object at +0xB4. */
ObjB0* func_003BA210(ObjB0* o) {
    TmpB0 tmp;
    AnimRoot_ConstructBase(&tmp);
    func_003B6CB0(o, &tmp);
    o->unkB0 = 0;
    func_003BA260(o->sub);
    return o;
}
