/* Copyright (C) 2023 Harry Clark */

/* SDL Reimplementation/Port of The Simpsons - Hit and Run */
/* Special thanks to the following resources for making this project possible: */

/* libogc: https://github.com/devkitPro/libogc */
/* sdl-wii: https://github.com/dborth/sdl-wii */
/* GRRLIB: https://github.com/GRRLIB/GRRLIB */
/* libwiigui: https://github.com/dborth/libwiigui */

/* THIS FILE IS FOR MANAGING AND HANDLING FILES */
/* TO IMPLEMENT CUSTOM HANDLES FOR LOADING SPECIFIC FILE TYPES */
/* (as indicative by the source code; thanks Radical) */

#ifndef _FILE_HANLDER_
#define _FILE_HANDLER_

/* NESTED INCLUDES */

#include "shar_memory.h"
#include "common.h"

#ifndef FILE_DEFINES
#define FILE_DEFINES

typedef struct FILE_HANDLER
{
	FILE_HANDLER* REF_COUNT();
	typedef struct LOAD_FILE_CALLBACK;
};

typedef enum FILE_HANDLE_ENUM
{
    FILEHANDLER_PURE3D,
    FILEHANDLER_LEVEL,
    FILEHANDLER_MISSION,
    FILEHANDLER_ANIMATION,
    FILEHANDLER_CHOREO,
    FILEHANDLER_CONSOLE,
    FILEHANDLER_SCROOBY,
    FILEHANDLER_SOUND,
    FILEHANDLER_TEMP,
    FILEHANDLER_ICON,
    NUM_FILEHANDLERS
};

#endif 
#endif