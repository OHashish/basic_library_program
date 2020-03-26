
#include "unity.h"
#include <stdlib.h>
#include <string.h>
#include "assert.h"
#include <stdio.h>
#include "book_management.h"
#include "library.h"
#include "users.h"

extern struct BookArray library;
extern struct BorrowArray borrow_set;
void test_add_book() {
	
	library_init();
	struct Book book;
	book.title="Mighty Ant";
	book.authors="Bob Ross";
	book.copies=345;
	book.year=1999;
	 int res;
	 res=add_book(book);
	 TEST_ASSERT_NOT_NULL_MESSAGE(book.title,"Book title is NULL");
	 TEST_ASSERT_NOT_NULL_MESSAGE(book.authors,"Book author is NULL"); 
	 TEST_ASSERT_EQUAL_INT_MESSAGE (1, library.length,"No book was added.");
	TEST_ASSERT_EQUAL_PTR_MESSAGE(library.array[library.length-1].title,book.title,"Add book added the wrong book");
	TEST_ASSERT_EQUAL_INT_MESSAGE (0, res,"error occured in add book");

}
 void test_store_books() {
	
		library_init();
		for (int i=0;i<100;i++){
			char s1[10];
			char s2[10];
			sprintf(s1,"%d",i);
			sprintf(s2,"%d",i+5);
			strcpy(library.array[i].title,"Book");
			strcat(library.array[i].title,s1);
			strcpy(library.array[i].authors,"Author");
			strcat(library.array[i].authors,s2);
			library.array[i].year=100+i;
			library.array[i].copies=i;
			library.length++;
		}
		

	FILE *fp;
	fp=fopen("../store_test_file.txt","w");
	TEST_ASSERT_NOT_NULL_MESSAGE (fp,"file returned a null pointer");
	int r =store_books(fp);
	
	TEST_ASSERT_EQUAL_INT_MESSAGE (0, r,"error occured in store books function");
}
void test_load_books() {
	library_init();
	FILE *fp;

	fp=fopen("../store_test_file.txt","r");
	TEST_ASSERT_NOT_NULL_MESSAGE (fp,"file returned a null pointer");
	int r =load_books(fp);
	
	TEST_ASSERT_EQUAL_INT_MESSAGE (0, r,"error occured in load books function");
	fp=fopen("../load_test_file.txt","w");
	TEST_ASSERT_NOT_NULL_MESSAGE (fp,"file returned a null pointer");
	
	for (int i=0;i<library.length;i++)
        {
            fprintf(fp,"%s|%s|%d|%d|\n",library.array[i].title,library.array[i].authors,library.array[i].year,library.array[i].copies);
        }
    
         fclose(fp);
}

void test_remove_book() {
	library_init();
	struct Book book;
	book.title=(char*)malloc(20*sizeof(char));
	book.authors=(char*)malloc(20*sizeof(char));
	book.title="Mighty Ant";
	book.authors="Bob Ross";
	book.copies=345;
	book.year=1999;
	add_book(book);
	 int res;
	 int length;
	 length= library.length;
	 res=remove_book(book);
	 TEST_ASSERT_NOT_NULL_MESSAGE(book.title,"Book title is NULL");
	 TEST_ASSERT_NOT_NULL_MESSAGE(book.authors,"Book author is NULL"); 
	TEST_ASSERT_EQUAL_INT_MESSAGE (length-1, library.length,"No book was removed."); 
	TEST_ASSERT_EQUAL_INT_MESSAGE (0, res,"error occured in remove book");
}
void test_find_book_title() {
	library_init();
	struct BookArray newbookarray;
    newbookarray.length=0;
    newbookarray.array= malloc(60*sizeof(struct Book)); 
    for(int i=0;i<60;i++)
        {

        newbookarray.array[i].title= (char*)malloc(50*sizeof(char)); 
        newbookarray.array[i].title= "";  
        newbookarray.array[i].authors= (char*)malloc(50*sizeof(char));     
        }
	library.array[library.length].title="Leeds";
	library.array[library.length].authors="Phillips";
	library.array[library.length].year=1980;
	library.array[library.length].copies=5;
	library.length++;
	library.array[library.length].title="London";
	library.array[library.length].authors="Phillips Brother";
	library.array[library.length].year=1999;
	library.array[library.length].copies=8;
	library.length++;

	char *title =(char*)malloc(30*sizeof(char));
	title="Leeds";
	TEST_ASSERT_NOT_NULL_MESSAGE(title,"Book title is NULL");
	
	newbookarray=find_book_by_title(title);
	TEST_ASSERT_NOT_EQUAL_MESSAGE (0, newbookarray.length,"No book was added");
	TEST_ASSERT_EQUAL_STRING_MESSAGE (library.array[0].title, newbookarray.array[0].title,"find book by title returned the wrong title");
	
}
void test_find_book_authors() {
	library_init();
	struct BookArray newbookarray;
    newbookarray.length=0;
    newbookarray.array= malloc(60*sizeof(struct Book)); 
    for(int i=0;i<60;i++)
        {

        newbookarray.array[i].title= (char*)malloc(50*sizeof(char)); 
        newbookarray.array[i].title= "";  
        newbookarray.array[i].authors= (char*)malloc(50*sizeof(char));     
        }
	library.array[library.length].title="Leeds";
	library.array[library.length].authors="Phillips,Matt,Alex Sandro";
	library.array[library.length].year=1980;
	library.array[library.length].copies=5;
	library.length++;
	library.array[library.length].title="London";
	library.array[library.length].authors="Phillips Brother";
	library.array[library.length].year=1999;
	library.array[library.length].copies=8;
	library.length++;

	char *author =(char*)malloc(30*sizeof(char));
	author="Phillips";
	TEST_ASSERT_NOT_NULL_MESSAGE(author,"Book author is NULL");
	newbookarray=find_book_by_author(author);
	TEST_ASSERT_EQUAL_STRING_MESSAGE (library.array[0].title, newbookarray.array[0].title,"find book by author returned the wrong book");
	author="Matt";
	TEST_ASSERT_NOT_NULL_MESSAGE(author,"Book author is NULL");
	TEST_ASSERT_NOT_EQUAL_MESSAGE (0, newbookarray.length,"No book was added");
	newbookarray=find_book_by_author(author);
	TEST_ASSERT_EQUAL_STRING_MESSAGE (library.array[0].title, newbookarray.array[0].title,"find book by author returned the wrong author");
	
}
void test_find_book_year() {
	library_init();
	struct BookArray newbookarray;
    newbookarray.length=0;
    newbookarray.array= malloc(60*sizeof(struct Book)); 
    for(int i=0;i<60;i++)
        {

        newbookarray.array[i].title= (char*)malloc(50*sizeof(char)); 
        newbookarray.array[i].title= "";  
        newbookarray.array[i].authors= (char*)malloc(50*sizeof(char));     
        }
	library.array[library.length].title="Leeds";
	library.array[library.length].authors="Phillips";
	library.array[library.length].year=1980;
	library.array[library.length].copies=5;
	library.length++;
	library.array[library.length].title="London";
	library.array[library.length].authors="Phillips Brother";
	library.array[library.length].year=1999;
	library.array[library.length].copies=8;
	library.length++;
	library.array[library.length].title="Coventry";
	library.array[library.length].authors="Jakson john";
	library.array[library.length].year=1999;
	library.array[library.length].copies=8;
	library.length++;

	

	newbookarray=find_book_by_year(1980);
	TEST_ASSERT_NOT_EQUAL_MESSAGE (0, newbookarray.length,"No book was added");
	TEST_ASSERT_EQUAL_STRING_MESSAGE (library.array[0].title, newbookarray.array[0].title,"find book by year returned the wrong book");
	newbookarray=find_book_by_year(1999);
	TEST_ASSERT_NOT_EQUAL_MESSAGE (0, newbookarray.length,"No book was added");
	TEST_ASSERT_EQUAL_INT_MESSAGE (library.array[1].year, newbookarray.array[0].year,"find book by year returned the wrong books");
	TEST_ASSERT_EQUAL_INT_MESSAGE (library.array[2].year, newbookarray.array[1].year,"find book by year returned the wrong books");
}

void test_register_user(){
	struct User U;
	U.username="Burger";
	U.password="King";
	int res = register_user(U);
	int result=login_user(U);
	TEST_ASSERT_NOT_NULL_MESSAGE (U.username,"Register Username is NULL");
	TEST_ASSERT_NOT_NULL_MESSAGE (U.password,"Register Password is NULL");
	TEST_ASSERT_NOT_EQUAL_MESSAGE (1, res,"Register User File returned a null pointer");
	TEST_ASSERT_EQUAL_INT_MESSAGE (0, res,"error occured in register user");
	TEST_ASSERT_EQUAL_MESSAGE (1, result,"User Wasn't registered");
	


}
void test_login_user(){
	struct User U;
	U.username="Burger";
	U.password="King";
	int result=login_user(U);
	TEST_ASSERT_NOT_NULL_MESSAGE (U.username,"Login Username is NULL");
	TEST_ASSERT_NOT_NULL_MESSAGE (U.password,"Login Password is NULL");
	TEST_ASSERT_EQUAL_MESSAGE (1, result,"User Wasn't registered");
	TEST_ASSERT_NOT_EQUAL_MESSAGE (-1, result,"login User File returned a null pointer");
	
}
void test_login_librarian(){
	int result=login_librarian("admin");
	TEST_ASSERT_NOT_EQUAL_MESSAGE (-1, result,"login librarian File returned a null pointer");
	TEST_ASSERT_EQUAL_MESSAGE (1, result,"An error occured in login librarian");
}
void test_borrow_book(){
	 borrow_set_init();
	struct Borrow book;
	book.user=(char*)malloc(40*sizeof(char));
	book.title=(char*)malloc(40*sizeof(char));
	book.user="Burger";
	book.title="The Great Book";
	int result=borrow_book(book);
	
	
	TEST_ASSERT_NOT_EQUAL_MESSAGE (-1, result,"User File returned a null pointer");
	TEST_ASSERT_EQUAL_MESSAGE (0, result,"An error occured in borrow book");
	TEST_ASSERT_NOT_EQUAL_MESSAGE (0, borrow_set.length,"No book was added");
	TEST_ASSERT_EQUAL_STRING_MESSAGE (borrow_set.array[0].title, book.title,"Borrow book borrowed wrong book");
	TEST_ASSERT_EQUAL_STRING_MESSAGE (borrow_set.array[0].user, book.user,"Borrow book borrowed for wrong user");
}
void test_return_book(){
	
	struct Borrow book;
	book.user=(char*)malloc(40*sizeof(char));
	book.title=(char*)malloc(40*sizeof(char));
	book.user="Burger";
	book.title="The Great Book";
	int result=return_book(book);
	TEST_ASSERT_EQUAL_INT_MESSAGE (1 ,result,"An error occured in return book"); 
	 result=return_book(book);
	TEST_ASSERT_EQUAL_INT_MESSAGE (0, borrow_set.length,"No book was returned");	
}
void test_store_loans(){
	borrow_set_init();
	for (int i=0;i<100;i++){
		char s1[10];
		char s2[10];
		sprintf(s1,"%d",i);
		sprintf(s2,"%d",i+5);
		strcpy(borrow_set.array[i].title,"Book");
		strcat(borrow_set.array[i].title,s1);
		strcpy(borrow_set.array[i].user,"User");
		strcat(borrow_set.array[i].user,s2);
		
			borrow_set.length++;
	}
		
	printf("%d",borrow_set.length);
	FILE *fp;
	fp=fopen("../store_loans_test_file.txt","w");
	TEST_ASSERT_NOT_NULL_MESSAGE (fp,"Store loans file returned a null pointer");
	int r =store_loans(fp);
	
	TEST_ASSERT_EQUAL_INT_MESSAGE (1, r,"Error occured in store loans function");
}
void test_load_loans(){
	borrow_set_init();
	FILE *fp;

	fp=fopen("../load_helper_test.txt","r");
	TEST_ASSERT_NOT_NULL_MESSAGE (fp,"Store loans file returned a null pointer");
	int r =load_loans(fp);
	
	TEST_ASSERT_EQUAL_INT_MESSAGE (1, r,"Error occured in load loans function");
	fp=fopen("../load_loans_test_file.txt","w");
	TEST_ASSERT_NOT_NULL_MESSAGE (fp,"Load loans file returned a null pointer");
	printf("%d",borrow_set.length);
	for (int i=0;i<borrow_set.length;i++)
        {
            fprintf(fp,"%s,%s,\n",borrow_set.array[i].title,borrow_set.array[i].user);
        }
    
         fclose(fp);
}


void setUp() {
	 //this function is called before each test, it can be empty
}

void tearDown() {
	 //this function is called after each test, it can be empty
}

int main() {
	UNITY_BEGIN();


	RUN_TEST(test_store_books);
	RUN_TEST(test_load_books);
	RUN_TEST(test_add_book);
	RUN_TEST(test_remove_book);
	RUN_TEST(test_find_book_title);
	RUN_TEST(test_find_book_authors);
	RUN_TEST(test_find_book_year);
	RUN_TEST(test_register_user);
	RUN_TEST(test_login_user);
	RUN_TEST(test_login_librarian);
	RUN_TEST(test_borrow_book);
	RUN_TEST(test_return_book);
	RUN_TEST(test_store_loans);
	RUN_TEST(test_load_loans);
	
	

	return UNITY_END();
}
