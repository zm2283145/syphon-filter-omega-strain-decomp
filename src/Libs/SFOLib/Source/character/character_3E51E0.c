/*
 * main/character: 3 files, 003E51E0-003E5360
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E51E0 */
#pragma push /* merge_units */
#include "types.h"
extern int NetRegisterMessageStart(void* reg);
extern int cCharActionMsg_RegisterFields(void);
extern int NetMessageField(void* desc, void* field, int size, int count);
extern int NetRegisterApplicationMessage(void* type, void* factory);
extern int D_0055A208;
extern void cCharActionMsg_MotionParams_NetCharActionMotionParamsReq(void);
unsigned char cCharActionMsg_MotionParams_InitNet(void* reg)
{
    struct { long long file; int pad; char a[16]; int b; int c; char d; } L;
    unsigned char ok = 0;
    if (NetRegisterMessageStart(reg) == 0 && cCharActionMsg_RegisterFields() != 0
        && NetMessageField(&L.file, L.a, 0x10, 1) == 0
        && NetMessageField(&L.file, &L.b, 4, 1) == 0
        && NetMessageField(&L.file, &L.c, 4, 1) == 0
        && NetMessageField(&L.file, &L.d, 1, 1) == 0
        && NetRegisterApplicationMessage(&D_0055A208, cCharActionMsg_MotionParams_NetCharActionMotionParamsReq) == 0)
        ok = 1;
    return ok;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E51E0 */

/* merge_units: begin func_003E52A0 */
#pragma push /* merge_units */
extern int cMessage_RegisterFields(void* desc);
extern int NetRegisterApplicationMessage(void* t, void* fn);
extern int D_0055A200;
extern void cCharActionMsg_ObjectId_Int_Scalar_Bool_NetCharActionNetObjectIdIntScalarBoolReq(void);
unsigned char cCharActionMsg_ObjectId_Int_Scalar_Bool_InitNet(void* reg)
{
    struct { long long file; char padC[4]; int fC; int f10; int f14; char f18; } L;
    unsigned char ok = 0;
    if (NetRegisterMessageStart(reg) == 0 && cCharActionMsg_RegisterFields() != 0
        && NetMessageField(&L.file, &L.fC, 4, 1) == 0
        && NetMessageField(&L.file, &L.f10, 4, 1) == 0
        && NetMessageField(&L.file, &L.f14, 4, 1) == 0
        && NetMessageField(&L.file, &L.f18, 1, 1) == 0
        && NetRegisterApplicationMessage(&D_0055A200, cCharActionMsg_ObjectId_Int_Scalar_Bool_NetCharActionNetObjectIdIntScalarBoolReq) == 0)
        ok = 1;
    return ok;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E52A0 */

/* merge_units: begin func_003E5360 */
#pragma push /* merge_units */
extern int D_0055A1F8;
extern void cCharActionMsg_ObjectId_Int_NetCharActionNetObjectIdIntReq(void);
unsigned char cCharActionMsg_ObjectId_Int_InitNet(void* reg)
{
    struct { long long file; char padC[4]; int fC; int f10; } L;
    unsigned char ok = 0;
    if (NetRegisterMessageStart(reg) == 0 && cCharActionMsg_RegisterFields() != 0
        && NetMessageField(&L.file, &L.fC, 4, 1) == 0
        && NetMessageField(&L.file, &L.f10, 4, 1) == 0
        && NetRegisterApplicationMessage(&D_0055A1F8, cCharActionMsg_ObjectId_Int_NetCharActionNetObjectIdIntReq) == 0)
        ok = 1;
    return ok;
}
#pragma pop /* merge_units */
/* merge_units: end func_003E5360 */
