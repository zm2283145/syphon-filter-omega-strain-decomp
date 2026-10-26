typedef struct { int seq; int len; char data[248]; } E3136D0;
typedef struct { int state; int x4; int base; unsigned int count; E3136D0 e[64]; } S3136D0;
extern void *memcpy(void *, const void *, unsigned int);
void AddSequence(S3136D0 *s, int x4, int seq, void *data, unsigned int len)
{
    int i = seq & 63;
    int d;
    if (len >= 248) return;
    if (!s) return;
    if (!len) return;
    s->x4 = x4;
    d = seq - s->base;
    if (d < 0) {
        if (s->base - seq < 64) return;
        s->base = seq;
    } else {
        if (d < 64) goto store;
        if (d >= 128) return;
        s->base = seq;
    }
    while (seq - s->base >= 64) {
        if (s->e[s->base & 63].len) {
            s->e[s->base & 63].len = 0;
            s->state = 2;
            s->count--;
        }
        s->base++;
    }
store:
    if (s->e[i].len) {
        s->e[i].len = 0;
        s->count--;
    }
    s->e[i].seq = seq;
    if (len) {
        memcpy(s->e[i].data, data, len);
        s->e[i].len = len;
        s->count++;
    }
    if (s->state == 1 && s->count >= 2) s->state = 0;
    if (s->count >= 4) s->state = 2;
}
