/*
 * SFOGame/Source/NetGeneratorDelete: 3 files, 002D15C0-002D1790
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D15C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void* cMemMan_Allocate(int pool, int size, char* file, int line);
extern char D_004DFD80[];
extern char D_004DE260[];
}
union V4_E100 { struct { float x, y, z, w; } f; struct { char c[16]; } s; };
struct Msg2530 { void* vtable; int a, b, c, d, e, f, g; char h; char p1[3]; V4_E100 v; };
extern "C" Msg2530* cNetGeneratorDeleteMsg_Clone(Msg2530* src)
{
    Msg2530* p;
    {
        AllocGuard guard;
        p = (Msg2530*)cMemMan_Allocate(0, 0x34, "NetGeneratorDelete.hh", 0x1A);
    }
    if (p) {
        p->vtable = D_004DFD80;
        p->a = src->a;
        p->b = src->b;
        p->c = src->c;
        p->d = src->d;
        p->e = src->e;
        p->f = src->f;
        p->g = src->g;
        p->h = src->h;
        p->vtable = D_004DE260;
        p->v = src->v;
    }
    return p;
}
static inline void merge_flush_func_002D15C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D15C0 */

/* merge_units: begin func_002D16E0 */
#pragma push /* merge_units */
extern int NetRegisterMessageStart(void);
extern int cMessage_RegisterFields(void* f);
extern int NetMessageField(void* f, void* buf, int size, int count);
extern int NetRegisterMessage(void* t, int id, void* fn);
extern char D_0051F070[];
extern void cNetGeneratorDeleteMsg_GeneratorDeleteCallback(void);
unsigned char cNetGeneratorDeleteMsg_InitNet(void)
{
    struct { long long file; int a; int b; } L;
    int err;
    unsigned char ok;
    ok = 0;
    err = NetRegisterMessageStart();
    if (err == 0 && cMessage_RegisterFields(&L.file) && err == 0 &&
        NetMessageField(&L.file, &L.a, 4, 1) == 0 &&
        NetMessageField(&L.file, &L.b, 4, 1) == 0 &&
        NetRegisterMessage(D_0051F070, 2, cNetGeneratorDeleteMsg_GeneratorDeleteCallback) == 0)
        ok = 1;
    return ok;
}
static inline void merge_flush_func_002D16E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D16E0 */

/* merge_units: begin func_002D1790 */
#pragma push /* merge_units */
typedef struct { char pad[0x2C]; int a; int b; } Ev1790;
typedef struct { char pad[8]; int a; int b; } Buf1790;
#if 0 /* merge_units */
extern int D_0051F070;
#endif /* merge_units */
#define D_0051F070 (*(int*)&D_0051F070) /* merge_units */

extern void Event_PackHeader(Ev1790* e, int a1, int* type, int a3, int a4, unsigned int size, void* buf);
int cNetGeneratorDeleteMsg_Pack(Ev1790* e, int a1, int* type, int a3, int a4, unsigned int size, void* buf)
{
    int r = -1;
    if (size >= 0x10 && buf) {
        Buf1790* b = (Buf1790*)buf;
        Event_PackHeader(e, a1, type, a3, a4, size, buf);
        b->a = e->a;
        b->b = e->b;
        if (type) {
            r = 0x10;
            *type = D_0051F070;
        }
    }
    return r;
}
#undef D_0051F070 /* merge_units */
static inline void merge_flush_func_002D1790(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002D1790 */
