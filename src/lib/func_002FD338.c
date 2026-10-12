typedef struct { char pad[0x48]; unsigned int f48; unsigned int f4C; char q50[0x18]; char q68[4]; } S;
typedef struct { char pad[0x78]; S *sub[2]; } O;
extern unsigned char D_004908EC;
extern int func_002FE860(unsigned short, O **);
extern int func_002F5818(void *, unsigned int *);
int func_002FD338(unsigned short id, unsigned int *a, unsigned int *b, unsigned int *pa, unsigned int *pb)
{
    unsigned int x = 0; unsigned int y = 0;
    O *o = 0;
    unsigned int s4c = 0;
    unsigned int s48 = 0;
    unsigned int sx = 0;
    unsigned int sy = 0;
    unsigned int i;
    int r;
    S *s;
    if (D_004908EC != 1) return 5;
    r = func_002FE860(id, &o);
    if (r) return r;
    for (i = 0; i < 2; i++) {
        s = o->sub[i];
        if (s) {
            if (func_002F5818(s->q68, &x)) return 0x15;
            sx += x;
            s48 += s->f48;
            if (func_002F5818(s->q50, &y)) return 0x15;
            s4c += s->f4C;
            sy += y;
        }
    }
    if (a) *a = sx;
    if (b) *b = sy;
    if (pa) {
        if (s48 == 0) return 1;
        *pa = sx * 100 / s48;
        if (*pa > 100) *pa = 100;
    }
    if (pb) {
        if (s4c != 0) {
            *pb = sy * 100 / s4c;
            if (*pb > 100) *pb = 100;
        } else return 1;
    }
    return 0;
}



