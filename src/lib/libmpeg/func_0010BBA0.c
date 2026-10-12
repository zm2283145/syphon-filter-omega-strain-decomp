#define F(p,o) (*(int *)((char *)(p)+(o)))
extern char D_004987A8[];
extern void func_0010BD90(void *,char *,int);
extern void func_001092C8(void *,int,int),func_001093D8(void *,int,int,int);
void func_0010BBA0(void *p){
 int n=F(p,0x130);
 if(F(p,0x138))func_0010BD90(p,D_004987A8,n);
 else if(F(p,0x18c)==3)func_001092C8(p,F(p,0x1d4),n-1);
 else func_001093D8(p,F(p,0x1e4),F(p,0x1f4),n-1);
 F(p,0x138)=0;
}

