#include "types.h"
typedef struct { int a; int b; unsigned char ready; } O470;
extern int func_004084D0(O470* o, const char* name, unsigned char* out);
unsigned char func_00408470(O470* o, const char* name) {
    unsigned char r = 0;
    if (!o->ready || !name || !*name)
        return 0;
    func_004084D0(o, name, &r);
    return r;
}