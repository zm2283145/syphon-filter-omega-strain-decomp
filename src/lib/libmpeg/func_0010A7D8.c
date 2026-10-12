extern unsigned func_0010A008(void *,int),func_00109F50(void *,int);
extern void func_0010A058(void *),func_0010A928(void *,unsigned *);
int func_0010A7D8(void *ctx,unsigned *out){
 unsigned hi,mid,lo,n,i=0;
 func_0010A008(ctx,34);
 hi=func_0010A008(ctx,3);
 func_0010A058(ctx);
 mid=func_0010A008(ctx,15);
 func_0010A058(ctx);
 lo=func_0010A008(ctx,15);
 func_0010A058(ctx);
 out[0]=func_0010A008(ctx,9);
 func_0010A008(ctx,30);
 n=func_0010A008(ctx,3);
 out[2]=(hi>>2)&1;
 out[1]=(hi<<30)|(mid<<15)|lo;
 for(;i<n;i++)func_0010A008(ctx,8);
 if(func_00109F50(ctx,32)==0x1bb){out[3]=1;func_0010A928(ctx,out);}else out[3]=0;
 return 1;
}
