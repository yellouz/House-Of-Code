#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024 // Define a reasonable maximum line length

// my str_len function from phase 01
int my_strlen(const char *str)
{
    int i = 0;
    while (str[i++]);

    return i-1;
}

// if the name sounds confusing, basically this function just shifts all the characters one position to the left, removing the first character
void TruncateBufferOnce(char *buffer)
{
    if(buffer == NULL)
        return;

    int BufferLength = my_strlen(buffer);

    for(int i = 0; i < BufferLength; i++)
        buffer[i] = buffer[i+1];
}

// just calls the TrncateBufferOnce function multiple times
void TruncateBuffer(char *buffer, int truncate_count)
{
    for(int i = 0; i < truncate_count; i++)
        TruncateBufferOnce(buffer);
}