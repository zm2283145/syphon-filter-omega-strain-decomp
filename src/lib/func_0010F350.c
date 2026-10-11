extern int func_0010ED58(const char* fmt, char* ap);
int func_0010F350(const char* fmt, ...)
{
    char* ap;
    ap = (char*)__builtin_next_arg(fmt) - (__builtin_args_info(0) < 8 ? (8 - __builtin_args_info(0)) * 8 : 0);
    return func_0010ED58(fmt, ap);
}