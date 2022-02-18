#include "../include/common.h"
#include "../include/input.h"
#include "../include/signalhandler.h"
#include "../include/movescreen.h"
#include <pthread.h>
#include <signal.h>
#include <stdio.h>

int main() {
  // if we recive Ctrl+C purpously save and exit
  signal(SIGINT, handle_exit);
  // if we recive a Segmentation Fault save and exit
  signal(SIGSEGV, handle_exit);

  printf(CLEAR);
  print_mapdata_from_curr_mappos(debug_map_data);

  if (pthread_create(&input_thread_id, NULL, input_thread, NULL) != 0) {
    ERROR("Could not create input thread!\n");
  }

  while (1) {
  }
}
