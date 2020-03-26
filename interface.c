#include "interface.h"
#include "book_management.h"
#include "users.h"
#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern struct BookArray library;
extern struct BorrowArray borrow_set;
static void search_book_interface(){
	int choice;
	do{
	printf("\nPlease enter next action:\n1) Search by title\n2) Search by author\n3) Search by year\n4) Go Back\nchoice: ");
		scanf("%d",&choice);
	
		switch (choice) {
			case 1:{
				char *titleb;
				struct BookArray newbookarray;
   				newbookarray.length=0;
   				newbookarray.array= malloc(sizeof(struct Book)); 
				titleb=(char*) malloc(100*sizeof(char));

				printf("Please enter title of book:");
				fgetc(stdin);
				fgets(titleb,100,stdin);
			//	scanf("%s",book.title);
				int len =strlen(titleb);
				
				titleb[len-1]='\0';

				newbookarray=find_book_by_title(titleb);
				
				if(newbookarray.length==0){
					printf("\nBook not found!\n");
				}
				else
				{
					for (int i=0;i<newbookarray.length;i++){
				printf("\nBook title: %s\n",newbookarray.array[i].title);
				printf("Book author: %s\n",newbookarray.array[i].authors);
				printf("Book year of production: %u\n",newbookarray.array[i].year);
					}
				}
				
				break;
			}
			case 2:{
				char *author;
				author=(char*) malloc(100*sizeof(char));

				struct BookArray newbookarray;
   				newbookarray.length=0;
   				newbookarray.array= malloc(sizeof(struct Book)); 
				

				printf("Please enter author of book:");
				// scanf("%s",author);
				fgetc(stdin);
				fgets(author,100,stdin);
				
				int len =strlen(author);
				
				author[len-1]='\0';
				
				newbookarray=find_book_by_author(author);
				if(newbookarray.array[0].year==0){
					printf("\nBook not found!\n");
				}
				else
				{
				for (int i=0;i<newbookarray.length;i++){
				printf("\nBook title: %s\n",newbookarray.array[i].title);
				printf("Book author: %s\n",newbookarray.array[i].authors);
				printf("Book year of production: %u\n",newbookarray.array[i].year);
					}
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

				if(newbookarray.array[0].year==0){
					printf("\nBook not found!\n");
				}
				else
				{
				for (int i=0;i<newbookarray.length;i++){
				printf("\nBook title: %s\n",newbookarray.array[i].title);
				printf("Book author: %s\n",newbookarray.array[i].authors);
				printf("Book year of production: %u\n",newbookarray.array[i].year);
					}
				}
			 	break;
			}
			case 4:
				printf("\nGoodbye\n");
				break;
			default:
				printf("Sorry, that doesn't seem to be an option\n");
		}
	}while(choice!=4);
}	
static void user_actions_interface(){
	int choice;
	do {
	printf("\nPlease enter next action:\n1) Search for book\n2) Borrow book\n3) Return Book\n4) Log Out\nchoice: ");
		scanf("%d",&choice);

		switch (choice) {
			case 1:{

				 search_book_interface();
				break;
			}
			case 2:{
				struct Borrow Book;
				
				Book.title=(char*) malloc(100*sizeof(char));
				Book.user=(char*) malloc(50*sizeof(char));
				

				printf("Enter book title you want to borrow:");
				fgetc(stdin);
				fgets(Book.title,100,stdin);
				int len =strlen(Book.title);
				
				Book.title[len-1]='\0';
				printf("Enter your username:");
				scanf("%s",Book.user);
				if((find_book_by_title(Book.title).length==0))
				{
					printf("\nBook not found!\n");
				}
				else
				{
					if(borrow_book(Book)==0)
					printf("\nBook Borrowed.Enjoy!\n");
					else
					{
						printf("\nUsername not found!!\n");
					}
					
				}

				
				break;
			}
			case 3:{	
				struct Borrow Book;
				
				Book.title=(char*) malloc(100*sizeof(char));
				Book.user=(char*) malloc(50*sizeof(char));
				

				printf("Enter book title you want to return:");
				fgetc(stdin);
				fgets(Book.title,50,stdin);
				int len =strlen(Book.title);
				
				Book.title[len-1]='\0';

				printf("Enter your username:");
				scanf("%s",Book.user);

				if(return_book(Book))	
				printf("\nBook Returned.\n");
				else
				printf("\nUser didn't borrow a book.\n");
					
				
			 	break;
			}
			case 4:
			break;
			default:
				printf("Sorry, that doesn't seem to be an option\n");
		}
	}while(choice!=4);
}	
static void librarian_actions_interface(){
	int choice;
	do{
	printf("\nPlease enter next action:\n1) Add book\n2) Remove book\n3) Quit\nchoice: ");
		scanf("%d",&choice);

		switch (choice) {
			case 1:{
				struct Book book;
				book.authors=(char*) malloc(100*sizeof(char));
				book.title=(char*) malloc(100*sizeof(char));
				

				printf("Enter book title:");
				fgetc(stdin);
				fgets(book.title,100,stdin);
			//	scanf("%s",book.title);
				int len =strlen(book.title);
				
				book.title[len-1]='\0';
				

				printf("Enter book author:");
				
				fgets(book.authors,100,stdin);
				 len =strlen(book.authors);
				
				book.authors[len-1]='\0';
				

				printf("Enter year of production:");
				scanf("%u",&book.year);

				printf("Enter number of copies:");
				scanf("%u",&book.copies);
				 if(add_book(book)==0)
				 printf("\nBook Added Successfully.\n");
				 
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
				
				if(remove_book(book)==0){
					printf("\nBook Removed Successfully.\n");
				}
				else
				{
					printf("\nBook Not Found.\n");
				}
				
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

	if(register_user(u)==0){
		printf("\nRegistered successfully!!!\n");
	}
	
	
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
					printf("\nSuccess!!\n");
					user_actions_interface();
				}
				else
				{
				printf("\nNot registered.\n");
				}
				
				break;
			}
				case 2:
				{
				char *pass;
				pass=(char*) malloc(30*sizeof(char));
				printf("Please enter Password:");

	 			scanf("%s",pass);
				if(login_librarian(pass)){
					printf("\nWELCOME!\n");
				librarian_actions_interface();
				}
				else{
					printf("\nIncorrect Password\n");
				}
				break;
				}
			    case 3:
				printf("\nGoodbye\n");
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
				printf("\nGoodbye\n");
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
	borrow_set_init();
	FILE *file;
	
	file=fopen("../books.txt", "r");
	load_books(file);
	file=fopen("../book_loan.txt", "r");
	load_loans(file);
	main_menu();
	file=fopen("../books.txt","w");
	store_books(file);
	file=fopen("../book_loan.txt", "w");
	store_loans(file);

	return;
}