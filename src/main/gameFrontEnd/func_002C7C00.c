#include "types.h"

extern int D_0051EF98;
unsigned int D_0048C368[2] = { 0x1F40, 0x0 };
extern unsigned long long func_003698B0(void);

/* Returns whether D_0051EF98 + (*(int*)D_0048C368) is below func_003698B0(). */
int func_002C7C00(void) {
    unsigned long long limit = func_003698B0();
    return (unsigned long long)(D_0051EF98 + (*(int*)D_0048C368)) < limit;
}
