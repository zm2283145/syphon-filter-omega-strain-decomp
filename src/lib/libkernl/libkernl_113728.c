/*
 * lib/libkernl: 2 files, 00113728-001138C0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00113728 */
typedef struct { int sem,out,size,pad,arg;signed char name[1024]; } PathReq;
extern int D_0048623C,D_004E5440;
extern char D_004E4800[];
extern char D_004E5F00[];
extern void func_001112E0(void),_sceFsWaitS(int),_sceFsSigSema(void),WaitSema(int),DeleteSema(int);
extern int CreateSema(void *),sceSifCallRpc(void *,int,int,void *,int,void *,int,void *,void *);
int sceSync(unsigned char *name,int arg){
 int sem[8],out,n,id,status;PathReq *req=(PathReq *)D_004E4800;
 _sceFsWaitS(19);
 if(!D_0048623C)func_001112E0();
 for(n=0;n<1024&&(req->name[n]=name[n]);n++){}
 if(n==1024)req->name[1023]=0;
 req->arg=arg;
 sem[1]=1;sem[2]=0;sem[5]=0;
 id=CreateSema(sem);
 req->out=(int)&out;req->sem=id;req->size=4;
 if(sceSifCallRpc(D_004E5F00,19,0,D_004E4800,1044,&D_004E5440,4,0,0)<0){DeleteSema(id);_sceFsSigSema();return -11;}
 status=*(int *)((unsigned)&D_004E5440|0x20000000);
 _sceFsSigSema();
 if(!status){DeleteSema(id);return -11;}
 WaitSema(id);DeleteSema(id);return out;
}
/* merge_units: end func_00113728 */

/* merge_units: begin func_001138C0 */
typedef struct { int sem,out,size;signed char name[1024],name2[1024];unsigned char payload[1024];int mode,len; } PathReq_001138C0;
extern void sceSifWriteBackDCache(void *,int);
int sceMount(unsigned char *name,unsigned char *name2,int mode,unsigned char *payload,int len){
 int sem[8],out,n,id,status;PathReq_001138C0 *req=(PathReq_001138C0 *)D_004E4800;
 _sceFsWaitS(20);
 if(!D_0048623C)func_001112E0();
 for(n=0;n<1024&&(req->name[n]=name[n]);n++){}
 if(n==1024)req->name[1023]=0;
 for(n=0;n<1024&&(req->name2[n]=name2[n]);n++){}
 if(n==1024)req->name2[1023]=0;
 if(len>1024){_sceFsSigSema();return -7;}
 for(n=0;n<len;n++)req->payload[n]=payload[n];
 req->len=len;req->mode=mode;
 sem[1]=1;sem[2]=0;sem[5]=0;
 id=CreateSema(sem);
 req->size=4;req->out=(int)&out;req->sem=id;
 sceSifWriteBackDCache(D_004E4800,3092);
 if(sceSifCallRpc(D_004E5F00,20,0,D_004E4800,3092,&D_004E5440,4,0,0)<0){DeleteSema(id);_sceFsSigSema();return -11;}
 status=*(int *)((unsigned)&D_004E5440|0x20000000);
 _sceFsSigSema();
 if(!status){DeleteSema(id);return -11;}
 WaitSema(id);DeleteSema(id);return out;
}
/* merge_units: end func_001138C0 */
