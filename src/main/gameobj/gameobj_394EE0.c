/*
 * main/gameobj: range (2 files, 00394EE0-00395050)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00394EE0 */
#pragma push /* merge_units */
typedef struct Res394EE0 { unsigned int flags; char data[0x90]; unsigned char b94; } Res394EE0;
typedef struct Hog394EE0 { int x0; char data[0x94]; char* name; } Hog394EE0;
typedef struct ModelInfo394EE0 { int x0; unsigned int flags; } ModelInfo394EE0;
typedef struct Model394EE0 { int loaded; ModelInfo394EE0* info; char p8[0x20]; int x28; } Model394EE0;

typedef struct Obj394EE0 {
    char p0[0x2C];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    char p2F[0x31];
    int x60;
    int x64;
    Model394EE0* model;
    int p6C;
    void* col;
    char x74[0x16C];
    Res394EE0* res;
    Hog394EE0* h1E4;
    Hog394EE0* h1E8;
    Hog394EE0* h1EC;
    unsigned char b1F0;
    unsigned char b1F1;
    unsigned char b1F2;
} Obj394EE0;

extern void* Fstream_GetLoader(void);
extern void func_003EAA40(void* mgr, Res394EE0* r);
extern int FileMan_ReadData(Res394EE0* r);
extern void func_0036D540(void* ctx, void* data, int size, int z);
extern int String_CompareNoCase(char* a, char* b);
extern void Hog_Register(Hog394EE0* h, void* data, void* ctx, int z);
extern void Model_Load(Model394EE0* m, Hog394EE0* a, Hog394EE0* b);
extern void Col_Load(void* c, Hog394EE0* h);
extern void Object_Deactivate(Obj394EE0* o, int arg);
extern void Model_Unload(Model394EE0* m);
extern void* D_00539248;
extern void func_003814D0(void* mgr, Hog394EE0* h);
extern void func_003C1790(void* c);

static inline void LoadCol(void* c, Hog394EE0* h) { if (c) Col_Load(c, h); }
static inline unsigned char Model_IsLoaded(Model394EE0* m) { return m->loaded != 0; }

void func_00394EE0(Obj394EE0* o, int arg)
{
    Res394EE0* r = o->res;
    if (r->flags & 4) {
        if (r->b94 && Model_IsLoaded(o->model) && o->model->x28 == 0) {
            Model_Unload(o->model);
            if (!o->b1F2 && String_CompareNoCase(o->h1E4->name, o->h1E8->name) == 0)
                func_003814D0(D_00539248, o->h1E4);
            if (o->col) func_003C1790(o->col);
            o->b2E = 1;
            if (o->b1F2 && o->x64 == 0) {
                Res394EE0* r2 = o->res;
                func_0036D540(o->x74, r2->data, FileMan_ReadData(r2), 0);
                Hog_Register(o->h1E4, o->h1E4->data, o->x74, 0);
                func_003814D0(D_00539248, o->h1E4);
            }
        }
        if (o->x60 && !Model_IsLoaded(o->model)) o->b2E = 1;
    } else {
        o->b2E = 0;
    }
    o->b2C = 0;
    Object_Deactivate(o, arg);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00394EE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00394EE0 */

/* merge_units: begin func_00395050 */
#pragma push /* merge_units */
typedef struct Res395050 { unsigned int flags; char data[0x90]; unsigned char b94; } Res395050;
typedef struct Hog395050 { int x0; char data[0x94]; char* name; } Hog395050;
typedef struct ModelInfo395050 { int x0; unsigned int flags; } ModelInfo395050;
typedef struct Model395050 { int loaded; ModelInfo395050* info; char p8[0x20]; int x28; } Model395050;

typedef struct Obj395050 {
    char p0[0x2C];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    char p2F[0x31];
    int x60;
    int x64;
    Model395050* model;
    int p6C;
    void* col;
    char x74[0x16C];
    Res395050* res;
    Hog395050* h1E4;
    Hog395050* h1E8;
    Hog395050* h1EC;
    unsigned char b1F0;
    unsigned char b1F1;
    unsigned char b1F2;
} Obj395050;
#if 0 /* merge_units */
extern void func_003EAA40(void* mgr, Res395050* r);
#endif /* merge_units */
#define func_003EAA40(a0, a1) (func_003EAA40((a0), (void *)(a1))) /* merge_units */

#if 0 /* merge_units */
extern int FileMan_ReadData(Res395050* r);
#endif /* merge_units */
#define FileMan_ReadData(a0) (FileMan_ReadData((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void Hog_Register(Hog395050* h, void* data, void* ctx, int z);
#endif /* merge_units */
#define Hog_Register(a0, a1, a2, a3) (Hog_Register((void *)(a0), (a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
extern void Model_Load(Model395050* m, Hog395050* a, Hog395050* b);
#endif /* merge_units */
#define Model_Load(a0, a1, a2) (Model_Load((void *)(a0), (void *)(a1), (void *)(a2))) /* merge_units */

#if 0 /* merge_units */
extern void Col_Load(void* c, Hog395050* h);
#endif /* merge_units */
#define Col_Load(a0, a1) (Col_Load((a0), (void *)(a1))) /* merge_units */

extern void Object_Activate(Obj395050* o, int arg);

static inline void LoadCol_00395050(void* c, Hog395050* h) { if (c) Col_Load(c, h); }
static inline unsigned char Model_IsLoaded_00395050(Model395050* m) { return m->loaded != 0; }

void func_00395050(Obj395050* o, int arg)
{
    Res395050* r = o->res;
    if (r->flags & 4) {
        if (!Model_IsLoaded_00395050(o->model)) {
            func_003EAA40(Fstream_GetLoader(), r);
            r = o->res;
            func_0036D540(o->x74, r->data, FileMan_ReadData(r), 0);
            if (String_CompareNoCase(o->h1E4->name, o->h1E8->name) == 0)
                Hog_Register(o->h1E4, o->h1E4->data, o->x74, 0);
            Hog_Register(o->h1E8, o->h1E8->data, o->x74, 0);
            Hog_Register(o->h1EC, o->h1EC->data, o->x74, 0);
            Model_Load(o->model, o->h1E8, o->h1E4);
            LoadCol_00395050(o->col, o->h1EC);
            if (o->model->info->flags & 0x10) {
                o->b1F0 = 0;
                o->b1F1 = 0;
            }
        }
    }
    o->b2E = 0;
    o->b2C = 1;
    Object_Activate(o, arg);
}
#undef func_003EAA40 /* merge_units */
#undef FileMan_ReadData /* merge_units */
#undef Hog_Register /* merge_units */
#undef Model_Load /* merge_units */
#undef Col_Load /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00395050(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00395050 */
