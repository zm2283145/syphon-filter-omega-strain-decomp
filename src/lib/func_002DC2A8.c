typedef struct Codec {
    char pad0[8];
    int inBlk;
    int outBlk;
    char pad10[0x18];
    int (*fn)(int, char *, char *);
    char pad2C[4];
    int inLen;
    int outLen;
    int stats;
    int ctx;
    char out[0x1E0];
    char in[0x800];
} Codec;

extern void *memcpy(void *, const void *, unsigned int);
extern void func_00125FE8(void *, const void *, int);
extern void func_002D8678(void);
extern int func_002D86A0(void);
extern void func_002D86C8(int, int, int);

int func_002DC2A8(Codec *s, char *in, int inlen, char *out, int outcap)
{
    int total = 0;
    int n;

    if (s->inBlk == 0) {
        while (inlen > 0 || outcap > 0) {
            if (outcap <= 0) {
                n = 0x800 - s->inLen;
                if (inlen < n) n = inlen;
                if (n <= 0) return total;
                memcpy(s->in + s->inLen, in, n);
                s->inLen += n;
                break;
            }
                if (s->inLen > 0) {
                    n = s->inLen;
                    if (outcap < n) n = outcap;
                    memcpy(out, s->in, n);
                    s->inLen -= n;
                    out += n;
                    outcap -= n;
                    total += n;
                    if (s->inLen > 0) func_00125FE8(s->in, s->in + n, s->inLen);
                } else {
                    if (inlen <= 0) return total;
                    n = outcap < inlen ? outcap : inlen;
                    memcpy(out, in, n);
                    out += n;
                    in += n;
                    outcap -= n;
                    inlen -= n;
                    total += n;
                }
        }
        return total;
    }
    if (outcap > 0x1E0) outcap = 0x1E0;
    while (inlen > 0 || outcap >= s->outBlk) {
        if (inlen > 0 && s->inLen < 0x800) {
            n = 0x800 - s->inLen;
            if (inlen < n) n = inlen;
            memcpy(s->in + s->inLen, in, n);
            in += n;
            inlen -= n;
            s->inLen += n;
        } else if (outcap >= s->outBlk && outcap < s->outLen + s->outBlk) {
            n = s->outLen;
            while (outcap < n) n -= s->outBlk;
            memcpy(out, s->out, n);
            s->outLen -= n;
            out += n;
            outcap -= n;
            total += n;
            if (s->outLen > 0) func_00125FE8(s->out, s->out + n, s->outLen);
        } else {
            int done = 0;
            while (s->inLen - done >= s->inBlk && s->outLen + s->outBlk <= 0x1E0) {
                func_002D8678();
                s->fn(s->ctx, s->in + done, s->out + s->outLen);
                func_002D86C8(s->stats, s->inBlk, func_002D86A0());
                s->outLen += s->outBlk;
                done += s->inBlk;
            }
            if (done <= 0) break;
            s->inLen -= done;
            if (s->inLen > 0) func_00125FE8(s->in, s->in + done, s->inLen);
        }
    }
    return total;
}






