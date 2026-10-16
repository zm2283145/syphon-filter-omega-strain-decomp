#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int Hud_FindOrCreateElement(int, char *);                        
int func_003EEB30(int, char *);                        
int func_003EEBE0(int, int, int);                         
int func_003F45A0(float, int);                          
extern int D_0048B0D8;
extern char D_004DC930;
extern char D_004DC950;
extern int D_004FFD50;
extern int D_004FFD58;
extern int D_004FFD60;

typedef struct { char p0[4]; int f4; int f8; int fC; int f10; int f14; int f18; } PS0_002619B0;
char * HudRadar_ctor(PS0_002619B0 *arg0, int arg1) {
    arg0->f4 = (int)(&D_004DC930);
    arg0->f4 = (int)(&D_004DC950);
    arg0->f8 = Hud_FindOrCreateElement(arg1, "dangermeter");
    arg0->fC = Hud_FindOrCreateElement(arg1, "environmentalmeter");
    arg0->f10 = Hud_FindOrCreateElement(arg1, "playermarker");
    arg0->f14 = Hud_FindOrCreateElement(arg1, "northindicator");
    func_003EEBE0(arg1, 1, 0);
    func_003EEBE0(func_003EEB30(arg1, "radar"), 1, 1);
    arg0->f18 = Hud_FindOrCreateElement(arg1, "selected_waypoint");
    func_003F45A0((float) D_0048B0D8, arg0->f18);
    D_004FFD58 = func_003EEB30(arg1, "radartriangle");
    D_004FFD50 = func_003EEB30(arg1, "radartriangle");
    D_004FFD60 = func_003EEB30(arg1, "radarsquare");
    return arg0;
}
