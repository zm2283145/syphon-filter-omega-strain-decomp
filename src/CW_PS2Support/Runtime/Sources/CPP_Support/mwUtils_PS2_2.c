/*
 * CW_PS2Support/Runtime/Sources/CPP_Support/mwUtils_PS2: 1 file, 00100320
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00100320 */
#pragma push /* merge_units */
typedef struct Overlay {
    char pad0[0x14];
    int bssSize;
    void *ctorStart;
    void *ctorEnd;
} Overlay;

extern int sceOpen(const char *path, int mode);
extern int sceLseek(int fd, int offset, int whence);
extern int sceRead(int fd, void *buf, int size);
extern int sceClose(int fd);
extern void FlushCache(int mode);
extern void *memset(void *, int, unsigned int);
extern void FunctionList_CallEach(void *start, void *end, int a, int b);

int mwLoadOverlay(const char *path, char *buf)
{
    int ret = 0;
    int size = 0;
    int fd;
    Overlay *ovl;
    int bss;

    fd = sceOpen(path, 1);
    if (fd >= 0) {
        size = sceLseek(fd, 0, 2);
        sceLseek(fd, 0, 0);
    }
    if (size > 0)
        size = sceRead(fd, buf, size);
    if (fd >= 0)
        sceClose(fd);
    if (size > 0) {
        bss = ((Overlay *)buf)->bssSize;
        ovl = (Overlay *)buf;
        FlushCache(2);
        if (bss) {
            buf += size;
            memset(buf, 0, bss);
        }
        FunctionList_CallEach(ovl->ctorStart, ovl->ctorEnd, 0, 0);
        ret = 1;
    }
    return ret;
}
static inline void merge_flush_func_00100320(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00100320 */
