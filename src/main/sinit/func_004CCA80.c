#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int func_002824D0(char *, char *, char *);                   
extern char *D_004F53F0;
extern char *D_004F53F8;
extern char D_004F5400;
extern int D_004F5408;
extern char *D_004F5410;
extern char D_004F5418;
extern int D_004F5420;
extern char func_0020FFD0;
extern char func_002101D0;

void func_004CCA80(void) {
    D_004F53F0 = "MSGGAME_PLAYER_TOGGLE_RIGHT_STICK";
    D_004F53F8 = "cMaxActiveNpcCountMsg";
    D_004F5408 = func_002824D0(&func_002101D0, &D_004F5400, "cMaxActiveNpcCountMsg");
    D_004F5410 = "cAtmosphericEffectMsg";
    D_004F5420 = func_002824D0(&func_0020FFD0, &D_004F5418, "cAtmosphericEffectMsg");
}
