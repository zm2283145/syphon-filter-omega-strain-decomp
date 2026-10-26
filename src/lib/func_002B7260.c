extern int _sceMcFatGetNextClust(int ctx, int id, int* status);
int _fat_chain_trace(int ctx, int id)
{
    int status; int depth = 1; int cl; int more;
    if (id == -1) return 0;
    cl = id;
    for (;;) {
        cl = _sceMcFatGetNextClust(ctx, cl, &status);
        if (status) return status;
        if (cl == -1) return depth;
        if (!(cl & 0x80000000)) break;
        cl &= 0x7FFFFFFF;
        depth++;
    }
    return 0x81019002;
}

