/*
 * lib/libkernl: 4 files, 00115448-00115770
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00115448 */
typedef struct { char pad[0x24]; int serve; char pad2[0x18]; } RpcCd;
typedef struct { int ret; int size; char name[0xFC]; char data[0xFC]; } RpcBuf;
extern RpcCd D_004E63C0;
extern RpcBuf D_004E61C0;
extern int sceSifCallRpc(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endf, void *endp);
extern int _lf_bind(void);
extern int _lf_version(void);
extern char *strncpy(char *, const char *, unsigned int);
int sceSifGetIopAddr(int id, void *out, unsigned int size)
{
    if (_lf_bind() < 0) return -0x10000;
    if (size >= 3) goto invalid;
        D_004E61C0.ret = id;
        D_004E61C0.size = size;
        if (sceSifCallRpc(&D_004E63C0, 3, 0, &D_004E61C0, 0x20, &D_004E61C0, 0x20, 0, 0) < 0) return -0x10001;
        if (size == 0) { *(unsigned char *)out = *(unsigned char *)&D_004E61C0; goto success; }
        if (size == 1) { *(unsigned short *)out = *(unsigned short *)&D_004E61C0; goto success; }
        if (size == 2) goto word;
invalid:
    return -0x10002;
word:
    *(int *)out = D_004E61C0.ret;
success:
    return 0;
}
/* merge_units: end func_00115448 */

/* merge_units: begin func_00115538 */
int sceSifSetIopAddr(int id, void *in, int size)
{
    if (_lf_bind() < 0) return -0x10000;
    D_004E61C0.ret = id;
    D_004E61C0.size = size;
    if (size == 0) *(unsigned char *)D_004E61C0.name = *(unsigned char *)in;
    else if (size == 1) *(unsigned short *)D_004E61C0.name = *(unsigned short *)in;
    else if (size == 2) *(int *)D_004E61C0.name = *(int *)in;
    else return -0x10002;
    if (sceSifCallRpc(&D_004E63C0, 2, 0, &D_004E61C0, 0x20, &D_004E61C0, 0x10, 0, 0) < 0) return -0x10001;
    return 0;
}
/* merge_units: end func_00115538 */

/* merge_units: begin func_00115618 */
typedef struct { unsigned long psize:8; unsigned long dsize:24; int dest; unsigned int cmd; int opt; int length,mode; char args[80]; } ResetPacket5618;
typedef struct { void *src; unsigned int dest; int size,attr; } Dma5618;
extern ResetPacket5618 D_004E6400;
extern int sceSifExecNotifyHandler(int,int);
extern void sceSifStopDma(void);
extern unsigned int sceSifGetReg(unsigned int);
extern void sceSifWriteBackDCache(void *,int);
extern int sceSifSetReg(unsigned int,unsigned int);
extern int sceSifSetDma(Dma5618 *,int);
int sceSifResetIop(char *args,int mode)
{
 Dma5618 dma;
 int n;
 unsigned int dest;
 sceSifExecNotifyHandler(0,0);sceSifExecNotifyHandler(1,0);
 sceSifStopDma();dest=sceSifGetReg(0x80000000);
 D_004E6400.mode=mode;
 for(n=0;args[n];n++)D_004E6400.args[n]=args[n];
 D_004E6400.dest=0;
 D_004E6400.length=n;
 D_004E6400.cmd=0x80000003;
 D_004E6400.dsize=0;
 D_004E6400.psize=0x68;
 dma.src=&D_004E6400;dma.dest=dest;dma.size=0x68;dma.attr=0x44;
 sceSifWriteBackDCache(&D_004E6400,0x68);
 sceSifSetReg(4,0x40000);
 if(sceSifSetDma(&dma,1)){
  sceSifSetReg(4,0x10000);sceSifSetReg(4,0x20000);
  sceSifSetReg(0x80000002,0);sceSifSetReg(0x80000000,0);
  return 1;
 }
 return 0;
}
/* merge_units: end func_00115618 */

/* merge_units: begin func_00115770 */
#if 0 /* merge_units */
extern unsigned int sceSifGetReg(int);
#endif /* merge_units */
#define sceSifGetReg(a0) (sceSifGetReg((unsigned int)(a0))) /* merge_units */

int sceSifIsAliveIop(void) { if (sceSifGetReg(4) & 0x10000) return 1; return 0; }
#undef sceSifGetReg /* merge_units */
/* merge_units: end func_00115770 */
