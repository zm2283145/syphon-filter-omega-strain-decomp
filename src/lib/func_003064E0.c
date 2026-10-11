typedef struct { int sec; int usec; } ScfTime;
extern int func_003060D8(ScfTime *tv);
extern int func_003062A8(ScfTime *a, ScfTime *b, ScfTime *out);
int func_003064E0(ScfTime *in, ScfTime *out)
{
    ScfTime tv;
    int ret = 2;
    if (in == 0) return ret;
    if (out == 0) return ret;
    ret = func_003060D8(&tv);
    if (ret != 0) return ret;
    return func_003062A8(in, &tv, out);
}