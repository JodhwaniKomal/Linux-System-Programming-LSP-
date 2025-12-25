/* Accept file name and mode from user and create the file with the mode
display fd
*/

#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>


int main(int argc,char *argv[])
{
    if(argc != 3)
    {
        printf("Invaild Number of command line arguments\n");
        return -1;
    }
    int fd = 0;
    if(strcmp(argv[2],"R") == 0)
    {
        fd = open(argv[1],O_RDONLY|O_CREAT);
    }
    else if(strcmp(argv[2],"W") == 0)
    {
         fd = open(argv[1],O_WRONLY|O_CREAT);
    }
    else if(strcmp(argv[2],"RW") == 0)
    {
         fd = open(argv[1],O_RDWR|O_CREAT);
    }
    else if(strcmp(argv[2],"A") == 0)
    {
         fd = open(argv[1],O_APPEND|O_CREAT);
    }
    else
    {
        printf("Invalid command line argument");
    }
    

    if(fd == -1)
    {
        perror("Error message");
    }
    else
    {
        printf("File opened succesfully with fd:%d\n",fd);
    }
    
    close(fd);
    return 0;
}

