#include "types.h"

extern void func_001F4220(int*);
extern void func_001F41C0(void*, int*);

/* Fetches a value via func_001F4220 and passes it to func_001F41C0(self, &value). */
void func_001F4180(void* self) {
    int value;
    func_001F4220(&value);
    func_001F41C0(self, &value);
}
