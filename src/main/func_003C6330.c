#include "types.h"
typedef struct F1V3_6330 { float x, y, z; } F1V3_6330;
typedef struct F1Shape6330 { char pad0[2]; signed char kind; char pad3; int count; } F1Shape6330;
typedef struct F1Holder6330 { F1Shape6330* shape; } F1Holder6330;
typedef struct F1Obj6330 { int pad0; F1Holder6330* holder; } F1Obj6330;
extern char D_00542D10[];
extern void* func_003C6420(void* tab, int n);
extern void func_003C62F0(void* p, int arg);
extern void func_003C6410(void);
extern int func_001828B0(F1Shape6330* s);
extern int func_00182880(F1Shape6330* s);
extern void func_003C5EA0(F1Shape6330* s, F1V3_6330* v, int n, int arg);
extern void func_003C5BD0(F1Shape6330* s, F1V3_6330* v, int n, int arg);
void func_003C6330(F1Obj6330* obj, F1V3_6330* pos, int arg)
{
    F1V3_6330 v;
    F1Shape6330* s;
    v = *pos;
    *(F1Obj6330**)&v.y = obj;
    s = obj->holder->shape;
    if (s->kind == 0x46) {
        func_003C62F0(func_003C6420(D_00542D10, 0), arg);
        func_003C6410();
        if (s->count > 0) {
            func_003C5EA0(s, &v, func_001828B0(s), arg);
        } else {
            func_003C5BD0(s, &v, func_00182880(s), arg);
        }
    }
}