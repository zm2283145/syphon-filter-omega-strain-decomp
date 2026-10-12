extern int D_00485F48[];
extern void func_0010B500(int);
extern long func_001078B0(int *);
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


