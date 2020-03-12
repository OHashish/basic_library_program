
#include "unity.h"
#include <stdlib.h>
#include <string.h>
#include "assert.h"
#include "stdio.h"
#include "book_management.h"


void test_a_function() {
		//  FILE *fp;

		//  fp=fopen("lmao","w");
		// int r =store_books(fp);
		// TEST_ASSERT_NOT_NULL_MESSAGE (fp,"file returened a null pointer")
		// TEST_ASSERT_EQUAL_INT_MESSAGE (0, r,"error occured");
}

void setUp() {
	 //this function is called before each test, it can be empty
}

void tearDown() {
	 //this function is called after each test, it can be empty
}

int main() {
	UNITY_BEGIN();


	RUN_TEST(test_a_function);

	return UNITY_END();
}
