typedef struct { int buf[0x100]; int buf2[0x100]; int f800; int f804; char cwd[0x80]; int f888; int f88C; int f890; int f894; } MC2Cache;
typedef struct { char magic[0x1C]; char ver[0x14]; int f30; int f34; int f38; int f3C; char pad[0x130]; int f170; char pad2[0x10]; } MC2Super;
typedef struct { unsigned short mode; char pad[0x3E]; char name[0x20]; char rest[0x1A0]; } MC2Dirent;
typedef struct { int type; int f4; int free; } MC2Info;
extern MC2Cache D_00512C88[];
extern MC2Super D_0048BD90[];
extern char D_004AC1B0[];
extern char D_004AC1B8[];
extern char D_004AC1D0[];
extern const char D_004AC1C8[];
extern int strcmp(const char *, const char *);
extern int Libc_Strncmp(const char *, const char *, int);
extern int func_002BC788(int);
extern int func_002BAA38(int);
extern int func_002BAA20(int, int *);
extern int _sceMcpReadSysInfo(int);
extern void _reset_problem_patch(int, MC2Super *);
extern void _sceMcCoreWriteBack(int);
extern int func_002BB358(int, int);
extern int _GetEntryByPos(int, MC2Dirent *, int, int);
extern int _sceMcFatGetFreeClustSize(int, int *);
int _sceMcFatGetInfo(int idx, MC2Info *info)
{
    int tmp[2];
    MC2Dirent ent;
    int err;
    MC2Super *sb = &D_0048BD90[idx];
    int t;
    int cl, cnt, i, lim, n;

    if (!func_002BC788(idx)) return 0x81010013;
    if (info) {
        info->f4 = 0;
        info->type = 0;
        info->free = 0;
    }
    t = func_002BAA38(idx);
    if (t == 0) return 0x8101006F;
    if (t == 2) D_00512C88[idx].f888 = 1;
    if (D_00512C88[idx].f888) {
        if (!func_002BAA20(idx, tmp)) return 0x8101006F;
        if (tmp[0] == 0) return 0x8101006F;
        D_00512C88[idx].f894 = 0;
        D_00512C88[idx].f800 = -1;
        D_00512C88[idx].f804 = -1;
        D_00512C88[idx].f890 = 0;
        __builtin_memcpy(D_00512C88[idx].cwd, D_004AC1C8, 2);
        if (!_sceMcpReadSysInfo(idx)) return 0x8101006F;
        if (info) info->type = 2;
        if (Libc_Strncmp(sb->magic, D_004AC1D0, 0x1B)) {
            if (info) info->f4 = 0;
            return 0x8101002F;
        }
        n = (sb->ver[0] - '0') * 10 + (sb->ver[2] - '0');
        if (n < 11) return 0x81010086;
        _reset_problem_patch(idx, sb);
        _sceMcCoreWriteBack(idx);
        cl = sb->f34;
        lim = sb->f30 / 1000 * 1000 + 1;
        cnt = 0;
        for (i = 0; i < sb->f38; i++) {
            if (cnt == lim) sb->f170 = cl - sb->f34;
            if (func_002BB358(idx, cl++) == 0) cnt++;
        }
        err = _GetEntryByPos(idx, &ent, sb->f3C, 0);
        if (err) return err;
        if (!(ent.mode & 0x8000)) return 0x8101002F;
        if (strcmp(ent.name, D_004AC1B0)) return 0x8101002F;
        err = _GetEntryByPos(idx, &ent, sb->f3C, 1);
        if (err) return err;
        if (!(ent.mode & 0x8000)) return 0x8101002F;
        if (strcmp(ent.name, D_004AC1B8)) return 0x8101002F;
        D_00512C88[idx].f88C = 1;
    }
    if (!D_00512C88[idx].f88C) return 0x8101002F;
    if (info) {
        n = _sceMcFatGetFreeClustSize(idx, &err);
        if (err) return err;
        info->f4 = D_00512C88[idx].f88C;
        info->free = n;
        info->type = 2;
    }
    if (D_00512C88[idx].f888) {
        D_00512C88[idx].f888 = 0;
        return 0x81019003;
    }
    return 0;
}




