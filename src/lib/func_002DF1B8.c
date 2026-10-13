extern int func_002DCD20(int);
extern int func_002E51B8(unsigned int, int **);
extern int func_002DD5B8(unsigned int, unsigned short, int, unsigned short);
extern int func_002DEF70(unsigned int, unsigned short);
extern unsigned short D_0058C0B0;
extern unsigned short D_0058D178;

typedef struct {
    char pad[0x440];
    int cnt;
} S_002DF1B8;

void func_002DF1B8(unsigned short a0, unsigned short a1, int a2, unsigned char a3)
{
    S_002DF1B8 *p = 0;
    unsigned int idx = func_002DCD20(a0);
    if (idx < 4 && a2 != 0 && func_002E51B8(idx, (int **)&p) == 0 && p != 0) {
        if (a3) {
            unsigned short v;
            p->cnt++;
            if (D_0058D178 == 0)
                v = D_0058C0B0;
            else
                v = D_0058D178;
            func_002DD5B8(idx, a1, a2, v);
        } else {
            func_002DEF70(idx, a1);
        }
    }
}
