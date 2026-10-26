typedef void (*Handler)(void *);
extern void _unknown_extension(void *);
extern void _sequenceExtension(void *);
extern void _sequenceDisplayExtension(void *);
extern void _quantMatrixExtension(void *);
extern void _copyrightExtension(void *);
extern void _sequenceScalableExtension(void *);
extern void _pictureDisplayExtension(void *);
extern void _pictureCodingExtension(void *);
extern void _pictureSpatialScalableExtension(void *);
extern void _pictureTemporalScalableExtension(void *);

extern void _nextStartCode(void *);
extern unsigned _peepBit(void *,int),_nextBit(void *,int);
extern void _flushBuf(void *,int);
void _extensionAndUserData(void *ctx){
 Handler handlers[11]={_unknown_extension,_sequenceExtension,_sequenceDisplayExtension,_quantMatrixExtension,_copyrightExtension,_sequenceScalableExtension,_unknown_extension,_pictureDisplayExtension,_pictureCodingExtension,_pictureSpatialScalableExtension,_pictureTemporalScalableExtension};unsigned code;
 _nextStartCode(ctx);
 while((code=_peepBit(ctx,32))==0x1b5 || code==0x1b2){
  if(code==0x1b5){
   unsigned ext;
   _flushBuf(ctx,32);
   ext=_nextBit(ctx,4);
   ext=ext<=10?ext:0;
   handlers[ext](ctx);
   _nextStartCode(ctx);
  }else{
   _flushBuf(ctx,32);
   _nextStartCode(ctx);
  }
 }
}

