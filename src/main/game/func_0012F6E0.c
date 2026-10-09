/*
 * Matched functions (byte-identical with the retail executable).
 * Script bindings and global level/stat reset helpers.
 */

#include "types.h"
#include "game_types.h"

extern void AgentData_ResetMission(int);
extern int Agent_GetSelected(int, int);
extern char D_004FFB50[];                      /* world object */
extern char* D_004FFC0C;                       /* world +0xBC service */
extern GameTimerService* D_004FFC2C;           /* world +0xDC service */
extern int D_004FFC3C;                         /* world +0xEC service */
extern unsigned char D_005721C8;               /* multiplayer flag */
extern int Game_IsMultiplayer(void);
extern int Global_ResetLevel(void);
extern void Global_ResetStats(void);
extern int Script_ClearSchedules_3DFB20(void);
extern void func_0013A290(GameTimerService*);
extern int func_00247320(int);
extern int func_002570C0(void);
extern int func_0025A120(void);
extern void func_002795A0(int);
extern int func_003FA1E0(int);

int Script_ResetLevel(void) {
    Global_ResetLevel();
    return 0;
}

/* Resets world services, the selected agent's mission data and all script schedules. */
int Global_ResetLevel(void) {
    GameTimerService* svc;
    int agent;

    func_00247320((int)(D_004FFC0C + 0x50));
    func_002570C0();
    func_0025A120();
    agent = Agent_GetSelected((int)D_004FFB50, -1);
    AgentData_ResetMission(agent);
    svc = D_004FFC2C;
    svc->unk6DC = 0;
    svc->unk6E0 = 0xbf800000; /* -1.0f */
    func_0013A290(D_004FFC2C);
    func_003FA1E0((int)((char*)D_004FFC2C + 0x100));
    func_002795A0(D_004FFC3C);
    return Script_ClearSchedules_3DFB20();
}

int Script_ResetStats(void) {
    Global_ResetStats();
    return 0;
}

/* Resets the selected agent's mission data and the timer service fields. */
void Global_ResetStats(void) {
    GameTimerService* svc;
    int agent;

    agent = Agent_GetSelected((int)D_004FFB50, -1);
    AgentData_ResetMission(agent);
    svc = D_004FFC2C;
    svc->unk6DC = 0;
    svc->unk6E0 = 0xbf800000; /* -1.0f */
}

int Script_IsMultiplayer(void) {
    return Game_IsMultiplayer() & 0xFF;
}

int Game_IsMultiplayer(void) {
    return D_005721C8;
}
