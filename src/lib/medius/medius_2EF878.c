extern int GetCurChannel(int);
extern char *GridGetConnection(char *, int);
extern void InvalidateConnection(char *);
extern void GridSendRedundancyMessage(char *);
extern int GridInviteConnect(char *);
extern void GridRemoveAllRedundancy(char *, int);
extern void RemoveRefFromSet(char *, int);
void GridRemovePlayer(char *s, int b)
{
    char *n;
    if (s == 0) return;
    if (GetCurChannel(*(int *)(s + 8)) == *(int *)(s + 0xC)) {
        n = GridGetConnection(s, b);
        if (n) {
            InvalidateConnection(n);
            if (*(int *)(s + 0x58)) {
                GridSendRedundancyMessage(s);
                GridInviteConnect(s);
                GridRemoveAllRedundancy(s, b);
            }
        }
    }
    RemoveRefFromSet(s + 0x50, b);
}
