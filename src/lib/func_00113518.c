typedef struct { int sem,out,size;signed char name[1024],name2[1024]; } PathReq;
extern int D_0048623C,D_004E5440;
extern char D_004E4800[];
extern char D_004E5F00[];
extern void func_0010FB10(void *,int);
extern void func_001112E0(void),func_001111B0(int),func_001111E0(void),func_0010D1A0(int),func_0010D170(int);
extern int CreateSema(void *),func_00110528(void *,int,int,void *,int,void *,int,void *,void *);
int func_00113518(unsigned char *name,unsigned char *name2){
 int sem[8],out,n,id,status;PathReq *req=(PathReq *)D_004E4800;
 func_001111B0(17);
 if(!D_0048623C)func_001112E0();
 for(n=0;n<1024&&(req->name[n]=name[n]);n++){}
 if(n==1024)req->name[1023]=0;
 for(n=0;n<1024&&(req->name2[n]=name2[n]);n++){}
 if(n==1024)req->name2[1023]=0;
 sem[2]=0;sem[1]=1;sem[5]=0;
 id=CreateSema(sem);
 req->size=4;req->out=(int)&out;req->sem=id;
 func_0010FB10(D_004E4800,2060);
 if(func_00110528(D_004E5F00,17,0,D_004E4800,2060,&D_004E5440,4,0,0)<0){func_0010D170(id);func_001111E0();return -11;}
 status=*(int *)((unsigned)&D_004E5440|0x20000000);
 func_001111E0();
 if(!status){func_0010D170(id);return -11;}
 func_0010D1A0(id);func_0010D170(id);return out;
}




