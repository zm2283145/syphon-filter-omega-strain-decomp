typedef struct { int a; int b; int c; unsigned char s[256]; } Rc2F38B8;

void func_002F38B8(Rc2F38B8* st, unsigned char* data, unsigned int len)
{
    unsigned char i = st->b;
    unsigned char j = st->c;
    unsigned char* S = st->s;
    int t;
    unsigned int k;
    for (k = 0; k < len; k++) {
        i += 5;
        j += S[i];
        t = S[i];
        S[i] = S[j];
        S[j] = t;
        data[k] ^= S[(unsigned char)(S[i] + t)];
        j += S[data[k]];
    }
    st->b = i;
    st->c = j;
    st->a += len;
}
