#define FIELD(p,o) (*(int *)((char *)(p)+(o)))
extern int func_0010BD90(void *,const char *);
int func_00106E38(void *ctx,int *a,int *b,int *c,int *flags)
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

