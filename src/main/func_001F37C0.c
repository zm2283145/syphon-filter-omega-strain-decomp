#include "types.h"

typedef struct Obj3 {
    int a;
    int b;
    int c;
} Obj3;

extern void func_001F3800(Obj3*, int);

/* Constructor: func_001F3800(self, 0), then clears +4 and +8. */
Obj3* func_001F37C0(Obj3* o) {
    func_001F3800(o, 0);
    o->b = 0;
    o->c = 0;
    return o;
}
