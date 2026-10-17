typedef struct { unsigned char zero,sec,min,hour,day,month; unsigned short year; } MCDate;
typedef struct { unsigned short mode,pad; int size; MCDate created; int cl,index; MCDate modified; int f20; char pad24[0x3c]; unsigned char extra; char rest[0x19f]; } MCEnt;
typedef struct { int busy; char pad[0x894]; } MCPortTail;
extern MCPortTail D_00513518[];
extern const char D_004AC220[];
extern void String_Copy(char *, char *);
extern char *func_00128F58(char *, const char *);
extern int func_002B8188(int,char*,char*);
extern int func_002B84E0(int,char*,MCEnt*,int*,int*);
extern int func_002BA220(int,char*,int,int,int,int*);
extern int func_002B8928(int,MCEnt*,int,int);
extern int func_002B6D60(int,int,int,int*);
extern int func_002B6D20(int,int,int*);
extern int func_002B6B28(int);
extern int func_002BAD48(int);
int func_002B9F10(int dev, char *path)
{
    MCEnt st;
    char full[0x80];
    char tmp[0x80];
    int parent, index;
    int cnt;
    int err;
    int cur, cl;
    err = func_002B8188(dev, path, full);
    if (err) return err;
    err = func_002B84E0(dev, full, &st, &parent, &index);
    if (err != 0x81010011) return err;
    if (!(st.mode & 2)) return 0x8101000D;
    if (st.mode & 0x20) {
        String_Copy(tmp, full);
        func_00128F58(tmp, D_004AC220);
        err = func_002BA220(dev, tmp, 0, -1, 0, &cnt);
        if (err) return err;
        if (cnt > 0) return 0x8101005A;
    }
    st.mode ^= 0x8000;
    err = func_002B8928(dev, &st, parent, index);
    if (err) return err;
    if (!func_002BAD48(dev)) goto fail;
    { int first = st.cl;
    if (first == -1) return 0;
    cl = first; }
    while (1) {
        cur = cl;
        cl = func_002B6D20(dev, cur, &err);
        if (err) return err;
        if (cl == -3) break;
        if (!(cl & 0x80000000)) break;
        func_002B6D60(dev, cur, cl ^ 0x80000000, &err);
        if (err) return err;
        if (cl == -1) break;
        cl &= 0x7FFFFFFF;
    }
    if (!func_002B6B28(dev)) goto fail;
    if (!func_002BAD48(dev)) {
fail:
        return 0x8101006F;
    }
    D_00513518[dev].busy = 0;
    return 0;
}


