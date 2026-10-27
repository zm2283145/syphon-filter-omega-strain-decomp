/* setsockopt-style wrapper: a one-byte value for options 10/11 at level 0 is widened to an int. */
extern int sceInsockSetsockopt(int s, int level, int optname, void* optval, int optlen);

int sceNetGlueSetsockopt(int s, int level, int optname, void* optval, int optlen)
{
    int v;
    if (level == 0 && (unsigned)(optname - 10) < 2 && optval != 0 && optlen == 1) {
        v = *(char*)optval;
        return sceInsockSetsockopt(s, 0, optname, &v, 4);
    }
    return sceInsockSetsockopt(s, level, optname, optval, optlen);
}
