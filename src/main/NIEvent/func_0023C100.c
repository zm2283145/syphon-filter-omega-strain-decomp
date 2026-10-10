#include "types.h"
typedef struct B5hObj { char pad[0x94]; struct B5hObj* next; } B5hObj;
extern void func_0023C010(B5hObj* o);
void cNIEventOBJ_v15(B5hObj* o) {
    B5hObj* n = o->next;
    while (n) {
        o = n;
        n = n->next;
    }
    func_0023C010(o);
}