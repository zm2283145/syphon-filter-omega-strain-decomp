/*
 * lib/libmpeg: 3 files, 00106758-001069F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00106758 */
typedef struct { char pad[0x18C]; int picture_structure; int top_field_first; } Ctx;

void _dualPrimeVector(Ctx *ctx, int DMV[][2], int *dmvector, int mvx, int mvy)
{
    if (ctx->picture_structure == 3) {
        if (ctx->top_field_first) {
            DMV[0][0] = ((mvx + (mvx > 0)) >> 1) + dmvector[0];
            DMV[0][1] = ((mvy + (mvy > 0)) >> 1) + dmvector[1] - 1;
            DMV[1][0] = ((3 * mvx + (mvx > 0)) >> 1) + dmvector[0];
            DMV[1][1] = ((3 * mvy + (mvy > 0)) >> 1) + dmvector[1] + 1;
        } else {
            DMV[0][0] = ((3 * mvx + (mvx > 0)) >> 1) + dmvector[0];
            DMV[0][1] = ((3 * mvy + (mvy > 0)) >> 1) + dmvector[1] - 1;
            DMV[1][0] = ((mvx + (mvx > 0)) >> 1) + dmvector[0];
            DMV[1][1] = ((mvy + (mvy > 0)) >> 1) + dmvector[1] + 1;
        }
    } else {
        DMV[0][0] = ((mvx + (mvx > 0)) >> 1) + dmvector[0];
        DMV[0][1] = ((mvy + (mvy > 0)) >> 1) + dmvector[1];
        if (ctx->picture_structure == 1)
            DMV[0][1]--;
        else
            DMV[0][1]++;
    }
}
/* merge_units: end func_00106758 */

/* merge_units: begin func_001068E0 */
#define FIELD(p,o) (*(int *)((char *)(p)+(o)))
extern unsigned int _ipuVdec(void *,int);
extern int _peepBit(void *,int),_flushBuf(void *,int);
extern int func_0010BD58(void *,const char *,int);
int _mbAddressIncrement(void *ctx)
{
 int sum=0, again;
 unsigned int code;
 do {
  code=_ipuVdec(ctx,0);
  switch(code){
   case 0x23:again=1;sum+=0x21;break;
   case 0x22:again=1;break;
   case 0:
    {int v=_peepBit(ctx,11);
     if(FIELD(ctx,0x860) && v==15){_flushBuf(ctx,11);again=1;}
     else{func_0010BD58(ctx,"Invalid macroblock_address_increment code(0x%08x)",code);FIELD(ctx,0x134)=1;return 1;}}
    break;
   default:sum+=code;again=0;break;
  }
 }while(again);
 return sum;
}
/* merge_units: end func_001068E0 */

/* merge_units: begin func_001069F0 */
#define F(p, o, T) (*(T *)((char *)(p) + (o)))
extern int _slice0(void *, int);
extern void _waitIpuIdle(void *);
extern int _waitBdecOut(void *);
extern void func_001054A8(void *, int);
extern void func_0010BD90(void *, const char *);

int _pictureData0(void *ctx)
{
    int r;
    int n;

    F(ctx, 0x828, int) = 0;
    n = F(ctx, 0x144, int) * F(ctx, 0x148, int);
    F(ctx, 0x82C, int) = 0;
    if (F(ctx, 0x18C, int) != 3)
        n = n >> 1;
    do {
        r = _slice0(ctx, n);
    } while (r == 1 || r == 3);
    _waitIpuIdle(ctx);
    if (!_waitBdecOut(ctx)) {
        if (F(ctx, 0x10A0, int))
            return 4;
        r = 2;
    }
    while ((*(volatile unsigned int *)0x1000D400 >> 8) & 1)
        ;
    if (r == 0)
        func_001054A8(ctx, F(ctx, 0x828, int) == 0);
    if (r == 1 || r == 2)
        func_0010BD90(ctx, "= Skip to the next picture =");
    return r == 0;
}
/* merge_units: end func_001069F0 */
