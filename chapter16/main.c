#include <stdio.h>
#include <string.h>
#include <stdio.h>

#define NAME_LEN (10)
#define FIRST_NAME_LEN (10)
#define LAST_NAME_LEN (10)

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
} part1 = {10, "blue", 4}, part2;

struct person_name {
    char first_name[FIRST_NAME_LEN + 1];
    char middle_initial;
    char last_name[LAST_NAME_LEN + 1];
};

struct student {
    struct person_name name;
    int id, age;
    char sex;
} student1, student2;

struct dialing_code {
    char *country;
    int code;
};

typedef struct {
    enum {INT_KIND, DOUBLE_KIND} kind;
    union {
        int i;
        double d;
    } u;
} Number;

void print_part(struct part p);
struct part build_part(int number, const char *name, int on_hand);


int main() {
    struct part inventory[100];
    part1 = build_part(528, "Disk drive", 10);


    const struct dialing_code country_codes[] = {{"Argentina", 54}, {"Bangladesh", 880}};

    
    print_part(part1);  


    return 0;
}


void print_part (struct part p) {
    printf("Part number: %d\n", p.number);
    printf("Part name: %s\n", p.name);
    printf("Quantity on hand: %d\n", p.on_hand);
}

struct part build_part(int number, const char *name, int on_hand) {
    struct part p;
    
    p.number = number;
    strcpy(p.name, name);
    p.on_hand = on_hand;
    return p;
}