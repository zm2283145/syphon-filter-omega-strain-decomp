/*
 * main/gameobj: range (2 files, 00393690-00393760)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00393690 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int func_001A09F0();                        
int func_001A0A10();                               
int func_001A0A30();                               
int func_001A0AD0();                             
int func_001A0AE0();                             
int func_001A0AF0();                          
int func_001A0B10();                          
int func_001A0B20();                             
int func_001AD940();                      

void func_00393690(int arg0) {
    int sp3C;
    int sp38;
    char * sp34;
    int temp_v0;
    int temp_v1_2;
    char * temp_v1;

    temp_v0 = func_001A0B20(arg0 + 0x10);
    func_001A0B10(&sp3C, temp_v0);
    func_001A0AF0(&sp38, temp_v0);
    if (func_001A09F0(&sp3C, &sp38) != 0) {
        do {
            func_001A0A30(func_001A0AD0(func_001A0AE0(&sp3C)));
            func_001A0A10(&sp3C);
        } while (func_001A09F0(&sp3C, &sp38) != 0);
    }
    temp_v1 = (char *)(arg0 + 0x100);
    sp34 = temp_v1;
    temp_v1_2 = F_(*(char * volatile *)&sp34, 0x4, int);
    if (temp_v1_2 != 0) {
        func_001AD940(temp_v1_2 + 8, &sp34);
        F_(sp34, 0x4, int) = 0;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00393690(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00393690 */

/* merge_units: begin func_00393760 */
#pragma push /* merge_units */
#pragma opt_propagation off

typedef struct { float v[4]; } V4;
typedef struct { char p[0x1D8]; } SkelNode;

typedef struct Anim {
    int x0;
    char p4[0xC];
    char x10[0xF0];
    char x100[0x10];
} Anim;

typedef struct Sub2E50 {
    int x0;
    char x4[0x10];
    unsigned char x14;
    char p15[3];
    char x18[0x10];
    int x28;
    char p2c[4];
    char x30[0x20];
    V4 x50;
} Sub2E50;

typedef struct Tail {
    int x0;
    char p4[0xC];
    float mn[4];
    float mx[4];
    int x30;
    int x34;
    char p38[8];
    Sub2E50* x40;
    int x44;
} Tail;

static inline void Tail_ctor(Tail* t, Sub2E50* s)
{
    t->x0 = 0;
    t->mn[0] = 3.4028235e38f;
    t->mn[1] = 3.4028235e38f;
    t->mn[2] = 3.4028235e38f;
    t->mn[3] = 1.0f;
    t->mx[0] = -3.4028235e38f;
    t->mx[1] = -3.4028235e38f;
    t->mx[2] = -3.4028235e38f;
    t->mx[3] = 1.0f;
    t->x30 = 0;
    t->x34 = 0;
    t->x40 = s;
    t->x44 = 0;
}

typedef struct Actor {
    void* vt;
    char p4[0x2B];
    unsigned char x2F;
    int x30;
    char p34[0x2C];
    char x60[0x2E50 - 0x60];
    Sub2E50 x2E50;
    int x2EB0;
    char p2EB4[0xC];
    Anim x2EC0;
    char p2FD0[0x2FE0 - 0x2EC0 - sizeof(Anim)];
    Tail x2FE0;
} Actor;

extern char D_004DF740[];
extern void cGOBJ_ctor(Actor* self, int* name, int type, int* extra);
extern void func_00392380(void*);
extern void func_00393FA0(void*);
extern void SkelNode_Construct(SkelNode*);
extern void func_00393F30(void*, int, SkelNode*);
extern void func_003BA9A0(SkelNode*, int);
extern void Bounds_SetEmpty(void*);
extern void Vec4_SetOrigin(V4*);
extern void Vec4_Assign(V4*, V4*);
extern void func_00393A40(void*, void*, void*);
extern void func_003939D0(void*, Anim**);
extern void AnimModel_InitAnim(Anim*);

static inline void Anim_ctor(Anim* a, void* owner)
{
    a->x0 = 0;
    func_00393A40(a->x10, owner, 0);
    func_003939D0(a->x100, &a);
    AnimModel_InitAnim(a);
}

Actor* Actor_Construct(Actor* me, int* name, int* extra)
{
    Sub2E50* s;
    Actor* self = me;
    cGOBJ_ctor(me, name, 2, extra);
    self->vt = D_004DF740;
    func_00392380(self->x60);
    s = &self->x2E50;
    s->x0 = 0;
    func_00393FA0(s->x4);
    s->x14 = 0;
    {
        SkelNode n;
        SkelNode_Construct(&n);
        func_00393F30(s->x18, 0, &n);
        func_003BA9A0(&n, -1);
    }
    s->x28 = 0;
    Bounds_SetEmpty(s->x30);
    {
        V4 v;
        Vec4_SetOrigin(&v);
        Vec4_Assign(&s->x50, &v);
    }
    self->x2EB0 = 0xDEADBEEF;
    Anim_ctor(&self->x2EC0, &self->x2E50);
    Tail_ctor(&self->x2FE0, &self->x2E50);
    self->x2F = 1;
    self->x30 = 0;
    return self;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00393760(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00393760 */
