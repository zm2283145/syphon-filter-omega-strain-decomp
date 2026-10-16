extern int func_002B6D20(int ctx, int id, int* status);
int func_002B7260(int ctx, int id)
{
    int status; int depth = 1; int cl; int more;
    if (id == -1) return 0;
    cl = id;
    for (;;) {
        cl = func_002B6D20(ctx, cl, &status);
        if (status) return status;
        if (cl == -1) return depth;
        if (!(cl & 0x80000000)) break;
        cl &= 0x7FFFFFFF;
        depth++;
    }
    return 0x81019002;
}

