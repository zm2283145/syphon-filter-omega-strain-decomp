typedef struct {int fd,used,a,b;} Entry;
typedef struct {char b[1024];} SceIoctlArg;
extern int D_0048623C,D_004E4800[],D_004E5440,D_0048624C,D_00486238;
extern volatile int D_004861B8[32];
extern char D_004E5490[];
extern void *D_004E47C8;
extern char D_004E5F00[];
extern Entry *func_00110D38(int);
extern int func_001111B0(int);extern void func_001111E0(void),func_001112E0(void),WaitSema(int),SignalSema(int),DeleteSema(int);
extern int CreateSema(void *);
extern void func_0010FB10(void *,int);
extern int sceSifCallRpc(void *,int,int,void *,int,void *,int,void *,void *);
int func_00112110(int fd,int request,void *argp){
 int *g=D_004E4800;
 Entry *iob;
 int uv,h,rc,i,result;
 int sema[8];
 rc=1;
 iob=func_00110D38(fd);
 func_001111B0(5);
 D_004E47C8=argp;
 if(D_0048623C==0)func_001112E0();
 if(iob==0||iob->used==0){func_001111E0();return -9;}
 g[0x105]=0;g[0x106]=0;
 switch(request){
 case 1:
  WaitSema(D_0048624C);
  for(i=0;i<0x20;i++){if(D_004861B8[i]!=-1)break;}
  if(i==0x20)*(int *)D_004E47C8=0;else *(int *)D_004E47C8=1;
  SignalSema(D_0048624C);
  func_001111E0();
  return 0;
 case 2:
  *(int *)argp=*(int *)((unsigned)(D_004E5490+D_00486238*0x440)|0x20000000);
  func_001111E0();
  return 0;
 case 3:
  *(long *)argp=*(long *)((unsigned)(D_004E5490+D_00486238*0x440)|0x20000000);
  func_001111E0();
  return 0;
 }
 g[3]=iob->fd;
 g[4]=request;
 if(argp==0)g[0x107]=0;
 else{g[0x107]=1024;*(SceIoctlArg *)((char *)g+0x14)=*(SceIoctlArg *)argp;}
 sema[1]=1;sema[2]=0;sema[5]=0;
 h=CreateSema(sema);
 g[2]=4;
 *(int **)(g+1)=&result;
 g[0]=h;
 func_0010FB10(D_004E4800,0x420);
 rc=sceSifCallRpc(D_004E5F00,5,0,D_004E4800,0x420,&D_004E5440,4,0,0);
 if(rc<0){DeleteSema(h);func_001111E0();return -11;}
 uv=*(int *)((unsigned)&D_004E5440|0x20000000);
 func_001111E0();
 if(uv==0){DeleteSema(h);return -11;}
 WaitSema(h);DeleteSema(h);return result;
}
