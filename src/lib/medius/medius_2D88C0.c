/*
 * lib/medius: 4 files, 002D88C0-002D8A98
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002D88C0 */
typedef struct { int x; } A;
typedef struct { char p[0x18]; int f18; char p2[0x848 - 0x1C]; int f848; } B;
extern unsigned int GetPlayerStatus(B *);
extern int GetSequenceData(int, int *, char *, int);
extern int StreamOutput(A *, B *, int, char *, int);
extern int GetResourceManager(A *);
extern int ReleaseSequencer(int, int);
extern int SetPlayerStatus(B *, int);
extern int ResetPlayerStatus(B *, int);
int gAudioOut(A *a, B *b)
{
    char buf[0x800];
    int from[1];
    int total = 0;
    int n;
    unsigned int flags = GetPlayerStatus(b);
    if (flags & 0x2000) {
        int sum = 0;
        from[0] = 0;
        do {
            n = GetSequenceData(b->f848, from, buf, 0x800);
            sum += n;
            if (sum == 0 || n != 0) total += StreamOutput(a, b, from[0], buf, n);
        } while (n != 0);
        if (!(flags & 0x4000)) {
            ReleaseSequencer(GetResourceManager(a), b->f848);
            b->f848 = 0;
            SetPlayerStatus(b, 0x1000);
        }
        ResetPlayerStatus(b, 0x2000);
    } else if (flags & 0x1000) StreamOutput(a, b, b->f18, buf, 0);
    return total;
}
/* merge_units: end func_002D88C0 */

/* merge_units: begin func_002D89E0 */
extern int gVideoIn(int, char *, int);
extern void VideoInput(int, char *, int);
void UpdateVideo(int a)
{
    char buf[0x7E00];
    int n = gVideoIn(a, buf, 0x7E00);
    if (n > 0) VideoInput(a, buf, n);
}
/* merge_units: end func_002D89E0 */

/* merge_units: begin func_002D8A28 */
typedef struct { char p0[0x74]; int x74; char p78[0x90 - 0x78]; int x90; int x94; char p98[0xBC - 0x98]; int xBC; char pC0[0xD4 - 0xC0]; int xD4; } T2D8A28;
extern void rt_memory_allocate_init_zero(void *, unsigned long);
extern void *memset(void *, int, unsigned int);
T2D8A28 *CreateAudio(void)
{
    T2D8A28 *p = 0;
    rt_memory_allocate_init_zero(&p, sizeof(T2D8A28));
    if (p != 0) {
        memset(p, 0, sizeof(T2D8A28));
        p->x90 = 0;
        p->x94 = 0;
        p->xBC = 0;
        p->xD4 = 0;
        p->x74 = 0;
    }
    return p;
}
/* merge_units: end func_002D8A28 */

/* merge_units: begin func_002D8A98 */
extern void ReleaseCodec(int, int);
extern void CleanupAudio(char *);
void DestroyAudio(char *o)
{
    int v = *(int *)(o + 0x60);
    if (v) {
        ReleaseCodec(*(int *)(o + 0x5C), v);
        *(int *)(o + 0x60) = 0;
        *(int *)(o + 0x90) = 0;
    }
    CleanupAudio(o);
}
/* merge_units: end func_002D8A98 */
