extern void _dispatchMpegCallback(int a, int* r);
int _dispatchMpegCbNodata(int a)
{
    int r[8];
    r[0] = 1;
    _dispatchMpegCallback(a, r);
    return 1;
}