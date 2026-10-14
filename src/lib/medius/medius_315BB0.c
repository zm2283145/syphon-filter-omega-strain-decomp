/*
 * lib/medius: 3 files, 00315BB0-00315CF8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00315BB0 */
typedef struct { int a; int b; int c; int result; int user; } Req5BB0;
typedef struct Obj5BB0 {
    char pad0[9];
    unsigned char state;
    char pad1[0x54 - 10];
    void (*cb)(Req5BB0 *);
    int user;
    char pad2[0xA9 - 0x5C];
    unsigned char mode;
} Obj5BB0;
extern int func_003150D0(int id, Obj5BB0 **out);
int func_00315BB0(int id, int a, int b, int c)
{
    Obj5BB0 *o = 0;
    Req5BB0 r;
    if (a == 0) return -1;
    if (b == 0) return -1;
    if (c == 0) return -1;
    if (func_003150D0(id, &o) != 0) return -1;
    r.result = 0;
    if (o->cb && o->state == 1 && o->mode == 1) {
        r.user = o->user;
        r.a = a;
        r.b = b;
        r.c = c;
        o->cb(&r);
    }
    return r.result;
}
/* merge_units: end func_00315BB0 */

/* merge_units: begin func_00315C60 */
typedef struct { int a; int b; int result; int user; } Req5C60;
typedef struct Obj5C60 {
    char pad0[9];
    unsigned char state;
    char pad1[0x5C - 10];
    void (*cb)(Req5C60 *);
    int user;
    char pad2[0xA9 - 0x64];
    unsigned char mode;
} Obj5C60;
#if 0 /* merge_units */
extern int func_003150D0(int id, Obj5C60 **out);
#endif /* merge_units */
#define func_003150D0(a0, a1) (func_003150D0((a0), (Obj5BB0 * *)(a1))) /* merge_units */

int func_00315C60(int id, int a, int b)
{
    Obj5C60 *o = 0;
    Req5C60 r;
    if (b == 0) return -1;
    if (func_003150D0(id, &o) != 0) return -1;
    r.result = 0;
    if (o->cb && o->state == 1 && o->mode == 1) {
        int u = o->user;
        r.a = a;
        r.b = b;
        r.user = u;
        o->cb(&r);
    }
    return r.result;
}
#undef func_003150D0 /* merge_units */
/* merge_units: end func_00315C60 */

/* merge_units: begin func_00315CF8 */
typedef struct { char pad[4]; unsigned int flags; } Ent5CF8;
typedef struct {
    char pad[4];
    int count;
    char pad1[0xA4 - 8];
    int sock;
    unsigned char bA8;
    unsigned char bA9;
    char pad2[2];
    char info[0x3C];
    char addr[0x10];
    int user;
} Obj5CF8;
#if 0 /* merge_units */
extern int func_003150D0(int sock, Obj5CF8 **out);
#endif /* merge_units */
#define func_003150D0(a0, a1) (func_003150D0((a0), (Obj5BB0 * *)(a1))) /* merge_units */

extern void func_002F4E20(int a, char *dst);
extern int func_002F4F90(int sock, int *out);
extern int func_002F4FB0(int sock, int sz, char *info);
extern int func_003151D8(Obj5CF8 *o, int i, Ent5CF8 **out);
extern int func_00315818(Obj5CF8 *o, Ent5CF8 *e);
extern int func_00315E28(int r, int code);
int func_00315CF8(int sock, int a, int user)
{
    Obj5CF8 *o = 0;
    int x;
    Ent5CF8 *e;
    int i, r;
    if (func_003150D0(sock, &o) != 0) return -1;
    {
        Obj5CF8 *p = o;
        p->user = user;
        func_002F4E20(a, p->addr);
    }
    r = func_00315E28(func_002F4F90(o->sock, &x), 0x2A);
    if (r != 0) return r;
    r = func_00315E28(func_002F4FB0(o->sock, x, o->info), 0x2A);
    if (r != 0) return r;
    o->bA8 = 1;
    o->bA9 = 1;
    for (i = 0; i < o->count; i++) {
        r = func_003151D8(o, i, &e);
        if (r != 0) return r;
        if ((e->flags & 0xFF00FF) == 1) {
            r = func_00315818(o, e);
            if (r != 0) return r;
        }
    }
    return 0;
}
#undef func_003150D0 /* merge_units */
/* merge_units: end func_00315CF8 */
