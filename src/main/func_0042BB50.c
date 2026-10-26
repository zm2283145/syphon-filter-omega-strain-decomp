#pragma inline_depth(10)
#pragma opt_propagation off
#pragma opt_common_subs off
extern unsigned char D_00582630;
extern unsigned char D_00582640;
extern unsigned char D_00582650;
extern int D_00582668;
extern int D_00582670;
extern int D_00582678;
extern long* D_005825D8;
extern long* D_005825F8;
extern long* D_00582618;
extern long* D_00582628;
extern long* D_00582638;
extern long* D_00582648;
extern short D_005825DE;
extern short D_005825FE;
extern short D_0058261E;
extern int D_00542D48;
extern int D_00582578;
extern char* D_005825D0;
extern unsigned short D_005825D4;
int nciDecodeSase3200(int h, char** io);
void nciDecodeNeedsInputSase3200(int h, unsigned char* done);

/* inline-asm block copy (hand-written in the original) */
static inline void Copy_BB50(void* d0, void* s0, int n0)
{
    int n = n0;
    int t;
    int m;
    void* d = d0;
    void* s = s0;
    asm {
        .set noreorder
        blez n, done
        andi m, s, 0xF
        andi t, d, 0xF
        or m, m, t
        andi t, n, 0xF
        or m, m, t
        nop
        bgtz m, bytes
    quads:
        lq t, 0(s)
        addiu d, d, 0x10
        addi n, n, -0x10
        addiu s, s, 0x10
        bgtz n, quads
        sq t, -0x10(d)
        b done
        nop
    bytes:
        lb t, 0(s)
        addiu d, d, 1
        addi n, n, -1
        addiu s, s, 1
        bgtz n, bytes
        sb t, -1(d)
    done:
        .set reorder
    }
}

/* inline-asm doubleword move (hand-written in the original) */
static inline void Move_BB50(void* d0, void* s0, int n0)
{
    int n = n0;
    int t;
    void* d = d0;
    void* s = s0;
    asm {
        .set noreorder
    loop:
        ld t, 0(s)
        addiu d, d, 8
        addi n, n, -1
        addiu s, s, 8
        bgtz n, loop
        sd t, -8(d)
        .set reorder
    }
}

static inline void Pop_BB50(unsigned char* cnt, int* act, long** out, long** q)
{
    if (*cnt >= 8 || *act == 1) {
        if (*cnt <= 0) {
            *act = 0;
            **out = 0;
        } else {
            *act = 1;
            {
                long* o;
                long v;
                v = **q;
                o = *out;
                *o = v;
            }
            (*cnt)--;
            Move_BB50(*q, *q + 1, 0x4F);
        }
    } else {
        **out = 0;
    }
}
int cNellyMoser_nmsMultiDecode(char* buf)
{
    int total = 0;
    unsigned char done;
    unsigned short len;
    if (D_00582630 <= 16 && !D_00582668 && D_00582640 <= 16 && !D_00582670 &&
        D_00582650 <= 16 && !D_00582678)
        return 0;
    Pop_BB50(&D_00582630, &D_00582668, &D_005825D8, &D_00582628);
    Pop_BB50(&D_00582640, &D_00582670, &D_005825F8, &D_00582638);
    Pop_BB50(&D_00582650, &D_00582678, &D_00582618, &D_00582648);
    if (!D_00582668 && !D_00582670 && !D_00582678)
        return 0;
    D_005825DE = 0;
    D_005825FE = 0;
    D_00542D48 = -1;
    D_0058261E = 0;
    for (;;) {
        if ((unsigned short)nciDecodeSase3200(D_00582578, &D_005825D0))
            return 0;
        len = D_005825D4;
        if (len) {
            Copy_BB50(buf + total, D_005825D0, len * 2);
            total += D_005825D4 * 2;
        }
        nciDecodeNeedsInputSase3200(D_00582578, &done);
        if (done)
            return total;
    }
}






