// search,insert,deleted in binaryTree
#include <stdio.h>
#include <stdlib.h>

struct binaryTree{
    int data;
    struct binaryTree * left;
    struct binaryTree * right;
};

struct binaryTree * createNode(int value){
    struct binaryTree * newNode = (struct binaryTree*)malloc(sizeof(struct binaryTree));
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    
    return newNode;
}

struct binaryTree * inOrderPre(struct binaryTree * root){
    root=root->left;
    while(root->right !=NULL){
        root=root->right;
    }
    return root;
}

struct binaryTree * search(struct binaryTree * root,int value){
    if(root==NULL){
        return NULL;
    }
    if(value==root->data){
        return root;
    }
    else if(value < root->data){
        return search(root->left,value);
    }
    else{
        return search(root->right,value);
    }
}

struct binaryTree * insert(struct binaryTree * root,int value){
    struct binaryTree * prev = NULL;
    // searching the postion for insertion.
    while(root!=NULL){
        prev=root;
        if(value == root->data){
            return 0;
        }
        else if(value<root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    
    struct binaryTree *newNode = createNode(value);
    if(value < prev->data){
        prev->left=newNode;
    }
    else{
    prev->right=newNode;
    }
}


struct binaryTree * deleted(struct binaryTree * root,int value){
    struct binaryTree * iPre; // inOrder Predecssor
    // base condition of recursion
    if(root == NULL){
        return NULL;
    }

    // deleted node to be leaf node.
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }

    // deleted node to be non-leaf node
    // search the node to be deleted
    if(value < root->data){
       root->left = deleted(root->left,value);
    }
    else if(value > root->data){
        root->right= deleted(root->right,value);
    }

    // deleting stategy for the node to deleted 
    else{
        iPre = inOrderPre(root);
        root->data = iPre->data;
        root->left = deleted(root->left,iPre->data);
    }
    return root;
}

void inOrder(struct binaryTree * root){
    if(root!=NULL){
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
    }
}

void main(){
    struct binaryTree * p = createNode(10); 
    struct binaryTree * q = createNode(5);
    struct binaryTree * r = createNode(15);
    struct binaryTree * q1 = createNode(1);
    struct binaryTree * q2 = createNode(8);
    struct binaryTree * r1 = createNode(12);
    struct binaryTree * r2 = createNode(20);


                    // p is parent node 
          p->left=q;              p->right=r;                               
    q->left=q1;q->right=q2;    r->left=r1; r->right=r2;  

    printf("\ninOrder traversal in binaryTree :\n");
    inOrder(p);
    printf("\n");

    //which number you like to search in binaryTree
    struct binaryTree * n =search(p,8);
    
    if(n!=NULL){
    printf("%d is present is the binaryTree\n",n->data);
    }
    else{
        printf("element not found in binaryTree");
    }
    
    printf("\ninserting the value (7) in binaryTree \n");
    insert(p,7);
    
    printf("\ninOrder traversal after insertion in binaryTree :\n");
    inOrder(p);
    printf("\n");
    
    printf("\ndeleting the value(10) in binaryTree");
    deleted(p,10);
    printf("\n");
    
    printf("\ninOrder traversal after deletion in binaryTree :\n");
    inOrder(p);
    printf("\n");
}
