typedef struct { unsigned char flag; char pad[3]; int x4; int x8; } S2FD288;
extern unsigned char D_004908EC;
extern S2FD288 D_005297E0;
extern unsigned int strlen(const char *);
extern int func_002F5FE8(int, unsigned char *, char *, unsigned short);
extern int func_003010C8(int);
int func_002FD288(unsigned char *out, char *name, unsigned short x)
{
    int r;
    if (out == 0) return 2;
    *out = 0;
    if (D_004908EC != 1) return 5;
    if (D_005297E0.flag != 1) return 5;
    if (name == 0) return 2;
    if (strlen(name) >= 0x10) return 2;
    r = func_003010C8(func_002F5FE8(D_005297E0.x4, out, name, x));
    __asm__ __volatile__("");
    return r;
}
