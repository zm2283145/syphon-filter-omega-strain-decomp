/*
 * lib/libkernl: 5 files, 00111838-00112110
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00111838 */
typedef struct {int fd,used,a,b;} Entry;
extern int D_0048623C,D_004E4800[],D_004E5440;
extern Entry D_004E5D00[];
extern char D_004E5F00[];
extern Entry *func_00110D38(int);
extern int func_001111B0(int);extern void func_001111E0(void),WaitSema(int),DeleteSema(int);
extern int CreateSema(void *);
extern int sceSifCallRpc(void *,int,int,void *,int,void *,int,void *,void *);
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
 if(sceSifCallRpc(D_004E5F00,1,0,req,20,&D_004E5440,4,0,0)<0){DeleteSema(id);func_001111E0();return -11;}
 entry->used=0;
 status=*(int *)((unsigned)&D_004E5440|0x20000000);
 func_001111E0();
 if(!status){DeleteSema(id);return -11;}
 WaitSema(id);DeleteSema(id);if(out<0)return out;return 0;
}
/* merge_units: end func_00111838 */

/* merge_units: begin func_001119B8 */
extern int D_0048623C,D_004E4800[],D_004E5440,D_0048624C;
extern volatile int D_004861B8[32];extern void func_001111E0(void),WaitSema(int),SignalSema(int),DeleteSema(int);
static inline int isNowait(unsigned short mode){return mode&0x8000;}
int func_001119B8(int fd,int offset,int whence){
 int *g=D_004E4800;
 Entry *iob;
 int inuse,uv,h,rc,i,result;
 int sema[8];
 iob=func_00110D38(fd);
 func_001111B0(4);
 if(D_0048623C==0){func_001111E0();return -1;}
 if(iob==0||(inuse=iob->used)==0){func_001111E0();return -9;}
 g[3]=iob->fd;
 g[4]=offset;
 g[5]=whence;
 g[6]=iob-D_004E5D00;
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
 rc=sceSifCallRpc(D_004E5F00,4,0,D_004E4800,0x1C,&D_004E5440,4,0,0);
 if(rc<0){DeleteSema(h);func_001111E0();return -11;}
 uv=*(int *)((unsigned)&D_004E5440|0x20000000);
 func_001111E0();
 if(uv==0){DeleteSema(h);return -11;}
 if(isNowait(inuse)){DeleteSema(h);return 0;}
 WaitSema(h);DeleteSema(h);return result;
}
/* merge_units: end func_001119B8 */

/* merge_units: begin func_00111BF0 */
extern void func_0010FB10(void *,int);
int func_00111BF0(int fd,void *buf,int nbyte){
 int *g=D_004E4800;
 Entry *iob;
 int inuse,uv,h,rc,i,result;
 int sema[8];
 iob=func_00110D38(fd);
 func_001111B0(2);
 if(D_0048623C==0){func_001111E0();return -1;}
 if(iob==0||(inuse=iob->used)==0){func_001111E0();return -9;}
 g[3]=iob->fd;
 g[7]=iob-D_004E5D00;
 *(void **)(g+4)=buf;
 g[5]=nbyte;
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
 if((inuse&0x20000000)==0)func_0010FB10(buf,nbyte);
 func_0010FB10(g,0x20);
 rc=sceSifCallRpc(D_004E5F00,2,0,D_004E4800,0x20,&D_004E5440,4,0,0);
 if(rc<0){DeleteSema(h);func_001111E0();return -11;}
 uv=*(int *)((unsigned)&D_004E5440|0x20000000);
 func_001111E0();
 if(uv==0){DeleteSema(h);return -11;}
 if(isNowait(inuse)){DeleteSema(h);return 0;}
 WaitSema(h);DeleteSema(h);return result;
}
/* merge_units: end func_00111BF0 */

/* merge_units: begin func_00111E50 */
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
/* merge_units: end func_00111E50 */

/* merge_units: begin func_00112110 */
typedef struct {char b[1024];} SceIoctlArg;
extern int D_0048623C,D_004E4800[],D_004E5440,D_0048624C,D_00486238;
extern char D_004E5490[];
extern void *D_004E47C8;extern void func_001111E0(void),func_001112E0(void),WaitSema(int),SignalSema(int),DeleteSema(int);
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
/* merge_units: end func_00112110 */
