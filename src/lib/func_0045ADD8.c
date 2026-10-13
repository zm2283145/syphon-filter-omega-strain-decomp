/* setsockopt-style wrapper: a one-byte value for options 10/11 at level 0 is widened to an int. */
extern int func_0035A590(int s, int level, int optname, void* optval, int optlen);

int func_0045ADD8(int s, int level, int optname, void* optval, int optlen)
{
    int v;
    if (level == 0 && (unsigned)(optname - 10) < 2 && optval != 0 && optlen == 1) {
        v = *(char*)optval;
        return func_0035A590(s, 0, optname, &v, 4);
    }
    return func_0035A590(s, level, optname, optval, optlen);
}
