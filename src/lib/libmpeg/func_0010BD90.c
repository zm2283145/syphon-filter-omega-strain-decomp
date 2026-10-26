extern int _dispatchMpegCallback(void *o, int *id);
extern int Mpeg_PrintError(const char *msg);
int func_0010BD90(char *o, const char *msg)
{
    void *t = *(void **)(o + 0x870);
    if (t != 0 && o != 0 && *(int *)(o + 0xC) != 0) {
        int cb[2];
        cb[1] = (int)msg;
        cb[0] = 0;
        return _dispatchMpegCallback(t, cb);
    }
    return Mpeg_PrintError(msg);
}
