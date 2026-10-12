typedef struct { int size; volatile int count; unsigned char *rd; unsigned char *wr; } Ring;
typedef struct { int fd; volatile int x4; volatile unsigned int x8; volatile int xC; char *x10; unsigned char *x14; Ring *x18; } Ctx;
extern Ctx D_004E2950;
extern void ByteRing_Pop(Ring *);
int func_0010E8A0(char *buf, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        while (D_004E2950.x18->count == 0)
            ;
        buf[i] = *D_004E2950.x18->rd;
        ByteRing_Pop(D_004E2950.x18);
        if (buf[i] == '\n' || buf[i] == '\r')
            return i + 1;
    }
    return i;
}
