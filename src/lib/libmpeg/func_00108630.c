extern int _nextBit(void *, int);
extern void _flushBuf(void *, int);

void _extrainfo(void *m)
{
    while (_nextBit(m, 1)) _flushBuf(m, 8);
}