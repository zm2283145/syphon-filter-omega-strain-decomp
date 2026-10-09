/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_00582550[];         /* 32-byte decoded key buffer */
extern int Transport_Send(int, int, int, int);

/* Sends a2 through the transport with the first two arguments swapped and -1 as the third. */
int func_00429200(int a0, int a1, int a2) {
    return Transport_Send(a1, a0, -1, a2);
}

/*
 * Copies 32 bytes into D_00582550, XOR-ing each with 0xB3. Kept as the
 * unrolled-by-8 form: a plain for loop picks different registers.
 */
void DecodeKey_XorB3(signed char* src) {
    int c, key;
    signed char* p;
    char* dst;
    int i, more;
    int cond;

    i = 0;
    dst = D_00582550;
    key = -77;
    do {
        p = src + i;
        c = p[0];
        i = i + 8;
        more = i < 32;
        c = c ^ key;
        dst[0] = c;
        c = p[1];
        c = c ^ key;
        dst[1] = c;
        c = p[2];
        c = c ^ key;
        dst[2] = c;
        c = p[3];
        c = c ^ key;
        dst[3] = c;
        c = p[4];
        c = c ^ key;
        dst[4] = c;
        c = p[5];
        c = c ^ key;
        dst[5] = c;
        c = p[6];
        c = c ^ key;
        dst[6] = c;
        c = p[7];
        c = c ^ key;
        dst[7] = c;
        cond = more != 0;
        dst = dst + 8;
    } while (cond);
}
