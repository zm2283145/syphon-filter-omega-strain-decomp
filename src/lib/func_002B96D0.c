/* func_002B96D0: libmc2 file read (read len bytes at off from path into buf). */
typedef struct { unsigned short mode; unsigned short pad; int size; int f8; int fC; int cl; char pad2[0x1EC]; } MC2Dirent;
extern char D_00513DC0[];
extern void *memcpy(void *, const void *, unsigned int);
extern int func_002B8188(int, char *, char *);
extern int func_002B84E0(int, char *, MC2Dirent *, int *, int *);
extern int func_002BB2D0(int, void *, int, int);
extern int func_002B6D20(int, int, int *);
int func_002B96D0(int idx, char *path, char *buf, int off, int len)
{
    MC2Dirent st;
    char full[0x80];
    int err;
    int r;
    int total;
    int cl;
    int n;
    char *p;

    r = func_002B8188(idx, path, full);
    if (r) return r;
    if (func_002B84E0(idx, full, &st, 0, 0) != 0x81010011) return err;
    if (!(unsigned short)(st.mode & 1)) return 0x8101000D;
    if (st.mode & 0x2000) return 0x8101000D;
    if (st.mode & 0x20) return 0x81010002;
    if (st.size < off) return 0x81010016;
    p = buf;
    if (len == 0) len = st.size - off;
    if (st.size < len + off) len = st.size - off;
    cl = st.cl;
    total = len;
    while (len) {
        if (off < 0x400) {
            err = func_002BB2D0(idx, D_00513DC0, cl, 1);
            if (!err) return 0x8101006F;
            n = 0x400 - off;
            if (n < len) {
                memcpy(p, D_00513DC0 + off, n);
                p += n;
                len = len + off - 0x400;
                off = 0;
            } else {
                memcpy(p, D_00513DC0 + off, len);
                break;
            }
        }
        cl = func_002B6D20(idx, cl, &err);
        if (err) return err;
        if (cl == -1) return 0x81019002;
        if (off) off -= 0x400;
        cl &= 0x7FFFFFFF;
    }
    return total;
}

