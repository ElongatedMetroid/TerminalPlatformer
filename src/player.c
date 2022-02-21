#include "../include/player.h"

_Atomic int32_t player_height_row = 20;
_Atomic int32_t player_pos = 0;
int32_t player_ground_row = 20;
int8_t jump_height = 6;
int32_t jump_fall_speed = 1200000;
bool isJumping = false;

void *player_jump_thread(void *ptr) {
  while (1) {
    // does nothing, isJumping will not work if you dont do something inside the
    // thread before running it
    usleep(0);
    // if the isJumping flag is true
    if (isJumping) {
      // make the player jump up 2 rows
      player_height_row -= jump_height;

      // wihle jump_height is not greater than i
      for (int i = 0; i < jump_height; i++) {
        // sleep for half of fall speed each incrementation
        usleep(jump_fall_speed / 2);
        // check if we are at the ground row, if we are we do not want to
        // continue falling so we break from the loop
        if (player_height_row == player_ground_row)
          break;
        // fall half of jump_heigh each incrementation
        player_height_row += jump_height / 2;
      }
		
	  // we are done with our jump "function"
      isJumping = false;
    }
  }
}
