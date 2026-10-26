register int context_gp asm("$28");
typedef struct { unsigned long long key, mask; int handler, arg; void *gp; int pad; } Hook6E0;
typedef struct { char pad[0x60]; Hook6E0 *hooks; int count; } Lib6E0;
typedef struct { char pad[0x40]; Lib6E0 *lib; } Ctx6E0;
typedef struct { unsigned long long a,b; } Pair6E0;
extern Pair6E0 D_00485FB0[];
extern unsigned long long _type2id(int,int);
static inline int current_gp(void){int v=context_gp; /* Snapshot the callback global-pointer context. */ __asm__ volatile("" : "+r"(v) :: "memory"); return v;}
int sceMpegAddStrCallback(Ctx6E0 *ctx,int kind,int code,int handler,int arg)
{
 Lib6E0 *lib=ctx->lib;
 Hook6E0 *hooks=lib->hooks;
 int old=0,i;
 unsigned long long key=_type2id(kind,code);
 for(i=0;i<lib->count;i++){
  if(key==hooks[i].key){old=hooks[i].handler;break;}
 }
 if(i<64){
  hooks[i].key=key;
  hooks[i].handler=handler;
  hooks[i].arg=arg;
  hooks[i].mask=D_00485FB0[kind].b;
  /* Publish the callback mask before snapshotting its global-pointer context. */
  __asm__ volatile("" : "+r"(context_gp) :: "memory");
  hooks[i].gp=(void *)current_gp();
  lib->count++;
 }
 return old;
}



