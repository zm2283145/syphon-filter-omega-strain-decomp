#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Script_RegisterType(char *, char *, int, int);            
extern char *D_004F5370;
extern char *D_004F5378;
extern char *D_004F5380;
extern int D_004F5388;
extern int D_004F5390;
extern char *D_004F5398;
extern int D_004F53A8;
extern int D_004F53B0;
extern char ScriptType_cEndLevelMsg_Init;
extern char ScriptType_cStartLevelMsg_Init;

void StaticInit_RegisterGameMsgs(void) {
    D_004F5370 = "MSGGAME_INIT";
    D_004F5378 = "MSGGAME_LOAD";
    D_004F5380 = "MSGGAME_STARTLEVEL";
    D_004F5388 = Script_RegisterType("cStartLevelMsg", &ScriptType_cStartLevelMsg_Init, 1, 0);
    D_004F5398 = "MSGGAME_ENDLEVEL";
    D_004F5390 = D_004F5388;
    D_004F53A8 = Script_RegisterType("cEndLevelMsg", &ScriptType_cEndLevelMsg_Init, 1, 0);
    D_004F53B0 = D_004F53A8;
}
