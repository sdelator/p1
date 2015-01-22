//directory.cpp
//#include "directory.h"
#include <stdio.h>
#include <stdlib.h>
//#include "permissions.h"
#define SUBDIR 3
typedef struct Dir
{
	char *d_name[];
	int time;
	int exist_subdir;

	int *array[SUBDIR];//not sure if char or int
	struct Dir *subdir, *parent, *root; //allocate array each time make subdir
	//struct Permission *perm;
	//when array is 3 or less it reallocates memory
			
}Directory;

void createDirectory(Directory *Dire, const char *name[]);
//void showPath();

int main (void){
	Directory *D = (Directory*)malloc(sizeof(Directory));
	const char *n[1] = {"3"};
	createDirectory(D, n);	
	return 0;
}
void createDirectory(Directory *Dire, const char *name[]) {
	if(name[0] == "/"){
		Dire-> d_name = name;
		Dire-> time;
		Dire-> exist_subdir; 	 
		
	}
	//CHECK IF 3 DIR
  	if(Dire->exist_subdir == 3){
		printf("mkdir: %s already contains the maximum number of directories\n", Dire->d_name); 
		Directory *subdirectory = (Directory *) malloc (sizeof(Directory));
	} 

	else	Directory *subdirectory = (Directory *) malloc (sizeof(Directory));
		Dire-> exist_subdir ++;
	
//	char *d_name1 = malloc(strlen(name)+1);
//	strcpy(d_name1, d_name); 
		
	//initalize stuff from struct in directory.h
//	Directory main;//call
//	main.time
//	main.exist_subdirectories
	
			
//	funix->currentDirectory = (Directory*)malloc(sizeof(Directory));	
//	return directory;
}//createDirectory

/*void showPath(Directory *Dir)
{
}//showPath

//}// Directory;
//is this suppose to have the struct or does .h? 
*/
