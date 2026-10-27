/*
 * SFOGame/Source/targetManager: 2 files, 0022C180-0022C210
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0022C180 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern GameUI* g_Hud;
extern MarkerTarget* cGOBJ_SOBJ_convert(void*);
extern int SetRadarBlip_cGOBJP(MarkerTarget*);
extern int printf(char*, int, int, int, int, int, int, int, float, float, float, float, float, float, float, float);
extern int cHudTargetManager_Add(void*, int*, int);

int Script_SetRadarBlip(ScriptArg* args) {
    SetRadarBlip_cGOBJP(cGOBJ_SOBJ_convert(args[0].p));
    return 0;
}

/* Prints the deprecation message "******* Don't use this function, Use SetRadarBlip( gobj )\n", then sets the blip. */
int SetRadarBlip_cGOBJP_float(MarkerTarget* obj, int a1, int a2, int a3, int t0, int t1, int t2, int t3, float f12, float f13, float f14, float f15, float f16, float f17, float f18, float f19) {
    printf("******* Don't use this function, Use SetRadarBlip( gobj )\n", a1, a2, a3, t0, t1, t2, t3, f12, f13, f14, f15, f16, f17, f18, f19);
    return SetRadarBlip_cGOBJP(obj);
}

int SetRadarBlip_cGOBJP(MarkerTarget* obj) {
    return cHudTargetManager_Add(g_Hud->markerMgr, &obj->markerKey, 1);
}
static inline void merge_flush_func_0022C180(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0022C180 */

/* merge_units: begin func_0022C210 */
#pragma push /* merge_units */
#pragma cplusplus on

struct Ctl {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12();
    virtual int Active(); /* 0x54 */
};
struct Tgt {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v2A(); virtual void v2B(); virtual void v2C(); virtual void v2D(); virtual void v2E();
    virtual unsigned char Kind(); /* 0xC4 */
    int pad4[2];
    int id;
    char p10[0x2C - 0x10];
    bool x2C; bool x2D; bool x2E; char p2F;
    char p30[0x58 - 0x30];
    Ctl* x58;
    bool Alive() { return x2D && x2C && !x2E; }
};
struct Hnd { Tgt* p; int id; };
static inline Tgt* HGet2(Hnd* h) {
    bool ok = !h->p || h->p->id == h->id;
    return ok ? h->p : 0;
}
static inline bool IdEq(Tgt* p, Hnd* h) { return p->id == h->id; }
static inline Tgt* HGet(Hnd* h) {
    bool ok = !h->p || IdEq(h->p, h);
    return ok ? h->p : 0;
}
struct WNode { WNode* prev; WNode* next; Hnd h; };
struct Player { char p[0xC8]; Hnd lock; };
struct World { char p[0x90]; char markers[1]; };
struct WL { int x0; int list; };

extern "C" {
#if 0 /* merge_units */
extern World* g_Hud;
#endif /* merge_units */
#define g_Hud (*(World **)&g_Hud) /* merge_units */

extern char D_004F78DC[];
WNode* details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_2(void* l);
#if 0 /* merge_units */
int cHudTargetManager_Add(void* mgr, int* key, int f);
#endif /* merge_units */
#define cHudTargetManager_Add(a0, a1, a2) (cHudTargetManager_Add((a0), (a1), (a2))) /* merge_units */

void cPlayerControls_Untarget(Player* p, Tgt* t);
int cHudTargetManager_Remove(void* mgr, int* key, int f);
}

extern "C" void SeedPlayerLos(Tgt* self, Player* pl)
{
    void* mgr;
    WL* wl = (WL*)D_004F78DC;
    WNode* it = details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_2(&wl->list)->next;
    WNode* end = details_compressed_pair_imp_cAllocator_node_node_base_1_second_void_2(&wl->list);
    mgr = g_Hud->markers;
    for (; it != end; it = it->next) {
        Hnd* h = &it->h;
        Tgt* t = HGet(h);
        if (!t || t == self) continue;
        bool active = false;
        if (t->x58 && t->x58->Active()) active = true;
        if (active) {
            cHudTargetManager_Add(mgr, &t->id, 0);
        } else if (HGet2(&pl->lock) == t || t->Kind() == 2) {
            if (t->Alive()) {
                cHudTargetManager_Add(mgr, &t->id, 0);
            } else {
                cPlayerControls_Untarget(pl, t);
                cHudTargetManager_Remove(mgr, &t->id, 0);
            }
        } else if ((unsigned char)t->Kind() == 0) {
            cPlayerControls_Untarget(pl, t);
            cHudTargetManager_Remove(mgr, &t->id, 0);
        }
    }
}
#undef g_Hud /* merge_units */
#undef cHudTargetManager_Add /* merge_units */
static inline void merge_flush_func_0022C210(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0022C210 */
