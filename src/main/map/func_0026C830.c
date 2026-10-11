#include "types.h"
typedef struct { char pad[0x24]; int state; } Sub26C8;
typedef struct { Sub26C8* sub; } Self26C8;
typedef struct { char pad[0x10]; int kind; } Obj26C8;
extern Obj26C8* func_00272AC0(Sub26C8* s);
extern void func_00272AD0(Sub26C8* s, int v);
extern void func_0026C570(Self26C8* s);
extern void func_0026C3B0(Self26C8* s);
void func_0026C830(Self26C8* s, Obj26C8* o) {
    unsigned char ok = 1;
    if (!(o->kind == 1 || o->kind == 2)) ok = 0;
    if (ok && o == func_00272AC0(s->sub)) {
        if (s->sub->state == 1) {
            func_00272AD0(s->sub, 0);
            func_0026C570(s);
        } else {
            func_0026C3B0(s);
        }
    }
}

