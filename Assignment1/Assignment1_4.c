/* Accept file name from user and display all info about file using stat
*/

#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
    int iRet = 0;
    struct stat sobj;
    
    iRet = stat(argv[1],&sobj);
    printf("File inode number:%ld\n",sobj.st_ino);
    printf("File type and mode:%ld\n",sobj.st_mode);
    printf("Number of hardlinks:%ld\n",sobj.st_nlink);
    printf("User ID of owner:%ld\n",sobj.st_uid);
    printf("Group ID of owner:%ld\n",sobj.st_gid);
    printf("Total size of file::%ld\n",sobj.st_size);
    printf("Time of last access:%d\n",sobj.st_atim);
    printf("Time of last modification:%d\n",sobj.st_mtim);
   
    return 0;
}