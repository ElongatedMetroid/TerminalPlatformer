#include "../include/draw.h"

void *draw_thread() {
  // go forever, clear screen, update screen, wait
  strcpy(current_level_data, return_current_level(current_level_number));
  while (1) {
    printf(CLEAR);
    draw_mapdata_from_curr_mappos((char *)current_level_data);
    usleep(20000);
  }
}

void draw_mapdata_from_curr_mappos(char *mapdata) {
  // set index to the map position offset because we want to start printing the
  // array at the offset, not anything before
  int index = map_pos_offset;
  // go until we have printed all rows
  for (int rows = 0; rows < MAP_DATA_HEIGHT; rows++) {
    // we want the player to be draw in the middle at all times so we add 50 to
    // the index and make that the player position
    player_pos = index + 50;
    // the map HUD will always we drawn at the top of the screen before any map
    // data will be able to be drawn
    if (rows == 0)
      draw_map_hud();
    if (rows == player_y_level)
      mapdata[player_pos] = '@';

    // loop until we have printed 105 characters (MAP_DATA_WIDTH) or 1 row
    for (int cols = 0; cols < MAP_DATA_WIDTH; ++cols) {
      // print the next character
      printf("%c", mapdata[index]);
      // increment index
      index++;
    }

    // keep going through the array until we hit the next row we have to do this
    // because we are not printing the whole array at once
    while (mapdata[index] != '-') {
      // make sure the index has not gone out of control
      if (index >= OUT_OF_CONTROL_INDEX)
        return;
      index++;
    }

    //  add the map position offset to the index because we want to print the
    //  next row starting at the right position
    index += map_pos_offset + 1;

    if (rows == player_y_level)
      mapdata[player_pos] = ' ';

    // add newline since the array does not provide any
    putc('\n', stdout);
  }
}

void draw_map_hud() { puts("Coins:  Score:"); }
