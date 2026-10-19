#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int NetMsgTable_Add(char *, char *, char *);                   
extern char *D_004F53F0;
extern char *D_004F53F8;
extern char D_004F5400;
extern int D_004F5408;
extern char *D_004F5410;
extern char D_004F5418;
extern int D_004F5420;
extern char cAtmosphericEffectMsg_NetReceive;
extern char cMaxActiveNpcCountMsg_NetReceive;

void StaticInit_PlayerMsgTypes(void) {
    D_004F53F0 = "MSGGAME_PLAYER_TOGGLE_RIGHT_STICK";
    D_004F53F8 = "cMaxActiveNpcCountMsg";
    D_004F5408 = NetMsgTable_Add(&cMaxActiveNpcCountMsg_NetReceive, &D_004F5400, "cMaxActiveNpcCountMsg");
    D_004F5410 = "cAtmosphericEffectMsg";
    D_004F5420 = NetMsgTable_Add(&cAtmosphericEffectMsg_NetReceive, &D_004F5418, "cAtmosphericEffectMsg");
}
