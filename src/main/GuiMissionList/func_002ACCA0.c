#include "types.h"

extern int GuiMissionList_UpdateLobbyList(int);
extern int GuiWidget_onAdvanceTime(int, float);

void GuiMissionList_onAdvanceTime(int a0) {
    int s0, v0, v1;
    float f12;
    int cond;

    s0 = a0;
    v0 = GuiWidget_onAdvanceTime(a0, f12);
    v1 = *(int*)((char*)s0 + 284);
    cond = v1 == 0;
    if (cond) goto L002ACCD8;
    v1 = *(unsigned char*)((char*)v1 + 24);
    cond = v1 == 0;
    a0 = s0;
    if (cond) goto L002ACCD8;
    v0 = GuiMissionList_UpdateLobbyList(a0);
L002ACCD8:;
    goto ret;
ret:;
}
