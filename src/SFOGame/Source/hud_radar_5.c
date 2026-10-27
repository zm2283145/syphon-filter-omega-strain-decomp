/*
 * SFOGame/Source/hud_radar: 1 file, 002619B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin fireObj_2619B0 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int nHud_CreateHudElement(int, char *);                        
int cInterfaceModel_GetChild(int, char *);                        
int cInterfaceModel_Activate(int, int, int);                         
int viBufGetTs(float, int);                          
extern int D_0048B0D8;
extern char D_004DC930;
extern char D_004DC950;
extern int D_004FFD50;
extern int D_004FFD58;
extern int D_004FFD60;

typedef struct { char p0[4]; int f4; int f8; int fC; int f10; int f14; int f18; } PS0_002619B0;
char * cHudRadar_ctor(PS0_002619B0 *arg0, int arg1) {
    arg0->f4 = (int)(&D_004DC930);
    arg0->f4 = (int)(&D_004DC950);
    arg0->f8 = nHud_CreateHudElement(arg1, "dangermeter");
    arg0->fC = nHud_CreateHudElement(arg1, "environmentalmeter");
    arg0->f10 = nHud_CreateHudElement(arg1, "playermarker");
    arg0->f14 = nHud_CreateHudElement(arg1, "northindicator");
    cInterfaceModel_Activate(arg1, 1, 0);
    cInterfaceModel_Activate(cInterfaceModel_GetChild(arg1, "radar"), 1, 1);
    arg0->f18 = nHud_CreateHudElement(arg1, "selected_waypoint");
    viBufGetTs((float) D_0048B0D8, arg0->f18);
    D_004FFD58 = cInterfaceModel_GetChild(arg1, "radartriangle");
    D_004FFD50 = cInterfaceModel_GetChild(arg1, "radartriangle");
    D_004FFD60 = cInterfaceModel_GetChild(arg1, "radarsquare");
    return arg0;
}
static inline void merge_flush_fireObj_2619B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end fireObj_2619B0 */
