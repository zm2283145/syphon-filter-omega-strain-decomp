typedef struct { int x0, x4, x8, xC, x10, x14, x18, x1C, x20, x24, x28, x2C; } P2F9780;
extern void KM_SHA1(char *buf, int len, unsigned int *out, int n);
/* same-unit callee stub: weak, in a section the link discards; restores retail branch-likely choices */
int __attribute__((weak, section(".dtors_drop"))) IsNullRCKey(int a) { return 0; }
/* same-unit callee stub: weak, in a section the link discards; restores retail branch-likely choices */
int __attribute__((weak, section(".dtors_drop"))) IsNullRSAKey(int a) { return 0; }
extern void RCSaltyInitialize(int st, int key, unsigned int hdr);
extern void RCEncrypt(int st, char *buf, int len);
extern void RSAEncrypt(int key, char *in, char *out, int len);
extern void KM_GetSoftwareKeyPair(char *a, char *b);
extern P2F9780 *GetKeyMaster(int id);
extern P2F9780 *GetKeyChain(P2F9780 *p, int sub);
unsigned int KM_Encrypt(int id, int sub, char *buf, int len)
{
    P2F9780 *p = GetKeyMaster(id);
    P2F9780 *q = 0;
    char k1[64];
    char k2[64];
    unsigned int hdr = 0;
    unsigned int r = 0;
    if (len && buf) {
        KM_SHA1(buf, len, &hdr, 4);
        hdr &= 0x1FFFFFFF;
    } else {
        len = 0;
    }
    if (!p)
        return 0;
    if (sub == 0xFFFE)
        sub = 0xFFFF;
    if (sub != 0xFFFF || p->x14 != sub)
        q = GetKeyChain(p, sub);
    if (!q && sub != 0xFFFF) {
    } else if (q && !IsNullRCKey(q->x18)) {
        r = (hdr & 0x1FFFFFFF) | 0x60000000;
        if (len) {
            RCSaltyInitialize(q->x10, q->x18, r);
            RCEncrypt(q->x10, buf, len);
        }
    } else if (!IsNullRCKey(p->x2C) && (sub == 0xFFFF || p->x14 != 0xFFFF || !q || IsNullRSAKey(q->xC))) {
        r = (hdr & 0x1FFFFFFF) | 0x20000000;
        if (len) {
            RCSaltyInitialize(p->x24, p->x2C, r);
            RCEncrypt(p->x24, buf, len);
        }
    } else if (q && !IsNullRSAKey(q->xC) && (p->x14 == 0xFFFF || IsNullRCKey(q->x18))) {
        r = (hdr & 0x1FFFFFFF) | 0xE0000000;
        if (len)
            RSAEncrypt(q->xC, buf, buf, len);
    } else if (sub != 0xFFFF && !IsNullRSAKey(p->x1C) && p->x14 != 0xFFFF && ((unsigned)p->x10 == 0xFFFFFFFF || (unsigned)p->x10 >> 31 == 0)) {
        KM_GetSoftwareKeyPair(k1, k2);
        if (!IsNullRSAKey((int)k1)) {
            r = (hdr & 0x1FFFFFFF) | 0x80000000;
            if (len)
                RSAEncrypt((int)k1, buf, buf, len);
        }
    }
    return r;
}
