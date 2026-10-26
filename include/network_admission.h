#ifndef NETWORK_ADMISSION_H
#define NETWORK_ADMISSION_H

/* Bit representations used by the retail software floating-point runtime. */
typedef unsigned long long SoftwareDoubleBits;

extern "C" {
extern int D_00572538;
extern unsigned int D_00572428;
extern unsigned int D_0057242C;
extern unsigned int D_00572430;
extern unsigned char D_00572400;
extern unsigned char D_005723F8;
extern unsigned char g_IsMultiplayer;
extern int D_005721A8;
extern int D_00494180;
SoftwareDoubleBits SoftFloat_IntToDouble(int value);
SoftwareDoubleBits SoftFloat_FloatToDouble(float value);
SoftwareDoubleBits SoftFloat_DoubleMultiply(SoftwareDoubleBits first, SoftwareDoubleBits second);
SoftwareDoubleBits SoftFloat_DoubleSub(SoftwareDoubleBits first, SoftwareDoubleBits second);
unsigned int SoftFloat_DoubleToInt(SoftwareDoubleBits value);
void NetGetValidClientCount(int* count, int game);
}

static inline unsigned int retry_threshold(void)
{
    int timer = D_00572538;
    SoftwareDoubleBits base = SoftFloat_IntToDouble(timer);
    SoftwareDoubleBits converted = SoftFloat_FloatToDouble((float)timer);
    SoftwareDoubleBits scaled = SoftFloat_DoubleMultiply(0x3FB0000000000000ULL, converted);
    return SoftFloat_DoubleToInt(SoftFloat_DoubleSub(base, scaled));
}

static inline int player_count(void)
{
    if (g_IsMultiplayer) {
        int count;
        NetGetValidClientCount(&count, D_005721A8);
        return count;
    }
    return 1;
}

static inline unsigned char admission_available(void)
{
    unsigned char available = (D_00572400 != 0) ^ 1;
    if (available)
        available = (D_005723F8 != 0) ^ 1;
    return available;
}

static inline unsigned char room_available(void)
{
    unsigned char allowed = admission_available();
    if (allowed) {
        int limit = D_00494180;
        allowed = player_count() < limit;
    }
    return allowed;
}

#endif
