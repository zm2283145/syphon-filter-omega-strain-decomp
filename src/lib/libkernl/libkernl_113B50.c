typedef struct {int fd,used,a,b;} Entry;
extern int D_0048623C,D_004E4800[],D_004E5440,D_0048624C;
extern volatile int D_004861B8[32];
extern Entry D_004E5D00[];
extern char D_004E5F00[];
extern Entry *get_iob(int);
extern int _sceFsWaitS(int);extern void _sceFsSigSema(void),WaitSema(int),SignalSema(int),DeleteSema(int);
extern int CreateSema(void *);
extern int sceSifCallRpc(void *,int,int,void *,int,void *,int,void *,void *);
static inline int isNowait(unsigned short mode){return mode&0x8000;}
long long sceLseek64(int fd,long long offset,int whence){
 int *g=D_004E4800;
 Entry *iob;
 int inuse,uv,h,rc,i;
 long long result;
 int sema[8];
 iob=get_iob(fd);
 _sceFsWaitS(0x16);
 if(D_0048623C==0){_sceFsSigSema();return -1;}
 if(iob==0||(inuse=iob->used)==0){_sceFsSigSema();return -9;}
 *(long long *)(g+4)=offset;
 g[3]=iob->fd;
 g[6]=whence;
 g[7]=iob-D_004E5D00;
 sema[1]=1;sema[2]=0;sema[5]=0;
 D_004E4800[0]=h=CreateSema(sema);
 *(int **)(g+1)=&result;
 g[2]=8;
 if(inuse&0x8000){
  WaitSema(D_0048624C);
  for(i=0;i<32;i++){
   if(D_004861B8[i]==-1){D_004861B8[i]=g[0];g[0]=-g[0];break;}
  }
  SignalSema(D_0048624C);
 }
 rc=sceSifCallRpc(D_004E5F00,0x16,0,D_004E4800,0x20,&D_004E5440,4,0,0);
 if(rc<0){DeleteSema(h);_sceFsSigSema();return -11;}
 uv=*(int *)((unsigned)&D_004E5440|0x20000000);
 _sceFsSigSema();
 if(uv==0){DeleteSema(h);return -11;}
 if(isNowait(inuse)){DeleteSema(h);return 0;}
 WaitSema(h);DeleteSema(h);return result;
}