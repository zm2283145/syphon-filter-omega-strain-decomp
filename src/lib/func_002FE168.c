typedef struct { unsigned char flag; char pad[3]; int x4; void (*cb)(char *, unsigned short); } S2FE168;
extern unsigned char D_004908EC;
extern S2FE168 D_005297E0;
extern int func_002F6268(int, unsigned char *, char *, unsigned short *);
extern int func_003010C8(int);
int func_002FE168(void)
{
    char buf[16];
    unsigned char y;
    unsigned short x;
    int r;
    unsigned char st;
    x = 0;
    y = 0;
    st = D_004908EC;
    if (st != 1) return 5;
    if (D_005297E0.flag != st) return 5;
    do {
        r = func_003010C8(func_002F6268(D_005297E0.x4, &y, buf, &x));
        if (r) return r;
        if (y != 1) break;
        if (D_005297E0.cb) D_005297E0.cb(buf, x);
    } while (y == 1);
    return 0;
}

