typedef struct { int a; int b; int c; unsigned char s[256]; } Rc2F3698;

void func_002F3698(Rc2F3698* st, unsigned char* key)
{
    unsigned char* S = st->s;
    unsigned char i, j, n, t;
    i = 0;
    do {
        S[i] = ~i;
        i++;
    } while (i != 0);
    j = 0;
    n = 0;
    do {
        j = j + key[n] + S[i];
        n = (n + 1) & 0x3F;
        t = S[i];
        S[i] = S[j];
        S[j] = t;
        i += 3;
    } while (i != 0);
    st->b = 0; st->c = 0; st->a = 0;
}
