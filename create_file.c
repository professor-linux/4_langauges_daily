#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

// Need to add a \n after the text


int main(int argc, char *argv[]){

	if (argc < 3) {
	   fprintf(stderr, "Usage: %s <filename> <text>\n", argv[0]);
	   return 1;
	}

	char *filename = argv[1];
	char *text = argv[2];
        size_t length = strlen(text);

	if( access(filename, F_OK) == 0){
		printf("%s exists, appending to file.\n",argv[1]);
	        int result = open(filename, O_WRONLY | O_APPEND, 0644);
	        size_t bw = write(result, text, length);
	        printf("Bytes Written %ld\n", bw);
		close(result);	

		FILE *file = open(filename, "ab")
		fputc('\n',file);
		fputc('\0',file);
		fclose(file);
	}
	else {
	     int result = open(filename, O_CREAT | O_RDWR);
             size_t bw = write(result, text, length);
             printf("Bytes Written %ld\n", bw);
	     close(result);

	}

	return 0;
}
