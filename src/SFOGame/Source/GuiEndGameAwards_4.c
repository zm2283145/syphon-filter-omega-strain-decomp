/*
 * SFOGame/Source/GuiEndGameAwards: 2 files, 0045F300-0045F3F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiGameScreen_45F300 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after GuiGameScreen.cc (ends 0x0045F090).
 */

#include "loose05_types.h"

char D_004C2460[] = "GuiAutoSaver"; /* resource name */
extern int Gui_Manager(void);
extern int Gui_Canvas(void);
#if 0 /* merge_units */
extern void GuiCanvas_Transition(int mgr, void* owner, int res);
#endif /* merge_units */
int GuiCanvas_Transition(int, int, int); /* merge_units */
#define GuiCanvas_Transition(a0, a1, a2) ((void)GuiCanvas_Transition((a0), (int)(a1), (a2))) /* merge_units */

extern int GuiManager_Add(int a0, int res);
extern int GuiWidget_onWake(void* self);
extern int AbstractWidgetClassRep_Create(char* name);
extern int GuiSaveAgentWidget_HandleEvent(void* self);

void GuiAutoSaver_SaveDone(void* self) {
    GuiCanvas_Transition(Gui_Canvas(), self, 0);
}

int GuiAutoSaver_Wake(GuiWidget45F340* self) {
    GuiWidget_onWake(self);
    self->unk4C = 2;
    return GuiSaveAgentWidget_HandleEvent(self);
}

/* Looks up the named resource and, if found, registers it for this owner. */
void GuiEndGameAwards_Done(void* self) {
    int res;

    res = AbstractWidgetClassRep_Create(D_004C2460);
    if (res != 0) {
        GuiManager_Add(Gui_Manager(), res);
        GuiCanvas_Transition(Gui_Canvas(), self, res);
    }
}
#undef GuiCanvas_Transition /* merge_units */
static inline void merge_flush_GuiGameScreen_45F300(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiGameScreen_45F300 */

/* merge_units: begin func_0045F3F0 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
#if 0 /* merge_units */
int Gui_Manager();
#endif /* merge_units */
#define Gui_Manager() (Gui_Manager()) /* merge_units */
                                
#if 0 /* merge_units */
int Gui_Canvas();
#endif /* merge_units */
#define Gui_Canvas() (Gui_Canvas()) /* merge_units */
                                
int GuiCanvas_Transition(int, int, int);                     
#if 0 /* merge_units */
int GuiManager_Add(int, int);
#endif /* merge_units */
#define GuiManager_Add(a0, a1) (GuiManager_Add((a0), (a1))) /* merge_units */
                          
#if 0 /* merge_units */
int AbstractWidgetClassRep_Create(char *);
#endif /* merge_units */
#define AbstractWidgetClassRep_Create(a0) (AbstractWidgetClassRep_Create((a0))) /* merge_units */
                             
int GuiEndGameAwards_ActivateNextAward(int);                             
#if 0 /* merge_units */
extern char D_004C2460;
#endif /* merge_units */
#define D_004C2460 (*(char*)&D_004C2460) /* merge_units */


int GuiEndGameAwards_onInput(int arg0, char * arg1) {
    int temp_v0;
    int var_v0;

    var_v0 = F_(arg1, 0x0, unsigned short) == 1;
    if (var_v0 != 0) {
        var_v0 = F_(arg1, 0x2, unsigned short) == 0;
    }
    var_v0 = var_v0 ? F_(arg1, 0x8, unsigned short) == 0x40 : var_v0;
    if (var_v0 != 0) {
        var_v0 = F_(arg1, 0x6, unsigned short) == 0;
    }
    if (var_v0 != 0) {
        if (GuiEndGameAwards_ActivateNextAward(arg0) == 0) {
            temp_v0 = AbstractWidgetClassRep_Create(&D_004C2460);
            if (temp_v0 != 0) {
                GuiManager_Add(Gui_Manager(), temp_v0);
                GuiCanvas_Transition(Gui_Canvas(), arg0, temp_v0);
            }
        }
        return 1;
    }
    return 0;
}
#undef Gui_Manager /* merge_units */
#undef Gui_Canvas /* merge_units */
#undef GuiManager_Add /* merge_units */
#undef AbstractWidgetClassRep_Create /* merge_units */
#undef D_004C2460 /* merge_units */
static inline void merge_flush_func_0045F3F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0045F3F0 */
