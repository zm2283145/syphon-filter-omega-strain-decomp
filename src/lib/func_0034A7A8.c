typedef struct { char pad[0x30]; int bufsize; } NetCd_7A8;
extern char D_004BA670[];
extern int func_0010F388(const char *fmt, ...);
extern int sceSifMCallRpc(void *cd, unsigned int fno, unsigned int mode, void *send, int ssize, void *recv, int rsize, void *end, void *edata);
int func_0034A7A8(NetCd_7A8 *cd, int fno, void *buf, int ssize, int rsize)
{
    int bsize;
    ssize = (ssize + 63) & ~63;
    rsize = (rsize + 63) & ~63;
    bsize = cd->bufsize;
    if (bsize < ssize || bsize < rsize) {
        func_0010F388(D_004BA670, ssize, rsize, bsize);
        return -0x21F;
    }
    return sceSifMCallRpc(cd, fno, 0, buf, ssize, buf, rsize, 0, 0);
}
