/* Accept file name and mode and using access check if file is accessible or not
*/

#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>


int main(int argc,char *argv[])
{
    int fd = 0;
    if(strcmp(argv[2],"R") == 0)
    {
        fd = access(argv[1],R_OK);
    }
    else if(strcmp(argv[2],"W") == 0)
    {
        fd = access(argv[1],W_OK);
    }
    else if(strcmp(argv[2],"RW") == 0)
    {
         fd = access(argv[1],R_OK|W_OK);
    }
    else
    {
        printf("Invalid command line argument\n");
        return -1;
    }
    

    if(fd == -1)
    {
        printf("Not accessible:%s\n",strerror(errno));
    }
    else
    {
        printf("Accessible\n");
    }
    
    close(fd);
    return 0;
}


