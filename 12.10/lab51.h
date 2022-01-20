#define NAME_LEN 25

#define MAX_PARTS 100

struct part {
int number;
char name[NAME_LEN+1];
int on_hand;
};


int read_line(char str[], int n);
int find_part(int number, const struct part inv[], int np);
void insert(struct part inv[], int *np);
void search(const struct part inv[], int np);
void update(struct part inv[], int np);
void print(const struct part inv[], int np);
