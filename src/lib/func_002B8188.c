typedef struct { int x; char pad[0x894]; } E2B8188;
extern E2B8188 D_00513514[];
extern int func_002BC788(void);
extern int _make_path(int, char *, char *);
extern int isCorrFname(char *);
extern int isCorrNameSize(char *);
extern int func_002BAA50(int);
int func_002B8188(int idx, char *path, char *out)
{
    if (!func_002BC788()) return 0x81010013;
    if (D_00513514[idx].x == 0) return 0x8101006F;
    if (!_make_path(idx, path, out)) return 0x81010016;
    if (!isCorrFname(out)) return 0x81010016;
    if (!isCorrNameSize(out)) return 0x8101005B;
    return func_002BAA50(idx) ? 0 : 0x8101006F;
}
