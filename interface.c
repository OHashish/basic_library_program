#include "interface.h"
#include "book_management.h"
#include "users.h"
#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static void user_actions(){
	int choice;
	printf("\nPlease enter next action:\n1) Search for book\n2) Return book\n3) Borrow Book\nchoice: ");
		scanf("%d",&choice);

		switch (choice) {
			case 1:{

				 search_book();
				break;
			}
			case 2:{
				 borrow_book();
				break;
			}
			case 3:{			
				 return_book();
			 	break;
			}
			case 4:
				printf("goodbye\n");
				break;
			default:
				printf("Sorry, that doesn't seem to be an option\n");
		}
}	
 static void register_user_interface(){

	 struct User u;
	 u.username=(char*) malloc(20*sizeof(char));
	 u.password=(char*) malloc(20*sizeof(char));
	 
	 printf("Please enter Username:");

	 scanf("%s",u.username);
	 
	
	 printf("Please enter Password:");

	 scanf("%s",u.password);

	register_user(u);
	
 }
 static void login_interface(){
	 int choice;
	 	printf("\nPlease enter next action:\n1) User login\n2) Librarian login\n3) Quit\nchoice: ");
		scanf("%d",&choice);

		switch (choice) {
			case 1:{
				struct User u;
				u.username=(char*) malloc(20*sizeof(char));
				u.password=(char*) malloc(20*sizeof(char));
	 
				printf("Please enter Username:");

	 			scanf("%s",u.username);
	 
	
	 			printf("Please enter Password:");

	 			scanf("%s",u.password);
	 

				if(login_user(u)==1){
					user_actions();
				}
				
				break;
			}
				case 2:
				{
				char *pass;
				pass=(char*) malloc(5*sizeof(char));
				printf("Please enter Password:");

	 			scanf("%s",pass);
				login_librarian(pass);
				break;
				}
			    case 3:
				printf("goodbye\n");
				break;
				default:
				printf("Sorry, that doesn't seem to be an option\n");
		}
 }	

     
static void main_menu() {

	int choice; //exit

	do {

		printf("\nPlease enter next action:\n1) Register\n2) Login\n3) Quit\nchoice: ");
		scanf("%d",&choice);

		switch (choice) {
			case 1:
				register_user_interface();
				break;
			case 2:
				login_interface();
				break;
			// case 3:
			// 	search_book_interface();
			// 	break;
			case 3:
				printf("goodbye\n");
				break;
			default:
				printf("Sorry, that doesn't seem to be an option\n");
		}

	} while (choice != 3);

	return;
}
void run_interface() {

	main_menu();
	

	return;
}