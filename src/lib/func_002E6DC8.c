typedef struct { unsigned char b[4]; } IP4;
typedef struct { int port; IP4 ip; } Addr;
extern int D_0058D17C, D_0058D180, D_005983D8;
extern IP4 D_0058DF80;
extern unsigned short D_0058C0B0;
extern char D_0058808C[];
extern int func_002E56D0(unsigned char *);
extern int func_002EBA60(char *);
extern int func_002DD440(char *, char *);
extern int func_002DD380(IP4 *, char *);
extern int func_002DDFF8(int, char *, int, int, int, Addr *);
int func_002E6DC8(int a, int b, int c, int *id)
{
    char b1[16];
    char b2[16];
    unsigned char flag[16];
    Addr ad;
    int g;
    flag[0] = 0;
    if (id == 0) return -1;
    if (func_002E56D0(flag)) return 4;
    func_002EBA60(b2);
    func_002DD440(b1, b2);
    g = D_0058D17C;
    if (g != 0 || flag[0] != 0) {
        if (*id != D_0058D180) return 4;
        if (g) ad.ip = D_0058DF80;
        else func_002DD380(&ad.ip, D_0058808C);
        if (flag[0] == 1) ad.port = D_0058C0B0;
        else ad.port = D_0058D17C;
        func_002DDFF8(0, b2, 0, D_005983D8, 8, &ad);
    }
    return 4;
}
