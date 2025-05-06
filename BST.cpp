#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val < root->data){
        root->left = insert(root->left,val);
    }
    else{
        root->right = insert(root->right,val);
    }
    return root;
}

void inorderprint(Node* root){
    if(root == NULL){
        return;
    }
    inorderprint(root->left);
    cout << root->data << " ";
    inorderprint(root->right);
}

Node* search(Node* root, int key){
    if(root == NULL){
        return NULL;
    }

    if(root->data == key){
        return root;
    }

    if(root->data > key){
        return search(root->left, key);
    }

    return search(root->right, key);
}

Node* inorersucc(Node* root){
    Node* curr = root;
    while(curr && curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}

Node* delet(Node* root, int key){
    if(key < root->data){
        root->left = delet(root->left, key);
    }
    else if(key > root->data){
        root->right = delet(root->right,key);
    }
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = inorersucc(root->right);
        root->data = temp->data;
        root->right = delet(root->right, temp->data);
    }
    return root;
}

Node* buildBST(int preorder[], int* idx, int key, int min, int max, int size){
    if(*idx >= size){
        return NULL;
    }
    Node* root = NULL;
    if(key > min && key < max){
        root = new Node(key);
        *idx = *idx+1;

        if(*idx < size){
            root->left = buildBST(preorder, idx, preorder[*idx], min, key, size);
        }
        if(*idx < size){
            root->right = buildBST(preorder, idx, preorder[*idx], key, max, size);
        }
    }
    return root;
}

void preorderprint( Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preorderprint(root->left);
    preorderprint(root->right);
}

bool isBST(Node* root, Node* min=NULL, Node* max=NULL){
    if(root == NULL){
        return true;
    }
    if(min != NULL && root->data <= min->data){
        return false;
    }
    if(max != NULL && root->data >= max->data){
        return false;
    }

    bool left = isBST(root->left, min, root);
    bool right = isBST(root->right, root, max);
    return left and right;
}

Node* sortedaArrToBST(int arr[], int st, int end){
    if(st > end){
        return NULL;
    }
    int mid = (st+end)/2;
    Node* root = new Node(arr[mid]);
    root->left = sortedaArrToBST(arr,st,mid-1);
    root->right = sortedaArrToBST(arr,mid+1,end);
    return root;
}

int main()
{

    Node* root = NULL;
    root = insert(root,5);
    insert(root,1);
    insert(root,3);
    insert(root,4);
    insert(root,2);
    insert(root,7);

    inorderprint(root);
    cout << endl;

    delet(root,4);

    inorderprint(root);
    cout << endl;

    if(search(root,5)==NULL){
        cout << "Key doesn't exist." << endl;
    }
    else{
        cout << "Key exists." << endl;
    }

    int preorder[] = {10,2,1,13,11};
    int n = 5;
    int i = 0;
    Node* root2 = buildBST(preorder, &i, preorder[0], INT_MIN, INT_MAX, n);

    preorderprint(root2);
    cout << endl;

    if(isBST(root2,NULL,NULL)){
        cout << "Valid BST." << endl;
    }
    else{
        cout << "Invalid BST." << endl;
    }

    int arr[] = {1,2,3,4,5};
    Node* root3 = sortedaArrToBST(arr,0,4);
    preorderprint(root3);
}