/* HudTargets_RemoveMarker: per-frame check of one HUD target marker: returns 0 when the marker should
 * go (object gone, handle stale, target dead), otherwise refreshes its colours by team, visibility and
 * lock progress and records the object in the tracked-handle list. */
#pragma cplusplus on
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))

class VObj {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual int IsActive();          /* 0x54 */
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34();
    virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46();
    virtual int Kind();              /* 0xC4 */
    char pad4[0x0C - 4];
    int serial;                      /* 0x0C */
    char pad10[0x14 - 0x10];
    unsigned char b14;
    char pad15[0x20 - 0x15];
    float f20;
    char pad24[0x2C - 0x24];
    unsigned char b2C, b2D, b2E;
    char pad2F[0x58 - 0x2F];
    VObj* x58;
};

struct Hnd { VObj* obj; int id; };
struct MRec { int id; char* icon0; char* icon1; unsigned char team; char pad0D[3]; int kind; Hnd h; };

extern "C" {
VObj* Object_LookupById(int* id);
int ObjMarkerList_Append(char* list, MRec** rec);
void IeElement_SetColour(char* e, float* c);
int TeamTable_AreEnemies(int a, int b);
void HudTracker_Kill(char* t);
void ObjMarker_ConstructIcon(MRec* rec, unsigned char enemy);
int TargetVis_Test(char* a, int b, VObj* c, int d, int e);
VObj* Controller_GetAimTarget(VObj* c);
void WeakHandleList_Append(int* res, char* list, char** pos, Hnd* h);
extern char* g_LocalPlayer;
extern char g_TargetVisMgr[];
extern float D_004FFDB0[4];
extern float g_HudPlayerMarkerColour[4];
extern float D_004FFDD0[4];
extern float D_004FFDE0[4];
extern float D_004FFDF0[4];
extern float D_0048B310;
}

static inline bool Alive(VObj* o) { return o->b2D && o->b2C && !o->b2E; }
#define SetBoth(r, c) (IeElement_SetColour(F_((r)->icon1, 0x60, char*), (c)), IeElement_SetColour(F_((r)->icon0, 0x60, char*), (c)))

#pragma bool off
static inline int Hidden(int a, VObj* o) { return !(TargetVis_Test(g_TargetVisMgr, a, o, 0, 0) != 0); }
#pragma bool reset
extern "C" unsigned char HudTargets_RemoveMarker(MRec* rec, char* list, char* hlist, float* best, float scale)
{
    VObj* obj;
    unsigned char keep;
    obj = Object_LookupById((int*)(rec->icon1 + 0x68));
    keep = 1;
    if (!obj)
        return 0;
    if (rec->kind == 1) {
        unsigned char ok = keep;
        VObj* o = rec->h.obj;
        bool isNull = !o;
        if (!isNull && o->serial != rec->h.id) ok = 0;
        o = ok ? o : 0;
        if (o) ObjMarkerList_Append(list, &rec);
        else keep = 0;
    } else if (rec->kind == 2) {
        ObjMarkerList_Append(list, &rec);
    } else if (F_(obj, 0x58, int) != 0) {
        if (!Alive(obj)) {
            keep = 0;
        } else {
            unsigned char act = 0; /* reused below for the enemy flag (retail keeps both in s0) */
            VObj* c = obj->x58;
            if (c && c->IsActive()) act = 1;
            if (act) {
                SetBoth(rec, g_HudPlayerMarkerColour);
            } else {
                char* pl = g_LocalPlayer;
                int e = TeamTable_AreEnemies(F_(pl, 0x30, int), (int)obj) != 0;
                if (!e) e = TeamTable_AreEnemies((int)obj, F_(pl, 0x30, int)) != 0;
                act = e;
                if (act != rec->team) {
                    HudTracker_Kill(rec->icon1);
                    HudTracker_Kill(rec->icon0);
                    rec->icon1 = 0;
                    rec->icon0 = 0;
                    ObjMarker_ConstructIcon(rec, act);
                }
                if (!act) {
                    SetBoth(rec, D_004FFDB0);
                } else {
                    if (!Hidden(F_(pl, 0x30, int), obj)) {
                        SetBoth(rec, D_004FFDE0);
                    } else {
                        float t = 0.0f;
                        float col[4];
                        if (Alive(obj) && (unsigned char)obj->Kind() == 2) {
                            VObj* ctl = obj->x58;
                            if (ctl && Controller_GetAimTarget(ctl)) {
                                VObj* tg = Controller_GetAimTarget(ctl)->x58;
                                if (tg && tg->IsActive() && tg->b14)
                                    t = obj->x58->f20;
                            }
                        }
                        if (!(t <= *best)) *best = t;
                        if (!(t * D_0048B310 <= 0.98f)) t = t * scale;
                        col[0] = D_004FFDD0[0] * (1.0f - t) + D_004FFDF0[0] * t;
                        col[1] = D_004FFDD0[1] * (1.0f - t) + D_004FFDF0[1] * t;
                        col[2] = D_004FFDD0[2] * (1.0f - t) + D_004FFDF0[2] * t;
                        col[3] = D_004FFDD0[3] * (1.0f - t) + D_004FFDF0[3] * t;
                        SetBoth(rec, col);
                    }
                    {
                        Hnd h;
                        int res;
                        int* p;
                        char* pos;
                        int def;
                        h.id = -1;
                        h.obj = obj;
                        if (obj) p = &obj->serial; else { def = -1; p = &def; }
                        h.id = *p;
                        pos = hlist + 4;
                        WeakHandleList_Append(&res, hlist, &pos, &h);
                    }
                }
            }
        }
    }
    return keep;
}
