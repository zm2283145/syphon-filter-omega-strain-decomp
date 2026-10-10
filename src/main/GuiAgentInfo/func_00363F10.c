#include "types.h"

typedef struct ObjC0 {
    char pad[0xC];
    signed char flag;
} ObjC0;

extern void func_00290B90(ObjC0*);
extern void func_001396D0(ObjC0*, int);

/* Constructor: base init, then func_001396D0(self, *src) and flag byte at +0xC. */
ObjC0* func_00363F10(ObjC0* o, int* src, int flag) {
    func_00290B90(o);
    func_001396D0(o, *src);
    o->flag = flag;
    return o;
}
