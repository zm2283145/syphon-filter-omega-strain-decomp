#pragma cplusplus on
#include "types.h"
#include "fileman_entry.h"
#define V5(a) virtual void a##0(); virtual void a##1(); virtual void a##2(); virtual void a##3(); virtual void a##4();
#define V10(p) V5(p##x) V5(p##y)
struct Reader_74500 { int version; int a, b; char* cur; };
struct Vec_74500 { int a; int b; int c; unsigned char flag; };
struct Ld_74500 { FileManEntry* a; FileManEntry* b; int c; int d; int e; };
struct Terrain_74500 {
    V10(a) virtual void b0(); virtual void b1(); virtual void b2(); virtual void b3();
    virtual void Load(int a); /* +0x40 */
    virtual void Load2(Ld_74500* l); /* +0x44 */
    virtual void c0(); virtual void c1(); virtual void c2(); virtual void c3(); virtual void c4(); virtual void c5();
    virtual void SetActive(int on); /* +0x60 */
    int pad4[2];
    int idC;
    char pad10[0x1F4 - 0x10];
    Vec_74500 v1F4;
    Vec_74500 v204;
    Vec_74500 v214;
    char pad224[0xC];
    int lo[4];
    int hi[4];
    unsigned char b250;
};
extern "C" {
extern char D_004EE780[];
extern char D_004D9BE0[];
extern char D_0049CA58[];
void cVUM_GOBJ_ctor(Terrain_74500* o, int* desc, char* info);
void std_vector_cGOBJPtr_ctor_uint_cGOBJPR(Vec_74500* v, int a, int* b);
void std_vector_cObjectId_ctor_uint_cObjectIdR(Vec_74500* v, int a, int* b);
void PtrVec_InitEmpty(Vec_74500* v);
char* strchr(const char* s, int c);
void String_Copy(char* d, const char* s);
int Hog_Register(void* h, const char* name, int arg, int opt);
unsigned char FileMan_FindMember(void* e);
Terrain_74500* Terrain_Construct(Terrain_74500* self, Reader_74500* r, int a, int b);
}
static inline void ReadInt_74500(Reader_74500* r, int* out) { *out = *(int*)r->cur; r->cur += 4; }
static inline void Align_74500(Reader_74500* r)
{
    int rem;
    char* ptr = r->cur;
    rem = (int)((unsigned long long)(unsigned int)ptr & 3);
    if (rem) r->cur = ptr + (4 - rem);
}
Terrain_74500* Terrain_Construct(Terrain_74500* self, Reader_74500* r, int a, int b)
{
    int gid;
    FileManEntry e1;
    FileManEntry e2;
    Ld_74500 ld;
    int hi;
    int lo;
    char* s;
    gid = -1;
    cVUM_GOBJ_ctor(self, &gid, D_004EE780);
    *(void**)self = D_004D9BE0;
    {
        Vec_74500* v = &self->v1F4;
        int z = 0;
        std_vector_cGOBJPtr_ctor_uint_cGOBJPR(v, 0, &z);
        v->flag = 1;
    }
    {
        int m = -1;
        Vec_74500* v = &self->v204;
        std_vector_cObjectId_ctor_uint_cObjectIdR(v, 0, &m);
        v->flag = 1;
    }
    {
        Vec_74500* v = &self->v214;
        PtrVec_InitEmpty(v);
        v->flag = 1;
    }
    self->lo[0] = 0x7F7FFFFF;
    self->lo[1] = 0x7F7FFFFF;
    self->lo[2] = 0x7F7FFFFF;
    self->lo[3] = 0x3F800000;
    self->hi[0] = 0xFF7FFFFF;
    self->hi[1] = 0xFF7FFFFF;
    self->hi[2] = 0xFF7FFFFF;
    self->hi[3] = 0x3F800000;
    Resource_Construct(&e1);
    Resource_Construct(&e2);
    self->b250 = 0;
    ReadInt_74500(r, &hi);
    ReadInt_74500(r, &lo);
    s = r->cur;
    while (*r->cur++) ;
    String_Copy(strchr(s, '.'), D_0049CA58);
    Hog_Register(&e1, s, a, 1);
    Hog_Register(&e2, s, b, 0);
    Align_74500(r);
    if (FileMan_FindMember(&e1) == 0) {
        ld.a = &e1;
        ld.b = &e2;
        ld.c = 0;
        ld.d = 0;
        ld.e = 0;
        self->idC = lo | (hi << 16);
        self->Load(0);
        self->Load2(&ld);
        self->SetActive(1);
    }
    FileMan_Release(&e2, -1);
    FileMan_Release(&e1, -1);
    return self;
}
