#define F_(b, o, T) (*(T *)((char *)(b) + (o)))

extern int _decPicture(void *);
extern void _outputFrame(void *, int, int);
extern int _updateRefImage(void *, int);
extern int _nextHeader(void *);
extern int _dispatchMpegCbNodata(void *);
extern int _sceMpegFlush(void *);

int _decodeOrSkipField(char *mp, int a, int b)
{
    char *p;
    int ret;
    int more;
    int ok;
    int x;

    more = 0;
    p = F_(mp, 0x40, char *);
    F_(p, 0x138, int) = 0;
    if (b == -1 || a < b)
        more = 1;
    if (F_(p, 0x8, int) == 0) {
        F_(mp, 0x8, int) = 0;
        F_(p, 0x8, int) = 1;
    }
    if (_updateRefImage(p, 0) && more)
        _decPicture(p);
    if (F_(p, 0x10A0, int))
        return 0;
    F_(p, 0x138, int) = 1;
    if (_nextHeader(p) == 0) {
        _sceMpegFlush(mp);
        F_(p, 0x0, int) = 1;
        return 0;
    }
    x = 2;
    if (F_(p, 0xEC, int) != 1)
        x = 1;
    if (F_(p, 0x18C, int) != x)
        return -1;
    ok = 0;
    if (_updateRefImage(p, 1))
        ok = 1;
    ret = 0;
    if (ok && more)
        {
        if (_decPicture(p))
            ret = 1;
    }
    if (F_(p, 0x10A0, int))
        return 0;
    _outputFrame(p, F_(p, 0x130, int), F_(p, 0x4, int));
    F_(p, 0x138, int) = 0;
    F_(mp, 0x8, int) = F_(p, 0x130, int) - F_(p, 0xC4, int);
    F_(p, 0x130, int)++;
    F_(p, 0x4, int)++;
    if (!more)
        _dispatchMpegCbNodata(mp);
    return ret;
}


