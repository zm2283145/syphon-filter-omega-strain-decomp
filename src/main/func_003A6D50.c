#include "types.h"

extern char D_0053DC00[];
extern char D_0053DC08[];
extern int func_001183B8(int);

int func_003A6D50(int a0) {
    int v0;
    int cond;

    v0 = *(int*)(char*)D_0053DC00;
    cond = v0 != 0;
    if (cond) goto L003A6D78;
    v0 = func_001183B8(a0);
    goto L003A6D88;
L003A6D78:;
    v0 = *(int*)(char*)D_0053DC08;
    *(int*)(char*)D_0053DC08 = a0;
L003A6D88:;
    goto ret;
ret:
    return v0;
}
