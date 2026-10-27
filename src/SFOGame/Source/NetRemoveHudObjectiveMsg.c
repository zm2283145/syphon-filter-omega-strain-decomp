/*
 * SFOGame/Source/NetRemoveHudObjectiveMsg: 3 files, 00324000-00324140
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00324000 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int cMessage_ctor_cMessageNameR(char **, char *);                       
int nGobjManager_LookupGOBJ_cObjectIdR(int *);                       
int cMessage_dtor(char **, int);                           
int nHudTargets_RemoveHudObjective(int, int);                            
extern char D_004DE650;
extern char D_0052ACF8;
extern unsigned char D_005721D0;
extern unsigned char D_005723C8;

#pragma push
#pragma opt_common_subs off
int cNetRemoveHudObjectiveMsg_NetRemoveHudObjectiveMsgCallback(int d0, int d1, int d2, char * arg3) {
    struct { char * f20[9]; int f44; int f48[2]; } sl;
    int temp_v0;

    if (D_005723C8 == 0) {
        D_005723C8 = 1;
    }
    if (D_005721D0 != 0) {
        cMessage_ctor_cMessageNameR(sl.f20, &D_0052ACF8);
        sl.f20[0] = &D_004DE650;
        { int *p = &sl.f44; *p = F_(arg3, 0x8, int); sl.f48[0] = *p; }
        temp_v0 = nGobjManager_LookupGOBJ_cObjectIdR(sl.f48);
        if (temp_v0 != 0) {
            nHudTargets_RemoveHudObjective(temp_v0, 1);
        }
        sl.f20[0] = &D_004DE650;
        cMessage_dtor(sl.f20, 0);
    }
    D_005723C8 = 0;
    return 0xC;
}

#pragma pop
static inline void merge_flush_func_00324000(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00324000 */

/* merge_units: begin func_003240C0 */
#pragma push /* merge_units */
extern int NetRegisterMessageStart(void);
extern int cMessage_RegisterFields(void* p);
extern int NetMessageField(void* a, void* b, int c, int d);
extern int NetRegisterMessage(void* t, int id, void* fn);
extern int D_0052ACF0;
extern int cNetRemoveHudObjectiveMsg_NetRemoveHudObjectiveMsgCallback();
unsigned char cNetRemoveHudObjectiveMsg_InitNet(void) {
    int ok[2];
    int buf[2];
    unsigned char r = 0;
    if (NetRegisterMessageStart() == 0 && cMessage_RegisterFields(buf) != 0 && NetMessageField(buf, ok, 4, 1) == 0 &&
        NetRegisterMessage(&D_0052ACF0, 2, cNetRemoveHudObjectiveMsg_NetRemoveHudObjectiveMsgCallback) == 0) {
        r = 1;
    }
    return r;
}
static inline void merge_flush_func_003240C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003240C0 */

/* merge_units: begin func_00324140 */
#pragma push /* merge_units */
typedef struct { int pad[3]; int id; } AIDeadSrc;
typedef struct { int pad[7]; int size; int pad2; AIDeadSrc* src; } AIDeadMsg;
extern void Event_PackHeader(AIDeadMsg* self, int a1, int* type, int a3, int t0, unsigned int len, int* buf);
int cNetRemoveHudObjectiveMsg_Pack(AIDeadMsg* self, int a1, int* type, int a3, int t0, unsigned int len, int* buf) {
    int r = -1;
    if (len >= 0xC && buf != 0) {
        Event_PackHeader(self, a1, type, a3, t0, len, buf);
        buf[2] = (int)self->src;
        self->size = 0x40;
        if (type != 0) {
            r = 0xC;
            *type = D_0052ACF0;
        }
    }
    return r;
}
static inline void merge_flush_func_00324140(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00324140 */
