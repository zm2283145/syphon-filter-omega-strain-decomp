extern int D_0048BD88;
extern int D_00506644;
extern int sceDbcSearchPortSpecific(void *);
extern int _sceMcCoreChangeSocketTypeDbc2Mc(int);
typedef struct { int x0; int x4; int a; int b; char pad[0x20]; } Q2B5000;
int sceMc2SearchSocket(int a, int b)
{
    Q2B5000 q;
    int id;
    if (D_0048BD88 == 0) return 0x81018001;
    if (D_00506644) return 0x81010010;
    q.a = a;
    q.b = b;
    id = sceDbcSearchPortSpecific(&q);
    if (id < 0) return 0x81018002;
    return _sceMcCoreChangeSocketTypeDbc2Mc(id);
}
