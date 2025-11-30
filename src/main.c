#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<getopt.h>

#include "file_handling.h"
#include "data_handling.h"
#include "common.h"

void command_usage(char** argv){
	printf("Usage: %s -n -f <database file>\n", argv[-1]);
	printf("\t -n  -  create a new database file\n");
	printf("\t -f  -  (required) path to the database file\n");
}

/* 
 * Arguments :
 * 
 * - db_fd :
 *   	> Type : int
 *   	> Purpose : database file descriptor
 * 	
 * - flag :
 *   	> Type : int
 *   	> Purpose : 
 *
 * - newfile :
 *   	> Type : bool
 *   	> Purpose : defines whether a new database file should be created
 *
 * - filepath :
 *   	> Type : char
 *   	> Purpose : location of the database file
 *
 * */
int main(int argc, char** argv){

	int flag;
	char *filepath = NULL;
	bool newfile = false;
	int db_fd = -1;
	
	//Flag handling
	while ((flag = getopt(argc ,argv , "nf:")) != -1){
		switch(flag){
			case 'n':
				newfile = true;
				break;
			case 'f':
				filepath = optarg;
				break;
			case '?':
				printf("Unknown option %c\n", flag);
				break;
			default:
				return -1;
		}
	}
	
	//NULL filepath error handling
	if(filepath == NULL){
		printf("Filepath is a required argument.\n");
		command_usage(argv);		
	}

	if(newfile){
		db_fd = create_database_file(filepath);	
		if (db_fd == STATUS_ERROR){
			printf("Unable to create database file %s.\n", filepath);
			return -1;
		}
	} else {
		db_fd = open_database_file(filepath);
		if (db_fd == STATUS_ERROR){
			printf("Unable to open database file %s.\n", filepath);
			return -1;
		}
	}


	return 0;
}
