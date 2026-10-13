typedef struct { int sem,out,size,pad,arg;signed char name[1024]; } PathReq;
extern int D_0048623C,D_004E5440;
extern char D_004E4800[];
extern char D_004E5F00[];
extern void func_0010FB10(void *,int);
extern void func_001112E0(void),func_001111B0(int),func_001111E0(void),WaitSema(int),DeleteSema(int);
extern int CreateSema(void *),sceSifCallRpc(void *,int,int,void *,int,void *,int,void *,void *);
int func_001141A0(unsigned char *name,void *arg,unsigned len){
 int sem[8],out,n,id,status;PathReq *req=(PathReq *)D_004E4800;
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



