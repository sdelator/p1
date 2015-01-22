//directory.cpp
#include "directory.h"
#include <stdio.h>
#include <stdlib.h>
#include "permissions.h"
#include <string.h>
/*
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

void createDirectory(Directory *Dir);
void showPath();
*/
void createDirectory(Directory *Dire, const char *name[], int time, int umask) {

	strncpy(*(Dire->d_name),*name,strlen(*name));
	Dire->time = time;
	Dire->exist_subdir = 0;
	Permissions *permissions=(Permissions*)malloc(sizeof(Permissions));
	createPermissions(permissions, umask); 	
	 
}//createDirectory

void showPath(Directory *Dir)
{
}//showPath

void ls(Directory *Dir,int argCount,const char *arguments[]){
	if(argCount == 1){
	  strcmp("-l\n", *arguments);
	 // printPermissions(Dir->subdir->perm);
	}//if
}//ls

void mkdir(Directory *Dir, int argCount, const char *arguments[]){
	// if there are multiple arguments
	if (argCount != 1)
		printf("usage: mkdir directoryName");
	else {
		//CHECK IF 3 DIR
		if(Dir->exist_subdir == 3){
			printf("mkdir: %s already contains the maximum number of directories\n", Dir->d_name); 
			Directory *subdirectory = (Directory *) malloc (sizeof(Directory));
		}//if
  
		else {	Directory *subdirectory = (Directory *) malloc (sizeof(Directory)); 
			subdirectory->exist_subdir ++;
//			subdirectory->d_name = *arguments;
		}//else
	

	}//else
}//mkdir

void cd(Directory *Dir, int argCount, const char *arguments){
	if (argCount != 1)
		printf("usage: cd directoryName\n");
	else
	{

		if ((strcmp(*(Dir->d_name), arguments)) == 0) //need if statement
		{
			//change directory
		}//if
		else
			printf("cd: %s: No such file or directory.\n", arguments[0]);
		// if argument isn't a child or a parent print ^
		//if (arguments != 
		// else 
		Dir = Dir->subdir[0];
	}
}//cd

