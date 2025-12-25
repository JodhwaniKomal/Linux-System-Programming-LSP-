/* Accepts a file name and a string from user and writes that string in 
the given file
*/
#include<stdio.h>
#include<fcntl.h>
#include<string.h>


int main(int argc,char *argv[])
{
    int fd = 0;
    int iRet = 0;

    fd = open(argv[1],O_CREAT|O_WRONLY|O_APPEND);
    if(fd < 0)
    {
        printf("Unable to open file");
        return -1;
    }
    
    iRet = write(fd,argv[2],strlen(argv[2]));
    printf("Total number of bytes written:%d\n",iRet);
 
    return 0;
}