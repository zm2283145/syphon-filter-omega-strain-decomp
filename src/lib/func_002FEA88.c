typedef struct { char b[64]; } K64;
extern unsigned char D_004908EC;
extern int rt_msg_client_calc_connect_msg_size(int, unsigned short *);
extern int rt_msg_client_get_client_version(int, unsigned char *, unsigned char *, unsigned char *);
extern int rt_msg_set_ubyte(unsigned char *, unsigned char);
extern int rt_msg_set_u2byte(unsigned char *, unsigned short);
extern void rt_msg_set_u4byte(unsigned char *, unsigned int);
extern unsigned int KM_GetSoftwareID(void);
extern int rt_msg_client_have_encryption_key(unsigned short, unsigned char *);
extern void KM_GetSoftwareKeyPair(char *a, char *b);
extern int KM_DigiSign(int a, int b, char *c, char *d, char *e);
extern void *memset(void *, int, unsigned int);
extern void *memcpy(void *, const void *, unsigned int);
int rt_msg_client_store_connect_msg_in_buf(unsigned char *out, unsigned short type, int addr, unsigned short key, unsigned short port,
                  void *data, unsigned short len)
{
    char k1[64];
    char k2[64];
    unsigned char flag = 0;
    unsigned short chk = 0;
    unsigned char a, b, c;
    unsigned char *p;
    int r;
    if (D_004908EC != 1) return 5;
    if (!data && len) return 2;
    if (!out) return 2;
    r = rt_msg_client_calc_connect_msg_size(len, &chk);
    if (r) return r;
    if (type != chk) return 2;
    p = out;
    r = rt_msg_client_get_client_version(addr, &a, &b, &c);
    if (r) return r;
    if (rt_msg_set_ubyte(p, a)) return 7;
    p++;
    if (rt_msg_set_ubyte(p, b)) return 7;
    p++;
    if (rt_msg_set_ubyte(p, c)) return 7;
    p++;
    if (rt_msg_set_u2byte(p, port)) return 7;
    p += 2;
    rt_msg_set_u4byte(p, KM_GetSoftwareID());
    p += 4;
    r = rt_msg_client_have_encryption_key(key, &flag);
    if (r) return r;
    if (flag == 1) {
        K64 sig;
        KM_GetSoftwareKeyPair(k1, k2);
        if (KM_DigiSign(key, 0xFFFF, k1, k2, (char *)&sig)) return 27;
        *(K64 *)p = sig;
    } else {
        memset(p, 0, 64);
    }
    p += 64;
    if (data && len)
        memcpy(p, data, len);
    return 0;
}
