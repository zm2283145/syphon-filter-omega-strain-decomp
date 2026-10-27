#pragma cplusplus on
#include "types.h"
typedef struct { char* base; char* y; int pad8; int padC; int count; } MovieBufs;
typedef struct { int a; int b; int stopped; char pad[0xA8 - 0xC]; int state; } MovieCtx;
typedef struct { int y; int uv; } Frame;
extern "C" {
int sceMpegIsEnd(MovieCtx*);
void sceMpegReset(MovieCtx*);
void sceMpegGetPicture(MovieCtx*, int, int);
void printf(char*);
int voBufGetData(MovieBufs*);
void voBufIncCount(MovieBufs*);
int setImageTag(char*, char*, int, int, int);
void cMoviePlayer_SetMovieDims(int, int);
void cMoviePlayer_SwitchThread(void);
void cMovieSubtitles_GraftDma(char*, int, int, int, int);
void cMovieSubtitles_Render(char*);
void cMovieSubtitles_FirstFrame(char*);
}
extern char D_004BE1C0[];
extern MovieBufs D_0055C460;
extern int D_0055C5A8;
extern char D_00571CF0[];

extern "C" int decBs0(MovieCtx* self)
{
    int ret = 1;
    Frame f[2];
    while (!sceMpegIsEnd(self)) {
        int buf;
        if (self->state == 1) {
            ret = -1;
            printf(D_004BE1C0);
            break;
        }
        while (!(buf = voBufGetData(&D_0055C460)))
            cMoviePlayer_SwitchThread();
        sceMpegGetPicture(self, buf, 0x654);
        if (self->stopped == 0) {
            int a = self->a;
            int b = self->b;
            int i;
            for (i = 0; i < D_0055C460.count; i++) {
                f[i].y = setImageTag(D_0055C460.y + i * 0x4CE40 + 0x40, D_0055C460.base + i * 0x195000, 0, a, b);
                f[i].uv = setImageTag(D_0055C460.y + i * 0x4CE40 + 0x26740, D_0055C460.base + i * 0x195000, 1, a, b);
            }
            cMoviePlayer_SetMovieDims(a, b);
            D_0055C5A8 = 0;
            cMovieSubtitles_GraftDma(D_00571CF0, f[0].y, f[0].uv, f[1].y, f[1].uv);
            cMovieSubtitles_FirstFrame(D_00571CF0);
        }
        cMovieSubtitles_Render(D_00571CF0);
        voBufIncCount(&D_0055C460);
        cMoviePlayer_SwitchThread();
    }
    sceMpegReset(self);
    return ret;
}



