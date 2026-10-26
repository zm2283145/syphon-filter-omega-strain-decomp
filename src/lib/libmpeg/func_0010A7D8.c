extern unsigned _sysbitGet(void *,int),_sysbitNext(void *,int);
extern void _sysbitMarker(void *),_system_header(void *,unsigned *);
int _pack_header(void *ctx,unsigned *out){
 unsigned hi,mid,lo,n,i=0;
 _sysbitGet(ctx,34);
 hi=_sysbitGet(ctx,3);
 _sysbitMarker(ctx);
 mid=_sysbitGet(ctx,15);
 _sysbitMarker(ctx);
 lo=_sysbitGet(ctx,15);
 _sysbitMarker(ctx);
 out[0]=_sysbitGet(ctx,9);
 _sysbitGet(ctx,30);
 n=_sysbitGet(ctx,3);
 out[2]=(hi>>2)&1;
 out[1]=(hi<<30)|(mid<<15)|lo;
 for(;i<n;i++)_sysbitGet(ctx,8);
 if(_sysbitNext(ctx,32)==0x1bb){out[3]=1;_system_header(ctx,out);}else out[3]=0;
 return 1;
}
