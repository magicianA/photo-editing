#ifndef DEBUG_H
#define DEBUG_H

#include<stdio.h>

#define LOG_DIR "log.txt"
#define PREPARE_DEBUG FILE *DEBUG_FILE
#define BEGIN_DEBUG DEBUG_FILE = fopen(LOG_DIR,"a+")
#define LOG(x,y) fprintf(DEBUG_FILE,x,y)
#define LOG3(x,y,z) fprintf(DEBUG_FILE,x,y,z)
#define LOG4(a,b,c,d) fprintf(DEBUG_FILE,a,b,c,d)
#define END_DEBUG fclose(DEBUG_FILE)


#endif