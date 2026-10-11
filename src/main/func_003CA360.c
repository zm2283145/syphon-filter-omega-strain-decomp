#include "types.h"
extern void func_003C9340(int* out, void* self);
extern void func_003CA3E0(int* out, void* self);
extern void func_003C9EA0(int* out, void* self, int* first, int* last);
extern void operator_delete(void* p);
void* func_003CA360(void* self, short del)
{
    if (self) {
        if (self) {
            int r;
            int first;
            int last;
            func_003C9340(&first, self);
            func_003CA3E0(&last, self);
            func_003C9EA0(&r, self, &first, &last);
        }
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
