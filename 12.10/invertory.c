#include <stdio.h>
#include <stdlib.h>
#include "lab51.h" // 请不要删除本行头文件，否则检查不通过

int main(void)
{
  int num_parts;
  struct part inventory[MAX_PARTS];
   
  char code;

  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n');  /* skips to end of line */
    switch (code) {
      case 'i': insert(inventory,&num_parts);
                break;
      case 's': search(inventory,num_parts);
                break;
      case 'u': update(inventory,num_parts);
                break;
      case 'p': print(inventory,num_parts);
                break;
      case 'q': return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
  return 0;
} 

void insert(struct part inv[], int *np){
    if((*np) == MAX_PARTS){
      printf("Database is full; can't add more parts.\n");
      return;
    }
    int part_number;
    scanf("%d", &part_number);
    if(find_part(part_number, inv, *np) >= 0){
      printf("Part already exists.\n");
      return;
    }
    inv[(*np)].number = part_number;
    printf("Enter part name: ");
    read_line(inv[(*np)].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &inv[(*np)].on_hand);
    (*np)++;
}

void search(const struct part inv[], int np){
	int i, number;

  printf("Enter part number: ");
  scanf("%d", &number);
  i = find_part(number, inv, np);
  if (i >= 0) {
    printf("Part name: %s\n", inv[i].name);
    printf("Quantity on hand: %d\n", inv[i].on_hand);
  } else
    printf("Part not found.\n");
}

void update(struct part inv[], int np){
	int i, number, change;

  printf("Enter part number: ");
  scanf("%d", &number);
  i = find_part(number, inv, np);
  if (i >= 0) {
    printf("Enter change in quantity on hand: ");
    scanf("%d", &change);
    inv[i].on_hand += change;
  } else
    printf("Part not found.\n");
}

void print(const struct part inv[], int np){
	  int i;

  printf("Part Number   Part Name                  "
         "Quantity on Hand\n");
  for (i = 0; i < np; i++)
    printf("%7d       %-25s%11d\n", inv[i].number,
           inv[i].name, inv[i].on_hand);
}
