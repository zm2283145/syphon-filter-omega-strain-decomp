/*
 * SFOGame/Source/hudTargets: 2 files, 00274750-002749B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00274750 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

extern "C" {
void* cMemMan_Allocate(int, int, char*, int);
int cInterfaceModel_CreateInstance(int);
void cIE_GOBJ_ctor(void*, int, void*);
void cInterfaceElement_SetFilterColor(int, void*);
extern char D_004A8F40[];
extern char D_004A8F50[];
extern char D_004A8F60[];
extern char D_004DC810[];
extern char D_004E0360[];
extern int D_004FFD50;
extern int D_004FFD58;
extern int D_004FFD60;
extern int D_004FFD68;
extern int D_004FFD70;
extern int D_004FFD78;
extern char g_IdentityMatrix[];
}

#define S4(n) virtual void s##n##a(); virtual void s##n##b(); virtual void s##n##c(); virtual void s##n##d();
struct Icon274750 {
    S4(0) S4(1) S4(2) S4(3) S4(4) S4(5) S4(6) S4(7)
    virtual void s32(); virtual void s33();
    virtual void SetProp(void*, int);
};

struct Marker274750 {
    int pad0;
    Icon274750* icon;
    void* label;
    signed char big;
    int type;
};

extern "C" void cHudTargetInfo_SetModel(Marker274750* m, signed char big)
{
    int s1;
    void* o;
    int id;
    unsigned char f;

    m->big = big;
    f = 1;
    if (!(m->type == 1 || m->type == 2))
        f = 0;
    id = f ? D_004FFD78 : (big ? D_004FFD68 : D_004FFD70);
    s1 = cInterfaceModel_CreateInstance(id);
    {
        AllocGuard g;
        o = cMemMan_Allocate(0, 0x90, D_004A8F60, 0xE9);
    }
    if (o) {
        cIE_GOBJ_ctor(o, s1, m);
        *(char**)o = D_004E0360;
    }
    m->label = o;
    cInterfaceElement_SetFilterColor(s1, big ? D_004A8F50 : D_004A8F40);
    f = 1;
    if (!(m->type == 1 || m->type == 2))
        f = 0;
    id = f ? D_004FFD60 : (big ? D_004FFD50 : D_004FFD58);
    {
        AllocGuard g;
        o = cMemMan_Allocate(0, 0x90, D_004A8F60, 0xF3);
    }
    if (o) {
        cIE_GOBJ_ctor(o, cInterfaceModel_CreateInstance(id), m);
        *(char**)o = D_004DC810;
    }
    m->icon = (Icon274750*)o;
    m->icon->SetProp(g_IdentityMatrix, 0);
}
static inline void merge_flush_func_00274750(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00274750 */

/* merge_units: begin func_002749B0 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
int nGlobalization_GetString_charP(signed char *);                           
signed char *std_basic_string_char_char_traits_char_c_str(int);                             
int cHudTargetInfo_GetObjectiveString();                                
int sprintf(int, int *, int, int);                      

int cHudTargetInfo_GetObjectiveLocationString(int arg0, int arg1) {
    int temp_v0;
    int var_a3;
    signed char *temp_v0_2;

    if (arg1 == 0) {
        return 0;
    }
    temp_v0 = cHudTargetInfo_GetObjectiveString();
    if (temp_v0 == 0) {
        return 0;
    }
    temp_v0_2 = std_basic_string_char_char_traits_char_c_str(arg0 + 0x28);
    var_a3 = 0;
    if ((temp_v0_2 != NULL) && (*temp_v0_2 != 0)) {
        var_a3 = nGlobalization_GetString_charP(temp_v0_2);
    }
    if (var_a3 != 0) {
        sprintf(arg1, ((int*)"%s %s"), temp_v0, var_a3);
        return arg1;
    }
    return temp_v0;
}
static inline void merge_flush_func_002749B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002749B0 */
