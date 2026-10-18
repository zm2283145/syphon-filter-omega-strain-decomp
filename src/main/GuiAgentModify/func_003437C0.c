#pragma opt_propagation off
typedef union { __int128 q; char c[16]; } Key;
typedef struct { char data[0x10]; __int128 key; } E;
typedef struct {
    char pad[0x80];
    E e[(0x22C0 - 0x80) / 0x20];
    short a[0x20];
    short b[0x20];
    char pad2340[0x2C0C - 0x2340];
    unsigned char u;
    signed char s;
} Sub;
typedef struct { char pad[0x60]; Sub sub; } P;
typedef struct { char pad[0x8C]; P *p; } O;
extern char D_0055DDA0[];
extern int func_004027E0(void *t, __int128 key);
extern void func_004022E0(void *t, __int128 key, E *e, short *a, short *b, unsigned char u, signed char s);

void GuiAgentModify_AdvancePatchA(O *o, int idx)
{
    Key k;
    char *lo, *hi, *b;
    int i;
    k.q = o->p->sub.e[idx].key;
    if (func_004027E0(D_0055DDA0, k.q) != -1)
        return;
    
    b = k.c;
    lo = b + 13;
    hi = b + 12;
    i = 0;
    do {
        if (*lo == '-') {
            if (*hi == '9') {
                *hi = '1';
                *lo = '0';
            } else {
                (*hi)++;
            }
        } else if (*lo == '9') {
            (*hi)++;
            *lo = '0';
        } else {
            (*lo)++;
        }
        if (func_004027E0(D_0055DDA0, k.q) != -1) {
            Sub *s = &o->p->sub;
            func_004022E0(D_0055DDA0, k.q, &s->e[idx], &s->a[idx], &s->b[idx], s->u, s->s);
            o->p->sub.e[idx].key = k.q;
            return;
        }
    } while (++i < 0x20);
}







