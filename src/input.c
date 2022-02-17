#include "../include/input.h"

void *input_thread(void *ptr) {
  char ch = '\0';
  while (1) {
    ch = fgetc(stdin);
    if ((ch = 'a')) { // move left
      map_pos_offset--;
	  print_mapdata_from_curr_mappos(debug_map_data);
    }
    if ((ch = 'd')) { // move right
      map_pos_offset++;
	  print_mapdata_from_curr_mappos(debug_map_data);
	}
  }
}
