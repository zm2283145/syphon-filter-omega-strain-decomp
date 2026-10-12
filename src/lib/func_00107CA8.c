extern int D_00485F48[];
extern void func_0010B500(int);
extern long func_001078B0(int *);
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
