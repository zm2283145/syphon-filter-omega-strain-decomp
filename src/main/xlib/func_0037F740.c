typedef struct { float w, h; } Res;
typedef struct {
    unsigned int flags;
    char pad4[0x10 - 4];
    int dispw;
    int disph;
    char pad18[0x1C - 0x18];
    int w;
    int h;
    char pad24[0x3C - 0x24];
    float f3C, f40, f44, f48, sx, sy, f54, f58, f5C, f60;
    char pad64[0xF80 - 0x64];
    int iF80, iF84;
    float resw, resh;
    float aspect, aspect2;
} Rnd;
extern Res D_004BC1D0[];

void Renderer_GetAspect(Rnd* r)
{
    int sel;
    int iw;
    int ih;
    int i;
    Res* p;
    int dw;
    int dh;
    dw = r->dispw;
    dh = r->disph;
    iw = 0;
    ih = 0;

    for (i = 0, p = D_004BC1D0; i < 6; i++, p++) {
        if ((float)dw <= p->w) iw = i;
        if ((float)dh <= p->h) ih = i;
        if (iw != i || ih != i) {
            sel = i - 1;
            break;
        }
    }
    r->iF80 = 0;
    r->iF84 = 0;
    r->resw = D_004BC1D0[sel].w;
    r->resh = D_004BC1D0[sel].h;
    r->sx = r->w / r->resw;
    r->sy = r->h / r->resh;
    r->f54 = 0.0f;
    r->f58 = 0.0f;
    r->f5C = 1.0f;
    r->f60 = 1.0f;
    if (r->flags & 4) {
        r->f60 *= r->w / 720.0f;
    } else if (r->flags & 2) {
        r->f60 *= 1.0666667f;
    }
    r->f44 = 1.0f;
    r->f48 = 1.0f;
    r->f3C = 0.0f;
    r->f40 = 0.0f;
    r->aspect2 = r->aspect = r->resw / r->resh;
}




