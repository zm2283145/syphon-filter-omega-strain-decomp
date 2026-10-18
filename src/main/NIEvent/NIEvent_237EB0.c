/*
 * main/NIEvent: range (3 files, 00237EB0-00238780)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"
#include "vc_copy.h"
#include "net_local_id.h"

/* merge_units: begin func_00237EB0 */
#pragma push /* merge_units */
typedef struct {
    float value;
    int pad4;
    int count;
    float* keys;
    int pad10;
    int pad14;
    int time;
    unsigned char active;
    char pad1D[3];
} LightTrack237EB0;

typedef struct {
    char pad0[0x24];
    int kind;
} LightEv237EB0;

typedef struct {
    char pad0[0x170];
    LightTrack237EB0 a;
    LightTrack237EB0 b;
} LightObj237EB0;

extern int* Event_GetType(LightEv237EB0* ev);
extern int D_004F7C28;
extern void NiEvent_HandlePlayMsg(LightObj237EB0* self, LightEv237EB0* ev);

static inline void LightTrack_Rewind(LightTrack237EB0* t) {
    t->time = 0;
    if (t->count > 0) {
        t->value = t->keys[1];
    }
}

void cNIEventLight_v01(LightObj237EB0* self, LightEv237EB0* ev) {
    int t = *Event_GetType(ev);
    if (t == D_004F7C28) {
        switch (ev->kind) {
        case 0:
            self->a.active = 1;
            self->b.active = 1;
            break;
        case 2:
            LightTrack_Rewind(&self->a);
            LightTrack_Rewind(&self->b);
            break;
        }
    }
    NiEvent_HandlePlayMsg(self, ev);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00237EB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00237EB0 */

/* merge_units: begin func_00237F80 */
#pragma push /* merge_units */
#pragma opt_rotateloops off
#pragma opt_dead_assignments off
#pragma opt_unroll_loops off
#pragma opt_strength_reduction off
#pragma cplusplus on
#pragma inline_depth(10)
extern "C" {}
struct V4_7F80 { float x, y, z, w; V4_7F80() {} } __attribute__((aligned(16)));
struct V4P_7F80 { float x, y, z, w; } __attribute__((aligned(16)));
struct Mat_7F80 { V4P_7F80 r[4]; };
struct E64_7F80 { float a; float pad4[3]; V4_7F80 pos; float b[4]; float c[4]; };
struct E8_7F80 { float t; unsigned char on; };
struct V64_7F80 { int cap; int count; E64_7F80* data; };
struct V8_7F80 { int cap; int count; E8_7F80* data; E8_7F80& operator[](int i) { return data[i]; } };
struct OwnedVec_7F80 { int w[4]; };
struct Track_7F80 { float cur; OwnedVec_7F80 vec; char pad14[0xC]; void Init(); };
struct Reader_7F80 { int version; int a, b; char* cur; };
struct Light_7F80 {
    VPAD16(a) VPAD4(b) VPAD2(c)
    virtual void v60(int on, V4_7F80* pos);   /* +0x60 */
    VPAD8(d) VPAD2(e) VPAD1(f)
    virtual void SetFrame(Mat_7F80* m, int f); /* +0x90 */
    VPAD32(g) VPAD8(h)
    virtual void v134(float t);              /* +0x134 */
    char pad4[8];
    int idC;
    int id10;
    char pad14[0x4C];
    int f60;
    char pad64[0x30];
    int f94;
    char pad98[0x14];
    V64_7F80 keys;
    int fB8;
    int fBC;
    int fC0;
    V8_7F80 flags;
    int fD0;
    int fD4;
    int fD8;
    unsigned char bDC;
    char padDD[3];
    V4_7F80 posE0;
    Mat_7F80 mF0;
    unsigned char b130;
    char pad131[0xF];
    int f140;
    float f144;
    float f148;
    float f14C;
    unsigned char b150;
    unsigned char b151;
    char pad152[2];
    float f154;
    float f158;
    int pad15C;
    float f160;
    float f164;
    float f168;
    float f16C;
    Track_7F80 t170;
    Track_7F80 t190;
};
extern "C" {
extern char D_004F7C98[];
extern char D_004DBED0[];
void func_0023F350(Light_7F80* self, int kind, void* info);
void func_00238940(OwnedVec_7F80* v);
void NetMap_BindReceiver(int id, int owner, Light_7F80* o);
void NiEvent_ReadKeyedTrack4(Track_7F80* t, Reader_7F80* r);
void NiEvent_ReadFloatTrack(Track_7F80* t, float v);
void func_002401C0(V64_7F80* v, int n, const E64_7F80& fill);
static inline void Assign64_7F80(V64_7F80* v, int n, const E64_7F80& fill) { E64_7F80 t; func_002401C0(v, 0, t); func_002401C0(v, n, fill); }
void func_00240230(V8_7F80* v, int n, const E8_7F80& fill);
static inline void Resize8_7F80(V8_7F80* v, int n, const E8_7F80& f = E8_7F80()) { func_00240230(v, n, f); }
static inline void Assign8_7F80(V8_7F80* v, int n, const E8_7F80& fill) { Resize8_7F80(v, 0); Resize8_7F80(v, n, fill); }
int IdMgr_FindCollision(int region, int id);
void ZoneMgr_Associate(int found, Light_7F80* o, int a, int b);
void Node_ClearLocalMatrix(Light_7F80* o);
}
static inline int RdI_7F80(Reader_7F80* r) { int t = *(int*)r->cur; r->cur += 4; return t; }
static inline float RdF_7F80(Reader_7F80* r) { float t = *(float*)r->cur; r->cur += 4; return t; }
static inline void ReadF_7F80(Reader_7F80* r, float* out) { *out = *(float*)r->cur; r->cur += 4; }
static inline void ReadId_7F80(Reader_7F80* r, int* out)
{
    int hi = RdI_7F80(r);
    int lo = RdI_7F80(r);
    *out = lo | (hi << 16);
}
static inline void Align_7F80(Reader_7F80* r)
{
    int rem;
    char* ptr = r->cur;
    rem = (int)((unsigned long long)(unsigned int)ptr & 3);
    if (rem) r->cur = ptr + (4 - rem);
}
inline void Track_7F80::Init() { Track_7F80* t = this; func_00238940(&t->vec); }
static inline void VCX_7F80(void* d0, const void* s0) { const void* s = s0; void* d = d0; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
static inline E8_7F80* Fl_7F80(V8_7F80* v) { E8_7F80** pd = &v->data; return *pd; }
static inline void MC2_7F80(void* d, const void* s) {
    __int128 qa, qb;
    __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory");
}
extern "C" Light_7F80* cNIEventLight_ctor(Light_7F80* self, Reader_7F80* r)
{
    volatile int id;
    int n;
    int i;
    func_0023F350(self, 0x11, D_004F7C98);
    *(void**)self = D_004DBED0;
    self->t170.Init();
    self->t190.Init();
    self->f60 = 7;
    ReadId_7F80(r, (int*)&id);
    self->idC = id;
    if (D_005721C8) {
        self->id10 = self->idC;
        {
            int t = self->id10;
            int a = D_005721A8; int rr = 0;
            if (*(volatile unsigned char*)&D_005721C8) { if (D_00494178 == -1) NetGame_InitLocalSlot(&D_00494178, a); rr = D_00494178; } else { asm { .set reorder } }
            NetMap_BindReceiver(t, rr, self);
        }
    }
    if (r->version >= 0x46) {
        NiEvent_ReadKeyedTrack4(&self->t170, r);
        NiEvent_ReadKeyedTrack4(&self->t190, r);
    } else {
        float a = RdF_7F80(r);
        float b = RdF_7F80(r);
        NiEvent_ReadFloatTrack(&self->t170, a);
        NiEvent_ReadFloatTrack(&self->t190, b);
    }
    ReadF_7F80(r, &self->f144);
    ReadF_7F80(r, &self->f148);
    ReadF_7F80(r, &self->f14C);
    if (r->version >= 0x42) {
        self->b151 = *(unsigned char*)r->cur;
        r->cur++;
        Align_7F80(r);
        self->b150 = *(unsigned char*)r->cur;
        r->cur++;
        Align_7F80(r);
    } else {
        self->b151 = 0;
        self->b150 = 0;
    }
    if (r->version >= 0x45) {
        ReadF_7F80(r, &self->f160);
        ReadF_7F80(r, &self->f164);
        ReadF_7F80(r, &self->f168);
        ReadF_7F80(r, &self->f154);
        ReadF_7F80(r, &self->f158);
    } else {
        self->f154 = 0.0f;
        self->f158 = 0.0f;
        self->f160 = 0.0f;
        self->f164 = 0.0f;
        self->f168 = 0.0f;
        self->f16C = 0.0f;
    }
    n = RdI_7F80(r);
    if (n)
        self->fBC = (int)(RdF_7F80(r) - 1.0f);
    Assign64_7F80(&self->keys, n, E64_7F80());
    for (i = 0; i < n; i++) {
        ReadF_7F80(r, &self->keys.data[i].a);
        ReadF_7F80(r, &self->keys.data[i].pos.x);
        ReadF_7F80(r, &self->keys.data[i].pos.y);
        ReadF_7F80(r, &self->keys.data[i].pos.z);
        *(int*)&self->keys.data[i].pos.w = 0x3F800000;
        ReadF_7F80(r, &self->keys.data[i].b[0]);
        ReadF_7F80(r, &self->keys.data[i].b[1]);
        ReadF_7F80(r, &self->keys.data[i].b[2]);
        ReadF_7F80(r, &self->keys.data[i].c[0]);
        ReadF_7F80(r, &self->keys.data[i].c[1]);
        ReadF_7F80(r, &self->keys.data[i].c[2]);
    }
    n = RdI_7F80(r);
    if (n) {
        self->fD4 = (int)(RdF_7F80(r) - 1.0f);
        {
            Assign8_7F80(&self->flags, n, E8_7F80());
        }
        int j;
        for (j = 0; j < n; j++) {
            ReadF_7F80(r, &self->flags.data[j].t);
            self->flags[j].on = RdF_7F80(r) != 0.0f;
        }
    } else {
        self->fD4 = -1;
        {
            Assign8_7F80(&self->flags, 1, E8_7F80());
        }
        self->flags[0].t = 0.0f;
        self->flags[0].on = 1;
    }
    {
    int k;
    int cnt = RdI_7F80(r);
    for (k = 0; k < cnt; k++) {
        int a = RdI_7F80(r);
        int b = RdI_7F80(r);
        int found = IdMgr_FindCollision(a, b);
        if (found)
            ZoneMgr_Associate(found, self, 1, found);
    }
    }
    self->f94 = 0;
    self->f140 = 0;
    V4_7F80* pp = &self->posE0;
    VCX_7F80(pp, &self->keys.data[0].pos);
    self->bDC = Fl_7F80(&self->flags)->on;
    self->v60(1, pp);
    Node_ClearLocalMatrix(self);
    {
        Mat_7F80 m;
        VCX_7F80(&m.r[3], &self->posE0);
        { Mat_7F80* dst = &self->mF0; Mat_7F80* src = &m; MC2_7F80(dst, src); }
        self->SetFrame(&m, 0);
    }
    self->b130 = 0;
    self->fC0 = 0;
    self->fD8 = 0;
    self->v134(0.0f);
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00237F80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00237F80 */

/* merge_units: begin func_00238780 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int cGOBJ_dtor(char **, int);                              
int func_00238850(char * , int);                         
int func_00240390(char * , int);                         
int func_00240480(int, int);                            
int operator_delete(char **);                            
extern void Actor_ApplyContactDamage();
extern void Actor_BaseWorldUpdate();
extern void Actor_VirtualNop();
extern void Controller_DeathNotice();
extern void Node_ClearFlag2C();
extern void Node_GetFlag2C();
extern void Node_SetFlag2C();
extern void Object_Activate();
extern void Object_AttachTransform();
extern void Object_GetAttachedOrSelf();
extern void cGOBJ_v0B();
extern void cGOBJ_v0C();
extern void GObj_GetID();
extern void func_0012ED00();
extern void func_0012ED30();
extern void func_0012ED40();
extern void func_0012ED50();
extern void func_0013E060();
extern void func_0013EE60();
extern void func_00140E90();
extern void GObj_GetLifeState();
extern void func_00148870();
extern void Object_GetEye();
extern void func_00153860();
extern void func_0015BFB0();
extern void func_0015BFC0();
extern void func_0015BFD0();
extern void func_0015C000();
extern void func_0015C010();
extern void func_0015C020();
extern void func_0015C030();
extern void func_0015C040();
extern void func_0015C050();
extern void func_0015C080();
extern void func_0015C0A0();
extern void NiEventLight_Step();
extern void NiPositionTrack_Update();
extern void NiSwitchTrack_Update();
extern void NiEvent_UpdateNode();
extern void func_0023E5D0();
extern void NiEvent_Reset();
extern void NiEvent_Stop();
extern void NiEvent_Play();
extern void NiEvent_HandlePlayMsg();
extern void NiEvent_PreLogic();
extern void func_0023EA10();
extern void func_0023EA50();
extern void func_0023EE90();
extern void func_0023FCD0();
extern void func_0023FCE0();
extern void func_0023FCF0();
extern void GObj_GetWorldMatrix();
extern void func_003CD090();
extern void func_003CD110();
extern void Node_GetComponentMatrix();
extern void PathObj_GetPosition();
extern void Node_GetLightRefPoint();
extern void func_003CD4A0();
extern void Node_GetWorldMatrix();
extern void func_003CD7A0();
extern void func_003CD920();
extern void func_003CDA60();
extern void func_003CDBE0();
extern void func_003CDC20();
extern void func_003CDD40();
extern void func_003CDD80();
extern void func_003CDDC0();
extern void Player_GetActiveWeapon();
extern void Object_Deactivate();
extern void func_003CE7D0();
extern void func_003CE810();
extern void func_003CE9D0();
extern void func_003CE9E0();
extern void func_003CE9F0();
extern void func_003CEA00();
extern void * const D_004DC190[];

char **func_00238780(char **arg0, long long arg1) {
    int temp_a0;
    char * temp_a0_2;
    char * temp_a0_3;

    if (arg0 != NULL) {
        temp_a0 = (int)((char *)arg0 + 0xC4);
        *arg0 = &(*(char*)D_004DC190);
        if ((temp_a0 != 0) && (temp_a0 != 0) && (temp_a0 != 0)) {
            func_00240480(temp_a0, 0);
        }
        temp_a0_2 = (char *)arg0 + 0xAC;
        if ((temp_a0_2 != NULL) && (temp_a0_2 != NULL) && (temp_a0_2 != NULL)) {
            func_00240390(temp_a0_2, 0);
        }
        temp_a0_3 = (char *)arg0 + 0x9C;
        if (temp_a0_3 != NULL) {
            func_00238850(temp_a0_3, -1);
        }
        cGOBJ_dtor(arg0, 0);
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
void * const D_004DC190[80] = { (void*)0x0, (void*)0x0, (void*)func_00238780, (void*)NiEvent_HandlePlayMsg, (void*)GObj_GetID, (void*)Object_GetAttachedOrSelf, (void*)func_0023FCF0, (void*)func_0012ED00, (void*)func_003CE810, (void*)func_003CE7D0, (void*)func_0012ED30, (void*)func_0012ED40, (void*)func_0012ED50, (void*)cGOBJ_v0B, (void*)cGOBJ_v0C, (void*)func_003CEA00, (void*)func_003CE9F0, (void*)func_003CE9E0, (void*)func_0023EA10, (void*)NiEvent_PreLogic, (void*)Actor_BaseWorldUpdate, (void*)Actor_VirtualNop, (void*)func_003CE9D0, (void*)Object_Activate, (void*)Object_Deactivate, (void*)Node_SetFlag2C, (void*)Node_ClearFlag2C, (void*)Node_GetFlag2C, (void*)func_0015BFB0, (void*)func_0015BFC0, (void*)func_0015BFD0, (void*)func_00148870, (void*)func_0023FCE0, (void*)func_0023FCD0, (void*)func_0013EE60, (void*)func_0015C000, (void*)Object_AttachTransform, (void*)Player_GetActiveWeapon, (void*)func_003CDDC0, (void*)func_003CDD80, (void*)func_003CDD40, (void*)func_003CDC20, (void*)func_003CDBE0, (void*)func_003CDA60, (void*)func_003CD920, (void*)func_003CD7A0, (void*)func_0015C010, (void*)func_00153860, (void*)Object_GetEye, (void*)func_0015C020, (void*)func_00140E90, (void*)func_0015C030, (void*)func_0015C040, (void*)func_0015C050, (void*)Node_GetWorldMatrix, (void*)func_003CD4A0, (void*)Node_GetLightRefPoint, (void*)PathObj_GetPosition, (void*)Node_GetComponentMatrix, (void*)func_003CD110, (void*)func_003CD090, (void*)GObj_GetWorldMatrix, (void*)func_0013E060, (void*)func_0015C080, (void*)Actor_ApplyContactDamage, (void*)func_0015C0A0, (void*)GObj_GetLifeState, (void*)Controller_DeathNotice, (void*)func_0023EA50, (void*)NiEvent_Play, (void*)NiEvent_Stop, (void*)NiEvent_Reset, (void*)NiEvent_UpdateNode, (void*)func_0023EE90, (void*)func_0023E5D0, (void*)NiPositionTrack_Update, (void*)NiSwitchTrack_Update, (void*)NiEventLight_Step, (void*)0x0, (void*)0x0 };
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00238780(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00238780 */
