/*
 * lib/libkernl: 7 files, 00114668-001149B8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00114668 */
extern int D_00486258;
extern char D_004E6000[];
extern int D_004E6040[];
extern int D_004E6080[];
extern int sceSifCallRpc(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *endf, void *endp);
unsigned int sceSifQueryMemSize(void)
{
    if (D_00486258 < 0) return 0;
    if (sceSifCallRpc(D_004E6000, 5, 0, 0, 0, D_004E6040, 4, 0, 0) < 0) return 0xFFFFFFFF;
    return D_004E6040[0];
}
/* merge_units: end func_00114668 */

/* merge_units: begin func_001146D8 */
unsigned int sceSifQueryMaxFreeMemSize(void)
{
    if (D_00486258 < 0) return 0;
    if (sceSifCallRpc(D_004E6000, 6, 0, 0, 0, D_004E6040, 4, 0, 0) < 0) return 0xFFFFFFFF;
    return D_004E6040[0];
}
/* merge_units: end func_001146D8 */

/* merge_units: begin func_00114748 */
unsigned int sceSifQueryTotalFreeMemSize(void)
{
    if (D_00486258 < 0) return 0;
    if (sceSifCallRpc(D_004E6000, 7, 0, 0, 0, D_004E6040, 4, 0, 0) < 0) return 0xFFFFFFFF;
    return D_004E6040[0];
}
/* merge_units: end func_00114748 */

/* merge_units: begin func_001147B8 */
unsigned int sceSifQueryBlockTopAddress(int a0)
{
    if (D_00486258 < 0) return 0;
    D_004E6080[0] = a0;
    if (sceSifCallRpc(D_004E6000, 8, 0, D_004E6080, 4, D_004E6040, 4, 0, 0) < 0) return 0xFFFFFFFF;
    return D_004E6040[0];
}
/* merge_units: end func_001147B8 */

/* merge_units: begin func_00114838 */
unsigned int sceSifQueryBlockSize(int a0)
{
    if (D_00486258 < 0) return 0;
    D_004E6080[0] = a0;
    if (sceSifCallRpc(D_004E6000, 9, 0, D_004E6080, 4, D_004E6040, 4, 0, 0) < 0) return 0xFFFFFFFF;
    return D_004E6040[0];
}
/* merge_units: end func_00114838 */

/* merge_units: begin func_001148B8 */
typedef struct { char pad[0x24]; int serve; char pad2[0x18]; } RpcCd;
typedef struct { char c[4]; } Name4;
extern RpcCd D_004E63C0;
extern int D_004E61C0[];
extern Name4 D_004E63E8;
unsigned int D_00486260[1] = { 0xFFFFFFFF };
extern int sceSifBindRpc(RpcCd*,unsigned int,int);
#if 0 /* merge_units */
extern int sceSifCallRpc(void*,int,int,void*,int,void*,int,void*,void*);
#endif /* merge_units */
#define sceSifCallRpc(a0, a1, a2, a3, a4, a5, a6, a7, a8) (sceSifCallRpc((a0), (a1), (a2), (a3), (a4), (a5), (a6), (a7), (a8))) /* merge_units */

int _lf_bind(void) {
 int n;
 if((*(int*)D_00486260)<0) {
retry:
 if(sceSifBindRpc(&D_004E63C0,0x80000006,0)<0)return -1;
 if(D_004E63C0.serve) {
  (*(int*)D_00486260)=0;
  if(sceSifCallRpc(&D_004E63C0,0xFF,0,0,0,D_004E61C0,4,0,0)<0)return -0x10001;
  D_004E63E8=*(Name4*)D_004E61C0;
  return 0;
 }
 n=0x100000;
 while(n--){}
 goto retry;
 }
 return 0;
}
#undef sceSifCallRpc /* merge_units */
/* merge_units: end func_001148B8 */

/* merge_units: begin func_001149B8 */
extern int Name_Compare48(const char *, const char *, int);
#if 0 /* merge_units */
extern char D_004E63E8[];
#endif /* merge_units */
#define D_004E63E8 ((char*)&D_004E63E8) /* merge_units */

extern char D_0048618C[];
extern char D_00498B70[];
static char *D_00486264 = D_00498B70;
int _lf_version(void)
{
    char *b = D_0048618C;
    char *a = D_004E63E8;
    int r = 0;
    if (Name_Compare48(a, b, 4) && Name_Compare48(a, D_00486264, 4))
        r = Name_Compare48(b, D_00486264, 4) != 0;
    return r;
}
#undef D_004E63E8 /* merge_units */
/* merge_units: end func_001149B8 */
