/*
 * Libs/SFOLobby/SFOLobby/SFOLobby_Contact: 3 files, 0044D670-0044D780
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0044D670 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int SFOLobby_GetMillisecs();                                
int SFOLobby_RequestBuddyList(char * , int);                         
int SFOLobby_FindAgent(char * , int, int);                    

int SFOLobby_ContactListContainsAgent(char * arg0, int arg1, int arg2) {
    if (arg2 != 0) {
        SFOLobby_GetMillisecs();
        SFOLobby_RequestBuddyList(arg0, 1);
        F_(arg0, 0x257C, int) = SFOLobby_GetMillisecs();
    }
    if (SFOLobby_FindAgent(arg0 + 0x150, arg1, 0) != 0) {
        return 1;
    }
    return SFOLobby_FindAgent(arg0 + 0xE0, arg1, 0) != 0;
}
static inline void merge_flush_func_0044D670(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044D670 */

/* merge_units: begin func_0044D700 */
#pragma push /* merge_units */
#pragma mpwc_relax on
                       
extern int D_004977B8;

typedef struct { char p0[9596]; int f257C; } PS0_0044D700;
void SFOLobby_ContactUpdateMemberList(PS0_0044D700 *arg0, int arg1) {
    int temp_a0;
    int temp_s0;

    temp_s0 = arg0->f257C;
    temp_a0 = SFOLobby_GetMillisecs() - temp_s0;
    if ((arg1 == 0) && (temp_s0 != 0)) {
        if (D_004977B8 < temp_a0) {
            goto block_4;
        }
    } else {
block_4:
        SFOLobby_RequestBuddyList(arg0, arg1);
        arg0->f257C = SFOLobby_GetMillisecs();
    }
}
static inline void merge_flush_func_0044D700(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044D700 */

/* merge_units: begin func_0044D780 */
#pragma push /* merge_units */
#pragma mpwc_relax on
int Libc_Strcpy(char *, char *);                                
int SFOLobby_GuiCallback(char * , int, int);                      
int SFOLobby_Poll(char * , int, int, int);             
int MediusGetBuddyInvitations(char *, char *);                        
int memset(char *, int, int);                                
extern int D_00497890;
extern char SFOLobby_Callback_GetBuddyInvitations;

typedef struct { char p0[552]; int f228; int f22C; char p230[28]; int f24C; } PS0_0044D780;
void SFOLobby_ContactGetInvites(PS0_0044D780 *arg0) {
    int sp30[8];
    int temp_v0;

    if (arg0->f228 == 0) {
        arg0->f228 = 1;
        memset(sp30, 0, 0x15);
        Libc_Strcpy(sp30, "1");
        arg0->f24C = MediusGetBuddyInvitations(sp30, &SFOLobby_Callback_GetBuddyInvitations);
        if (arg0->f24C == 0) {
            temp_v0 = SFOLobby_GetMillisecs();
            arg0->f22C = 0;
            if (arg0->f22C == 0) {
loop_4:
                SFOLobby_GuiCallback(arg0, 0, 0);
                if (SFOLobby_Poll(arg0, temp_v0, D_00497890, 0) != 0) {
                    if (arg0->f22C != 0) {

                    } else {
                        goto loop_4;
                    }
                }
            }
        }
    }
}
static inline void merge_flush_func_0044D780(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0044D780 */
