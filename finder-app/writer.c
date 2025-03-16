#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <syslog.h>


int main(int argc, const char *argv[])
{
    openlog("writer", LOG_PID, LOG_USER); 


    if(argc != 3)
    {   
        syslog(LOG_ERR, "Usage: ./writer <filedir> <filestr>");
        fprintf(stderr, "Usage: ./writer <filedir> <filestr>\n");
        closelog(); 
        return EXIT_FAILURE; 
    }

    const char *filedir = argv[1]; 
    const char *filestr = argv[2]; 

    FILE *file = fopen(filedir, "w"); 
    if(!file)
    {
        syslog(LOG_ERR, "Error opening file: %s", filedir); 
        perror("Error opening file"); 
        closelog(); 
        return EXIT_FAILURE; 
    }

    if(fprintf(file, "%s", filestr) < 0 )
    {
        syslog(LOG_ERR, "Error writing to file"); 
        perror("Error writing to file"); 
        fclose(file); 
        closelog(); 
        return EXIT_FAILURE; 
    }

    fclose(file); 

    syslog(LOG_DEBUG, "Writing \"%s\" to \"%s\" ", filestr, filedir);

    closelog(); 

    return EXIT_SUCCESS; 
}