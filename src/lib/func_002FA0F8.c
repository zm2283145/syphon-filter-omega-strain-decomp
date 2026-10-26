typedef struct LargeInt { int w[32]; } LargeInt;
typedef struct RSAKey { char b[64]; } RSAKey;

extern void *memset(void *, int, unsigned int);
extern void LargeInt_Add(LargeInt *a, LargeInt *b);

void KM_RSAAdjust(RSAKey *a, RSAKey *b)
{
    LargeInt x, y;
    memset((char *)&x + 64, 0, 64);
    *(RSAKey *)&x = *a;
    memset((char *)&y + 64, 0, 64);
    *(RSAKey *)&y = *b;
    LargeInt_Add(&x, &y);
    *a = *(RSAKey *)&x;
}
