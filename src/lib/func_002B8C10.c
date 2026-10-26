/* Layout follows the matched libmc2 neighbours at 002B84E0 and 002B96D0. */
typedef struct { unsigned char b[8]; } MCDate;
typedef struct { char b[32]; } MCName;
typedef struct {
    unsigned short mode, pad;
    int size;
    MCDate created;
    int cl, index;
    MCDate modified;
    int f20;
    char pad24[0x1c];
    MCName name;
    char rest[0x1a0];
} MCEnt;
extern MCEnt D_00513DC0[];
extern char D_004AC1B0[];
extern int strcmp(const char*,const char*);
extern int func_002BB2D0(int,void*,int,int);
extern int func_002BB2E8(int,void*,int,int);
extern int _sceMcFatGetNextClust(int,int,int*);
extern int _sceMcFatWriteFatData(int,int,int,int*);
extern int _sceMcFatGetFreeClust(int,int*);
extern int _GetEntryByPos(int,MCEnt*,int,int);
extern int _SetEntryByPos(int,MCEnt*,int,int);
int _CreateEntry(int dev, MCEnt *entry, int cl, int skip, int *err)
{
    MCEnt buf;
    MCEnt parent;
    int root = cl == 0;
    int count = 0;
    int i;
    int old;
    int r;
    int pcl;
    MCEnt *p;
    parent.cl = -1;
    for (;;) {
        if (!func_002BB2D0(dev,D_00513DC0,cl,1)) { *err=0x8101006f; return -1; }
        for (i=0,p=D_00513DC0;i<2;i++,p++,count++) {
            if ((unsigned short)(p->mode & 1)) {
                if (!strcmp(p->name.b,D_004AC1B0)) parent=*p;
            }
            if (!(p->mode & 0x8000) || skip==0) {
                *p=*entry;
                if (!func_002BB2E8(dev,D_00513DC0,cl,1)) { *err=0x8101006f; return -1; }
                if (skip) { *err=0; goto success; }
                pcl = parent.cl;
                if (pcl == -1) { *err = 0x81019002; return -1; }
                goto update;
            }
            skip -= skip>0;
        }
        if (!root && count>=20) { *err=0x81010017; return -1; }
        old=cl;
        cl=_sceMcFatGetNextClust(dev,old,err);
        if (*err) return -1;
        if (cl == -1) {
            cl=_sceMcFatGetFreeClust(dev,err);
            if (*err) return -1;
            _sceMcFatWriteFatData(dev,old,cl|0x80000000,err);
            if (*err) return -1;
            _sceMcFatWriteFatData(dev,cl,-1,err);
            if (*err) return -1;
            p=D_00513DC0;
            *p=*entry;
            p[1].mode=0;
            if (!func_002BB2E8(dev,D_00513DC0,cl,1)) { *err=0x8101006f; return -1; }
            if (parent.cl == -1) return 0x81019002;
            pcl = parent.cl;
        update:
            r = _GetEntryByPos(dev, &buf, pcl, parent.index);
            if (r) goto fail;
            buf.size++;
            r = _SetEntryByPos(dev, &buf, parent.cl, parent.index);
            if (r == 0) { *err = 0; goto success; }
        fail:
            *err = r;
            return -1;
        success:
            return count;
        }
        cl = cl & 0x7fffffff;
    }
}