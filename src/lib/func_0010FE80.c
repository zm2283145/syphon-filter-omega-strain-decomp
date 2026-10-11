typedef struct { char pad[0x1C]; char *x1C; int x20; } TblFE80;
extern char *func_0010FE50(TblFE80 *, int);

char *func_0010FE80(TblFE80 *t, int idx)
{
    if (idx < 0 || idx >= t->x20) return func_0010FE50(t, idx);
    return t->x1C + (idx << 6);
}