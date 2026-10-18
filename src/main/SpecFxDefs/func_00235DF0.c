#include "types.h"
typedef struct { int x0; int x4; int x8; } L_35DF0;
typedef struct { int f0; char p4[43]; signed char f2F; char p30[48]; int f60; int f64; short f68; char p6A[6]; int f70; L_35DF0 list; unsigned char f80; char p81[0xA0 - 0x81]; int fA0; float fA4; float fA8; float fAC; float fB0; float fB4; } S_35DF0;
extern char D_004DF860[];
extern char D_004DBC70[];
int IdMgr_Allocate(int*, int);
int cGOBJ_ctor(S_35DF0*, int*, int, int*);
void ScalarCollection_Init(L_35DF0*);
void ObjectList_EraseRange(int* out, L_35DF0* l, int* first, int** last);
float Math_Asinf(float);
S_35DF0* SmokeField_Construct(S_35DF0* self, unsigned char kind, float a, float b, float c, float d)
{
    int id;
    int z;
    int r;
    int first;
    int* last;
    IdMgr_Allocate(&id, 0xE7);
    z = 0;
    cGOBJ_ctor(self, &id, 4, &z);
    self->f0 = (int)D_004DF860;
    self->f60 = -1;
    self->f64 = 0;
    self->f68 = 0;
    self->f70 = 0x3F800000;
    self->f2F = 1;
    self->f0 = (int)D_004DBC70;
    ScalarCollection_Init(&self->list);
    last = &self->list.x4;
    first = self->list.x8;
    ObjectList_EraseRange(&r, &self->list, &first, &last);
    self->f80 = kind;
    self->fA8 = a;
    self->fAC = b + a;
    self->fB0 = c + self->fA8;
    self->fB4 = d;
    self->fA4 = 2.0f * Math_Asinf(a / (2.0f * c));
    self->fA0 = (int)(0.5f + 1.5707964f / self->fA4);
    return self;
}
