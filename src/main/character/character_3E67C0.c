/*
 * main/character: 2 files, 003E67C0-003E6910
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E67C0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { void* vt; char pad04[0x18]; int x1C; char pad20[4]; int cat; signed char kind; char pad29[3]; int id; int x30; float val; unsigned char flag; char pad39[3]; } Msg_3E67C0;
typedef struct { char pad0[0x30]; void* owner; } Pt2_Tgt;
typedef struct { char pad0[0xC]; int id; } Pt2_Hd;
extern int D_0055A840;
const float D_00493938[2] = { -1.0f, 0.0f };
const float D_00493940[2] = { -2.0f, 0.0f };
extern char D_0055D480[];
extern char D_004E0160[];
extern char D_004E0840[];
extern int* Receiver_GetOwner(void);
extern void Event_Construct(Msg_3E67C0* m, void* type);
extern void Event_Send(Msg_3E67C0* m, void* target, int x);
extern void cMessage_dtor(Msg_3E67C0* m, int f);

void ObjectAction_SendKind7(Pt2_Tgt* t, char cat, Pt2_Hd* h, unsigned char flag, float val) {
    int tmp[1];
    int* idp;
    Msg_3E67C0 m;
    { int k = *Receiver_GetOwner(); if (k == D_0055A840) t = (Pt2_Tgt*)t->owner; }
    if (val == (*(float*)D_00493938)) val = -1.0f;
    else if (val == (*(float*)D_00493940)) val = 3.4028235e38f;
    if (h) idp = &h->id;
    else { tmp[0] = -1; idp = tmp; }
    Event_Construct(&m, D_0055D480);
    m.cat = cat;
    m.kind = 7;
    m.vt = D_004E0160;
    m.id = *idp;
    m.val = val;
    m.x30 = -1;
    m.x1C = 0x40;
    m.flag = flag;
    Event_Send(&m, t, 0);
    m.vt = D_004E0840;
    cMessage_dtor(&m, 0);
}
#pragma pop /* merge_units */
/* merge_units: end func_003E67C0 */

/* merge_units: begin func_003E6910 */
#pragma push /* merge_units */
#include "canonical_key_copy.h"
typedef struct { unsigned int w[3]; } Str_3E6910;
typedef struct { char* p; } It_3E6910;
typedef struct { char c[0x30]; } __attribute__((aligned(16))) Key_3E6910;
typedef struct { void* vt; char pad04[0x18]; int x1C; unsigned char x20; char pad21[3]; int cat; signed char kind; char pad29[3]; int id; Key_3E6910 key; float val; unsigned char flag; } Msg_3E6910;
extern const float D_00493938[2];
extern const float D_00493940[2];
extern char D_004DA910[];
#if 0 /* merge_units */
extern void Event_Construct(Msg_3E6910* m, void* type);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((Msg_3E67C0 *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void Event_Send(Msg_3E6910* m, void* target, int x);
#endif /* merge_units */
#define Event_Send(a0, a1, a2) (Event_Send((Msg_3E67C0 *)(a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(Msg_3E6910* m, int f);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((Msg_3E67C0 *)(a0), (a1))) /* merge_units */

extern void String_CtorCStr_13B480(Str_3E6910* s, const char* c);
extern void func_0013D680(Str_3E6910* d, Str_3E6910* s);
extern void String_Dtor(Str_3E6910* s, int f);
extern void func_001BFF20(It_3E6910* out, Str_3E6910* s);
extern void func_001BFEE0(It_3E6910* out, Str_3E6910* s);
extern int func_001BFE90(It_3E6910* a, It_3E6910* b);
extern char* func_001BFED0(It_3E6910* a);
extern void func_001BFEB0(It_3E6910* a);
extern char* String_CStr(Str_3E6910* s);

static inline void KQ_Copy(void* dd, void* ss, int nn)
{
    int n = nn; void* d = dd; void* s = ss; __int128 q;
    asm {
        .set noreorder
    lp:
        lq q, 0(s)
        addiu d, d, 0x10
        addi n, n, -1
        addiu s, s, 0x10
        bgtz n, lp
        sq q, -0x10(d)
        .set reorder
    }
}
static inline Msg_3E6910* Msg_Init(Msg_3E6910* self, char cat, int* idp, Key_3E6910* key, float val, unsigned char flag)
{
    Event_Construct(self, D_0055D480);
    self->vt = D_004E0840;
    self->cat = cat;
    self->kind = 10;
    self->vt = D_004DA910;
    self->id = *idp;
    {
        int n = 3; void* s = key; void* d = &self->key; __int128 q;
        asm {
            .set noreorder
        lp:
            lq q, 0(s)
            addiu d, d, 0x10
            addi n, n, -1
            addiu s, s, 0x10
            bgtz n, lp
            sq q, -0x10(d)
            .set reorder
        }
    }
    self->val = val;
    self->flag = flag;
    return self;
}
static inline void Str_Ctor(Str_3E6910* self) { unsigned int i; for (i = 0; i < 3; i++) self->w[i] = 0; }
#pragma push
#pragma opt_common_subs off
#pragma opt_rotateloops off
#pragma opt_unroll_loops off
#pragma opt_strength_reduction off
#pragma opt_propagation off
void Global_PerformAction_WithObject(Pt2_Tgt* t, char cat, Pt2_Hd* h, const char* name, unsigned char flag, float val)
{
    Msg_3E6910* pm;
    int tmp[1];
    int* idp;
    Msg_3E6910 m;
    Key_3E6910 key;
    Str_3E6910 s;
    It_3E6910 it;
    It_3E6910 end;
    { int k = *Receiver_GetOwner(); if (k == D_0055A840) t = (Pt2_Tgt*)t->owner; }
    if (val == (*(float*)D_00493938)) val = -1.0f;
    else if (val == (*(float*)D_00493940)) val = 3.4028235e38f;
    { Str_3E6910* ps = &s; Str_Ctor(ps); }
    if (*name) {
        Str_3E6910 t1;
        cat = 0x25;
        String_CtorCStr_13B480(&t1, name);
        func_0013D680(&s, &t1);
        String_Dtor(&t1, 0);
        func_001BFF20(&it, &s);
        func_001BFEE0(&end, &s);
        while (func_001BFE90(&it, &end)) {
            if (*func_001BFED0(&it) >= 'A' && *func_001BFED0(&it) <= 'Z') *func_001BFED0(&it) += 0x20;
            func_001BFEB0(&it);
        }
    } else {
        Str_3E6910 t2;
        String_CtorCStr_13B480(&t2, name);
        func_0013D680(&s, &t2);
        String_Dtor(&t2, 0);
    }
    {
        char* c = String_CStr(&s);
        CANONICAL_KEY_INIT(key.c, c)
    }
    if (h) idp = &h->id;
    else { tmp[0] = -1; idp = tmp; }
    pm = &m; Msg_Init(pm, cat, idp, &key, val, flag);
    m.x20 = 1;
    m.x1C = 0x40;
    Event_Send(&m, t, 0);
    m.vt = D_004E0840;
    cMessage_dtor(&m, 0);
    String_Dtor(&s, 0);
}
#pragma pop
#undef Event_Construct /* merge_units */
#undef Event_Send /* merge_units */
#undef cMessage_dtor /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E6910 */
