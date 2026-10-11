#pragma cplusplus on
#include "types.h"
struct Eq_0570 {};
struct Pred_0570 { Eq_0570 op; int* ref; Pred_0570(const Eq_0570& e, int* r) : op(e), ref(r) {} };
struct M_0570 { char pad[0x28]; char list[4]; };
extern "C" {
extern char D_004EE688[];
extern char D_004EE6E0[];
extern int D_004EE6E4;
extern M_0570* D_004FFBD0;
void ActiveList_EraseMatching(void* list, Pred_0570 p);
int* func_00170650(void* v, int i);
}
extern "C" void func_00170570(void)
{
    int key;
    Eq_0570 e1;
    Eq_0570 e2;
    M_0570* mgr = D_004FFBD0;
    int i;
    for (i = 0; i < D_004EE6E4; i++) {
        key = *func_00170650(D_004EE6E0, i);
        ActiveList_EraseMatching(D_004EE688, Pred_0570(e1, &key));
        ActiveList_EraseMatching(mgr->list, Pred_0570(e2, &key));
    }
    D_004EE6E4 = 0;
}