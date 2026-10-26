typedef struct { int x0, x4, x8, xC, x10, x14, x18, x1C, x20, x24, x28, x2C; } P2F9EE0;
extern P2F9EE0 *GetKeyMaster(int id);
extern P2F9EE0 *GetKeyChain(P2F9EE0 *p, int sub);
extern void Sha1_Digest(char *buf, int len, unsigned int *out, int n);
/* same-unit callee stub: weak, in a section the link discards; restores retail branch-likely choices */
int __attribute__((weak, section(".dtors_drop"))) IsNullRCKey(int a) { return 0; }
extern void RCSaltyInitialize(int st, int key, unsigned int hdr);
extern void RCDecrypt(int st, char *buf, int len);
extern void RSADecrypt(int a, int b, char *in, char *out, int len);
extern void KM_GetSoftwareKeyPair(char *a, char *b);
extern void KM_RSAAdjust(char *buf, int key);
int KM_Decrypt2(P2F9EE0 *p, P2F9EE0 *q, unsigned int hdr, char *buf, int len)
{
    char k1[64];
    char k2[64];
    char k3[64];
    char k4[64];
    unsigned int chk;
    int r = 0;
    chk = 0;
    if (!p)
        return -1;
    switch (hdr & 0xE0000000) {
    case 0xE0000000:
        RSADecrypt(p->x1C, p->x20, buf, buf, len);
        break;
    case 0x80000000:
        KM_GetSoftwareKeyPair(k1, k2);
        RSADecrypt((int)k1, (int)k2, buf, buf, len);
        break;
    case 0x60000000:
        if (!q || IsNullRCKey(q->x18)) {
            r = -1;
        } else {
            RCSaltyInitialize(q->x14, q->x18, hdr);
            RCDecrypt(q->x14, buf, len);
        }
        break;
    case 0x20000000:
        if (IsNullRCKey(p->x2C)) {
            r = -1;
        } else {
            RCSaltyInitialize(p->x28, p->x2C, hdr);
            RCDecrypt(p->x28, buf, len);
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
        Sha1_Digest(buf, len, &chk, 4);
        chk = (chk & 0x1FFFFFFF) | (hdr & 0xE0000000);
        if (hdr != chk && (hdr & 0xE0000000) == 0xE0000000) {
            /* dead arm (outer test already excludes it), kept from the sibling 2F9C80: it changes register priorities */
            if ((hdr & 0xE0000000) == 0x80000000) {
                KM_GetSoftwareKeyPair(k3, k4);
                KM_RSAAdjust(buf, (int)k3);
            } else {
                KM_RSAAdjust(buf, p->x1C);
            }
            Sha1_Digest(buf, len, &chk, 4);
            chk = (chk & 0x1FFFFFFF) | (hdr & 0xE0000000);
        }
        if (hdr != chk)
            r = -2;
    }
    return r;
}
