#include "types.h"
typedef struct { char d[0x4]; } B4;
typedef struct { char d[0x8]; } B8;
typedef struct { char d[0x10]; } B10;
typedef struct { char d[0x30]; } B30;
typedef struct { char d[0x38]; } B38;
typedef struct { char d[0x50]; } B50;
extern void* CanonicalKey_Construct(void*, void*);
extern void MotionSlider_RegisterNode(void*, void*, void*, void*);
extern void func_003B28F0(void*, int);
extern void* func_001EFE10(void*, float, float);
extern void* Camera_ShakeMatrix(void*, float, float, float);
extern void func_003B4010(void*, void*, void*, int, int, void*, void*, int, float, int, int);
extern char D_004A05A0[];
extern char D_004A05B8[];
extern char D_004A05C8[];
extern char D_004A05D8[];
#pragma optimization_level 1
void func_001EFC50(void* p0)
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
    func_003B4010(&v110, CanonicalKey_Construct(&v170, D_004A05A0), p0, 0, 0, func_001EFE10(&v1E0, 0.0f, 0.9f), Camera_ShakeMatrix(&v160, 0.0f, 0.0f, 0.0f), -1, 1.0f, 0, 0);
    MotionSlider_RegisterNode(&v1EC, p0, CanonicalKey_Construct(&v1A0, D_004A05B8), &v110);
    func_003B28F0(&v110, -1);
    func_003B4010(&v50, CanonicalKey_Construct(&vB0, D_004A05C8), p0, 0, 0, func_001EFE10(&v1D8, 0.0f, 0.9f), Camera_ShakeMatrix(&vA0, 0.0f, 0.0f, 0.0f), -1, 1.0f, 0, 0);
    MotionSlider_RegisterNode(&v1E8, p0, CanonicalKey_Construct(&vE0, D_004A05D8), &v50);
    func_003B28F0(&v50, -1);
}
#pragma optimization_level reset
