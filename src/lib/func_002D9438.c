typedef struct Node {
    int x0;
    struct Node *next;
    int x8;
    int flag;
    unsigned int time;
    unsigned int count;
    char pad18[0x34 - 0x18];
    int id;
} Node;
typedef struct Obj {
    char pad0[0x68];
    Node *end;
    Node *head;
    unsigned int flags;
} Obj;
extern unsigned int GetCurrentTimeMs(void);
extern void AudioSendPingMessage(Obj *, int);
int UpdatePlayers(Obj *o)
{
    Node *n = o->head;
    int b = 0;
    int a = 0;
    unsigned int now = GetCurrentTimeMs();
    for (n = n->next; n != 0 && n != o->end; n = n->next) {
        int f = n->flag;
        unsigned int d;
        if (!f)
            a = 1;
        else
            b = 1;
        d = now - n->time;
        if (f && d < 1500)
            continue;
        if (!f && d < 200)
            continue;
        if (f && n->count < 30) {
            AudioSendPingMessage(o, n->id);
            n->time = now;
            n->count++;
        } else if (f || n->count < 100) {
            AudioSendPingMessage(o, n->id);
            n->time = now;
            n->count++;
        } else {
            AudioSendPingMessage(o, n->id);
            n->time = now;
            n->count++;
        }
    }
    if (!(o->flags & 2) && b && !a)
        o->flags |= 2;
    return 0;
}
