/* Copyright (C) 2023 Harry Clark */

/* SDL Reimplementation/Port of The Simpsons - Hit and Run */
/* Special thanks to the following resources for making this project possible: */

/* libogc: https://github.com/devkitPro/libogc */
/* sdl-wii: https://github.com/dborth/sdl-wii */
/* GRRLIB: https://github.com/GRRLIB/GRRLIB */
/* libwiigui: https://github.com/dborth/libwiigui */

/* THIS FILE DISCERNS THE ASYNCHRONOUS METHODS FOR LOADING AND UNLOADING */
/* DATA FOR FILES AS WELL AS PARSING INFORMATION ONTO THE HEAP AND STACK */

#ifndef LOADING_MANAGER
#define LOADING_MANAGER

/* NESTED INCLUDES */

#include "file_handler.h"
#include "shar_memory.h"

/* DATA INCLUDES */

#include "common.h"

#ifndef LOADING_DEFINES
#define LOADING_DEFINES

typedef U32* CEMENT_LIB_FILE_HANDLE; // NOT SURE WHAT THIS IS; SOME PREPRIATORY SHAR SOURCE LIBRARY RADICAL MUST HAVE USED
typedef U32 REQUEST_HEAD;
typedef U32 REQUEST_TAIL;

typedef struct LOADING : FILE_HANDLER
{
	typedef LOADING* GET_INSTANCE();
	typedef LOADING* CREATE_INSTANCE();
	typedef void(*DESTROY_INSTANCE);
	FILE_HANDLER::LOAD_FILE_CALLBACK* CALLBACK();
};

typedef struct PROCESS_CALLBACK
{
	typedef void ON_PROC_REQUEST_CALLBACK(void* USER_DATA);
};

#ifndef ASYNCHRONOUS
#define ASYNCHRONOUS

#define ADD_CALLBACK(void)(PROCESS_CALLBACK* PROC_CB = NULL);
#define ADD_REQUEST(void)();
#define LOAD_SYNC(void)();
#define IS_LOADING(bool);
#define GET_REQUEST_HEAD(int) const { return REQUEST_HEAD; }
#define GET_REQUEST_TAIL(int) const { return REQUEST_TAIL; }

#endif
#endif
#endif
