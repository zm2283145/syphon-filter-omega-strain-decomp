extern unsigned char D_004908EC;
extern int D_00490904;
extern int func_002FE720(void);
extern void func_00301840(void);
extern void func_00301900(unsigned char *src, unsigned char *dst);
extern void func_00301AB8(unsigned char *src, void *dst);
extern void func_003018E0(unsigned char *dst, unsigned char v);
extern int func_00301A80(unsigned char *dst, unsigned int v);
extern void *memcpy(void *, const void *, unsigned int);
extern int Sha1_Digest(unsigned char *a, unsigned int b, unsigned char *c, int d);
extern int Md5_Digest(unsigned char *a, unsigned int b, unsigned char *c);
extern int Sha1_Digest2(unsigned char *a, unsigned int b, unsigned char *c, unsigned int d, unsigned char *e, int f);
extern int Md5_Digest2(unsigned char *a, unsigned int b, unsigned char *c, unsigned int d, unsigned char *e);
extern int func_00305E10(unsigned int *out);
extern int func_00305E98(unsigned int *out);
extern int func_002FA2D8(unsigned int *out);
extern int func_00305F30(unsigned char *a, unsigned char *b, int n, unsigned int *out);
extern int NetConn_BufferMessage(void *conn, int type, int id, unsigned char *buf, unsigned short len, int flags);

int func_00300528(void *unused0, void *conn, void *unused2, unsigned char *pkt, unsigned int pktlen)
{
    unsigned char buf[0x200];
    unsigned char type;
    unsigned int a;
    unsigned char *b;
    unsigned int c;
    unsigned int tmp;
    unsigned char *p;
    unsigned short len;
    int st = D_004908EC;

    if (st != 1) return 5;
    if (func_002FE720() != st) return 2;
    if (pkt == 0) return 2;
    if (pktlen < 13) return 0;
    func_00301900(pkt, &type);
    func_00301AB8(pkt + 1, &a);
    func_00301AB8(pkt + 5, &b);
    func_00301AB8(pkt + 9, &c);
    func_003018E0(buf, type);
    func_00301A80(buf + 1, a);
    func_00301A80(buf + 5, (unsigned int)b);
    p = buf + 9;
    switch (type) {
    case 0:
        {
            unsigned int n = 0x1F3;
            if (c < 0x1F3) n = c;
            c = n;
        }
        func_00301A80(p, c);
        memcpy(p + 4, b, c);
        len = c + 13;
        break;
    case 1:
        func_00301A80(p, 16);
        len = 0x1D;
        Sha1_Digest(b, c, p + 4, 16);
        break;
    case 2:
        func_00301A80(p, 16);
        len = 0x1D;
        Md5_Digest(b, c, p + 4);
        break;
    case 3:
        tmp = 0;
        if (!func_00305E10(&tmp))
            func_00301A80(p, tmp);
        else
            func_00301A80(p, 0);
        len = 13;
        break;
    case 4:
        tmp = 0;
        if (!func_00305E98(&tmp))
            func_00301A80(p, tmp);
        else
            func_00301A80(p, 0);
        len = 13;
        break;
    case 5:
        func_00301A80(p, 16);
        len = 0x1D;
        Sha1_Digest2(pkt + 13, pktlen - 13, b, c, p + 4, 16);
        break;
    case 6:
        func_00301A80(p, 16);
        len = 0x1D;
        Md5_Digest2(pkt + 13, pktlen - 13, b, c, p + 4);
        break;
    case 8:
        func_00301A80(p, 4);
        func_00301A80(p + 4, (unsigned int)&D_00490904);
        len = 0x11;
        break;
    case 9:
        func_00301A80(p, 4);
        func_00301A80(p + 4, (unsigned int)func_00301840);
        len = 0x11;
        break;
    case 10:
        tmp = 0;
        if (!func_002FA2D8(&tmp))
            func_00301A80(p, tmp);
        else
            func_00301A80(p, 0);
        len = 13;
        break;
    case 11:
        p += 4;
        len = 13;
        {
        int r = func_00305F30(b, p, 0x1F3, &tmp);
        __asm__("" : "+r"(len)); /* empty barrier: stops gcse const-prop of len=13 (retail keeps addu/addiu on s0) */
        if (r == 0) {
            func_00301A80(p - 4, tmp);
            { unsigned short t = tmp; len = t + len; }
        } else {
            func_00301A80(p - 4, 0);
        }
        }
        break;
    case 12: {
        unsigned int i, j;
        unsigned char *found;
        func_00301A80(p, 4);
        p += 4;
        len = 13;
        __asm__("" : "+r"(len)); /* empty barrier: stops gcse const-prop of len=13 (retail keeps addu/addiu on s0) */
        i = 0;
        j = 13;
        found = 0;
        if (c != 0 && len < pktlen) {
            do {
                if (b[i] != pkt[j]) {
                    j = 13;
                    found = 0;
                } else if (!found)
                    found = &b[i];
                i++;
                j++;
            } while (i < c && j < pktlen);
        }
        func_00301A80(p, (unsigned int)found);
        len += 4;
        break;
    }
    default:
        func_00301A80(p, 0);
        len = 13;
        break;
    }
    NetConn_BufferMessage(conn, 0x1D, 0xFFFF, buf, len, 0);
    return 0;
}
