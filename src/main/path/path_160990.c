/*
 * main/path: range (3 files, 00160990-00160C40)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "v4_asm_copy.h"
#include "vc_copy.h"

/* merge_units: begin func_00160990 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } D2_Vec4;
typedef struct { char pad[0x4C]; void* target; } D2_Obj990;
extern void* NpcPath_GetNode(void* t);
extern int Node_GetTranslation(D2_Vec4* out, void* node);
extern unsigned char NpcPath_SetSegmentToPoint(D2_Obj990* o, D2_Vec4* pos, void* t);
unsigned char NpcPath_SetSegment(D2_Obj990* o, void* t) {
    unsigned char r = 0;
    D2_Vec4 pos;
    if (t != o->target) {
        Node_GetTranslation(&pos, NpcPath_GetNode(t));
        r = NpcPath_SetSegmentToPoint(o, &pos, t);
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00160990(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00160990 */

/* merge_units: begin func_00160A00 */
#pragma push /* merge_units */
void NpcPath_HoldNode(char* arg0, int arg1); /* gsynth: defined below */
#pragma cplusplus on
struct RsActor { char pad[0x58]; RsActor* owner; };
struct RsRoute { char pad[0x10]; int last; char pad14[0xC]; int* segs; };
struct RsPath { char pad[0x48]; int count; int hold; int ev; char pad54[0x70 - 0x54]; RsActor* actor; RsRoute* route; };
struct RsMsg { void* vt; char pad[0x20]; unsigned char kind; char pad25[3]; int id; char pad2c[4]; };
extern "C" {
extern char D_004ED9B8[];
extern char D_004D9760[];
void Event_Construct(RsMsg* m, void* type);
void Event_Send(RsMsg* m, RsActor* to, int flags);
void cMessage_dtor(RsMsg* m, int flags);
#if 0 /* merge_units */
unsigned char NpcPath_SetSegment(RsPath* p, int seg);
#endif /* merge_units */
#define NpcPath_SetSegment(a0, a1) (NpcPath_SetSegment((D2_Obj990 *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
unsigned char NpcPath_SetSegmentToPoint(RsPath* p, RsRoute* r, int pt);
#endif /* merge_units */
#define NpcPath_SetSegmentToPoint(a0, a1, a2) (NpcPath_SetSegmentToPoint((D2_Obj990 *)(a0), (D2_Vec4 *)(a1), (void *)(a2))) /* merge_units */

#if 0 /* merge_units */
void NpcPath_HoldNode(RsPath* p, int node);
#endif /* merge_units */
#define NpcPath_HoldNode(a0, a1) (NpcPath_HoldNode((char *)(a0), (a1))) /* merge_units */

}
static inline RsActor* Root(RsActor* a) { RsActor* o = a->owner; return o == 0 ? a : o; }
static inline void Notify(RsPath* p, unsigned char kind, int id)
{
    RsMsg m;
    Event_Construct(&m, D_004ED9B8);
    m.vt = D_004D9760;
    m.kind = kind;
    m.id = id;
    Event_Send(&m, Root(p->actor), 0);
    m.vt = D_004D9760;
    cMessage_dtor(&m, 0);
}
extern "C" unsigned char NpcRoute_Step(RsPath* p)
{
    unsigned char r = 0;
    while (p->count > 0 && !r) {
        int ev = p->ev;
        if (ev >= 0)
            Notify(p, 5, ev);
        p->count--;
        r = NpcPath_SetSegment(p, p->route->segs[p->count]);
    }
    if (!r) {
        int ev = p->ev;
        if (ev >= 0 && ev != p->route->last)
            Notify(p, 5, ev);
        if (p->count >= 0) {
            p->count--;
            RsRoute* rt = p->route;
            int last = rt->last;
            if (last < 0)
                r = NpcPath_SetSegmentToPoint(p, rt, -1);
            else
                r = NpcPath_SetSegment(p, last);
        }
    }
    if (!r) {
        NpcPath_HoldNode(p, p->route->last);
        Notify(p, 6, p->hold);
    }
    return r;
}
#undef NpcPath_SetSegment /* merge_units */
#undef NpcPath_SetSegmentToPoint /* merge_units */
#undef NpcPath_HoldNode /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00160A00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00160A00 */

/* merge_units: begin func_00160C40 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
typedef __int128 Q128;
#pragma mpwc_relax on
#if 0 /* merge_units */
int Node_GetTranslation(Q128 *, char * );
#endif /* merge_units */
#define Node_GetTranslation(a0, a1) (Node_GetTranslation((void *)(a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
char * NpcPath_GetNode(int);
#endif /* merge_units */
#define NpcPath_GetNode(a0) ((char *)NpcPath_GetNode((void *)(a0))) /* merge_units */


void NpcPath_HoldNode(char * arg0, int arg1) {
    Q128 sp30;
    int temp_a0;
    int temp_v1;
    char * temp_v0;

    F_(arg0, 0x4C, int) = arg1;
    temp_a0 = F_(arg0, 0x4C, int);
    if (temp_a0 >= 0) {
        temp_v0 = NpcPath_GetNode(temp_a0);
        Node_GetTranslation(&sp30, temp_v0);
        { Q128* d = &F_(arg0, 0x20, Q128); V4Copy(d, &sp30); }
        temp_v1 = F_(temp_v0, 0x7C, int);
        if (temp_v1 >= 0) {
            F_(arg0, 0x5C, int) = temp_v1;
        }
        F_(arg0, 0x60, unsigned char) = (unsigned char) ((F_(arg0, 0x60, unsigned char) & ~2) | (((F_(temp_v0, 0x64, int) & 8) != 0) * 2));
    }
}
#undef Node_GetTranslation /* merge_units */
#undef NpcPath_GetNode /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00160C40(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00160C40 */
