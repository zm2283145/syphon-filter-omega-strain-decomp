#ifndef MOVIE_PLAYER_H
#define MOVIE_PLAYER_H

/*
 * main/MoviePlayer (MoviePlayer.cc): the movie player keeps ten work buffers
 * at the start of its object (Unk3F9380 in loose04_types.h, built by
 * func_003F9380 and destroyed by func_003F9300). MoviePlayer_AllocBuffers
 * allocates them from heap 1; each entry keeps the raw allocation for
 * Mem_Free and a 64-byte aligned pointer into it for the decoder (the last
 * buffer is used unaligned). MoviePlayer_FreeBuffers releases them.
 * The roles of the individual buffers are not identified yet; the sizes are
 * MOVIE_BUF_SIZE_0..9 (the aligned ones include 0x40 bytes of slack).
 * C++ (MW).
 */
typedef struct MovieBuffer {
    char* aligned; /* raw rounded up to 64 bytes (== raw for buffer 9) */
    char* raw;     /* Mem_Alloc result, passed to Mem_Free */
} MovieBuffer;

#define MOVIE_BUFFER_COUNT 10

typedef struct MovieBuffers {
    MovieBuffer buf[MOVIE_BUFFER_COUNT]; /* 0x00..0x50 */
} MovieBuffers;

#define MOVIE_BUF_SIZE_0 0x32A040
#define MOVIE_BUF_SIZE_1 0x99CC0
#define MOVIE_BUF_SIZE_2 0x1050
#define MOVIE_BUF_SIZE_3 0x1CA240
#define MOVIE_BUF_SIZE_4 0xC040
#define MOVIE_BUF_SIZE_5 0x840
#define MOVIE_BUF_SIZE_6 0x5004C
#define MOVIE_BUF_SIZE_7 0x80040
#define MOVIE_BUF_SIZE_8 0x4040
#define MOVIE_BUF_SIZE_9 0x3000

#define MOVIE_ALIGN64(p) ((char*)(((int)(p) + 0x3F) & ~0x3F))

#define MoviePlayer_srcFile D_004BE1E0 /* "MoviePlayer.cc" */

#endif /* MOVIE_PLAYER_H */