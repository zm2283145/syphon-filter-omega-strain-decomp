/*
 * SFOGame/Source/GuiStartMenu: 2 files, 004545A0-00454630
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin message_4545A0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "message_two_member_dtor.h"

/* Message destructor: payload members, then cMessage base. */
DEFINE_MESSAGE_TWO_MEMBER_DTOR(func_004545A0, D_004DADF0)
static inline void merge_flush_message_4545A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end message_4545A0 */

/* merge_units: begin message_454630 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int QueueMessage_cMessageR_cSystemP_int();                         
int cStopSoundMsg_ctor_cSndFxR_bool();                    
#if 0 /* merge_units */
int cMessage_dtor();
#endif /* merge_units */
                           
#if 0 /* merge_units */
int cFileMan_dtor();
#endif /* merge_units */
                            
int GuiSubTitleDisplay_Clear();                               
#if 0 /* merge_units */
extern char D_004DADF0;
#endif /* merge_units */
#define D_004DADF0 (*(char*)&D_004DADF0) /* merge_units */

extern char g_Game;

void GuiRadioLog_StopPlayback(char * arg0) {
    struct { char * f20[8]; signed char f40[88]; int f98[39]; int f134[47]; } sl;
    int temp_a0;

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
#undef D_004DADF0 /* merge_units */
static inline void merge_flush_message_454630(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end message_454630 */
