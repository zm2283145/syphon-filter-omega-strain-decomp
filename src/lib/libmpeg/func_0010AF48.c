#define R(a) (*(volatile unsigned *)(a))
extern int func_001161A0(void);
extern void func_001161F8(void),func_0010CAF0(void);
int func_0010AF48(void){
 int irq=func_001161A0();
 R(0x1000F590)=R(0x1000F520)|0x10000;
 R(0x1000B000)&=~0x100;
 R(0x1000B400)&=~0x100;
 R(0x1000F590)=R(0x1000F520)&~0x10000;
 if(irq)func_001161F8();
 {unsigned *reg0=(unsigned *)0x1000B020,*reg1=(unsigned *)0x1000B420; /* Materialize both hardware addresses before the reset stores. */ __asm__ volatile("" : "+r"(reg0), "+r"(reg1)); *reg0=0;*reg1=0;}
 func_0010CAF0();return 1;
}

