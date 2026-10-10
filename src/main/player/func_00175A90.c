#include "types.h"

typedef struct { char pad[0x6AC]; char timer[0x30]; float baseTime; } SoundMgr175;
typedef union { int i; float f; } ScriptArg;

extern SoundMgr175* D_004FFC2C;
extern int Loc_LookupText(int id);
extern void func_00244EE0(void* timer, int obj, float time);

/* Script native: starts the player timer with the given time and optional target. */
int Script_cPlayer_SetTimer_2(ScriptArg* args)
{
    float timeArg[1];
    int idArg[1];
    float time;
    int id;
    idArg[0] = args[2].i;
    *(int*)timeArg = args[1].i;
    time = *timeArg;
    id = *(int*)idArg ? Loc_LookupText(*(int*)idArg) : 0;
    func_00244EE0(D_004FFC2C->timer, id, time + D_004FFC2C->baseTime);
    return 0;
}
