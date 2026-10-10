#include "types.h"

extern void func_001C4650(void* self, int* a, int* b);

/* Calls func_001C4650 with two scratch outputs (discarded); returns self. */
void* func_001C0720(void* self) {
    int second, first;
    func_001C4650(self, &first, &second);
    return self;
}
