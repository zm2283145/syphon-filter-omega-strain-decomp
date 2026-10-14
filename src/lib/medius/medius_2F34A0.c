/*
 * lib/medius: 6 files, 002F34A0-002F3960
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F34A0 */
typedef struct { unsigned char b[0x80]; } Blk2F34A0;

extern Blk2F34A0 D_0048C780;
extern int D_00490800;
extern unsigned short D_0048C800[];

extern void func_00302088(unsigned int seed);
extern unsigned int func_00301F40(void);
extern void LargeInt_AddInt(Blk2F34A0* b, int sum);

Blk2F34A0 func_002F34A0(void)
{
    Blk2F34A0 t = D_0048C780;
    unsigned int n;
    int sum;

    if (!D_00490800) {
        D_00490800 = 1;
        func_00302088(0x5BEF6DF9);
    }
    n = (func_00301F40() >> 5) & 0x1FFF;
    sum = 0;
    while (n) {
        sum += D_0048C800[n];
        n--;
    }
    LargeInt_AddInt(&t, sum);
    return t;
}
/* merge_units: end func_002F34A0 */

/* merge_units: begin func_002F3698 */
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
/* merge_units: end func_002F3698 */

/* merge_units: begin func_002F3728 */
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
/* merge_units: end func_002F3728 */

/* merge_units: begin func_002F3810 */
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
/* merge_units: end func_002F3810 */

/* merge_units: begin func_002F38B8 */
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
/* merge_units: end func_002F38B8 */

/* merge_units: begin func_002F3960 */
extern void Net_AllocZeroed(void *, int);
int *func_002F3960(int a, int b)
{
    int *p = 0;
    Net_AllocZeroed(&p, 0x30);
    if (p) {
        p[0] = a;
        p[1] = b;
    }
    return p;
}
/* merge_units: end func_002F3960 */
