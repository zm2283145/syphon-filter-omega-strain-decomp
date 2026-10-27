/*
 * lib/medius: 22 files, 002E9350-002EA448
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002E9350 */
extern int sprintf(char* buf, const char* fmt, ...);
extern char* strstr(const char* s, const char* sub);
extern int atoi(const char* s);

int NetGetBuildTimeStamp(char* out)
{
    char months[] = "JanFebMarAprMayJunJulAugSepOctNovDec\0";
    char buf[16];
    const char* date;
    const char* time;
    int m;

    if (out == 0)
        return 0x17;
    date = "Mar  8 2004";
    time = "12:08:45";
    sprintf(buf, "%.3s", date);
    m = (strstr(months, buf) - months) / 3 + 1;
    sprintf(out, "Time of build: %.2d.%.2d.%.4s.%.2s.%.2s.%.2s", m, atoi(date + 4), date + 7, time, time + 3, time + 6);
    return 0;
}
/* merge_units: end func_002E9350 */

/* merge_units: begin func_002E9480 */
extern void *memset(void *, int, unsigned int);
extern int KM_GetSoftwareID(void);
int NetSetDefaultInitializeParams(int *p)
{
    int v;
    if (p == 0) return 0x17;
    memset(p, 0, 0x1C);
    v = KM_GetSoftwareID();
    p[0] = 1;
    p[3] = 0xE4A;
    p[6] = 0;
    p[2] = 0;
    p[5] = 0;
    p[1] = v;
    return 0;
}
/* merge_units: end func_002E9480 */

/* merge_units: begin func_002E94E0 */
typedef struct { int f0; int f4; } Res;
extern unsigned char D_0048C4D7, D_0048C4DC;
extern unsigned int D_0048C4D8;
extern char D_005253F0[];
extern int rt_mutex_create(char *);
extern int rt_mutex_destroy(char *);
extern int rt_mutex_lock(char *, int);
extern int rt_mutex_unlock(char *, int);
extern int NetIInitialize(int *, Res *);

int NetInitialize(int *o, Res *res)
{
    int r;
    int v;

    if (res == 0) return 0x17;
    res->f4 = 0x12;
    res->f0 = 1;
    if (o == 0) {
        res->f4 = 0x17;
        return 0x17;
    }
    v = *o;
    if (v != 1) {
        res->f4 = 0x26;
        return 0x17;
    }
    if (D_0048C4D8 != 0) {
        D_0048C4D8++;
        res->f4 = 0;
        return 0;
    }
    if (D_0048C4DC == v || rt_mutex_create(D_005253F0) != 0) {
        res->f4 = 0x2B;
        return 0x2B;
    }
    D_0048C4DC = v;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIInitialize(o, res);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    if (r) {
        rt_mutex_destroy(D_005253F0);
        D_0048C4DC = 0;
        D_0048C4D7 = 0;
        return r;
    }
    D_0048C4D8 = v;
    D_0048C4D7 = v;
    return 0;
}
/* merge_units: end func_002E94E0 */

/* merge_units: begin func_002E9648 */
#if 0 /* merge_units */
extern int rt_mutex_lock(void *, int);
#endif /* merge_units */
#define rt_mutex_lock(a0, a1) (rt_mutex_lock((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int rt_mutex_unlock(void *, int);
#endif /* merge_units */
#define rt_mutex_unlock(a0, a1) (rt_mutex_unlock((char *)(a0), (a1))) /* merge_units */

extern int NetIClose(void);
#if 0 /* merge_units */
extern int rt_mutex_destroy(void *);
#endif /* merge_units */
#define rt_mutex_destroy(a0) (rt_mutex_destroy((char *)(a0))) /* merge_units */

int NetClose(void)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4D8 == 0) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (D_0048C4D8 >= 2) {
        D_0048C4D8--;
        return 0;
    }
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIClose();
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    if (r == 0) {
        if (rt_mutex_destroy(D_005253F0)) return 0x2B;
        D_0048C4DC = 0;
        D_0048C4D7 = 0;
        D_0048C4D8 = 0;
    }
    return r;
}
#undef rt_mutex_lock /* merge_units */
#undef rt_mutex_unlock /* merge_units */
#undef rt_mutex_destroy /* merge_units */
/* merge_units: end func_002E9648 */

/* merge_units: begin func_002E9740 */
#if 0 /* merge_units */
extern int rt_mutex_lock(void *, int);
#endif /* merge_units */
#define rt_mutex_lock(a0, a1) (rt_mutex_lock((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int rt_mutex_unlock(void *, int);
#endif /* merge_units */
#define rt_mutex_unlock(a0, a1) (rt_mutex_unlock((char *)(a0), (a1))) /* merge_units */

extern int NetIGetAverageDelayToClient(void *, void *);
int NetGetAverageDelayToClient(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIGetAverageDelayToClient(a, b);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
#undef rt_mutex_lock /* merge_units */
#undef rt_mutex_unlock /* merge_units */
/* merge_units: end func_002E9740 */

/* merge_units: begin func_002E97E8 */
#if 0 /* merge_units */
extern int rt_mutex_lock(void *, int);
#endif /* merge_units */
#define rt_mutex_lock(a0, a1) (rt_mutex_lock((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int rt_mutex_unlock(void *, int);
#endif /* merge_units */
#define rt_mutex_unlock(a0, a1) (rt_mutex_unlock((char *)(a0), (a1))) /* merge_units */

extern int NetIGetBufferStatus(void *, void *, void *, void *, void *);
int NetGetBufferStatus(void *a, void *b, void *c, void *d, void *e)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIGetBufferStatus(a, b, c, d, e);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
#undef rt_mutex_lock /* merge_units */
#undef rt_mutex_unlock /* merge_units */
/* merge_units: end func_002E97E8 */

/* merge_units: begin func_002E98C0 */
#if 0 /* merge_units */
extern int rt_mutex_lock(void *, int);
#endif /* merge_units */
#define rt_mutex_lock(a0, a1) (rt_mutex_lock((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int rt_mutex_unlock(void *, int);
#endif /* merge_units */
#define rt_mutex_unlock(a0, a1) (rt_mutex_unlock((char *)(a0), (a1))) /* merge_units */

extern int NetISetSendAggregationInterval(void *, void *, void *);
int NetSetSendAggregationInterval(void *a, void *b, void *c)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetISetSendAggregationInterval(a, b, c);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
#undef rt_mutex_lock /* merge_units */
#undef rt_mutex_unlock /* merge_units */
/* merge_units: end func_002E98C0 */

/* merge_units: begin func_002E9978 */
#if 0 /* merge_units */
extern int rt_mutex_lock(void *, int);
#endif /* merge_units */
#define rt_mutex_lock(a0, a1) (rt_mutex_lock((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int rt_mutex_unlock(void *, int);
#endif /* merge_units */
#define rt_mutex_unlock(a0, a1) (rt_mutex_unlock((char *)(a0), (a1))) /* merge_units */

extern int NetIGetBandwidthInfo(void *);
int NetGetBandwidthInfo(void *a)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIGetBandwidthInfo(a);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
#undef rt_mutex_lock /* merge_units */
#undef rt_mutex_unlock /* merge_units */
/* merge_units: end func_002E9978 */

/* merge_units: begin func_002E9A10 */
#if 0 /* merge_units */
extern int rt_mutex_lock(void *, int);
#endif /* merge_units */
#define rt_mutex_lock(a0, a1) (rt_mutex_lock((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int rt_mutex_unlock(void *, int);
#endif /* merge_units */
#define rt_mutex_unlock(a0, a1) (rt_mutex_unlock((char *)(a0), (a1))) /* merge_units */

extern int NetIRegisterMessageStart(void);
int NetRegisterMessageStart(void)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIRegisterMessageStart();
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
#undef rt_mutex_lock /* merge_units */
#undef rt_mutex_unlock /* merge_units */
/* merge_units: end func_002E9A10 */

/* merge_units: begin func_002E9A98 */
#if 0 /* merge_units */
extern int rt_mutex_lock(void *, int);
#endif /* merge_units */
#define rt_mutex_lock(a0, a1) (rt_mutex_lock((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int rt_mutex_unlock(void *, int);
#endif /* merge_units */
#define rt_mutex_unlock(a0, a1) (rt_mutex_unlock((char *)(a0), (a1))) /* merge_units */

extern int NetIMessageField(void *, void *, void *, void *);
int NetMessageField(void *a, void *b, void *c, void *d)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIMessageField(a, b, c, d);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
#undef rt_mutex_lock /* merge_units */
#undef rt_mutex_unlock /* merge_units */
/* merge_units: end func_002E9A98 */

/* merge_units: begin func_002E9B60 */
#if 0 /* merge_units */
extern int rt_mutex_lock(void *, int);
#endif /* merge_units */
#define rt_mutex_lock(a0, a1) (rt_mutex_lock((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int rt_mutex_unlock(void *, int);
#endif /* merge_units */
#define rt_mutex_unlock(a0, a1) (rt_mutex_unlock((char *)(a0), (a1))) /* merge_units */

extern int NetIRegisterObjectStart(void);
int NetRegisterObjectStart(void)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIRegisterObjectStart();
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
#undef rt_mutex_lock /* merge_units */
#undef rt_mutex_unlock /* merge_units */
/* merge_units: end func_002E9B60 */

/* merge_units: begin func_002E9BE8 */
#if 0 /* merge_units */
extern int rt_mutex_lock(void *, int);
#endif /* merge_units */
#define rt_mutex_lock(a0, a1) (rt_mutex_lock((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int rt_mutex_unlock(void *, int);
#endif /* merge_units */
#define rt_mutex_unlock(a0, a1) (rt_mutex_unlock((char *)(a0), (a1))) /* merge_units */

extern int NetIObjectField(void *, void *, void *, void *, void *, void *);
int NetObjectField(void *a, void *b, void *c, void *d, void *e, void *f)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIObjectField(a, b, c, d, e, f);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
#undef rt_mutex_lock /* merge_units */
#undef rt_mutex_unlock /* merge_units */
/* merge_units: end func_002E9BE8 */

/* merge_units: begin func_002E9CD0 */
#if 0 /* merge_units */
extern int rt_mutex_lock(void *, int);
#endif /* merge_units */
#define rt_mutex_lock(a0, a1) (rt_mutex_lock((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int rt_mutex_unlock(void *, int);
#endif /* merge_units */
#define rt_mutex_unlock(a0, a1) (rt_mutex_unlock((char *)(a0), (a1))) /* merge_units */

extern int NetIRegisterStructure(void *, void *, void *);
int NetRegisterStructure(void *a, void *b, void *c)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIRegisterStructure(a, b, c);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
#undef rt_mutex_lock /* merge_units */
#undef rt_mutex_unlock /* merge_units */
/* merge_units: end func_002E9CD0 */

/* merge_units: begin func_002E9D88 */
#if 0 /* merge_units */
extern int rt_mutex_lock(void *, int);
#endif /* merge_units */
#define rt_mutex_lock(a0, a1) (rt_mutex_lock((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int rt_mutex_unlock(void *, int);
#endif /* merge_units */
#define rt_mutex_unlock(a0, a1) (rt_mutex_unlock((char *)(a0), (a1))) /* merge_units */

extern int NetIRegisterRemoteObjectCallback(void *, void *, void *, void *);
int NetRegisterRemoteObjectCallback(void *a, void *b, void *c, void *d)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIRegisterRemoteObjectCallback(a, b, c, d);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
#undef rt_mutex_lock /* merge_units */
#undef rt_mutex_unlock /* merge_units */
/* merge_units: end func_002E9D88 */

/* merge_units: begin func_002E9E50 */
#if 0 /* merge_units */
extern int rt_mutex_lock(void *, int);
#endif /* merge_units */
#define rt_mutex_lock(a0, a1) (rt_mutex_lock((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int rt_mutex_unlock(void *, int);
#endif /* merge_units */
#define rt_mutex_unlock(a0, a1) (rt_mutex_unlock((char *)(a0), (a1))) /* merge_units */

extern int NetIRegisterMessage(void *, void *, void *);
int NetRegisterMessage(void *a, void *b, void *c)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIRegisterMessage(a, b, c);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
#undef rt_mutex_lock /* merge_units */
#undef rt_mutex_unlock /* merge_units */
/* merge_units: end func_002E9E50 */

/* merge_units: begin func_002E9F08 */
#if 0 /* merge_units */
extern int rt_mutex_lock(void *, int);
#endif /* merge_units */
#define rt_mutex_lock(a0, a1) (rt_mutex_lock((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int rt_mutex_unlock(void *, int);
#endif /* merge_units */
#define rt_mutex_unlock(a0, a1) (rt_mutex_unlock((char *)(a0), (a1))) /* merge_units */

extern int NetIRegisterApplicationMessage(void *, void *);
int NetRegisterApplicationMessage(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIRegisterApplicationMessage(a, b);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
#undef rt_mutex_lock /* merge_units */
#undef rt_mutex_unlock /* merge_units */
/* merge_units: end func_002E9F08 */

/* merge_units: begin func_002E9FB0 */
#if 0 /* merge_units */
extern int rt_mutex_lock(void *, int);
#endif /* merge_units */
#define rt_mutex_lock(a0, a1) (rt_mutex_lock((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int rt_mutex_unlock(void *, int);
#endif /* merge_units */
#define rt_mutex_unlock(a0, a1) (rt_mutex_unlock((char *)(a0), (a1))) /* merge_units */

extern int NetISendMessageByUDPToIP(signed char, void *, void *, void *, void *, void *);
int NetSendMessageByUDPToIP(signed char a, void *b, void *c, void *d, void *e, void *f)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetISendMessageByUDPToIP(a, b, c, d, e, f);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
#undef rt_mutex_lock /* merge_units */
#undef rt_mutex_unlock /* merge_units */
/* merge_units: end func_002E9FB0 */

/* merge_units: begin func_002EA0A0 */
#if 0 /* merge_units */
extern int rt_mutex_lock(void *, int);
#endif /* merge_units */
#define rt_mutex_lock(a0, a1) (rt_mutex_lock((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int rt_mutex_unlock(void *, int);
#endif /* merge_units */
#define rt_mutex_unlock(a0, a1) (rt_mutex_unlock((char *)(a0), (a1))) /* merge_units */

extern int NetISendMessage(signed char, void *, void *, void *, void *, void *, void *);
int NetSendMessage(signed char a, void *b, void *c, void *d, void *e, void *f, void *g)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetISendMessage(a, b, c, d, e, f, g);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
#undef rt_mutex_lock /* merge_units */
#undef rt_mutex_unlock /* merge_units */
/* merge_units: end func_002EA0A0 */

/* merge_units: begin func_002EA198 */
#if 0 /* merge_units */
extern int rt_mutex_lock(void *, int);
#endif /* merge_units */
#define rt_mutex_lock(a0, a1) (rt_mutex_lock((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int rt_mutex_unlock(void *, int);
#endif /* merge_units */
#define rt_mutex_unlock(a0, a1) (rt_mutex_unlock((char *)(a0), (a1))) /* merge_units */

extern int NetISendFilteredMessage(signed char, void *, void *, void *, void *, void *, void *);
int NetSendFilteredMessage(signed char a, void *b, void *c, void *d, void *e, void *f, void *g)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetISendFilteredMessage(a, b, c, d, e, f, g);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
#undef rt_mutex_lock /* merge_units */
#undef rt_mutex_unlock /* merge_units */
/* merge_units: end func_002EA198 */

/* merge_units: begin func_002EA290 */
#if 0 /* merge_units */
extern int rt_mutex_lock(void *, int);
#endif /* merge_units */
#define rt_mutex_lock(a0, a1) (rt_mutex_lock((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int rt_mutex_unlock(void *, int);
#endif /* merge_units */
#define rt_mutex_unlock(a0, a1) (rt_mutex_unlock((char *)(a0), (a1))) /* merge_units */

extern int NetISendApplicationMessage(signed char, void *, void *, void *, void *, void *);
int NetSendApplicationMessage(signed char a, void *b, void *c, void *d, void *e, void *f)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetISendApplicationMessage(a, b, c, d, e, f);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
#undef rt_mutex_lock /* merge_units */
#undef rt_mutex_unlock /* merge_units */
/* merge_units: end func_002EA290 */

/* merge_units: begin func_002EA380 */
#if 0 /* merge_units */
extern int rt_mutex_lock(void *, int);
#endif /* merge_units */
#define rt_mutex_lock(a0, a1) (rt_mutex_lock((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int rt_mutex_unlock(void *, int);
#endif /* merge_units */
#define rt_mutex_unlock(a0, a1) (rt_mutex_unlock((char *)(a0), (a1))) /* merge_units */

extern int NetIRegisterDataStream(void *, void *, void *, void *);
int NetRegisterDataStream(void *a, void *b, void *c, void *d)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIRegisterDataStream(a, b, c, d);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
#undef rt_mutex_lock /* merge_units */
#undef rt_mutex_unlock /* merge_units */
/* merge_units: end func_002EA380 */

/* merge_units: begin func_002EA448 */
#if 0 /* merge_units */
extern int rt_mutex_lock(void *, int);
#endif /* merge_units */
#define rt_mutex_lock(a0, a1) (rt_mutex_lock((char *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int rt_mutex_unlock(void *, int);
#endif /* merge_units */
#define rt_mutex_unlock(a0, a1) (rt_mutex_unlock((char *)(a0), (a1))) /* merge_units */

extern int NetIRegisterObjectFilter(void *, void *);
int NetRegisterObjectFilter(void *a, void *b)
{
    int r;
    if (D_0048C4D7 != 1) return 0x11;
    if (D_0048C4DC != D_0048C4D7) return 0x2B;
    if (rt_mutex_lock(D_005253F0, 0)) return 0x2B;
    r = NetIRegisterObjectFilter(a, b);
    if (rt_mutex_unlock(D_005253F0, 0)) return 0x2B;
    return r;
}
#undef rt_mutex_lock /* merge_units */
#undef rt_mutex_unlock /* merge_units */
/* merge_units: end func_002EA448 */
