typedef struct { int mode; signed char name[252]; } Path4578;
extern int D_00486258, D_004E6040;
extern char D_004E6000[];
extern Path4578 D_004E60C0;
extern int sceSifCallRpc(void *,unsigned int,int,void *,int,void *,int,void *,void *);
int func_00114578(unsigned char *name,int mode)
{
 int n,r;
 if(D_00486258<0)return 0;
 for(n=0;n<252 && (D_004E60C0.name[n]=name[n]);n++){}
 if(n==252){D_004E60C0.name[251]=0;n=251;}
 D_004E60C0.mode=mode;
 D_004E60C0.name[251]=0;
 r=sceSifCallRpc(D_004E6000,3,0,&D_004E60C0,n+5,&D_004E6040,4,0,0);
 if(r<0)return -1;
 return D_004E6040;
}
