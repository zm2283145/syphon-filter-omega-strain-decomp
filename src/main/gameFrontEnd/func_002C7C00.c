#include "types.h"

extern int D_0051EF98;
unsigned int D_0048C368[2] = { 0x1F40, 0x0 };
extern unsigned long long cTimer_GetMillisecondTime(void);

/* Returns whether D_0051EF98 + (*(int*)D_0048C368) is below cTimer_GetMillisecondTime(). */
int func_002C7C00(void) {
    unsigned long long limit = cTimer_GetMillisecondTime();
    return (unsigned long long)(D_0051EF98 + (*(int*)D_0048C368)) < limit;
}
