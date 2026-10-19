/*
 * lib/usbkb: 6 files, 00223478-00223B60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00223478 */
typedef struct { int n; int b; unsigned char data[1]; } KB223478;
extern unsigned char D_004F58C0[];
extern KB223478* D_004F5818;
int func_00223478(void)
{
    int i;
    KB223478* p = D_004F5818;
    unsigned char* s = D_004F58C0;
    p->n = s[0];
    p->b = s[1];
    for (i = 0; i < p->n; i++) {
        p->data[i] = s[i + 2];
    }
    return 0;
}
/* merge_units: end func_00223478 */

/* merge_units: begin func_002234D0 */
typedef struct { int led; int mkey; int len; unsigned short keycode[62]; } KbData;
typedef struct { int state; int cnt; int delay; int interval; unsigned short last; unsigned short buf[4]; int wr; int rd; int count; } KbRep;
typedef struct { int f0; int f4; int f8; int raw; KbRep rep; } KbEnt;
typedef struct { int f0; KbEnt* ents; KbData cur; int mode; int idx; KbData* out; } KbCtx;
extern KbCtx D_004F5780;
extern int func_00223B60(int i);
extern int func_00223B90(int i, unsigned short v);
extern int func_00223C00(int i, unsigned short* out);
extern int func_00223C68(int map, unsigned char a, unsigned char b, int count, unsigned short* src, unsigned short* dst);

int func_002234D0(void)
{
    unsigned char* raw = D_004F58C0;
    KbData* out = D_004F5780.out;
    KbEnt* e = &D_004F5780.ents[D_004F5780.idx];
    KbRep* q = &e->rep;
    KbData tmp;
    unsigned short buf[64];
    unsigned short key;
    int i, j, n, m, k;
    unsigned char* s;
    unsigned char* d;

    if (raw[1] == 0xFF) return -1;
    if (e->raw == 1) {
        out->led = raw[0];
        out->len = raw[1];
        out->mkey = raw[2];
        if (out->len) {
            n = 0;
            for (i = 0; i < out->len; i++) {
                if (raw[i + 4]) out->keycode[n++] = raw[i + 4];
            }
            out->len = n;
            if (n == 0) {
                out->keycode[0] = 0;
                out->len = 1;
            }
            func_00223C68(D_004F5780.idx, out->mkey, out->led, out->len, out->keycode, out->keycode);
        }
        return 0;
    }
    switch (q->state) {
    case 0:
        break;
    case 1:
        if (q->cnt >= q->delay) {
            q->cnt = 0;
            func_00223B60(D_004F5780.idx);
            if (q->delay >= 2) func_00223B90(D_004F5780.idx, 0);
            func_00223B90(D_004F5780.idx, q->last);
            if (q->interval >= 2) func_00223B90(D_004F5780.idx, 0);
            q->state = 2;
        }
        break;
    case 2:
        if (q->cnt >= q->interval) {
            q->cnt = 0;
            func_00223B90(D_004F5780.idx, q->last);
            if (q->interval >= 2) func_00223B90(D_004F5780.idx, 0);
        }
        break;
    }
    if (raw[1] == 0) {
        if (func_00223C00(D_004F5780.idx, &key) == 0) {
            out->len = 1;
            out->keycode[0] = key;
            out->led = D_004F5780.cur.led;
            out->mkey = D_004F5780.cur.mkey;
        } else {
            out->len = 0;
        }
        return 0;
    }
    if (raw[4] == 1) {
        q->state = 0;
        out->len = 0;
        return 0;
    }
    tmp.led = raw[0];
    tmp.len = raw[1];
    tmp.mkey = raw[2];
    n = 0;
    for (i = 0; i < tmp.len; i++) {
        if (raw[i + 4]) tmp.keycode[n++] = raw[i + 4];
    }
    tmp.len = n;
    func_00223B60(D_004F5780.idx);
    if (tmp.keycode[0] == 0 || tmp.mkey != D_004F5780.cur.mkey) {
        out->keycode[0] = 0;
        out->len = 1;
        q->last = 0;
        out->led = tmp.led;
        out->mkey = tmp.mkey;
        q->state = 0;
    } else {
        if (D_004F5780.cur.keycode[0]) {
            k = 0;
            for (i = 0; i < tmp.len; i++) {
                for (j = 0; j < D_004F5780.cur.len; j++) {
                    if (tmp.keycode[i] == D_004F5780.cur.keycode[j]) break;
                }
                if (j == D_004F5780.cur.len) out->keycode[k++] = tmp.keycode[i];
            }
            out->len = k;
        } else {
            for (i = 0; i < tmp.len; i++) out->keycode[i] = tmp.keycode[i];
            out->len = i;
        }
        out->led = tmp.led;
        out->mkey = tmp.mkey;
        func_00223C68(D_004F5780.idx, out->mkey, out->led, out->len, out->keycode, out->keycode);
        if (out->len > 0) {
            q->last = out->keycode[out->len - 1];
            if (q->delay > 0 && q->interval > 0) q->state = 1;
        } else {
            func_00223C68(D_004F5780.idx, tmp.mkey, tmp.led, tmp.len, tmp.keycode, buf);
            for (i = 0; i < tmp.len; i++) {
                if (buf[i] == q->last) break;
            }
            if (i == tmp.len) {
                q->state = 0;
                out->len = 1;
                out->keycode[0] = 0;
                out->led = tmp.led;
                out->mkey = tmp.mkey;
            }
        }
    }
    s = (unsigned char*)&tmp;
    d = (unsigned char*)&D_004F5780.cur;
    for (i = 0; i < sizeof(KbData); i++) *d++ = *s++;
    return 0;
}
/* merge_units: end func_002234D0 */

/* merge_units: begin func_00223A48 */
#if 0 /* merge_units */
extern unsigned char* D_004F5818;
#endif /* merge_units */
#define D_004F5818 (*(unsigned char **)&D_004F5818) /* merge_units */

int func_00223A48(void)
{
    unsigned char* s = D_004F58C0;
    unsigned char* d = D_004F5818;
    int i;
    if (s[6]) return -1;
    for (i = 6; i >= 0; i--) *d++ = *s++;
    return 0;
}
#undef D_004F5818 /* merge_units */
/* merge_units: end func_00223A48 */

/* merge_units: begin func_00223A98 */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F5881[];
extern char D_004F58C1[];

int func_00223A98(void) {
    int a0, v0, v1;

    v1 = *(unsigned char*)(char*)D_004F58C1;
    a0 = *(unsigned char*)(char*)D_004F5881;
    v0 = 0 + -1;
    v1 = v1 ^ a0;
    if (v1 == 0) v0 = 0;
    goto ret;
ret:
    return v0;
}

int func_00223AB8(void) {
    int a0, v0, v1;

    v1 = *(unsigned char*)(char*)D_004F58C1;
    a0 = *(unsigned char*)(char*)D_004F5881;
    v0 = 0 + -1;
    v1 = v1 ^ a0;
    if (v1 == 0) v0 = 0;
    goto ret;
ret:
    return v0;
}
/* merge_units: end func_00223A98 */

/* merge_units: begin func_00223AD8 */
typedef struct { int state; int cnt; int f8; int fc; } S223AD8;
typedef struct { int f0; int f4; int f8; int mode; S223AD8 s; char pad[0x18]; } E223AD8;
typedef struct { int count; E223AD8* tbl; } G223AD8;
#if 0 /* merge_units */
extern G223AD8 D_004F5780;
#endif /* merge_units */
#define D_004F5780 (*(G223AD8*)&D_004F5780) /* merge_units */

int func_00223AD8(void)
{
    int i;
    for (i = 0; i < D_004F5780.count; i++) {
        S223AD8* p = &D_004F5780.tbl[i].s;
        if (p->f8 > 0 && p->fc > 0 && p->state != 0 && p->state >= 0 && p->state < 3) p->cnt++;
    }
    __asm__ __volatile__("sync");
    __asm__ __volatile__("ei");
    return 0;
}
#undef D_004F5780 /* merge_units */
/* merge_units: end func_00223AD8 */

/* merge_units: begin func_00223B60 */
typedef struct { int f0; int f4; char pad[0x14]; int f1c; int f20; int f24; } Q223B60;
typedef struct { char pad[0x10]; Q223B60 q; } E223B60;
extern E223B60* D_004F5784;
int func_00223B60(int i)
{
    Q223B60* q = &D_004F5784[i].q;
    q->f24 = 0;
    q->f1c = 0;
    q->f20 = 0;
    q->f4 = 0;
    return 0;
}
/* merge_units: end func_00223B60 */
