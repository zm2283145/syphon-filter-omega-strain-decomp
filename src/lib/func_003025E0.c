typedef struct { int f0; int f4; int f8; int sema; } ScfObj_5E0;
extern int SignalSema(int s);
int func_003025E0(ScfObj_5E0 *o)
{
    int ret = 2;
    if (o == 0) return ret;
    return SignalSema(o->sema) == -1;
}