#include "types.h"

extern char D_0048C448[];

void stubCreate(void) {
    int tmp0;

    tmp0 = *(int*)(char*)(int)D_0048C448;
    *(int*)((char*)(int)D_0048C448) = (tmp0 + 1);
}

static char D_0048C448[8] = { 0 };
