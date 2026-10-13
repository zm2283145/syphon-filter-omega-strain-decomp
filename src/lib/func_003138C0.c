typedef unsigned int u32;
void* memcpy(void*, const void*, u32);

typedef struct Entry {
    int seq;
    u32 size;
    char data[0xF8];
} Entry;

typedef struct Ring {
    int state;
    void* unk4;
    int head;
    u32 count;
    Entry e[64];
} Ring;

int func_003138C0(Ring* r, void** out, char* dst, u32 len)
{
    int i, start;
    int total = 0;
    Entry* e;
    u32 n;

    if (r == 0)
        return 0;
    i = r->head & 0x3F;
    *out = r->unk4;
    start = i;
    if (r->state == 1)
        return 0;
    if (len != 0) {
        e = &r->e[i];
        n = e->size;
        while (len >= n) {
            if (n != 0) {
                memcpy(dst + total, e->data, n);
                total += n;
                e->size = 0;
                len -= n;
                r->count--;
                r->head = e->seq + 1;
            } else if (r->state != 2) {
                return total;
            }
            i = (i + 1) & 0x3F;
            if (i == start || len == 0)
                break;
            e = &r->e[i];
            n = e->size;
        }
    }
    if (r->state == 2 && r->count < 4)
        r->state = 0;
    return total;
}

