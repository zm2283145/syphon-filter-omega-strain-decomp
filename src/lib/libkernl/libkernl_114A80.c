/*
 * lib/libkernl: 5 files, 00114A80-00114FC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00114A80 */
typedef struct { char pad[0x24]; int serve; char pad2[0x18]; } RpcCd;
typedef struct { char d[0xFC]; } Blk252;
typedef struct { int ret; int size; char name[0xFC]; char data[0xFC]; } RpcBuf;
extern RpcCd D_004E63C0;
extern RpcBuf D_004E61C0;
extern int sceSifCallRpc(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endf, void *endp);
extern int func_001148B8(void);
extern int func_001149B8(void);
extern void *memcpy(void *, const void *, unsigned int);

int func_00114A80(int id, int size, void *data, int *out)
{
    if (func_001148B8() < 0) return -0x10000;
    if (func_001149B8() != 0) return -0x10004;
    D_004E61C0.ret = id;
    if (data != 0) {
        if (size > 0xFC) {
            *(Blk252 *)D_004E61C0.data = *(Blk252 *)data;
            D_004E61C0.size = 0xFC;
        } else {
            memcpy(D_004E61C0.data, data, size);
            D_004E61C0.size = size;
        }
    } else {
        D_004E61C0.size = 0;
    }
    if (sceSifCallRpc(&D_004E63C0, 6, 0, &D_004E61C0, 0x200, &D_004E61C0, 8, 0, 0) < 0) return -0x10001;
    { int r = D_004E61C0.ret; *out = D_004E61C0.size; return r; }
}
/* merge_units: end func_00114A80 */

/* merge_units: begin func_00114C88 */
int sceSifStopModule(int id, int size, void *data, int *out)
{
    if (func_001148B8() < 0) return -0x10000;
    if (func_001149B8() != 0) return -0x10004;
    D_004E61C0.ret = id;
    if (data != 0) {
        if (size > 0xFC) {
            *(Blk252 *)D_004E61C0.data = *(Blk252 *)data;
            D_004E61C0.size = 0xFC;
        } else {
            memcpy(D_004E61C0.data, data, size);
            D_004E61C0.size = size;
        }
    } else {
        D_004E61C0.size = 0;
    }
    if (sceSifCallRpc(&D_004E63C0, 7, 0, &D_004E61C0, 0x200, &D_004E61C0, 8, 0, 0) < 0) return -0x10001;
    { int r = D_004E61C0.ret; *out = D_004E61C0.size; return r; }
}
/* merge_units: end func_00114C88 */

/* merge_units: begin func_00114E90 */
typedef struct { char c[4]; } Name4;
#if 0 /* merge_units */
extern int D_004E61C0[];
#endif /* merge_units */
#define D_004E61C0 ((int*)&D_004E61C0) /* merge_units */

extern Name4 D_004E63E8;
extern int D_00486260;
extern int sceSifBindRpc(RpcCd *cd, unsigned int id, int mode);
extern char *strncpy(char *, const char *, unsigned int);
int sceSifUnloadModule(int a0)
{
    if (func_001148B8() < 0) return -0x10000;
    if (func_001149B8() != 0) return -0x10004;
    D_004E61C0[0] = a0;
    if (sceSifCallRpc(&D_004E63C0, 8, 0, D_004E61C0, 4, D_004E61C0, 4, 0, 0) < 0) return -0x10001;
    return D_004E61C0[0];
}
#undef D_004E61C0 /* merge_units */
/* merge_units: end func_00114E90 */

/* merge_units: begin func_00114F20 */
typedef struct { int ret; int pad; char name[0xFC]; } RpcBuf_00114F20;
#if 0 /* merge_units */
extern RpcBuf_00114F20 D_004E61C0;
#endif /* merge_units */
#define D_004E61C0 (*(RpcBuf_00114F20*)&D_004E61C0) /* merge_units */

int sceSifSearchModuleByName(const char *name)
{
    if (func_001148B8() < 0) return -0x10000;
    if (func_001149B8() != 0) return -0x10004;
    strncpy(D_004E61C0.name, name, 0xFC);
    D_004E61C0.name[0xFB] = 0;
    if (sceSifCallRpc(&D_004E63C0, 9, 0, &D_004E61C0, 0x200, &D_004E61C0, 4, 0, 0) < 0) return -0x10001;
    return D_004E61C0.ret;
}
#undef D_004E61C0 /* merge_units */
/* merge_units: end func_00114F20 */

/* merge_units: begin func_00114FC0 */
#if 0 /* merge_units */
extern int D_004E61C0[];
#endif /* merge_units */
#define D_004E61C0 ((int*)&D_004E61C0) /* merge_units */

int func_00114FC0(int a0)
{
    if (func_001148B8() < 0) return -0x10000;
    if (func_001149B8() != 0) return -0x10004;
    D_004E61C0[0] = a0;
    if (sceSifCallRpc(&D_004E63C0, 10, 0, D_004E61C0, 4, D_004E61C0, 4, 0, 0) < 0) return -0x10001;
    return D_004E61C0[0];
}
#undef D_004E61C0 /* merge_units */
/* merge_units: end func_00114FC0 */
