#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int cScriptBase_addClass(char *, char *, int, int);            
int cGOBJ_SOBJ_getClassId();                    
int cNetMsg_RegisterMsg(char *, char *, char *);                   
int cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(int, char *, int, char *, int, char *);              
extern char D_004A93B8;
extern char *D_00506210;
extern char D_00506218;
extern int D_00506220;
extern int D_00506228;
extern int D_00506230;
extern int D_00506238;
extern char Script_cBeamMsg_Who;
extern char cBeamMsg_SOBJ_init;
extern char cBeamMsg_NetReceive;

void StaticInit_BeamMsg(void) {
    D_00506210 = "cBeamMsg";
    D_00506220 = cNetMsg_RegisterMsg(&cBeamMsg_NetReceive, &D_00506218, "cBeamMsg");
    D_00506228 = cScriptBase_addClass("cBeamMsg", &cBeamMsg_SOBJ_init, 1, 0);
    D_00506230 = D_00506228;
    D_00506238 = cScriptBase_registerFunc_int_intPintPint_intP_charP_etc(D_00506228, &Script_cBeamMsg_Who, cGOBJ_SOBJ_getClassId(), &D_004A93B8, 1, &D_00506228);
}

