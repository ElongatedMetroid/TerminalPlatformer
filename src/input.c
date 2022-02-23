#include "../include/input.h"

void *input_thread(void *ptr) {
  // structure for our new terminal settings that do not require enter to be
  // pressed for our program to recive input
  static struct termios newt;
  // char for reciving input
  char ch = '\0';

  /* tcgetattr gets the parameters of the current terminal
   * STDIN_FILENO will tell tcgetattr that it should write
   * the settings of stdin to oldt
   */
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;

  /* ICANON normally takes care that one line at a time will
   * be processed that means it will return if it sees a \normally
   * or an EOF or an EOL
   */
  newt.c_lflag &= ~(ICANON);

  /* Those settings will now be set to STDIN TCANOW tells
   * tcsetattr to changes attributes immetiantely
   */
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);

  // go forever
  while (1) {
    ch = getchar();
    // check what the input we got was
    switch (ch) {
    case 'a': // move left
      map_pos_offset--;
      break;
    case 'd': // move right
      map_pos_offset++;
      break;
    case ' ': // jump
      isJumping = true;
      break;
    case 'p': // pause

      break;
    case 'q': // quit
      // take advantage of our function for signals but we will use it
      // for a different kind of exiting
      handle_exit(QUIT_FROM_KEYPRESS);
      break;
// if you are using a debug build
#ifdef DEBON
    case 'n': // jump to next level
      // next level
      break;
    case 'b': // go back a level
      // back a level
      break;
    case 'f': // debug function
      player_ground_row = 19;
      break;
#endif
    }
    // set char to NUL just incase
    ch = '\0';
  }
}
