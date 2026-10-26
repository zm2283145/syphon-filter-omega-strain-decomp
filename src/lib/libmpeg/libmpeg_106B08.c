#define F(p,o,T) (*(T *)((char *)(p)+(o)))
extern void _nextStartCode(void *,int);
extern int _peepBit(void *,int),_flushBuf(void *,int),_sliceB(void *),_mbAddressIncrement(void *);
extern void func_0010BD58(void *,char *,int),func_0010BD90(void *,char *);
int func_00106B08(void *ctx,int arg,int *pos,int *count,int *state){
 int code,ext,n;
 F(ctx,0x134,int)=0;
 _nextStartCode(ctx,arg);
 code=_peepBit(ctx,32);
 if((unsigned)(code-0x101)>=0xaf){func_0010BD58(ctx,"slice_start_code(0x%08x) out of range",code);return 2;}
 _flushBuf(ctx,32);
 ext=_sliceB(ctx);
 n=_mbAddressIncrement(ctx);
 *count=n;
 if(F(ctx,0x134,int)){func_0010BD90(ctx,"_sliceA0(): error happens");return 1;}
 *pos=(((ext<<7)+(code&255)-1)*F(ctx,0x144,int))+n-1;
 *count=1;
 F(ctx,0x1c8,int)=1;
 state[2]=state[3]=state[6]=state[7]=state[0]=state[1]=state[4]=state[5]=0;
 return 0;
}

