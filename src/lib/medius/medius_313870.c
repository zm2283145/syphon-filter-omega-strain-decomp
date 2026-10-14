/*
 * lib/medius: 3 files, 00313870-00313A20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00313870 */
typedef struct { int n; char pad[0xFC]; } G7Slot;
typedef struct { int a; int b; int head; int c; int d; G7Slot slot[64]; } G7Ring;
int func_00313870(G7Ring* r)
{
    int sum = 0;
    int ret = 0;
    int start, i, n;
    if (r != 0) {
        start = r->head & 0x3F;
        i = start;
        do {
            n = r->slot[i].n;
            if (n == 0) break;
            sum += n;
            i = (i + 1) & 0x3F;
        } while (i != start);
        ret = sum;
    }
    return ret;
}
/* merge_units: end func_00313870 */

/* merge_units: begin func_003138C0 */
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
/* merge_units: end func_003138C0 */

/* merge_units: begin func_00313A20 */
typedef struct { int w[21]; int tail[3]; } Blk3A20;
static Blk3A20 D_004913D0 = { { 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0 }, { 0, 0, 0 } };
extern void func_00313D90(int *p);
void func_00313A20(Blk3A20 *p)
{
    *p = D_004913D0;
    func_00313D90(p->tail);
}
/* merge_units: end func_00313A20 */
