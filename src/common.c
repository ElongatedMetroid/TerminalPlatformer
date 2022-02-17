// This files stores all global variables

#include "../include/common.h"
#include <stdint.h>

// this map is 3 screens long
char *debug_map_data =
    /*--Screen 1                                                                                           --*/
    {"-123456789012345678901234567890123451234567890123456789012345678901234512345678901234567890123456789012345ABCDEFGHIJKLMNOP"
     "-2******	****	****																   								    "
     "-3******  ****    ****                                                                                                    "
     "-4            123456789                                                                                                   "
     "-5                                                                                                                        "
     "-6                                                                                                                        "
     "-7                                                                                                                        "
     "-8                                                                                                                        "
     "-9                                                                                                                        "
     "-10                                                                                                                       "
     "-11                                                                                                                       "
     "-12                                                                                                                       "
     "-13                                                                                                                       "
     "-14                                                                                                                       "
     "-15                                                                                                                       "
     "-16                                                                                                                       "
     "-17                                                                                                                       "
     "-18                                                                                                                       "
     "-19                                                                                                                       "
     "-20                                                                                                                       "
     "-21                                                                                                                       "
     "-22                                                                                                                       "
     "-23                                                                                                                       "
     "-24                                                                                                                       "
     "-25           end                                                                                                         "};

// a single thread to handle inputs
pthread_t input_thread_id = 0;

// (The _Atomic keyword allows these variables to be thread safe without using
// mutexes)
_Atomic int32_t map_pos_offset = 0;
// your position in comparison to all the map data, the bottom left
// corner of the furthest spot you can see in the whole map data
_Atomic int32_t player_pos = 0;
// where your player character is at, in consideration of the whole
// map data

void *xmalloc(size_t multiplier, size_t size) {
  void *result = calloc(multiplier, size);
  if (result == NULL)
    ERROR("error: unable to allocate memory!");
  return result;
}
