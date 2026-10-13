typedef struct ScfSock ScfSock;
typedef void (*ScfCb)(ScfSock *s, int ev, int a, int b, int user);
struct ScfSock {
    char pad0[0x45];
    unsigned char pending;
    char pad46[2];
    unsigned int idx;
    ScfCb cb;
    int user;
};
extern unsigned char D_00491324;
extern ScfSock *D_00529860[8];

/* Flushes pending notifications: fires each pending socket's callback with event -2. */
void func_0030B338(int a0, int abort, int a2, int a3, int t0, ScfSock *s)
{
    unsigned int i;

    if (s == 0) return;
    if (s->idx < 8) {
        D_00491324 = 0;
        for (i = 0; i < 8; i++) {
            if (D_00529860[i] != 0 && D_00529860[i]->pending != 0) {
                D_00529860[i]->pending = 0;
                if (abort == 0)
                    D_00529860[i]->cb(s, -2, 5, 0, D_00529860[i]->user);
                else
                    D_00529860[i]->cb(s, -2, 5, 15, D_00529860[i]->user);
            }
        }
    } else {
        s->pending = 0;
        if (abort == 0)
            s->cb(s, -2, 5, 0, s->user);
        else
            s->cb(s, -2, 5, 15, s->user);
    }
}
