typedef void (*Handler)(void *);
extern void func_0010C668(void *);
extern void func_0010C498(void *);
extern void func_0010C5C8(void *);
extern void func_00108790(void *);
extern void func_00108950(void *);
extern void _sequenceScalableExtension(void *);
extern void func_00108858(void *);
extern void func_00108440(void *);
extern void _pictureSpatialScalableExtension(void *);
extern void _pictureTemporalScalableExtension(void *);

extern void func_00108048(void *);
extern unsigned func_00107CA8(void *,int),func_00107ED8(void *,int);
extern void func_00107DC8(void *,int);
void func_00108318(void *ctx){
 Handler handlers[11]={func_0010C668,func_0010C498,func_0010C5C8,func_00108790,func_00108950,_sequenceScalableExtension,func_0010C668,func_00108858,func_00108440,_pictureSpatialScalableExtension,_pictureTemporalScalableExtension};unsigned code;
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

