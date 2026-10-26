#define F(p,o) (*(int *)((char *)(p)+(o)))
extern void func_0010BD90(void *,char *,int);
extern void _dispRefImage(void *,int,int),_dispRefImageField(void *,int,int,int);
void _lastFrame(void *p){
 int n=F(p,0x130);
 if(F(p,0x138))func_0010BD90(p,"the second field is missing",n);
 else if(F(p,0x18c)==3)_dispRefImage(p,F(p,0x1d4),n-1);
 else _dispRefImageField(p,F(p,0x1e4),F(p,0x1f4),n-1);
 F(p,0x138)=0;
}

