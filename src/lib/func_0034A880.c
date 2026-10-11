typedef struct { char pad[0x30]; int bufsize; } NetCd_880;
extern void *memcpy(void *d, const void *s, unsigned int n);
int func_0034A880(NetCd_880 *cd, void *dst, char *buf, int idx, int len)
{
    int room = cd->bufsize - idx * 4;
    if (dst == 0) return 0;
    if (len < 0 || room < len) return -0x21F;
    memcpy(dst, buf + idx * 4, len);
    return 0;
}