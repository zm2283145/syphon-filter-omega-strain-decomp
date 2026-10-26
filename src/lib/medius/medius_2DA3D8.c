extern void QuitChannel(char *, int);
extern char *GetGrid(char *, int);
extern void GridSetPackHeader(int, char *, int, int);
extern int GridSendPackage(int, int, char *, unsigned short *, int);
extern char *GetPlayerFromGroup(int, int);
extern void SetPlayerCurChannel(char *, int);
extern void GridAddPlayer(char *, char *);
extern void GridConnectAll(char *);
int JoinChannel(char *s, int id)
{
    char buf[16];
    unsigned short v;
    int r = 0;
    char *n, *c;
    if (*(int *)(s + 0x98) > 0 && *(int *)(s + 0x98) != id && (*(int *)(s + 0x70) & 4))
        QuitChannel(s, *(int *)(s + 0x98));
    if (id > 0) {
    n = GetGrid(s, id);
    v = id;
    GridSetPackHeader(*(int *)(s + 0x64), buf, 9, 2);
    r = GridSendPackage(*(int *)(s + 0x64), *(int *)(s + 0x78), buf, &v, 2);
    if (r == 0) {
        c = GetPlayerFromGroup(*(int *)(s + 0x6C), *(int *)(s + 0x78));
        *(int *)(s + 0x98) = id;
        SetPlayerCurChannel(c, id);
        if (n) GridAddPlayer(n, c);
    }
    GridConnectAll(n);
    }
    return r;
}
