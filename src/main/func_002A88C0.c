#pragma cplusplus on
#include "types.h"
typedef struct LNode_88C0 { struct LNode_88C0* prev; struct LNode_88C0* next; int data; } LNode_88C0;
typedef union { LNode_88C0* p; LNode_88C0* volatile vp; } LIt_88C0;
extern "C" {
void func_002A89A0(LIt_88C0* out, void* list);
void func_0028C0A0(LIt_88C0* out, void* list);
void func_0028C090(LIt_88C0* r, LIt_88C0* s);
}
struct LItS_88C0 { LNode_88C0* p; LItS_88C0(LNode_88C0* n) : p(n) {} };
extern "C" LItS_88C0 func_002A88C0(void* list, const int& val)
{
    LIt_88C0 it;
    LIt_88C0 c;
    LIt_88C0 end;
    LIt_88C0 b0;
    LIt_88C0 e0;
    func_002A89A0(&b0, list);
    func_0028C090(&c, &b0);
    for (it = c; func_0028C0A0(&e0, list), func_0028C090(&end, &e0), it.p != end.p; it.p = it.vp->next) {
        if (it.p->data == val) break;
    }
    return LItS_88C0(it.p);
}
