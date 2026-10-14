/* sceFsInit (gcc29). D_004E5F80 is a {int;void*} pair: distinct field types give the two stores different alias sets, which drives the retail prologue schedule. */
typedef struct {char v[4];} SceFsVersion;
typedef struct {int w[9];int serve;} Client;
extern void func_0010FBC0(int);
extern int func_001161A0(void);
extern void func_001161F8(void);
extern void func_0010F748(int,void *,void *);
extern void func_00110DA8(void),func_00111298(void);
extern int sceSifBindRpc(void *,int,int);
extern int sceSifCallRpc(void *,int,int,void *,int,void *,int,void *,void *);
extern void func_00110C50(void);extern int WaitSema(int),SignalSema(int);
extern int D_00486248,D_0048623C,D_00486240;
typedef struct {int a;void *b;} CB;extern CB D_004E5F80;
extern char D_004E5F40[],D_004E5D00[],D_004E5480[],D_004E5440[],D_004E5F28[];
extern Client D_004E5F00;
extern void *D_004E47C0[2];
int func_001112E0(void){
 char *p,*end;
 int i,intr,ver;
 CB *cb=&D_004E5F80;
 func_0010FBC0(0);
 cb->a=0;cb->b=0;
 intr=func_001161A0();
 func_0010F748(0x80000011,func_00110DA8,D_004E5F40);
 func_0010F748(0x80000013,func_00111298,cb);
 if(intr)func_001161F8();
 for(;;){
  if(sceSifBindRpc(&D_004E5F00,0x80000001,0)<0)return -1;
  if(D_004E5F00.serve!=0)break;
  for(i=0x100000;i!=-1;i--){}
 }
 func_00110C50();
 WaitSema(D_00486248);
 p=D_004E5D00;end=p+0x200;
 while(p<end){((int *)p)[1]=0;p+=0x10;}
 SignalSema(D_00486248);
 D_004E47C0[0]=D_004E5480;
 D_004E47C0[1]=D_004E5480+0x440;
 if(sceSifCallRpc(&D_004E5F00,0xFF,0,D_004E47C0,8,D_004E5440,8,0,0)<0)return 0xFFFEFFFF;
 *(SceFsVersion *)D_004E5F28=*(SceFsVersion *)((int)D_004E5440|0x20000000);
 *(SceFsVersion *)&ver=*(SceFsVersion *)((int)(D_004E5440+4)|0x20000000);
 D_00486240=ver==2;
 D_0048623C=1;
 return 0;
}