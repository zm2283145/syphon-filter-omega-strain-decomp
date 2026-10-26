typedef struct {
    unsigned int flags;
    unsigned int len;
    unsigned char data[0x1F8];
} Slot6170;
typedef struct {
    unsigned int head;
    int pad4;
    int count;
    Slot6170 slots[64];
} Q6170;
extern void *memcpy(void *d, const void *s, unsigned int n);
unsigned int GetVDataBytes(Q6170 *q);
unsigned int GetVSequenceData(Q6170 *q, unsigned char *out, unsigned int size)
{
    unsigned int need;
    unsigned int seq;
    unsigned int got;
    unsigned int idx;
    unsigned int n;
    Slot6170 *s;

    got = GetVDataBytes(q);
    if (got == 0)
        return got;
    if (size < got)
        return -1;
    seq = q->head & 0x1FFFFFFF;
    need = q->head & 0x3F;
    got = 0;
    if (q->count == 0)
        return 0;
    for (n = 0, idx = need; n < 64; n++, idx = (idx + 1) & 0x3F) {
        s = &q->slots[idx];
        if (s->flags & 0x20000000) {
            memcpy(out + got, s->data, s->len);
            got += s->len;
            s->len = 0;
            seq = s->flags & 0x1FFFFFFF;
            q->count--;
            seq++;
        } else if (got == 0 || s->len == 0 || seq != (s->flags & 0x1FFFFFFF)) {
            got = 0;
        } else {
            memcpy(out + got, s->data, s->len);
            got += s->len;
            s->len = 0;
            q->count--;
            if (s->flags & 0x40000000)
                break;
            seq++;
        }
    }
    got = n == 64 ? 0 : got;
    if (got)
        q->head = seq + 1;
    return got;
}