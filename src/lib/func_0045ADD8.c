/* setsockopt-style wrapper: a one-byte value for options 10/11 at level 0 is widened to an int. */
extern int Insck_Setsockopt(int s, int level, int optname, void* optval, int optlen);

int sceNetGlueSetsockopt(int s, int level, int optname, void* optval, int optlen)
{
    int v;
    if (level == 0 && (unsigned)(optname - 10) < 2 && optval != 0 && optlen == 1) {
        v = *(char*)optval;
        return Insck_Setsockopt(s, 0, optname, &v, 4);
    }
    return Insck_Setsockopt(s, level, optname, optval, optlen);
}
