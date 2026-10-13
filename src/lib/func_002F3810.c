typedef struct { int a; int b; int c; unsigned char s[256]; } Rc2F3810;

void func_002F3810(Rc2F3810* st, unsigned char* data, unsigned int len)
{
    unsigned char i = st->b;
    unsigned char j = st->c;
    unsigned char* S = st->s;
    int t; unsigned char d, x;
    unsigned int k;
    for (k = 0; k < len; k++) {
        i += 5;
        j += S[i]; t = S[i];
        S[i] = S[j];
        S[j] = t;
        d = data[k];
        x = S[(unsigned char)(S[i] + t)];
        j += S[d];
        data[k] = d ^ x;
    }
    st->b = i;
    st->c = j;
    st->a += len;
}
