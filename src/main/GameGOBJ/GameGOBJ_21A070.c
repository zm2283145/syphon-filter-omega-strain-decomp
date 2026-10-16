/*
 * main/GameGOBJ: range (2 files, 0021A070-0021A0D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0021A070 */
#pragma push /* merge_units */
typedef struct { char pad[0x1F0]; char a; char b; } Sub0021A070;
typedef struct { void* vtable; char pad[0x5C]; unsigned char flag; char pad61[3]; Sub0021A070* sub; } Obj0021A070;
extern void cGameGOBJ_ctor(Obj0021A070* self, void* a1, void* a2, int kind);
extern void Actor_ApplyContactDamage();
extern void Actor_BaseWorldUpdate();
extern void Actor_VirtualNop();
extern void Controller_DeathNotice();
extern void Node_GetFlag2C();
extern void Object_AttachTransform();
extern void Object_GetAttachedOrSelf();
extern void cGameGOBJ_v0B();
extern void cGameGOBJ_v0C();
extern void func_0012ECE0();
extern void func_0012ED00();
extern void func_0012ED50();
extern void func_0013E060();
extern void func_00140E90();
extern void func_00141850();
extern void func_00148870();
extern void Object_GetEye();
extern void func_00153860();
extern void func_0015BFB0();
extern void func_0015BFC0();
extern void func_0015BFD0();
extern void func_0015BFE0();
extern void func_0015BFF0();
extern void func_0015C000();
extern void func_0015C030();
extern void func_0015C040();
extern void func_0015C050();
extern void func_0015C080();
extern void func_0015C0A0();
extern void cGameGOBJ_GetBounds();
extern void func_002152D0();
extern void func_00216C50();
extern void func_00219E10();
extern void func_00219E90();
extern void func_00219EA0();
extern void cGameGOBJ_Receive();
extern void cGameGOBJ_Disable();
extern void cGameGOBJ_Enable();
extern void func_0021AB00();
extern void func_0021AB60();
extern void func_0021ABC0();
extern void func_0021AC20();
extern void func_0021BD70();
extern void func_0021BD80();
extern void cGameGOBJ_GetModelCol();
extern void func_0021BE50();
extern void func_0021BE60();
extern void func_003CCFF0();
extern void func_003CD090();
extern void func_003CD110();
extern void func_003CD1C0();
extern void PathObj_GetPosition();
extern void func_003CD420();
extern void func_003CD4A0();
extern void func_003CD520();
extern void func_003CD7A0();
extern void func_003CD920();
extern void func_003CDA60();
extern void func_003CDBE0();
extern void func_003CDC20();
extern void func_003CDD40();
extern void func_003CDD80();
extern void func_003CDDC0();
extern void Player_GetActiveWeapon();
extern void func_003CE9E0();
extern void func_003CE9F0();
extern void func_003CEA00();
void * const D_004DB3A0[72] = { (void*)0x0, (void*)0x0, (void*)func_0021BE60, (void*)cGameGOBJ_Receive, (void*)func_0012ECE0, (void*)Object_GetAttachedOrSelf, (void*)func_0021BE50, (void*)func_0012ED00, (void*)func_0021AB60, (void*)func_0021AB00, (void*)func_0021BD70, (void*)func_0021BD80, (void*)func_0012ED50, (void*)cGameGOBJ_v0B, (void*)cGameGOBJ_v0C, (void*)func_003CEA00, (void*)func_003CE9F0, (void*)func_003CE9E0, (void*)func_00219EA0, (void*)func_00219E90, (void*)Actor_BaseWorldUpdate, (void*)Actor_VirtualNop, (void*)func_00219E10, (void*)func_0021AC20, (void*)func_0021ABC0, (void*)cGameGOBJ_Enable, (void*)cGameGOBJ_Disable, (void*)Node_GetFlag2C, (void*)func_0015BFB0, (void*)func_0015BFC0, (void*)func_0015BFD0, (void*)func_00148870, (void*)func_0015BFF0, (void*)func_0015BFE0, (void*)cGameGOBJ_GetBounds, (void*)func_0015C000, (void*)Object_AttachTransform, (void*)Player_GetActiveWeapon, (void*)func_003CDDC0, (void*)func_003CDD80, (void*)func_003CDD40, (void*)func_003CDC20, (void*)func_003CDBE0, (void*)func_003CDA60, (void*)func_003CD920, (void*)func_003CD7A0, (void*)cGameGOBJ_GetModelCol, (void*)func_00153860, (void*)Object_GetEye, (void*)func_002152D0, (void*)func_00140E90, (void*)func_0015C030, (void*)func_0015C040, (void*)func_0015C050, (void*)func_003CD520, (void*)func_003CD4A0, (void*)func_003CD420, (void*)PathObj_GetPosition, (void*)func_003CD1C0, (void*)func_003CD110, (void*)func_003CD090, (void*)func_003CCFF0, (void*)func_0013E060, (void*)func_0015C080, (void*)Actor_ApplyContactDamage, (void*)func_0015C0A0, (void*)func_00141850, (void*)Controller_DeathNotice, (void*)func_00216C50, (void*)0x0, (void*)0x0, (void*)0x0 };
Obj0021A070* cGameGOBJ_CtorKind6(Obj0021A070* self, void* a1, void* a2)
{
    cGameGOBJ_ctor(self, a1, a2, 6);
    self->vtable = ((char*)D_004DB3A0);
    if (self->flag) {
        self->sub->a = 0;
        self->sub->b = 0;
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021A070(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021A070 */

/* merge_units: begin func_0021A0D0 */
#pragma push /* merge_units */
#pragma push
#pragma opt_propagation off
typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
extern void* GObj_IdentityB(void*);
extern void Blast_Prepare(void* obj, int kind, float x, float y, float z, int flag, int a, int b, int c);
/* Script native: creates a blast of kind args[1] at (args[2], args[3], args[4]) on object args[0], flag args[5]; returns 0. */
    int Script_CreateBlast_2(ScriptArg* args)
{
    int flag;
    volatile int kind;
    float fz, fy, fx;
    int x[1];
    int y[1];
    int z[1];
    flag = args[5].i != 0;
    z[0] = args[4].i;
    fz = *(float*)z;
    y[0] = args[3].i;
    fy = *(float*)y;
    x[0] = args[2].i;
    fx = *(float*)x;
    kind = args[1].i;
    Blast_Prepare(GObj_IdentityB(args[0].p), kind, fx, fy, fz, flag, 0, 0, 0);
    return 0;
}
#pragma pop
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021A0D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021A0D0 */
