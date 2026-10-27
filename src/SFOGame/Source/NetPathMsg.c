/*
 * SFOGame/Source/NetPathMsg: 2 files, 002D78C0-002D79A0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D78C0 */
#pragma push /* merge_units */
#include "types.h"
/* Loads the saved id pair and position, then registers the net message type. */
typedef struct { float x, y, z; } Vec2D78C0;
typedef struct { int a, b; } Ids2D78C0;
extern int NetRegisterMessageStart(void);
extern int cMessage_RegisterFields(void* f);
extern int NetMessageField(void* f, void* buf, int size, int count);
extern int NetRegisterMessage(void* t, int id, void* fn);
extern char D_0051F0C8[];
extern void cNetPathMsg_PathCallback(void);
static inline void IInit2D78C0(Ids2D78C0* i) { i->a = -1; i->b = -1; }
unsigned char cNetPathMsg_InitNet(void)
{
    struct { long long file; Ids2D78C0 ids; int pad; Vec2D78C0 v; } L;
    int err;
    unsigned char ok;
    Vec2D78C0* p;
    ok = 0;
    p = &L.v;
    p->x = -1.0f; L.v.y = -1.0f; L.v.z = -1.0f;
    IInit2D78C0((Ids2D78C0*)((char*)&L + 8));
    err = NetRegisterMessageStart();
    if (err == 0 && cMessage_RegisterFields(&L.file) && err == 0 &&
        NetMessageField(&L.file, p, 12, 1) == 0 &&
        NetMessageField(&L.file, &L.ids, 4, 2) == 0 &&
        NetRegisterMessage(D_0051F0C8, 2, cNetPathMsg_PathCallback) == 0)
        ok = 1;
    return ok;
}
static inline void merge_flush_func_002D78C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D78C0 */

/* merge_units: begin func_002D79A0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose02_types.h"

/* Writes the object's position as a homogeneous vector (w = 1). */
void cNetPathMsg_GetDestination(PosObj38* self, Vec4* out) {
    float x;
    float y;
    float z;

    x = self->x;
    out->x = x;
    y = self->y;
    out->y = y;
    z = self->z;
    out->z = z;
    out->w = 1.0f;
}
static inline void merge_flush_func_002D79A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D79A0 */
