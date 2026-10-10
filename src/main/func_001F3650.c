#include "types.h"

extern void func_001F3690(int* out);
extern void func_001F3580(void* self, int* value);

/* Fetches a value via func_001F3690 and applies it to self via func_001F3580. */
void func_001F3650(void* self) {
    int value;
    func_001F3690(&value);
    func_001F3580(self, &value);
}
