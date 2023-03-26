#include <stdio.h>
#include "simply linked list.h"

int main(int argc, char **argv) {
    node root = CreateNode(10);
    node node_to_add = CreateNode(5);
    node another_one = CreateNode(7);

    AddNodeEnd(&root, &node_to_add);
    AddNode(&root, &another_one, 10);
    DeleteNode(&root, 5);
    TraverseLinkedList(&root);

    if (ValueExists(&root, 7)) {
        printf("The value 7 does exist\n");
    } else {
        printf("The value 7 does not exist\n");
    }

    if (ValueExists(&root, 5)) {
        printf("The value 5 does exist\n");
    } else {
        printf("The value 5 does not exist\n");
    }

    return 0;
}