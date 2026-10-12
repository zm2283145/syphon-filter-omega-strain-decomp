extern int func_00107A38(void *,int),func_00107ED8(void *,int),func_00106738(void *);
extern void func_001073A0(int *,int,int,int,int);
void func_001075C8(void *ctx,int *vec,int *out,int xbits,int ybits,int ext,int scale,int mode){
 int code=func_00107A38(ctx,2);
 int rest;
 if(xbits && code) rest=func_00107ED8(ctx,xbits);else rest=0;
 func_001073A0(vec,xbits,code,rest,mode);
 if(ext) out[0]=func_00106738(ctx);
 code=func_00107A38(ctx,2);
 if(ybits && code) rest=func_00107ED8(ctx,ybits);else rest=0;
 if(scale)vec[1]>>=1;
 func_001073A0(vec+1,ybits,code,rest,mode);
 if(scale)vec[1]<<=1;
 if(ext)out[1]=func_00106738(ctx);
}
