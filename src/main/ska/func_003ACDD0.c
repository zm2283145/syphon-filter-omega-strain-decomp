#include "types.h"
#pragma cplusplus on
struct C4Anim3AC { char pad[0x31]; unsigned char complete; };
struct C4It3AC { void* p; C4It3AC() {} C4It3AC(const C4It3AC& o) : p(o.p) {} };
extern "C" {
C4It3AC func_00198B90(void* list);
C4It3AC func_00198B60(void* list);
bool func_001989E0(C4It3AC* a, C4It3AC* b);
void func_00198A00(C4It3AC* it);
C4Anim3AC** func_00198B50(C4It3AC* it);
bool func_00198A20(C4Anim3AC* a, int id);
}
extern "C" unsigned char AnimGroup_IsComplete(void* list, int id) {
    C4Anim3AC* found = 0;
    C4It3AC it = func_00198B90(list);
    C4It3AC end = func_00198B60(list);
    while (func_001989E0(&it, &end)) {
        if (func_00198A20(*func_00198B50(&it), id)) {
            found = *func_00198B50(&it);
            break;
        }
        func_00198A00(&it);
    }
    if (found) return found->complete;
    return 0;
}