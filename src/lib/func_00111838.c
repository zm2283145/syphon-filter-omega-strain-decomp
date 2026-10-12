typedef struct {int fd,used,a,b;} Entry;
extern int D_0048623C,D_004E4800[],D_004E5440;
extern Entry D_004E5D00[];
extern char D_004E5F00[];
extern Entry *func_00110D38(int);
extern int func_001111B0(int);extern void func_001111E0(void),func_0010D1A0(int),func_0010D170(int);
extern int CreateSema(void *);
extern int func_00110528(void *,int,int,void *,int,void *,int,void *,void *);
int func_00111838(int fd){
 int sem[8],out;
 Entry *entry=func_00110D38(fd);
 int *req=D_004E4800;
 int id,status;
 func_001111B0(1);
 if(!D_0048623C){func_001111E0();return -1;}
 if(!entry || !entry->used){func_001111E0();return -9;}
 req[3]=entry->fd;req[4]=entry-D_004E5D00;
 sem[1]=1;sem[2]=0;sem[5]=0;
 id=CreateSema(sem);
 req[0]=id;req[1]=(int)&out;req[2]=4;
 if(func_00110528(D_004E5F00,1,0,req,20,&D_004E5440,4,0,0)<0){func_0010D170(id);func_001111E0();return -11;}
 entry->used=0;
 status=*(int *)((unsigned)&D_004E5440|0x20000000);
 func_001111E0();
 if(!status){func_0010D170(id);return -11;}
 func_0010D1A0(id);func_0010D170(id);if(out<0)return out;return 0;
}

