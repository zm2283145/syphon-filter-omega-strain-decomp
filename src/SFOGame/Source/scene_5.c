/*
 * SFOGame/Source/scene: 2 files, 0013DAD0-0013DB30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0013DAD0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(cSceneManager_dtor, std_list_cScenePtr_dtor)
static inline void merge_flush_func_0013DAD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0013DAD0 */

/* merge_units: begin func_0013DB30 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
/* cScene::UpdateActivation: when the key object leaves its terrain sector (or a full refresh is
   forced), switch to the best sector and deactivate the objects of the old activation set that
   are not in the new one, then activate the new set's objects that were not already active. */
struct cVector { float x, y, z, w; cVector() {} cVector(const cVector& o); } __attribute__((aligned(16)));
struct cBox { cVector lo; cVector hi; };
struct GObj { char pad00[0x2D]; unsigned char active; };
struct GVec { int count; int cap; GObj** data; };
union GIter {
    GObj** p;
    bool operator==(const GIter& o) const { GObj** b = o.p; GObj** a = p; return a == b; }
    bool operator!=(const GIter& o) const { return !(*this == o); }
    GObj*& operator*() const { return *p; }
    GIter& operator++() { p++; return *this; }
};
struct cTerrain { VPAD32(a) virtual cBox* GetBBox(); char pad4[0x1F4 - 4]; GVec activation; };
struct cKeyObj { VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d) virtual cVector GetPosition(); char pad4[0x4C]; void* xform; };
struct cScene { cKeyObj* key; unsigned char forceUpdate; char pad5[3]; cTerrain* keyTerrain; };
extern "C" {
void* nGobjManager_GetGOBJList(void);
cTerrain* nActivation_FindBestSectorInActivation(const cVector& pos, cTerrain* cur);
cTerrain* nActivation_GetClosestTerrainPiece(const cVector& pos);
GVec* cTerrain_GetActivationSortedByDist(cTerrain* t, void* xform);
GIter std_vector_cGOBJPtr_begin(GVec* v);
GIter std_vector_cGOBJPtr_end(GVec* v);
GIter cArray_cGOBJPtr_ConstIterator_ctor_wrapiteratorR(const GIter& s);
void* GetGOBJActivationMan(void);
void cGOBJActivationMan_Deactivate(void* m, GObj* g, int mode);
void cGOBJActivationMan_Activate(void* m, GObj* g, int mode);
void cScene_UpdateActivation(cScene* self);
}
/* VU0 box containment test with branch-likely exits: no C equivalent */
static inline int InBox(const cVector* p, cBox* b) {
    cVector* lo = &b->lo;
    cVector* hi = &b->hi;
    int r;
    asm volatile {
        .set noreorder
        lqc2 vf2, 0(p)
        lqc2 vf1, 0(lo)
        vsub.xyz vf3, vf2, vf1
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni r, vi17
        andi r, r, 0xE0
        bnel r, zero, done
        addi r, zero, 0
        lqc2 vf1, 0(hi)
        vsub.xyz vf3, vf1, vf2
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni r, vi17
        andi r, r, 0xE0
        bnel r, zero, done
        addi r, zero, 0
        addi r, zero, 1
    done:
        .set reorder
    }
    return r;
}
static inline GIter Begin(GVec* v) { return cArray_cGOBJPtr_ConstIterator_ctor_wrapiteratorR(std_vector_cGOBJPtr_begin(v)); }
static inline GIter End(GVec* v) { return cArray_cGOBJPtr_ConstIterator_ctor_wrapiteratorR(std_vector_cGOBJPtr_end(v)); }

void cScene_UpdateActivation(cScene* self)
{
    const cVector& keyPos = self->key->GetPosition();
    if (!self->forceUpdate) {
        if ((unsigned char)InBox(&keyPos, self->keyTerrain->GetBBox()))
            return;
    }
    nGobjManager_GetGOBJList();
    {
        cTerrain* newKeyTerrainPiece = nActivation_FindBestSectorInActivation(keyPos, self->keyTerrain);
        if (!newKeyTerrainPiece) {
            newKeyTerrainPiece = nActivation_GetClosestTerrainPiece(keyPos);
            if (!newKeyTerrainPiece) {
                self->forceUpdate = 1;
                return;
            }
        }
        if (self->forceUpdate || self->keyTerrain != newKeyTerrainPiece) {
            cTerrain* old = self->keyTerrain;
            self->keyTerrain = newKeyTerrainPiece;
            {
                GVec& oldActivation = old->activation;
                GVec& newActivation = *cTerrain_GetActivationSortedByDist(self->keyTerrain, self->key->xform);
                GIter deactivate;
                GIter activate;
                for (deactivate = Begin(&oldActivation); deactivate != End(&oldActivation); ++deactivate) {
                    unsigned char deactivateFlag = 1;
                    if (!self->forceUpdate) {
                        for (activate = Begin(&newActivation); activate != End(&newActivation); ++activate) {
                            if (*activate == *deactivate) {
                                deactivateFlag = 0;
                                break;
                            }
                        }
                    }
                    if (deactivateFlag && *deactivate && (*deactivate)->active) {
                        if (self->forceUpdate)
                            cGOBJActivationMan_Deactivate(GetGOBJActivationMan(), *deactivate, 1);
                        else
                            cGOBJActivationMan_Deactivate(GetGOBJActivationMan(), *deactivate, 0);
                    }
                }
                for (activate = Begin(&newActivation); activate != End(&newActivation); ++activate) {
                    unsigned char activateFlag = 1;
                    if (!self->forceUpdate) {
                        for (deactivate = Begin(&oldActivation); deactivate != End(&oldActivation); ++deactivate) {
                            if (*deactivate == *activate) {
                                activateFlag = 0;
                                break;
                            }
                        }
                    }
                    if (activateFlag && *activate && !(*activate)->active) {
                        if (self->forceUpdate)
                            cGOBJActivationMan_Activate(GetGOBJActivationMan(), *activate, 1);
                        else
                            cGOBJActivationMan_Activate(GetGOBJActivationMan(), *activate, 0);
                    }
                }
            }
        }
    }
    self->forceUpdate = 0;
}
static inline void merge_flush_func_0013DB30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0013DB30 */
