#pragma cplusplus on
#include "types.h"
struct Eq_8DE0 {};
struct Pred_8DE0 { Eq_8DE0 op; int* ref; Pred_8DE0(Eq_8DE0 o, int* r) : op(o), ref(r) {} };
extern "C" {
void ActiveList_EraseMatching(void* list, Pred_8DE0 p);
char* TextManager_Get(unsigned char);
void TextManager_AddText(void*, int*);
}
struct O_8DE0 { char pad[0x18]; unsigned char on; char pad2[0x74 - 0x19]; int id; };
extern "C" void IeElement_SetShown(O_8DE0* o, int on) {
    unsigned char cur = o->on;
    if ((unsigned char)on != cur) {
        if (cur) {
            if (o->id) {
                int id = o->id;
                Eq_8DE0 e;
                char* x = TextManager_Get(cur);
                ActiveList_EraseMatching(x + 0x10, Pred_8DE0(e, &id));
            }
            o->on = 0;
        } else {
            if (o->id) {
                int id = o->id;
                TextManager_AddText(TextManager_Get(cur) + 0x10, &id);
            }
            o->on = 1;
        }
    }
}