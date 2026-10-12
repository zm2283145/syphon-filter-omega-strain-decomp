/* Stores a 48-byte block passed by value into a global. */
typedef struct { unsigned char b[48]; } Blk2CE768;
extern Blk2CE768 D_0051EFA8;
void func_002CE768(Blk2CE768 s)
{
    D_0051EFA8 = s;
}
