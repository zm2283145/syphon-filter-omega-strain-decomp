typedef struct { int a; long b; long c; } Pic8130;
extern void _nextStartCode(void *);
extern unsigned int _nextBit(void *, int);
extern void _sequenceHeader(void *);
extern void _groupOfPicturesHeader(void *);
extern void _pictureHeader(void *);
extern void _dispatchMpegCallback(int, Pic8130 *);

int _nextHeader(char *m)
{
    Pic8130 s;
    for (;;) {
        if (*(int *)(m + 0x10A0)) return -1;
        _nextStartCode(m);
        switch (_nextBit(m, 32)) {
        case 0x1B3:
            _sequenceHeader(m);
            break;
        case 0x1B8:
            _groupOfPicturesHeader(m);
            break;
        case 0x100:
            _pictureHeader(m);
            s.a = 5;
            s.b = -1;
            s.c = -1;
            _dispatchMpegCallback(*(int *)(m + 0x870), &s);
            *(long *)(m + 0x848) = s.c;
            *(long *)(m + 0x840) = s.b;
            return *(int *)(m + 0x168);
        case 0x1B7:
            return 0;
        }
    }
}