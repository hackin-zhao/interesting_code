/*****************************************************************************
*                                                                            *
*  ex-1.c                                                                    *
*  ======                                                                    *
*                                                                            *
*  Description: Illustrates using a linked list (see Chapter 5).             *
*                                                                            *
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

#pragma pack(4)
typedef  struct  bodyDef_
{
	char name[9];
	char id;
	int  age;
}bodyDef;


bodyDef *body;
/*****************************************************************************
*                                                                            *
*  ------------------------------ print_list ------------------------------  *
*                                                                            *
*****************************************************************************/

static void print_list(const List *list) {

ListElmt           *element;

int                *data,
                   i;

bodyDef *body;
/*****************************************************************************
*                                                                            *
*  Display the linked list.                                                  *
*                                                                            *
*****************************************************************************/

fprintf(stderr, "int:%d\n", sizeof(int));
fprintf(stdout, "char:%d\n", sizeof(char));


fprintf(stdout, "List size is %d\n", list_size(list));

i = 0;
element = list_head(list);

while (1) {

   body = list_data(element);

   fprintf(stdout, "bodyDef:%d\n", sizeof(bodyDef));
	fprintf(stdout, "body:%p\n", body);
	fprintf(stdout, "body:%p\n", &body[0]);
	fprintf(stdout, "body:%p\n", &(body -> name[0]));
	fprintf(stdout, "body:%p\n", &(body -> name[8]));
	fprintf(stdout, "body:%p\n", &(body -> id));

	fprintf(stdout, "test:%p\n", (&(body -> name[0])+9));
	fprintf(stdout, "test:%d\n", *(&(body -> name[0])+9));
	fprintf(stdout, "body:%d\n", (body -> id));

   fprintf(stdout, "list[%03d]=%c,%d,%ld\n", i, body -> name,body -> age,sizeof(bodyDef));

   i++;

   if (list_is_tail(element))
      break;
   else
      element = list_next(element);

}

return;

}



/*****************************************************************************
*                                                                            *
*  --------------------------------- main ---------------------------------  *
*                                                                            *
*****************************************************************************/

int main(int argc, char **argv) {

List               bodylist;
ListElmt           *element;

int                *data,
                   i;

bodyDef *body;
/*****************************************************************************
*                                                                            *
*  Initialize the linked list.                                               *
*                                                                            *
*****************************************************************************/

list_init(&bodylist, free);

/*****************************************************************************
*                                                                            *
*  Perform some linked list operations.                                      *
*                                                                            *
*****************************************************************************/

element = list_head(&bodylist);

for (i = 10; i > 0; i--) {

   if ((body = (bodyDef *)malloc(sizeof(bodyDef))) == NULL)
      return 1;

   body -> name[9] = "abcdefghi";
   body -> id = 1;
   body -> age = i;

   if (list_ins_next(&bodylist, NULL, body) != 0)
      return 1;

}

print_list(&bodylist);

// element = list_head(&bodylist);

// for (i = 0; i < 7; i++)
//    element = list_next(element);

// data = list_data(element);
// fprintf(stdout, "Removing an element after the one containing %03d\n", *data);

// if (list_rem_next(&bodylist, element, (void **)&data) != 0)
//    return 1;

// print_list(&bodylist);

// fprintf(stdout, "Inserting 011 at the tail of the list\n");

// *data = 11;
// if (list_ins_next(&list, list_tail(&list), data) != 0)
//    return 1;

// print_list(&list);

// fprintf(stdout, "Removing an element after the first element\n");

// element = list_head(&list);
// if (list_rem_next(&list, element, (void **)&data) != 0)
//    return 1;

// print_list(&list);

// fprintf(stdout, "Inserting 012 at the head of the list\n");

// *data = 12;
// if (list_ins_next(&list, NULL, data) != 0)
//    return 1;

// print_list(&list);

// fprintf(stdout, "Iterating and removing the fourth element\n");

// element = list_head(&list);
// element = list_next(element);
// element = list_next(element);

// if (list_rem_next(&list, element, (void **)&data) != 0)
//    return 1;

// print_list(&list);

// fprintf(stdout, "Inserting 013 after the first element\n");

// *data = 13;
// if (list_ins_next(&list, list_head(&list), data) != 0)
//    return 1;

// print_list(&list);

// i = list_is_head(&list, list_head(&list));
// fprintf(stdout, "Testing list_is_head...Value=%d (1=OK)\n", i);
// i = list_is_head(&list, list_tail(&list));
// fprintf(stdout, "Testing list_is_head...Value=%d (0=OK)\n", i);
// i = list_is_tail(list_tail(&list));
// fprintf(stdout, "Testing list_is_tail...Value=%d (1=OK)\n", i);
// i = list_is_tail(list_head(&list));
// fprintf(stdout, "Testing list_is_tail...Value=%d (0=OK)\n", i);

// /*****************************************************************************
// *                                                                            *
// *  Destroy the linked list.                                                  *
// *                                                                            *
// *****************************************************************************/

// fprintf(stdout, "Destroying the list\n");
// list_destroy(&list);

return 0;

}
