/*
 * main/GuiEquipmentModify: range (4 files, 002C0790-002C1100)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"
int cMemMan_Deallocate();

/* merge_units: begin func_002C0790 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "gui_widget_vslots.h"
struct Widget : GuiWidgetV {
    char pad04[0x10]; unsigned short unk14; char pad16[0x1E];
    float unk34; float unk38; int unk3C; float unk40; int unk44;
    void* unk48; char pad4C[0x10]; int unk5C;
};
struct Screen {
    char pad00[0x48]; int unk48; char pad4C[0x48];
    Widget* unk94; int unk98; int unk9C; int unkA0; int unkA4; int unkA8;
    char padAC[0x20]; Widget* unkCC; Widget* unkD0; Widget* unkD4;
    char padD8[0x880]; Widget* unk958; char* unk95C;
};
struct Agent { char pad[0xB70]; unsigned char unkB70; };
struct State { char pad[0x251]; unsigned char unk251; };
extern "C" {
int nGlobalization_GetStringIndex(char*);
char* nGlobalization_GetString_int(int);
char* nGlobalization_GetString_charP(char*);
Agent* cHuman_GetAgentData(int);
char* AgentData_GetRankText(Agent*);
char* cAgentData_GetUserName(Agent*);
void GuiTextWidget_SetText(Widget*, char*, int);
void GuiWidget_onAdd();
void GuiTextListWidget_Clear(Widget*);
extern State* D_004FFC04;
extern int D_00506508;
extern Screen* D_0051EE10;
extern unsigned char g_IsMultiplayer;
void EM_Gun2RenderWrapper();
void EM_Gun1RenderWrapper();
void EM_ManRenderWrapper();
extern char D_0048BA80[];
extern char D_004A7520[];
extern char D_004A9870[];
extern char D_004A9BF0[];
extern char D_004AA640[];
extern char D_004AC2F0[];
extern char D_004AC300[];
extern char D_004AC310[];
extern char D_004AC320[];
extern char D_004AC330[];
extern char D_004AC340[];
extern char D_004AC4A0[];
extern char D_004AC4B0[];
extern char D_004AC4C0[];
extern char D_004AC4D0[];
extern char D_004AC4E0[];
extern char D_004AC4F8[];
extern char D_004AC508[];
extern char D_004AC518[];
extern char D_004AC520[];
extern char D_004AC530[];
extern char D_004AC540[];
extern char D_004AC550[];
extern char D_004AC560[];
extern char D_004AC570[];
extern char D_004AC580[];
extern char D_004AC590[];
extern char D_004AC5A0[];
extern char D_004AC5B0[];
}
extern "C" void GuiEquipmentModify_onAdd(Screen* arg0) {
    Widget *var_s2;
    char *temp_s2;
    char *var_a0;
    Widget *temp_v1;
    Widget *temp_v1_2;
    Widget *temp_v1_3;
    Widget *temp_v1_4;
    Widget *temp_v1_5;
    Widget *temp_v1_6;
    Widget *temp_v1_7;
    Widget *temp_v1_8;
    Widget *var_s0;
    Widget *var_s1;
    Widget *var_s1_10;
    Widget *var_s1_11;
    Widget *var_s1_12;
    Widget *var_s1_13;
    Widget *var_s1_2;
    Widget *var_s1_3;
    Widget *var_s1_4;
    Widget *var_s1_5;
    Widget *var_s1_6;
    Widget *var_s1_7;
    Widget *var_s1_8;
    Widget *var_s1_9;
    Widget *var_s2_2;
    char *temp_s1;

    GuiWidget_onAdd();
    D_0051EE10 = arg0;
    var_s1 = (Widget*)GuiFindAs(arg0, D_004AC4A0, D_004A9BF0);
    if (var_s1 != 0) {
        var_s1->unk48 = (void*)&EM_ManRenderWrapper;
    }
    var_s1_2 = (Widget*)GuiFindAs(arg0, D_004AC4B0, D_004A9BF0);
    arg0->unkD0 = var_s1_2;
    temp_v1 = arg0->unkD0;
    if (temp_v1 != 0) {
        temp_v1->unk48 = (void*)&EM_Gun1RenderWrapper;
    }
    var_s1_3 = (Widget*)GuiFindAs(arg0, D_004AC4C0, D_004A9BF0);
    arg0->unkD4 = var_s1_3;
    temp_v1_2 = arg0->unkD4;
    if (temp_v1_2 != 0) {
        temp_v1_2->unk48 = (void*)&EM_Gun2RenderWrapper;
    }
    var_s1_4 = (Widget*)GuiFindAs(arg0, D_004AC4D0, D_004AA640);
    arg0->unk94 = var_s1_4;
    arg0->unk98 = (int) arg0->unk94->unk34;
    arg0->unk9C = (int) arg0->unk94->unk38;
    arg0->unkA4 = (int) arg0->unk94->unk5C;
    arg0->unkA8 = (int) ((arg0->unk94->unk40 / (float) arg0->unkA4) - 1.0f);
    arg0->unkCC = (Widget*)GuiWidget_FindChild_charP(arg0, D_004AC4E0);
    temp_v1_3 = arg0->unkCC;
    temp_v1_3->unk14 = (unsigned short) (temp_v1_3->unk14 & 0xFF7F);
    temp_v1_4 = arg0->unk94;
    temp_v1_4->unk14 = (unsigned short) (temp_v1_4->unk14 & 0xFF7F);
    var_s2 = (Widget*)GuiFindAs(arg0, D_004AC4F8, D_004A7520);
    var_s1_5 = (Widget*)GuiFindAs(arg0, D_004AC508, D_004A7520);
    if (cHuman_GetAgentData(arg0->unk48)->unkB70 != 0) {
        GuiTextWidget_SetText(var_s2, cAgentData_GetUserName(cHuman_GetAgentData(arg0->unk48)), 0);
        GuiTextWidget_SetText(var_s1_5, AgentData_GetRankText(cHuman_GetAgentData(arg0->unk48)), 0);
    } else {
        GuiTextWidget_SetText(var_s2, D_004AC518, 0);
        GuiTextWidget_SetText(var_s1_5, nGlobalization_GetString_int(nGlobalization_GetStringIndex(D_004AC520) + 1), 0);
    }
    if (D_004FFC04->unk251 != 0) {
        var_s1_6 = (Widget*)GuiFindAs(arg0, D_004AC340, D_004A9870);
        var_s1_6->unk14 = (unsigned short) (var_s1_6->unk14 & 0xFFFB);
        var_s1_7 = (Widget*)GuiFindAs(arg0, D_004AC2F0, D_004A9870);
        var_s1_7->unk14 = (unsigned short) (var_s1_7->unk14 & 0xFFFB);
        var_s1_8 = (Widget*)GuiFindAs(arg0, D_004AC300, D_004A9870);
        var_s1_8->unk14 = (unsigned short) (var_s1_8->unk14 & 0xFFFB);
        var_s1_9 = (Widget*)GuiFindAs(arg0, D_004AC310, D_004A9870);
        var_s1_9->unk14 = (unsigned short) (var_s1_9->unk14 & 0xFFFB);
        var_s1_10 = (Widget*)GuiFindAs(arg0, D_004AC320, D_004A9870);
        var_s1_10->unk14 = (unsigned short) (var_s1_10->unk14 & 0xFFFB);
        var_s1_11 = (Widget*)GuiFindAs(arg0, D_004AC330, D_004A9870);
        var_s1_11->unk14 = (unsigned short) (var_s1_11->unk14 & 0xFFFB);
        GuiTextListWidget_Clear(arg0->unk94);
        temp_v1_5 = arg0->unk94;
        temp_v1_5->unk14 = (unsigned short) (temp_v1_5->unk14 & 0xFF7F);
        temp_v1_6 = arg0->unkCC;
        temp_v1_6->unk14 = (unsigned short) (temp_v1_6->unk14 & 0xFF7F);
        temp_v1_7 = arg0->unkCC;
        temp_v1_7->unk14 = (unsigned short) (temp_v1_7->unk14 & 0xFFFD);
    }
    temp_s2 = nGlobalization_GetString_charP(D_004AC530);
    var_s1_12 = (Widget*)GuiFindAs(arg0, D_004AC540, D_004A7520);
    if ((temp_s2 != 0) && (var_s1_12 != 0)) {
        GuiTextWidget_SetText(var_s1_12, temp_s2, 0);
    }
    temp_s1 = nGlobalization_GetString_charP(D_004AC550);
    var_s2_2 = (Widget*)GuiFindAs(arg0, D_004AC560, D_004A7520);
    if ((temp_s1 != 0) && (var_s2_2 != 0)) {
        GuiTextWidget_SetText(var_s2_2, temp_s1, 0);
    }
    var_s1_13 = (Widget*)GuiFindAs(arg0, D_004AC570, D_004A7520);
    arg0->unk958 = var_s1_13;
    arg0->unk95C = nGlobalization_GetString_charP(D_004AC580);
    if (arg0->unk95C == 0) {
        arg0->unk95C = D_0048BA80;
    }
    if ((D_00506508 == 0) || (g_IsMultiplayer == 0)) {
        temp_v1_8 = arg0->unk958;
        if (temp_v1_8 != 0) {
            temp_v1_8->unk14 = (unsigned short) (temp_v1_8->unk14 & 0xFFFD);
        }
    }
    var_s0 = (Widget*)GuiFindAs(arg0, D_004AC590, D_004A7520);
    if (var_s0 != 0) {
        if (g_IsMultiplayer != 0) {
            var_a0 = D_004AC5A0;
        } else {
            var_a0 = D_004AC5B0;
        }
        GuiTextWidget_SetText(var_s0, nGlobalization_GetString_charP(var_a0), 0);
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002C0790(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002C0790 */

/* merge_units: begin func_002C0F00 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
struct V002C0F00 { virtual void v0(int f); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual void v22(int f); char pad4[0x2420 - 4]; short h2420; char pad2422[0x2C74 - 0x2422]; int x2C74; };
struct O002C0F00 { void* vt; char pad[0x48]; V002C0F00* p4C; V002C0F00* p50; };
extern "C" {

extern char g_AgentPartCache[];
extern char D_004DDEE0[];
extern char D_004E1220[];
extern int D_00506500;
void Monster_RestoreLockedPartsTex(void* p);
void cMotionManager_FlushUpdateList(void);
void GuiEquipmentModify_EmptyQue(void* p);
void GuiWidget_dtor(void* p, int f);
void operator_delete(void* p);
}
static inline void Del002C0F00(V002C0F00* o, int line)
{
    AllocGuard g;
    o->v0(-1);
    cMemMan_Deallocate(0, o, "GuiEquipmentModify.cc", line);
}
extern "C" O002C0F00* GuiEquipmentModify_dtor(O002C0F00* self, short del)
{
    if (self) {
        int i;
        self->vt = D_004DDEE0;
        GuiEquipmentModify_EmptyQue(self);
        Del002C0F00(self->p50, 0x169);
        self->p4C->h2420 = 0;
        self->p4C->x2C74 = 0;
        self->p4C->v22(1);
        Del002C0F00(self->p4C, 0x16D);
        GuiWidget_dtor(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002C0F00(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002C0F00 */

/* merge_units: begin func_002C10A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

/* Derived destructor: restore vtable, run cGOBJ base destructor, optionally delete. */
DEFINE_VTABLE_BASE_DTOR(func_002C10A0, D_004DA470, cGOBJ_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_002C10A0 */

/* merge_units: begin func_002C1100 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
#pragma inline_depth(10)
#pragma opt_loop_invariants off
#pragma opt_propagation off
#pragma opt_dead_assignments off
#pragma opt_common_subs on
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
#pragma opt_unroll_loops off

typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_1100;
struct M4_1100 { float m[4][4]; } __attribute__((aligned(16)));
struct M4Q_1100 { __int128 r[4]; };
static inline void MK_1100(V4_1100* t0, float x0, float y0, float z0, float w0) { V4_1100* t = t0; float x = x0, y = y0, z = z0, w = w0; t->x = x; t->y = y; t->z = z; t->w = w; }
static inline void MK3_1100(V4_1100* t0, float x0, float y0, float z0) { V4_1100* t = t0; float x = x0, y = y0, z = z0; t->x = x; t->y = y; t->z = z; }
static inline void QAsgB_1100(void* d0, const void* s0) { void* d = d0; const void* s = s0; __int128 t; __asm__ volatile("lq %0, 0x0(%1)" : "=r"(t) : "r"(s) : "memory"); __asm__ volatile("sq %0, 0x0(%1)" : : "r"(t), "r"(d) : "memory"); }
static inline void QAsgA_1100(void* d0, const void* s0) { void* d = d0; const void* s = s0; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
static inline void M4Cp_1100(M4Q_1100* d0, const M4Q_1100* s0) { M4Q_1100* d = d0; __int128 qa, qb; const M4Q_1100* s = s0; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
struct Sph_1100 { char pad[0x20]; };
struct SVec_1100 { char pad[0x10]; };
struct Word_1100 { int w; };
struct H_1100 { char pad[0xC]; int serial; };
struct Blk_1100 { char d[0x440]; };
struct Wpn_1100 { char pad[0x40A]; short id; };
struct WDef_1100 { char pad[0x30]; unsigned char b30; };
struct Tab_1100 { void* p; char pad[0xC]; };

class Xf_1100 {
public:
    VPAD2(a) virtual void SetMtx(M4_1100* m);
};

struct Anim_1100 {
    void* f0;
    char pad4;
    unsigned char b5;
    char pad6[2];
    char v8[0x10];
};

struct Man_1100 {
    char pad0[0x40];
    char app[0x30];
    char name[0x10];
    char pad80[0x23F0 - 0x80];
    float f23F0;
    float f23F4;
    char pad23F8[0x2410 - 0x23F8];
    Wpn_1100* wpn[10];
    char pad2438[0x2BD0 - 0x2438];
    int f2BD0;
    char pad2BD4[0x2C04 - 0x2BD4];
    void* f2C04;
    char pad2C08[0x2C11 - 0x2C08];
    unsigned char b2C11;
    char pad2C12[0x2D70 - 0x2C12];
    H_1100* f2D70;
    int f2D74;
    char pad2D78[8];
    V4_1100 pos;
    char pad2D90[4];
    short s2D94;
    char pad2D96[0xA];
    unsigned char b2DA0;
};

class Model_1100 {
public:
    VPAD8(a) VPAD4(b) VPAD2(c) virtual void SetMtx(M4_1100* m);
    VPAD4(d) VPAD2(e) virtual void Init(int a);
    char pad4[0x4C];
    Xf_1100* xf;
    char pad54[0xC];
    Man_1100 man;
};

#define MAN(p) (&(p)->man)
static inline char* APP_1100(Man_1100* m) { return m->app; }
static inline char* NAME_1100(Man_1100* m) { return m->name; }
#define FLD(p, T, o) (*(T*)((char*)(p) + (o)))

struct Self_1100 {
    void* vt;
    char pad4[0x48 - 4];
    Model_1100* plr;
    Model_1100* model;
    void* gobj;
    char pad54[0xC];
    V4_1100 f60;
    V4_1100 f70;
    int f80;
    int f84;
    int f88;
    int f8C;
    int f90;
    char pad94[0xA8 - 0x94];
    int fA8;
    float fAC[7];
    char padC8[8];
    int fD0;
    int fD4;
    int fD8;
    short fDC[10];
    unsigned char fF0[12];
    int fFC;
    int f100;
    int f104;
    int f108;
    char pad10C[0x90C - 0x10C];
    short f90C[10];
    int f920;
    char pad924[0x958 - 0x924];
    int f958;
};

struct Arr7_1100 { char d[0x38]; };
struct Y_1100 { char d[0x10]; };
struct Sel_1100 { char b0; char pad[3]; Arr7_1100 arr; Y_1100 y; };
struct Str_1100 { char s[0x30]; };
struct Req_1100 {
    char b0;
    char pad1[0xF];
    char mr[0x38];
    char b48;
    char pad49[3];
    Sel_1100 sel;
    float f98;
    int f9C;
};
struct It_1100 { int w; };
struct Ev_1100 { char d[0x40]; };
struct Rate_1100 { char d[0x10]; };

extern "C" {
extern char D_004DA470[];
extern int D_0055DE94;
extern Tab_1100 D_0055DE98[];
extern signed char D_00493A60;
extern char D_004AC5C0[];
extern char D_004AC5D8[];
extern char D_004AC5E8[];
extern char D_004AC288[];
extern char D_004AC298[];
extern char D_004AC600[];
extern char D_004FFBC0[];
extern char g_IdentityMatrix[];
extern Blk_1100 D_0055D510[];
#if 0 /* merge_units */
extern void* D_00506500;
#endif /* merge_units */
#define D_00506500 (*(void **)&D_00506500) /* merge_units */

extern void* g_WeaponDatabase;
void GuiWidget_ctor(Self_1100* self);
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void cGOBJ_ctor(void* p, int* a, int b, int* c);
void cGOBJ_CreateXform(void* p, void* t, int a);
Model_1100* cSKM_GOBJ_ctor_cObjectIdR(void* p, int* idx);
float SIN(float a);
float COS(float a);
void cMatrix_Set_ColumnMajorForm(M4_1100* m, float a, float b, float c, float d, float e, float f, float g, float h, float i);
Model_1100* cNetObj_GetPlayer(void* a);
WDef_1100* cWeaponDB_GetEntry(void* db, int id);
int SKL_FindSex(void* app);
void cMan_AddDisguise(Man_1100* m, void* p);
void cSKM_GOBJ_CloneMan(Model_1100* m, Man_1100* src);
void cMan_SortParts(Man_1100* m);
void cSKM_GOBJ_ResetSkeleton(Model_1100* m, char* name);
void cArrayCapacity_ctor(Word_1100* w, int n);
void cArray_cSkeletonBBoxContributionPtr_ctor(SVec_1100* v, Word_1100* w, unsigned char f);
V4_1100* cVector_ctor_float_float_float_float(V4_1100* v, float x, float y, float z, float w);
void cSkeletonBBoxContribution_ctor(Sph_1100* s, int bone, float r, V4_1100* off);
void cArray_cSkeletonBBoxContributionPtr_PushBackActual(SVec_1100* v, Sph_1100** p);
void cSkeletonBBoxContribution_dtor(Sph_1100* s, int f);
void* cSKM_GOBJ_GetSkeleton_void_2(Model_1100* m);
void cSkeleton_ResetBBoxContributors(void* n, SVec_1100* v);
void cArray_cSkeletonBBoxContributionPtr_dtor(SVec_1100* v, int f);
void cAssocArray_cString_cSkaAnimationSetPtr_Find(It_1100* it, void* tab, char* key);
void cAssocArray_cString_cSkaAnimationSetPtr_End(It_1100* it, void* tab);
int cAssocArray_cString_cSkaAnimationSetPtr_Iterator_opNe(It_1100* a, It_1100* b);
void** cAssocArray_cString_cSkaAnimationSetPtr_Iterator_opMul(It_1100* it);
void cSkaParams_HandleNewAnimationSet(void* a, void* b);
void cSkaSystem_SetInitialAnimation(void* a);
void cArray_FixedSize_cSkaAnimEvent_7_ctor_void(Arr7_1100* a);
void cArray_cTimedEvent_ctor_void(Y_1100* y);
void cString16N_3_ctor_cString16NR(void* mr, Str_1100* s);
void cSkaAnimCheckpoints_ctor_cSkaAnimCheckpointsR(Sel_1100* d, Sel_1100* s);
void func_001BE5A0(Y_1100* y, int f);
void __destroy_array(void* a, void* dtor, int size, int n);
void func_0018A210(void* p, int f);
void cSkaPlaybackGroupId_ctor_int(Word_1100* w, int a);
void cSkaRequestStream_AnimationPacket_GetAnimationAndPlaybackGroupId(Req_1100* r, int* sel, Word_1100* w, void* m);
float cSkaAnimationSet_DefaultCrossFadeDuration(void* m);
V4_1100* cSkaCrossFadeDuration_ctor_float(Rate_1100* r, float f);
}
static inline V4_1100* Splat_1100(V4_1100* t, float) { float z = 0.0f; return cVector_ctor_float_float_float_float(t, z, z, z, z); }
extern "C" {
void cSkaCrossFadeDuration_ctor_cSkaCrossFadeDurationR(Rate_1100* d, V4_1100* s);
void cSkaAnimEndedMessage_ctor_void(Ev_1100* e);
int cSkaRequestStream_AnimationPacket_GetInstruction(Req_1100* r);
int cSkaRequestStream_AnimationPacket_GetAnimCheckpoints(Req_1100* r);
float cSkaRequestStream_AnimationPacket_GetDuration(Req_1100* r);
float func_0018A2C0(Req_1100* r);
void cSkaRequestStream_AddRequest(Anim_1100* a, int sel, int b, Rate_1100* r, Word_1100* w, Ev_1100* e0, Ev_1100* e1, int c, float f0, float f1);
void cSkaAnimEndedMessage_dtor(Ev_1100* e, int f);
void cMan_SetGunOffsets(Man_1100* m);
void cMan_GetTextureIDs(Man_1100* m);
void cMan_BuildMan(Man_1100* m, int flag);
void cMan_SetBoneSet(Man_1100* m, int a);
Self_1100* GuiEquipmentModify_ctor(Self_1100* self);
}

static inline void QCopy_1100(void* d0, void* s0, int n0) { int n = n0; void* d = d0; void* s = s0;
    asm {
        .set noreorder
    loop:
        lq $v0, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, loop
        sq $v0, -0x10(d)
        .set reorder
    }
}
static inline void G_1100(void* p, int a, int n, int b) { int* pa = &a; cGOBJ_ctor(p, pa, n, &b); }
static inline Model_1100* M_1100(void* p, int x) { return cSKM_GOBJ_ctor_cObjectIdR(p, &x); }
struct V4C_1100 { float x, y, z, w; V4C_1100(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; } V4C_1100(float a, float b, float c) { x = a; y = b; z = c; } } __attribute__((aligned(16)));
static inline void MKd_1100(V4_1100* t, float x, float y, float z, float w) { t->x = x; t->y = y; t->z = z; t->w = w; }
static inline void MKd3_1100(V4_1100* t, float x, float y, float z) { t->x = x; t->y = y; t->z = z; }
static inline void Q3_1100(void* a0, const void* b0, void* c0, float z) { void* d1 = a0; const void* s1 = b0; void* d2 = c0; __int128 q = 0; q = *(const __int128*)s1; *(__int128*)d1 = q; { V4C_1100 r(0.0f, 0.0f, z); const void* s2 = &r; q = *(const __int128*)s2; *(__int128*)d2 = q; } }
static inline Man_1100* ManA_1100(Model_1100* md) { return &md->man; }
static inline Wpn_1100* GetW_1100(Man_1100* m, int o) { return *(Wpn_1100**)((char*)m->wpn + o); }
struct V4R_1100 { float x, y, z, w; V4R_1100(const float& a, const float& b, const float& c, const float& d) { x = a; y = b; z = c; w = d; } V4R_1100(const float& a, const float& b, const float& c) { x = a; y = b; z = c; } } __attribute__((aligned(16)));
static inline void* Alloc_1100(int n, int line) { AllocGuard g; return cMemMan_Allocate(0, n, D_004AC5C0, line); }

static inline void SelInit_1100(Sel_1100* s0) { Sel_1100* s = s0; s->b0 = 0; cArray_FixedSize_cSkaAnimEvent_7_ctor_void(&s->arr); cArray_cTimedEvent_ctor_void(&s->y); }
static inline void ReqInit2_1100(Req_1100* r0, Str_1100* str0, Sel_1100* sel) { Str_1100* str = str0; Req_1100* r = r0; r->b0 = 0; cString16N_3_ctor_cString16NR(r->mr, str); r->b48 = 3; cSkaAnimCheckpoints_ctor_cSkaAnimCheckpointsR(&r->sel, sel); r->f98 = -1.0f; r->f9C = 0; }
static inline void Spheres_1100(Model_1100* md)
{
            Word_1100 w;
            {
            SVec_1100 vec;
            Sph_1100 arr[12];
            V4_1100 t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11;
            int k;
            cArrayCapacity_ctor(&w, 0x15);
            cArray_cSkeletonBBoxContributionPtr_ctor(&vec, &w, 1);
            cSkeletonBBoxContribution_ctor(&arr[0], 0, 0.75f, Splat_1100(&t0, 0.0f));
            cSkeletonBBoxContribution_ctor(&arr[1], 4, 0.41666666f, Splat_1100(&t1, 0.0f));
            cSkeletonBBoxContribution_ctor(&arr[2], 6, 0.41666666f, Splat_1100(&t2, 0.0f));
            cSkeletonBBoxContribution_ctor(&arr[3], 0xC, 0.75f, Splat_1100(&t3, 0.0f));
            cSkeletonBBoxContribution_ctor(&arr[4], 0x10, 0.75f, Splat_1100(&t4, 0.0f));
            cSkeletonBBoxContribution_ctor(&arr[5], 0xE, 1.0f, Splat_1100(&t5, 0.0f));
            cSkeletonBBoxContribution_ctor(&arr[6], 0xD, 0.33333334f, Splat_1100(&t6, 0.0f));
            cSkeletonBBoxContribution_ctor(&arr[7], 0xF, 0.33333334f, Splat_1100(&t7, 0.0f));
            cSkeletonBBoxContribution_ctor(&arr[8], 0x11, 0.33333334f, Splat_1100(&t8, 0.0f));
            cSkeletonBBoxContribution_ctor(&arr[9], 0x12, 0.33333334f, Splat_1100(&t9, 0.0f));
            cSkeletonBBoxContribution_ctor(&arr[10], 0x13, 0.6666667f, Splat_1100(&t10, 0.0f));
            cSkeletonBBoxContribution_ctor(&arr[11], 0x14, 0.6666667f, Splat_1100(&t11, 0.0f));
            for (k = 0; k < 12; k++) {
Sph_1100* sp; Sph_1100** pp = &sp; sp = &arr[k]; cArray_cSkeletonBBoxContributionPtr_PushBackActual(&vec, pp);
            }
            cSkeletonBBoxContribution_dtor(&arr[11], -1);
            cSkeletonBBoxContribution_dtor(&arr[10], -1);
            cSkeletonBBoxContribution_dtor(&arr[9], -1);
            cSkeletonBBoxContribution_dtor(&arr[8], -1);
            cSkeletonBBoxContribution_dtor(&arr[7], -1);
            cSkeletonBBoxContribution_dtor(&arr[6], -1);
            cSkeletonBBoxContribution_dtor(&arr[5], -1);
            cSkeletonBBoxContribution_dtor(&arr[4], -1);
            cSkeletonBBoxContribution_dtor(&arr[3], -1);
            cSkeletonBBoxContribution_dtor(&arr[2], -1);
            cSkeletonBBoxContribution_dtor(&arr[1], -1);
            cSkeletonBBoxContribution_dtor(&arr[0], -1);
            cSkeleton_ResetBBoxContributors(cSKM_GOBJ_GetSkeleton_void_2(md), &vec);
            cArray_cSkeletonBBoxContributionPtr_dtor(&vec, -1);
            }
}
static inline void Install_1100(Anim_1100* an, int* selp, Req_1100* rq, Word_1100* wp)
{
                Rate_1100 rate;
                Rate_1100 tmp;
                Ev_1100 e0;
                Ev_1100 e1;
                V4_1100* v;
                if (an->b5) v = (V4_1100*)an->v8;
                else { v = cSkaCrossFadeDuration_ctor_float(&tmp, cSkaAnimationSet_DefaultCrossFadeDuration(an->f0)); asm { .set reorder } }
                cSkaCrossFadeDuration_ctor_cSkaCrossFadeDurationR(&rate, v);
                an->b5 = 0;
                cSkaAnimEndedMessage_ctor_void(&e0);
                cSkaAnimEndedMessage_ctor_void(&e1);
                cSkaRequestStream_AddRequest(an, *selp, cSkaRequestStream_AnimationPacket_GetInstruction(rq), &rate, wp, &e0, &e1, cSkaRequestStream_AnimationPacket_GetAnimCheckpoints(rq), cSkaRequestStream_AnimationPacket_GetDuration(rq), func_0018A2C0(rq));
                cSkaAnimEndedMessage_dtor(&e1, -1);
                cSkaAnimEndedMessage_dtor(&e0, -1);
}
static inline void FindAnim_1100(Self_1100* self, int kind)
{
            It_1100 it;
            It_1100 end;
            void* a;
            char* nm;
            if (kind == 1) nm = D_004AC298; else { nm = D_004AC288; asm { .set reorder } }
            cAssocArray_cString_cSkaAnimationSetPtr_Find(&it, D_004FFBC0, nm);
            cAssocArray_cString_cSkaAnimationSetPtr_End(&end, D_004FFBC0);
            if (cAssocArray_cString_cSkaAnimationSetPtr_Iterator_opNe(&it, &end)) a = *cAssocArray_cString_cSkaAnimationSetPtr_Iterator_opMul(&it);
            else { a = 0; asm { .set reorder } }
            {
                void** an = (void**)((char*)self->model + 0x2EC0);
                cSkaParams_HandleNewAnimationSet(an + 4, a);
                *an = a;
                cSkaSystem_SetInitialAnimation(an);
            }
        }

static inline void Motion_1100(Model_1100* md, Req_1100* rq)
{
            char* c = (char*)md + 0x2EC0;
            Anim_1100* an = (Anim_1100*)(c + 0x34);
            int sel;
            Word_1100 w[3];
            cSkaPlaybackGroupId_ctor_int(w, -1);
            cSkaRequestStream_AnimationPacket_GetAnimationAndPlaybackGroupId(rq, &sel, w, an->f0);
            if (sel) {
                Install_1100(an, &sel, rq, w);
            }
        }

static inline void SetF_1100(Model_1100* md, float v) { FLD(md, float, 0x2450) = v; }
static inline int& Neg1_1100(int& d) { d = -1; return d; }
static inline int& Ser_1100(H_1100* o, int& d) { return *(o ? &o->serial : &Neg1_1100(d)); }
static inline void F_1100(Self_1100* self, M4_1100* mtx, Req_1100* req)
{
    int kind;
        {
            Model_1100* m = self->model;
            m->man.f2C04 = (char*)m + 0x2E50;
        }
        self->model->SetMtx(mtx);
        {
            Xf_1100* xf = self->model->xf;
            M4_1100 rot;
            float s = SIN(0.0f);
            float c = COS(0.0f);
            { M4_1100* pr = &rot; float z = 0.0f; cMatrix_Set_ColumnMajorForm(pr, c, -s, z, s, c, z, z, z, 1.0f); }
            { M4_1100* pr = &rot; xf->SetMtx(pr); }
        }
        self->fFC = 0;
        self->plr = cNetObj_GetPlayer(D_00506500);
        Model_1100* pl;
        if ((pl = self->plr) != 0) {
            Wpn_1100* w = pl->man.wpn[0];
            if (w) {
                int n = cWeaponDB_GetEntry(g_WeaponDatabase, w->id)->b30;
                if (n > 0 && n < 10) self->fFC = n;
            }
            if (!g_IsMultiplayer && D_0055DE94) {
                void* a = D_0055DE98[SKL_FindSex(APP_1100(MAN(self->plr)))].p;
                if (a) cMan_AddDisguise(MAN(self->plr), a);
            }
            cSKM_GOBJ_CloneMan(self->model, MAN(self->plr));
        } else {
            { int n = 0x44; int i = D_00493A60; Model_1100* m = self->model; QCopy_1100(APP_1100(MAN(m)), &D_0055D510[i], n); }
            if (!g_IsMultiplayer && D_0055DE94) {
                void* a = D_0055DE98[SKL_FindSex(APP_1100(MAN(self->model)))].p;
                if (a) cMan_AddDisguise(MAN(self->model), a);
            }
        }
        self->f100 = self->fFC;
        cMan_SortParts(MAN(self->model));
        kind = SKL_FindSex(APP_1100(MAN(self->model)));
        {
            char* nm; if (kind == 0) nm = D_004AC5D8; else { nm = D_004AC5E8; asm { .set reorder } }
            cSKM_GOBJ_ResetSkeleton(self->model, nm);
            Libc_Strcpy(NAME_1100(MAN(self->model)), nm);
        }
        self->model->Init(1);
        {
            Spheres_1100(self->model);
        }
        FindAnim_1100(self, kind);
        {
            Str_1100 str;
            Sel_1100 sel;
            SelInit_1100(&sel);
            {
                bool done;
                int k;
                char c;
                const char* src;
                done = false;
                k = 0;
                src = D_004AC600;
                for (; k < 0x2F; k++) {
                    if (!src[k]) done = true;
                    c = 0; if (done) asm { .set reorder } else c = src[k];
                    str.s[k] = c;
                }
                str.s[k] = 0;
            }
            ReqInit2_1100(req, &str, &sel);
            func_001BE5A0(&sel.y, 0);
            __destroy_array(&sel.arr, (void*)func_0018A210, 8, 7);
        }
        Motion_1100(self->model, req);
        {
            Y_1100* y = &req->sel.y;
            if (y) { if (y) { if (y) func_001BE5A0(y, 0); } }
        }
        {
            Arr7_1100* a = &req->sel.arr;
            if (a) __destroy_array(a, (void*)func_0018A210, 8, 7);
        }
    SetF_1100(self->model, 1.0f);
    FLD(self->model, float, 0x2454) = 0.0f;
    cMan_SetGunOffsets(MAN(self->model));
    {
        V4_1100 v;
        Man_1100* m;
        v.x = 0.0f; v.y = 30.0f; v.z = 0.0f; v.w = 1.0f;
        { Model_1100* md = self->model; FLD(md, H_1100*, 0x2DD0) = 0; m = MAN(md); }
        {
            int d;
            H_1100* o = 0;
            FLD(m, int, 0x2D74) = Ser_1100(0, d);
        }
        { QAsgB_1100(&FLD(m, V4_1100, 0x2D80), &v); FLD(m, float, 0x2D8C) = 1.0f; }
    }
    { Man_1100* mm = MAN(self->model); FLD(mm, unsigned char, 0x2DA0) = 1; }
}

static inline void SetI_1100(Model_1100* md, int v) { FLD(md, int, 0x2C30) = v; }
static inline void SetS_1100(Model_1100* md, short v) { FLD(md, short, 0x2DF4) = v; }
static inline void SetB_1100(Model_1100* md, unsigned char v) { FLD(md, unsigned char, 0x2C71) = v; }
extern "C" Self_1100* GuiEquipmentModify_ctor(Self_1100* p0)
{
    Self_1100* self = p0;
    int i;
    int x;
    GuiWidget_ctor(p0);
    self->vt = D_004DDEE0;
    self->f84 = -1;
    self->f90 = 0;
    self->f88 = 2;
    self->f80 = D_0055DE94;
    {
        void* p;
        p = Alloc_1100(0x68, 0xC6);
        if (p) {
            G_1100(p, 0, 9, 0);
            *(char**)p = D_004DA470;
            ((int*)p)[0x60 / 4] = 0;
            ((int*)p)[0x64 / 4] = 0;
            cGOBJ_CreateXform(p, g_IdentityMatrix, 0);
            ((int*)p)[0x30 / 4] = 0;
        }
        self->gobj = p;
    }
    {
        M4_1100 mtx;
        Req_1100 req;
        {
            M4_1100 t;
            float one = 1.0f; float tz = -3.25f;
            t.m[0][0] = one; t.m[0][1] = 0.0f; t.m[0][2] = 0.0f; t.m[0][3] = 0.0f;
            t.m[1][0] = 0.0f; t.m[1][1] = one; t.m[1][2] = 0.0f; t.m[1][3] = 0.0f;
            t.m[2][0] = 0.0f; t.m[2][1] = 0.0f; t.m[2][2] = one; t.m[2][3] = 0.0f;
            t.m[3][0] = 0.0f; t.m[3][1] = 0.0f; t.m[3][2] = tz; t.m[3][3] = one;
            M4Cp_1100((M4Q_1100*)&mtx, (M4Q_1100*)&t);
        }
        float pa = 3.1415927f; float pb = 3.1415927f;
        {
            V4C_1100 r1(0.0f, 0.0f, pa, 0.0f);
            Q3_1100(&self->f60, &r1, &self->f70, pb);
        }
        {
            Model_1100* p;
            p = (Model_1100*)Alloc_1100(0x3030, 0xCD);
            if (p) {
                x = 0;
                p = cSKM_GOBJ_ctor_cObjectIdR(p, &x);
            }
            self->model = p;
        }
        F_1100(self, &mtx, &req);
    cMan_GetTextureIDs(MAN(self->model));
    SetI_1100(self->model, 1);
    cMan_BuildMan(MAN(self->model), 1);
    cMan_SetBoneSet(MAN(self->model), -1);
    SetS_1100(self->model, 0);
    SetB_1100(self->model, 1);
    self->fD8 = 0;
    for (i = 0; i < 10; i++) {
        int o;
        Wpn_1100* w;
        o = i * 4;
        w = GetW_1100(ManA_1100(self->model), o);
        if (w) {
            self->fDC[self->fD8] = w->id;
            self->fF0[self->fD8] = cWeaponDB_GetEntry(g_WeaponDatabase, GetW_1100(ManA_1100(self->model), o)->id)->b30;
            self->fD8++;
        }
    }
    self->fD0 = 0;
    self->fD4 = 0;
    self->f104 = 0;
    self->f108 = 0;
    self->f8C = 0;
    { int j; for (j = 0; j < 10; j++) self->f90C[j] = 0; }
    {
    float pi = 3.1415927f;
    self->fAC[0] = pi;
    self->fAC[1] = 6.2831855f;
    self->fAC[2] = 4.712389f;
    self->fAC[3] = pi;
    self->fAC[4] = pi;
    self->fAC[5] = pi;
    self->fAC[6] = pi;
    }
    self->f920 = 0;
    self->fA8 = 0xC;
    self->f958 = 0;
    }
    return self;
}
#undef D_00506500 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002C1100(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002C1100 */
