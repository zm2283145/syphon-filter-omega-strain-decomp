/*
 * lib/lgaud: 5 files, 00325C80-00325FD8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin lgAudResumePlayback */
extern int D_0049147C;
extern int* D_00491474;
extern char D_0052AD00[];
extern int func_0010D1A0(int sema);
extern int func_0010D180(int sema);
extern int func_00110528(void* cd, int rpc, int mode, void* send, int ssize, void* recv, int rsize, void* end, void* param);
extern int func_00127358(const char* fmt, ...);

int lgAudResumePlayback(int device)
{
    int* buf;
    if (D_0049147C == -1)
        return 0x8000000A;
    func_0010D1A0(D_0049147C);
    buf = D_00491474;
    buf[3] = device;
    if (func_00110528(D_0052AD00, 17, 0, buf, 0x20, buf, 0x20, 0, 0) == 0) {
        device = *D_00491474;
        func_0010D180(D_0049147C);
        return device;
    }
    func_00127358("lgAudResumePlayback: rpc call failed
");
    func_0010D180(D_0049147C);
    return 0x80000000;
}
/* merge_units: end lgAudResumePlayback */

/* merge_units: begin func_00325D48 */
extern char D_004B8318[];
int func_00325D48(int device, unsigned char a, unsigned char b)
{
    int ret;
    if (D_0049147C == -1)
        return 0x8000000A;
    func_0010D1A0(D_0049147C);
    {
    int *buf = D_00491474;
    buf[3] = device;
    ((unsigned char *)buf)[16] = a;
    }
    ((unsigned char *)D_00491474)[17] = b;
    if (func_00110528(D_0052AD00, 0xD, 0, D_00491474, 0x20, D_00491474, 0x20, 0, 0) == 0) {
        ret = *D_00491474;
        func_0010D180(D_0049147C);
        return ret;
    }
    func_00127358(D_004B8318);
    func_0010D180(D_0049147C);
    return 0x80000000;
}
/* merge_units: end func_00325D48 */

/* merge_units: begin func_00325E40 */
int func_00325E40(int device, unsigned char a, unsigned char b)
{
    int ret;
    if (D_0049147C == -1)
        return 0x8000000A;
    func_0010D1A0(D_0049147C);
    {
    int *buf = D_00491474;
    buf[3] = device;
    ((unsigned char *)buf)[16] = a;
    }
    ((unsigned char *)D_00491474)[17] = b;
    if (func_00110528(D_0052AD00, 0xE, 0, D_00491474, 0x20, D_00491474, 0x20, 0, 0) == 0) {
        ret = *D_00491474;
        func_0010D180(D_0049147C);
        return ret;
    }
    func_00127358(D_004B8318);
    func_0010D180(D_0049147C);
    return 0x80000000;
}
/* merge_units: end func_00325E40 */

/* merge_units: begin func_00325F38 */
extern int D_0052AEB8;
extern int func_00110720(void *cd);int func_00325F38(int poll, int *result)
{
    int r;
    if (D_0049147C == -1)
        return 0x8000000A;
    if (poll == 0) {
        while (func_00110720(D_0052AD00))
            ;
        if (result)
            *result = D_0052AEB8;
        return 0;
    }
    r = func_00110720(D_0052AD00);
    if (r == 0 && result)
        *result = D_0052AEB8;
    return r;
}
/* merge_units: end func_00325F38 */

/* merge_units: begin func_00325FD8 */
extern int func_0010D190(int sema);
extern void *memcpy(void *, const void *, unsigned int);
typedef struct { void *dst; int *len; int ret; } lgAudReadReq;
void func_00325FD8(lgAudReadReq *req)
{
    memcpy(req->dst, (char *)D_00491474 + 0x30, D_00491474[8]);
    *req->len = D_00491474[8];
    req->ret = D_00491474[0];
    func_0010D190(D_0049147C);
}
/* merge_units: end func_00325FD8 */
