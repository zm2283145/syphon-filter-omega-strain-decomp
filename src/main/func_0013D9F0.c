#include "types.h"

typedef struct { char b[0xC]; } ScalarCollection;
extern signed char D_004EA100;
extern int D_004EA108;
extern ScalarCollection D_004EA118;
extern void ScalarCollection_Init(ScalarCollection* c);
extern void func_0013DAD0(void);
extern void __register_global_object(void* obj, void* dtor, void* link);

/* Returns the lazily constructed static collection at D_004EA118. */
ScalarCollection* func_0013D9F0(void)
{
    if (D_004EA100 == 0) {
        ScalarCollection_Init(&D_004EA118);
        __register_global_object(&D_004EA118, func_0013DAD0, &D_004EA108);
        D_004EA100 = 1;
    }
    return &D_004EA118;
}
