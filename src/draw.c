#include "../include/draw.h"

void *draw_thread(void *level_data) {
  while (1) {
    printf(CLEAR);
    print_mapdata_from_curr_mappos((char *)level_data);
    usleep(20000);
  }
}
