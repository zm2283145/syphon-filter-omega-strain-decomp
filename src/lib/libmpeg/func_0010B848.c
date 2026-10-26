#define F_(b, o, T) (*(T *)((char *)(b) + (o)))

extern int _decPicture(void *);
extern void _outputFrame(void *, int, int);
extern int _updateRefImage(void *, int);
extern int _dispatchMpegCbNodata(void *);

static inline int dec(char *p)
{
    int t = _updateRefImage(p, 0);
    int r = 0;
    if (t)
        r = _decPicture(p) != 0;
    return r;
}

int _decodeOrSkipFrame(char *mp, int a, int b)
{
    char *p;
    int ret;
    int last;

    last = 0;
    p = F_(mp, 0x40, char *);
    if (b == -1 || a < b) {
        if (F_(p, 0x8, int) == 0) {
            F_(mp, 0x8, int) = 0;
            F_(p, 0x8, int) = 1;
        }
        ret = dec(p);
    } else {
        last = 1;
        ret = _updateRefImage(p, 0);
        _dispatchMpegCbNodata(mp);
    }
    if (F_(p, 0x10A0, int))
        return 0;
    _outputFrame(p, F_(p, 0x130, int), F_(p, 0x4, int));
    if (F_(p, 0x18C, int) != 3 && last == 0)
        F_(p, 0x138, int) = F_(p, 0x138, int) == 0;
    F_(mp, 0x8, int) = F_(p, 0x130, int) - F_(p, 0xC4, int);
    if (F_(p, 0x138, int) == 0) {
        F_(p, 0x130, int)++;
        F_(p, 0x4, int)++;
    }
    return ret;
}

