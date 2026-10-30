typedef struct Node {
    int x0;
    struct Node *next;
    char pad8[0x1C - 0x8];
    int t1C;
} Node;
typedef struct Obj {
    char pad0[0x48];
    int x48;
    char pad4C[4];
    int x50;
    char pad54[0x68 - 0x54];
    Node *end;
    Node *head;
    char pad70[0x98 - 0x70];
    int x98;
} Obj;
extern int GetCurrentTimeMs(void);
extern int UpdateIncomingPackages(Obj *);
extern int UpdatePlayers(Obj *);
extern int GetGrid(Obj *, int);
extern void GridUpdate(int);
extern unsigned int UpdateAudioInput(Obj *, int);
extern void UpdateVideo(Obj *);
extern unsigned int GetPlayerStatus(Node *);
extern void gVideoOut(Obj *, Node *);
extern void ResetPlayerStatus(Node *, unsigned int);
extern void gAudioOut(Obj *, Node *);
extern void SetPlayerStatus(Node *, unsigned int);
int UpdateAudio(Obj *o)
{
    int now = GetCurrentTimeMs();
    unsigned int r;
    Node *n;
    unsigned int fl;
    if (UpdateIncomingPackages(o) == 0 && UpdatePlayers(o) == 0 && o->x98 > 0) {
        int p = GetGrid(o, o->x98);
        if (p != 0)
            GridUpdate(p);
    }
    r = 0;
    if (o->x48 != 0)
        r = UpdateAudioInput(o, now);
    if (r <= 8000 && o->x50 != 0)
        UpdateVideo(o);
    if (o->x98 != 0 && GetGrid(o, o->x98) != 0) {
        n = o->head;
        if ((n = n->next) != 0 && n != o->end) {
    top:
            fl = GetPlayerStatus(n);
            if (fl & 0x40000000) {
                gVideoOut(o, n);
                ResetPlayerStatus(n, 0x40000000);
            }
            if (fl & 0x3000) {
                gAudioOut(o, n);
            } else if ((fl & 0x4000) && now - n->t1C > 1500) {
                ResetPlayerStatus(n, 0x4000);
                SetPlayerStatus(n, 0x2000);
            }
            if ((n = n->next) != 0 && n != o->end) goto top;
        }
    }
    return 0;
}
