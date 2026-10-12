#define FIELD(p,o) (*(int *)((char *)(p)+(o)))
extern unsigned int func_00107A38(void *,int);
extern int func_00107CA8(void *,int),func_00107DC8(void *,int);
extern int func_0010BD58(void *,const char *,int);
extern char D_00498438[];
int func_001068E0(void *ctx)
{
 int sum=0, again;
 unsigned int code;
 do {
  code=func_00107A38(ctx,0);
  switch(code){
   case 0x23:again=1;sum+=0x21;break;
   case 0x22:again=1;break;
   case 0:
    {int v=func_00107CA8(ctx,11);
     if(FIELD(ctx,0x860) && v==15){func_00107DC8(ctx,11);again=1;}
     else{func_0010BD58(ctx,D_00498438,code);FIELD(ctx,0x134)=1;return 1;}}
    break;
   default:sum+=code;again=0;break;
  }
 }while(again);
 return sum;
}

