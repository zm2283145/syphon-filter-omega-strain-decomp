/*
 * SFOGame/Source/humanAnimData: 2 files, 002064D0-00206830
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002064D0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char d[0x4]; } B4;
typedef struct { char d[0x8]; } B8;
typedef struct { char d[0x10]; } B10;
typedef struct { char d[0x20]; } B20;
typedef struct { char d[0x30]; } B30;
typedef struct { char d[0x40]; } B40;
typedef struct { char d[0x50]; } B50;
typedef struct { B10 m2F0; B8 m300; B10 m308; B8 m318; B10 m320; } S2F0;
extern char D_004A3A20[];
extern void* cString16N_3_ctor_charP(void*, void*);
extern void cSkaAnim_ctor_cString16NR_cSkaAnimationSetR_bool_bool_etc_3(void*, void*, void*, int, int, void*, int, int, float, float, int);
extern void cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR(void*, void*, void*, void*);
extern void cSkaAnim_dtor(void*, int);
extern float Deg2Rad(float);
extern void* cEulerAngle_T_1_2_ctor_float_float_float(void*, float, float, float);
extern void cSkaAnim_ctor_cString16NR_cSkaAnimationSetR_eModifier_cEulerAngleTR_etc(void*, void*, void*, int, void*, int);
extern void cSkaInitListOfPointers_cSkaBlendSequenceItem_ctor(void*);
extern void cSkaBlendSequenceExtents_ctor_float_float(void*, float, float);
extern void cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(void*, void*, void*, void*);
extern void* cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(void*, void*);
extern void cQuaternion_GetIdentity(void*);
extern void cSkaSlider_ctor_int_cSkaInitListOfPointersR_bool_bool_etc(void*, int, void*, int, int, void*);
extern void cSkaSlider_dtor(void*, int);
extern void cSkaBlendSequenceItem_dtor(void*, int);
extern void cSkaBlendSequenceExtents_dtor(void*, int);
extern void cSkaInitListOfPointers_cSkaBlendSequenceItem_dtor(void*, int);
extern void* cSkaPlaybackGroupId_ctor_int(void*, int);
extern void cSkaAnimationBlend_ctor(void*, void*, void*, void*);
extern void* cString16N_2_ctor_charP(void*, void*);
extern void cSkaAnimationSet_CreateAnimationBlend(void*, void*, void*);
extern void cSkaAnimationBlend_dtor(void*, int);
/* Builds and registers the run-roll-back-right motion nodes. */
#pragma optimization_level 1
void BuildAnimationBlend_RunRollBackRght(void* p0)
{
    B4 v34C;
    B4 v348;
    B4 v344;
    B8 v338;
    B8 v330;
    S2F0 s;
    B30 v2C0;
    B30 v290;
    B10 v280;
    B50 v230;
    B30 v200;
    B30 v1D0;
    B10 v1C0;
    B50 v170;
    B30 v140;
    B30 v110;
    B30 vE0;
    B10 vD0;
    B40 v90;
    B20 v70;
    B30 v40;
    void* t1;
    void* t2;
    cSkaAnim_ctor_cString16NR_cSkaAnimationSetR_bool_bool_etc_3(&v230, cString16N_3_ctor_charP(&v290, D_004A3A20), p0, 0, 1, cEulerAngle_T_1_2_ctor_float_float_float(&v280, 0.0f, 0.0f, 0.0f), 2, 1, 0.0f, 1.0f, 0);
    cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR(&v34C, p0, cString16N_3_ctor_charP(&v2C0, "animRunRollBackRght_Rght"), &v230);
    cSkaAnim_dtor(&v230, -1);
    cSkaAnim_ctor_cString16NR_cSkaAnimationSetR_eModifier_cEulerAngleTR_etc(&v170, cString16N_3_ctor_charP(&v1D0, "animRunRollBackRght_Rght"), p0, 4, cEulerAngle_T_1_2_ctor_float_float_float(&v1C0, 0.0f, 0.0f, Deg2Rad(-90.0f)), 2);
    cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR(&v348, p0, cString16N_3_ctor_charP(&v200, "animRunRollBackRght_Back"), &v170);
    cSkaAnim_dtor(&v170, -1);
    cSkaInitListOfPointers_cSkaBlendSequenceItem_ctor(&v338);
    cSkaBlendSequenceExtents_ctor_float_float(&v330, 0.0f, 0.75f);
    cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(&s.m320, cString16N_3_ctor_charP(&v110, "animRunRollBackRght_Rght"), p0, &v330);
    cSkaBlendSequenceExtents_ctor_float_float(&s.m318, 1.0f, 1.0f);
    cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(&s.m308, cString16N_3_ctor_charP(&vE0, "animRunRollBackRght_Back"), p0, &s.m318);
    t1 = cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(&v338, &s.m320);
    t2 = cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(t1, &s.m308);
    cQuaternion_GetIdentity(&vD0);
    cSkaSlider_ctor_int_cSkaInitListOfPointersR_bool_bool_etc(&v90, 15, t2, 0, 0, &vD0);
    cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR(&v344, p0, cString16N_3_ctor_charP(&v140, "sliderRunRollBackRght"), &v90);
    cSkaSlider_dtor(&v90, -1);
    cSkaBlendSequenceItem_dtor(&s.m308, -1);
    cSkaBlendSequenceExtents_dtor(&s.m318, -1);
    cSkaBlendSequenceItem_dtor(&s.m320, -1);
    cSkaBlendSequenceExtents_dtor(&v330, -1);
    cSkaInitListOfPointers_cSkaBlendSequenceItem_dtor(&v338, -1);
    cSkaAnimationBlend_ctor(&s.m2F0, cString16N_3_ctor_charP(&v40, "sliderRunRollBackRght"), p0, cSkaPlaybackGroupId_ctor_int(&s.m300, 2));
    cSkaAnimationSet_CreateAnimationBlend(p0, cString16N_2_ctor_charP(&v70, "RunRollBackRght"), &s.m2F0);
    cSkaAnimationBlend_dtor(&s.m2F0, -1);
}
#pragma optimization_level reset
static inline void merge_flush_func_002064D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002064D0 */

/* merge_units: begin func_00206830 */
#pragma push /* merge_units */
typedef struct { B10 m2D0; B8 m2E0; B10 m2E8; B8 m2F8; B10 m300; } S2D0;
extern void cSkaAnim_ctor_cString16NR_cSkaAnimationSetR_int_eAxisOfMotion(void*, void*, void*, int, int);
/* Builds and registers the run-roll-back-left motion nodes. */
#pragma optimization_level 1
void BuildAnimationBlend_RunRollBackLeft(void* p0)
{
    B4 v32C;
    B4 v328;
    B4 v324;
    B8 v318;
    B8 v310;
    S2D0 s2D0;
    B30 v2A0;
    B30 v270;
    B50 v220;
    B30 v1F0;
    B30 v1C0;
    B10 v1B0;
    B50 v160;
    B30 v130;
    B30 v100;
    B30 vD0;
    B10 vC0;
    B40 v80;
    B20 v60;
    B30 v30;
    void* t1;
    void* t2;
    cSkaAnim_ctor_cString16NR_cSkaAnimationSetR_int_eAxisOfMotion(&v220, cString16N_3_ctor_charP(&v270, D_004A3A20), p0, 2, 1);
    cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR(&v32C, p0, cString16N_3_ctor_charP(&v2A0, "animRunRollBackLeft_Left"), &v220);
    cSkaAnim_dtor(&v220, -1);
    cSkaAnim_ctor_cString16NR_cSkaAnimationSetR_eModifier_cEulerAngleTR_etc(&v160, cString16N_3_ctor_charP(&v1C0, "animRunRollBackLeft_Left"), p0, 4, cEulerAngle_T_1_2_ctor_float_float_float(&v1B0, 0.0f, 0.0f, Deg2Rad(90.0f)), 2);
    cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR(&v328, p0, cString16N_3_ctor_charP(&v1F0, "animRunRollBackLeft_Back"), &v160);
    cSkaAnim_dtor(&v160, -1);
    cSkaInitListOfPointers_cSkaBlendSequenceItem_ctor(&v318);
    cSkaBlendSequenceExtents_ctor_float_float(&v310, 0.0f, 0.0f);
    cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(&s2D0.m300, cString16N_3_ctor_charP(&v100, "animRunRollBackLeft_Back"), p0, &v310);
    cSkaBlendSequenceExtents_ctor_float_float(&s2D0.m2F8, 0.25f, 1.0f);
    cSkaBlendSequenceItem_ctor_cString16NR_cSkaAnimationSetR_cSkaBlendSequenceExtentsR(&s2D0.m2E8, cString16N_3_ctor_charP(&vD0, "animRunRollBackLeft_Left"), p0, &s2D0.m2F8);
    t1 = cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(&v318, &s2D0.m300);
    t2 = cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(t1, &s2D0.m2E8);
    cQuaternion_GetIdentity(&vC0);
    cSkaSlider_ctor_int_cSkaInitListOfPointersR_bool_bool_etc(&v80, 15, t2, 0, 0, &vC0);
    cSkaAnimationSet_CreateNode_cString16NR_cSkaNodeR(&v324, p0, cString16N_3_ctor_charP(&v130, "sliderRunRollBackLeft"), &v80);
    cSkaSlider_dtor(&v80, -1);
    cSkaBlendSequenceItem_dtor(&s2D0.m2E8, -1);
    cSkaBlendSequenceExtents_dtor(&s2D0.m2F8, -1);
    cSkaBlendSequenceItem_dtor(&s2D0.m300, -1);
    cSkaBlendSequenceExtents_dtor(&v310, -1);
    cSkaInitListOfPointers_cSkaBlendSequenceItem_dtor(&v318, -1);
    cSkaAnimationBlend_ctor(&s2D0.m2D0, cString16N_3_ctor_charP(&v30, "sliderRunRollBackLeft"), p0, cSkaPlaybackGroupId_ctor_int(&s2D0.m2E0, 2));
    cSkaAnimationSet_CreateAnimationBlend(p0, cString16N_2_ctor_charP(&v60, "RunRollBackLeft"), &s2D0.m2D0);
    cSkaAnimationBlend_dtor(&s2D0.m2D0, -1);
}
#pragma optimization_level reset
static inline void merge_flush_func_00206830(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00206830 */
