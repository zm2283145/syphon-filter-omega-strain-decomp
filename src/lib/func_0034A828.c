typedef struct { char pad[0x30]; int bufsize; } NetCd_828;
extern void *memcpy(void *d, const void *s, unsigned int n);
int func_0034A828(NetCd_828 *cd, char *buf, int idx, void *src, int len)
{
    int room = cd->bufsize - idx * 4;
    if (src == 0) return 0;
    if (len < 0 || room < len) return -0x21F;
    memcpy(buf + idx * 4, src, len);
    return 0;
}