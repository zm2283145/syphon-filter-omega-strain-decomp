/*
 * lib/libmpeg: 7 files, 00107748-00108048
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00107748 */
#define F(p, o, T) (*(T *)((char *)(p) + (o)))
#define REG(a) (*(volatile unsigned int *)(a))
extern int DIntr(void);
extern void EIntr(void);
extern void func_0010B500(int);

void func_00107748(void *m)
{
    int count = 0;
    int oldintr;

    while ((REG(0x10002010) & 0x80004000) == 0x80000000) {
        if (F(m, 0x10A0, int)) {
            oldintr = DIntr();
            REG(0x1000F590) = REG(0x1000F520) | 0x10000;
            REG(0x1000B400) = 0;
            REG(0x1000B000) = 0;
            *(unsigned int *)0x1000F590 = REG(0x1000F520) & ~0x10000;
            if (oldintr)
                EIntr();
            REG(0x1000B020) = 0;
            REG(0x1000B420) = 0;
            REG(0x10002010) = 0x40000000;
            return;
        }
        if (count++ > 5000) {
            func_0010B500(F(m, 0x870, int));
            count = 0;
        }
    }
}
/* merge_units: end func_00107748 */

/* merge_units: begin func_001078B0 */
long func_001078B0(void *m)
{
    long cmd;
    int count = 0;
    int oldintr;

    while ((cmd = *(volatile long *)0x10002000) < 0 && !(REG(0x10002010) & 0x4000)) {
        if (F(m, 0x10A0, int)) {
            oldintr = DIntr();
            REG(0x1000F590) = REG(0x1000F520) | 0x10000;
            REG(0x1000B400) = 0;
            REG(0x1000B000) = 0;
            *(unsigned int *)0x1000F590 = REG(0x1000F520) & ~0x10000;
            if (oldintr)
                EIntr();
            REG(0x1000B020) = 0;
            REG(0x1000B420) = 0;
            REG(0x10002010) = 0x40000000;
            break;
        }
        if (count++ > 5000) {
            func_0010B500(F(m, 0x870, int));
            count = 0;
        }
    }
    return cmd;
}
/* merge_units: end func_001078B0 */

/* merge_units: begin func_00107A38 */
extern int D_00485F48[];

int func_00107A38(void *m, int type)
{
    int count2 = 0;
    int count = 0;
    int value;
    long cmd;
    unsigned int bp;
    long top;
    int oldintr;

    while ((REG(0x10002010) & 0x80004000) == 0x80000000 && !F(m, 0x10A0, int)) {
        if (count++ > 5000) {
            func_0010B500(F(m, 0x870, int));
            count = 0;
        }
    }
    value = (type << 26) | 0x30000000;
    REG(0x10002000) = value;
    F(m, 0x830, int) = D_00485F48[value >> 28];
    while ((cmd = *(volatile long *)0x10002000) < 0) {
        if (F(m, 0x10A0, int)) {
            oldintr = DIntr();
            REG(0x1000F590) = REG(0x1000F520) | 0x10000;
            REG(0x1000B400) = 0;
            REG(0x1000B000) = 0;
            *(unsigned int *)0x1000F590 = REG(0x1000F520) & ~0x10000;
            if (oldintr)
                EIntr();
            REG(0x1000B020) = 0;
            REG(0x1000B420) = 0;
            REG(0x10002010) = 0x40000000;
            return 0;
        }
        if (count2++ > 5000) {
            func_0010B500(F(m, 0x870, int));
            count2 = 0;
        }
    }
    bp = REG(0x10002020);
    top = *(long *)0x10002030;
    F(m, 0x850, int) = (int)top;
    if (top < 0)
        F(m, 0x854, int) = (32 - (bp & 0x1F)) & 0x1F;
    else
        F(m, 0x854, int) = 32;
    F(m, 0x134, int) = (int)cmd == 0;
    return (short)cmd;
}
/* merge_units: end func_00107A38 */

/* merge_units: begin func_00107CA8 */
#if 0 /* merge_units */
extern long func_001078B0(int *);
#endif /* merge_units */
#define func_001078B0(a0) (func_001078B0((void *)(a0))) /* merge_units */

unsigned func_00107CA8(int *m,int bits){
 if(m[0x830/4] || m[0x854/4]<bits){
  int count=0,value;
  while((*(volatile unsigned *)0x10002010 &0x80004000)==0x80000000 && !m[0x10A0/4]){
   if(count++>5000){func_0010B500(m[0x870/4]);count=0;}
  }
  *(volatile unsigned *)0x10002000=0x40000000;
  m[0x830/4]=D_00485F48[4];
  value=(int)func_001078B0(m);
  m[0x850/4]=value;m[0x854/4]=32;
 }
 return (unsigned)m[0x850/4]>>(32-bits);
}
#undef func_001078B0 /* merge_units */
/* merge_units: end func_00107CA8 */

/* merge_units: begin func_00107DC8 */
#if 0 /* merge_units */
extern long func_001078B0(int *);
#endif /* merge_units */
#define func_001078B0(a0) (func_001078B0((void *)(a0))) /* merge_units */

void func_00107DC8(int *m,unsigned cmd){
 int count=0,result;unsigned value;
 while((*(volatile unsigned *)0x10002010 &0x80004000)==0x80000000 && !m[0x10A0/4]){
  if(count++>5000){func_0010B500(m[0x870/4]);count=0;}
 }
 value=cmd|0x40000000;
 *(volatile unsigned *)0x10002000=value;
 m[0x830/4]=D_00485F48[value>>28];
 result=(int)func_001078B0(m);
 m[0x850/4]=result;m[0x854/4]=32;

}
#undef func_001078B0 /* merge_units */
/* merge_units: end func_00107DC8 */

/* merge_units: begin func_00107ED8 */
#if 0 /* merge_units */
extern long func_001078B0(int *);
#endif /* merge_units */
#define func_001078B0(a0) (func_001078B0((void *)(a0))) /* merge_units */

unsigned func_00107ED8(int *m,int bits){
 int count=0;unsigned result,value;
 while((*(volatile unsigned *)0x10002010 &0x80004000)==0x80000000 && !m[0x10A0/4]){
  if(count++>5000){func_0010B500(m[0x870/4]);count=0;}
 }
 if(m[0x830/4] || m[0x854/4]<bits){
  *(volatile unsigned *)0x10002000=0x40000000;
  m[0x830/4]=D_00485F48[4];
  m[0x850/4]=(int)func_001078B0(m);
 }
 m[0x854/4]=32;
 result=(unsigned)m[0x850/4]>>(32-bits);
 value=bits|0x40000000;
 {unsigned index=value>>28; *(volatile unsigned *)0x10002000=value;
 m[0x830/4]=D_00485F48[index];}
 m[0x850/4]=(int)func_001078B0(m);
 return result;
}
#undef func_001078B0 /* merge_units */
/* merge_units: end func_00107ED8 */

/* merge_units: begin func_00108048 */
#if 0 /* merge_units */
extern void func_00107748(void *);
#endif /* merge_units */
#define func_00107748(a0) (func_00107748((a0))) /* merge_units */

#if 0 /* merge_units */
extern void func_00107DC8(void *, int);
#endif /* merge_units */
#define func_00107DC8(a0, a1) (func_00107DC8((int *)(a0), (unsigned)(a1))) /* merge_units */

#if 0 /* merge_units */
extern int func_00107CA8(void *, int);
#endif /* merge_units */
#define func_00107CA8(a0, a1) ((int)func_00107CA8((int *)(a0), (a1))) /* merge_units */


void func_00108048(char *m)
{
    int n;
    func_00107748(m);
    n = -(*(volatile int *)0x10002020 & 7) & 7;
    if (n) func_00107DC8(m, n);
    while (func_00107CA8(m, 0x18) != 1 && *(int *)(m + 0x10A0) == 0) func_00107DC8(m, 8);
}
#undef func_00107748 /* merge_units */
#undef func_00107DC8 /* merge_units */
#undef func_00107CA8 /* merge_units */
/* merge_units: end func_00108048 */
