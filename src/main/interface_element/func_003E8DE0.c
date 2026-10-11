#pragma cplusplus on
#include "types.h"
struct Eq_8DE0 {};
struct Pred_8DE0 { Eq_8DE0 op; int* ref; Pred_8DE0(Eq_8DE0 o, int* r) : op(o), ref(r) {} };
extern "C" {
void ActiveList_EraseMatching(void* list, Pred_8DE0 p);
char* func_003D1020(unsigned char);
void func_003E8E80(void*, int*);
}
struct O_8DE0 { char pad[0x18]; unsigned char on; char pad2[0x74 - 0x19]; int id; };
extern "C" void func_003E8DE0(O_8DE0* o, int on) {
    unsigned char cur = o->on;
    if ((unsigned char)on != cur) {
        if (cur) {
            if (o->id) {
                int id = o->id;
                Eq_8DE0 e;
                char* x = func_003D1020(cur);
                ActiveList_EraseMatching(x + 0x10, Pred_8DE0(e, &id));
            }
            o->on = 0;
        } else {
            if (o->id) {
                int id = o->id;
                func_003E8E80(func_003D1020(cur) + 0x10, &id);
            }
            o->on = 1;
        }
    }
}