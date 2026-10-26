/*
 * lib/libmpeg: 5 files, 00106E38-001075C8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00106E38 */
#define FIELD(p,o) (*(int *)((char *)(p)+(o)))
extern int func_0010BD90(void *,const char *);
int _skipMB0(void *ctx,int *a,int *b,int *c,int *flags)
{
 int result=1;
 FIELD(ctx,0x6E4+FIELD(ctx,0x828)*0x140)=1;
 FIELD(ctx,0x1C8)=1;
 if(FIELD(ctx,0x168)==2){a[0]=a[1]=a[4]=a[5]=0;}
 if(FIELD(ctx,0x18C)==3)*b=2;
 else{*b=1;c[0]=c[1]=(FIELD(ctx,0x18C)==2);}
 if(FIELD(ctx,0x168)==1){func_0010BD90(ctx,"skiped macroblock in I picure is not allowed");result=0;}
 *flags&=~1;
 return result;
}
/* merge_units: end func_00106E38 */

/* merge_units: begin func_00106EF8 */
#define F(p, o, T) (*(T *)((char *)(p) + (o)))
#define REG(a) (*(volatile unsigned int *)(a))
extern int _ipuVdec(void *, int);
#if 0 /* merge_units */
extern void func_0010BD90(void *, const char *);
#endif /* merge_units */
#define func_0010BD90(a0, a1) ((void)func_0010BD90((a0), (a1))) /* merge_units */

extern int _nextBit(void *, int);
extern void _flushBuf(void *, int);
extern void _motionVectors(void *, int *, int *, int *, int, int, int, int, int, int, int);
extern void _motionVector(void *, int *, int *, int, int, int, int, int);
extern void receiveDataFromIPU(int, int);
extern void _waitIpuIdle(void *);
extern void _sendIpuCommand(void *, int);

int _decMB0(void *m, int *macroblock_type, int *motion_type, int *dct_type,
                  int *PMV, int *mvfs, int *dmvector)
{
    int motion_vector_count;
    int mv_format;
    int dmv;
    int mvscale;

    REG(0x10002010) = (REG(0x10002010) & 0xF8FFFFFF) | (F(m, 0x168, int) << 24);
    *macroblock_type = _ipuVdec(m, 1);
    if (!*macroblock_type) {
        func_0010BD90(m, "Invalid macroblock_type code: 0");
        F(m, 0x134, int) = 1;
        return 0;
    }
    if (*macroblock_type & 0xC) {
        if (F(m, 0x18C, int) == 3 && F(m, 0x194, int))
            *motion_type = 2;
        else
            *motion_type = _nextBit(m, 2);
    } else if ((*macroblock_type & 1) && F(m, 0x198, int)) {
        *motion_type = F(m, 0x18C, int) == 3 ? 2 : 1;
    }

    if (F(m, 0x18C, int) == 3) {
        motion_vector_count = *motion_type == 1 ? 2 : 1;
        mv_format = *motion_type == 2;
    } else {
        motion_vector_count = *motion_type == 2 ? 2 : 1;
        mv_format = 0;
    }
    dmv = *motion_type == 3;
    mvscale = !mv_format && F(m, 0x18C, int) == 3;

    *dct_type = (F(m, 0x18C, int) == 3 && !F(m, 0x194, int) && (*macroblock_type & 3))
                    ? _nextBit(m, 1) : 0;

    if (*macroblock_type & 0x10)
        F(m, 0x1CC, int) = _nextBit(m, 5);

    if ((*macroblock_type & 8) || ((*macroblock_type & 1) && F(m, 0x198, int))) {
        if (F(m, 0x860, int))
            _motionVectors(m, PMV, dmvector, mvfs, 0, motion_vector_count, mv_format,
                          F(m, 0x17C, int) - 1, F(m, 0x180, int) - 1, dmv, mvscale);
        else
            _motionVector(m, PMV, dmvector, F(m, 0x170, int) - 1, F(m, 0x170, int) - 1, 0, 0,
                          F(m, 0x16C, int));
    }
    if (F(m, 0x134, int))
        return 0;

    if (*macroblock_type & 4) {
        if (F(m, 0x860, int))
            _motionVectors(m, PMV, dmvector, mvfs, 1, motion_vector_count, mv_format,
                          F(m, 0x184, int) - 1, F(m, 0x188, int) - 1, 0, mvscale);
        else
            _motionVector(m, PMV + 2, dmvector, F(m, 0x178, int) - 1, F(m, 0x178, int) - 1, 0, 0,
                          F(m, 0x174, int));
    }
    if (F(m, 0x134, int))
        return 0;

    if ((*macroblock_type & 1) && F(m, 0x198, int))
        _flushBuf(m, 1);

    if (*macroblock_type & 3) {
        receiveDataFromIPU(F(m, F(m, 0x828, int) * 0x140 + 0x5AC, int), 0x300);
        _waitIpuIdle(m);
        _sendIpuCommand(m, ((*macroblock_type & 1) << 27) | (*dct_type << 25) | ((F(m, 0x1C8, int) << 26) | 0x20000000) | (F(m, 0x1CC, int) << 16));
    } else {
        F(m, F(m, 0x828, int) * 0x140 + 0x6E4, int) = 1;
    }
    F(m, 0x1C8, int) = 0;
    if (F(m, 0x134, int))
        return 0;

    if (!(*macroblock_type & 1))
        F(m, 0x1C8, int) = 1;

    if ((*macroblock_type & 1) && !F(m, 0x198, int)) {
        PMV[0] = PMV[1] = PMV[4] = PMV[5] = 0;
        PMV[2] = PMV[3] = PMV[6] = PMV[7] = 0;
    }

    if (F(m, 0x168, int) == 2 && !(*macroblock_type & 9)) {
        PMV[0] = PMV[1] = PMV[4] = PMV[5] = 0;
        if (F(m, 0x18C, int) == 3) {
            *motion_type = 2;
        } else {
            *motion_type = 1;
            mvfs[0] = F(m, 0x18C, int) == 2;
        }
    }
    return 1;
}
#undef func_0010BD90 /* merge_units */
/* merge_units: end func_00106EF8 */

/* merge_units: begin func_001073A0 */
void _decode_motion_vector(int *p, int shift, int n, int off, int half)
{
    int lim = 16 << shift;
    int v = *p;
    if (half) v >>= 1;
    if (n > 0) {
        v += ((n - 1) << shift) + off + 1;
        if (v >= lim) v -= lim * 2;
    } else if (n < 0) {
        v -= ((-n - 1) << shift) + off + 1;
        if (v < -lim) v += lim * 2;
    }
    *p = half ? v << 1 : v;
}
/* merge_units: end func_001073A0 */

/* merge_units: begin func_00107428 */
void _motionVectors(void *ctx,int *vec,int *out,int *codes,int index,int type,int skip,int xbits,int ybits,int ext,int scale){
 if(type==1){
  if(!skip && !ext){
   int code=_nextBit(ctx,1);
   codes[index]=code;codes[index+2]=code;
  }
 }else{
  codes[index]=_nextBit(ctx,1);
  _motionVector(ctx,vec+index*2,out,xbits,ybits,ext,scale,0);
  codes[index+2]=_nextBit(ctx,1);
  return _motionVector(ctx,(int *)((char *)vec+(index*8+16)),out,xbits,ybits,ext,scale,0);
 }
 { int *v=vec+index*2;
 _motionVector(ctx,v,out,xbits,ybits,ext,scale,0);
 { int x=v[0],y=v[1];v[4]=x;v[5]=y; } }
}
/* merge_units: end func_00107428 */

/* merge_units: begin func_001075C8 */
extern int _ipuVdec(void *,int),_nextBit(void *,int),_dmVector(void *);
#if 0 /* merge_units */
extern void _decode_motion_vector(int *,int,int,int,int);
#endif /* merge_units */
#define _decode_motion_vector(a0, a1, a2, a3, a4) (_decode_motion_vector((a0), (a1), (a2), (a3), (a4))) /* merge_units */

void _motionVector(void *ctx,int *vec,int *out,int xbits,int ybits,int ext,int scale,int mode){
 int code=_ipuVdec(ctx,2);
 int rest;
 if(xbits && code) rest=_nextBit(ctx,xbits);else rest=0;
 _decode_motion_vector(vec,xbits,code,rest,mode);
 if(ext) out[0]=_dmVector(ctx);
 code=_ipuVdec(ctx,2);
 if(ybits && code) rest=_nextBit(ctx,ybits);else rest=0;
 if(scale)vec[1]>>=1;
 _decode_motion_vector(vec+1,ybits,code,rest,mode);
 if(scale)vec[1]<<=1;
 if(ext)out[1]=_dmVector(ctx);
}
#undef _decode_motion_vector /* merge_units */
/* merge_units: end func_001075C8 */
