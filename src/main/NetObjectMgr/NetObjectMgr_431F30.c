/*
 * main/NetObjectMgr: range (4 files, 00431F30-00432150)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#pragma push
#pragma cplusplus on
#include "msg_clone.h"
#pragma pop
#include "types.h"
#include "NetObjectMgr_types.h"

/* merge_units: begin func_00431F30 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" char D_004E0F20[];
extern "C" char D_004DFD80[];
MSG_CLONE_BEGIN(cNetTransferMsg_v01, 0x2C, "NetTransferMsg.hh", 0x19)
    p->vt = D_004DFD80;
    F(int, 0x4) = S(int, 0x4);
    F(int, 0x8) = S(int, 0x8);
    F(int, 0xC) = S(int, 0xC);
    F(int, 0x10) = S(int, 0x10);
    F(int, 0x14) = S(int, 0x14);
    F(int, 0x18) = S(int, 0x18);
    F(int, 0x1C) = S(int, 0x1C);
    F(char, 0x20) = S(char, 0x20);
    p->vt = D_004E0F20;
    F(int, 0x24) = S(int, 0x24);
    F(short, 0x28) = S(short, 0x28);
MSG_CLONE_END
#pragma pop /* merge_units */
/* merge_units: end func_00431F30 */

/* merge_units: begin func_00432040 */
#pragma push /* merge_units */
int cNetTransferMsg_NetReceive(int unused0, int unused1, int unused2, const NetObjectUpdate* update); /* gsynth: defined below */extern int NetRegisterMessageStart(void);
extern int Event_UnpackHeader(void* p);
extern int NetMessageField(void* a, void* b, int c, int d);
extern int NetMsg_RegisterType(void* t, int id, void* fn);
extern int D_00582768;
extern int cNetTransferMsg_NetReceive();
unsigned char cNetTransferMsg_NetRegister(void) {
    int buf[2];
    int b[1];
    int a[1];
    int busy;
    unsigned char r = 0;
    busy = NetRegisterMessageStart();
    if (!busy && Event_UnpackHeader(buf) && !busy && NetMessageField(buf, a, 4, 1) == 0 &&
        NetMessageField(buf, b, 2, 1) == 0 && NetMsg_RegisterType(&D_00582768, 2, cNetTransferMsg_NetReceive) == 0) {
        r = 1;
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00432040(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00432040 */

/* merge_units: begin func_004320F0 */
#pragma push /* merge_units */
extern volatile unsigned char D_005723C8;
extern unsigned char D_005721D0;
extern void cNetObjectMgr_TransferRequest(const GobjId* id, int value);

/* Forward a received object update while the network session is active. */
int cNetTransferMsg_NetReceive(int unused0, int unused1, int unused2, const NetObjectUpdate* update)
{
    GobjId staged[2];
    if (!D_005723C8)
        D_005723C8 = 1;
    if (D_005721D0) {
        staged[0].word = update->id.word;
        cNetObjectMgr_TransferRequest(staged, update->value);
    }
    D_005723C8 = 0;
    return 16;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004320F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004320F0 */

/* merge_units: begin func_00432150 */
#pragma push /* merge_units */
typedef struct { char pad[0x24]; int a; short b; } Ev1790;
typedef struct { char pad[8]; int a; short b; } Buf1790;
extern void Event_PackHeader(Ev1790* e, int a1, int* type, int a3, int a4, unsigned int size, void* buf);
int cNetTransferMsg_v02(Ev1790* e, int a1, int* type, int a3, int a4, unsigned int size, void* buf)
{
    int r = -1;
    if (size >= 0x10 && buf) {
        Buf1790* b = (Buf1790*)buf;
        Event_PackHeader(e, a1, type, a3, a4, size, buf);
        b->a = e->a;
        b->b = e->b;
        if (type) {
            r = 0x10;
            *type = D_00582768;
        }
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00432150(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00432150 */
