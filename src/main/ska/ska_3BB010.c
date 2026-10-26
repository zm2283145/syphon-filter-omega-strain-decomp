#include "types.h"

extern char g_TextureMgr[];
extern int TexMan_ReleaseSlot(int, int);

void cUserFrameEnv_Deactivate(int a0, int a1) {
    int s0, v0, v1;
    int cond;

    cond = a1 != 0;
    s0 = a0;
    if (cond) goto L003BB050;
    a0 = *(int*)(char*)g_TextureMgr;
    a1 = *(int*)(char*)s0;
    v0 = TexMan_ReleaseSlot(a0, a1);
    a1 = *(int*)((char*)s0 + 4);
    v1 = 0 + -1;
    cond = a1 == v1;
    if (cond) goto L003BB050;
    a0 = *(int*)(char*)g_TextureMgr;
    v0 = TexMan_ReleaseSlot(a0, a1);
L003BB050:;
    goto ret;
ret:;
}
