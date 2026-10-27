/*
 * SFOGame/Source/humanAnimData: 2 files, 001EFB60-001EFC50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001EFB60 */
#pragma push /* merge_units */
#include "types.h"

extern void BuildAnimationBlend_RollBack(void* self);
extern void BuildAnimationBlend_RunRollBackLeft(void* self);
extern void BuildAnimationBlend_RunRollBackRght(void* self);
extern void BuildAnimationBlend_RunRollLeft(void* self);
extern void BuildAnimationBlend_RunRollRght(void* self);
extern void BuildAnimationBlend_RunRollForw(void* self);
extern void BuildAnimationBlend_Crawl(void* self);
extern void BuildAnimationBlend_Hang(void* self);
extern void BuildAnimationBlend_LadderWeaponAim(void* self);
extern void BuildAnimationBlend_LadderClimb(void* self);
extern void BuildAnimationBlend_Climbs(void* self);
extern void BuildAnimationBlend_CoreMotions(void* self);
extern void BuildAnimations_BuddyClimb(void* self);
extern void BuildAnimations_CarryBody(void* self);
extern void BuildAnimations_JumpFallLand(void* self);
extern void BuildAnimations_BodyLand(void* self);
extern void BuildAnimations_NeckSnap(void* self);

/* Runs every registration step on self in order. */
#pragma optimization_level 1
void nHumanAnimData_BuildAnimations(void* self)
{
    BuildAnimationBlend_RollBack(self);
    BuildAnimationBlend_RunRollBackLeft(self);
    BuildAnimationBlend_RunRollBackRght(self);
    BuildAnimationBlend_RunRollLeft(self);
    BuildAnimationBlend_RunRollRght(self);
    BuildAnimationBlend_RunRollForw(self);
    BuildAnimationBlend_Crawl(self);
    BuildAnimationBlend_Hang(self);
    BuildAnimationBlend_LadderWeaponAim(self);
    BuildAnimationBlend_LadderClimb(self);
    BuildAnimationBlend_Climbs(self);
    BuildAnimationBlend_CoreMotions(self);
    BuildAnimations_BuddyClimb(self);
    BuildAnimations_CarryBody(self);
    BuildAnimations_JumpFallLand(self);
    BuildAnimations_BodyLand(self);
    BuildAnimations_NeckSnap(self);
}
#pragma optimization_level reset
static inline void merge_flush_func_001EFB60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EFB60 */

/* merge_units: begin func_001EFC50 */
#pragma push /* merge_units */
typedef struct { char d[0x4]; } B4;
typedef struct { char d[0x8]; } B8;
typedef struct { char d[0x10]; } B10;
typedef struct { char d[0x30]; } B30;
typedef struct { char d[0x38]; } B38;
typedef struct { char d[0x50]; } B50;
extern void* cString16N_3_ctor_charP(void*, void*);
extern void cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR(void*, void*, void*, void*);
extern void cSkaAnim_dtor(void*, int);
extern void* cSkaAnimPlaybackRange_Normalized_ctor(void*, float, float);
extern void* cEulerAngle_T_1_2_ctor_float_float_float(void*, float, float, float);
extern void cSkaAnim_ctor_cString16NR_cSkaAnimationSetR_bool_bool_etc_2(void*, void*, void*, int, int, void*, void*, int, float, int, int);
extern char D_004A05A0[];
extern char D_004A05B8[];
extern char D_004A05C8[];
extern char D_004A05D8[];
#pragma optimization_level 1
void BuildAnimations_NeckSnap(void* p0)
{
    B4 v1EC;
    B4 v1E8;
    B8 v1E0;
    B8 v1D8;
    B38 v1A0;
    B30 v170;
    B10 v160;
    B50 v110;
    B30 vE0;
    B30 vB0;
    B10 vA0;
    B50 v50;
    cSkaAnim_ctor_cString16NR_cSkaAnimationSetR_bool_bool_etc_2(&v110, cString16N_3_ctor_charP(&v170, D_004A05A0), p0, 0, 0, cSkaAnimPlaybackRange_Normalized_ctor(&v1E0, 0.0f, 0.9f), cEulerAngle_T_1_2_ctor_float_float_float(&v160, 0.0f, 0.0f, 0.0f), -1, 1.0f, 0, 0);
    cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR(&v1EC, p0, cString16N_3_ctor_charP(&v1A0, D_004A05B8), &v110);
    cSkaAnim_dtor(&v110, -1);
    cSkaAnim_ctor_cString16NR_cSkaAnimationSetR_bool_bool_etc_2(&v50, cString16N_3_ctor_charP(&vB0, D_004A05C8), p0, 0, 0, cSkaAnimPlaybackRange_Normalized_ctor(&v1D8, 0.0f, 0.9f), cEulerAngle_T_1_2_ctor_float_float_float(&vA0, 0.0f, 0.0f, 0.0f), -1, 1.0f, 0, 0);
    cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR(&v1E8, p0, cString16N_3_ctor_charP(&vE0, D_004A05D8), &v50);
    cSkaAnim_dtor(&v50, -1);
}
#pragma optimization_level reset
static inline void merge_flush_func_001EFC50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EFC50 */
