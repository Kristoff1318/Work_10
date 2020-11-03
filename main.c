#include <stdlib.h>
#include <stdio.h>
#include "construction.h"
#include <time.h>
int main() {
    //First item
    struct Pepper *p = new_pepper("Bell", 100);
    print_list(p);

    //Add item
    struct Pepper *np = insert_front(p, "Pimento", 50);
    print_list(np);

    //Remove item
    struct Pepper *qp = remove_node(np, "Pimento", 50);
    print_list(qp);

    //Free list
    free_list(qp);
}
