#include "types.h"
typedef struct { char d[0x4]; } B4;
typedef struct { char d[0x8]; } B8;
typedef struct { char d[0x10]; } B10;
typedef struct { char d[0x30]; } B30;
typedef struct { char d[0x40]; } B40;
typedef struct { char d[0x50]; } B50;
typedef struct { B10 m2C0; B8 m2D0; B10 m2D8; B8 m2E8; B10 m2F0; } S2C0;
extern void* CanonicalKey_Construct(void*, void*);
extern void cSkaAnim_ctor_cString16NR_cSkaAnimationSetR_int_eAxisOfMotion(void*, void*, void*, int, int);
extern void MotionSlider_RegisterNode(void*, void*, void*, void*);
extern void cSkaAnim_dtor(void*, int);
extern void* Camera_ShakeMatrix(void*, float, float, float);
extern void cSkaAnim_ctor_cString16NR_cSkaAnimationSetR_bool_bool_etc_3(void*, void*, void*, int, int, void*, int, int, float, float, int);
extern void cSkaInitListOfPointers_cSkaBlendSequenceItem_ctor(void*);
extern void cSkaBlendSequenceExtents_ctor_float_float(void*, float, float);
extern void MotionSliderChild_Resolve(void*, void*, void*, void*);
extern void* cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(void*, void*);
extern void Quat_SetIdentity(void*);
extern void MotionSlider_Ctor(void*, int, void*, int, int, void*);
extern void MotionSlider_Dtor(void*, int);
extern void cSkaBlendSequenceItem_dtor(void*, int);
extern void cSkaBlendSequenceExtents_dtor(void*, int);
extern void cSkaInitListOfPointers_cSkaBlendSequenceItem_dtor(void*, int);
/* Builds and registers the hang-from-edge motion nodes. */
#pragma optimization_level 1
void MotionGraph_BuildHang(void* p0)
{
    B4 v31C;
    B4 v318;
    B4 v314;
    B8 v308;
    B8 v300;
    S2C0 s2C0;
    B30 v290;
    B30 v260;
    B50 v210;
    B30 v1E0;
    B30 v1B0;
    B10 v1A0;
    B50 v150;
    B30 v120;
    B30 vF0;
    B30 vC0;
    B30 v90;
    B10 v80;
    B40 v40;
    void* t1;
    void* t2;
    void* t3;
    cSkaAnim_ctor_cString16NR_cSkaAnimationSetR_int_eAxisOfMotion(&v210, CanonicalKey_Construct(&v260, "hang_from_edge_strafe"), p0, 5, 0);
    MotionSlider_RegisterNode(&v31C, p0, CanonicalKey_Construct(&v290, "animHangMoveRght"), &v210);
    cSkaAnim_dtor(&v210, -1);
    cSkaAnim_ctor_cString16NR_cSkaAnimationSetR_bool_bool_etc_3(&v150, CanonicalKey_Construct(&v1B0, "hang_from_edge_strafe"), p0, 0, 1, Camera_ShakeMatrix(&v1A0, 0.0f, 0.0f, 0.0f), 5, 0, 0.0f, 1.0f, 0);
    MotionSlider_RegisterNode(&v318, p0, CanonicalKey_Construct(&v1E0, "animHangMoveLeft"), &v150);
    cSkaAnim_dtor(&v150, -1);
    cSkaInitListOfPointers_cSkaBlendSequenceItem_ctor(&v308);
    cSkaBlendSequenceExtents_ctor_float_float(&v300, 0.0f, 0.0f);
    MotionSliderChild_Resolve(&s2C0.m2F0, CanonicalKey_Construct(&vF0, "animHangMoveLeft"), p0, &v300);
    cSkaBlendSequenceExtents_ctor_float_float(&s2C0.m2E8, 0.5f, 0.5f);
    MotionSliderChild_Resolve(&s2C0.m2D8, CanonicalKey_Construct(&vC0, "hang_from_edge_idle"), p0, &s2C0.m2E8);
    cSkaBlendSequenceExtents_ctor_float_float(&s2C0.m2D0, 1.0f, 1.0f);
    MotionSliderChild_Resolve(&s2C0.m2C0, CanonicalKey_Construct(&v90, "animHangMoveRght"), p0, &s2C0.m2D0);
    t1 = cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(&v308, &s2C0.m2F0);
    t2 = cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(t1, &s2C0.m2D8);
    t3 = cSkaInitListOfPointers_cSkaBlendSequenceItem_opShl(t2, &s2C0.m2C0);
    Quat_SetIdentity(&v80);
    MotionSlider_Ctor(&v40, 6, t3, 0, 0, &v80);
    MotionSlider_RegisterNode(&v314, p0, CanonicalKey_Construct(&v120, "sliderHang"), &v40);
    MotionSlider_Dtor(&v40, -1);
    cSkaBlendSequenceItem_dtor(&s2C0.m2C0, -1);
    cSkaBlendSequenceExtents_dtor(&s2C0.m2D0, -1);
    cSkaBlendSequenceItem_dtor(&s2C0.m2D8, -1);
    cSkaBlendSequenceExtents_dtor(&s2C0.m2E8, -1);
    cSkaBlendSequenceItem_dtor(&s2C0.m2F0, -1);
    cSkaBlendSequenceExtents_dtor(&v300, -1);
    cSkaInitListOfPointers_cSkaBlendSequenceItem_dtor(&v308, -1);
}
#pragma optimization_level reset
