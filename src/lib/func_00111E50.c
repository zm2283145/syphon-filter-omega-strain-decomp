typedef struct {int fd,used,a,b;} Entry;
extern int D_0048623C,D_004E4800[],D_004E5440,D_0048624C;
extern volatile int D_004861B8[32];
extern Entry D_004E5D00[];
extern char D_004E5F00[];
extern Entry *func_00110D38(int);
extern int func_001111B0(int);extern void func_001111E0(void),WaitSema(int),SignalSema(int),DeleteSema(int);
extern int CreateSema(void *);
extern void func_0010FB10(void *,int);
extern int sceSifCallRpc(void *,int,int,void *,int,void *,int,void *,void *);
static inline int isNowait(unsigned short mode){return mode&0x8000;}
int func_00111E50(int fd,void *buf,int nbyte){
 int *g=D_004E4800;
 Entry *iob;
 int inuse,uv,h,rc,i,j,nb,result;
 char *dst;
 int sema[8];
 iob=func_00110D38(fd);
 func_001111B0(3);
 if(D_0048623C==0){func_001111E0();return -1;}
 if(iob==0||(inuse=iob->used)==0){func_001111E0();return -9;}
 g[3]=iob->fd;
 g[11]=iob-D_004E5D00;
 g[5]=nbyte;
 *(void **)(g+4)=buf;
 sema[1]=1;sema[2]=0;sema[5]=0;
 D_004E4800[0]=h=CreateSema(sema);
 *(int **)(g+1)=&result;
 g[2]=4;
 if(inuse&0x8000){
  WaitSema(D_0048624C);
  for(i=0;i<32;i++){
   if(D_004861B8[i]==-1){D_004861B8[i]=g[0];g[0]=-g[0];break;}
  }
  SignalSema(D_0048624C);
 }
 if(((unsigned)buf&0xF)==0)nb=0;
 else nb=(unsigned)buf/16*16+16-(unsigned)buf;
 if(nb>nbyte)nb=nbyte;
 if((inuse&0x20000000)==0)func_0010FB10(buf,nbyte);
 buf=(char *)((unsigned)buf|0x20000000);
 g[6]=nb;
 for(j=0;j<nb;j++){dst=(char *)(g+7);dst[j]=((char *)buf)[j];}
 rc=sceSifCallRpc(D_004E5F00,3,0,D_004E4800,0x30,&D_004E5440,4,0,0);
 if(rc<0){DeleteSema(h);func_001111E0();return -11;}
 uv=*(int *)((unsigned)&D_004E5440|0x20000000);
 func_001111E0();
 if(uv==0){DeleteSema(h);return -11;}
 if(isNowait(inuse)){DeleteSema(h);return 0;}
 WaitSema(h);DeleteSema(h);return result;
}
