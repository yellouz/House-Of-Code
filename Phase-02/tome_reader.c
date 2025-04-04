#include "tome_utils.h"

// this function copies the buffer to line then deletes what's been transmitted
// and finally returns wether a full line was read or not (1 or 0)
int CopyBufferToLine(char *buffer, char *line, int *line_index)
{
    int i = 0;
    while (buffer[i] != '\0') 
    {
        if (buffer[i] == '\n') 
        {
            // Found a newline, terminate the line and truncate the buffer
            line[*line_index] = '\0';
            i++; // Move past the newline
                
            // Truncate the buffer
            TruncateBuffer(buffer, i);
            return 1; // returns true (found new line)                
        }
            
        line[(*line_index)++] = buffer[i++];
            
        // Check for line too long
        if (*line_index >= MAX_LINE_LENGTH - 1)
        {
            line[*line_index] = '\0';
            
            // Truncate the buffer
            TruncateBuffer(buffer, i);
                
            return 1; // Line too long, return what we have
        }
    }
        
    // Clear the buffer
    buffer[0] = '\0';
    return 0; // returns false (did not found new line)
}

// this function at each call reads a full line from a file passed to it and returns it
char *tome_reader(int fd)
{
    static char buffer[BUFFER_SIZE + 1] = ""; // +1 for the null terminator
    
    // Allocate memory for the line
    char *line = malloc(sizeof(char) * MAX_LINE_LENGTH);
    if (line == NULL) 
    {
        perror("Memory allocation failed");
        return NULL;
    }
    
    int line_index = 0; // this variable will keep track of the line index where to start copying buffer to
    int found_newline = 0; // this is a boolezn variable that stores the information that we've successfully read a line or not yet
    
    // If buffer contains data from previous read copy it first
    if (buffer[0] != '\0') 
    {
        found_newline = CopyBufferToLine(buffer, line, &line_index);

        if(found_newline)
            return line;
    }
    
    // Continue reading until we find a newline or reach the end of the file
    while (!found_newline)
    {
        int bytes_read = read(fd, buffer, BUFFER_SIZE);
        
        // test if we reached the end of the file
        if (bytes_read <= 0) 
        {
            if (line_index > 0) 
            {
                line[line_index] = '\0';
                return line;
            }

            // Nothing to return
            free(line);
            return NULL;
        }

        // Ensure that the buffer terminates with '\0'
        if (bytes_read >= 0)
            buffer[bytes_read] = '\0';
        
        // Process the buffer
        found_newline = CopyBufferToLine(buffer, line, &line_index);

        if(found_newline)
            return line;
    }
    
    // This should never be reached, but just in case
    return line;
}

// this function shows a file line by line by calling tome_reader multiple times
void ProcessFile(int fd)
{
    char answer = 'y';

    while(answer == 'y' || answer == 'Y')
    {
        char *line = tome_reader(fd);

        //if line equals null it means we reached the end of the file
        if(line == NULL)
        {
            printf("\nYou finished the wisdom.\n");
            break;
        }

        printf("%s\n", line);
        free(line);

        printf("\nDo you want to seek more knowledge? [Y/N] ");
        scanf(" %c", &answer); // Notice the space before %c to consume whitespace
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    // Check if a file name was provided
    if (argc < 2) 
    {
        printf("\nUsage: %s filename\n", argv[0]);
        return 1;
    }

    int number_of_files = argc - 1;

    for(int i = 1; i <= number_of_files; i++)
    {
        char *filename = argv[i];
        int fd = open(filename, O_RDONLY); // Open the file in read mode

        if (fd == -1) 
        {
            printf("\nCould not open file : %s\n", filename);
            continue; // try to open the next file
        }

        printf("\n--------------------- Reading File %d/%d, Name : %s ---------------------\n\n", i, number_of_files, filename);
        ProcessFile(fd);
        close(fd);
    }
}