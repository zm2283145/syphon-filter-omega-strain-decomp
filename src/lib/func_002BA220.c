typedef struct { unsigned char zero, sec, min, hour, day, month; unsigned short year; } MCDate;
typedef struct {
    unsigned short mode, pad; int size; MCDate created; int cl; int index; MCDate modified;
    int f20; char pad24[0x1C]; char name[0x20]; char rest[0x1A0];
} MCEnt;
typedef struct { unsigned short mode; unsigned short pad; int f4; int f8; int fC; int f10; char pad2[0x1EC]; } MCDirInfo;
typedef struct { MCDate created; MCDate modified; int size; unsigned short mode; short pad; char name[0x20]; } MCDirOut;
typedef struct { int x; char pad[0x894]; } E2BA220;
extern E2BA220 D_00513514[];
extern MCEnt D_00513DC0[];
extern char D_004AC1B0[];
extern char D_004AC1B8[];
extern char D_004AC1C8[];
extern int func_002BC788(int);
extern int _make_path(int, char *, char *);
extern int strcmp(const char *, const char *);
extern unsigned int strlen(const char *);
extern char *strrchr(const char *, int);
extern char *String_Copy(char *, const char *);
extern int _sceMcFatSearchFile(int, char *, MCDirInfo *, int *, int *);
extern int _GetEntryByPos(int, MCEnt *, int, int);
extern int func_002BB2D0(int, void *, int, int);
extern int isWildFit(char *, char *);
extern int _sceMcFatGetNextClust(int, int, int *);

/* getdir: list the entries of a memory card directory matching a name pattern */
int _sceMcFatGetDir(int dev, char *path, int start, int max, MCDirOut *out, int *count)
{
    char buf[0x80];
    char dir[0x80];
    char pat[0x40];
    MCEnt ent;
    MCDirInfo st;
    int err;
    int done = 0;
    int n, i, cl;

    if (!func_002BC788(dev)) return 0x81010013;
    if (D_00513514[dev].x == 0) return 0x8101006F;
    if (!_make_path(dev, path, buf) || !strcmp(buf, D_004AC1C8)) return 0x81010016;
    String_Copy(dir, buf);
    *strrchr(dir, '/') = 0;
    String_Copy(pat, dir + strlen(dir) + 1);
    if (strlen(dir) == 0) {
        err = _sceMcFatSearchFile(dev, D_004AC1C8, &st, 0, 0);
        if (err != 0x81010011) return err;
    } else {
        err = _sceMcFatSearchFile(dev, dir, &st, 0, 0);
        if (err != 0x81010011) return err;
    }
    if (!(st.mode & 0x20)) return 0x81010014;
    err = _GetEntryByPos(dev, &ent, st.f10, 0);
    if (err) {
        if (err == 0x81010002) err = 0x81019002;
        return err;
    }
    if (!(ent.mode & 0x8000)) return 0x81019002;
    if (strcmp(ent.name, D_004AC1B0)) return 0x81019002;
    err = _GetEntryByPos(dev, &ent, st.f10, 1);
    if (err) {
        if (err == 0x81010002) err = 0x81019002;
        return err;
    }
    if (!(ent.mode & 0x8000)) return 0x81019002;
    if (strcmp(ent.name, D_004AC1B8)) return 0x81019002;
    n = 0;
    if (start + 2 >= st.f4) {
        if (count) *count = 0;
        return 0;
    }
    cl = st.f10;
    start += 2;
    do {
        if (start < 2) {
            if (!func_002BB2D0(dev, D_00513DC0, cl, 1)) return 0x8101006F;
            for (i = start; i < 2; i++) {
                ent = D_00513DC0[i];
                ent.name[0x1F] = 0;
                if (!(ent.mode & 0x8000)) continue;
                if (ent.mode & 0x2000) continue;
                if (!isWildFit(ent.name, pat)) continue;
                if (out && max > 0) {
                    out->created = ent.created;
                    out->modified = ent.modified;
                    out->size = ent.size;
                    out->mode = ent.mode;
                    String_Copy(out->name, ent.name);
                    out++;
                }
                n++;
                if (max > 0 && n >= max) {
                    done = 1;
                    break;
                }
            }
            start = 0;
        }
        if (done == 1) break;
        cl = _sceMcFatGetNextClust(dev, cl, &err);
        if (err) return err;
        if (cl == -1) break;
        if (start) start -= 2;
        cl &= 0x7FFFFFFF;
    } while (!done);
    if (count) *count = n;
    return 0;
}
