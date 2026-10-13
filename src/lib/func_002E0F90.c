typedef struct { int f0; int f4; } G;
typedef struct { int f0; void (*f4)(G *); int f8; } O;
typedef struct { int f0; int f4; } Res;
typedef struct { int f0; char name[0x10]; unsigned short port; } C;
typedef struct { char name[0x10]; unsigned short port; } A;
extern int D_0048C458;
extern unsigned char D_0048C4AC;
extern int D_0048C4B0;
extern G D_00520300;
extern C D_005202E8;
extern void (*D_00520338)(G *);
extern int func_002DF708(void);
void __attribute__((weak, section(".dtors_drop"))) func_002E0F00(int *p0) { }
extern char *strncpy(char *, const char *, unsigned int);
extern int func_00302968(int, A *, void *);
extern void func_002E6298(void);

int func_002E0F90(O *o, Res *res)
{
    A a;
    int r;

    if (res == 0) return 0x17;
    res->f4 = 0x1E;
    res->f0 = 1;
    if (o == 0) goto bad;
    if (D_0048C458 != 1) {
        res->f4 = 0x11;
        return 0x11;
    }
    if (o->f0 != D_0048C458) {
        res->f4 = 0x26;
        return 0x26;
    }
    if (o->f4 == 0) goto bad;
    if (D_0048C4AC == o->f0 && D_00520300.f0 == D_0048C4AC && D_00520300.f4 == 0) {
        o->f4(&D_00520300);
        goto ok;
    }
    if (D_0048C4AC == 0) {
        r = func_002DF708();
        res->f4 = r;
        if (r != 0) return r;
    }
    if (o->f8 == 3) func_002E0F00(&o->f8);
    if (D_005202E8.f0 != 3) {
bad:
        res->f4 = 0x17;
        return 0x17;
    }
    D_00520338 = o->f4;
    strncpy(a.name, D_005202E8.name, 0x10);
    a.port = D_005202E8.port;
    if (func_00302968(D_0048C4B0, &a, func_002E6298) != 0) {
        res->f4 = 0x25;
        return 0x25;
    }
ok:
    res->f4 = 0;
    return 0;
}