//funix.cpp
#include "funix.h"
#include "directory.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void cd(Funix *funix, int argCount, const char *arguments[])
{
	//cd(funix -> currentDirectory, argCount, arguments);

}//cd
int eXit(Funix *funix, int argCount, const char *arguments[])
{
	if(argCount != 0){
	  printf("usage: exit\n");
	 
	  return 1;
	  }//if
	else{

		return 0;
	}//else
}//eXit
void getCommand(Funix *funix, char *command)
{       writePrompt(funix);
        
	fgets(command, 79, stdin);
	funix->time++;
    
}//getCommand
void init(Funix *funix) {
	funix->umask = 0;
	funix->time = 0;	
	//char *d_name[] = 0;
	
	printf("/"); //creates root dir

	funix->currentDirectory=(Directory*)malloc(sizeof(Directory));//allocate memory
	//createDirectory(funix -> currentDirectory, name);
	Directory *root = (Directory *)malloc(sizeof(Directory));
	//createDirectory(root, mask, time);
	// 
	//createDirectory(funix->currentDirectory, "/",0,0,NULL);
}//init
void ls(Funix *funix, int argCount, const char *arguments[]) {
	//ls(funix->currentDirectory, argCount, arguments);

}//ls
void mkdir(Funix *funix, int argCount, const char *arguments[])
{
	if (argCount != 1){ //if argument does not equal to 2
		printf("usage: mkdir dir_name\n");
		return;
	}//if doesnt have 1 argument
 	//else 
	//mkdir(funix->currentDirectory, arguments, funix->time++, funix umask);
	
}//mkdir
int processCommand(Funix *funix, char *command)
{	
	char *str[40];
	int i = 0;
	int argCount = 0;
	char * token =  strtok(command, " \n");

	for (int j =0; j<40; j++)
	{
		str[j]=new char [40];
	}//for
	while(token != NULL)
	{
		strcpy(str[i], token);
		token = strtok(NULL, " \n");
		i++;
		argCount++; 
	}//while
 	argCount--;
//new transfer

	const char *cmd[]= {"exit","cd","ls","mkdir","umask"};
	int cmdIndex = -1;
	for (int i =0; i < 6; i++){
		if(strcmp (str[0], cmd[i])== 0){   //compare two strings until both true
			cmdIndex = i;
			break;
		}//if
	}//for
//new 

	const char *arguments[] = {NULL}; //call here? 

	switch(cmdIndex){
		case 0: cmdIndex = eXit(funix, argCount, arguments);//calls eXit	
			break;
		case 1: cd(funix, argCount, arguments);//calls cd
			break;
		case 2: ls(funix, argCount, arguments);//calls ls
			break;
		case 3: mkdir(funix, argCount, arguments);//calls mkdir
			break;
		case 4:	umask(funix, argCount, arguments);//calls umask
			break;
	default: printf("%s :Command not found\n", str[0]);//writePrompt(funix);
 	}//switch	
	return cmdIndex;
}//processCommand
void run(Funix* funix) {
	char command[79];
 //     char command[COMMAND_LENGTH]; //Sean code no need to use malloc
	init(funix);//calls init
		
	do {
		//char* command = (char*) malloc(79);
		getCommand(funix,command);
	} while( processCommand(funix,command) );

} // run

void umask(Funix *funix, int argCount, const char *arguments[])
{
// Assuming the command doesn't count as an argument
int i;
if (argCount != 1)
printf("usage: umask octal\n");
else
{
printf("%c\n", *arguments[0]);
// Parse through value in *arguments
if (arguments[0][0] < '0'||arguments[0][0] > '7')
printf("umask: octal must be between 0 and 7\n");
else
{
i = atoi(arguments[0]);
funix->umask = i;
}//else
}//else
}//umask

void writePrompt(Funix *funix)
{	
	//showPath(funix->currentDirectory);
	printf(" # "); //prints #

}//writePrompt
