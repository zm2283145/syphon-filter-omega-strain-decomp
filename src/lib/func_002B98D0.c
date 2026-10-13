typedef struct { unsigned char zero,sec,min,hour,day,month; unsigned short year; } MCDate;
typedef struct { unsigned short mode,pad; int size; MCDate created; int cl,index; MCDate modified; int f20; char pad24[0x3c]; unsigned char extra; char rest[0x19f]; } MCEnt;
extern char D_00513DC0[];
extern int func_002B8188(int,char*,char*);
extern int func_002B84E0(int,char*,MCEnt*,int*,int*);
extern int func_002B7260(int,int);
/* Weak in-TU scheduling model; linker discards body. */
int __attribute__((weak,section(".dtors_drop"))) func_002B6FF0(int a,int*b){return 0;}
/* Weak in-TU scheduling model; linker discards body. */
int __attribute__((weak,section(".dtors_drop"))) func_002B6EA8(int a,int*b){return 0;}
extern int func_002B6D60(int,int,int,int*);
extern int func_002B6D20(int,int,int*);
extern int func_002BBF98(int,void*);
extern int func_002B8928(int,MCEnt*,int,int);
extern int func_002B6B28(int);
extern int func_002BAD48(int);
extern int func_002BB2D0(int,void*,int,int);
extern int func_002BB2E8(int,void*,int,int);
extern void *memcpy(void*,const void*,unsigned int);
static __inline__ int BCD(unsigned int v) { int d=(v>>4)*10; return d+(v&15); }
int func_002B98D0(int dev,char *path,char *data,int off,int len)
{
    MCEnt st;
    char full[0x80];
    unsigned char rtc[8];
    int parent,index;
    int err;
    int io;
    int total;
    /* Retail reads this stack slot during initial allocation, before loop setup. */
    int position;
    int n;
    int cl;
    int old;
    int need;
    int have;
    int sum;
    char *p;
    char *cache;
    err=func_002B8188(dev,path,full);
    if(err)return err;
    err=func_002B84E0(dev,full,&st,&parent,&index);
    if(err!=0x81010011)return err;
    if(st.extra)return 0x81019002;
    { int mode=st.mode&0xf000; if(mode!=0x8000 && mode!=0xa000)return 0x81019002; }
    { int mode=st.mode&0xf00; if(mode!=0x400 && mode!=0)return 0x81019002; }
    if(!(st.mode&2))return 0x8101000d;
    if(st.mode&0x20)return 0x81010002;
    if(st.size<off)return 0x81010016;
    need=(off+len+0x3ff)/0x400;
    have=func_002B7260(dev,st.cl);
    if(have<0)return have;
    if(have<need) {
        int space=func_002B6FF0(dev,&err);
        if(err)return err;
        if(space<need-have)return 0x8101001c;
    }
    if(st.cl==-1) {
        cl=func_002B6EA8(dev,&err);
        if(err)return err;
        func_002B6D60(dev,cl,-1,&err);
        if(err)return err;
        st.cl=cl;
        func_002BBF98(dev,rtc);
        st.size=st.size<position?position:st.size;
        st.modified.month=BCD(rtc[6]);
        st.modified.year=BCD(rtc[7])+2000;
        st.modified.day=BCD(rtc[5]);
        st.modified.hour=BCD(rtc[3]);
        st.modified.min=BCD(rtc[2]);
        st.modified.sec=BCD(rtc[1]);
        err=func_002B8928(dev,&st,parent,index);
        if(err)return err;
        io=func_002B6B28(dev);
        if(!io)goto fail;
        io=func_002BAD48(dev);
        if(!io)goto fail;
    }
    p=data;
    cache=D_00513DC0;
    total=len;
    cl=st.cl;
    position=off;
for (;;) {
        if(off<0x400) {
            sum=off+len;
            if(sum<0x400) {
                if(position<st.size) {
                    io=func_002BB2D0(dev,D_00513DC0,cl,1);
                    if(!io)goto fail;
                }
            }
            n=0x400-off;
            if(n<len) {
                {char *dst=(char*)off; dst+=(unsigned int)cache; memcpy(dst,p,n); }
                io=func_002BB2E8(dev,cache,cl,1);
                if(!io)goto fail;
                p+=n;
                len=sum-0x400;
                position=position-off+0x400;
                off=0;
            } else {
                {char *dst=(char*)off; dst+=(unsigned int)cache; memcpy(dst,p,len); }
                io=func_002BB2E8(dev,cache,cl,1);
                if(!io)goto fail;
                position+=len;
                goto finished;
            }
        }
        old=cl;
        cl=func_002B6D20(dev,old,&io);
        if(io)return io;
        if(cl==-1) { do {
            cl=func_002B6EA8(dev,&err);
            /* Bind the loaded error result to the return register, as in retail. */
            {register int failure asm("$2")=err; if(failure)return failure;}
            func_002B6D60(dev,cl,-1,&err);
            /* Bind the loaded error result to the return register, as in retail. */
            {register int failure asm("$2")=err; if(failure)return failure;}
            func_002B6D60(dev,old,cl|0x80000000,&err);
            /* Bind the loaded error result to the return register, as in retail. */
            {register int failure asm("$2")=err; if(failure)return failure;}
        }while(0);
        }
        off=off?off-0x400:off;
        cl&=0x7fffffff;
        continue;
    }
finished:
    io=func_002B6B28(dev);
    if(!io)return 0x8101006f;
    io=func_002BAD48(dev);
    if(!io)return 0x8101006f;
    func_002BBF98(dev,rtc);
    st.size=st.size<position?position:st.size;
    st.mode|=0x80;
    st.modified.year=BCD(rtc[7])+2000;
    st.modified.month=BCD(rtc[6]);
    st.modified.day=BCD(rtc[5]);
    st.modified.hour=BCD(rtc[3]);
    st.modified.min=BCD(rtc[2]);
    st.modified.sec=BCD(rtc[1]);
    err=func_002B8928(dev,&st,parent,index);
    if(!err)goto last;
    return err;
fail:
    return 0x8101006f;
last:
    io=func_002BAD48(dev);
    return io?total:0x8101006f;
}
