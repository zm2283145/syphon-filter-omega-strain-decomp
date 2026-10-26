extern void _sendIpuCommand(int,int);
extern void _waitIpuIdle(int);
extern void _dispatchMpegCallback(int,int*);
extern int DIntr(void);
extern void EIntr(void);
void _setDefaultQM(int object,int value,int dma) {
 int command[5]; int enabled; int target=*(int*)(object+0x870);
 command[0]=2;
 _dispatchMpegCallback(target,command);
 _waitIpuIdle(object);
 {unsigned base=0x10000000;int arg=object; /* Materialize the IPU base and context before the command store. */ __asm__ volatile("" : "+r"(base), "+r"(arg)); *(int *)(base|0x2000)=0;_waitIpuIdle(arg);}
 enabled=DIntr();
 *(volatile int*)0x1000B410=dma&0x0FFFFFFF;
 *(volatile int*)0x1000B420=4;
 *(volatile int*)0x1000B400=0x101;
 if(enabled)EIntr();
 _sendIpuCommand(object,value);
 _waitIpuIdle(object);
 target=*(int*)(object+0x870);command[0]=3;
 _dispatchMpegCallback(target,command);
}




