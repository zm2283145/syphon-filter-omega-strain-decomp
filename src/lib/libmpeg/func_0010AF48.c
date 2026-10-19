#define R(a) (*(volatile unsigned *)(a))
extern int DIntr(void);
extern void EIntr(void),func_0010CAF0(void);
int func_0010AF48(void){
 int irq=DIntr();
 R(0x1000F590)=R(0x1000F520)|0x10000;
 R(0x1000B000)&=~0x100;
 R(0x1000B400)&=~0x100;
 R(0x1000F590)=R(0x1000F520)&~0x10000;
 if(irq)EIntr();
 {unsigned *reg0=(unsigned *)0x1000B020,*reg1=(unsigned *)0x1000B420; /* Materialize both hardware addresses before the reset stores. */ __asm__ volatile("" : "+r"(reg0), "+r"(reg1)); *reg0=0;*reg1=0;}
 func_0010CAF0();return 1;
}

