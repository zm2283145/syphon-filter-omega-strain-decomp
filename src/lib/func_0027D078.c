extern int (*D_00506144)(void *, void *, int, int, int *);
extern int (*D_00506148)(int, void *, void *, int *, int, int);
extern int (*D_0050614C)(int);

static inline void *offset(void *base,int off) { return (char*)base+off; }
static inline int callC(void *a,void *b,int c,int d,int *e) { if(D_00506144) return D_00506144(a,b,c,d,e+1); return -1; }
static inline int callD(int a,void *b,void *c,int *d,int e,int f) { if(D_00506148) return D_00506148(a,b,c,d+1,e,f); return -1; }
static inline int callE(int a) { if(D_0050614C) return D_0050614C(a); return -1; }
int *func_0027D078(unsigned int fno, int *buf)
{
    int r = -1;
    switch (fno) {
    case 0xC:
        r = callC((char *)buf + 0x10, offset(buf,buf[2]+0x10), buf[0], buf[1], buf);
        break;
    case 0xD:
        r = callD(buf[0], (char *)buf + 0x14, offset(buf,buf[1]+0x14), buf, buf[3], buf[4]);
        break;
    case 0xE:
        r = callE(buf[0]);
        break;
    }
    buf[0] = r;
    return buf;
}


