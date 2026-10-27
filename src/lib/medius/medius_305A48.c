extern unsigned char D_004912E8;
extern void *D_004912EC;
extern int D_004912F0, D_004912F4;
extern int *D_004912F8;
extern unsigned int D_00529808, D_0052980C;
extern unsigned int D_00529810;
typedef int (*NetMsgCb)(int, int, int, void *);
typedef void (*NetMsgPost)(int *, int *, int *);
extern int rt_parse_get_callback(unsigned int type, unsigned int sub, NetMsgCb *cb);
extern void *memcpy(void *d, const void *s, unsigned int n);
int rt_parse_execute(int a0, int a1, int a2, unsigned char *data, unsigned int len, NetMsgPost post)
{
    NetMsgCb cb;
    int a, b, c;
    unsigned int off;
    unsigned int type, sub;
    int n;
    if (D_004912E8 != 1) return 3;
    if (D_004912F0 == 0) return 3;
    if (D_004912F4 == 0) return 3;
    if (D_004912EC == 0) return 3;
    if (D_004912F8 == 0) return 3;
    if (data == 0) return 2;
    if (len < 2) return 2;
    if (len > D_00529810) return 2;
    a = a0;
    b = a1;
    c = a2;
    off = 0;
    while (off < len) {
        type = data[off];
        sub = data[off + 1];
        off += 2;
        if (type >= D_0052980C || sub >= D_00529808) return 7;
        if (rt_parse_get_callback(type, sub, &cb) != 0) return 7;
        if (cb == 0) return 7;
        D_004912F8[type * D_00529808 + sub]++;
        memcpy(D_004912EC, data + off, len - off);
        n = cb(a, b, c, D_004912EC);
        if (n < 0) { return 7; }
        off += n;
        if (off > len) return 7;
        if (post != 0) post(&a, &b, &c);
    }
    return 0;
}
