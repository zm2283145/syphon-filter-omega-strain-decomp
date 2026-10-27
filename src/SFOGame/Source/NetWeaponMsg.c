/*
 * SFOGame/Source/NetWeaponMsg: 1 file, 00316BB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00316BB0 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int NetRegisterMessage(char *, int, char *);               
int NetRegisterMessageStart();                                
int NetMessageField(char *, char *, int, int);                  
int cMessage_RegisterFields(char *);                             
extern char D_0052ACD0;
extern char cNetWeaponMsg_WeaponMsgCallback;

unsigned char cNetWeaponMsg_InitNet(void) {
    struct { int f20[2]; int f28; int f2C; int f30; int f34[3]; } sl;
    unsigned char var_s0;

    var_s0 = 0;
    if ((NetRegisterMessageStart() == 0) && (cMessage_RegisterFields(sl.f20) != 0) && (NetMessageField(sl.f20, &sl.f30, 1, 1) == 0) && (NetMessageField(sl.f20, sl.f34, 4, 1) == 0) && (NetMessageField(sl.f20, &sl.f28, 1, 1) == 0) && (NetMessageField(sl.f20, &sl.f2C, 4, 1) == 0) && (NetRegisterMessage(&D_0052ACD0, 2, &cNetWeaponMsg_WeaponMsgCallback) == 0)) {
        var_s0 = 1;
    }
    return var_s0;
}
static inline void merge_flush_func_00316BB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00316BB0 */
