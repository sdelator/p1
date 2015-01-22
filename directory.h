//directory.h
#ifndef DIRECTORY_H
  #define DIRECTORY_H
#include <stdlib.h>//for malloc
#define SUBDIR 3
#include "permissions.h"

typedef struct Dir
{
	char *d_name[];
	int time;
	int exist_subdir;

	int *array[SUBDIR];//not sure if char or int
	struct Dir *subdir, *parent, *root; //allocate array each time make subdir
	struct Permission *perm;
	//when array is 3 or less it reallocates memory
			
}Directory;

void createDirectory(Directory *Dir,const char name);
void showPath(Directory *Dir);
void ls(Directory *Dir, int argCount, const char *arguments);
void mkdir(Directory *Dir, int argCount, const char *arguments);
void cd(Directory *Dir, int argCount, const char *arguments);

#endif
