/*
 * SFOGame/Source/GuiOmegaStrain: 7 files, 0034EDF0-0034F070
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0034EDF0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"

enum { MODE_0, MODE_1, MODE_2 };

typedef struct { int id; char pad4[4]; unsigned char state; char pad9[0x1C - 9]; } EEDF0;

struct LEDF0 {
    int a0;
    int count;
    EEDF0* data;
    unsigned char aC;
    int size() const { return count; }
};

typedef struct { char pad0[0x48]; void* tbl; } OEDF0;

extern "C" char g_Game[];
extern "C" void func_00296F20(LEDF0* l);
extern "C" void std_vector_deleter_tRequirementInfo_dtor(LEDF0* l, int flags);
extern "C" void* cGameSystem_GetAgentData(void* list, int idx);
extern "C" void cAgentData_GetRequirements(void* ag, int a, int b, LEDF0* l);
extern "C" int nGlobalization_GetString_charP(const char* key);
extern "C" void GuiTextListWidget_AddItem(void* t, int id, int i, int mode);

extern "C" void GuiOmegaStrain_PopulateList(OEDF0* self)
{
    void* ag = cGameSystem_GetAgentData(g_Game, -1);
    LEDF0 l;
    int text;
    int i;
    func_00296F20(&l);
    l.aC = 1;
    cAgentData_GetRequirements(ag, 4, 0, &l);
    text = nGlobalization_GetString_charP("Classified");
    for (i = 0; i < l.size(); i++) {
        EEDF0* e = (EEDF0*)((int)l.data + i * sizeof(EEDF0));
        int id = text;
        int mode;
        if (e->state == 0) {
            mode = MODE_2;
        } else {
            id = e->id;
            mode = e->state == 2 ? MODE_0 : MODE_1;
        }
        GuiTextListWidget_AddItem(self->tbl, id, i, mode);
    }
    std_vector_deleter_tRequirementInfo_dtor(&l, 0);
}
static inline void merge_flush_func_0034EDF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034EDF0 */

/* merge_units: begin func_0034EF00 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GuiOmegaStrain message handler (vtable D_004DEDE0 slot 13).
 */

#include "loose03_types.h"

extern int GuiPersonnelScreen_onMessage(GuiPersonnelScreen* self, int a1, int msg, int value, int t0);

/* Forwards to the GuiPersonnelScreen handler. */
int GuiOmegaStrain_onMessage(GuiPersonnelScreen* self, int a1, int msg, int value, int t0) {
    return GuiPersonnelScreen_onMessage(self, a1, msg, value, t0);
}
static inline void merge_flush_func_0034EF00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034EF00 */

/* merge_units: begin func_0034EF10 */
#pragma push /* merge_units */
#pragma cplusplus on
struct GuiWidget {
    virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4();
    virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9();
    virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14();
    virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19();
    virtual int IsA(void* t);
};
typedef struct { char id[8]; unsigned char state; char pad9[0x1C - 9]; } tRequirementInfo;
struct cAgentData;
struct cArray;
extern "C" {
void GuiPersonnelScreen_onWake(GuiWidget* o);
GuiWidget* GuiWidget_FindChild_charP(GuiWidget* o, const char* name);
#if 0 /* merge_units */
cAgentData* cGameSystem_GetAgentData(char* g, int idx);
#endif /* merge_units */
#define cGameSystem_GetAgentData(a0, a1) ((cAgentData *)cGameSystem_GetAgentData((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void func_00296F20(cArray* l);
#endif /* merge_units */
#define func_00296F20(a0) (func_00296F20((LEDF0 *)(a0))) /* merge_units */

#if 0 /* merge_units */
void std_vector_deleter_tRequirementInfo_dtor(cArray* l, int flags);
#endif /* merge_units */
#define std_vector_deleter_tRequirementInfo_dtor(a0, a1) (std_vector_deleter_tRequirementInfo_dtor((LEDF0 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void cAgentData_GetRequirements(cAgentData* ag, int a, int b, cArray* l);
#endif /* merge_units */
#define cAgentData_GetRequirements(a0, a1, a2, a3) (cAgentData_GetRequirements((void *)(a0), (a1), (a2), (LEDF0 *)(a3))) /* merge_units */

int sprintf(char* b, const char* f, ...);
unsigned long SoftFloat_FloatToDouble(float);
void GuiTextWidget_SetText(GuiWidget* w, const char* s, int f);
extern char* D_00492BC0;
extern char D_004A7520[];
#if 0 /* merge_units */
extern char g_Game[];
#endif /* merge_units */
#define g_Game ((char*)&g_Game) /* merge_units */

extern char D_004BA9F8[];
}
#pragma define_section DROPDTOR ".dtors_drop" far_absolute RX
/* TU context: a preceding function in the original file used soft-double arithmetic */
__declspec(weak) __declspec(DROPDTOR) int k7_ctx(double a, double b) { return a >= b; }
struct cArray {
    int x0; int count; tRequirementInfo* data; unsigned char mCanExpand;
    cArray() { func_00296F20(this); mCanExpand = 1; }
    const tRequirementInfo& operator[](unsigned int k) const { return data[k]; }
    int size() const { return count; }
    __declspec(weak) __declspec(DROPDTOR) ~cArray() { std_vector_deleter_tRequirementInfo_dtor(this, 0); }
};

extern "C" void GuiOmegaStrain_onWake(GuiWidget* self)
{
    GuiWidget* text;
    GuiPersonnelScreen_onWake(self);
    text = GuiWidget_FindChild_charP(self, D_00492BC0);
    text = (text && text->IsA(D_004A7520)) ? text : 0;
    if (text) {
        cAgentData* data = cGameSystem_GetAgentData(g_Game, -1);
        cArray info;
        int numComplete;
        int i;
        char buf[32];
        cAgentData_GetRequirements(data, 4, 0, &info);
        numComplete = 0;
        for (i = 0; i < info.size(); i++) {
            if (info[i].state == 2) numComplete++;
        }
        sprintf(buf, D_004BA9F8, 100.0f * ((float)numComplete / (float)info.size()));
        GuiTextWidget_SetText(text, buf, 0);
    }
}
#undef cGameSystem_GetAgentData /* merge_units */
#undef func_00296F20 /* merge_units */
#undef std_vector_deleter_tRequirementInfo_dtor /* merge_units */
#undef cAgentData_GetRequirements /* merge_units */
#undef g_Game /* merge_units */
static inline void merge_flush_func_0034EF10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034EF10 */

/* merge_units: begin GuiOmegaStrain_34F070 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * GuiOmegaStrain constructor (vtable D_004DEDE0); derives from GuiPersonnelScreen.
 */


extern char D_004DEDE0[];       /* vtable */
extern int GuiPersonnelScreen_ctor(GuiPersonnelScreen*);

/* GuiPersonnelScreen subclass constructor (unk64 = 8). */
GuiPersonnelScreen* GuiOmegaStrain_ctor(GuiPersonnelScreen* self) {
    GuiPersonnelScreen_ctor(self);
    self->base.vtable = D_004DEDE0;
    self->unk64 = 8;
    return self;
}
static inline void merge_flush_GuiOmegaStrain_34F070(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiOmegaStrain_34F070 */

/* merge_units: begin func_0034F0B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

/* Derived destructor: restore vtable, run base destructor, optionally delete. */
DEFINE_VTABLE_BASE_DTOR(GuiPersonnelScreen_dtor_34F0B0, D_004DF0B0, GuiWidget_dtor)
static inline void merge_flush_func_0034F0B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034F0B0 */

/* merge_units: begin func_0034F110 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vector_destroy_dtor.h"

/* Destroy a vector: destroy elements, free the buffer, optionally delete. */
DEFINE_VECTOR_DESTROY_DTOR_FILE(func_0034F110, func_00299500, D_004AA5C8)
static inline void merge_flush_func_0034F110(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034F110 */

/* merge_units: begin func_0034F200 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void func_0034F200(char* self) {
    *(int*)(self + 4) = 0;
}
static inline void merge_flush_func_0034F200(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034F200 */
