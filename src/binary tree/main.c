#include <stdio.h>
#include "Binary Tree.h"

int main(int argc, char **argv) {
    node root = CreateNewNode(10);
    node node_to_add_one = CreateNewNode(20);
    node node_to_add_two = CreateNewNode(30);
    node node_to_add_three = CreateNewNode(4);

    AddNodeToTree(&root, &node_to_add_one);
    AddNodeToTree(&root, &node_to_add_two);
    AddNodeToTree(&root, &node_to_add_three);

    printf("The height of the binary tree is: %i\n", GetTreeHeight(&root));

    if (DoesValueExist(&root, 30)) {
        printf("The value 30 does exist\n");
    } else {
        printf("The value 30 does not exist\n");
    }

    if (DoesValueExist(&root, 16)) {
        printf("The value 16 does exist\n");
    } else {
        printf("The value 16 does not exist\n");
    }

    printf("The value of the root before deletion is: %li\n", root.value);
    RemoveValue(&root, 10);
    printf("The value of the root after deletion is: %li\n", root.value);

    return 0;
}