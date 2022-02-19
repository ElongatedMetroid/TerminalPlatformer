#include "../include/common.h"
#include "../include/draw.h"
#include "../include/input.h"
#include "../include/movescreen.h"
#include "../include/signalhandler.h"
#include <pthread.h>
#include <signal.h>
#include <stdio.h>

int main() {
  pthread_t input_thread_id = 0, draw_thread_id = 0;

  // if we recive Ctrl+C purpously save and exit
  signal(SIGINT, handle_exit);
  // if we recive a Segmentation Fault save and exit
  signal(SIGSEGV, handle_exit);

  printf(CLEAR);
  print_mapdata_from_curr_mappos(debug_map_data);

  if (pthread_create(&input_thread_id, NULL, input_thread, NULL) != 0)
    ERROR("Could not create input thread!\n");

  if (pthread_create(&draw_thread_id, NULL, draw_thread, debug_map_data) != 0)
    ERROR("Could not create draw thread!\n");

  pthread_join(input_thread_id, NULL);
  pthread_join(draw_thread_id, NULL);
  pthread_exit(NULL);
}
