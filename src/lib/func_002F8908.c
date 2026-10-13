typedef struct { char b[64]; } B64;
extern B64 D_00529640[];
extern B64 D_005296C0[];
extern B64 D_00529740[];
extern int func_002F7CE8(B64 *);
extern void *memset(void *, int, unsigned int);
/* Copies the 64-byte key selected by id into out; -3 (and a zeroed out) if the key is unset. */
int func_002F8908(int id, B64 *out)
{
    B64 *k;
    register int r asm("$17");
    register B64 *kk asm("$18");

    if (id == (int)0x80000000) { r = 0; k = D_00529640; }
    else if (id == -1) { r = 0; k = D_00529740; }
    else { r = 0; k = D_005296C0; }
    kk = k; if (func_002F7CE8(kk) != 0) r = -3;
    if (out != 0) {
        *out = *kk;
        if (r != 0) memset(out, 0, 64);
    }
    return r;
}



