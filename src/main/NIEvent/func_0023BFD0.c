#include "types.h"
typedef struct B4Ev { char pad[0x94]; struct B4Ev* next; } B4Ev;
extern void func_0023BEE0(B4Ev*);
void cNIEventOBJ_v16(B4Ev* p) {
    B4Ev* n;
    for (n = p->next; n != 0; n = n->next) p = n;
    func_0023BEE0(p);
}