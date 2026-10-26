#include "types.h"
extern char D_00571CD8[];
extern char D_00571CF0[];
extern void __register_global_object();
extern void cMovieSubtitles_dtor();
void StaticInit_MovieSubtitles(void)
{
    __register_global_object((int)D_00571CF0, (int)cMovieSubtitles_dtor, (int)D_00571CD8);
}
