/* Packet buffer: wraps if full, writes two zero dwords at the cursor and returns it (minus 8 when flag is set). */
typedef struct { char p0[8]; unsigned int end; char pC[4]; unsigned int cur; int f14; int f18; char f1C; } B375BA0;
typedef struct { char p0[0xC]; int base; } C375BA0;
typedef struct { B375BA0 *buf[0x33]; C375BA0 *cfg[3]; int cursel; } A375BA0;
static inline void Put375BA0(B375BA0* b, unsigned long long v) { unsigned long long* p = (unsigned long long*)b->cur; b->cur += 8; *p = v; }
int cDmaMan_BeginChain_eDmaChannel_eDmaMode_int_bool(A375BA0 *self, unsigned char i, char id, int addr, int flag) {
    B375BA0 *b = self->buf[i];
    if (b->cur >= b->end) {
        self->cursel = i;
        b->cur = self->cfg[i]->base;
    }
    b->f18 = addr;
    b->f1C = id;
    b->f14 = b->cur;
    Put375BA0(b, 0);
    Put375BA0(b, 0);
    return flag ? b->cur - 8 : b->cur;
}
