extern int sceScfGetTimeZone(void);
extern int sceScfGetSummerTime(void);
extern void AdjustTime(void *, int);

void sceScfGetLocalTimefromRTC(void *t)
{
    int tz = sceScfGetTimeZone();
    int d = sceScfGetSummerTime() * 60 - 540;
    AdjustTime(t, tz + d);
}
