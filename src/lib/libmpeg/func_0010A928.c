extern void _sysbitGet(int, int);
extern int _sysbitNext(int, int);
int _system_header(int x)
{
    _sysbitGet(x, 0x38);
    _sysbitGet(x, 0x28);
    while (_sysbitNext(x, 1) == 1) _sysbitGet(x, 0x18);
    return 1;
}