/*Incomplete:
print directory path from root to the file in indentation format like a tree
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>

int main(int argc,char *argv[])
{
    struct dirent *ptr = NULL;
    int largest = 0,total = 0;
    char fname[256] = "\0";
    struct stat sobj;

    char fullPath[1024];

    snprintf(fullPath,sizeof(fullPath), "%s/%s",argv[1]);

    return 0;
}