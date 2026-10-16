/*
 * main/hud: 4 files, 00260ED0-00261090
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00260ED0 */
#pragma push /* merge_units */
#include "types.h"
#pragma global_optimizer off
typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
typedef struct { float v; float pad[3]; } E_0ED0;
extern E_0ED0 D_004F8190[], D_004F8194[], D_004F8198[], D_004F819C[];
extern unsigned char D_004F8230;
static inline void SetNVLockColor_0ED0(int idx, float f, int b, int g, int r)
{
    D_004F8230 = 1;
    if (idx < 10) {
        if (f > 0.0f) D_004F8190[idx].v = f;
        D_004F8194[idx].v = r;
        D_004F8198[idx].v = g;
        D_004F819C[idx].v = b;
    }
}
int Script_SetNVLockColor(ScriptArg* args)
{
    int b[1];
    int g[1];
    int r[1];
    int f[1];
    int i[1];
    b[0] = args[4].i;
    g[0] = args[3].i;
    r[0] = args[2].i;
    f[0] = args[1].i;
    i[0] = args[0].i;
    SetNVLockColor_0ED0(*(int*)i, *(float*)f, *(int*)b, *(int*)g, *(int*)r);
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00260ED0 */

/* merge_units: begin func_00260FB0 */
#pragma push /* merge_units */
typedef struct { float v; float pad[3]; } B5fEnt;
extern B5fEnt D_004F80F0[];
extern B5fEnt D_004F80F4[];
extern B5fEnt D_004F80F8[];
extern B5fEnt D_004F80FC[];
#define B5F_ARG(var, i) (*(int*)&(var) = args[i])
int Script_SetLockColor(int* args) {
    int b;
    int g;
    int r;
    float a;
    int idx;
    int bb, gg, rr, ii;
    float aa;
    B5F_ARG(b, 4);
    bb = b;
    B5F_ARG(g, 3);
    gg = g;
    B5F_ARG(r, 2);
    rr = r;
    B5F_ARG(a, 1);
    aa = a;
    B5F_ARG(idx, 0);
    ii = idx;
    if (ii < 10) {
        if (!(aa <= 0.0f)) {
            D_004F80F0[ii].v = aa;
        }
        D_004F80F4[ii].v = rr;
        D_004F80F8[ii].v = gg;
        D_004F80FC[ii].v = bb;
    }
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_00260FB0 */

/* merge_units: begin func_00261080 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* func_00261080(void* self) {
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00261080 */

/* merge_units: begin func_00261090 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

extern "C" {
extern "C" void Actor_ApplyContactDamage();
extern "C" void Actor_BasePreLogic();
extern "C" void Actor_BaseWorldUpdate();
extern "C" void Actor_VirtualNop();
extern "C" void Controller_DeathNotice();
extern "C" void Node_ClearFlag2C();
extern "C" void Node_GetFlag2C();
extern "C" void Node_SetFlag2C();
extern "C" void Object_Activate();
extern "C" void Object_AttachTransform();
extern "C" void Object_GetAttachedOrSelf();
extern "C" void cGOBJ_v0B();
extern "C" void cGOBJ_v0C();
extern "C" void func_0012ECE0();
extern "C" void func_0012ED00();
extern "C" void func_0012ED30();
extern "C" void func_0012ED40();
extern "C" void func_0012ED50();
extern "C" void func_0013E060();
extern "C" void func_0013EE60();
extern "C" void func_00140E90();
extern "C" void func_00141850();
extern "C" void func_00148870();
extern "C" void Object_GetEye();
extern "C" void func_00153860();
extern "C" void func_0015BFB0();
extern "C" void func_0015BFC0();
extern "C" void func_0015BFD0();
extern "C" void func_0015BFE0();
extern "C" void func_0015BFF0();
extern "C" void func_0015C000();
extern "C" void func_0015C010();
extern "C" void func_0015C020();
extern "C" void func_0015C030();
extern "C" void func_0015C040();
extern "C" void func_0015C050();
extern "C" void func_0015C080();
extern "C" void func_0015C090();
extern "C" void func_0015C0A0();
extern "C" void HudBlip_Draw();
extern "C" void HudBlip_Place();
extern "C" void func_003CCFF0();
extern "C" void func_003CD090();
extern "C" void func_003CD110();
extern "C" void Node_GetComponentMatrix();
extern "C" void PathObj_GetPosition();
extern "C" void Node_GetLightRefPoint();
extern "C" void func_003CD4A0();
extern "C" void Node_GetWorldMatrix();
extern "C" void func_003CD7A0();
extern "C" void func_003CD920();
extern "C" void func_003CDA60();
extern "C" void func_003CDBE0();
extern "C" void func_003CDC20();
extern "C" void func_003CDD40();
extern "C" void func_003CDD80();
extern "C" void func_003CDDC0();
extern "C" void Player_GetActiveWeapon();
extern "C" void Object_Deactivate();
extern "C" void func_003CE7D0();
extern "C" void func_003CE810();
extern "C" void func_003CE9E0();
extern "C" void func_003CE9F0();
extern "C" void func_003CEA00();
extern "C" void Object_HandleMessage();
extern "C" void HudTracker_Update();
extern void * const D_004DC810[];
void* func_003E9940(void* self, short deleteFlag);
}
extern "C" VtableObject* HudBlip_dtor(VtableObject* self, short deleteFlag)
{
    if (self) {
        self->vtable = ((char*)D_004DC810);
        func_003E9940(self, 0);
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}
void * const D_004DC810[72] = { (void*)0x0, (void*)0x0, (void*)HudBlip_dtor, (void*)Object_HandleMessage, (void*)func_0012ECE0, (void*)Object_GetAttachedOrSelf, (void*)func_0015C090, (void*)func_0012ED00, (void*)func_003CE810, (void*)func_003CE7D0, (void*)func_0012ED30, (void*)func_0012ED40, (void*)func_0012ED50, (void*)cGOBJ_v0B, (void*)cGOBJ_v0C, (void*)func_003CEA00, (void*)func_003CE9F0, (void*)func_003CE9E0, (void*)HudTracker_Update, (void*)Actor_BasePreLogic, (void*)Actor_BaseWorldUpdate, (void*)Actor_VirtualNop, (void*)HudBlip_Draw, (void*)Object_Activate, (void*)Object_Deactivate, (void*)Node_SetFlag2C, (void*)Node_ClearFlag2C, (void*)Node_GetFlag2C, (void*)func_0015BFB0, (void*)func_0015BFC0, (void*)func_0015BFD0, (void*)func_00148870, (void*)func_0015BFF0, (void*)func_0015BFE0, (void*)func_0013EE60, (void*)func_0015C000, (void*)Object_AttachTransform, (void*)Player_GetActiveWeapon, (void*)func_003CDDC0, (void*)func_003CDD80, (void*)func_003CDD40, (void*)func_003CDC20, (void*)func_003CDBE0, (void*)func_003CDA60, (void*)func_003CD920, (void*)func_003CD7A0, (void*)func_0015C010, (void*)func_00153860, (void*)Object_GetEye, (void*)func_0015C020, (void*)func_00140E90, (void*)func_0015C030, (void*)func_0015C040, (void*)func_0015C050, (void*)Node_GetWorldMatrix, (void*)func_003CD4A0, (void*)Node_GetLightRefPoint, (void*)PathObj_GetPosition, (void*)Node_GetComponentMatrix, (void*)func_003CD110, (void*)func_003CD090, (void*)func_003CCFF0, (void*)func_0013E060, (void*)func_0015C080, (void*)Actor_ApplyContactDamage, (void*)func_0015C0A0, (void*)func_00141850, (void*)Controller_DeathNotice, (void*)HudBlip_Place, (void*)0x0, (void*)0x0, (void*)0x0 };
#pragma pop /* merge_units */
/* merge_units: end func_00261090 */
