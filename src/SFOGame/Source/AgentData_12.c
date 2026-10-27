/*
 * SFOGame/Source/AgentData: 8 files, 0032EFB0-0032F1F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin Objective_32EFB0 */
#pragma push /* merge_units */
#include "types.h"
typedef union ScriptArg { int i; float f; void* p; unsigned char b; } ScriptArg;
typedef struct { char data[0x18]; } F1Row32EF;
extern int D_00532BC0;
extern char D_005329F0[];
extern char D_00532A10[];
extern char D_00532A40[];
extern char g_Game[];
extern void* cAgentData_Record_ctor_charP_int_int(F1Row32EF* r, int a, int b, int id);
extern void cArray_Record_PushBackActual(void* registry, void* item);
extern void* cGameSystem_GetAgentData(void* list, int index);
#if 0 /* merge_units */
extern void cAgentData_SetBit(void* agent, void* mask, int id);
#endif /* merge_units */
void cAgentData_SetBit(); /* merge_units */

int Objective_RegisterMp(ScriptArg* args)
{
    F1Row32EF r;
    int p0[1];
    int p1[1];
    int id;
    int c;
    int b;
    c = args[3].i != 0;
    b = args[2].i != 0;
    
    p1[0] = args[1].i;
    p0[0] = args[0].i;
    id = D_00532BC0++;
    cArray_Record_PushBackActual(D_005329F0, cAgentData_Record_ctor_charP_int_int(&r, *(int*)p0, *(int*)p1, id));
    if (b) cAgentData_SetBit(cGameSystem_GetAgentData(g_Game, -1), D_00532A10, id);
    if (c) cAgentData_SetBit(cGameSystem_GetAgentData(g_Game, -1), D_00532A40, id);
    return 0;
}
static inline void merge_flush_Objective_32EFB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end Objective_32EFB0 */

/* merge_units: begin func_0032F090 */
#pragma push /* merge_units */
/* Sets bit n in the objective mask (ignores negative n). */
void cAgentData_SetBit(void* self, unsigned int* mask, int n)
{
    if (n > -1)
        mask[n / 32] |= 1 << (n & 31);
}
static inline void merge_flush_func_0032F090(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032F090 */

/* merge_units: begin func_0032F0D0 */
#pragma push /* merge_units */
typedef struct { char data[0x18]; } ObjRow_32F0D0;
#if 0 /* merge_units */
extern void* cAgentData_Record_ctor_charP_int_int(ObjRow_32F0D0* r, int a, int b, int id);
#endif /* merge_units */
#define cAgentData_Record_ctor_charP_int_int(a0, a1, a2, a3) (cAgentData_Record_ctor_charP_int_int((F1Row32EF *)(a0), (a1), (a2), (a3))) /* merge_units */

int Objective_Register(ScriptArg* args)
{
    ObjRow_32F0D0 r;
    int p0[1];
    int p1[1];
    p1[0] = args[1].i;
    p0[0] = args[0].i;
    cArray_Record_PushBackActual(D_005329F0, cAgentData_Record_ctor_charP_int_int(&r, *(int*)p0, *(int*)p1, D_00532BC0++));
    return 0;
}
#undef cAgentData_Record_ctor_charP_int_int /* merge_units */
static inline void merge_flush_func_0032F0D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032F0D0 */

/* merge_units: begin func_0032F130 */
#pragma push /* merge_units */
typedef union { int i; void* p; } ScriptArg_0032F130;

extern void cAgentData_CompleteRequirement(void* agent, int kind, int index);

/* Script native: completes a bonus-level requirement (kind 3) of the agent data. */
int Script_cAgentData_CompleteBonusLevelReq(ScriptArg_0032F130* args)
{
    int index[1];
    index[0] = args[1].i;
    cAgentData_CompleteRequirement(args[0].p, 3, *(int*)index);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0032F130(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0032F130 */

/* merge_units: begin func_0032F160 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void cAgentData_CompleteRequirement(void* agent, int kind, int value);
#endif /* merge_units */
#define cAgentData_CompleteRequirement(a0, a1, a2) (cAgentData_CompleteRequirement((a0), (a1), (a2))) /* merge_units */



typedef union { int i; void* p; float f; } ScriptArg_0032F160;

/* Script native: completes an Omega requirement (kind 4) on the agent data. */
int Script_cAgentData_CompleteOmegaReq(ScriptArg_0032F160* args)
{
    int p1[1];
    p1[0] = args[1].i;
    cAgentData_CompleteRequirement(args[0].p, 4, *(int*)p1);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0032F160(void) {}
#undef cAgentData_CompleteRequirement /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032F160 */

/* merge_units: begin func_0032F190 */
#pragma push /* merge_units */
typedef union ScriptArg_0032F190 { int i; float f; void* p; } ScriptArg_0032F190;
#if 0 /* merge_units */
extern void cAgentData_CompleteRequirement(void* agent, int a1, int requirement);
#endif /* merge_units */
#define cAgentData_CompleteRequirement(a0, a1, a2) (cAgentData_CompleteRequirement((a0), (a1), (a2))) /* merge_units */



/* Script native: completes commendation requirement args[1] for agent data args[0]. */
int Scr_cAgentData_CompleteCommendationReq(ScriptArg_0032F190* args)
{
    int part[1];
    part[0] = args[1].i;
    cAgentData_CompleteRequirement(args[0].p, 1, *(int*)part);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0032F190(void) {}
#undef cAgentData_CompleteRequirement /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032F190 */

/* merge_units: begin func_0032F1C0 */
#pragma push /* merge_units */
typedef union ScriptArg_0032F1C0 { int i; float f; void* p; } ScriptArg_0032F1C0;
#if 0 /* merge_units */
extern void cAgentData_CompleteRequirement(void* agent, int a1, int requirement);
#endif /* merge_units */
#define cAgentData_CompleteRequirement(a0, a1, a2) (cAgentData_CompleteRequirement((a0), (a1), (a2))) /* merge_units */



/* Script native: completes special rating requirement args[1] for agent data args[0]. */
int Scr_cAgentData_CompleteSpecialRatingReq(ScriptArg_0032F1C0* args)
{
    int part[1];
    part[0] = args[1].i;
    cAgentData_CompleteRequirement(args[0].p, 0, *(int*)part);
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0032F1C0(void) {}
#undef cAgentData_CompleteRequirement /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032F1C0 */

/* merge_units: begin func_0032F1F0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern void cAgentData_CompleteRequirement(void* self, int kind, int v);
#endif /* merge_units */
#define cAgentData_CompleteRequirement(a0, a1, a2) (cAgentData_CompleteRequirement((a0), (a1), (a2))) /* merge_units */

int Script_cAgentData_CompleteMedalReq(ScriptArg* args)
{
    int p1[1];
    p1[0] = args[1].i;
    cAgentData_CompleteRequirement(args[0].p, 2, *(int*)p1);
    return 0;
}
#undef cAgentData_CompleteRequirement /* merge_units */
static inline void merge_flush_func_0032F1F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0032F1F0 */
