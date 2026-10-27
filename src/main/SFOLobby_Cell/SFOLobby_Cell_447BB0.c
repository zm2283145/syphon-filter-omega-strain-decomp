/*
 * main/SFOLobby_Cell: 3 files, 00447BB0-00447D70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00447BB0 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int atoi(char * );                          
int SFOLobbyList_Append(int, int *);                        
int SFOLobby_IgnoreCallbacks();                                
int memset(int *, int, int);                              
int strncpy(char *, char * , int);                          
extern char * D_00585E60;

void SFOLobby_Callback_ChatTextFilter(int d0, int d1, int d2, char * arg3) {
    struct { int f40; int f44[8]; int f64[16]; signed char fA4[12]; } sl;
    int temp_s0;
    int temp_a0;
    int temp_s2;

    if (SFOLobby_IgnoreCallbacks() == 0) {
        temp_s0 = F_(D_00585E60, 0x23EC, int);
        if ((temp_s0 != 0) && ((temp_a0 = F_(arg3, 0x58, int), (temp_a0 == 0)) || (temp_a0 == 4))) {
            temp_s2 = atoi(arg3);
            memset(&sl.f40, 0, 0x68);
            sl.fA4[0] = temp_s2 != 0;
            sl.f40 = temp_s2;
            strncpy(sl.f44, D_00585E60 + 0x243D, 0x1F);
            strncpy(sl.f64, arg3 + 0x15, 0x3F);
            SFOLobbyList_Append(temp_s0, &sl.f40);
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00447BB0 */

/* merge_units: begin func_00447C70 */
#pragma push /* merge_units */
#pragma mpwc_relax on
/*fc*/
int Libc_Strcpy();                         
int SFOLobbyList_Append();                                
int memset();

#pragma push
#pragma opt_common_subs off
void SFOLobby_Callback_LobbyChat(int d0, int d1, int d2, char * arg3) {
    struct { int f30; int f34[8]; int f54[16]; signed char f94[12]; int fA0[2]; int fA8; int fAC[8]; int fCC[33]; } sl;
    char * temp_s1;

    if (SFOLobby_IgnoreCallbacks() == 0) {
        temp_s1 = (char *)(F_(D_00585E60, 0x23EC, int));
        if (temp_s1 == NULL) {
            if (F_(arg3, 0x3C, int) == 1) {
                memset(sl.fA0, 0, 0xAC);
                sl.fA0[0] = 9;
                sl.fA8 = F_(arg3, 0x18, int);
                Libc_Strcpy(sl.fAC, arg3 + 0x1C);
                Libc_Strcpy(sl.fCC, arg3 + 0x40);
                SFOLobbyList_Append(D_00585E60 + 0x1C, sl.fA0);
            }
            return;
        }
        memset(&sl.f30, 0, 0x68);
        sl.f30 = F_(arg3, 0x18, int);
        Libc_Strcpy(sl.f34, arg3 + 0x1C);
        Libc_Strcpy(sl.f54, arg3 + 0x40);
        sl.f94[0] = F_(arg3, 0x3C, int) == 1;
        SFOLobbyList_Append(temp_s1, &sl.f30);
    }
}
#pragma pop
#pragma pop /* merge_units */
/* merge_units: end func_00447C70 */

/* merge_units: begin func_00447D70 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Not inside a known source-file range: after SFOLobby_Callback.cc (ends 0x004475E0),
 * before SFOLobby_Cell.cc (starts 0x00447D90).
 */


void SFOLobby_Callback_RemoteClientDisconnect(void) {
}

void SFOLobby_Callback_RemoteClientConnect(void) {
}
#pragma pop /* merge_units */
/* merge_units: end func_00447D70 */
