#pragma cplusplus on
#include "types.h"
struct Eq_0570 {};
struct Pred_0570 { Eq_0570 op; int* ref; Pred_0570(const Eq_0570& e, int* r) : op(e), ref(r) {} };
struct M_0570 { char pad[0x28]; char list[4]; };
extern "C" {
extern char g_HotboxList[];
extern char g_RuntimeHotboxes[];
extern int D_004EE6E4;
extern M_0570* g_HotboxTracker;
void ActiveList_EraseMatching(void* list, Pred_0570 p);
int* func_00170650(void* v, int i);
}
extern "C" void func_00170570(void)
{
    int key;
    Eq_0570 e1;
    Eq_0570 e2;
    M_0570* mgr = g_HotboxTracker;
    int i;
    for (i = 0; i < D_004EE6E4; i++) {
        key = *func_00170650(g_RuntimeHotboxes, i);
        ActiveList_EraseMatching(g_HotboxList, Pred_0570(e1, &key));
        ActiveList_EraseMatching(mgr->list, Pred_0570(e2, &key));
    }
    D_004EE6E4 = 0;
}