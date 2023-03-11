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
typedef struct RAD_DRIVE_ERROR_CALLBACK {};

typedef struct WII : RAD_DRIVE_ERROR_CALLBACK
{
	typedef void(*WII_INIT)(void);
	typedef void(*WII_SHUTDOWN)(void);
	typedef void(*WII_RESET)(void);

	/* THIS IS IN ACCORDANCE WITH THE PRE-DEFINED */
	/* SPLASH ENUM FROM THE SHAR SOURCE */

	typedef enum SPLASH
	{
		LICENSE,
		ERROR,
		FADE
	};

	typedef enum ERROR_STATE
	{
		NONE,
		CONTROLLER,
		P3D
	};

};

#ifndef POINTER_OBJECTS
#define POINTER_OBJECTS

WII::SPLASH* SPLASH_INIT();
WII::ERROR_STATE* ERROR_STATE();

#endif 

#define DISPLAY_SPLASH(VALUE, TEXT, FRAMES, POSITION, SCALE) \
static DISPLAY_SPLASH(SPLASH_INIT(), UNK_8* TEXT = NULL, U32* FADE_FRAMES = 3 = 0, F32* SCALE, F32* POS_X, F32* POS_Y));

#endif 
