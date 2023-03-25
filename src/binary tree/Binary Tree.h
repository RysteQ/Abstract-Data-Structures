#define NODE_VALUE long long

typedef enum { FALSE, TRUE } bool;

typedef struct node {
    struct node *left_node;
    struct node *right_node;
    NODE_VALUE value;
} node;

node CreateNewNode(NODE_VALUE value) {
    node toReturn;

    toReturn.left_node = NULL;
    toReturn.right_node = NULL;
    toReturn.value = value;

    return toReturn;
}

void AddNodeToTree(node *root, node *node_to_add) {
    node *current_node = root;

    while (TRUE) {
        if (current_node->value <= node_to_add->value) {
            if (current_node->right_node == NULL) {
                current_node->right_node = node_to_add;
                break;
            } else {
                current_node = current_node->right_node;
            }
        } else {
            if (current_node->left_node == NULL) {
                current_node->left_node = node_to_add;
                break;
            } else {
                current_node = current_node->left_node;
            }
        }
    }
}

int GetTreeHeight(node *root) {
    int right_height = 0;
    int left_height = 0;

    if (root->right_node != NULL)
        right_height = GetTreeHeight(root->right_node) + 1;
    
    if (root->left_node != NULL)
        left_height = GetTreeHeight(root->left_node) + 1;
    
    if (right_height > left_height)
        return right_height;
    
    return left_height;
}

bool DoesValueExist(node *root, NODE_VALUE value_to_search_for) {
    node *current_node = root;

    while (TRUE) {
        if (current_node->value == value_to_search_for)
            return TRUE;

        if (current_node->value <= value_to_search_for) {
            if (current_node->right_node == NULL)
                return FALSE;
            
            current_node = current_node->right_node;
        } else {
            if (current_node->left_node == NULL)
                return FALSE;
            
            current_node = current_node->left_node;
        }
    }
}

void RemoveValue(node *root, NODE_VALUE value_to_remove) {
    node *current_node = root;
    bool removed = FALSE;

    while (removed == FALSE){
        if (current_node->value == value_to_remove) {
            if (current_node->right_node != NULL) {
                *current_node = *(current_node->right_node);
            } else {
                *current_node = *(current_node->left_node);
            }

            removed = TRUE;
        }

        if (current_node->value <= value_to_remove) {
            if (current_node->right_node != NULL) {
                current_node = current_node->right_node;
            } else {
                removed = TRUE;
            }
        } else {
            if (current_node->left_node != NULL) {
                current_node = current_node->left_node;
            } else {
                removed = TRUE;
            }
        }
    }
}