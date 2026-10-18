/*
 * main/Generator: range (2 files, 00221BC0-00221D20)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
#include "SFOLobby_helpers.h"
int Mem_Free();
int strlen(const char *);

/* merge_units: begin func_00221BC0 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
extern "C" {
int cGOBJ_dtor(char *, int);
int func_00135D80(char *, int);
int func_00177B80(char *, int);
int Player_ClearRecentTargets(int *, char *, int *, char **);
int operator_delete(char *);
extern char D_004A4A90;
extern "C" void Actor_ApplyContactDamage();
extern "C" void Actor_BaseWorldUpdate();
extern "C" void Actor_VirtualNop();
extern "C" void Controller_DeathNotice();
extern "C" void Node_GetFlag2C();
extern "C" void Object_AttachTransform();
extern "C" void Object_GetAttachedOrSelf();
extern "C" void cGenerator_v01();
extern "C" void cGenerator_v04();
extern "C" void cGenerator_v05();
extern "C" void cGenerator_v06();
extern "C" void cGenerator_v07();
extern "C" void cGenerator_v08();
extern "C" void cGenerator_v09();
extern "C" void cGenerator_v0B();
extern "C" void cGenerator_v0C();
extern "C" void cGenerator_v0E();
extern "C" void cGenerator_v0F();
extern "C" void cGenerator_v10();
extern "C" void cGenerator_v11();
extern "C" void cGenerator_v15();
extern "C" void cGenerator_v16();
extern "C" void cGenerator_v17();
extern "C" void cGenerator_v18();
extern "C" void cGenerator_v3D();
extern "C" void GObj_GetID();
extern "C" void func_0012ED50();
extern "C" void func_0013E060();
extern "C" void func_0013EE60();
extern "C" void func_00140E90();
extern "C" void GObj_GetLifeState();
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
extern "C" void func_0015C0A0();
extern "C" void GObj_GetWorldMatrix();
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
extern "C" void func_003CE9D0();
extern "C" void func_003CEA00();
extern void * const D_004DB680[];
}
static inline char* Identity(char*a){return a;} static inline void clr0(char*a){int r;int f;char*l;l=Identity(a+0xA0);f=F_(a,0xA4,int);Player_ClearRecentTargets(&r,a+0x9C,&f,&l);}
static inline void clr1(char *a) { clr0(a); }
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
extern "C" char *cGenerator_dtor(char *arg0, long long arg1) {
    int temp_s2;
    char *temp_a0;

    if (arg0 != NULL) {
        F_(arg0, 0x0, char *) = &(*(char*)D_004DB680);
        F_(arg0, 0x78, int) = 0;
        clr0(arg0);
        temp_s2 = F_(arg0, 0x64, int);
        {
            AllocGuard g;
            Mem_Free(0, temp_s2, &D_004A4A90, 0x23C);
        }
        temp_a0 = arg0 + 0x9C;
        if (temp_a0 != NULL) func_00177B80(temp_a0, 0);
        temp_a0 = arg0 + 0x90;
        if (temp_a0 != NULL) func_00177B80(temp_a0, 0);
        temp_a0 = arg0 + 0x74;
        if (temp_a0 != NULL) func_00135D80(temp_a0, -1);
        cGOBJ_dtor(arg0, 0);
        if (((long long)(arg1 << 0x30) >> 0x30) > 0) operator_delete(arg0);
    }
    return arg0;
}
#pragma pop
void * const D_004DB680[68] = { (void*)0x0, (void*)0x0, (void*)cGenerator_dtor, (void*)cGenerator_v01, (void*)GObj_GetID, (void*)Object_GetAttachedOrSelf, (void*)cGenerator_v04, (void*)cGenerator_v05, (void*)cGenerator_v06, (void*)cGenerator_v07, (void*)cGenerator_v08, (void*)cGenerator_v09, (void*)func_0012ED50, (void*)cGenerator_v0B, (void*)cGenerator_v0C, (void*)func_003CEA00, (void*)cGenerator_v0E, (void*)cGenerator_v0F, (void*)cGenerator_v10, (void*)cGenerator_v11, (void*)Actor_BaseWorldUpdate, (void*)Actor_VirtualNop, (void*)func_003CE9D0, (void*)cGenerator_v15, (void*)cGenerator_v16, (void*)cGenerator_v17, (void*)cGenerator_v18, (void*)Node_GetFlag2C, (void*)func_0015BFB0, (void*)func_0015BFC0, (void*)func_0015BFD0, (void*)func_00148870, (void*)func_0015BFF0, (void*)func_0015BFE0, (void*)func_0013EE60, (void*)func_0015C000, (void*)Object_AttachTransform, (void*)Player_GetActiveWeapon, (void*)func_003CDDC0, (void*)func_003CDD80, (void*)func_003CDD40, (void*)func_003CDC20, (void*)func_003CDBE0, (void*)func_003CDA60, (void*)func_003CD920, (void*)func_003CD7A0, (void*)func_0015C010, (void*)func_00153860, (void*)Object_GetEye, (void*)func_0015C020, (void*)func_00140E90, (void*)func_0015C030, (void*)func_0015C040, (void*)func_0015C050, (void*)Node_GetWorldMatrix, (void*)func_003CD4A0, (void*)Node_GetLightRefPoint, (void*)PathObj_GetPosition, (void*)Node_GetComponentMatrix, (void*)func_003CD110, (void*)func_003CD090, (void*)GObj_GetWorldMatrix, (void*)func_0013E060, (void*)cGenerator_v3D, (void*)Actor_ApplyContactDamage, (void*)func_0015C0A0, (void*)GObj_GetLifeState, (void*)Controller_DeathNotice };
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00221BC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00221BC0 */

/* merge_units: begin func_00221D20 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_strength_reduction off
#define V5(a) virtual void a##0(); virtual void a##1(); virtual void a##2(); virtual void a##3(); virtual void a##4();
struct V4_221D20 { float x, y, z, w; };
struct Reader_221D20 { int version; int a, b; char* cur; };
struct Rel_221D20;
extern "C" void PtrVector_Resize(Rel_221D20* v, int n, int* fill);
struct Rel_221D20 { int a; int b; int* c; int& at(int i) { return c[i]; } void Clear(){ int z = 0; PtrVector_Resize(this, 0, &z);} };
struct Mat_221D20 { V4_221D20 r[4]; };
struct RelFlag_221D20 { Rel_221D20 rel; unsigned char flag; };
struct Xf_221D20 {
    V5(a) V5(b) V5(c) V5(d)
    virtual void Update(); /* +0x58 */
    char pad4[0x3C];
    V4_221D20 pos;
    unsigned char dirty;
};
struct List_221D20 { int size; void* head[2]; };
struct Gen_221D20 {
    V5(a) V5(b) V5(c) V5(d) virtual void e0();
    virtual void Activate(int on); /* +0x5C */
    V5(f) V5(g) virtual void h0(); virtual void h1();
    virtual void SetFrame(Mat_221D20* m, int f); /* +0x90 */
    int pad4[2];
    int idC;
    int id10;
    char pad14[0x18];
    unsigned char b2C;
    char pad2D[0x23];
    Xf_221D20* xf;
    char pad54[0xC];
    int f60;
    char* name;
    int f68;
    int f6C;
    int f70;
    RelFlag_221D20 r74;
    float f84;
    int f88;
    int f8C;
    List_221D20 list90;
    List_221D20 list9C;
    char nameA8[0x10];
    float fB8;
    float fBC;
    int nC0;
    int nC4;
    int nC8;
    int maskCC;
    unsigned char bD0;
    unsigned char bD1;
    unsigned char bD2;
    unsigned char bD3;
};
extern "C" {
extern char D_004F56B0[];
#if 0 /* merge_units */
extern char D_004DB680[];
#endif /* merge_units */
#define D_004DB680 ((char*)&D_004DB680) /* merge_units */

#if 0 /* merge_units */
extern char D_004A4A90[];
#endif /* merge_units */
#define D_004A4A90 ((char*)&D_004A4A90) /* merge_units */

extern int D_004F56B8;
extern int D_005721A8;
extern unsigned char D_005721C0;
extern unsigned char D_005721C8;
void cGOBJ_ctor(Gen_221D20* o, int* id, int kind, void* info);
Rel_221D20* func_001365E0(Rel_221D20* r);
void func_00222B60(List_221D20* l);
void* Mem_Alloc(int heap, int size, char* file, int line);
void PtrVector_Resize(Rel_221D20* v, int n, int* fill);
int IdMgr_FindCollision(int region, int id);
void ZoneMgr_Associate(int found, Gen_221D20* o, int a, int b);
int LosRegion_FindGlobal(V4_221D20* p);
void func_002EBBA0(int s, int* out);
void NetMap_BindReceiver(int id, int owner, Gen_221D20* o);
void func_0043B190(void* ctx);
void func_004398E0(void* ctx, int* id, int n);
int Net_GetClock(int a);
}
static inline int Read_221D20(Reader_221D20* r) { int v = *(int*)r->cur; r->cur += 4; return v; }
static inline void ReadInt_221D20(Reader_221D20* r, int* out) { *out = *(int*)r->cur; r->cur += 4; }
static inline void ReadFloat_221D20(Reader_221D20* r, float* out) { *out = *(float*)r->cur; r->cur += 4; }
static inline void ReadVec_221D20(Reader_221D20* r, float* v) { int k; for (k = 0; k < 3; k++) ReadFloat_221D20(r, &v[k]); }
static inline void Align_221D20(Reader_221D20* r)
{
    int rem;
    char* ptr = r->cur;
    rem = (int)((unsigned long long)(unsigned int)ptr & 3);
    if (rem) r->cur = ptr + (4 - rem);
}
static inline char* ReadStr_221D20(Reader_221D20* r)
{
    char* s = r->cur;
    while (*r->cur++)
        ;
    return s;
}
static inline void* New_221D20(int size, int line)
{
    AllocGuard g;
    return Mem_Alloc(0, size, D_004A4A90, line);
}
static inline char* ReadStrA_221D20(Reader_221D20* r) { char* s = ReadStr_221D20(r); Align_221D20(r); return s; }
static inline int HostId_221D20(void) { int t; func_002EBBA0(D_005721A8, &t); return t; }
static inline V4_221D20* GetPos_221D20(Xf_221D20* x)
{
    if (x->dirty) x->Update();
    return &x->pos;
}
extern "C" Gen_221D20* cGenerator_ctor(Gen_221D20* self, Reader_221D20* r)
{
    int id;
    int ctx;
    int gid;
    int fC0;
    Mat_221D20 m;
    int hi;
    int n;
    int i;
    unsigned char act;
    char* s;
    gid = -1;
    cGOBJ_ctor(self, &gid, 0, D_004F56B0);
    *(void**)self = D_004DB680;
    self->f60 = 0;
    {
        RelFlag_221D20* rf = &self->r74;
        func_001365E0(&rf->rel);
        rf->flag = 1;
    }
    func_00222B60(&self->list90);
    func_00222B60(&self->list9C);
    m.r[0].w = 0.0f;
    m.r[3].w = 1.0f;
    m.r[1].w = 0.0f;
    m.r[2].w = 0.0f;
    hi = Read_221D20(r);
    {
        int lo = Read_221D20(r);
        id = lo | (hi << 16);
    }
    self->idC = id;
    s = ReadStrA_221D20(r);
    self->name = (char*)New_221D20(strlen(s) + 1, 0x1AF);
    String_Copy(self->name, s);
    ReadInt_221D20(r, &self->f68);
    {
        float* p2 = &m.r[2].x; float* p1 = &m.r[1].x;
        ReadVec_221D20(r, &m.r[3].x);
        ReadVec_221D20(r, &m.r[0].x);
        ReadVec_221D20(r, p1);
        ReadVec_221D20(r, p2);
    }
    self->SetFrame(&m, 0);
    ReadInt_221D20(r, &self->f6C);
    ReadInt_221D20(r, &self->f70);
    n = Read_221D20(r);
    fC0 = 0;
    self->r74.rel.Clear();
    n /= 2;
    PtrVector_Resize(&self->r74.rel, n, &fC0);
    for (i = 0; i < n; i++) {
        int a = Read_221D20(r);
        int b = Read_221D20(r);
        self->r74.rel.at(i) = IdMgr_FindCollision(a, b);
    }
    ReadInt_221D20(r, &self->f88);
    ReadInt_221D20(r, &self->f8C);
    ReadFloat_221D20(r, &self->f84);
    if (r->version >= 0x3E) {
        self->bD2 = *(unsigned char*)r->cur;
        r->cur++;
        Align_221D20(r);
    } else {
        self->bD2 = 0;
    }
    act = *(unsigned char*)r->cur;
    r->cur++;
    if (act)
        self->b2C = 1;
    else
        self->b2C = 0;
    if (r->version >= 0x32) {
        int child;
        Align_221D20(r);
        child = Read_221D20(r);
        if (child != -1 && hi != -1) {
            int found = IdMgr_FindCollision(hi, child);
            if (found)
                ZoneMgr_Associate(found, self, 1, 0);
            else
                self->Activate(1);
        } else {
            int found = LosRegion_FindGlobal(GetPos_221D20(self->xf));
            if (found)
                ZoneMgr_Associate(found, self, 1, 0);
            else
                self->Activate(1);
        }
    }
    String_Copy(self->nameA8, ReadStr_221D20(r));
    Align_221D20(r);
    self->nC0 = 0;
    self->nC4 = 0;
    self->nC8 = self->nC4;
    self->bD0 = 0;
    self->fBC = self->f84;
    self->bD1 = 0;
    self->fB8 = 256.0f;
    self->id10 = id;
    if (D_005721C8) {
        self->bD3 = 0;
        self->maskCC = act ? 0xFF : 0;
        NetMap_BindReceiver(self->id10, HostId_221D20(), self);
        if (D_005721C8 ? D_005721C0 : 1) {
            func_0043B190(&ctx);
            func_004398E0(&ctx, &id, -1);
        }
        D_004F56B8 = Net_GetClock(1) + 0xFA;
    }
    return self;
}
#undef D_004DB680 /* merge_units */
#undef D_004A4A90 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00221D20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00221D20 */
