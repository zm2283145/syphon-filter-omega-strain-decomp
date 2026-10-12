extern int String_CompareN(const char *, const char *, unsigned int);

typedef struct {
    char *p[26];
} Names;

extern Names D_004B0C88;

typedef struct {
    int f0;
    int type;
    char pad8[0x208];
    unsigned int *flags;
} Obj;

void func_0030FF20(Obj *o, const char *s, unsigned int n)
{
    unsigned int *p = 0;
    int i = 0;
    Names names = D_004B0C88;

    if (o->type == 8) {
        p = o->flags;
    } else if (o->type == 7) {
        p = o->flags;
    }
    while (names.p[i] != 0 && String_CompareN(names.p[i], s, n) != 0) {
        i++;
    }
    switch (i) {
    case 0:
        *p |= 0x1;
        break;
    case 1:
        *p |= 0x2;
        break;
    case 2:
        *p |= 0x4;
        break;
    case 3:
        *p |= 0x8;
        break;
    case 4:
        *p |= 0x10;
        break;
    case 5:
        *p |= 0x20;
        break;
    case 6:
        *p |= 0x40;
        break;
    case 7:
        *p |= 0x80;
        break;
    case 8:
        *p |= 0x100;
        break;
    case 9:
        *p |= 0x200;
        break;
    case 10:
        *p |= 0x400;
        break;
    case 11:
        *p |= 0x800;
        break;
    case 12:
        *p |= 0x1000;
        break;
    case 13:
        *p |= 0x2000;
        break;
    case 14:
        *p |= 0x4000;
        break;
    case 15:
        *p |= 0x8000;
        break;
    case 16:
        *p |= 0x10000;
        break;
    case 17:
        *p |= 0x20000;
        break;
    case 18:
        *p |= 0x40000;
        break;
    case 19:
        *p |= 0x80000;
        break;
    case 20:
        *p |= 0x100000;
        break;
    case 21:
        *p |= 0x200000;
        break;
    case 22:
        *p |= 0x400000;
        break;
    case 23:
        *p |= 0x800000;
        break;
    case 24:
        *p |= 0x1000000;
        break;
    }
}