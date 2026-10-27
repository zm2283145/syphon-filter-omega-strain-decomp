/*
 * SFOGame/Source/GameGOBJ: 1 file, 00210940
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00210940 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int QueueMessage_cMessageR_cSystemP_int(char **, char *, int);                         
int cPlaySoundMsg_ctor_cSndFxR(char **, char * , char * );  
int cMessage_dtor(char **, int);                           
int cFileMan_dtor(char *, int);                            
extern char D_004DAE30;
extern char g_Game;
extern char func_001C6700;

#pragma opt_common_subs off
int Script_cSoundGOBJ_Trigger(void **arg0) {
    struct { char * f10[8]; signed char f30[88]; int f88[39]; int f124[43]; } sl;
    char * temp_v1;
    char * var_a2;

    temp_v1 = *arg0;
    var_a2 = (F_(temp_v1, 0x1F2, unsigned char) != 0) ? temp_v1 : NULL;
    if (F_(temp_v1, 0x1F0, unsigned char) == 0) {
        F_(temp_v1, 0x1F0, unsigned char) = 1U;
        cPlaySoundMsg_ctor_cSndFxR(sl.f10, temp_v1 + 0x60, var_a2);
        if (&func_001C6700 == NULL) {
            sl.f30[0] = 1;
        }
        QueueMessage_cMessageR_cSystemP_int(sl.f10, &g_Game, 1);
        sl.f10[0] = &D_004DAE30;
        cFileMan_dtor(sl.f124, -1);
        cFileMan_dtor(sl.f88, -1);
        cMessage_dtor(sl.f10, 0);
    }
    return 0;
}
static inline void merge_flush_func_00210940(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00210940 */
