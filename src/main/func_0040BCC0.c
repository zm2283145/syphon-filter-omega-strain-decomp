#include "types.h"

typedef struct Obj40BCC0 {
    char pad[0xC];
    unsigned char unkC;
} Obj40BCC0;

extern signed char D_00571C20;
extern Obj40BCC0 D_00571C40;
extern char D_00571C28;
extern void func_0040BEB0(Obj40BCC0*);
extern int func_001361D0(int*);
extern void func_0040BEA0(Obj40BCC0*, int);
extern void func_0040BD50(void);
extern void __register_global_object(void*, void*, void*);

#pragma push
#pragma opt_propagation off
Obj40BCC0* func_0040BCC0(void) {
    if (!D_00571C20) {
        Obj40BCC0* p = &D_00571C40;
        int kind;
        kind = 0x20;
        func_0040BEB0(p);
        func_0040BEA0(p, func_001361D0(&kind));
        p->unkC = 1;
        __register_global_object(p, func_0040BD50, &D_00571C28);
        D_00571C20 = 1;
    }
    return &D_00571C40;
}
#pragma pop

