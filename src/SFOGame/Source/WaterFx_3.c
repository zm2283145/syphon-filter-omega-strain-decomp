/*
 * SFOGame/Source/WaterFx: 2 files, 002B2280-002B2330
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002B2280 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct WObj_2280 { char pad[0xC]; int serial; };
struct WRef_2280 { WObj_2280* obj; int serial; };
struct WMgr_2280 { char pad[0x400]; WRef_2280* refs[20]; };
static inline bool V_2280(WRef_2280* h) { bool isNull = !h->obj; return isNull || h->obj->serial == h->serial; }
static inline WObj_2280* G1_2280(WRef_2280* h) { return V_2280(h) ? h->obj : 0; }
extern "C" int cWaterFx_FindBodyIdx(WMgr_2280* m, WObj_2280* target)
{
    int res = -1;
    int i;
    if (target != 0) {
        for (i = 0; i < 20; i++) {
            WRef_2280* r = m->refs[i];
            if (r != 0 && G1_2280(r) != 0 && G1_2280(r) == target) { res = i; break; }
        }
    }
    return res;
}
static inline void merge_flush_func_002B2280(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002B2280 */

/* merge_units: begin func_002B2330 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct SoundRequest {
    char pad000[0x48];
    char partA[0x9C];   /* 0x048 */
    char partB[0xAC];   /* 0x0E4 */
} SoundRequest; /* size 0x190 */
typedef struct EffectMsg {
    void* vtbl;
    char pad004[0x1C];
    unsigned char flag; /* 0x20 */
    char pad021[0x57];
    char partA[0x9C];   /* 0x078 */
    char partB[0xAC];   /* 0x114 */
} EffectMsg; /* size 0x1C0 */
struct WObj_2330 { char pad[0xC]; int serial; };
struct WRef_2330 { WObj_2330* obj; int serial; };
struct WMgr_2330 { char pad[0x400]; WRef_2330* refs[20]; char pad450[4]; int count; };
extern "C" {
extern char D_004ABFB0[];
extern char g_Game[];
extern char D_004DAE30[];
void cSndFx_ctor_int_charP_cGOBJP_int(SoundRequest* req, int kind, char* name, WObj_2330* a, int b);
void EffectMsg_WrapRequest(EffectMsg* msg, SoundRequest* req);
void QueueMessage_cMessageR_cSystemP_int(EffectMsg* msg, void* target, int flags);
void cFileMan_dtor(void* part, int flags);
void cMessage_dtor(EffectMsg* msg, int flags);
void cWaterFx_RemoveBody(WMgr_2330* m, WObj_2330* target);
}
static inline bool V_2330(WRef_2330* h) { bool isNull = !h->obj; return isNull || h->obj->serial == h->serial; }
static inline WObj_2330* G1_2330(WRef_2330* h) { return V_2330(h) ? h->obj : 0; }
static inline int Find_2330(WMgr_2330* m, WObj_2330* target)
{
    int res = -1;
    int i;
    if (target != 0) {
        for (i = 0; i < 20; i++) {
            WRef_2330* r = m->refs[i];
            if (r != 0 && G1_2330(r) != 0 && G1_2330(r) == target) { res = i; break; }
        }
    }
    return res;
}
static inline const int& IdOf_2330(WObj_2330* p) { if (p) return p->serial; int m = -1; return m; }
static inline void SetH_2330(WRef_2330* h, WObj_2330* o) { h->obj = o; h->serial = IdOf_2330(o); }
void cWaterFx_RemoveBody(WMgr_2330* m, WObj_2330* target)
{
    int i = Find_2330(m, target);
    if (i >= 0) {
        SoundRequest req;
        EffectMsg msg;
        cSndFx_ctor_int_charP_cGOBJP_int(&req, 0, D_004ABFB0, target, 0);
        EffectMsg_WrapRequest(&msg, &req);
        msg.flag = 1;
        QueueMessage_cMessageR_cSystemP_int(&msg, g_Game, 0);
        SetH_2330(m->refs[i], 0);
        m->count--;
        msg.vtbl = D_004DAE30;
        cFileMan_dtor(msg.partB, -1);
        cFileMan_dtor(msg.partA, -1);
        cMessage_dtor(&msg, 0);
        cFileMan_dtor(req.partB, -1);
        cFileMan_dtor(req.partA, -1);
    }
}
static inline void merge_flush_func_002B2330(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002B2330 */
