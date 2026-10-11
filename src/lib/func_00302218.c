typedef struct { unsigned char ok; int f4; int f8; } ScfSem_218;
extern int func_00302518(ScfSem_218 *o);
int func_00302218(ScfSem_218 *o)
{
    int ret = 2;
    if (o == 0) return ret;
    if (o->ok != 1) return ret;
    ret = func_00302518(o);
    if (ret == 0) o->ok = 0;
    return ret;
}