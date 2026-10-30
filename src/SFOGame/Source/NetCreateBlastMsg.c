/*
 * SFOGame/Source/NetCreateBlastMsg: 2 files, 002C6370-002C64D0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002C6370 */
#pragma push /* merge_units */
#include "types.h"

typedef struct Msg2530 {
    void* vtable;
    int a, b, c, d, e, f, g;
    char h;
    char p1[3];
    int i0;
    int i1;
    float x, y, z;
    int i2;
    int i3;
} Msg2530;

typedef struct Pkt {
    char pad[8];
    int i0;
    int i1;
    float x, y, z;
    int i2;
    int i3;
} Pkt;

extern unsigned char D_005723C8;
extern unsigned char D_005721D0;
extern char D_0051EE68[];
extern char D_004DE130[];
extern void cMessage_ctor_cMessageNameR(Msg2530* m, void* type);
extern int nGobjManager_LookupGOBJ_cObjectIdR(int* id);
extern void Blast_Prepare(int obj, int a, float x, float y, float z, int b, int c, int d, int e);
extern void cMessage_dtor(Msg2530* m, int flags);

#pragma opt_propagation off
int cNetCreateBlastMsg_NetCreateBlastMsgCallback(int a0, int a1, int a2, Pkt* pkt) {
    if (!D_005723C8) {
        D_005723C8 = 1;
    }
    if (D_005721D0) {
        Msg2530 m;
        int id[2];
        int obj;
        Pkt* p = pkt;
        cMessage_ctor_cMessageNameR(&m, D_0051EE68);
        m.vtable = D_004DE130;
        m.i0 = p->i0;
        m.i1 = p->i1;
        m.x = p->x;
        m.y = p->y;
        m.z = p->z;
        m.i3 = p->i3;
        m.i2 = p->i2;
        id[0] = m.i0;
        obj = nGobjManager_LookupGOBJ_cObjectIdR(id);
        if (obj) {
            Blast_Prepare(obj, m.i1, m.x, m.y, m.z, m.i3 != 0, 0, m.i2 != 0, 1);
        }
        m.vtable = D_004DE130;
        cMessage_dtor(&m, 0);
    }
    D_005723C8 = 0;
    return 0x24;
}
static inline void merge_flush_func_002C6370(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C6370 */

/* merge_units: begin func_002C64D0 */
#pragma push /* merge_units */
extern int NetRegisterMessageStart(void);
extern int cMessage_RegisterFields(void* f);
extern int NetMessageField(void* f, void* buf, int size, int count);
extern int NetRegisterMessage(void* t, int id, void* fn);
extern int D_0051EE60;
struct Pkt;
extern int cNetCreateBlastMsg_NetCreateBlastMsgCallback(int, int, int, struct Pkt*);
unsigned char cNetCreateBlastMsg_InitNet(void)
{
    struct { long long file; int v[7]; } L;
    unsigned char ok = 0;
    if (NetRegisterMessageStart() == 0 && cMessage_RegisterFields(&L.file) &&
        NetMessageField(&L.file, &L.v[0], 4, 1) == 0 &&
        NetMessageField(&L.file, &L.v[1], 4, 1) == 0 &&
        NetMessageField(&L.file, &L.v[2], 4, 1) == 0 &&
        NetMessageField(&L.file, &L.v[3], 4, 1) == 0 &&
        NetMessageField(&L.file, &L.v[4], 4, 1) == 0 &&
        NetMessageField(&L.file, &L.v[5], 4, 1) == 0 &&
        NetMessageField(&L.file, &L.v[6], 4, 1) == 0 &&
        NetRegisterMessage(&D_0051EE60, 2, cNetCreateBlastMsg_NetCreateBlastMsgCallback) == 0)
        ok = 1;
    return ok;
}
static inline void merge_flush_func_002C64D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002C64D0 */
