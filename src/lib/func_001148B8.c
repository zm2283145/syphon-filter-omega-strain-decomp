typedef struct { char pad[0x24]; int serve; char pad2[0x18]; } RpcCd;
typedef struct { char c[4]; } Name4;
extern RpcCd D_004E63C0;
extern int D_004E61C0[];
extern Name4 D_004E63E8;
unsigned int D_00486260[1] = { 0xFFFFFFFF };
extern int sceSifBindRpc(RpcCd*,unsigned int,int);
extern int sceSifCallRpc(void*,int,int,void*,int,void*,int,void*,void*);
int func_001148B8(void) {
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

