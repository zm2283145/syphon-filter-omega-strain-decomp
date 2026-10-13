typedef struct { int a; int b; int c; unsigned char s[256]; } Rc2F3728;

void func_002F3728(Rc2F3728* st, unsigned char* key, int k4)
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
        j = j + ((unsigned char*)&k4)[n] + S[i];
        n = (n + 1) & 3;
        t = S[i];
        S[i] = S[j];
        S[j] = t;
        i += 5;
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

