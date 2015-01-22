//directory.cpp
#include "directory.h"
#include <stdio.h>
#include <stdlib.h>
#include "permissions.h"
#include <strings.h>
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

	Dire->d_name = *name;
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
	  strcmp("-l\n", arguments);
	  printPermissions(Dir->subdir->perm);
	}//if
}//ls

void mkdir(Directory *Dir, int argCount, const char *arguments[]){
	//CHECK IF 3 DIR
	if(Dir->exist_subdir == 3){
		printf("mkdir: %s already contains the maximum number of directories\n", Dir->d_name); 
		Directory *subdirectory = (Directory *) malloc (sizeof(Directory));
	}//if
  
	else {	Directory *subdirectory = (Directory *) malloc (sizeof(Directory)); 
		subdirectory->exist_subdir ++;
		subdirectory->d_name = *arguments;
		}//else
	
//	char *d_name1 = malloc(strlen(name)+1);
//	strcpy(d_name1, d_name); 
		
	//initalize stuff from struct in directory.h
			
//	funix->currentDirectory = (Directory*)malloc(sizeof(Directory));	

}//mkdir

void cd(Directory *Dir, int argCount, const char *arguments){
}//cd

//} Directory;
//is this suppose to have the struct or does .h? 
