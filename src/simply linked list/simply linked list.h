#define data_type long long

typedef enum { FALSE, TRUE } bool;

typedef struct node {
    struct node *next;
    data_type value;
} node;

node CreateNode(data_type value) {
    node toReturn;

    toReturn.next = NULL;
    toReturn.value = value;

    return toReturn;
}

void AddNode(node *root, node *node_to_add, data_type value_to_add_after) {
    node *current_node = root;

    while (current_node->value != value_to_add_after && current_node->next != NULL)
        current_node = current_node->next;
    
    node_to_add->next = current_node->next;
    current_node->next = node_to_add;
}

void AddNodeEnd(node *root, node *node_to_add) {
    node *current_node = root;

    while (current_node->next != NULL)
        current_node = current_node->next;

    current_node->next = node_to_add;
}

void DeleteNode(node *root, data_type value_to_delete) {
    node *current_node = root;

    do {
        if (current_node->next->value == value_to_delete) {
            current_node->next = current_node->next->next;
        } else {
            current_node = current_node->next;   
        }
    } while (current_node->next != NULL);
}

void TraverseLinkedList(node *root) {
    node *current_node = root;
    int node_index = 0;

    printf("Value at index %i -> %li\n", node_index, current_node->value);

    while (current_node->next != NULL) {
        current_node = current_node->next;
        node_index++;
        
        printf("Value at index %i -> %li\n", node_index, current_node->value);
    }
}

bool ValueExists(node *root, data_type value_to_search_for) {
    node *current_node = root;

    while (current_node->next != NULL) {
        if (current_node->value == value_to_search_for)
            return TRUE;
        
        current_node = current_node->next;
    }

    if (current_node->value == value_to_search_for)
        return TRUE;

    return FALSE;
}