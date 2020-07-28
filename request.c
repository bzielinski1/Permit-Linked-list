#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "request.h"
#include "readline.h"
#define COURSE_LEN 100
#define NAME_LEN 30
#define STATUS_LEN 30
// Blaine Zielinski, This program pompts the user to either append, update, print, or clear a student data list. Elements include courseId, studentId, name, and request status. It adds to the list using structure and dynamic memory allocation. Update can change the status of the student without moving the location. the print function prints and the clear function deallocates the memory and ends the program. 
struct request{
	char courseID[COURSE_LEN+1];
	char studentID[NAME_LEN+1];
	char first[NAME_LEN+1];
	char last[NAME_LEN+1];
	char status[STATUS_LEN+1];
	struct request *next;
};

struct request *append_to_list(struct request *list){ // append_to_list appends a new student to a list using structures, pointers, and dynamic memory

 struct request *new_request, *p, *prev;
 
  
	  new_request = malloc(sizeof(struct request)); // makes sure new_request is usable
	  if (new_request == NULL) {
	    printf("malloc failed in append_to_list\n");
	    return list;
	  }

  printf("Enter the CourseID: "); // ask user for input
  read_line(new_request->courseID, COURSE_LEN);
  printf("Enter the StudentID: ");
  read_line(new_request->studentID, NAME_LEN);

  for (p = list, prev = NULL; p != NULL && new_request->courseID > p->courseID; prev = p, p = p->next) // loop to make sure the student doesnt already exist
    if(p != NULL && strcmp(p->courseID, new_request->courseID) == 0 && strcmp(p->studentID, new_request->studentID) == 0)
    {
      free(new_request);
      printf("Student already found");
      return list;
    }  
  printf("Enter the student's first name: "); // ask user for rest of input
  read_line(new_request->first, NAME_LEN);
  printf("Enter the student's last name: ");
  read_line(new_request->last, NAME_LEN);
  strcpy(new_request->status, "Pending");
  
  new_request->next = p;
  
  
  if(prev == NULL) // if statement to append the student in the correct location
    return new_request;
  else{    
    prev->next = new_request;
    return list;  
   }
 return NULL;

}

void update(struct request *list){ // update function finds the structure and updates the status variable inside the structure

  char courseID[COURSE_LEN]; //creation of variables
  char studentID[NAME_LEN];

  printf("Enter the courseID: "); // ask for user input
  read_line(courseID, COURSE_LEN);
  printf("Enter the studentID: ");
  read_line(studentID, NAME_LEN);
  for(; list != NULL; list = list->next) // finds the student in the list
    if(strcmp(list->courseID, courseID) == 0 && strcmp(list->studentID, studentID) == 0)
    {
      printf("Enter the student's status: ");
      read_line(list->status, STATUS_LEN);
      break;
    }
    if(list == NULL) // if the student isnt found
    {
      printf("Child not found.");
    }
}

struct request *insert_to_list(struct request *list){ // insert_to_list appends a new student to a list using structures, pointers, and dynamic memory

 struct request *new_request, *cur, *prev;


	  new_request = malloc(sizeof(struct request)); // makes sure new_request is usable
	  if (new_request == NULL) {
	    printf("malloc failed in append_to_list\n");
	    return list;
	  }

  printf("Enter the CourseID: "); // ask user for input
  read_line(new_request->courseID, COURSE_LEN);
  printf("Enter the StudentID: ");
  read_line(new_request->studentID, NAME_LEN);

  for(cur = list, prev = NULL; cur != NULL && strcmp(new_request->courseID, cur->courseID) > 0; prev = cur, cur = cur->next); // loop to make sure courseID is in the correct alphabetical location

  if(cur != NULL && strcmp(new_request->courseID, cur->courseID) == 0){ //checks if two students are in the same course
  for(;cur != NULL && strcmp(new_request->studentID, cur->studentID) > 0; prev = cur, cur = cur->next){ //loop to insert node into correct alphabetical location by stuentID
     if(strcmp(new_request->courseID, cur->courseID)!=0)//stops the loop when it reaches the end of the course section
            break;
  }
  }
  printf("Enter the student's first name: "); // ask user for rest of input
  read_line(new_request->first, NAME_LEN);
  printf("Enter the student's last name: ");
  read_line(new_request->last, NAME_LEN);
  strcpy(new_request->status, "Pending");

 new_request->next = cur;
 if(prev == NULL)
    return new_request;
 else{
    prev->next = new_request;
    return list;
    }

}

void printList(struct request *list){ // function simply prints the values in array of structures

  struct request *p;

  for(p = list; p!=NULL; p = p->next) { //loops through the list 
        printf("%s ", p->courseID); // prints the values
        printf(" %s ", p->studentID);
        printf(" %s ", p->first);
        printf(" %s ", p->last);
        printf(" %s \n", p->status);
    }

}


void clearList(struct request *list) // emptys the memory after user quits the program
{
 struct request *p;
  while(list != NULL) // loops through the list
  {
	   p = list;
     list = list->next;
     if( p!= NULL)
           free(p); // frees up the memory 
  }

}