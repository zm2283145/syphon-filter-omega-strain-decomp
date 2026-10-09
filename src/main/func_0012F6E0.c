/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004FFB50[];
extern char D_004FFC0C[];
extern char D_004FFC2C[];
extern char D_004FFC3C[];
extern char D_005721C8[];
extern int Game_IsMultiplayer(void);
extern int func_0012F700(void);
extern void func_0012F7B0(void);
extern int Agent_GetSelected(int, int);
extern void func_0013A290(int);
extern int func_00247320(int);
extern int func_002570C0(void);
extern int func_0025A120(void);
extern void func_002795A0(int);
extern void AgentData_ResetMission(int);
extern int Script_ClearSchedules_3DFB20(void);
extern int func_003FA1E0(int);

int func_0012F6E0(void) {
    func_0012F700();
    return 0;
}

int func_0012F700(void) {
    int tmp0;
    int tmp7;
    int tmp11;
    int tmp12;
    int tmp15;
    int tmp18;
    int tmp21;

    tmp0 = *(int*)D_004FFC0C;
    func_00247320((tmp0 + 80));
    func_002570C0();
    func_0025A120();
    tmp7 = Agent_GetSelected((int)D_004FFB50, -1);
    AgentData_ResetMission(tmp7);
    tmp11 = *(int*)D_004FFC2C;
    *(int*)((char*)tmp11 + 1756) = 0;
    *(int*)((char*)tmp11 + 1760) = 0xbf800000;
    tmp12 = *(int*)D_004FFC2C;
    func_0013A290(tmp12);
    tmp15 = *(int*)D_004FFC2C;
    func_003FA1E0((tmp15 + 256));
    tmp18 = *(int*)D_004FFC3C;
    func_002795A0(tmp18);
    tmp21 = Script_ClearSchedules_3DFB20();
    return tmp21;
}

int func_0012F790(void) {
    func_0012F7B0();
    return 0;
}

void func_0012F7B0(void) {
    int tmp0;
    int tmp4;

    tmp0 = Agent_GetSelected((int)D_004FFB50, -1);
    AgentData_ResetMission(tmp0);
    tmp4 = *(int*)D_004FFC2C;
    *(int*)((char*)tmp4 + 1756) = 0;
    *(int*)((char*)tmp4 + 1760) = 0xbf800000;
}

int Script_IsMultiplayer(void) {
    int tmp0;

    tmp0 = Game_IsMultiplayer();
    return (tmp0 & 255);
}

int Game_IsMultiplayer(void) {
    unsigned char tmp0;

    tmp0 = *(unsigned char*)D_005721C8;
    return tmp0;
}
