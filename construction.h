struct Pepper {
    int scoville;
    char name[256];
    struct Pepper *next;
};

void printsp(struct Pepper* p);
struct Pepper * new_pepper(char* n, int s);
void change_pepper(struct Pepper* p, char* n, int s);
void print_list(struct Pepper * node);
struct Pepper* insert_front(struct Pepper* node, char* n, int s);
struct Pepper * remove_node(struct Pepper *front, char* n, int s);
struct Pepper * free_list(struct Pepper * p);
