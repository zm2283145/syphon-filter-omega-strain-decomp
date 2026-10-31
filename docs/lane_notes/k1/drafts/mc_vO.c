typedef struct {
    unsigned char resv2, sec, min, hour;
    unsigned char day, month;
    unsigned short year;
} sceMcStDateTime;

typedef struct {
    unsigned char stat, second, minute, hour;
    unsigned char pad, day, month, year;
} sceCdCLOCK;

struct SceMcDirEntry {
    unsigned short mode;
    unsigned short pad02;
    int length;
    sceMcStDateTime created;
    int cluster;
    int dir_entry;
    sceMcStDateTime modified;
    int attr;
    int pad24[7];
    char name[32];
    char pad60[0x200 - 0x60];
};

struct McName { char s[32]; };

extern struct SceMcDirEntry D_00513DC0[2];
extern const char D_004AC1B0[] __attribute__((aligned(4)));
extern const char D_004AC1B8[] __attribute__((aligned(4)));

int func_002B8188(int unit, const char *name, char *path);
int _get_dir_nest(const char *path);
int _sceMcFatSearchFile(int unit, const char *path, struct SceMcDirEntry *entry, int *cluster, int *dir_entry);
int _sceMcFatGetFreeClustSize(int unit, int *err);
int _GetFreeEntrySize(int unit, int cluster, int length, int *err);
int _sceMcFatGetFreeClust(int unit, int *err);
int _sceMcFatWriteFatData(int unit, int clust, int value, int *err);
int _sceMcCoreReadClock(int port, sceCdCLOCK *clk);
void *memset(void *dst, int c, unsigned int size);
char *strrchr(const char *s, int c);
int _CreateEntry(int unit, struct SceMcDirEntry *entry, int cluster, int length, int *err);
int func_002BB2E8(int unit, void *buf, int clust, int count);
int _sceMcFatFlushFatCache(int unit);
int func_002BAD48(int unit);

static __inline__ int BCD(unsigned char x) { return (x >> 4) * 10 + (x & 0xF); }

int _sceMcFatCreateFile(int unit, const char *name, int mode)
{
    struct SceMcDirEntry parent;
    struct SceMcDirEntry ent;
    char path[0x80];
    sceCdCLOCK clk;
    int ret;
    int isdir;
    char *pp;
    int top, free, n, clust, idx, i;
    char *q;
    struct SceMcDirEntry *p;

    pp = path;
    ret = func_002B8188(unit, name, pp);
    if (ret != 0)
        return ret;
    if (mode == 0)
        mode = 0x8417;
    isdir = mode & 0x20;
    if (isdir && _get_dir_nest(pp) >= 2)
        return 0x81019004;
    top = _get_dir_nest(pp) == 1;
    ret = _sceMcFatSearchFile(unit, pp, &parent, 0, 0);
    if (ret != (int)0x81010002)
        return ret;
    if (!top && parent.length - n >= 0x14)   /* n is read before it is set, as in the original (s3) */
        return 0x81010017;
    free = _sceMcFatGetFreeClustSize(unit, &ret);
    if (ret != 0)
        return ret;
    n = _GetFreeEntrySize(unit, parent.cluster, parent.length, &ret);
    if (ret != 0)
        return ret;
    i = isdir ? 2 : 1;
    free += n > ret;
    if (free < i)
        return 0x8101001C;
    if (isdir) {
        clust = _sceMcFatGetFreeClust(unit, &ret);
        if (ret != 0)
            return ret;
        _sceMcFatWriteFatData(unit, clust, -1, &ret);
        if (ret != 0)
            return ret;
    }
    _sceMcCoreReadClock(unit, &clk);
    memset(&ent, 0, 0x200);
    ent.mode = mode;
    ent.cluster = isdir ? clust : -1;
    ent.length = isdir ? 2 : 0;
    ent.created.year = BCD(clk.year) + 2000;
    ent.created.month = BCD(clk.month);
    ent.created.day = BCD(clk.day);
    ent.created.hour = BCD(clk.hour);
    ent.created.min = BCD(clk.minute);
    ent.created.sec = BCD(clk.second);
    ent.pad02 = 0;
    ent.created.resv2 = 0;
    ent.dir_entry = 0;
    ent.modified = ent.created;
    ent.attr = 0;
    q = strrchr(pp, '/');
    __builtin_memcpy(ent.name, q + 1, 32);
    idx = _CreateEntry(unit, &ent, parent.cluster, parent.length, &ret);
    if (idx < 0)
        return ret;
    if (isdir) {
        p = D_00513DC0;
        memset(p, 0, 0x200);
        p->mode = 0x8427;
        p->created.year = BCD(clk.year) + 2000;
        p->created.month = BCD(clk.month);
        p->created.day = BCD(clk.day);
        p->created.hour = BCD(clk.hour);
        p->created.min = BCD(clk.minute);
        p->created.sec = BCD(clk.second);
        p->dir_entry = idx;
        p->length = 0;
        p->pad02 = 0;
        p->cluster = 0;
        p->modified = p->created;
        __builtin_memcpy(p->name, D_004AC1B0, 2);
        p++;
        memset(p, 0, 0x200);
        p->mode = 0x8427;
        p->created.year = BCD(clk.year) + 2000;
        p->created.month = BCD(clk.month);
        p->created.day = BCD(clk.day);
        p->created.hour = BCD(clk.hour);
        p->created.min = BCD(clk.minute);
        p->created.sec = BCD(clk.second);
        p->length = 0;
        p->pad02 = 0;
        p->created.resv2 = 0;
        p->cluster = 0;
        p->dir_entry = 0;
        p->modified = p->created;
        p->attr = 0;
        __builtin_memcpy(p->name, D_004AC1B8, 3);
        if (func_002BB2E8(unit, D_00513DC0, ent.cluster, 1) == 0)
            return 0x8101006F;
    }
    if (_sceMcFatFlushFatCache(unit) == 0)
        return 0x8101006F;
    if (func_002BAD48(unit) == 0)
        return 0x8101006F;
    return ret;
}

