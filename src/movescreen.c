#include "../include/movescreen.h"

void print_mapdata_from_curr_mappos(char *mapdata) {
	int cols = 0;
	int index = map_pos_offset;
	for(int rows = 0; rows < MAP_DATA_HEIGHT; rows++){
		for(cols = 0; cols < MAP_DATA_WIDTH; ++cols){
			printf("%c", mapdata[index]);
			if(index >= MAP_DATA_PRINT_SIZE)
				return;
			index++;
		}

		while(mapdata[index] != '-'){
			if(index >= MAP_DATA_PRINT_SIZE)
				return;
			index++;
		}
		
		if(index >= MAP_DATA_PRINT_SIZE)
			return;
		index+=map_pos_offset + 1;
		putc('\n', stdout);
	}
}
