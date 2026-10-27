typedef struct LargeInt { int w[32]; } LargeInt;
typedef struct RSAKey { char b[64]; } RSAKey;

extern void *memset(void *, int, unsigned int);
extern void lintAddIP(LargeInt *a, LargeInt *b);

void KM_RSAAdjust(RSAKey *a, RSAKey *b)
{
    LargeInt x, y;
    memset((char *)&x + 64, 0, 64);
    *(RSAKey *)&x = *a;
    memset((char *)&y + 64, 0, 64);
    *(RSAKey *)&y = *b;
    lintAddIP(&x, &y);
    *a = *(RSAKey *)&x;
}
