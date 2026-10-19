#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int Script_RegisterType(char *, char *, int, int);            
int cGOBJ_GetScriptTypeKeyPtr();                    
int NetMsgTable_Add(char *, char *, char *);                   
int Script_RegisterNative(int, char *, int, char *, int, char *);              
extern char D_004A93B8;
extern char *D_00506210;
extern char D_00506218;
extern int D_00506220;
extern int D_00506228;
extern int D_00506230;
extern int D_00506238;
extern char Script_cBeamMsg_Who;
extern char ScriptType_cBeamMsg_Init;
extern char cBeamMsg_NetReceive;

void StaticInit_RegisterBeamMsg(void) {
    D_00506210 = "cBeamMsg";
    D_00506220 = NetMsgTable_Add(&cBeamMsg_NetReceive, &D_00506218, "cBeamMsg");
    D_00506228 = Script_RegisterType("cBeamMsg", &ScriptType_cBeamMsg_Init, 1, 0);
    D_00506230 = D_00506228;
    D_00506238 = Script_RegisterNative(D_00506228, &Script_cBeamMsg_Who, cGOBJ_GetScriptTypeKeyPtr(), &D_004A93B8, 1, &D_00506228);
}

