#include "types.h"

extern int* func_001F3050(void* obj);

/* Returns the int pointed to by func_001F3050's result. */
int func_001F3030(void* obj) {
    return *func_001F3050(obj);
}
