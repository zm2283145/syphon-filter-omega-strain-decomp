/*
 * lib/libinsck: 6 files, 00358578-00358990
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00358578 */
int Insck_MapLibnetError(int e)
{
    switch (e) {
    case 0: return 0;
    case -0x1F4: return 0x74;
    case -0x1F5: return 0x71;
    case -0x1F6: return 0x10;
    case -0x1F7: return 0x73;
    case -0x1F8: return 0xC;
    case -0x1F9:
    case -0x1FA: return 0x7D;
    case -0x1FB: return 0x7F;
    case -0x1FC: return 0x80;
    case -0x1FD: return 0x6E;
    case -0x1FE: return 0x68;
    case -0x1FF: return 0x6F;
    case -0x200:
    case -0x201: return 0x16;
    case -0x202: return 0x76;    }
    return -1;
}
/* merge_units: end func_00358578 */

/* merge_units: begin func_00358678 */
typedef struct T8678 { struct T8678 *next; int x4; int id; } T8678;
typedef struct S8678 { struct S8678 *next; int x4; int id; char pad[0x44]; T8678 *x50; int x54; T8678 *x58; } S8678;
extern S8678 *D_00492CD8;

int func_00358678(void)
{
    int id = 0;
    S8678 *s;
    T8678 *t;
    for (;;) {
        for (s = D_00492CD8; s; s = s->next) {
            if (id == s->id) break;
            for (t = s->x50; t; t = t->next)
                if (id == t->id) break;
            if (t) break;
            for (t = s->x58; t; t = t->next)
                if (id == t->id) break;
            if (t) break;
        }
        if (!s) break;
        id++;
    }
    return id;
}
/* merge_units: end func_00358678 */

/* merge_units: begin func_003586F0 */
typedef struct N81E0 { struct N81E0 *next; struct N81E0 *prev; int tid; int err; int x10; char x14[0x3C]; char *x50; int x54; unsigned int x58; int x5C; int x60; } N81E0;
extern int D_00492CCC;
extern N81E0 *D_00492CD0;
extern N81E0 *D_00492CD4;
extern void func_0034B7E8(void *);
extern void func_00357D88(void *);
extern void *func_00357D50(int);
extern N81E0 *Insck_GetThreadContext(int);
extern int Insck_SetErrno(N81E0 *, int);
extern int sceLibnetInitialize(void *, unsigned int, int, int);

int func_003586F0(unsigned int a, int b, int c)
{
    N81E0 *n = Insck_GetThreadContext(0);
    unsigned int mask;
    int err;
    if (n == 0) return -1;
    mask = 0xFFFFFFC0;
    func_0034B7E8(n->x14);
    func_00357D88(n->x50);
    n->x5C = b;
    n->x60 = c;
    n->x58 = a;
    n->x50 = func_00357D50((a + 0x63) | 0x3F);
    if (n->x50 == 0) {
        N81E0 *x = n->next;
        if (n->prev) n->prev->next = x;
        else D_00492CD0 = x;
        if (n->next) n->next->prev = n->prev;
        else D_00492CD4 = n->prev;
        func_00357D88(n);
        D_00492CCC--;
        return Insck_SetErrno(n, 0xC);
    } else {
        n->x54 = (int)(n->x50 + 0x3F) & -0x40;
        if (sceLibnetInitialize(n->x14, (n->x58 + 0x63) & mask, n->x5C, n->x60) < 0) {
            N81E0 *x = n->next;
            if (n->prev) n->prev->next = x;
            else D_00492CD0 = x;
            if (n->next) n->next->prev = n->prev;
            else D_00492CD4 = n->prev;
            func_00357D88(n);
            D_00492CCC--;
            return Insck_SetErrno(n, 0x16);
        } else {
            return Insck_SetErrno(n, 0);
        }
    }
}
/* merge_units: end func_003586F0 */

/* merge_units: begin func_00358890 */
typedef struct { char pad[0x60]; int f60; } E358890;
#if 0 /* merge_units */
extern int Insck_GetThreadContext(int x);
#endif /* merge_units */
#define Insck_GetThreadContext(a0) ((int)Insck_GetThreadContext((a0))) /* merge_units */

extern E358890* Insck_FindSocket(int a);
#if 0 /* merge_units */
extern int Insck_SetErrno(int h, int c);
#endif /* merge_units */
#define Insck_SetErrno(a0, a1) (Insck_SetErrno((N81E0 *)(a0), (a1))) /* merge_units */

int func_00358890(int a, int b)
{
    int h = Insck_GetThreadContext(0);
    E358890* e;
    if (h == 0) return -1;
    e = Insck_FindSocket(a);
    if (e == 0) return Insck_SetErrno(h, 9);
    e->f60 = b;
    Insck_SetErrno(h, 0);
    return 0;
}
#undef Insck_GetThreadContext /* merge_units */
#undef Insck_SetErrno /* merge_units */
/* merge_units: end func_00358890 */

/* merge_units: begin func_00358910 */
typedef struct { char pad[0x64]; int f60; } E358910;
#if 0 /* merge_units */
extern int Insck_GetThreadContext(int x);
#endif /* merge_units */
#define Insck_GetThreadContext(a0) ((int)Insck_GetThreadContext((a0))) /* merge_units */

#if 0 /* merge_units */
extern E358910* Insck_FindSocket(int a);
#endif /* merge_units */
#define Insck_FindSocket(a0) ((E358910 *)Insck_FindSocket((a0))) /* merge_units */

#if 0 /* merge_units */
extern int Insck_SetErrno(int h, int c);
#endif /* merge_units */
#define Insck_SetErrno(a0, a1) (Insck_SetErrno((N81E0 *)(a0), (a1))) /* merge_units */

int func_00358910(int a, int b)
{
    int h = Insck_GetThreadContext(0);
    E358910* e;
    if (h == 0) return -1;
    e = Insck_FindSocket(a);
    if (e == 0) return Insck_SetErrno(h, 9);
    e->f60 = b;
    Insck_SetErrno(h, 0);
    return 0;
}
#undef Insck_GetThreadContext /* merge_units */
#undef Insck_FindSocket /* merge_units */
#undef Insck_SetErrno /* merge_units */
/* merge_units: end func_00358910 */

/* merge_units: begin func_00358990 */
typedef struct { char pad[0x68]; int f60; } E358990;
#if 0 /* merge_units */
extern int Insck_GetThreadContext(int x);
#endif /* merge_units */
#define Insck_GetThreadContext(a0) ((int)Insck_GetThreadContext((a0))) /* merge_units */

#if 0 /* merge_units */
extern E358990* Insck_FindSocket(int a);
#endif /* merge_units */
#define Insck_FindSocket(a0) ((E358990 *)Insck_FindSocket((a0))) /* merge_units */

#if 0 /* merge_units */
extern int Insck_SetErrno(int h, int c);
#endif /* merge_units */
#define Insck_SetErrno(a0, a1) (Insck_SetErrno((N81E0 *)(a0), (a1))) /* merge_units */

int func_00358990(int a, int b)
{
    int h = Insck_GetThreadContext(0);
    E358990* e;
    if (h == 0) return -1;
    e = Insck_FindSocket(a);
    if (e == 0) return Insck_SetErrno(h, 9);
    e->f60 = b;
    Insck_SetErrno(h, 0);
    return 0;
}
#undef Insck_GetThreadContext /* merge_units */
#undef Insck_FindSocket /* merge_units */
#undef Insck_SetErrno /* merge_units */
/* merge_units: end func_00358990 */
