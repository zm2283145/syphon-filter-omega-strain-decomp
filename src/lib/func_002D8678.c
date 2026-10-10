#include "types.h"

extern char D_0048C438[];
extern int func_002F5160(void);

void func_002D8678(void) {
    int tmp0;

    tmp0 = func_002F5160();
    *(int*)D_0048C438 = tmp0;
}
