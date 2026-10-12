#include "types.h"
#pragma cplusplus on
typedef struct VT3D1B60 { int a, b, c; void (*fn)(void*); } VT3D1B60;
typedef struct { int kind; float rate; } A3D1B60;
typedef struct { char pad[0x44]; struct { char pad[0x22]; unsigned short count; }* info; } E3D1B60;
typedef struct { int a, b; E3D1B60** list; } M3D1B60;
typedef struct {
    int id; A3D1B60* a; int b; int c; VT3D1B60* vt;
    int count; int first; int last; int kind; float inv; int cur; int step;
} S3D1B60;
extern VT3D1B60 D_004E0080;
extern VT3D1B60 D_004E0060;
extern M3D1B60* D_00539248;
class C3D1B60 { public: int id; void* a; int b; int c; virtual void s0(); virtual void s1(); };
extern "C" S3D1B60* func_003D1B60(S3D1B60* o, A3D1B60* a, int b, int c, int id) {
    o->vt = &D_004E0080;
    o->id = id;
    o->a = a;
    o->b = b;
    o->c = c;
    o->vt = &D_004E0060;
    o->kind = a->kind;
    o->inv = 1.0f / a->rate;
    o->count = D_00539248->list[id]->info->count;
    o->first = 0;
    o->last = o->count - 1;
    switch (o->kind) {
    case 0: case 2: case 4:
        o->cur = o->first;
        o->step = 1;
        break;
    case 1: case 3:
        o->cur = o->last;
        o->step = -1;
        break;
    case 5:
    default:
        o->cur = o->first;
        o->step = 0;
        break;
    }
    ((C3D1B60*)o)->s1();
    return o;
}