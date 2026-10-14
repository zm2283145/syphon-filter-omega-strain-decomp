/*
 * lib/medius: 11 files, 00314180-00314CB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00314180 */
typedef struct { char pad[0xA4]; int sock; } Obj4180;
extern short D_00491432;
extern unsigned char D_00491430;
extern int func_00315028(int id, Obj4180 **out);
extern int func_00315608(int h, int *out);
extern int func_002F5080(int sock, int h, int a, int b);
extern int func_00315E28(int r, int code);
int func_00314180(int id, int h)
{
    Obj4180 *o;
    int t;
    int r;
    if (D_00491432 <= 0) return 0x11;
    if (D_00491430 != 1) return 0x11;
    r = func_00315028(id, &o);
    if (r != 0) return r;
    r = func_00315608(h, &t);
    if (r != 0) return r;
    return func_00315E28(func_002F5080(o->sock, t, 0, 0), 0x2A);
}
/* merge_units: end func_00314180 */

/* merge_units: begin func_00314208 */
typedef struct { char pad[0xA4]; int sock; char pad2[1]; unsigned char mode; } Obj4208;
#if 0 /* merge_units */
extern int func_00315028(int id, Obj4208 **out);
#endif /* merge_units */
#define func_00315028(a0, a1) (func_00315028((a0), (Obj4180 * *)(a1))) /* merge_units */

extern int func_002F5050(int sock);
int func_00314208(int id, int *out)
{
    Obj4208 *o;
    int st;
    int r;
    if (D_00491432 <= 0) return 0x11;
    st = D_00491430;
    if (st != 1) return 0x11;
    if (out == 0) return 0x17;
    r = func_00315028(id, &o);
    if (r != 0) return r;
    if ((func_002F5050(o->sock) & 8) && o->mode == st) *out = o->mode;
    else *out = 0;
    return 0;
}
#undef func_00315028 /* merge_units */
/* merge_units: end func_00314208 */

/* merge_units: begin func_003142A0 */
typedef struct { int pad; int id; int h; int flag; } Arg42A0;
typedef struct { char pad[0xA4]; int sock; } Obj42A0;
#if 0 /* merge_units */
extern int func_00315028(int id, Obj42A0 **out);
#endif /* merge_units */
#define func_00315028(a0, a1) (func_00315028((a0), (Obj4180 * *)(a1))) /* merge_units */

extern int func_002E6088(int h);
extern int func_002F5008(int sock, int h, int mode);
int func_003142A0(Arg42A0 *a)
{
    Obj42A0 *o;
    int ok;
    int r;
    if (D_00491432 <= 0) return 0x11;
    ok = D_00491430;
    if (ok != 1) return 0x11;
    if (a == 0) return 0x17;
    if (func_002E6088(a->h) != ok) return 0x17;
    r = func_00315028(a->id, &o);
    if (r != 0) return r;
    if (a->flag) {
        r = func_00315E28(func_002F5008(o->sock, a->h, 3), 0x2A);
        if (r != 0) return r;
    } else {
        r = func_00315E28(func_002F5008(o->sock, a->h, 0), 0x2A);
        if (r != 0) return r;
    }
    return 0;
}
#undef func_00315028 /* merge_units */
/* merge_units: end func_003142A0 */

/* merge_units: begin func_00314380 */
extern char D_0052AC98[];
extern void *memset(void *d, int c, unsigned int n);
int func_00314380(void)
{
    if (D_00491432 == 0) {
        memset(D_0052AC98, 0, 16);
        D_00491430 = 1;
    }
    D_00491432++;
    return 0;
}
/* merge_units: end func_00314380 */

/* merge_units: begin func_003143E0 */
int func_003143E0(void)
{
    if (D_00491432 <= 0) return 0x11;
    if (D_00491430 != 1) return 0x11;
    if (D_00491432 == 1) D_00491430 = 0;
    D_00491432--;
    return 0;
}
/* merge_units: end func_003143E0 */

/* merge_units: begin func_00314430 */
/* volatile fields keep the retail source-order stores (no store scheduling) */
typedef struct { volatile int f[21]; } Cfg4430;
int func_00314430(Cfg4430 *c)
{
    if (c == 0) return 0x17;
    memset((void *)c, 0, 0x54);
    c->f[1] = 0;
    c->f[0] = 1;
    c->f[9] = 16;
    c->f[10] = 8000;
    c->f[2] = 1;
    c->f[3] = 1;
    c->f[4] = 0;
    c->f[5] = 1;
    c->f[6] = 16;
    c->f[7] = 8000;
    c->f[8] = 1;
    c->f[11] = 0;
    c->f[12] = 0;
    c->f[13] = 0;
    c->f[14] = 0;
    c->f[15] = 0;
    c->f[16] = 0;
    c->f[17] = 0;
    c->f[18] = 0;
    c->f[19] = 0;
    c->f[20] = 0;
    return 0;
}
/* merge_units: end func_00314430 */

/* merge_units: begin func_003144C8 */
typedef struct { char pad[9]; unsigned char state; char pad2[0xA4 - 10]; int sock; } Obj44C8;
#if 0 /* merge_units */
extern int func_00315028(int id, Obj44C8 **out);
#endif /* merge_units */
#define func_00315028(a0, a1) (func_00315028((a0), (Obj4180 * *)(a1))) /* merge_units */

extern int func_002F5068(int sock);
int func_003144C8(int id, unsigned char st)
{
    Obj44C8 *o;
    int ok;
    int r;
    if (D_00491432 <= 0) return 0x11;
    ok = D_00491430;
    if (ok != 1) return 0x11;
    r = func_00315028(id, &o);
    if (r != 0) return r;
    o->state = st;
    r = func_002F5068(o->sock);
    o->state = ok;
    return func_00315E28(r, 0x2A);
}
#undef func_00315028 /* merge_units */
/* merge_units: end func_003144C8 */

/* merge_units: begin func_00314550 */
typedef struct {
    int x00;
    int x04;
    unsigned int count;
    int x0C;
    int x10;
    int x14;
    int x18;
    int x1C;
    int x20;
    int x24;
    int x28;
    int x2C;
    int x30;
    void *x34;
    int x38;
    int x3C;
    int x40;
    int x44;
    int x48;
    int x4C;
    int x50;
} Cfg;

typedef struct {
    int port;
    int x04;
    int x08;
    int x0C;
    int x10;
    int x14;
    int x18;
    int x1C;
    int x20;
    int x24;
    int x28;
    int x2C;
    void *x30;
    void *x34;
    void *x38;
    void *x3C;
} Prm;

typedef struct {
    int id;
    unsigned char a;
    unsigned char b;
    unsigned char c;
} Ent;

typedef struct {
    int slot;
    int count;
    unsigned char state;
    unsigned char ready;
    unsigned char xA;
    int xC;
    Cfg cfg;
    Prm prm;
    int handle;
    unsigned char xA8;
    unsigned char xA9;
    int xAC[8];
    int xCC[12];
    int subs[0x40];
    unsigned char x1FC;
    int x200;
    Ent *ents;
} Obj;

typedef struct {
    int type;
    char x04[0x10];
    int x14;
} Info;
extern unsigned short D_0058C0B0;
extern int D_0048C460;
extern char D_004B34A0[];

int func_00314D50(int, int);
int func_00314F58(int, Obj **);
#if 0 /* merge_units */
int func_00315E28(int, int);
#endif /* merge_units */
#define func_00315E28(a0, a1) (func_00315E28((a0), (a1))) /* merge_units */

int func_002F4EE0(int *, Prm *);
int func_00315730(int, int *);
int func_002F4F48(int, int, int *, char *);
int func_002F5038(int, int);
int func_002E60A0(Info **);
int func_002F4F30(int, char *, int, void *);
int func_002F4F90(int, int *);
int func_002F4FB0(int, int, void *);
int func_00315260(void *, void *);
int func_00315A28();
int func_00315AE8();
int func_00315BB0();
int func_00315C60();
int func_00315CF8();
#if 0 /* merge_units */
void *memset(void *, int, unsigned int);
#endif /* merge_units */
#define memset(a0, a1, a2) (memset((a0), (a1), (a2))) /* merge_units */

int sprintf(char *, const char *, ...);

int func_00314550(int slot, int unused, Cfg *cfg)
{
    char name[0x40];
    Obj *obj;
    int h;
    int sub;
    Info *info;
    int x;
    int ret;
    unsigned int i;
    int f;
    int j;

    info = 0;
    sub = 0;
    ret = 0x11;
    if (D_00491432 <= 0) return ret;
    if (D_00491430 != 1) return ret;
    ret = 0x17;
    if (cfg == 0) return ret;
    if (cfg->count > 0x40) return ret;
    ret = func_00314D50(slot, unused);
    if (ret != 0) return ret;
    ret = func_00314F58(slot, &obj);
    if (ret != 0) return ret;
    ret = 0x29;
    if (obj == 0) return ret;
    if (obj->state != 0) return ret;
    obj->handle = 0;
    obj->slot = slot;
    obj->xA = 0;
    obj->xC = 0x100;
    obj->cfg = *cfg;
    obj->xA8 = 0;
    obj->xA9 = 0;
    obj->x1FC = 0;
    obj->ready = 0;
    memset(&obj->prm, 0, sizeof(Prm));
    obj->prm.x28 = obj->cfg.x0C;
    obj->prm.port = D_0058C0B0;
    obj->prm.x04 = obj->cfg.x14;
    obj->prm.x10 = obj->cfg.x20;
    obj->prm.x08 = obj->cfg.x18;
    obj->prm.x14 = obj->cfg.x24;
    obj->prm.x0C = obj->cfg.x1C;
    obj->prm.x18 = obj->cfg.x28;
    obj->prm.x1C = obj->cfg.x3C;
    obj->prm.x20 = obj->cfg.x40;
    obj->prm.x2C = D_0048C460;
    if (cfg->x34 != 0 || cfg->x2C != 0) {
        obj->prm.x30 = func_00315A28;
        obj->prm.x34 = func_00315AE8;
    } else {
        obj->prm.x30 = 0;
        obj->prm.x34 = 0;
    }
    if (cfg->x44 != 0) {
        obj->prm.x38 = func_00315BB0;
    } else {
        obj->prm.x38 = 0;
    }
    if (cfg->x4C != 0) {
        obj->prm.x3C = func_00315C60;
    } else {
        obj->prm.x3C = 0;
    }
    ret = 0x29;
    if (obj->ents == 0) return ret;
    for (j = 0; j < obj->count; j++) {
        obj->ents[j].id = j;
        obj->ents[j].a = 0;
        obj->ents[j].b = 0;
        obj->ents[j].c = 0;
    }
    ret = func_00315E28(func_002F4EE0(&obj->handle, &obj->prm), 0x2A);
    if (ret != 0) return ret;
    ret = func_00315730(obj->cfg.x10, &h);
    if (ret != 0) return ret;
    i = 0;
    if (obj->cfg.count != 0) {
        do {
            sprintf(name, D_004B34A0, i);
            ret = func_00315E28(func_002F4F48(obj->handle, h, &sub, name), 0x2A);
            if (ret != 0) return ret;
            obj->subs[i] = sub;
            i++;
        } while (i < obj->cfg.count);
    }
    if (i != 0) {
        ret = func_00315E28(func_002F5038(obj->handle, sub), 0x2A);
        if (ret != 0) return ret;
    }
    obj->state = 1;
    ret = func_002E60A0(&info);
    if (ret != 0) return ret;
    if (info == 0) return 0xA;
    if (info->type == 3) {
        obj->xA8 = 0;
        ret = func_00315E28(func_002F4F30(obj->handle, info->x04, info->x14, func_00315CF8), 0x2A);
        if (ret != 0) return ret;
    } else {
        obj->xA9 = 1;
    }
    ret = func_00315E28(func_002F4F90(obj->handle, &x), 0x2A);
    if (ret != 0) return ret;
    ret = func_00315E28(func_002F4FB0(obj->handle, x, &obj->xAC), 0x2A);
    if (ret != 0) return ret;
    ret = func_00315260(&obj->xAC, &obj->xCC);
    if (ret != 0) return ret;
    obj->ready = 1;
    return ret;
}
#undef func_00315E28 /* merge_units */
#undef memset /* merge_units */
/* merge_units: end func_00314550 */

/* merge_units: begin func_00314A98 */
typedef struct { char pad[8]; unsigned char b8; unsigned char b9; unsigned char bA; char pad2; int size; char pad3[0xA4 - 0x10]; int sock; } Obj4A98;
#if 0 /* merge_units */
extern int func_00315028(int id, Obj4A98 **out);
#endif /* merge_units */
#define func_00315028(a0, a1) (func_00315028((a0), (Obj4180 * *)(a1))) /* merge_units */

extern void func_002F4F60(int sock);
extern void func_002F5098(int sock);
extern int func_00314EA8(int id);
int func_00314A98(int id)
{
    Obj4A98 *o;
    int r;
    if (D_00491432 <= 0) return 0x11;
    if (D_00491430 != 1) return 0x11;
    r = func_00315028(id, &o);
    if (r != 0) return r;
    func_002F4F60(o->sock);
    func_002F5098(o->sock);
    o->b8 = 0;
    o->bA = 0;
    o->size = 0x100;
    o->sock = 0;
    o->b9 = 0;
    func_00314EA8(id);
    return 0;
}
#undef func_00315028 /* merge_units */
/* merge_units: end func_00314A98 */

/* merge_units: begin func_00314B40 */
typedef struct { char pad[4]; unsigned char b4; unsigned char b5; unsigned char b6; } Ent4B40;
typedef struct {
    char pad[0xA];
    unsigned char mode;
    char pad1;
    int size;
    char pad2[0xA4 - 0x10];
    int sock;
    char pad3[0xAC - 0xA8];
    char info[0x14];
    int cur;
} Obj4B40;
#if 0 /* merge_units */
extern int func_00315028(int id, Obj4B40 **out);
#endif /* merge_units */
#define func_00315028(a0, a1) (func_00315028((a0), (Obj4180 * *)(a1))) /* merge_units */

extern int func_002F4F78(int sock, int sz);
#if 0 /* merge_units */
extern int func_002F4FB0(int sock, int sz, char *info);
#endif /* merge_units */
#define func_002F4FB0(a0, a1, a2) (func_002F4FB0((a0), (a1), (void *)(a2))) /* merge_units */

#if 0 /* merge_units */
extern int func_002F4F90(int sock, int *out);
#endif /* merge_units */
#define func_002F4F90(a0, a1) (func_002F4F90((a0), (a1))) /* merge_units */

extern int func_003151D8(Obj4B40 *o, int sz, Ent4B40 **out);
int func_00314B40(int id, int sz)
{
    Obj4B40 *o;
    int x;
    Ent4B40 *e;
    int ok, st, r;
    if (D_00491432 <= 0) return 0x11;
    ok = D_00491430;
    if (ok != 1) return 0x11;
    st = func_002E6088(sz);
    if (st != ok) return 0x17;
    r = func_00315028(id, &o);
    if (r != 0) return r;
    r = func_00315E28(func_002F4F78(o->sock, sz), 0x2A);
    if (r != 0) return r;
    r = func_00315E28(func_002F4FB0(o->sock, sz, o->info), 0x2A);
    if (r != 0) return r;
    r = func_00315E28(func_002F4F90(o->sock, &x), 0x2A);
    if (r != 0) return r;
    r = func_00315E28(func_002F4FB0(o->sock, x, o->info), 0x2A);
    if (r != 0) return r;
    if (o->cur != sz) return 0x29;
    o->mode = st;
    o->size = sz;
    r = func_003151D8(o, sz, &e);
    if (r != 0) return r;
    e->b4 = st;
    e->b5 = st;
    e->b6 = st;
    return r;
}
#undef func_00315028 /* merge_units */
#undef func_002F4FB0 /* merge_units */
#undef func_002F4F90 /* merge_units */
/* merge_units: end func_00314B40 */

/* merge_units: begin func_00314CB0 */
typedef struct { char pad[8]; unsigned char state; } Obj4CB0;
extern int func_002E6098(int id);
#if 0 /* merge_units */
extern int func_00314F58(int id, Obj4CB0 **out);
#endif /* merge_units */
#define func_00314F58(a0, a1) (func_00314F58((a0), (Obj * *)(a1))) /* merge_units */

int func_00314CB0(int id)
{
    Obj4CB0 *o;
    int ok, v;
    if (D_00491432 <= 0) return 0;
    ok = D_00491430;
    if (ok != 1) return 0;
    v = func_002E6098(id);
    if (v != ok) return 0;
    if (func_00314F58(id, &o) == 0 && o != 0) {
        if (o->state == v) return 1;
    }
    return 0;
}
#undef func_00314F58 /* merge_units */
/* merge_units: end func_00314CB0 */
