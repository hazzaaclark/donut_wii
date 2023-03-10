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

/* A RETOOL OF RADICAL'S FILE SUBSYSTEM TO JUST */
/* TAKE INTO ACCOUNT THE SCHEMA SURROUDNING THE GC/WII */

#ifndef RAD_FILE_DEFINE
#define RAD_FILE_DEFINE

#if !defined(RAD_GAMECUBE) && !defined(WII) 
#else
#endif 

#ifndef _RAD_FILE_
#define _RAD_FILE_

typedef struct RAD_FILE_CALLBACK{};
typedef struct RAD_CEMENT_LIB
{
    union
    {
        RAD_CEMENT_LIB* GET_CEMENT_CALLBACK;
        typedef RAD_CEMENT_LIB* RAD_CEMENT_COMPLETE_CALLBACK;
    };
};

typedef struct RAD_FILE{};
typedef struct RAD_DRIVE
{
    union
    {
        RAD_DRIVE* GET_DRIVE_CALLBACK;
        typedef RAD_DRIVE* RAD_DRIVE_COMPLETE_CALLBACK;
    };
};

typedef struct MEM_CARD_INFO;
typedef enum FILE_PRIORITY
{
    NONE,
    NORMAL,
    MSP
};

#endif 

/* THIS IS IN RELATION TO THE GAMECUBE AND WII'S */
/* CPU ARCHITECURE AND THE BITWISE ALIGNMENT OF THE MEMORY THAT CAN */
/* BE STORED IN RELATION TO REALTIME COMPUTATION AND CACHE */

#if defined RAD_GAMECUBE && WII
#define OPTIMAL_MEMORY_ALIGNMENT 32
#else
#define MAX_FILE_SECTOR_SIZE 2048 // MAX AMOUNT OF L2 CACHE VIA POWER PC'S ISA
#define MAX_GC_MEM_CARD_SIZE 8192 // 8MB GC MEM CARD
#endif

#define FILENAME_MAX 256 const U32
#define FILEDRIVE_MAX 16 const U32

typedef void(*FILE_SET_ROOT_DIR)(const char* DRIVE, const char* ROOT_DIR);
typedef void(*FILE_GET_ROOT_DIR)(const char* DRIVE, const char* ROOT_DIR);
typedef void(*FILE_OPEN_ASYNC)(RAD_DRIVE* RAD_DRIVE_ASYNC, const char* DRIVE_NAME, FILE_PRIORITY* FILE_PRIORITY);

#endif
#endif
