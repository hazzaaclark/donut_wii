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

#ifndef _CONSOLE_
#define _CONSOLE_

/* NESTED INCLUDES */

#include "common.h"
#include "shar_memory.h"
#include "console_memory.h"
#include "loading_manager.h"

/* FORWARD REFERENCES */

#ifndef SHAR_DEBUG
#include "debug.h"
#include <map>
#endif

#ifndef SHAR_DEBUG
typedef struct DEBUG_CONSOLE;
typedef struct DEBUG_CONSOLE_CALLBACK;
#endif

/* DATA INCLUDES */

#include "common.h"

#ifndef CONSOLE_DEFINES
#define CONSOLE_DEFINES

/* TYPE DEFINED METHODS FOR RAW POINTER REFERENCING */
/* WE ARE ABSTRACTING THE LOADING STRUCTUREW FROM THE LOADING MANAGER */
/* TO HANDLE THE ASYNCHRONOUS FILE HANDLING METHODS */

typedef struct CONSOLE : LOADING
{
	typedef CONSOLE* CREATE_INSTANCE();
	typedef CONSOLE* GET_INSTANCE();
	typedef CONSOLE* DESTROY_INSTANCE(void);

	typedef void(*CONSOLE_FUNCTION)(int argc, char** argv);
	typedef void(*CONSOLE_BOOL_FUNCTION)(int argc, char** argv);
	typedef bool ADD_FUNCTION(const UNK_8* NAME, CONSOLE_FUNCTION* FUNCTION_PTR, U32 MIN_ARGS, U32 MAX_ARGS);
	typedef bool ADD_FUNCTION(const UNK_8* NAME, CONSOLE_BOOL_FUNCTION* FUNCTION_PTR, U32 MIN_ARGS, U32 MAX_ARGS);
	typedef bool ADD_ALIAS(const UNK_8* NAME, const UNK_8* FUNCTION_NAME, int argc, char** argv[]);
	typedef void(*EXECUTE_CALLBACK_SYNC)(const UNK_8* FILE_NAME);
	typedef bool EVALUATE_BUFFER(const UNK_8* STRING, const UNK_8* SOURCE_NAME);
};

typedef enum MAX_PROC
{
	MAX_STRING_LENGTH = 256,
	MAX_FUNCTIONS = 256,
	MAX_FUNCTION_NAME = 32,
	MAX_HELP_LENGTH = 256,
	MAX_ALIAS_NAME = 32,
	MAX_ARGS = 16,
	MAX_ARG_LENGTH = 64,
	MAX_ALIASES = 32,
	MAX_BUFFERS = 16
};

typedef struct SCRIPT_CALLBACK : CONSOLE
{
	virtual void ON_EXECUTE(void* USER_DATA);
	typedef void(*EXECUTE)(const UNK_8* FILE_NAME, SCRIPT_CALLBACK* CALLBACK, void* USER_DATA);
};

/* CREATE A UNION STRUCTURE TO EVOKE */
/* THE MEMORY ALLOCATED BY THE CONSOLE STRUCTURE */

/* THESE METHODS WILL BE CALLED UPON */
/* TO ALLOW FOR THE METHODS' USAGE TO BE CARRIED OVER */
/* AND UTILISED ELSEWHERE WITH THE SAME MEMORY ADDRESS */

typedef struct FUNCTION_UNISON : CONSOLE
{
	union
	{
		CONSOLE_FUNCTION VOID_RETURN;
		CONSOLE_BOOL_FUNCTION BOOL_RETURN;
	};
};

#endif

/* PREPRIATORY RADICAL CONSOLE DEBUG SCHEMA */

#ifndef RAD_DEBUG_WIN32
#define RAD_DEBUG_WIN32

typedef void(*ADD_DEBUG)();
typedef void(*SET_DEBUG)();
typedef U32 DEBUG_LINE;

DEBUG_CONSOLE* RAD_DEBUG();
DEBUG_CONSOLE_CALLBACK* RAD_CALLBACK();

/* CONSTRUCTOR AND DESTRUCTOR METHODS */
/* AS DESCRIBED BY THE ORIGINAL SOURCE, */
/* THIS IS TO PREVENT UNWANTED INITIALISATION */
/* OF THE STRUCTURE; MY WAY OF UNDERSTANDING 
/* THIS IS THAT THIS IS TO PREVENT AN OVERFLOW 
/* IN THE HEAP */

CONSOLE* GET_CONSOLE(const CONSOLE&);
CONSOLE& DEALLOC_CONSOLE(const CONSOLE&);

#endif
#endif 
