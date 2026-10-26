typedef struct { unsigned short mode; unsigned short pad; int f4; int f8; int fC; int f10; char pad2[0x2C]; char name[0x20]; char rest[0x1A0]; } MC2Dirent;
typedef struct { char pad[0x3C]; int f3C; char pad2[0x144]; } MC2Super;
extern MC2Super D_0048BD90[];
extern char D_004AC1B0[];
extern const char D_004AC1C8[];
extern int strcmp(const char *, const char *);
extern unsigned int strlen(const char *);
extern char *String_Copy(char *, const char *);
extern char *_strtok(char *, const char *);
extern int func_002B8188(int, char *, char *);
extern int _GetEntryByPos(int, MC2Dirent *, int, int);
extern int _SearchEntry(int, MC2Dirent *, int *, char *, int, int);
int _sceMcFatSearchFile(int idx, char *path, MC2Dirent *st, int *x, int *y)
{
    MC2Dirent buf;
    MC2Dirent dir;
    char name[0x20];
    char full[0x80];
    int pos;
    char *f = full;
    MC2Super *sb = &D_0048BD90[idx];
    char *p;
    int last;
    int r;

    r = func_002B8188(idx, path, f);
    if (r) return r;
    /* do/while(0) pins loop.c's return blocks; its LOOP_BEG note must follow the first call */
    do {
    last = 0;
    r = _GetEntryByPos(idx, &buf, sb->f3C, 0);
    if (r) return r;
    if (strlen(buf.name) >= 0x20) return 0x81019002;
    if (strcmp(buf.name, D_004AC1B0)) return 0x81019002;
    if (strcmp(f, D_004AC1C8) == 0) {
        *st = buf;
        return 0x81010011;
    }
    p = _strtok(f + 1, D_004AC1C8);
    for (;;) {
        String_Copy(name, p);
        p = _strtok(0, D_004AC1C8);
        if (p == 0) last = 1;
        dir = buf;
        r = _SearchEntry(idx, &buf, &pos, name, dir.f10, dir.f4);
        if (buf.mode & 0x2000) return 0x8101000D;
        if (last == 1) goto done;
        if (r) return r == 0x81010002 ? 0x81019FFF : r;
    }
done:
    if (r == 0) {
        if (st) *st = buf;
        if (y) *y = pos;
        if (x) *x = dir.f10;
        return 0x81010011;
    }
    if (r == 0x81010002) {
        *st = dir;
        return 0x81010002;
    }
    return r;
    } while (0);
}






