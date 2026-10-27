/*
 * SFOGame/Source/human: 1 file, 00184F90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00184F90 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { void* vt; char pad[0x20]; unsigned char on; char pad25[3]; float a; float b; } Msg_4F90;
void cMessage_ctor_cMessageNameR(Msg_4F90*, void*);
void cNetMsg_GetChar(unsigned char*);
void cNetMsg_GetFloat_floatR(float*);
int cHuman_SubclassId(void);
int cGOBJ_CheckSubclassID(void*, int);
void cHuman_Shock(void*, unsigned char, float, float, int);
void cMessage_dtor(Msg_4F90*, int);
extern char D_004EF078[];
extern char D_004DA9F0[];
extern char D_004DCF10[];
/* net handler: shock the target to death when it accepts the request */
void Actor_OnShockMessage(void* target)
{
    Msg_4F90 m;
    cMessage_ctor_cMessageNameR(&m, D_004EF078);
    m.vt = D_004DA9F0;
    cNetMsg_GetChar(&m.on);
    cNetMsg_GetFloat_floatR(&m.a);
    cNetMsg_GetFloat_floatR(&m.b);
    if (target && cGOBJ_CheckSubclassID(target, cHuman_SubclassId())) cHuman_Shock(target, m.on, m.a, m.b, 0);
    m.vt = D_004DCF10;
    cMessage_dtor(&m, 0);
}
static inline void merge_flush_func_00184F90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00184F90 */
