typedef struct { int fd, used, a, b; } Entry2DB0;
extern Entry2DB0 D_004E5D00[];
extern int D_0048623C, D_00486248;
extern int _sceFsWaitS(int);
extern void func_001112E0(void),_sceFsSigSema(void);
extern Entry2DB0 *new_iob(void);
extern int _sceCallCode(int,int);
extern int WaitSema(int),SignalSema(int);
int sceDopen(int path){
 Entry2DB0 *e;
 int r, sem;
 _sceFsWaitS(9);
 if(!D_0048623C)func_001112E0();
 _sceFsSigSema();
 e=new_iob();
 if(!e)return -19;
 r=_sceCallCode(path,9);
 if(r<0){WaitSema(D_00486248);e->used=0;sem=D_00486248;}
 else{WaitSema(D_00486248);e->fd=r;sem=D_00486248;r=e-D_004E5D00;}
 SignalSema(sem);
 return r;
}


