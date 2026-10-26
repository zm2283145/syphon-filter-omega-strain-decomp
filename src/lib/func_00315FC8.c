typedef struct { unsigned int hdr; int len; char data[504]; } E315FC8;
typedef struct { unsigned int cur; int x4; int count; E315FC8 e[64]; } S315FC8;
int GetVDataBytes(S315FC8 *s)
{
    unsigned int first = 0;
    int total = 0;
    unsigned int cur, seq, h;
    int i, j;
    unsigned int n;
    E315FC8 *e;
    if (!s)
        return 0;
    cur = s->cur;
    seq = cur & 0x1FFFFFFF;
    i = cur & 63;
    if (!s->count)
        return 0;
    if (!s->e[i].len || !(s->e[i].hdr & 0x20000000)) {
        j = i;
        do
            j = (j + 1) & 63;
        while (j != i && (!s->e[j].len || !(s->e[j].hdr & 0x20000000)));
        h = s->e[j].hdr;
        if (cur < (h & 0x1FFFFFFF)) {
            s->cur = h & 0x1FFFFFFF;
            seq = h & 0x1FFFFFFF;
            i = h & 63;
        } else
            return 0;
    }
    j = i;
    for (n = 0; n < 64; n++) {
        e = &s->e[j];
        h = e->hdr;
        if (h & 0x20000000) {
            first = h;
            total = e->len;
            seq = first & 0x1FFFFFFF;
            seq++; /* seq++ in both arms (cross-jumped later): the extra refs give seq a2 / i a3 like retail */
        } else {
            if (!total || !e->len || seq != (h & 0x1FFFFFFF)) {
                total = 0;
                goto next;
            }
            total += e->len;
            if (h & 0x40000000)
                break;
            seq++;
        }
next:
        j = (j + 1) & 63;
    }
    if (n == 64)
        total = 0;
    if (total)
        s->cur = first;
    return total;
}
