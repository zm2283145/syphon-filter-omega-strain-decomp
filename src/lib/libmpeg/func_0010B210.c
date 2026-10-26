typedef struct { char pad[0x40]; int h; } XB210;
extern void _sendDataToIPU(int h, int a, int n);
int sceMpegAddBs(XB210* p, int a, int n)
{
    _sendDataToIPU(p->h, a, ((n + 0x13) / 16) * 16);
    return 1;
}
