typedef struct {int sem,out,size,fd,cmd;char payload[1024];int outbuf,outlen,inlen;} Request;
extern char D_004E4800[],D_004E5F00[];
extern int D_0048623C,D_004E5440;
extern int *func_00110D38(int);
extern void func_001111B0(int),func_001111E0(void),func_001112E0(void),func_0010D1A0(int),func_0010D170(int),func_0010FB10(void *,int);
extern void *memcpy(void *,const void *,unsigned);
extern int CreateSema(void *),func_00110528(void *,int,int,void *,int,void *,int,void *,void *);
int func_00112488(int fd,int cmd,void *in,unsigned inlen,void *outbuf,unsigned outlen){
 int sem[8],out,id,status;
 Request *req=(Request *)D_004E4800;int *entry=func_00110D38(fd);
 func_001111B0(26);
 if(!D_0048623C)func_001112E0();
 if(!entry || !entry[1]){func_001111E0();return -9;}
 if(inlen>1024 || outlen>1024){func_001111E0();return -22;}
 if(!in)req->inlen=0;else memcpy(req->payload,in,inlen);
 {int handle=entry[0];req->cmd=cmd;req->fd=handle;}
 req->inlen=inlen;
 sem[1]=1;sem[2]=0;sem[5]=0;
 id=CreateSema(sem);
 req->outlen=outlen;req->out=(int)&out;req->size=4;req->outbuf=(int)outbuf;req->sem=id;
 func_0010FB10(D_004E4800,1056);
 if(func_00110528(D_004E5F00,26,0,D_004E4800,1056,&D_004E5440,4,0,0)<0){func_0010D170(id);func_001111E0();return -11;}
 status=*(int *)((unsigned)&D_004E5440|0x20000000);
 func_001111E0();
 if(!status){func_0010D170(id);return -11;}
 func_0010D1A0(id);func_0010D170(id);return out;
}
