typedef struct Codec {
    char pad0[8];
    int inBlk;
    int outBlk;
    char pad10[0x18];
    int (*fn)(int, char *, char *);
    int (*fn2)(int, char *, char *);
    int inLen;
    int outLen;
    int stats;
    int ctx;
    char out[0x1E0];
    char in[0x800];
} Codec;

extern void *memcpy(void *, const void *, unsigned int);
extern void *func_00125FE8(void *, const void *, int);
extern void func_002D8678(void);
extern int func_002D86A0(void);
extern void func_002D86E8(int, int, int);

int func_002DC620(Codec *s, char *in, int inlen, char *out, int outcap)
{
    int total = 0;
    int n;
    int ib = s->inBlk;
    int ob = s->outBlk;

    if (ib == 0) {
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
    if (outcap > 0 && s->inLen > 0) {
        n = s->inLen;
        if (outcap < n) n = outcap;
        memcpy(out, s->in, n);
        out += n;
        outcap -= n;
        s->inLen -= n;
        total += n;
        if (s->inLen > 0) func_00125FE8(s->in, s->in + n, s->inLen);
    }
    while (s->outLen >= ob) {
        if (outcap >= ib) {
            func_002D8678();
            s->fn2(s->ctx, s->out, out);
            out += ib;
            outcap -= ib;
            n = func_002D86A0();
            total += ib;
            func_002D86E8(s->stats, ib, n);
            s->outLen -= ob;
            if (s->outLen > 0) func_00125FE8(s->out, s->out + ob, s->outLen);
        } else {
            if (s->inLen + ib > 0x800) break;
            func_002D8678();
            s->fn2(s->ctx, s->out, s->in + s->inLen);
            func_002D86E8(s->stats, ib, func_002D86A0());
            s->inLen += ib;
            s->outLen -= ob;
            if (s->outLen > 0) func_00125FE8(s->out, s->out + ob, s->outLen);
        }
    }
    while (inlen > 0) {
        if (outcap >= ib) {
            func_002D8678();
            inlen -= ob;
            s->fn2(s->ctx, in, out);
            out += ib;
            outcap -= ib;
            func_002D86E8(s->stats, ib, func_002D86A0());
            in += ob;
            total += ib;
        } else if (s->inLen + ib <= 0x800) {
            func_002D8678();
            inlen -= ob;
            s->fn2(s->ctx, in, s->in + s->inLen);
            in += ob;
            func_002D86E8(s->stats, ib, func_002D86A0());
            s->inLen += ib;
        } else {
            if (s->outLen + ob > 0x1E0) break;
            if (inlen < ob) break;
            inlen -= ob;
            memcpy(s->out + s->outLen, in, ob);
            in += ob;
            s->outLen += ob;
        }
    }
    return total;
}


