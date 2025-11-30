#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "file_handling.h"
#include "common.h"

int create_database_file(char *filepath) {
	//Verify if the file does not already exist
	int fd = open(filepath, O_RDONLY);
	if(fd != -1){
		close(fd);
		printf("The file already exists.\n");
		return STATUS_ERROR;
	}

	//Open file as read-write in create mode with permissions -rw-r--r-- 
	fd = open(filepath, O_RDWR | O_CREAT, 0644);
	if (fd == -1){
		perror("open");
		 return STATUS_ERROR;
	}

	return fd;
}



int open_database_file(char *filepath) {
	int fd = open(filepath, O_RDWR, 0644);
	if (fd == -1){
		perror("open");
		 return STATUS_ERROR;
	}

	return fd;	
}
