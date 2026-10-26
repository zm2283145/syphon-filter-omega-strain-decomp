/*
 * lib/usbkb: 2 files, 00223C00-00223C68
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00223C00 */
typedef struct { char pad[0x10]; unsigned short s10; unsigned short buf[4]; char pad2[2]; int wr; int rd; int count; } Q223C00;
typedef struct { int f0; int f4; int f8; int fc; Q223C00 q; } E223C00;extern E223C00* D_004F5784;
int pop_repbuf(int i, unsigned short* out)
{
    Q223C00* q = &D_004F5784[i].q;
    if (q->count <= 0) return -1;
    *out = q->buf[q->rd++];
    if (q->rd >= 4) q->rd = 0;
    q->count--;
    return 0;
}
/* merge_units: end func_00223C00 */

/* merge_units: begin func_00223C68 */
typedef struct { int a,mode,table; char pad[44]; } Map3C68;
#if 0 /* merge_units */
extern Map3C68 *D_004F5784;
#endif /* merge_units */
#define D_004F5784 (*(Map3C68 **)&D_004F5784) /* merge_units */

extern unsigned short sceUsbKbCnvRawCode(int,unsigned char,unsigned char,unsigned short);
int cnv_keycode(int map,unsigned char a,unsigned char b,int count,unsigned short *src,unsigned short *dst)
{
 Map3C68 *p=&D_004F5784[map];
 int n=0,i;
 switch(p->mode){
 case 0:
  for(i=0;i<count && src[i];i++)dst[i]=src[i];
  n=i;break;
 case 1:
  for(i=0;i<count && src[i];i++)dst[i]=sceUsbKbCnvRawCode(p->table,a,b,src[i]);
  n=i;break;
 }
 return n;
}
#undef D_004F5784 /* merge_units */
/* merge_units: end func_00223C68 */
