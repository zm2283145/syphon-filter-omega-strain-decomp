#include "types.h"

typedef struct Obj40BCC0 {
    char pad[0xC];
    unsigned char unkC;
} Obj40BCC0;

extern signed char D_00571C20;
extern Obj40BCC0 D_00571C40;
extern char D_00571C28;
extern void std_vector_cBaseObjListPtr_ctor(Obj40BCC0*);
extern int cArrayCapacity_Int(int*);
extern void std_vector_cBaseObjListPtr_reserve(Obj40BCC0*, int);
extern void cArray_cBaseObjListPtr_dtor(void);
extern void __register_global_object(void*, void*, void*);

#pragma push
#pragma opt_propagation off
Obj40BCC0* GobjScope_GetList(void) {
    if (!D_00571C20) {
        Obj40BCC0* p = &D_00571C40;
        int kind;
        kind = 0x20;
        std_vector_cBaseObjListPtr_ctor(p);
        std_vector_cBaseObjListPtr_reserve(p, cArrayCapacity_Int(&kind));
        p->unkC = 1;
        __register_global_object(p, cArray_cBaseObjListPtr_dtor, &D_00571C28);
        D_00571C20 = 1;
    }
    return &D_00571C40;
}
#pragma pop

