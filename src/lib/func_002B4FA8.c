extern int D_0048BD88;
extern int D_00506644;
extern int _sceMcCoreDeleteSocket(int);
int sceMc2DeleteSocket(int a)
{
    if (D_0048BD88 == 0) return 0x81018001;
    if (D_00506644) return 0x81010010;
    return _sceMcCoreDeleteSocket(a) ? 0 : 0x81018002;
}