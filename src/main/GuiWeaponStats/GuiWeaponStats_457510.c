/*
 * main/GuiWeaponStats: 7 files, 00457510-00457A30
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00457510 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" void* Mem_Alloc(int pool, int size, char* file, int line);
extern "C" {
extern char D_004E1490[];
void GuiWidget_ctor(void* self);
}
struct GN457510 { void* vtable; char pad[0x10]; unsigned short flags; };
extern "C" GN457510* GuiStartMenuBackdrop_Create(void)
{
    GN457510* p;
    {
        AllocGuard guard;
        p = (GN457510*)Mem_Alloc(0, 0x48, "guiWidget.hh", 0x2A);
    }
    if (p) {
        GuiWidget_ctor(p);
        p->vtable = D_004E1490;
        p->flags &= ~0x20;
    }
    return p;
}
#pragma pop /* merge_units */
/* merge_units: end func_00457510 */

/* merge_units: begin func_004575D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on


extern "C" {
/*fc*/
int GuiObjectives_ctor(...);                 
#if 0 /* merge_units */
char * Mem_Alloc(int, int, char *, int);
#endif /* merge_units */
#define Mem_Alloc(a0, a1, a2, a3) ((char *)Mem_Alloc((a0), (a1), (a2), (a3))) /* merge_units */
                      
extern char D_004C1CA0;
extern char D_004E1430;
extern unsigned char g_ProfileLockEnabled;
}
extern "C" char * GuiStartMenu_Create(void) {
    char * temp_s0;

    {
        AllocGuard g;
    temp_s0 = (char *)(Mem_Alloc(0, 0xB4, &D_004C1CA0, 0x2A));
    }
    if (temp_s0 != NULL) {
        GuiObjectives_ctor(temp_s0, 1, 1);
        F_(temp_s0, 0x0, int) = (int)(&D_004E1430);
        F_(temp_s0, 0x90, int) = 0;
        F_(temp_s0, 0x94, int) = 0;
        F_(temp_s0, 0x98, int) = 0;
        F_(temp_s0, 0x9C, int) = 0;
        F_(temp_s0, 0xA0, int) = 0;
        F_(temp_s0, 0xA4, int) = 0;
        F_(temp_s0, 0xA8, int) = 0;
        F_(temp_s0, 0x14, unsigned short) = (unsigned short) (F_(temp_s0, 0x14, unsigned short) & 0xFFDF);
    }
    return temp_s0;
}
#undef Mem_Alloc /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004575D0 */

/* merge_units: begin func_004576C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_new.h"

/* Factory: allocate, run the base constructor, set the vtable. */
extern "C" { char D_004C1CB0[] = "guiWidget.hh"; }
DEFINE_GUARDED_NEW_VT(GuiBriefingPane_Create, 0x4C, D_004C1CB0, GuiWidget_ctor, D_004E13D0)
#pragma pop /* merge_units */
/* merge_units: end func_004576C0 */

/* merge_units: begin func_00457780 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" { char D_004C1CC0[] = "guiWidget.hh"; }
DEFINE_GUARDED_NEW_VT(GuiWeaponStats_Create, 0xC0, D_004C1CC0, guiTextArrayWidget_ctor, D_004E1350)
#pragma pop /* merge_units */
/* merge_units: end func_00457780 */

/* merge_units: begin func_00457840 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" { char D_004C1CD0[] = "guiWidget.hh"; }
DEFINE_GUARDED_NEW_VT(GuiEquipmentPane_Create, 0x58, D_004C1CD0, GuiWidget_ctor, D_004E12F0)
#pragma pop /* merge_units */
/* merge_units: end func_00457840 */

/* merge_units: begin func_00457900 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
#if 0 /* merge_units */
void* Mem_Alloc(int pool, int size, char* file, int line);
#endif /* merge_units */
#define Mem_Alloc(a0, a1, a2, a3) ((void *)Mem_Alloc((a0), (a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
void GuiWidget_ctor(void*);
#endif /* merge_units */
#define GuiWidget_ctor(a0) (GuiWidget_ctor((a0))) /* merge_units */

void Resource_Construct(void*);
int* cSystem_GetObjectID_void(void*);
int* cObjectId_ctor_uint(int*, int);
extern char D_004C1CE0[];
extern void* const D_004E1290[];
}
typedef struct {
    int type;
    char pad04[0xC];
    __int128 name;
    void* voice;
    int voiceId;
    char pad28[8];
    int x30;
    int x34;
    int x38;
    char pad3C[0xC];
    char a[0x9C];
    char b[0x9C];
    int x180;
    short x184;
    char x186;
} SndReq;
typedef struct {
    void* vt;
    char pad[0x4C];
    SndReq r;
} W57900;
static inline void SndReq_Ctor(SndReq* p, void* voice) {
    int tmp;
    p->voiceId = -2;
    p->voice = 0;
    Resource_Construct(p->a);
    Resource_Construct(p->b);
    p->type = -1;
    p->name = -1;
    p->voice = voice;
    int* r = voice ? cSystem_GetObjectID_void(voice) : cObjectId_ctor_uint(&tmp, -1);
    p->voiceId = *r;
    p->x30 = 0;
    p->x34 = 0;
    p->x38 = 0;
    p->x184 = -1;
    p->x180 = 0;
    p->x186 = 0;
}
#pragma opt_dead_code off
extern "C" W57900* GuiRadioLog_Create(void) {
    W57900* p;
    {
        AllocGuard g;
        p = (W57900*)Mem_Alloc(0, 0x1E0, D_004C1CE0, 0x2A);
    }
    if (p) {
        GuiWidget_ctor(p);
        p->vt = (void*)D_004E1290;
        SndReq* r = &p->r;
        SndReq_Ctor(r, 0);
    }
    return p;
}
#undef Mem_Alloc /* merge_units */
#undef GuiWidget_ctor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00457900 */

/* merge_units: begin func_00457A30 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "two_member_dtor.h"

/* Destructor: destroy two members, optionally delete. */
DEFINE_TWO_MEMBER_DTOR(cSndFx_dtor, FileMan_Release, 0x48, 0xE4)
#pragma pop /* merge_units */
/* merge_units: end func_00457A30 */
