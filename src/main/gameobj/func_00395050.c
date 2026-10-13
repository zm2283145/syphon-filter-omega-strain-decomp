#include "types.h"

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

extern void* func_003EBA50(void);
extern void func_003EAA40(void* mgr, Res395050* r);
extern int FileMan_ReadData(Res395050* r);
extern void func_0036D540(void* ctx, void* data, int size, int z);
extern int String_CompareNoCase(char* a, char* b);
extern void Hog_Register(Hog395050* h, void* data, void* ctx, int z);
extern void Model_Load(Model395050* m, Hog395050* a, Hog395050* b);
extern void Col_Load(void* c, Hog395050* h);
extern void Object_Activate(Obj395050* o, int arg);

static inline void LoadCol(void* c, Hog395050* h) { if (c) Col_Load(c, h); }
static inline unsigned char Model_IsLoaded(Model395050* m) { return m->loaded != 0; }

void func_00395050(Obj395050* o, int arg)
{
    Res395050* r = o->res;
    if (r->flags & 4) {
        if (!Model_IsLoaded(o->model)) {
            func_003EAA40(func_003EBA50(), r);
            r = o->res;
            func_0036D540(o->x74, r->data, FileMan_ReadData(r), 0);
            if (String_CompareNoCase(o->h1E4->name, o->h1E8->name) == 0)
                Hog_Register(o->h1E4, o->h1E4->data, o->x74, 0);
            Hog_Register(o->h1E8, o->h1E8->data, o->x74, 0);
            Hog_Register(o->h1EC, o->h1EC->data, o->x74, 0);
            Model_Load(o->model, o->h1E8, o->h1E4);
            LoadCol(o->col, o->h1EC);
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


