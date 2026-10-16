/*
 * main/gobj: 5 files, 003D1950-003D1E70
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003D1950 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

void func_003D1950(char* self) {
    *(int*)(self + 48) = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D1950 */

/* merge_units: begin func_003D1960 */
#pragma push /* merge_units */
typedef struct { char pad[0x22]; unsigned short count; } Clip;
typedef struct { char pad[0x44]; Clip* clip; char pad48[4]; int frame; char pad50[0x10]; unsigned char b60, b61; } Anim;
typedef struct { char pad[8]; Anim** anims; } AnimTbl;
typedef struct {
    int idx;
    char pad4[0x10];
    unsigned int range;
    int min;
    int max;
    int mode;
    float period;
    int value;
    int step;
    float timer;
} Seq;
extern AnimTbl* D_00539248;
int Random_Next(void);
static inline float RandF() { return (float)Random_Next() / 2147483648.0f; }

void TexFrameAnim_Update(Seq* s, float dt)
{
    Anim* a;
    int v;
    s->timer += dt;
    if (!(s->timer <= s->period)) {
        s->timer -= s->period;
        s->value += s->step;
        switch (s->mode) {
        case 0:
            if (s->value > s->max) {
                s->value = s->max;
                s->step = 0;
            }
            break;
        case 1:
            if (s->value < s->min) {
                s->value = s->min;
                s->step = 0;
            }
            break;
        case 2:
            if (s->value > s->max)
                s->value = s->min;
            break;
        case 3:
            if (s->value < s->min)
                s->value = s->max;
            break;
        case 4:
            if (s->value < s->min || s->value > s->max) {
                s->step = -s->step;
                s->value += s->step;
            }
            break;
        case 5:
            { int r = Random_Next(); s->value = (int)((float)s->range * ((float)r / 2147483648.0f)); }
            break;
        }
    }
    { int i = s->idx; v = s->value; a = D_00539248->anims[i]; }
    if (v != a->frame && (unsigned int)v < a->clip->count) {
        a->b60 = 0;
        a->b61 = 0;
        a->frame = v;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_003D1960 */

/* merge_units: begin func_003D1B60 */
#pragma push /* merge_units */
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
#if 0 /* merge_units */
extern M3D1B60* D_00539248;
#endif /* merge_units */
#define D_00539248 (*(M3D1B60 **)&D_00539248) /* merge_units */

class C3D1B60 { public: int id; void* a; int b; int c; virtual void s0(); virtual void s1(); };
extern "C" S3D1B60* Material_Animate(S3D1B60* o, A3D1B60* a, int b, int c, int id) {
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
#undef D_00539248 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003D1B60 */

/* merge_units: begin func_003D1C80 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)

/* 16-byte quad copy (lq/sq have no C equivalent). */
static inline void Q16(void* d, const void* s) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(d), "r"(s) : "memory"); }

struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    /* The unused xx keeps retail's dead destination-address addiu. */
    V& operator=(const V& o) { void* xx = this; Q16(this, &o); return *this; }
} __attribute__((aligned(16)));
struct Mat { char pad[0x10]; V uv; };
struct Scroll { char pad[8]; Mat* a; Mat* b; char pad10[4]; float du; float dv; };

static inline void Wrap(V& v)
{
    if (v.x > 1.0f) v.x -= 1.0f;
    if (v.y > 1.0f) v.y -= 1.0f;
    if (v.x < -1.0f) v.x += 1.0f;
    if (v.y < -1.0f) v.y += 1.0f;
}

extern "C" void UvScrollAnim_Update(Scroll* s, float dt)
{
    float du = s->du * dt;
    float dv = s->dv * dt;
    Mat* a = s->a;
    Mat* b = s->b;
    a->uv = V(a->uv.x + du, a->uv.y + dv, 0.0f, 0.0f);
    b->uv = V(b->uv.x + du, b->uv.y + dv, 0.0f, 0.0f);
    Wrap(a->uv);
    Wrap(b->uv);
}
#pragma pop /* merge_units */
/* merge_units: end func_003D1C80 */

/* merge_units: begin func_003D1E70 */
#pragma push /* merge_units */
#pragma peephole off

typedef struct Pair10 {
    char pad[0x10];
    int a;
    int b;
} Pair10;

typedef struct Link2 {
    char pad[8];
    Pair10* first;
    Pair10* second;
} Link2;

/* Clears the two words at +0x10/+0x14 of both linked objects. */
void UvScrollAnim_Init(Link2* l) {
    Pair10* a = l->first;
    Pair10* b = l->second;
    a->a = 0;
    a->b = 0;
    b->a = 0;
    b->b = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003D1E70 */
