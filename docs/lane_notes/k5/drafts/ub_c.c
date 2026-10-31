#pragma cplusplus on

typedef unsigned long long u64_t;
typedef struct { u64_t lo, hi; } q128_t __attribute__((aligned(16)));

struct tTDXHeader {
    unsigned short version;
    unsigned short imageFlags;
    unsigned short imageWidth;
    unsigned short imageHeight;
    unsigned short imageDepth;
    unsigned short imageFormat;
    unsigned short imageDstWidth;
    unsigned short imageDstSize;
    unsigned short mapWidth;
    unsigned short mapHeight;
    unsigned short mapDepth;
    unsigned short mapFormat;
    unsigned short mapDstWidth;
    unsigned short mapDstSize;
    unsigned short numMips;
    unsigned short lval;
    unsigned short kval;
    unsigned short numFrames;
    unsigned short numImageBlits;
    unsigned short numMapBlits;
    unsigned short imageVramOffs[5];
    unsigned short mapVramOffs[1];
    unsigned short imageDmaSize;
    unsigned short mapDmaSize;
    unsigned int imageFrameSize;
    unsigned int isPatched;
};

struct tTDXImageFrame {
    unsigned int imageBitBltOffs[5];
    unsigned int mapBitBltOffs[1];
    unsigned char* dmaImage;
    unsigned char* dmaMap;
};

struct tImageDMA {
    q128_t dmaCnt6;
    q128_t regListMode;
    u64_t bitBltBuffData;
    u64_t bitBltBuffCmd;
    q128_t trxPos;
    q128_t trxReg;
    q128_t trxDir;
    q128_t imageMode;
    q128_t dmaRef;
};

struct cTexture {
    char name[65];
    tTDXHeader* info;
    unsigned int flags;
    unsigned int frame;
    u64_t tex01;
    u64_t tex11;
    unsigned char txtrIsVram;
    unsigned char clutIsVram;
    unsigned char vramLock;
    int refCount;
    bool HasMap() const { return info->mapWidth > 0; }
    int MapW() const { return info->mapWidth; }
    tTDXHeader* Info() const { return info; }
};

extern "C" {
extern char D_00537F80[];
u64_t* cDmaMan_BeginChain_eDmaChannel_int(void* dm, int chan, int size);
void cDmaMan_EndChain_int_ulongP(void* dm, int chan, u64_t* end);
void cTexture_UploadBoth(cTexture* self, unsigned int texAddr, unsigned int clutAddr);
}

static inline u64_t SetAddrs(u64_t v, unsigned int t, unsigned int c) { v &= 0xFFF8001FFFFFC000ULL; return v | (u64_t)t | ((u64_t)c << 37); }
static inline tTDXImageFrame* GetFrame(tTDXHeader* info, unsigned int frame) { tTDXImageFrame* p = (tTDXImageFrame*)(info + 1); for (unsigned int f = 0; f < frame; f++) p = (tTDXImageFrame*)((char*)p + info->imageFrameSize); return p; }
static inline tTDXImageFrame* GetFrame2(tTDXHeader* info, unsigned int frame) { char* p = (char*)(info + 1); unsigned int f = 0; while (f < frame) { p += info->imageFrameSize; f++; } return (tTDXImageFrame*)p; }
static inline u64_t SetAddrs2(cTexture* s, u64_t v, unsigned int t, unsigned int c) { v &= 0xFFF8001FFFFFC000ULL; s->tex01 = v; return v | (u64_t)t | ((u64_t)c << 37); }
static inline void SetAddrs3(u64_t* p, unsigned int t, unsigned int c) { u64_t v = *p & 0xFFF8001FFFFFC000ULL; *p = v; *p = v | (u64_t)t | ((u64_t)c << 37); }
#define R(a) (*(volatile unsigned int*)(a))

void cTexture_UploadBoth(cTexture* self, unsigned int texAddr, unsigned int clutAddr)
{
    {
        u64_t c;
        u64_t t;
        u64_t l;
        u64_t m;
        m = ~0x0007FFE000003FFFULL;
        l = self->tex01;
        c = (u64_t)clutAddr << 37;
        t = l & m;
        self->tex01 = t;
        t |= (u64_t)texAddr;
        t |= c;
        self->tex01 = t;
    }
    if (self->info->numFrames == 1) {
        self->txtrIsVram = 1;
        self->clutIsVram = 1;
    }
    if (self->flags & 0x400) {
        tTDXImageFrame* tdata;
        tImageDMA* data;
        tImageDMA* dataPtr;
        tImageDMA* sourcePtr;
        int bothSize;
        u64_t mask;
        u64_t temp;
        int i;
        u64_t* gif;

        tdata = GetFrame2(self->info, self->frame);
        data = (tImageDMA*)0x70000000;
        mask = 0xFFFFC000FFFFFFFFULL;
        sourcePtr = (tImageDMA*)(tdata + 1);
        if (self->HasMap()) {
            dataPtr = data + self->info->numImageBlits;
            R(0x1000D420) = self->info->mapDmaSize >> 4;
            R(0x1000D480) = (unsigned int)dataPtr;
            R(0x1000D410) = (unsigned int)sourcePtr;
            R(0x1000D400) = 0x100;
            asm volatile ("sync");
            while (R(0x1000D400) & 0x100) {
            }
            sourcePtr++;
            temp = dataPtr->bitBltBuffData & mask;
            dataPtr->bitBltBuffData = temp | ((u64_t)(clutAddr + self->info->mapVramOffs[0]) << 32);
        }
        dataPtr = data;
        R(0x1000D420) = self->info->imageDmaSize >> 4;
        R(0x1000D480) = (unsigned int)dataPtr;
        R(0x1000D410) = (unsigned int)sourcePtr;
        R(0x1000D400) = 0x100;
        asm volatile ("sync");
        while (R(0x1000D400) & 0x100) {
        }
        for (i = 0; i < self->info->numImageBlits; i++) {
            temp = dataPtr->bitBltBuffData & mask;
            dataPtr->bitBltBuffData = temp | ((u64_t)(texAddr + self->info->imageVramOffs[i]) << 32);
            dataPtr++;
        }
        bothSize = self->info->imageDmaSize + self->info->mapDmaSize;
        gif = cDmaMan_BeginChain_eDmaChannel_int(D_00537F80, 2, bothSize);
        R(0x1000D020) = bothSize >> 4;
        R(0x1000D080) = (unsigned int)data;
        R(0x1000D010) = (unsigned int)gif & 0x0FFFFFFF;
        R(0x1000D000) = 0x100;
        asm volatile ("sync");
        gif += bothSize >> 3;
        cDmaMan_EndChain_int_ulongP(D_00537F80, 2, gif);
    }
}
