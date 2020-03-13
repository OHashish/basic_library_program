#include "interface.h"
#include "book_management.h"
#include "users.h"
#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern struct BookArray library;
static void search_book_interface(){
	int choice;
	do{
	printf("\nPlease enter next action:\n1) Search by title\n2) Search by author\n3) Search by year\n4) Quit\nchoice: ");
		scanf("%d",&choice);
	
		switch (choice) {
			case 1:{
				char *titleb;
				struct BookArray newbookarray;
   				newbookarray.length=0;
   				newbookarray.array= malloc(sizeof(struct Book)); 
				titleb=(char*) malloc(15*sizeof(char));

				printf("Please enter title of book:");
				scanf("%s",titleb);

				newbookarray=find_book_by_title(titleb);
				
				if(newbookarray.array[0].title==NULL){
					printf("Book not found!");
				}
				else
				{
					for (int i=0;i<newbookarray.length;i++){
				printf("Book title: %s\n",newbookarray.array[i].title);
				printf("Book author: %s\n",newbookarray.array[i].authors);
				printf("Book year of production: %u\n",newbookarray.array[i].year);
					}
				}
				
				break;
			}
			case 2:{
				char *author;
				author=(char*) malloc(50*sizeof(char));

				struct BookArray newbookarray;
   				newbookarray.length=0;
   				newbookarray.array= malloc(sizeof(struct Book)); 

				printf("Please enter author of book:");
				scanf("%s",author);
				
				newbookarray=find_book_by_author(author);
				if(newbookarray.array[0].title==NULL){
					printf("Book not found!");
				}
				else
				{
				printf("Book title: %s\n",newbookarray.array[0].title);
				printf("Book author: %s\n",newbookarray.array[0].authors);
				printf("Book year of production: %u\n",newbookarray.array[0].year);
				}
				break;
			}
			case 3:{
				unsigned int year;

				struct BookArray newbookarray;
   				newbookarray.length=0;
   				newbookarray.array= malloc(sizeof(struct Book)); 

				printf("Please enter year of book:");
				scanf("%u",&year);

				newbookarray=find_book_by_year(year);

				if(newbookarray.array[0].title==NULL){
					printf("Book not found!");
				}
				else
				{
				printf("Book title: %s\n",newbookarray.array[0].title);
				printf("Book author: %s\n",newbookarray.array[0].authors);
				printf("Book year of production: %u\n",newbookarray.array[0].year);
				}
			 	break;
			}
			case 4:
				printf("goodbye");
				break;
			default:
				printf("Sorry, that doesn't seem to be an option\n");
		}
	}while(choice!=4);
}	
static void user_actions_interface(){
	int choice;
	printf("\nPlease enter next action:\n1) Search for book\n2) Borrow book\n3) Return Book\nchoice: ");
		scanf("%d",&choice);

		switch (choice) {
			case 1:{

				 search_book_interface();
				break;
			}
			case 2:{
				struct BookU book;
				char *username;
				book.title=(char*) malloc(30*sizeof(char));
				username=(char*) malloc(20*sizeof(char));
				

				printf("Enter book title you want to borrow:");
				scanf("%s",book.title);

				printf("Enter your username:");
				scanf("%s",username);

				borrow_book(username,book);
				break;
			}
			case 3:{	
				struct BookU book;
				char *username;
				book.title=(char*) malloc(30*sizeof(char));
				username=(char*) malloc(20*sizeof(char));
				

				printf("Enter book title you want to return:");
				scanf("%s",book.title);

				printf("Enter your username:");
				scanf("%s",username);		
				return_book(username,book);
			 	break;
			}

			default:
				printf("Sorry, that doesn't seem to be an option\n");
		}
}	
static void librarian_actions_interface(){
	int choice;
	do{
	printf("\nPlease enter next action:\n1) Add book\n2) Remove book\n3) Quit\nchoice: ");
		scanf("%d",&choice);

		switch (choice) {
			case 1:{
				struct Book book;
				book.authors=(char*) malloc(30*sizeof(char));
				book.title=(char*) malloc(30*sizeof(char));
				

				printf("Enter book title:");
				scanf("%s",book.title);

				printf("Enter book author:");
				scanf("%s",book.authors);

				printf("Enter year of production:");
				scanf("%u",&book.year);

				printf("Enter number of copies:");
				scanf("%u",&book.copies);
				 add_book(book);
				 
				break;
			}
			case 2:{
				struct Book book;
				book.authors=(char*) malloc(30*sizeof(char));
				book.title=(char*) malloc(30*sizeof(char));
				
				
				printf("Enter book title:");
				scanf("%s",book.title);

				printf("Enter book author:");
				scanf("%s",book.authors);

				printf("Enter year of production:");
				scanf("%d",&book.year);

				remove_book(book);
				break;
			}
			case 3:
			break;

			default:
				printf("Sorry, that doesn't seem to be an option\n");
		}
	}while(choice!=3);
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
					user_actions_interface();
				}
				
				break;
			}
				case 2:
				{
				char *pass;
				pass=(char*) malloc(5*sizeof(char));
				printf("Please enter Password:");

	 			scanf("%s",pass);
				if(login_librarian(pass)){
				librarian_actions_interface();
				}
				
				break;
				}
			    case 3:
				printf("goodbye");
				break;
				default:
				printf("Sorry, that doesn't seem to be an option\n");
		}
 }	

     
 void main_menu(){

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
			case 3:
			{
				printf("goodbye");
				break;
			}
			default:
				printf("Sorry, that doesn't seem to be an option\n");
		}

	} while (choice != 3);

	return;
}
void run_interface() {
	library_init();
	FILE *file;
	load_books(file);
	// printf("0:%s    ",library.array[0].title);
    //       printf("1:%s    ",library.array[1].title);
    //        printf("2:%s    ",library.array[2].title);
    //         printf("3:%s    \n",library.array[3].title);
	main_menu();
	store_books(file);

	return;
}