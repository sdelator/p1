//permissions.h

#ifndef PERMISSIONS_H
#define PERMISSIONS_H
typedef struct{
short umask_val;
}Permissions;
void createPermissions(Permissions *permissions, int octal);
void printPermissions(Permissions *permissions);
#endif
