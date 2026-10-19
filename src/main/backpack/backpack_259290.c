/*
 * main/backpack: 3 files, 00259290-002593B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00259290 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_00259290, func_00135C90)
#pragma pop /* merge_units */
/* merge_units: end func_00259290 */

/* merge_units: begin func_002592F0 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } V4_92F0;
typedef struct { V4_92F0 mn; V4_92F0 mx; } Box_92F0;
extern signed char D_004F7FB0;
extern Box_92F0 D_004F7FC0;
extern char* g_WeaponDatabase;
typedef struct { char pad[0x60]; char* p; unsigned char idx; } Self_92F0;
void* WeaponPreview_GetBounds(Self_92F0* self)
{
    char* p;
    if (!D_004F7FB0) {
        D_004F7FC0.mn.x = 3.4028235e38f; D_004F7FC0.mn.y = 3.4028235e38f; D_004F7FC0.mn.z = 3.4028235e38f; D_004F7FC0.mn.w = 1.0f;
        D_004F7FC0.mx.x = -3.4028235e38f; D_004F7FC0.mx.y = -3.4028235e38f; D_004F7FC0.mx.z = -3.4028235e38f; D_004F7FC0.mx.w = 1.0f;
        D_004F7FB0 = 1;
    }
    p = self->p;
    if (!p && self->idx != 7) p = ((char**)(g_WeaponDatabase + 0xB8))[self->idx];
    return p ? (void*)(p + 0x3E0) : (void*)&D_004F7FC0;
}
#pragma pop /* merge_units */
/* merge_units: end func_002592F0 */

/* merge_units: begin func_002593B0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int ActorModel_DrawLod(int, int, char *, int);
extern char g_IdentityMatrix;

void WeaponPreview_Draw(char * arg0) {
    int var_a0;
    unsigned char temp_a1;

    var_a0 = F_(arg0, 0x60, int);
    if (var_a0 == 0) {
        temp_a1 = F_(arg0, 0x64, unsigned char);
        if (temp_a1 != 7) {
            var_a0 = ((int *)(g_WeaponDatabase + 0xB8))[temp_a1];
        }
    }
    if (var_a0 != 0) {
        ActorModel_DrawLod(var_a0, F_(arg0, 0x38, int), &g_IdentityMatrix, 1);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_002593B0 */
