typedef struct { int size; volatile int count; unsigned char *rd; unsigned char *wr; } Ring;
typedef struct { volatile int fd; volatile int x4; volatile unsigned int x8; volatile int xC; char *x10; unsigned char *x14; Ring *x18; } Ctx;
extern Ctx D_004E2950;
extern char D_004E2980[];
extern int func_001161A0(void);
extern int func_001161F8(void);
extern int func_0010E320(int, char);
extern void func_0010E350(int);
int func_0010E728(char *s, int n)
{
    int cnt = 0;
    int j = 0;
    int intr;
    char *p;
    char *d;
    if (D_004E2950.xC != 0)
        return -1;
    intr = func_001161A0();
    D_004E2950.xC = 1;
    p = (char *)((unsigned int)D_004E2980 | 0x20000000);
    D_004E2950.x10 = p;
    d = p + 12;
    while (--n != -1) {
        if (*s == '\n') {
            *d++ = '\r';
            j++;
            if (j >= 0x100)
                break;
        }
        *d = *s; j++; s++; d++;
        cnt++;
        if (j >= 0x100)
            break;
    }
    D_004E2950.x4 = j + 12;
    *(short *)p = D_004E2950.x4;
    if (func_0010E320(D_004E2950.fd, p[7]) < 0) {
        D_004E2950.xC = 0;
        if (intr)
            func_001161F8();
        return -1;
    }
    while (D_004E2950.xC)
        func_0010E350(D_004E2950.fd);
    if (intr)
        func_001161F8();
    return cnt;
}


