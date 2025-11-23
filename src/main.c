#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<getopt.h>

#include "file_handling.h"
#include "data_handling.h"
#include "common.h"

int main(int argc, char** argv){

	int opt;
	char *filepath = NULL;
	bool newfile = false;

	while ((opt = getopt(argc ,argv , "nf:")) != -1){
		switch(opt){
			case 'n':
				newfile = true;
				break;
			case 'f':
				filepath = optarg;
				break;
			case '?':
				printf("Unknown option %c\n", opt);
				break;
			default:
				return -1;
		}
	}

	//Tests
	printf("Newfile : %d\n", newfile);
	printf("Filepath : %s\n", filepath);

	return 0;
}
