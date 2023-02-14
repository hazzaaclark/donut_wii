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

typedef struct LOADING : FILE_HANDLER
{
	typedef LOADING* GET_INSTANCE();
	typedef LOADING* CREATE_INSTANCE();
	typedef void(*DESTROY_INSTANCE);
	FILE_HANDLER::LOAD_FILE_CALLBACK* CALLBACK();
};

#endif 

#endif 
