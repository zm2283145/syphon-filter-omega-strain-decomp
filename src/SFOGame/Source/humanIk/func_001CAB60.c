#pragma cplusplus on
#pragma inline_depth(8)
#pragma opt_rebuildconditionals off
#pragma opt_rotateloops off
#pragma opt_propagation off
#pragma opt_strength_reduction off
#include "types.h"

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
