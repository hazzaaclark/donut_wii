/* Copyright (C) 2023 Harry Clark */

/* SDL Reimplementation/Port of The Simpsons - Hit and Run */
/* Special thanks to the following resources for making this project possible: */

/* libogc: https://github.com/devkitPro/libogc */
/* sdl-wii: https://github.com/dborth/sdl-wii */
/* GRRLIB: https://github.com/GRRLIB/GRRLIB */
/* libwiigui: https://github.com/dborth/libwiigui */

/* THIS FILE IS ABOUT CONSOLE DECLARATIONS FOR MEMORY MANAGEMENT, */
/* ASYNCHRONOUS FUNCTIONS, AMONGST DEFINING THE */
/* DECLARATIVES FOR THE WII'S HARDWARE */

/* FORTUNATELY, THE WII AND GAMECUBE ARE VERY SIMILAR ASIDE */
/* FROM THE WAY IN WHICH EACH RESPECTIVE CPU'S REGISTERS WORK */
/* WITH PARSING INFORMATION */

#ifndef CONSOLE
#define CONSOLE

/* NESTED INCLUDES */

#include "shar_memory.h"
#include "console_memory.h"

/* FORWARD REFERENCES */

#ifndef SHAR_DEBUG
#include "debug.h"
#include <map>
#endif

#ifndef SHAR_DEBUG
struct DEBUG_CONSOLE;
struct DEBUG_CONSOLE_CALLBACK;
#endif

#endif 
