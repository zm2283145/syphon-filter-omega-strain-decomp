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

extern void* func_003EBA50(void);
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
