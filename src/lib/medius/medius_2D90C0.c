/*
 * lib/medius: 3 files, 002D90C0-002D9190
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D90C0 */
extern void QuitChannel(char *, int);
extern void GridQuit(int);
void Quit(char *o)
{
    int n = *(int *)(o + 0x98);
    if (n > 0) QuitChannel(o, n);
    if (*(int *)(o + 0x64)) GridQuit(*(int *)(o + 0x64));
    *(int *)(o + 0x70) &= ~2;
}
/* merge_units: end func_002D90C0 */

/* merge_units: begin func_002D9118 */
extern int AudioRecvFrom(int, char *, int, int *, int *);
extern int ProcessPackage(int, int, int, char *, int);
int UpdateIncomingPackages(int a)
{
    char buf[0x500];
    int len;
    int x = 0;
    int r = 0;
    int n;
    for (;;) {
        n = AudioRecvFrom(a, buf, 0x500, &len, &x);
        if (n < 0) { r = -1; break; }
        if (n == 0) break;
        if (ProcessPackage(a, len, x, buf, n)) { r = -1; break; }
    }
    return r;
}
/* merge_units: end func_002D9118 */

/* merge_units: begin func_002D9190 */
typedef struct S S;
struct S {
    char p[0x48];
    int (*read)(S *, int *, char *, int);
    char p4c[0x58 - 0x4C];
    int f58;
    int f5c;
    int f60;
    char p64[0x90 - 0x64];
    int f90;
};
extern int StreamInput(S *, int, char *, int);
int UpdateAudioInput(S *s, int now)
{
    char buf[0x800];
    int from[1];
    int total = 0;
    int n;
    from[0] = 0;
    do {
        n = s->read(s, from, buf, 0x800);
        total += n;
        if (n > 0) {
            StreamInput(s, from[0], buf, n);
            s->f58 = now;
        } else if (total == 0 && s->f60) {
            StreamInput(s, from[0], buf, -1);
        }
        if (n < 0x800 && (n <= 0 || from[0] != 0x3F)) break;
    } while (n > 0);
    if (total == 0 && s->f60 && now - s->f58 >= 0x5DD) StreamInput(s, s->f90, buf, 0);
    return total;
}
/* merge_units: end func_002D9190 */
