typedef void (*Handler)(void *);extern Handler D_00498548[];
extern void func_00108048(void *);
extern unsigned func_00107CA8(void *,int),func_00107ED8(void *,int);
extern void func_00107DC8(void *,int);
void func_00108318(void *ctx){
 Handler handlers[11];unsigned code;
 __builtin_memcpy(handlers,D_00498548,44);
 func_00108048(ctx);
 while((code=func_00107CA8(ctx,32))==0x1b5 || code==0x1b2){
  if(code==0x1b5){
   unsigned ext;
   func_00107DC8(ctx,32);
   ext=func_00107ED8(ctx,4);
   ext=ext<=10?ext:0;
   handlers[ext](ctx);
   func_00108048(ctx);
  }else{
   func_00107DC8(ctx,32);
   func_00108048(ctx);
  }
 }
}

