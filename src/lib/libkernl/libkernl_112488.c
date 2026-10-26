/*
 * lib/libkernl: 2 files, 00112488-00112668
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00112488 */
typedef struct {int sem,out,size,fd,cmd;char payload[1024];int outbuf,outlen,inlen;} Request;
extern char D_004E4800[],D_004E5F00[];
extern int D_0048623C,D_004E5440;
extern int *get_iob(int);
extern void _sceFsWaitS(int),_sceFsSigSema(void),func_001112E0(void),WaitSema(int),DeleteSema(int),sceSifWriteBackDCache(void *,int);
extern void *memcpy(void *,const void *,unsigned);
extern int CreateSema(void *),sceSifCallRpc(void *,int,int,void *,int,void *,int,void *,void *);
int sceIoctl2(int fd,int cmd,void *in,unsigned inlen,void *outbuf,unsigned outlen){
 int sem[8],out,id,status;
 Request *req=(Request *)D_004E4800;int *entry=get_iob(fd);
 _sceFsWaitS(26);
 if(!D_0048623C)func_001112E0();
 if(!entry || !entry[1]){_sceFsSigSema();return -9;}
 if(inlen>1024 || outlen>1024){_sceFsSigSema();return -22;}
 if(!in)req->inlen=0;else memcpy(req->payload,in,inlen);
 {int handle=entry[0];req->cmd=cmd;req->fd=handle;}
 req->inlen=inlen;
 sem[1]=1;sem[2]=0;sem[5]=0;
 id=CreateSema(sem);
 req->outlen=outlen;req->out=(int)&out;req->size=4;req->outbuf=(int)outbuf;req->sem=id;
 sceSifWriteBackDCache(D_004E4800,1056);
 if(sceSifCallRpc(D_004E5F00,26,0,D_004E4800,1056,&D_004E5440,4,0,0)<0){DeleteSema(id);_sceFsSigSema();return -11;}
 status=*(int *)((unsigned)&D_004E5440|0x20000000);
 _sceFsSigSema();
 if(!status){DeleteSema(id);return -11;}
 WaitSema(id);DeleteSema(id);return out;
}
/* merge_units: end func_00112488 */

/* merge_units: begin func_00112668 */
typedef struct { int sem,out,size;signed char name[1024]; } PathReq;
extern char D_004E4800[];
extern char D_004E5F00[];
extern void func_001112E0(void),_sceFsWaitS(int),_sceFsSigSema(void),WaitSema(int),DeleteSema(int);
int _sceCallCode(unsigned char *name,int arg){
 int sem[8],out,n,id,status;PathReq *req=(PathReq *)D_004E4800;
 _sceFsWaitS(arg);
 if(!D_0048623C)func_001112E0();
 for(n=0;n<1024&&(req->name[n]=name[n]);n++){}
 if(n==1024){req->name[1023]=0;n=1023;}

 sem[2]=0;sem[1]=1;sem[5]=0;
 id=CreateSema(sem);
 req->out=(int)&out;req->sem=id;req->size=4;
 if(sceSifCallRpc(D_004E5F00,arg,0,D_004E4800,n+13,&D_004E5440,4,0,0)<0){DeleteSema(id);_sceFsSigSema();return -11;}
 status=*(int *)((unsigned)&D_004E5440|0x20000000);
 _sceFsSigSema();
 if(!status){DeleteSema(id);return -11;}
 WaitSema(id);DeleteSema(id);return out;
}
/* merge_units: end func_00112668 */
