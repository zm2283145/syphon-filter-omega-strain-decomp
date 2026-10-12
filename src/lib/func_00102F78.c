extern unsigned long long *func_00102A18(void);
int func_00102F78(short mode, short width, short height)
{
    unsigned long long *p=func_00102A18();
    int x=(width+63)/64;
    int y;
    short count;
    if(mode&2)y=(height+63)/64;
    else y=(height+31)/32;
    if((*p&0x0000FFFF0000FFFFULL)==1) count=x*y;
    else count=x*y*2;
    return count;
}



