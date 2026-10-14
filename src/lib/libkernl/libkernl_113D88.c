/*
 * lib/libkernl: 4 files, 00113D88-00114368
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00113D88 */
typedef struct { int sem,out,size;signed char name[1024];unsigned char payload[1024];int mode,len,outbuf,outlen; } PathReq;
extern int D_0048623C,D_004E5440;
extern char D_004E4800[];
extern char D_004E5F00[];
extern void func_0010FB10(void *,int);
extern void func_001112E0(void),func_001111B0(int),func_001111E0(void),WaitSema(int),DeleteSema(int);
extern int CreateSema(void *),sceSifCallRpc(void *,int,int,void *,int,void *,int,void *,void *);
int func_00113D88(unsigned char *name,int mode,unsigned char *payload,unsigned len,void *outbuf,unsigned outlen){
 int sem[8],out,n,id,status;PathReq *req;
 func_001111B0(23);req=(PathReq *)D_004E4800;
 if(!D_0048623C)func_001112E0();
 for(n=0;n<1024&&(req->name[n]=name[n]);n++){}
 if(n==1024)req->name[1023]=0;

 if(len>1024 || outlen>1024){func_001111E0();return -22;}
 for(n=0;n<len;n++)req->payload[n]=payload[n];
 req->len=len;req->mode=mode;
 sem[1]=1;sem[2]=0;sem[5]=0;
 id=CreateSema(sem);
 req->outlen=outlen;req->out=(int)&out;req->size=4;req->outbuf=(int)outbuf;req->sem=id;
 func_0010FB10(D_004E4800,2076);
 if(sceSifCallRpc(D_004E5F00,23,0,D_004E4800,2076,&D_004E5440,4,0,0)<0){DeleteSema(id);func_001111E0();return -11;}
 status=*(int *)((unsigned)&D_004E5440|0x20000000);
 func_001111E0();
 if(!status){DeleteSema(id);return -11;}
 WaitSema(id);DeleteSema(id);return out;
}
/* merge_units: end func_00113D88 */

/* merge_units: begin func_00113FC0 */
typedef struct { int sem,out,size;signed char name[1024],name2[1024]; } PathReq_00113FC0;
int func_00113FC0(unsigned char *name,unsigned char *name2){
 int sem[8],out,n,id,status;PathReq_00113FC0 *req=(PathReq_00113FC0 *)D_004E4800;
 func_001111B0(17);
 if(!D_0048623C)func_001112E0();
 for(n=0;n<1024&&(req->name[n]=name[n]);n++){}
 if(n==1024)req->name[1023]=0;
 for(n=0;n<1024&&(req->name2[n]=name2[n]);n++){}
 if(n==1024)req->name2[1023]=0;
 sem[2]=0;sem[1]=1;sem[5]=0;
 id=CreateSema(sem);
 req->out=(int)&out;req->sem=id;req->size=4;
 if(sceSifCallRpc(D_004E5F00,24,0,D_004E4800,2060,&D_004E5440,4,0,0)<0){DeleteSema(id);func_001111E0();return -11;}
 status=*(int *)((unsigned)&D_004E5440|0x20000000);
 func_001111E0();
 if(!status){DeleteSema(id);return -11;}
 WaitSema(id);DeleteSema(id);return out;
}
/* merge_units: end func_00113FC0 */

/* merge_units: begin func_001141A0 */
typedef struct { int sem,out,size,pad,arg;signed char name[1024]; } PathReq_001141A0;
int func_001141A0(unsigned char *name,void *arg,unsigned len){
 int sem[8],out,n,id,status;PathReq_001141A0 *req=(PathReq_001141A0 *)D_004E4800;
 func_001111B0(17);
 if(!D_0048623C)func_001112E0();
 for(n=0;n<1024&&(req->name[n]=name[n]);n++){}
 if(n==1024)req->name[1023]=0;
 len=len<1024?len:1023;
 req->arg=(int)arg;req->pad=len;func_0010FB10(arg,len);
 sem[2]=0;sem[1]=1;sem[5]=0;
 id=CreateSema(sem);
 req->out=(int)&out;req->sem=id;req->size=4;
 if(sceSifCallRpc(D_004E5F00,25,0,D_004E4800,2060,&D_004E5440,4,0,0)<0){DeleteSema(id);func_001111E0();return -11;}
 status=*(int *)((unsigned)&D_004E5440|0x20000000);
 func_001111E0();
 if(!status){DeleteSema(id);return -11;}
 WaitSema(id);DeleteSema(id);return out;
}
/* merge_units: end func_001141A0 */

/* merge_units: begin func_00114368 */
typedef struct { char pad[0x24]; int serve; } RpcCd;
extern RpcCd D_004E6000;
unsigned int D_00486258[2] = { 0xFFFFFFFF, 0x0 };
extern int sceSifBindRpc(RpcCd*, unsigned int, int);
int func_00114368(void) {
    int n;
    for (;;) {
        if (sceSifBindRpc(&D_004E6000, 0x80000003, 0) < 0) return -1;
        if (D_004E6000.serve) break;
        n = 0x100000;
        while (n--) {}
    }
    (*(int*)D_00486258) = 0;
    /* Keep the completion store before the return-value setup. */
    __asm__ __volatile__("" ::: "memory");
    return 0;
}
/* merge_units: end func_00114368 */
