/*
 * SFOGame/Source/GuiStartMenu: 1 file, 00454880
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin message_454880 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int QueueMessage_cMessageR_cSystemP_int();                         
int cStopSoundMsg_ctor_cSndFxR_bool();                    
int cMessage_dtor();                           
int cFileMan_dtor();                            
int GuiWidget_onDeactivate();                                  
int GuiSubTitleDisplay_Clear();                               
extern char D_004DADF0;
extern char g_Game;

void GuiRadioLog_onDeactivate(char * arg0) {
    struct { char * f20[8]; signed char f40[88]; int f98[39]; int f134[47]; } sl;
    int temp_a0;

    GuiWidget_onDeactivate();
    cStopSoundMsg_ctor_cSndFxR_bool(sl.f20, arg0 + 0x50, 0);
    sl.f40[0] = 1;
    QueueMessage_cMessageR_cSystemP_int(sl.f20, &g_Game, 1);
    temp_a0 = F_(arg0, 0x4C, int);
    if (temp_a0 != 0) {
        GuiSubTitleDisplay_Clear(temp_a0);
    }
    sl.f20[0] = &D_004DADF0;
    cFileMan_dtor(sl.f134, -1);
    cFileMan_dtor(sl.f98, -1);
    cMessage_dtor(sl.f20, 0);
}
static inline void merge_flush_message_454880(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end message_454880 */
