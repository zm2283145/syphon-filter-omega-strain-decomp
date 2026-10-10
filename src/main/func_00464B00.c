#include "types.h"

typedef struct Obj4C {
    char pad[0x4C];
    int handle;
} Obj4C;

extern void func_0041EBF0(Obj4C*);
extern void func_0026D720(int);

/* Calls func_0041EBF0, releases the handle at +0x4C and clears it. */
void func_00464B00(Obj4C* o) {
    func_0041EBF0(o);
    func_0026D720(o->handle);
    o->handle = 0;
}
