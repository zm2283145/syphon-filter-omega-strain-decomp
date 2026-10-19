#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#include "fileman_entry.h"
extern "C" {
#include "net_local_id.h"
}
#pragma inline_depth(10)
#define V5(a) virtual void a##0(); virtual void a##1(); virtual void a##2(); virtual void a##3(); virtual void a##4();
#define V10(p) V5(p##x) V5(p##y)
struct V4_21ADD0 { float x, y, z, w; };
struct Mat_21ADD0 { V4_21ADD0 r[4]; };
struct Reader_21ADD0 { int version; int a, b; char* cur; };
struct Rel_21ADD0 { int a; int b; void** c; void*& at(int i) { return c[i]; } };
struct RelFlag_21ADD0 { Rel_21ADD0 rel; unsigned char flag; };
struct Name_21ADD0 { int a; int b; int c; };
struct Ld_21ADD0 { FileManEntry* a; FileManEntry* b; int c; int d; int e; };
struct GObj_21ADD0 {
    V10(a) V10(b) virtual void c0(); virtual void c1();
    virtual void SetActive(int on); /* +0x60 */
    V10(d) V10(e) V10(f) V10(g) virtual void h0(); virtual void h1(); virtual void h2();
    virtual void Link(GObj_21ADD0* o); /* +0x110 */
    int pad4[2];
    int idC;
    int id10;
    unsigned char b14;
    char pad15[3];
    Name_21ADD0* name18;
    char pad1C[0x13];
    unsigned char b2F;
    char pad30[0x19];
    unsigned char b49;
    char pad4A[6];
    void* xf50;
    char pad54[0xC];
    unsigned char b60;
    char pad61[3];
    struct VUM_21ADD0* vum;
    int kind;
    int f6C;
    int f70;
    RelFlag_21ADD0 r74;
    RelFlag_21ADD0 r84;
};
struct VUM_21ADD0 {
    V10(a) virtual void b0(); virtual void b1(); virtual void b2(); virtual void b3();
    virtual void Load(int a); /* +0x40 */
    virtual void Load2(Ld_21ADD0* l); /* +0x44 */
    char pad4[0x68];
    GObj_21ADD0* owner;
};
extern "C" {
extern char g_GameGobjClassWord[];
extern char D_004DB4C0[];
extern char D_004A4638[];
extern char D_004A4640[];
extern char D_0049C088[];
extern char D_004A4550[];
extern char g_Game[];
void cGOBJ_ctor(GObj_21ADD0* o, int* id, int kind, void* info);
void PtrVec_InitEmpty(Rel_21ADD0* r);
void func_0021B770(Rel_21ADD0* r);
int String_CompareNoCase(const char* a, const char* b);
char* strchr(const char* s, int c);
void String_Copy(char* d, const char* s);
int Hog_Register(void* h, const char* name, int arg, int opt);
void* Mem_Alloc(int heap, int size, char* file, int line);
void Script_LookupResource(Name_21ADD0* n, char* s);
void Mtx_SetBasis(Mat_21ADD0* m, V4_21ADD0* a, V4_21ADD0* b, V4_21ADD0* c);
void Mtx_SetTranslation(Mat_21ADD0* m, V4_21ADD0* t);
void PtrVec_Reserve(RelFlag_21ADD0* r, int n);
GObj_21ADD0* IdMgr_FindCollision(int region, int id);
unsigned char FileMan_FindMember(void* e);
unsigned char Game_FindNamedResource(void* m, char* name, int* out);
VUM_21ADD0* cVUM_GOBJ_ctor2(void* p, int* a);
void func_00130D10(void* m, VUM_21ADD0* v, char* name, int z);
void func_0036DEC0(void* e);
void Node_ClearLocalMatrix(GObj_21ADD0* o);
void Object_AttachTransform(GObj_21ADD0* o, Mat_21ADD0* m, int z);
void Object_ShareTransform(VUM_21ADD0* v, void* xf);
void ZoneMgr_Associate(GObj_21ADD0* found, GObj_21ADD0* o, int a, GObj_21ADD0* b);
void NetMap_BindReceiver(int id, int owner, GObj_21ADD0* o);
}
static inline int Read_21ADD0(Reader_21ADD0* r) { int v = *(int*)r->cur; r->cur += 4; return v; }
static inline void ReadInt_21ADD0(Reader_21ADD0* r, int* out) { *out = *(int*)r->cur; r->cur += 4; }
static inline float ReadF_21ADD0(Reader_21ADD0* r) { float v = *(float*)r->cur; r->cur += 4; return v; }
static inline void ReadV_21ADD0(Reader_21ADD0* r, V4_21ADD0* v, float w)
{
    float x = ReadF_21ADD0(r);
    float y = ReadF_21ADD0(r);
    float z = ReadF_21ADD0(r);
    v->x = x;
    v->w = w;
    v->y = y;
    v->z = z;
}
static inline void Align_21ADD0(Reader_21ADD0* r)
{
    int rem;
    char* ptr = r->cur;
    rem = (int)((unsigned long long)(unsigned int)ptr & 3);
    if (rem) r->cur = ptr + (4 - rem);
}
static inline void* New_21ADD0(int size, char* file, int line)
{
    AllocGuard g;
    return Mem_Alloc(0, size, file, line);
}
static inline int ObjId_21ADD0(void)
{
    int id;
    int ok = g_IsMultiplayer ? D_005721C0 : 1;
    if (ok) {
        id = NetLocalId();
    } else {
        int tmp;
        func_002EBBA0(D_005721A8, &tmp);
        id = tmp;
    }
    return id;
}
static inline Name_21ADD0* NewName_21ADD0(void)
{
    Name_21ADD0* p = (Name_21ADD0*)New_21ADD0(0xC, D_0049C088, 0x49);
    if (p) {
        p->a = 0;
        p->b = 0;
        p->c = -1;
    }
    return p;
}
static inline int IsAuth_21ADD0(void) { return g_IsMultiplayer ? D_005721C0 : 1; }
extern "C" GObj_21ADD0* cGameGOBJ_ctor(GObj_21ADD0* self, int arg, Reader_21ADD0* r, int kind)
{
    int got;
    int gid;
    FileManEntry e;
    int ia[256];
    int ib[256];
    V4_21ADD0 r0;
    V4_21ADD0 r1;
    V4_21ADD0 r2;
    V4_21ADD0 t;
    Mat_21ADD0 m;
    Ld_21ADD0 ld;
    int hi;
    int lo;
    char* s;
    char* s2;
    int n;
    int i;
    int j;
    gid = -1;
    cGOBJ_ctor(self, &gid, 0xF, g_GameGobjClassWord);
    *(void**)self = D_004DB4C0;
    {
        RelFlag_21ADD0* rf = &self->r74;
        PtrVec_InitEmpty(&rf->rel);
        rf->flag = 1;
    }
    {
        RelFlag_21ADD0* rf = &self->r84;
        func_0021B770(&rf->rel);
        rf->flag = 1;
    }
    Resource_Construct(&e);
    self->kind = kind;
    ReadInt_21ADD0(r, &hi);
    ReadInt_21ADD0(r, &lo);
    s = r->cur;
    while (*r->cur++) ;
    Align_21ADD0(r);
    self->b60 = String_CompareNoCase(D_004A4638, s) != 0;
    if (self->b60) {
        String_Copy(strchr(s, '.'), D_004A4640);
        Hog_Register(&e, s, arg, 1);
    } else {
        self->b49 = 0xE;
    }
    s2 = r->cur;
    while (*r->cur++) ;
    if (s2) {
        if (!self->name18) {
self->name18 = NewName_21ADD0();
        }
        Script_LookupResource(self->name18, s2);
    }
    Align_21ADD0(r);
    ReadV_21ADD0(r, &t, 1.0f);
    ReadV_21ADD0(r, &r0, 0.0f);
    ReadV_21ADD0(r, &r1, 0.0f);
    ReadV_21ADD0(r, &r2, 0.0f);
    Mtx_SetBasis(&m, &r0, &r1, &r2);
    Mtx_SetTranslation(&m, &t);
    n = Read_21ADD0(r);
    for (i = 0; i < n; i++) {
        ReadInt_21ADD0(r, &ia[i]);
        ReadInt_21ADD0(r, &ib[i]);
    }
    ReadInt_21ADD0(r, &self->f70);
    PtrVec_Reserve(&self->r74, self->f70);
    for (i = 0; i < self->f70; i++) {
        int a = Read_21ADD0(r);
        int b = Read_21ADD0(r);
        GObj_21ADD0* p = IdMgr_FindCollision(a, b);
        ((GObj_21ADD0**)self->r74.rel.c)[(unsigned)i] = p;
        if (p && p->b49 != 0xB && p->b49 != 0xA && p->b49 != 9)
            p->Link(self);
    }
    {
        int id = lo | (hi << 16);
        self->idC = id;
        self->id10 = id;
    }
    if (self->b60 && FileMan_FindMember(&e) == 0) {
        unsigned char have;
        got = 0;
        have = Game_FindNamedResource(g_Game, s, &got);
        {
            VUM_21ADD0* v = (VUM_21ADD0*)New_21ADD0(0x1F4, D_004A4550, 0xBC);
            if (v) {
                int z = 0;
                v = cVUM_GOBJ_ctor2(v, &z);
            }
            self->vum = v;
        }
        self->vum->owner = self;
        if (!have)
            func_00130D10(g_Game, self->vum, s, 0);
        ld.a = &e;
        ld.b = &e;
        ld.c = got;
        ld.d = 0;
        ld.e = 0;
        self->vum->Load(0);
        self->vum->Load2(&ld);
        self->b2F = 1;
        func_0036DEC0(&e);
    } else {
        self->b60 = 0;
        self->vum = 0;
    }
    Node_ClearLocalMatrix(self);
    Object_AttachTransform(self, &m, 0);
    if (self->vum)
        Object_ShareTransform(self->vum, self->xf50);
    self->SetActive(1);
    for (j = 0; j < n; j++) {
        if (ia[j] != -1 && ib[j] != -1) {
            GObj_21ADD0* f = IdMgr_FindCollision(ia[j], ib[j]);
            if (f)
                ZoneMgr_Associate(f, self, 1, f);
        }
    }
    self->f6C = 0;
    if (g_IsMultiplayer) {
        if (!IsAuth_21ADD0())
            self->b14 = 0;
        int id = self->id10;
        NetMap_BindReceiver(id, ObjId_21ADD0(), self);
    }
    FileMan_Release(&e, -1);
    return self;
}




