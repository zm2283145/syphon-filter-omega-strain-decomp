extern int func_00107ED8(void *,int);
extern void func_001075C8(void *,int *,int *,int,int,int,int,int);
void func_00107428(void *ctx,int *vec,int *out,int *codes,int index,int type,int skip,int xbits,int ybits,int ext,int scale){
 if(type==1){
  if(!skip && !ext){
   int code=func_00107ED8(ctx,1);
   codes[index]=code;codes[index+2]=code;
  }
 }else{
  codes[index]=func_00107ED8(ctx,1);
  func_001075C8(ctx,vec+index*2,out,xbits,ybits,ext,scale,0);
  codes[index+2]=func_00107ED8(ctx,1);
  return func_001075C8(ctx,(int *)((char *)vec+(index*8+16)),out,xbits,ybits,ext,scale,0);
 }
 { int *v=vec+index*2;
 func_001075C8(ctx,v,out,xbits,ybits,ext,scale,0);
 { int x=v[0],y=v[1];v[4]=x;v[5]=y; } }
}


