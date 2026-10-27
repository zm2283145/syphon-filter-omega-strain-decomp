#pragma cplusplus on
#include "types.h"
struct Eq_8DE0 {};
struct Pred_8DE0 { Eq_8DE0 op; int* ref; Pred_8DE0(Eq_8DE0 o, int* r) : op(o), ref(r) {} };
extern "C" {
void std_list_imp_voidPtr_remove_if(void* list, Pred_8DE0 p);
char* GetTextSystem(unsigned char);
void cLList_cTextAreaPtr_PushBackActual(void*, int*);
}
struct O_8DE0 { char pad[0x18]; unsigned char on; char pad2[0x74 - 0x19]; int id; };
extern "C" void cInterfaceElement_Activate(O_8DE0* o, int on) {
    unsigned char cur = o->on;
    if ((unsigned char)on != cur) {
        if (cur) {
            if (o->id) {
                int id = o->id;
                Eq_8DE0 e;
                char* x = GetTextSystem(cur);
                std_list_imp_voidPtr_remove_if(x + 0x10, Pred_8DE0(e, &id));
            }
            o->on = 0;
        } else {
            if (o->id) {
                int id = o->id;
                cLList_cTextAreaPtr_PushBackActual(GetTextSystem(cur) + 0x10, &id);
            }
            o->on = 1;
        }
    }
}