typedef struct { unsigned char b[64]; } B2F2C68;
typedef struct { int st[4]; unsigned int lo, hi; unsigned char buf[64]; } C2F2C68;
extern void *memcpy(void *, const void *, unsigned int);
extern void func_004AE1C0(C2F2C68 *);
void func_002F2C68(C2F2C68 *c, const unsigned char *in, unsigned int len)
{
    unsigned int idx, part;
    idx = c->lo & 0x3F;
    if ((c->lo += len) < len) c->hi++;
    part = 64 - idx;
    if (len >= part) {
        memcpy(&c->buf[idx], in, part);
        idx = 0;
        func_004AE1C0(c);
        in += part;
        len -= part;
        while (len >= 64) {
            *(B2F2C68 *)c->buf = *(const B2F2C68 *)in;
            len -= 64;
            in += 64;
            func_004AE1C0(c);
        }
    }
    memcpy(&c->buf[idx], in, len);
}