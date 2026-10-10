#include "types.h"

extern int D_004A9BE0;
extern int strcmp(void*);

/* Returns whether strcmp(&D_004A9BE0) returned 0. */
int func_0028B390(void) {
    return strcmp(&D_004A9BE0) == 0;
}
