typedef struct { int status; int f4; int f8; int fC; int f10; int f14; int f18; int pad[5]; } ScfThStat;
extern int ReferThreadStatus(int id, ScfThStat *st);
int func_00305E10(int *out)
{
    ScfThStat st;
    int cnt = 0;
    int i;
    int ret = 2;
    if (out == 0) return ret;
    *out = 0;
    for (i = 0; i < 256; i++) {
        if (ReferThreadStatus(i, &st) == -1) continue;
        if (st.status != 0) cnt++;
    }
    *out = cnt;
    return 0;
}
