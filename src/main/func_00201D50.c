#include "types.h"

extern int func_00201E80(void* src);
extern void func_00201DC0(void* self, int value);
extern int func_00201C10(void* src);
extern int func_00201BC0(void* src);
extern void func_00209680(void* self, int first, int last, char alloc);

/* Copy-constructs self from src: header, then the range [begin, end) of src. */
void* func_00201D50(void* self, void* src) {
    volatile char alloc[4];
    int first, last;
    func_00201DC0(self, func_00201E80(src));
    first = func_00201C10(src);
    last = func_00201BC0(src);
    func_00209680(self, first, last, alloc[0]);
    return self;
}
