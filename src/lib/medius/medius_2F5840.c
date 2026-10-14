int func_002F5840(unsigned int *o, unsigned int *out)
{
    int ret = 2;
    if (o != 0 && out != 0) {
        if (o[3] != 0) {
            if (o[0] < o[1]) *out = o[1] - o[0];
            else *out = o[2] - o[0];
        } else *out = 0;
        ret = 0;
    }
    return ret;
}