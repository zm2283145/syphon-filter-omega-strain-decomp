typedef struct { int fd, used, a, b; } Entry2DB0;
extern Entry2DB0 D_004E5D00[];
extern int D_0048623C, D_00486248;
extern int func_001111B0(int);
extern void func_001112E0(void),func_001111E0(void);
extern Entry2DB0 *func_00110CB0(void);
extern int func_00112668(int,int);
extern int func_0010D1A0(int),func_0010D180(int);
int func_00112DB0(int path){
 Entry2DB0 *e;
 int r, sem;
 func_001111B0(9);
 if(!D_0048623C)func_001112E0();
 func_001111E0();
 e=func_00110CB0();
 if(!e)return -19;
 r=func_00112668(path,9);
 if(r<0){func_0010D1A0(D_00486248);e->used=0;sem=D_00486248;}
 else{func_0010D1A0(D_00486248);e->fd=r;sem=D_00486248;r=e-D_004E5D00;}
 func_0010D180(sem);
 return r;
}


