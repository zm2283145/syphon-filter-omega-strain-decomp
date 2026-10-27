/*
 * Libs/SFOLib/Source/GenInfoObject: 4 files, 0043A810-0043AA30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0043A810 */
#pragma push /* merge_units */
#include "NetObjectMgr_types.h"

extern void* D_00497578;
extern unsigned char D_00583890;
extern int D_005721A8;
extern unsigned char g_IsMultiplayer;
extern int D_00494178;
extern int NetGetObject(NetSessionEntry** entry, void* key);
extern int NetGetMyClientIndex(int* id, int session);
extern int NetReleaseObjectPrivateOwnership(void* key);

/* Process a pending session request only when its peer ID matches. */
void cGenInfoObject_ReleasePrivate(void)
{
    NetSessionEntry* entry;
    NetGetObject(&entry, D_00497578);
    if (D_00583890) {
        int session = D_005721A8;
        int peer;
        if (g_IsMultiplayer) {
            if (D_00494178 == -1)
                NetGetMyClientIndex(&D_00494178, session);
            peer = D_00494178;
        } else {
            peer = 0;
        }
        if (entry->id == peer)
            NetReleaseObjectPrivateOwnership(D_00497578);
    }
    D_00583890 = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0043A810(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0043A810 */

/* merge_units: begin func_0043A8B0 */
#pragma push /* merge_units */
extern unsigned int D_00583910;
extern int D_005838B8;
extern int D_005838D8;
extern int D_00583900;
extern unsigned char D_005838A0[4];

extern unsigned int cDME_GetTime(int synchronized);
extern int NetRequestObjectPrivateOwnership(void* key);
extern void func_00439390(int peer, void* key, int event);

static inline int current_peer(void)
{
    int session = D_005721A8;
    if (g_IsMultiplayer) {
        if (D_00494178 == -1)
            NetGetMyClientIndex(&D_00494178, session);
        return D_00494178;
    }
    return 0;
}

/* Poll pending session changes at 500-tick intervals. */
void func_0043A8B0(void)
{
    if (D_00583910 < cDME_GetTime(1)) {
        if (D_005838B8 || D_005838D8 || D_00583900 ||
            D_005838A0[0] || D_005838A0[1] ||
            D_005838A0[2] || D_005838A0[3]) {
            NetSessionEntry* entry;
            int peer;
            NetGetObject(&entry, D_00497578);
            peer = current_peer();
            if (entry->id != peer) {
                NetRequestObjectPrivateOwnership(D_00497578);
            } else {
                peer = current_peer();
                func_00439390(peer, D_00497578, -2);
            }
        }
        D_00583910 = cDME_GetTime(1) + 500;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0043A8B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0043A8B0 */

/* merge_units: begin func_0043AA30 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern void func_0043A8B0(void);

void func_0043AA30(void) {
    func_0043A8B0();
}
static inline void merge_flush_func_0043AA30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043AA30 */

/* merge_units: begin func_0043AA40 */
#pragma push /* merge_units */
typedef struct { int id; unsigned char flags; char pad[3]; } E43AA40;
extern E43AA40 *D_00583888;
int NetGetMyClientIndex(int *, int);
static inline int Get43AA40(int a) {
    if (g_IsMultiplayer != 0) {
        if (D_00494178 == -1) {
            NetGetMyClientIndex(&D_00494178, a);
        }
        return D_00494178;
    }
    return 0;
}
int cGenInfoObject_IsOwner(int d0, int *arg1) {
    E43AA40 *e;
    E43AA40 *t = D_00583888;
    int key = *arg1;
    int v;
    if (t != 0) {
        int i = 0;
        E43AA40 *p = t;
        do {
            if (key == p->id) { e = &t[i]; goto found; }
            i++;
            p++;
        } while (i != 0x37);
    }
    e = 0;
found:
    if (e != 0) {
        v = Get43AA40(D_005721A8);
        return (e->flags & 0xF) == v;
    }
    return 0;
}
static inline void merge_flush_func_0043AA40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0043AA40 */
