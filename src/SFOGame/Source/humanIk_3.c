/*
 * SFOGame/Source/humanIk: 5 files, 001CAB30-001CB120
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001CAB30 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

/* Address of element index (0x20-byte records). */
Elem20* cHermiteSpline_cQuaternion_ControlPoint(Elem20* base, int index) {
    return base + index;
}

/* Address of element index (0x1C0-byte records). */
Elem1C0* cArray_FixedSize_cIkTargetWithSplinedTransition_2_opIndex(Elem1C0* base, int index) {
    return base + index;
}
static inline void merge_flush_func_001CAB30(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CAB30 */

/* merge_units: begin func_001CAB60 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma inline_depth(8)
#pragma opt_rebuildconditionals off
#pragma opt_rotateloops off
#pragma opt_propagation off
#pragma opt_strength_reduction off

struct Slot {
    int clip;
    int owner;
    float rate;
    float t0C;
    int w10;
    float t14;
    int w18;
    int w1C;
    unsigned char b20;
    Slot() { Slot* p = this; p->clip = 0; p->owner = 0; p->t0C = 0; p->w10 = 0; p->t14 = 0; p->w18 = 0; p->w1C = 0; p->b20 = 0; }
};

struct SlotBuf { int w[9]; };
struct Key {
    char name[0x30];
} __attribute__((aligned(16)));

struct Entry { char* a; Key* volatile b; };
struct Item { char pad[4]; unsigned char disabled; char pad5[0x24 - 5]; int clip; };
struct Owner { char pad[0x34]; int reg; };
struct Holder { Owner* owner; };
struct Self {
    char pad0[4];
    int* p4;
    char pad8[4];
    Holder* pC;
    char pad10[4];
    Entry ent[25];
    char padDC[4];
    Slot prev;
    char pad104[0xC];
    Slot cur;
    char pad134[0x310 - 0x134];
    unsigned char prevIdx;
    unsigned char idx;
};

extern "C" {
extern signed char D_004E9FB0;
extern Key D_004E9FC0;
int cSkaAnimationSet_GetNodeId(Owner* m, Key* k);
Item** cArray_cSkaNodePtr_opIndex(int* reg, int idx);
void cSkaAnimDataIterator_ctor_cSkaAnimDataR_cSkeletonDataR(Slot* s, int clip, int owner);
void cSkaAnimDataIterator_opAssign(Slot* d, Slot* s);
void cSkaAnimDataIterator_dtor(Slot* s, int f);
}

static inline void QZero_CAB60(void* dd, int nn)
{
    int n = nn; void* d = dd;
    asm {
        .set noreorder
    lp:
        nop
        addi n, n, -1
        sq $zero, 0(d)
        bgtz n, lp
        addiu d, d, 0x10
        .set reorder
    }
}

static inline void QCopy_CAB60(void* d0, const void* s0)
{
    int n = 3; const void* s = s0; void* d = d0;
    asm {
        .set noreorder
    lp:
        lq $a0, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq $a0, -0x10(d)
        .set reorder
    }
}

static inline bool QEq_CAB60(const __int128* a, const __int128* b, unsigned int m)
{
    __int128 y; __int128 x; unsigned int r;
    asm {
        .set noreorder
        lq x, 0(a)
        lq y, 0(b)
        .set reorder
    }
    asm {
        pceqw x, x, y
        ppach r, x, x
    }
    bool res = !(r < m);
    return res;
}

static inline const Key& EntryName(Entry* e)
{
    if (e->b) return *e->b;
    if (e->a) return *(Key*)(e->a + 0x10);
    if (!D_004E9FB0) {
        QZero_CAB60(&D_004E9FC0, 3);
        D_004E9FB0 = 1;
    }
    return D_004E9FC0;
}

static inline bool KeyNe(const Key& a, const Key& b);
static inline bool KeyEq(const Key& a, const Key& b)
{
    if (a.name[0] || b.name[0]) {
        unsigned int i;
        i = 0;
        for (; i < 3; i++) {
            if (!QEq_CAB60(&((const __int128*)a.name)[(unsigned)i], &((const __int128*)b.name)[(unsigned)i], 0xFFFFFFFFu)) return false;
        }
    }
    return true;
}

static inline float SlotPhase(Slot* ss)
{
    Slot* s = ss;
    if (s->clip) return s->t0C / (float)((int*)s->clip)[1];
    return -1.0f;
}

extern "C" float Secondary_MotionPhase(Self* self, const Key* key)
{
    if (KeyEq(*key, EntryName((Entry*)((char*)self->ent + self->idx * sizeof(Entry))))) {
        if (self->prevIdx != self->idx) {
            Slot* s = &self->cur;
            if (s->clip) return s->t0C / (float)((int*)s->clip)[1];
            return -1.0f;
        }
    }
    if (KeyEq(*key, EntryName((Entry*)((char*)self->ent + self->prevIdx * sizeof(Entry))))) {
        Slot* s = &self->prev;
        if (s->clip) return s->t0C / (float)((int*)s->clip)[1];
        return -1.0f;
    }
    return -1.0f;
}
static inline void merge_flush_func_001CAB60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CAB60 */

/* merge_units: begin func_001CAE10 */
#pragma push /* merge_units */
/* Copy byte +0x313 into +0x312. */
void cHumanIkRoutine_StopUpperBodyAnimation(Unk001CAE10* self) {
    self->unk312 = self->unk313;
}
static inline void merge_flush_func_001CAE10(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CAE10 */

/* merge_units: begin func_001CAE20 */
#pragma push /* merge_units */
#pragma cplusplus on
/* 48-byte key copies (3 qwords). The two inlines differ only in local order, which
   sets the register assignment: assignment uses the first, the copy after allocation the second. */
static inline void KeyQCopy(void* d, void* s, int n) {
    __int128 t;
    asm {
        .set noreorder
    lp:
        lq t, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq t, -0x10(d)
        .set reorder
    }
}
static inline void KeyQCopyNew(void* dd, void* s, int nn) {
    int n = nn; __int128 t; void* d = dd;
    asm {
        .set noreorder
    lp:
        lq t, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq t, -0x10(d)
        .set reorder
    }
}
typedef union { char s[48]; __int128 q[3]; } Name;
typedef struct { int pad; Name *p; } Slot_001CAE20;
typedef struct {
    char pad[0x24];
    int a;
    signed char b;
    char pad2[3];
    int c;
    unsigned char d;
    char pad3[3];
    float e;
} Params;
typedef struct {
    char pad0[0xBC];
    Slot_001CAE20 s1;
    Slot_001CAE20 s3;
    char pad1[0x310 - 0xCC];
    unsigned char k[3];
    char pad2[0x350 - 0x313];
    int a1; signed char b1; char q1[3]; int c1; unsigned char d1; char r1[3]; float e1;
    char pad3[0x388 - 0x364];
    int a3; signed char b3; char q3[3]; int c3; unsigned char d3; char r3[3]; float e3;
} Obj;

#include "alloc_guard.h"
extern "C" void* cMemMan_Allocate(int, int, char*, int);
extern "C" char D_004A0308[];

extern "C" int Secondary_RequestOneShot(Obj *o, Name *src, unsigned char kind, Params *p)
{
    switch (kind) {
    case 1: {
        Slot_001CAE20 *s;
        if (o->k[0] != 0x15 && o->k[1] != 0x15 && o->k[2] != 0x15) {
        o->k[2] = 0x15;
        s = &o->s1;
        if (s->p == 0) {
            Name *t;
            {
                AllocGuard g;
                t = (Name *)cMemMan_Allocate(0, 0x30, D_004A0308, 0x569);
            }
            if (t) KeyQCopyNew(t, src, 3);
            s->p = t;
        } else if (s->p->s[0] || src->s[0]) {
            KeyQCopy(s->p, src, 3);
        }
        o->a1 = p->a; o->b1 = p->b; o->c1 = p->c; o->d1 = p->d; o->e1 = p->e;
        return 1;
        }
        return 0;
    }
    case 3: {
        Slot_001CAE20 *s;
        if (o->k[0] != 0x16 && o->k[1] != 0x16 && o->k[2] != 0x16) {
        o->k[2] = 0x16;
        s = &o->s3;
        if (s->p == 0) {
            Name *t;
            {
                AllocGuard g;
                t = (Name *)cMemMan_Allocate(0, 0x30, D_004A0308, 0x569);
            }
            if (t) KeyQCopyNew(t, src, 3);
            s->p = t;
        } else if (s->p->s[0] || src->s[0]) {
            KeyQCopy(s->p, src, 3);
        }
        o->a3 = p->a; o->b3 = p->b; o->c3 = p->c; o->d3 = p->d; o->e3 = p->e;
        return 1;
        }
        return 0;
    }
    }
    return 0;
}
static inline void merge_flush_func_001CAE20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CAE20 */

/* merge_units: begin func_001CB120 */
#pragma push /* merge_units */
typedef struct { char pad[0x312]; unsigned char state; unsigned char req; } Obj_001CB120;
void cHumanIkRoutine_SetAimWeaponMode(Obj_001CB120* o, unsigned char s) {
    o->req = s;
    if (o->state != 0x15 && o->state != 0x16 && o->state != 0x18) {
        o->state = s;
    }
}
static inline void merge_flush_func_001CB120(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001CB120 */
