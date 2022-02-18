#include "../include/input.h"
#include <unistd.h>

void *input_thread(void *ptr) {
  static struct termios newt;
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

  while (1) {
    ch = getchar();
    if (ch == 'a') { // move left
      map_pos_offset--;
	  printf(CLEAR);
	  print_mapdata_from_curr_mappos(debug_map_data);
    }
    if (ch == 'd') { // move right
      map_pos_offset++;
	  printf(CLEAR);
	  print_mapdata_from_curr_mappos(debug_map_data);
	}
	ch = '\0';
  }
}
