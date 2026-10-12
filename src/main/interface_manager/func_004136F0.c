#pragma cplusplus on
#include "types.h"

struct Str4136F0 { int a; int b; int c; };
struct List4136F0 { int pad0; int count; Str4136F0* data; };
struct Self4136F0 { char pad[0x1E4]; List4136F0* list; };

extern "C" {
int String_AssignCStr_1C43A0(Str4136F0* s, char* name);
int func_00413870(List4136F0* v);
Str4136F0* func_00413850(List4136F0* v, int index);
Str4136F0* func_00329930(Str4136F0* dst, Str4136F0* src);
void StringVec_PopBack(List4136F0* v);
}

#pragma push
#pragma opt_strength_reduction off
extern "C" void func_004136F0(Self4136F0* self, char* name)
{
    int i;
    if (self->list) {
        for (i = 0; i < self->list->count; i++) {
            if (!String_AssignCStr_1C43A0(&self->list->data[i], name)) {
                List4136F0* v = self->list;
                int n = func_00413870(v);
                if (i >= 0 && i < n) {
                    int j;
                    for (j = i + 1; j < n; j++) {
                        func_00329930(func_00413850(v, j - 1), func_00413850(v, j));
                    }
                    StringVec_PopBack(v);
                }
                return;
            }
        }
    }
}
#pragma pop

