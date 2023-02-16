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
	typedef bool ADD_FUNCTION(const char* NAME, CONSOLE_FUNCTION* FUNCTION_PTR, U32 MIN_ARGS, U32 MAX_ARGS);
	typedef bool ADD_FUNCTION(const char* NAME, CONSOLE_BOOL_FUNCTION* FUNCTION_PTR, U32 MIN_ARGS, U32 MAX_ARGS);
	typedef bool ADD_ALIAS(const char* NAME, const char* FUNCTION_NAME, int argc, char** argv[]);
	typedef void(*EXECUTE_CALLBACK_SYNC)(const char* FILE_NAME);
	typedef bool EVALUATE_BUFFER(const char* STRING, const char* SOURCE_NAME);
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
	typedef void(*EXECUTE)(const char* FILE_NAME, SCRIPT_CALLBACK* CALLBACK, void* USER_DATA);
};

#endif

/* PREPRIATORY RADICAL CONSOLE DEBUG SCHEMA */

#ifndef RAD_DEBUG_WIN32
#define RAD_DEBUG_WIN32

typedef void(*ADD_DEBUG)();
typedef void(*SET_DEBUG)();
typedef int DEBUG_LINE;

DEBUG_CONSOLE* RAD_DEBUG();
DEBUG_CONSOLE_CALLBACK* RAD_CALLBACK();

#endif
#endif 
