typedef struct { unsigned long psize:8; unsigned long dsize:24; int dest; unsigned int cmd; int opt; int length,mode; char args[80]; } ResetPacket5618;
typedef struct { void *src; unsigned int dest; int size,attr; } Dma5618;
extern ResetPacket5618 D_004E6400;
extern int func_00118310(int,int);
extern void func_0010D430(void);
extern unsigned int func_0010D570(unsigned int);
extern void func_0010FB10(void *,int);
extern int func_0010D560(unsigned int,unsigned int);
extern int sceSifSetDma(Dma5618 *,int);
int func_00115618(char *args,int mode)
{
 Dma5618 dma;
 int n;
 unsigned int dest;
 func_00118310(0,0);func_00118310(1,0);
 func_0010D430();dest=func_0010D570(0x80000000);
 D_004E6400.mode=mode;
 for(n=0;args[n];n++)D_004E6400.args[n]=args[n];
 D_004E6400.dest=0;
 D_004E6400.length=n;
 D_004E6400.cmd=0x80000003;
 D_004E6400.dsize=0;
 D_004E6400.psize=0x68;
 dma.src=&D_004E6400;dma.dest=dest;dma.size=0x68;dma.attr=0x44;
 func_0010FB10(&D_004E6400,0x68);
 func_0010D560(4,0x40000);
 if(sceSifSetDma(&dma,1)){
  func_0010D560(4,0x10000);func_0010D560(4,0x20000);
  func_0010D560(0x80000002,0);func_0010D560(0x80000000,0);
  return 1;
 }
 return 0;
}
