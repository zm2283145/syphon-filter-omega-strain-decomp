typedef struct { signed char bits[0x24]; int lo; int hi; } Set;
typedef struct { char p[0x400]; int self; char p2[0x48]; int state; } Conn;
extern int func_002E51B8(unsigned int, Conn **);
extern int func_002DB188(int *, unsigned int, int);
extern int Net_SendTyped(char, int, int, unsigned int, unsigned int, int, void *);

int func_002DE5E8(signed char type, unsigned int idx, unsigned int chan, unsigned int sub, int len, void *data, Set *s)
{
    Conn *conn = 0;
    int ok = 0;
    int r;
    int i;
    if (chan >= 6) return 0x17;
    if (sub >= 0x100) return 0x17;
    if (len <= 0) return 0x17;
    if (data == 0) return 0x17;
    if (s == 0) return 0x17;
    r = func_002E51B8(idx, &conn);
    if (r) return r;
    if (conn == 0) return r;
    if (conn->state == 4) return 0xF;
    if (s->hi >= 0) for (i = s->lo; i <= s->hi; i++) {
        if (i == conn->self) continue;
        func_002DB188(&ok, idx, i);
        if (ok && ((s->bits[i >> 3] >> (i & 7)) & 1)) {
            if (Net_SendTyped(type, idx, i, chan, sub, len, data)) r = 0xD;
        }
    }
    return r;
}

/* score: 3 insn diff (sra v0/v1 scheduling in bit test) */

