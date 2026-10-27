#pragma cplusplus on
#include "types.h"

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
int cFileMan_Read_void(Res3951B0* r);
void cHogFile_Open(void* ctx, void* data, int size, int z);
void cFileMan_EncodeFilename_charP_cHogFileR_bool(Res3951B0* h, void* data, void* ctx, int z);
void cVU1Model_Load(Model3951B0* m, Res3951B0* a, Res3951B0* b);
void cCollisionModelMaster_Load(void* c, Res3951B0* h);
}

static inline void LoadCol(void* c, Res3951B0* h) { if (c) cCollisionModelMaster_Load(c, h); }

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
        LoadCol(self->col, self->h1EC);
        if (self->model->info->flags & 0x10) {
            self->b1F0 = 0;
            self->b1F1 = 0;
        }
    }
}

