extern int D_00485F48[];
extern void func_0010B500(int);
extern long func_001078B0(int *);
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

