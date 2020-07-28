#ifndef REQUEST_H // creation of header file
#define REQUEST_H 

struct request *append_to_list(struct request *list);
struct request *insert_to_list(struct request *list);
void update(struct request *list);
void printList(struct request *list);
void clearList(struct request *list);
int read_line(char str[], int n);

#endif //ends header