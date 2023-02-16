/* Copyright (C) 2023 Harry Clark */

/* SDL Reimplementation/Port of The Simpsons - Hit and Run */
/* Special thanks to the following resources for making this project possible: */

/* libogc: https://github.com/devkitPro/libogc */
/* sdl-wii: https://github.com/dborth/sdl-wii */
/* GRRLIB: https://github.com/GRRLIB/GRRLIB */
/* libwiigui: https://github.com/dborth/libwiigui */

/* THIS FILE IS DEDICATED TO PROVIDING THE FOUNDATION */
/* FOR THE SCHEMA BEHIND THE WII'S PLATFORM AND HOW THE GAME */
/* WILL CORRESPOND TO THE INTERFACE OF THE CONSOLE */

/* FORTUNATELY, THE WII AND GAMECUBE ARE VERY SIMILAR ASIDE */
/* FROM THE WAY IN WHICH EACH RESPECTIVE CPU'S REGISTERS WORK */
/* WITH PARSING INFORMATION */

#ifndef WII_PLATFORM
#define WII_PLATFORM

#include "console.h"
#include "common.h"

typedef struct RAD_DRIVE; // MORE PREPRIATORY RADICAL STUFF
typedef struct RAD_DRIVE_ERROR_CALLBACK{};

typedef struct WII : RAD_DRIVE_ERROR_CALLBACK
{

};

#endif 
