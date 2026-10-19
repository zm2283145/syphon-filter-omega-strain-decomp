typedef struct { int x0, x4, x8, xC, x10, x14, x18, x1C, x20, x24, x28, x2C; } P2F9780;
extern void Sha1_Digest(char *buf, int len, unsigned int *out, int n);
/* same-unit callee stub: weak, in a section the link discards; restores retail branch-likely choices */
int __attribute__((weak, section(".dtors_drop"))) func_002F7D28(int a) { return 0; }
/* same-unit callee stub: weak, in a section the link discards; restores retail branch-likely choices */
int __attribute__((weak, section(".dtors_drop"))) func_002F7CE8(int a) { return 0; }
extern void func_002F3728(int st, int key, unsigned int hdr);
extern void func_002F3810(int st, char *buf, int len);
extern void func_002F4CD0(int key, char *in, char *out, int len);
extern void func_004769A4(char *a, char *b);
extern P2F9780 *func_002F7D68(int id);
extern P2F9780 *func_002F7ED8(P2F9780 *p, int sub);
unsigned int func_002F9780(int id, int sub, char *buf, int len)
{
    P2F9780 *p = func_002F7D68(id);
    P2F9780 *q = 0;
    char k1[64];
    char k2[64];
    unsigned int hdr = 0;
    unsigned int r = 0;
    if (len && buf) {
        Sha1_Digest(buf, len, &hdr, 4);
        hdr &= 0x1FFFFFFF;
    } else {
        len = 0;
    }
    if (!p)
        return 0;
    if (sub == 0xFFFE)
        sub = 0xFFFF;
    if (sub != 0xFFFF || p->x14 != sub)
        q = func_002F7ED8(p, sub);
    if (!q && sub != 0xFFFF) {
    } else if (q && !func_002F7D28(q->x18)) {
        r = (hdr & 0x1FFFFFFF) | 0x60000000;
        if (len) {
            func_002F3728(q->x10, q->x18, r);
            func_002F3810(q->x10, buf, len);
        }
    } else if (!func_002F7D28(p->x2C) && (sub == 0xFFFF || p->x14 != 0xFFFF || !q || func_002F7CE8(q->xC))) {
        r = (hdr & 0x1FFFFFFF) | 0x20000000;
        if (len) {
            func_002F3728(p->x24, p->x2C, r);
            func_002F3810(p->x24, buf, len);
        }
    } else if (q && !func_002F7CE8(q->xC) && (p->x14 == 0xFFFF || func_002F7D28(q->x18))) {
        r = (hdr & 0x1FFFFFFF) | 0xE0000000;
        if (len)
            func_002F4CD0(q->xC, buf, buf, len);
    } else if (sub != 0xFFFF && !func_002F7CE8(p->x1C) && p->x14 != 0xFFFF && ((unsigned)p->x10 == 0xFFFFFFFF || (unsigned)p->x10 >> 31 == 0)) {
        func_004769A4(k1, k2);
        if (!func_002F7CE8((int)k1)) {
            r = (hdr & 0x1FFFFFFF) | 0x80000000;
            if (len)
                func_002F4CD0((int)k1, buf, buf, len);
        }
    }
    return r;
}
