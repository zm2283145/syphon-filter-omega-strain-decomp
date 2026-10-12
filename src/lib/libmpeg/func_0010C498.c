extern void func_00106478(int);
extern unsigned func_00107ED8(int *,int);
extern void func_0010BD90(int *,char *);
void func_0010C498(int *p){
 unsigned first,second,x,y,z,code;
 p[0x860/4]=1;func_00106478(0);
 first=func_00107ED8(p,28);
 x=(first>>1)&0xfff;y=(first>>13)&3;z=(first>>15)&3;
 p[0x158/4]=(first>>17)&3;
 if(p[0x158/4]!=1)func_0010BD90(p,"_chroma_format needs to be 1: 420");
 p[0x154/4]=(first>>19)&1;
 code=first>>20;
 second=func_00107ED8(p,16)>>8;
 if(code!=0x48&&code!=0x58&&code!=0x44)func_0010BD90(p,"Unsupported profile/level");
 {int a=(z<<12)|(p[0x13c/4]&0xfff),b=(y<<12)|(p[0x140/4]&0xfff),c=p[0x14c/4]+(x<<18),d=p[0x150/4]+(second<<10);
p[0x13c/4]=a;p[0x140/4]=b;p[0x14c/4]=c;p[0x150/4]=d;}
}
