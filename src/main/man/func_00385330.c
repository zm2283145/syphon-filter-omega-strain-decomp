#include "types.h"

/* Result block filled by func_00385370; the quadword at +0x30 is returned. */
typedef struct Result385 {
    char pad[0x30];
    Q value;
} Result385;

extern void func_00385370(void* src, Result385* out);

/* Computes a result block from src and copies its quadword at +0x30 to out. */
void func_00385330(Q* out, void* src) {
    Result385 result;
    func_00385370(src, &result);
    *out = result.value;
}
