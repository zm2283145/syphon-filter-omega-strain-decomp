extern int D_0048623C,D_004E4800[],D_004E5440;
extern char D_004E5F00[];
extern int *get_iob(int);
extern void _sceFsWaitS(int),_sceFsSigSema(void),WaitSema(int),DeleteSema(int);
extern int CreateSema(void *);
extern int sceSifCallRpc(void *,int,int,void *,int,void *,int,void *,void *);
int sceDread(int fd,int arg){
 int sem[8],out;
 int *entry=get_iob(fd),*req=D_004E4800;
 int id,status;
 _sceFsWaitS(11);
 if(!D_0048623C){_sceFsSigSema();return -1;}
 if(!entry || !entry[1]){_sceFsSigSema();return -9;}
 {int handle=entry[0];req[4]=arg;req[3]=handle;}
 sem[1]=1;sem[2]=0;sem[5]=0;
 id=CreateSema(sem);
 req[0]=id;req[1]=(int)&out;req[2]=4;
 if(sceSifCallRpc(D_004E5F00,11,0,req,32,&D_004E5440,4,0,0)<0){WaitSema(id);_sceFsSigSema();return -11;}
 status=*(int *)((unsigned)&D_004E5440|0x20000000);
 _sceFsSigSema();
 if(!status){DeleteSema(id);return -11;}
 WaitSema(id);DeleteSema(id);return out;
}

