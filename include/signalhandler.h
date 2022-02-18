#ifndef SIGNALHANDLER_H_
#define SIGNALHANDLER_H_

#include "common.h"
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

extern struct termios oldt;

void handle_exit(int signum);

#endif
