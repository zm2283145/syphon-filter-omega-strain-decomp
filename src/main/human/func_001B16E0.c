#include "types.h"

extern int ActorModel_Draw(int);

void Actor_Draw(int a0) {
    int v0, v1;
    int cond;

    v1 = *(int*)((char*)a0 + 13236);
    cond = v1 != 0;
    if (cond) goto L001B1700;
    v0 = ActorModel_Draw(a0);
L001B1700:;
    goto ret;
ret:;
}
