#include "types.h"

typedef struct {
    short time;
    unsigned short value;
} lipSyncData;

typedef struct {
    short count;
    unsigned short timeIndex;
    short time1;
    short time2;
    float value1;
    float value2;
} lipSyncKeys;

typedef struct {
    char pad0[0x23F0];
    float faceBlends[8];
    char pad2410[0x2BC1 - 0x2410];
    unsigned char faceBlendCount;
    unsigned char faceBlendNumbers[8];
    char pad2BCA[0x2C18 - 0x2BCA];
    lipSyncKeys speechAnim[21];
    lipSyncData** speechHeader;
    int speechTime;
} cMan;

extern int g_TimerAccum;
extern long g_TickCounter64;

static inline int DivTime(long n)
{
    int bit = 1 << 30;
    int q = 0;
    long d = 100;
    int i;
    d <<= 30;
    for (i = 0; i < 31; i++) {
        long r = n - d;
        if (r >= 0) {
            n = r;
            q += bit;
        }
        d >>= 1;
        bit >>= 1;
    }
    return q;
}

static inline float Lerp(float a, float b, float t) { return a + (b - a) * t; }
void cMan_LipSyncUpdate(cMan* self)
{
    int stillPlaying;
    int time1;
    int time2;
    int timeIndex;
    int faceCount;
    int time;
    int j;
    lipSyncData* data;

    stillPlaying = 0;
    faceCount = self->faceBlendCount;
    time = DivTime(g_TickCounter64 + (int)((float)(unsigned int)(*(volatile int*)0x10000800 + g_TimerAccum) / 5.76f));time -= self->speechTime;
    for (j = 0; j < 21; j++) {
        time2 = self->speechAnim[j].time2;
        while (time2 < time) {
            timeIndex = self->speechAnim[j].timeIndex + 1;
            if (timeIndex >= self->speechAnim[j].count) break;
            self->speechAnim[j].timeIndex = timeIndex;
            data = self->speechHeader[j];
            self->speechAnim[j].time1 = self->speechAnim[j].time2;
            data = (lipSyncData*)((char*)data + (timeIndex << 2));
            self->speechAnim[j].time2 = data->time;
            time2 = self->speechAnim[j].time2;
            self->speechAnim[j].value1 = self->speechAnim[j].value2;
            self->speechAnim[j].value2 = 3.0517578125e-05f * data->value;
            if (self->speechAnim[j].value1 == 0.0f && self->speechAnim[j].value2 == 0.0f) {
                self->speechAnim[j].time1 = self->speechAnim[j].time2;
            }
        }
        time1 = self->speechAnim[j].time1;
        if (time <= time2) {
            stillPlaying = 1;
            if (time1 < time && faceCount < 8) {
                time2 -= time1;
                self->faceBlends[faceCount] = Lerp(self->speechAnim[j].value1, self->speechAnim[j].value2, (float)(time - time1) / (float)time2);
                self->faceBlendNumbers[faceCount] = j;
                if (j >= 19) self->faceBlendNumbers[faceCount] = j + 4;
                faceCount++;
            }
        }
    }
    self->faceBlendCount = faceCount;
    if (!stillPlaying) self->speechHeader = 0;
}
