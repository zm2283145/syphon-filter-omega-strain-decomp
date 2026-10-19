extern void func_00107718(int,int);
extern void func_00107748(int);
extern void func_0010B488(int,int*);
extern int DIntr(void);
extern void EIntr(void);
void func_0010C3B8(int object,int value,int dma) {
 int command[5]; int enabled; int target=*(int*)(object+0x870);
 command[0]=2;
 func_0010B488(target,command);
 func_00107748(object);
 {unsigned base=0x10000000;int arg=object; /* Materialize the IPU base and context before the command store. */ __asm__ volatile("" : "+r"(base), "+r"(arg)); *(int *)(base|0x2000)=0;func_00107748(arg);}
 enabled=DIntr();
 *(volatile int*)0x1000B410=dma&0x0FFFFFFF;
 *(volatile int*)0x1000B420=4;
 *(volatile int*)0x1000B400=0x101;
 if(enabled)EIntr();
 func_00107718(object,value);
 func_00107748(object);
 target=*(int*)(object+0x870);command[0]=3;
 func_0010B488(target,command);
}




