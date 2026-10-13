/*
 * lib/lgaud: 2 files, 00324958-00324AC8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00324958 */
extern int D_0049147C;
extern int* D_00491474;
extern int D_0049146C;
extern char D_0052AD00[];
extern int func_0010D1A0(int sema);
extern int func_0010D180(int sema);
extern int func_00110528(void* cd, int rpc, int mode, void* send, int ssize, void* recv, int rsize, void* end, void* param);
extern int func_00127358(const char* fmt, ...);
extern void *memcpy(void *, const void *, unsigned int);int lgAudWrite(int dev, int flag, void *src, int *len)
{
    int ret;
    if (D_0049147C == -1)
        return 0x8000000A;
    if (src == 0) {
        func_00127358("lgAudWrite: invalid parameter (src)\n");
        return 0x80000004;
    }
    if (len == 0 || *len > D_0049146C) {
        func_00127358("lgAudWrite: invalid parameter (size too big)\n");
        return 0x80000004;
    }
    func_0010D1A0(D_0049147C);
    {
        int *buf = D_00491474;
        buf[3] = dev;
        buf[8] = *len;
        memcpy((char *)buf + 0x30, src, *len);
    }
    ((unsigned char *)D_00491474)[0x12] = (unsigned char)flag;
    if (func_00110528(D_0052AD00, 9, 0, D_00491474, ((*len + 0x3F) >> 4) << 4, D_00491474, 0x30, 0, 0) == 0) {
        ret = *D_00491474;
        *len = D_00491474[8];
        func_0010D180(D_0049147C);
        return ret;
    }
    *len = 0;
    func_00127358("lgAudWrite: rpc call failed\n");
    func_0010D180(D_0049147C);
    return 0x80000000;
}
/* merge_units: end func_00324958 */

/* merge_units: begin func_00324AC8 */
int lgAudWriteVag(int dev, int flag, void *src, int *len)
{
    int ret;
    if (D_0049147C == -1)
        return 0x8000000A;
    if (src == 0) {
        func_00127358("lgAudWriteVag: invalid parameter (src)\n");
        return 0x80000004;
    }
    if (len == 0 || *len > D_0049146C) {
        func_00127358("lgAudWriteVag: invalid parameter (size too big)\n");
        return 0x80000004;
    }
    func_0010D1A0(D_0049147C);
    {
        int *buf = D_00491474;
        buf[3] = dev;
        buf[8] = *len;
        memcpy((char *)buf + 0x30, src, *len);
    }
    ((unsigned char *)D_00491474)[0x12] = (unsigned char)flag;
    if (func_00110528(D_0052AD00, 0x15, 0, D_00491474, ((*len + 0x3F) >> 4) << 4, D_00491474, 0x30, 0, 0) == 0) {
        ret = *D_00491474;
        *len = D_00491474[8];
        func_0010D180(D_0049147C);
        return ret;
    }
    *len = 0;
    func_00127358("lgAudWriteVag: rpc call failed\n");
    func_0010D180(D_0049147C);
    return 0x80000000;
}
/* merge_units: end func_00324AC8 */
