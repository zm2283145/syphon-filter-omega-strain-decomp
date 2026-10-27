/*
 * Libs/SFOLib/Source/gameobj: 4 files, 00394EE0-003951B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00394EE0 */
#pragma push /* merge_units */
#include "types.h"

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

extern void* GetFileStreamMan(void);
extern void cFileStreamMan_IsStreamRequestDone(void* mgr, Res394EE0* r);
extern int cFileMan_Read_void(Res394EE0* r);
extern void cHogFile_Open(void* ctx, void* data, int size, int z);
extern int String_CompareNoCase(char* a, char* b);
extern void cFileMan_EncodeFilename_charP_cHogFileR_bool(Hog394EE0* h, void* data, void* ctx, int z);
extern void cVU1Model_Load(Model394EE0* m, Hog394EE0* a, Hog394EE0* b);
extern void cCollisionModelMaster_Load(void* c, Hog394EE0* h);
extern void cGOBJ_Deactivate(Obj394EE0* o, int arg);
extern void cVU1Model_Unload(Model394EE0* m);
extern void* g_TextureMgr;
extern void cTexMan_RemoveTextureHOG(void* mgr, Hog394EE0* h);
extern void cCollisionModelMaster_UnLoad(void* c);

static inline void LoadCol(void* c, Hog394EE0* h) { if (c) cCollisionModelMaster_Load(c, h); }
static inline unsigned char Model_IsLoaded(Model394EE0* m) { return m->loaded != 0; }

void cVUM_GOBJ_Deactivate(Obj394EE0* o, int arg)
{
    Res394EE0* r = o->res;
    if (r->flags & 4) {
        if (r->b94 && Model_IsLoaded(o->model) && o->model->x28 == 0) {
            cVU1Model_Unload(o->model);
            if (!o->b1F2 && String_CompareNoCase(o->h1E4->name, o->h1E8->name) == 0)
                cTexMan_RemoveTextureHOG(g_TextureMgr, o->h1E4);
            if (o->col) cCollisionModelMaster_UnLoad(o->col);
            o->b2E = 1;
            if (o->b1F2 && o->x64 == 0) {
                Res394EE0* r2 = o->res;
                cHogFile_Open(o->x74, r2->data, cFileMan_Read_void(r2), 0);
                cFileMan_EncodeFilename_charP_cHogFileR_bool(o->h1E4, o->h1E4->data, o->x74, 0);
                cTexMan_RemoveTextureHOG(g_TextureMgr, o->h1E4);
            }
        }
        if (o->x60 && !Model_IsLoaded(o->model)) o->b2E = 1;
    } else {
        o->b2E = 0;
    }
    o->b2C = 0;
    cGOBJ_Deactivate(o, arg);
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
extern void cFileStreamMan_IsStreamRequestDone(void* mgr, Res395050* r);
#endif /* merge_units */
#define cFileStreamMan_IsStreamRequestDone(a0, a1) (cFileStreamMan_IsStreamRequestDone((a0), (Res394EE0 *)(a1))) /* merge_units */


#if 0 /* merge_units */
extern int cFileMan_Read_void(Res395050* r);
#endif /* merge_units */
#define cFileMan_Read_void(a0) (cFileMan_Read_void((Res394EE0 *)(a0))) /* merge_units */


#if 0 /* merge_units */
extern void cFileMan_EncodeFilename_charP_cHogFileR_bool(Hog395050* h, void* data, void* ctx, int z);
#endif /* merge_units */
#define cFileMan_EncodeFilename_charP_cHogFileR_bool(a0, a1, a2, a3) (cFileMan_EncodeFilename_charP_cHogFileR_bool((Hog394EE0 *)(a0), (a1), (a2), (a3))) /* merge_units */


#if 0 /* merge_units */
extern void cVU1Model_Load(Model395050* m, Hog395050* a, Hog395050* b);
#endif /* merge_units */
#define cVU1Model_Load(a0, a1, a2) (cVU1Model_Load((Model394EE0 *)(a0), (Hog394EE0 *)(a1), (Hog394EE0 *)(a2))) /* merge_units */


#if 0 /* merge_units */
extern void cCollisionModelMaster_Load(void* c, Hog395050* h);
#endif /* merge_units */
#define cCollisionModelMaster_Load(a0, a1) (cCollisionModelMaster_Load((a0), (Hog394EE0 *)(a1))) /* merge_units */


extern void cGOBJ_Activate(Obj395050* o, int arg);

static inline void LoadCol_00395050(void* c, Hog395050* h) { if (c) cCollisionModelMaster_Load(c, h); }
static inline unsigned char Model_IsLoaded_00395050(Model395050* m) { return m->loaded != 0; }

void cVUM_GOBJ_Activate(Obj395050* o, int arg)
{
    Res395050* r = o->res;
    if (r->flags & 4) {
        if (!Model_IsLoaded_00395050(o->model)) {
            cFileStreamMan_IsStreamRequestDone(GetFileStreamMan(), r);
            r = o->res;
            cHogFile_Open(o->x74, r->data, cFileMan_Read_void(r), 0);
            if (String_CompareNoCase(o->h1E4->name, o->h1E8->name) == 0)
                cFileMan_EncodeFilename_charP_cHogFileR_bool(o->h1E4, o->h1E4->data, o->x74, 0);
            cFileMan_EncodeFilename_charP_cHogFileR_bool(o->h1E8, o->h1E8->data, o->x74, 0);
            cFileMan_EncodeFilename_charP_cHogFileR_bool(o->h1EC, o->h1EC->data, o->x74, 0);
            cVU1Model_Load(o->model, o->h1E8, o->h1E4);
            LoadCol_00395050(o->col, o->h1EC);
            if (o->model->info->flags & 0x10) {
                o->b1F0 = 0;
                o->b1F1 = 0;
            }
        }
    }
    o->b2E = 0;
    o->b2C = 1;
    cGOBJ_Activate(o, arg);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00395050(void) {}
#undef cFileStreamMan_IsStreamRequestDone /* merge_units */
#undef cFileMan_Read_void /* merge_units */
#undef cFileMan_EncodeFilename_charP_cHogFileR_bool /* merge_units */
#undef cVU1Model_Load /* merge_units */
#undef cCollisionModelMaster_Load /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00395050 */

/* merge_units: begin func_003951A0 */
#pragma push /* merge_units */
/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

void cVUM_GOBJ_NextFrame(void) {
}
static inline void merge_flush_func_003951A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003951A0 */

/* merge_units: begin func_003951B0 */
#pragma push /* merge_units */
#pragma cplusplus on

struct Res3951B0 {
    unsigned int flags;
    char path[0x80];
    short x84;
    int x88;
    int x8C;
    int x90;
    unsigned char b94;
    char* name;
};
struct ModelInfo3951B0 { int x0; unsigned int flags; };
struct Model3951B0 { int loaded; ModelInfo3951B0* info; };

struct Obj3951B0 {
    char p0[0x60];
    struct Obj3951B0* x60;
    int x64;
    Model3951B0* model;
    int p6C;
    void* col;
    char x74[0x16C];
    Res3951B0* res;
    Res3951B0* h1E4;
    Res3951B0* h1E8;
    Res3951B0* h1EC;
    unsigned char b1F0;
    unsigned char b1F1;
    unsigned char b1F2;
};

struct Desc3951B0 {
    Res3951B0* res;
    Res3951B0* res2;
    Obj3951B0* tmpl;
    int xC;
    char* name;
};

extern "C" {
extern char D_004BC440[];
extern char D_004BC448[];
extern char D_004BC450[];
void cVUM_GOBJ_CreateModelData(Obj3951B0* self, int x);
void Libc_Strcpy(char* d, const char* s);
char* strchr(const char* s, int c);
void cFileMan_EncodeFilename_charP_cFileManR(Res3951B0* h, char* path, Res3951B0* r);
int String_CompareNoCase(char* a, char* b);
#if 0 /* merge_units */
int cFileMan_Read_void(Res3951B0* r);
#endif /* merge_units */
#define cFileMan_Read_void(a0) (cFileMan_Read_void((Res394EE0 *)(a0))) /* merge_units */

void cHogFile_Open(void* ctx, void* data, int size, int z);
#if 0 /* merge_units */
void cFileMan_EncodeFilename_charP_cHogFileR_bool(Res3951B0* h, void* data, void* ctx, int z);
#endif /* merge_units */
#define cFileMan_EncodeFilename_charP_cHogFileR_bool(a0, a1, a2, a3) (cFileMan_EncodeFilename_charP_cHogFileR_bool((Hog394EE0 *)(a0), (a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
void cVU1Model_Load(Model3951B0* m, Res3951B0* a, Res3951B0* b);
#endif /* merge_units */
#define cVU1Model_Load(a0, a1, a2) (cVU1Model_Load((Model394EE0 *)(a0), (Hog394EE0 *)(a1), (Hog394EE0 *)(a2))) /* merge_units */

#if 0 /* merge_units */
void cCollisionModelMaster_Load(void* c, Res3951B0* h);
#endif /* merge_units */
#define cCollisionModelMaster_Load(a0, a1) (cCollisionModelMaster_Load((a0), (Hog394EE0 *)(a1))) /* merge_units */

}

static inline void LoadCol_003951B0(void* c, Res3951B0* h) { if (c) cCollisionModelMaster_Load(c, h); }

extern "C" void cVUM_GOBJ_Load(Obj3951B0* self, Desc3951B0* d)
{
    char buf[0x70];
    if (d->name) self->b1F2 = 1; else self->b1F2 = 0;
    Obj3951B0* t = d->tmpl;
    if (t) {
        self->x60 = t;
        self->x64 = t->x64;
        self->model = t->model;
        self->col = t->col;
        self->res = t->res;
        self->h1E4 = t->h1E4;
        self->h1E8 = t->h1E8;
        self->h1EC = t->h1EC;
        self->x64 = d->xC;
        return;
    }
    cVUM_GOBJ_CreateModelData(self, d->xC);
    if (!d->xC) *self->res = *d->res;
    char* base = d->res->path;
    if (d->name) Libc_Strcpy(buf, d->name); else Libc_Strcpy(buf, base);
    Libc_Strcpy(strchr(buf, '.'), D_004BC440);
    cFileMan_EncodeFilename_charP_cFileManR(self->h1E8, buf, self->res);
    if (d->name) Libc_Strcpy(buf, d->name); else Libc_Strcpy(buf, base);
    Libc_Strcpy(strchr(buf, '.'), D_004BC448);
    cFileMan_EncodeFilename_charP_cFileManR(self->h1EC, buf, self->res);
    if (String_CompareNoCase(d->res2->name, d->res->name) == 0) {
        Libc_Strcpy(buf, base);
        Libc_Strcpy(strchr(buf, '.'), D_004BC450);
        cFileMan_EncodeFilename_charP_cFileManR(self->h1E4, buf, self->res);
    } else {
        *self->h1E4 = *d->res2;
    }
    Res3951B0* r = self->res;
    if (!(r->flags & 4)) {
        cHogFile_Open(self->x74, r->path, cFileMan_Read_void(r), 0);
        if (String_CompareNoCase(self->h1E4->name, self->h1E8->name) == 0)
            cFileMan_EncodeFilename_charP_cHogFileR_bool(self->h1E4, self->h1E4->path, self->x74, 0);
        cFileMan_EncodeFilename_charP_cHogFileR_bool(self->h1E8, self->h1E8->path, self->x74, 0);
        cFileMan_EncodeFilename_charP_cHogFileR_bool(self->h1EC, self->h1EC->path, self->x74, 0);
        cVU1Model_Load(self->model, self->h1E8, self->h1E4);
        LoadCol_003951B0(self->col, self->h1EC);
        if (self->model->info->flags & 0x10) {
            self->b1F0 = 0;
            self->b1F1 = 0;
        }
    }
}
#undef cFileMan_Read_void /* merge_units */
#undef cFileMan_EncodeFilename_charP_cHogFileR_bool /* merge_units */
#undef cVU1Model_Load /* merge_units */
#undef cCollisionModelMaster_Load /* merge_units */
static inline void merge_flush_func_003951B0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003951B0 */
