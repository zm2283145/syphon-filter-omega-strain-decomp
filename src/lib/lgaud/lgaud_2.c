/*
 * lib/lgaud: 4 files, 00324D28-003251B0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00324D28 */
extern int D_0049147C;
typedef struct { int ret; int x4; int x8; int dev; short x10; unsigned char flag; char x13; int x14[3]; int size; } Pkt;
extern Pkt* D_00491474;
extern int D_0049146C;
extern char D_0052AD00[];
typedef struct { void *dst; int *len; int ret; } lgAudReadReq;
extern lgAudReadReq D_0052AEB0;
extern void func_00325FD8(lgAudReadReq *req);
extern int func_00110720(void *cd);
extern int func_0010D1A0(int sema);
extern int func_00110528(void* cd, int rpc, int mode, void* send, int ssize, void* recv, int rsize, void* end, void* param);
extern int func_00127358(const char* fmt, ...);

int lgAudARead(int dev, int flag, void *dest, int *len)
{
    if (D_0049147C == -1)
        return 0x8000000A;
    if (dest == 0) {
        func_00127358("lgAudARead: invalid parameter (dest)\n");
        return 0x80000004;
    }
    if (len == 0 || *len > D_0049146C) {
        func_00127358("lgAudARead: invalid parameter (*size too big)\n");
        return 0x80000004;
    }
    if (func_00110720(D_0052AD00)) {
        func_00127358("lgAudARead: error: another async call is in progress...\n");
        return 0x80000008;
    }
    func_0010D1A0(D_0049147C);
    {
        Pkt *buf = D_00491474;
        buf->dev = dev;
        buf->size = *len;
        buf->flag = flag;
    }
    D_0052AEB0.dst = dest;
    D_0052AEB0.len = len;
    if (func_00110528(D_0052AD00, 8, 1, D_00491474, 0x30, D_00491474, ((*len + 0x3F) >> 4) << 4, func_00325FD8, &D_0052AEB0) == 0)
        return 0;
    *len = 0;
    func_00127358("lgAudARead: rpc call failed\n");
    return 0x80000000;
}
/* merge_units: end func_00324D28 */

/* merge_units: begin func_00324EA0 */
typedef union { struct { void *src; int *len; int ret; } s; int i[3]; } lgAudWriteReq;
#if 0 /* merge_units */
extern lgAudWriteReq D_0052AEB0;
#endif /* merge_units */
#define D_0052AEB0 (*(lgAudWriteReq*)&D_0052AEB0) /* merge_units */

extern void func_00326040(lgAudWriteReq *req);
extern void *memcpy(void *, const void *, unsigned int);

int lgAudAWrite(int dev, int flag, void *src, int *len)
{
    if (D_0049147C == -1)
        return 0x8000000A;
    if (src == 0) {
        func_00127358("lgAudAWrite: invalid parameter (src)\n");
        return 0x80000004;
    }
    if (len == 0 || *len > D_0049146C) {
        func_00127358("lgAudAWrite: invalid parameter (*size too big)\n");
        return 0x80000004;
    }
    if (func_00110720(D_0052AD00)) {
        func_00127358("lgAudAWrite: error: another async call is in progress...\n");
        return 0x80000008;
    }
    func_0010D1A0(D_0049147C);
    {
        Pkt *buf = D_00491474;
        buf->dev = dev;
        buf->size = *len;
        buf->flag = flag;
    }
    D_0052AEB0.s.src = src;
    D_0052AEB0.s.len = len;
    memcpy((char *)D_00491474 + 0x30, src, D_00491474->size);
    if (func_00110528(D_0052AD00, 9, 1, D_00491474, ((*len + 0x3F) >> 4) << 4, D_00491474, 0x30, func_00326040, &D_0052AEB0) == 0)
        return 0;
    *len = 0;
    func_00127358("lgAudAWrite: rpc call failed\n");
    return 0x80000000;
}
#undef D_0052AEB0 /* merge_units */
/* merge_units: end func_00324EA0 */

/* merge_units: begin func_00325028 */
#if 0 /* merge_units */
extern lgAudWriteReq D_0052AEB0;
#endif /* merge_units */
#define D_0052AEB0 (*(lgAudWriteReq*)&D_0052AEB0) /* merge_units */


int lgAudAWriteVag(int dev, int flag, void *src, int *len)
{
    if (D_0049147C == -1)
        return 0x8000000A;
    if (src == 0) {
        func_00127358("lgAudAWriteVag: invalid parameter (src)\n");
        return 0x80000004;
    }
    if (len == 0 || *len > D_0049146C) {
        func_00127358("lgAudAWriteVag: invalid parameter (*size too big)\n");
        return 0x80000004;
    }
    if (func_00110720(D_0052AD00)) {
        func_00127358("lgAudAWriteVag: error: another async call is in progress...\n");
        return 0x80000008;
    }
    func_0010D1A0(D_0049147C);
    {
        Pkt *buf = D_00491474;
        buf->dev = dev;
        buf->size = *len;
        buf->flag = flag;
    }
    D_0052AEB0.s.src = src;
    D_0052AEB0.s.len = len;
    memcpy((char *)D_00491474 + 0x30, src, D_00491474->size);
    if (func_00110528(D_0052AD00, 0x15, 1, D_00491474, ((*len + 0x3F) >> 4) << 4, D_00491474, 0x30, func_00326040, &D_0052AEB0) == 0)
        return 0;
    *len = 0;
    func_00127358("lgAudAWriteVag: rpc call failed\n");
    return 0x80000000;
}
#undef D_0052AEB0 /* merge_units */
/* merge_units: end func_00325028 */

/* merge_units: begin func_003251B0 */
extern int D_00491470;
extern void (*D_00491484)(int);
#if 0 /* merge_units */
extern int D_0052AD00[];
#endif /* merge_units */
#define D_0052AD00 ((int*)&D_0052AD00) /* merge_units */

extern char D_0052AD40[];
extern int func_0010D180(int sema);
extern int func_0010D170(int sema);
extern int func_00325F38(int, int *);
int func_003251B0(void)
{
    if (D_0049147C != -1) {
        func_0010D1A0(D_0049147C);
        func_00325F38(0, 0);
        if (D_00491470) {
            if (D_00491484)
                D_00491484(D_00491470);
            D_00491470 = 0;
        }
        func_00110528(D_0052AD00, 0x16, 0, D_0052AD40, 0x20, D_0052AD40, 0, 0, 0);
        D_0052AD00[9] = 0;
        func_0010D180(D_0049147C);
        func_0010D170(D_0049147C);
        D_0049147C = -1;
    }
    return 0;
}
#undef D_0052AD00 /* merge_units */
/* merge_units: end func_003251B0 */
