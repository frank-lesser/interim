#include "minilisp.h"
#include "blit.h"
#include "machine.h"

#define CPU_ARM

#define put_pixel machine_video_set_pixel

int blit_vector32(uint32_t* pixels, uint sx, uint sy, uint pitch, uint w, uint h, uint dx, uint dy)
{
  for (int y=0; y<h; y++) {
    for (int x=0; x<w; x++) {
      put_pixel(dx+x,dy+y, pixels[((sy+y)*pitch+sx+x)]);
    }
  }
  
  return 0;
}

// blits b+w bitmaps 
//int blit_vector1(void* pixels, uint sx, uint sy, uint pitch, uint w, uint h, uint dx, uint dy, uint color)
int blit_vector1(uint color, uint dy, uint dx, uint h, uint w, uint pitch, uint sy, uint sx, uint8_t* pixels)
{
  for (unsigned int y=0; y<h; y++) {
    unsigned int ty = dy+y;
    for (unsigned int x=0; x<w; x++) {
      unsigned int px = pixels[((sy+y)*pitch+sx+x)];
      unsigned int tx = dx+x*8;
      
      // unpack byte into 8 pixels
      put_pixel(tx++,ty,((px>>7)&1)?color:0);
      put_pixel(tx++,ty,((px>>6)&1)?color:0);
      put_pixel(tx++,ty,((px>>5)&1)?color:0);
      put_pixel(tx++,ty,((px>>4)&1)?color:0);
      put_pixel(tx++,ty,((px>>3)&1)?color:0);
      put_pixel(tx++,ty,((px>>2)&1)?color:0);
      put_pixel(tx++,ty,((px>>1)&1)?color:0);
      put_pixel(tx,ty,(px&1)?color:0);
    }
  }
  
  return 0;
}

int blit_vector1_invert(uint color, uint dy, uint dx, uint h, uint w, uint pitch, uint sy, uint sx, uint8_t* pixels)
{
  for (unsigned int y=0; y<h; y++) {
    unsigned int ty = dy+y;
    for (unsigned int x=0; x<w; x++) {
      unsigned int px = pixels[((sy+y)*pitch+sx+x)];
      unsigned int tx = dx+x*8;
      
      // unpack byte into 8 pixels
      put_pixel(tx++,ty,((px>>7)&1)?0:color);
      put_pixel(tx++,ty,((px>>6)&1)?0:color);
      put_pixel(tx++,ty,((px>>5)&1)?0:color);
      put_pixel(tx++,ty,((px>>4)&1)?0:color);
      put_pixel(tx++,ty,((px>>3)&1)?0:color);
      put_pixel(tx++,ty,((px>>2)&1)?0:color);
      put_pixel(tx++,ty,((px>>1)&1)?0:color);
      put_pixel(tx,ty,(px&1)?0:color);
    }
  }
  
  return 0;
}
