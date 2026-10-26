extern int GetGrid(char *, int);
extern int IsSpeakDisallowedInGrid(int);
int GetSpeakAllowedGrid(char *o)
{
    int r = 0;
    int n = *(int *)(o + 0x98);
    if (n > 0) {
        r = GetGrid(o, n);
        if (r && *(int *)(o + 0x60) == 0) {
            if (IsSpeakDisallowedInGrid(r)) r = 0;
        }
    }
    return r;
}