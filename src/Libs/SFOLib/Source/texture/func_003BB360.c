/* 003BB360 cTexture::UploadBoth(unsigned int, unsigned int) (texture.cc), from the prototype DWARF (locals tdata, data,
   dataPtr, sourcePtr, bothSize, mask, temp, i, gif) and k5/m8 drafts. Line 180 (TEX0 TBP0/CBP rewrite) is the head block;
   the CLUT and texel blocks go through the scratchpad with the toSPR/fromSPR DMA channels. */
#pragma cplusplus on

typedef unsigned long u64_t;
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
};

extern "C" {
extern char D_00537F80[];
u64_t* cDmaMan_BeginChain_eDmaChannel_int(void* dm, int chan, int size);
void cDmaMan_EndChain_int_ulongP(void* dm, int chan, u64_t* end);
void cTexture_UploadBoth(cTexture* self, unsigned int texAddr, unsigned int clutAddr);
}

static inline tTDXImageFrame* GetFrame(tTDXHeader* info, unsigned int frame) { char* p = (char*)(info + 1); unsigned int f = 0; while (f < frame) { p += info->imageFrameSize; f++; } return (tTDXImageFrame*)p; }

#define R(a) (*(volatile unsigned int*)(a))

void cTexture_UploadBoth(cTexture* self, unsigned int texAddr, unsigned int clutAddr)
{
    /* TEX0: TBP0 <- texAddr, CBP <- clutAddr. The CBP shift is written as its own statement (two-statement form)
       so the zero-extension and the shift share one register, as in retail. */
    {
        unsigned long t;
        unsigned long c;
        c = clutAddr;
        t = self->tex01 & 0xFFF8001FFFFFC000UL;
        self->tex01 = t;
        t |= (unsigned long)texAddr;
        c <<= 37;
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

        tdata = GetFrame(self->info, self->frame);
        data = (tImageDMA*)0x70000000;
        mask = 0xFFFFC000FFFFFFFFULL;
        sourcePtr = (tImageDMA*)(tdata + 1);
        if (self->HasMap()) {
            dataPtr = data + self->info->numImageBlits;
            R(0x1000D420) = self->info->mapDmaSize >> 4;
            R(0x1000D480) = (unsigned int)dataPtr;
            R(0x1000D410) = (unsigned int)sourcePtr;
            R(0x1000D400) = 0x100;
            asm volatile ("sync"); /* EE sync: no C equivalent */
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
        asm volatile ("sync"); /* EE sync: no C equivalent */
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
        asm volatile ("sync"); /* EE sync: no C equivalent */
        gif += bothSize >> 3;
        cDmaMan_EndChain_int_ulongP(D_00537F80, 2, gif);
    }
}
