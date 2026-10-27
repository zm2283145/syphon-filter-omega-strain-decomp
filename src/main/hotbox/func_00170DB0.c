#pragma cplusplus on
#include "types.h"
struct Eq_0DB0 {};
struct Pred_0DB0 { Eq_0DB0 op; int* ref; Pred_0DB0(const Eq_0DB0& e, int* r) : op(e), ref(r) {} };
struct S_0DB0 { char pad[0x28]; char list[4]; };
extern "C" {
extern char g_HotboxList[];
void std_list_imp_voidPtr_remove_if(void* list, Pred_0DB0 p);
}
extern "C" void cHotboxMan_RemoveHotbox(S_0DB0* self, int id)
{
    Eq_0DB0 e1;
    Eq_0DB0 e2;
    std_list_imp_voidPtr_remove_if(g_HotboxList, Pred_0DB0(e1, &id));
    std_list_imp_voidPtr_remove_if(self->list, Pred_0DB0(e2, &id));
}