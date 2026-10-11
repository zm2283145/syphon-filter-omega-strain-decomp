#include "types.h"
extern void operator_delete(void* p);
void func_00430A10(int a, void* p) {
    operator_delete(p);
}
