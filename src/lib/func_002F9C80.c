typedef struct { int x0, x4, x8, xC, x10, x14, x18, x1C, x20, x24, x28, x2C; } P2F9C80;
extern P2F9C80 *func_002F7D68(int id);
extern P2F9C80 *func_002F7ED8(P2F9C80 *p, int sub);
extern void func_002F7FB0(char *buf, int len, unsigned int *out, int n);
/* same-unit callee stub: weak, in a section the link discards; restores retail branch-likely choices */
int __attribute__((weak, section(".dtors_drop"))) func_002F7D28(int a) { return 0; }
extern void func_002F3728(int st, int key, unsigned int hdr);
extern void func_002F38B8(int st, char *buf, int len);
extern void func_002F4D00(int a, int b, char *in, char *out, int len);
extern void func_004769A4(char *a, char *b);
extern void func_002FA0F8(char *buf, int key);
int func_002F9C80(int id, int sub, unsigned int hdr, char *buf, int len)
{
    char k1[64];
    char k2[64];
    char k3[64];
    char k4[64];
    unsigned int chk;
    int r = 0;
    P2F9C80 *p = func_002F7D68(id);
    P2F9C80 *q;
    chk = 0;
    if (!p)
        return -1;
    switch (hdr & 0xE0000000) {
    case 0xE0000000:
        func_002F4D00(p->x1C, p->x20, buf, buf, len);
        break;
    case 0x80000000:
        func_004769A4(k1, k2);
        func_002F4D00((int)k1, (int)k2, buf, buf, len);
        break;
    case 0x60000000:
        q = func_002F7ED8(p, sub);
        if (!q || func_002F7D28(q->x18)) {
            r = -1;
        } else {
            func_002F3728(q->x14, q->x18, hdr);
            func_002F38B8(q->x14, buf, len);
        }
        break;
    case 0x20000000:
        if (func_002F7D28(p->x2C)) {
            r = -1;
        } else {
            func_002F3728(p->x28, p->x2C, hdr);
            func_002F38B8(p->x28, buf, len);
        }
        break;
    case 0:
        break;
    case 0x40000000:
        r = -1;
        break;
    default:
        r = -1;
        break;
    }
    if (len && !r) {
        func_002F7FB0(buf, len, &chk, 4);
        chk = (chk & 0x1FFFFFFF) | (hdr & 0xE0000000);
        if (hdr != chk && ((hdr & 0xE0000000) == 0xE0000000 || (hdr & 0xE0000000) == 0x80000000)) {
            if ((hdr & 0xE0000000) == 0x80000000) {
                func_004769A4(k3, k4);
                func_002FA0F8(buf, (int)k3);
            } else {
                func_002FA0F8(buf, p->x1C);
            }
            func_002F7FB0(buf, len, &chk, 4);
            chk = (chk & 0x1FFFFFFF) | (hdr & 0xE0000000);
        }
        if (hdr != chk)
            r = -2;
    }
    return r;
}
