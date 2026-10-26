#define F_(b, o, T) (*(T *)((char *)(b) + (o)))

extern void func_0010BD58(void *, const char *, ...);
extern void scePrintf(const char *);
extern int _nextHeader(void *);
extern int _sceMpegFlush(void *);
extern int _decodeOrSkip(void *, int, int);
extern char D_004986E8[];
extern char D_00498728[];
extern char D_00498768[];

int _getpic(char *mp)
{
    char *p;
    int ret;
    int code;

    ret = 0;
    code = 1;
    p = F_(mp, 0x40, char *);
    F_(p, 0x0, int) = 0;
    if (F_(p, 0xF0, int) & 0x3F) {
        func_0010BD58(p, D_004986E8, F_(p, 0xF0, int));
        return -1;
    }
    if (F_(p, 0x10A0, int)) {
        scePrintf(D_00498728);
        return -1;
    }
    F_(p, 0x838, int) = 0;
    do {
        if (ret != -1) {
            do {
                code = _nextHeader(p);
                if (code < 0)
                    return -1;
                if (code == 0)
                    break;
                if (F_(p, 0x18C, int) == F_(p, 0xEC, int))
                    break;
            } while (F_(p, 0x860, int) != 0);
        }
        switch (code) {
        case 0:
            _sceMpegFlush(mp);
            F_(p, 0x0, int) = 1;
            break;
        case 1:
            F_(p, 0xC0, int) = 0;
            F_(p, 0xBC, int) = 0;
            F_(p, 0xB8, int) = 0;
            ret = _decodeOrSkip(mp, 0, F_(p, 0xAC, int));
            F_(p, 0xB8, int)++;
            break;
        case 2:
            ret = _decodeOrSkip(mp, F_(p, 0xBC, int), F_(p, 0xB0, int));
            F_(p, 0xBC, int)++;
            break;
        case 3:
        case 4:
            ret = _decodeOrSkip(mp, F_(p, 0xC0, int), F_(p, 0xB4, int));
            F_(p, 0xC0, int)++;
            break;
        }
        if (F_(p, 0x10A0, int)) {
            scePrintf(D_00498768);
            return -1;
        }
        if (F_(p, 0x838, int))
            return 1;
    } while (F_(p, 0x0, int) == 0);
    return 1;
}


