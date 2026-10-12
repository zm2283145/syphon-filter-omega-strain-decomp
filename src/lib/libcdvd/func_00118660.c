extern char D_004878D8[];
extern void func_00118420(char *);
typedef struct {int n,m;unsigned char *a,*b;unsigned char x[64],y[64];} Req;
void func_00118660(Req *p){
 int i;
 p=(Req *)((unsigned)p|0x20000000);
 if(p->n>0){
  unsigned char *dest=p->a,*uncached=(unsigned char *)((unsigned)dest|0x20000000);
  for(i=0;i<p->n;i++) {unsigned char c=p->x[i];uncached[i]=c;dest[i]=c;}
 }
 if(p->m>0){
  unsigned char *dest=p->b,*uncached=(unsigned char *)((unsigned)dest|0x20000000);
  for(i=0;i<p->m;i++) {unsigned char c=p->y[i];uncached[i]=c;dest[i]=c;}
 }
 func_00118420(D_004878D8);
}
