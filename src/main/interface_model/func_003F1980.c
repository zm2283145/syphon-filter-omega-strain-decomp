#include "types.h"
#include "interface_model_types.h"
typedef struct EVec { int unk0; int count; FloatVec3* data; char unk0C; } EVec;
typedef struct IfModelList {
    IfModelItem base;
    int unk18;
    int unk1C;
    EVec vec;
} IfModelList;
extern char D_004E0800[];
extern char D_004E07A0[];
extern EVec* func_003F1A80(EVec* v);
extern void func_003F3150(EVec* v, int n);
extern FloatVec3* func_003F3DF0(FloatVec3* dst, float** cursor);
extern int func_003F2BC0(EVec* v, FloatVec3* pos, int n, FloatVec3* val);
IfModelList* func_003F1980(IfModelList* self, int a, float** cursor)
{
    EVec* v;
    int n;
    int i;
    self->base.vtable = D_004E0800;
    self->base.unk04 = 0;
    self->base.unk08 = -1.0f;
    self->base.unk0C = -1.0f;
    self->base.unk10 = 0;
    self->base.unk14 = 0;
    self->base.vtable = D_004E07A0;
    self->unk18 = 0;
    self->unk1C = a;
    v = &self->vec;
    func_003F1A80(v);
    v->unk0C = 1;
    n = *(int*)*cursor;
    *cursor = *cursor + 1;
    func_003F3150(v, n);
    for (i = 0; i < n; i++) {
        FloatVec3 tmp;
        func_003F3DF0(&tmp, cursor);
        func_003F2BC0(&self->vec, self->vec.data + self->vec.count, 1, &tmp);
    }
    return self;
}

