/*
 * main/MoviePlayer: 2 files, 003F8840-003F8D20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003F8840 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#include "movie_player.h"
extern "C" {
void Mem_Free(int heap, void* p, char* file, int line);
}
/* Mem_Free from heap 1 under the allocator lock; line is the MoviePlayer.cc source line. */
static inline void MovieFree(void* p, int line) { AllocGuard g; Mem_Free(1, p, "MoviePlayer.cc", line); }
/* Releases the ten work buffers allocated by MoviePlayer_AllocBuffers. */
extern "C" void MoviePlayer_FreeBuffers(MovieBuffers* self)
{
    MovieFree(self->buf[0].raw, 0x7E);
    MovieFree(self->buf[1].raw, 0x7F);
    MovieFree(self->buf[2].raw, 0x80);
    MovieFree(self->buf[3].raw, 0x82);
    MovieFree(self->buf[4].raw, 0x83);
    MovieFree(self->buf[5].raw, 0x85);
    MovieFree(self->buf[6].raw, 0x86);
    MovieFree(self->buf[7].raw, 0x87);
    MovieFree(self->buf[8].raw, 0x88);
    MovieFree(self->buf[9].raw, 0x89);
}
#pragma pop /* merge_units */
/* merge_units: end func_003F8840 */

/* merge_units: begin func_003F8D20 */
#pragma push /* merge_units */
#pragma cplusplus on
extern "C" {
extern char MoviePlayer_srcFile[];
void* Mem_Alloc(int heap, int size, char* file, int line);
}
/* Mem_Alloc from heap 1 under the allocator lock; line is the MoviePlayer.cc source line. */
static inline char* MovieAlloc(int size, int line) { AllocGuard g; return (char*)Mem_Alloc(1, size, MoviePlayer_srcFile, line); }
/* Allocates the ten work buffers (64-byte aligned except the last). */
extern "C" void MoviePlayer_AllocBuffers(MovieBuffers* self)
{
    self->buf[0].raw = MovieAlloc(MOVIE_BUF_SIZE_0, 0x51);
    self->buf[0].aligned = MOVIE_ALIGN64(self->buf[0].raw);
    self->buf[1].raw = MovieAlloc(MOVIE_BUF_SIZE_1, 0x55);
    self->buf[1].aligned = MOVIE_ALIGN64(self->buf[1].raw);
    self->buf[2].raw = MovieAlloc(MOVIE_BUF_SIZE_2, 0x59);
    self->buf[2].aligned = MOVIE_ALIGN64(self->buf[2].raw);
    self->buf[3].raw = MovieAlloc(MOVIE_BUF_SIZE_3, 0x5E);
    self->buf[3].aligned = MOVIE_ALIGN64(self->buf[3].raw);
    self->buf[4].raw = MovieAlloc(MOVIE_BUF_SIZE_4, 0x62);
    self->buf[4].aligned = MOVIE_ALIGN64(self->buf[4].raw);
    self->buf[5].raw = MovieAlloc(MOVIE_BUF_SIZE_5, 0x67);
    self->buf[5].aligned = MOVIE_ALIGN64(self->buf[5].raw);
    self->buf[6].raw = MovieAlloc(MOVIE_BUF_SIZE_6, 0x6B);
    self->buf[6].aligned = MOVIE_ALIGN64(self->buf[6].raw);
    self->buf[7].raw = MovieAlloc(MOVIE_BUF_SIZE_7, 0x6F);
    self->buf[7].aligned = MOVIE_ALIGN64(self->buf[7].raw);
    self->buf[8].raw = MovieAlloc(MOVIE_BUF_SIZE_8, 0x73);
    self->buf[8].aligned = MOVIE_ALIGN64(self->buf[8].raw);
    self->buf[9].raw = MovieAlloc(MOVIE_BUF_SIZE_9, 0x77);
    self->buf[9].aligned = self->buf[9].raw;
}
#pragma pop /* merge_units */
/* merge_units: end func_003F8D20 */
