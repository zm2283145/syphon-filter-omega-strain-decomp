/*
 * lib/medius: 3 files, 002F2C68-002F2E90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002F2C68 */
typedef struct { unsigned char b[64]; } B2F2C68;
typedef struct { int st[4]; unsigned int lo, hi; unsigned char buf[64]; } C2F2C68;
extern void *memcpy(void *, const void *, unsigned int);
extern void Md5_Transform(C2F2C68 *);
void Md5_Update(C2F2C68 *c, const unsigned char *in, unsigned int len)
{
    unsigned int idx, part;
    idx = c->lo & 0x3F;
    if ((c->lo += len) < len) c->hi++;
    part = 64 - idx;
    if (len >= part) {
        memcpy(&c->buf[idx], in, part);
        idx = 0;
        Md5_Transform(c);
        in += part;
        len -= part;
        while (len >= 64) {
            *(B2F2C68 *)c->buf = *(const B2F2C68 *)in;
            len -= 64;
            in += 64;
            Md5_Transform(c);
        }
    }
    memcpy(&c->buf[idx], in, len);
}
/* merge_units: end func_002F2C68 */

/* merge_units: begin func_002F2DC8 */
extern void *memset(void *, int, unsigned int);
static const unsigned int dat_0048C740[16] = { 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
#if 0 /* merge_units */
extern void Md5_Update(unsigned int *, unsigned char *, unsigned int);
#endif /* merge_units */
#define Md5_Update(a0, a1, a2) (Md5_Update((C2F2C68 *)(a0), (const unsigned char *)(a1), (a2))) /* merge_units */

extern void func_004AEF70(void *, void *, int);
void Md5_Final(unsigned char *digest, unsigned int *ctx)
{
    unsigned char bits[8];
    unsigned int cnt[2];
    unsigned int idx, pad, t0, t1;
    cnt[0] = ctx[4];
    cnt[1] = ctx[5];
    idx = cnt[0] & 0x3F;
    pad = (idx < 0x38) ? (0x38 - idx) : (0x78 - idx);
    Md5_Update(ctx, ((unsigned char*)dat_0048C740), pad);
    t0 = cnt[0];
    t1 = cnt[1];
    cnt[0] = t0 << 3;
    cnt[1] = (t1 << 3) + (t0 >> 29);
    func_004AEF70(bits, cnt, 8);
    Md5_Update(ctx, bits, 8);
    func_004AEF70(digest, ctx, 0x10);
    memset(ctx, 0, 0x58);
}
#undef Md5_Update /* merge_units */
/* merge_units: end func_002F2DC8 */

/* merge_units: begin func_002F2E90 */
typedef struct N2F2E90 { struct N2F2E90 *prev, *next; int key; int arr[4]; } N2F2E90;
extern void Net_AllocZeroed(N2F2E90 **, int);
N2F2E90 *func_002F2E90(int key)
{
    N2F2E90 *n = 0;
    unsigned int i;
    Net_AllocZeroed(&n, 0x1C);
    if (n) {
    n->key = key;
    n->prev = n;
    n->next = n;
    for (i = 0; i < 4; i++) n->arr[i] = 0xFFFF;
    }
    return n;
}
/* merge_units: end func_002F2E90 */
