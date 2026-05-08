#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
        if(root == NULL) {
        struct TreeNode *aux = malloc(sizeof(struct TreeNode));
        aux->val = val;
        aux->left = NULL;               
        aux->right = NULL;
        return aux;
    } else {
        if(val < root->val) {
            root->left = insertIntoBST(root->left, val);
        } else {
            root->right= insertIntoBST(root->right, val);
        }
        return root;
    }
}

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if(root != NULL) {
         if( root->val == val ) {
            return root;
        }
        else if ( val < root->val ) {
            return searchBST(root->left, val);
        } else {
            return searchBST(root->right, val);
        }
    } 
        return NULL;
}

int main()
{
    struct TreeNode *root, *search = NULL;

    insertIntoBST(root, 10);
    insertIntoBST(root, 15);
    insertIntoBST(root, 5);
    insertIntoBST(root, 1);
    insertIntoBST(root, 20);
    
    search = searchBST(root, 5);

    search != NULL ? printf("\n\nValor encontrado: %d\n\n", search->val) : printf("\n\nValor nao encontrado!\n\n");
    
    return 0;
}
