#include "types.h"
/* light candidate test: range/cone check, appends (light, key) to the gather list */
typedef struct Pt1LcVec { float x, y, z, w; } __attribute__((aligned(16))) Pt1LcVec;
typedef struct Pt1LcEntry {
    unsigned char flags;
    char pad1[3];
    void* light;
    float range;
    float weight;
    Pt1LcVec pos;
} Pt1LcEntry;
typedef struct Pt1LcCand { void* light; float key; } Pt1LcCand;
typedef struct Pt1LcList { char pad[0x2000]; Pt1LcCand cand[1]; } Pt1LcList;
typedef struct Pt1LcGather {
    char pad0[0x50];
    int count;
    Pt1LcList* list;
} Pt1LcGather;
extern void Sphere_FromCenter(Pt1LcVec* out, Pt1LcVec* a, Pt1LcVec* b);
extern void Vec4_Assign(Pt1LcVec* out, Pt1LcVec* src);
extern void Vec4_NormalizeXYZ_132060(Pt1LcVec* out, Pt1LcVec* src);
extern float Vec4_Dot3(Pt1LcVec* a, Pt1LcVec* b);
extern float cSceneLight_GetFalloffAngleCos(void* light);
extern Pt1LcVec* cSceneLight_GetDirection(void* light);
extern float func_00372AE0(void* light);
extern float cVector_GetLengthSquared(Pt1LcVec* v);

void LightMgr_TestPointSpot(Pt1LcGather* g, Pt1LcEntry* e, Pt1LcVec* pos)
{
    Pt1LcVec dir;
    Pt1LcVec n;
    Pt1LcVec d;
    Pt1LcVec v;
    float key;
    float outer;
    unsigned char ok = 0;
    void* light;

    if (e->flags & 0x14) {
        Sphere_FromCenter(&d, pos, &e->pos);
        key = cVector_GetLengthSquared(&d);
        if (key < e->range * e->range) {
            ok = 1;
            key *= e->weight;
            if (e->flags == 0x10) {
                light = e->light;
                if (func_00372AE0(light) != 1.0f) {
                    Vec4_Assign(&dir, cSceneLight_GetDirection(light));
                    Sphere_FromCenter(&v, &e->pos, pos);
                    Vec4_NormalizeXYZ_132060(&n, &v);
                    outer = 1.0f - cSceneLight_GetFalloffAngleCos(light);
                    if (!(1.0f - Vec4_Dot3(&dir, &n) <= outer))
                        ok = 0;
                }
            }
        }
    } else if (e->flags == 2) {
        key = 0.0f;
        ok = 1;
    }
    if (ok) {
        g->list->cand[g->count].key = key;
        g->list->cand[g->count].light = e->light;
        g->count++;
    }
}