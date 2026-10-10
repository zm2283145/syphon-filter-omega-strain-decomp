#include "types.h"

extern void func_00383560(int* out, void* a, int* b);

/* Calls func_00383560 with a copy of *b and stores the produced word in *out. */
void func_00380CE0(int* out, void* a, int* b) {
    int value;
    int result;
    value = *b;
    func_00383560(&result, a, &value);
    *out = result;
}
