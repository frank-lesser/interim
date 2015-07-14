#include "minilisp.h"
#include <stdint.h>

#define SCREEN_W 640
#define SCREEN_H 480
#define COLOR_TYPE uint8_t
#define SCREEN_BPP 1 // bytes per pixel

int machine_video_set_pixel(uint32_t x,uint32_t y,COLOR_TYPE c);
int machine_video_rect(uint32_t x,uint32_t y,uint32_t w,uint32_t h,COLOR_TYPE c);
int machine_video_flip();

int machine_get_key();
int machine_get_modifiers();

Cell* machine_save_file(Cell* cell, char* path);
Cell* machine_load_file(char* path);

Cell* machine_poll_udp();
Cell* machine_send_udp(Cell* data_cell);

Cell* machine_connect_tcp(Cell* host_cell, Cell* port_cell, Cell* connected_fn_cell, Cell* data_fn_cell);
Cell* machine_send_tcp(Cell* data_cell);
Cell* machine_bind_tcp(Cell* port_cell, Cell* fn_cell);
