extern int func_00128D10(); extern int func_00128D78(); extern int func_00128DF8(); extern int func_00128E60();
typedef struct { unsigned char* _p; int _r; int _w; short _flags; short _file; unsigned char* _bf_base; int _bf_size; int _lbfsize; void* _cookie; void* _read; void* _write; void* _seek; void* _close; char pad[0x24]; void* _data; } FILE_00123730;
void func_00123730(FILE_00123730* ptr, int flags, int file, void* data)
{
  ptr->_p = 0;
  ptr->_r = 0;
  ptr->_w = 0;
  ptr->_flags = flags;
  ptr->_file = file;
  ptr->_bf_base = 0;
  ptr->_bf_size = 0;
  ptr->_lbfsize = 0;
  ptr->_cookie = ptr;
  ptr->_read = func_00128D10;
  ptr->_write = func_00128D78;
  ptr->_seek = func_00128DF8;
  ptr->_close = func_00128E60;
  ptr->_data = data;
}