typedef struct Overlay {
    char pad0[0x14];
    int bssSize;
    void *ctorStart;
    void *ctorEnd;
} Overlay;

extern int func_001115B0(const char *path, int mode);
extern int func_001119B8(int fd, int offset, int whence);
extern int func_00111BF0(int fd, void *buf, int size);
extern int func_00111838(int fd);
extern void func_0010D3E0(int mode);
extern void *memset(void *, int, unsigned int);
extern void FunctionList_CallEach(void *start, void *end, int a, int b);

int func_00100320(const char *path, char *buf)
{
    int ret = 0;
    int size = 0;
    int fd;
    Overlay *ovl;
    int bss;

    fd = func_001115B0(path, 1);
    if (fd >= 0) {
        size = func_001119B8(fd, 0, 2);
        func_001119B8(fd, 0, 0);
    }
    if (size > 0)
        size = func_00111BF0(fd, buf, size);
    if (fd >= 0)
        func_00111838(fd);
    if (size > 0) {
        bss = ((Overlay *)buf)->bssSize;
        ovl = (Overlay *)buf;
        func_0010D3E0(2);
        if (bss) {
            buf += size;
            memset(buf, 0, bss);
        }
        FunctionList_CallEach(ovl->ctorStart, ovl->ctorEnd, 0, 0);
        ret = 1;
    }
    return ret;
}


