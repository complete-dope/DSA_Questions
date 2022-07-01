// Lets implement and learn the bst from basic 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        left = NULL;
        right = NULL;
    }
};

void insertInaBst(Node* &root , int data){
    // ohh bst very very easy we have recursion
    Node* newNode = new Node(data);
    if(root == NULL){
        root = newNode;
        return;
    }

    if(data> root->data)
    {
        insertInaBst(root->right , data);
    }
    else if(data< root->data)
    {
        insertInaBst(root->left , data);
    }
}

bool searchinAtree(Node* &root , int data){
    // this would log time i guess
    // cout<<root->data<<endl;
    if(root == NULL){
        cout<<"not found"<<endl;
        return false;
    }
    if(root!= NULL && root->data == data){
        cout<<"found"<<endl;
        return true;
    }
    if(data > root->data){
        searchinAtree(root->right , data);
    }
    else if(data < root->data){
        searchinAtree(root->left , data);
    }
    return false;
}

// delete in a binary tree

void deletionInaBst(Node* root , int data){
    // we will be deleting leaf node
    if(data == root->data){
        root = NULL;
        return;
    }

    if(data > root->data){
        deletionInaBst(root->right , data);
    }
    else{
        deletionInaBst(root->left , data);
    }
}

void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void Inorder(Node* &root){
    if(root==NULL){
        return;
    }

    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

void Inordertwo(Node* &root){
    // we need to do inorder traversal without using recursion here
    cout<<endl;
    stack<Node* > st;
    Node* curr = root;

    while (curr != NULL || !st.empty())
    {   
        if(curr!=NULL){
            st.push(curr);
            curr = curr->left;
        }

        else{
            curr= st.top();
            st.pop();
            cout<<curr->data<<" ";
            curr = curr->right;
        }
    }
}


// LC 897
// INcreasing order search tree

void InorderwithVec(Node* &root , vector<Node* > &ans){
    if(root==NULL){
        return;
    }

    InorderwithVec(root->left ,ans);
    ans.push_back(root);
    InorderwithVec(root->right,ans);
}

void InorderwithVecInt(Node* &root , vector<int> &ans){
    if(root==NULL){
        return;
    }

    InorderwithVecInt(root->left , ans);
    ans.push_back(root->data);
    InorderwithVecInt(root->right, ans);
}

// LC Locked question 
// Find whether this target sum exists by adding 2 nodes only 
bool twoSumBst(Node* root , int target){
    // input is like (root , 20);
    vector<int> ans;
    InorderwithVecInt(root , ans);
    int n = ans.size();
    int i =0;
    int j = n-1;
    while(i<j){
        if(ans[i] + ans[j] == target){
            return true;
        }
        else if(ans[i] + ans[j] > target){
            j--;
        }
        else if (ans[i] + ans[j] < target){
            i++;
        }
    }
    return false;
}


// LC 108
// Inorder to bst
Node* arraytobst(int s , int e , vector<int> nums){
    if(s>e){
        return NULL;
        
    }
    int mid = (s+e)/2;
    Node* root = new Node(nums[mid]);
    root->left = arraytobst(s , mid-1 , nums);
    root->right = arraytobst(mid+1 , e , nums);
    return root;
}

void ost(Node* root){
    vector<Node*> ans;
    InorderwithVec(root , ans);
    int n = ans.size();
    ans[0]->left = NULL;
    for (int i = 1; i < n; i++)
    {
        ans[i]->left = NULL;
        ans[i-1]->right = ans[i];
    }
    cout<<ans[0];

}
// LC 235
// Lowest common ancestor
Node* lca(Node* root , Node* p , Node* q){
    while(root != NULL){
        if(root->data < p->data && root->data < q->data){
            root = root->right;
        }
        else if(root->data > p->data && root->data > q->data){
            root = root->left;
        }
        else{
            return root;
        }
    }
    return NULL;
}


Node* MakeBSTfromPreorder(int s , int e ,vector<int> &nums)
{
    if(s > e){
        return NULL;
    }
    int n =e-s+1;
    Node* root = new Node(nums[s]);
    int rightTree = 0;
    for (int i = s+1; i < n; i++)
    {
        if(nums[s] < nums[i]){
            rightTree = i;
            break;
        }
    }
    
    root->left = MakeBSTfromPreorder(s+1, rightTree-1 , nums);
    root->right = MakeBSTfromPreorder(rightTree , n , nums);
    return root;
}

int main(){
    Node* root = NULL;
    insertInaBst(root ,4);
    insertInaBst(root ,2);
    insertInaBst(root ,6);
    insertInaBst(root ,1);
    insertInaBst(root ,3);
    insertInaBst(root ,5);
    insertInaBst(root ,7);
    preorder(root);
    Inordertwo(root);
    // cout<<"Root data is "<<root->data<<" ";
    bool ans1 = searchinAtree(root ,7);
    // cout<<"Root data is "<<root->data<<" ";
    cout<<ans1;
    bool ans2 = searchinAtree(root ,9);
    // cout<<"Root data is "<<root->data<<" ";

    cout<<ans2;

    cout<<"make bst from preorder"<<endl;
    vector<int> nums {8,5,1,7,10,12};
    Node* rooted = MakeBSTfromPreorder(0 , 5 ,nums);
    Inorder(rooted);

    return 0;
}



/*
// Questions
Q-1 : Validate bst
---> get the ranges for all the node values and see if they are satisfying it or not 

*/

void validate(Node * &root , int min , int max){
    if(root==NULL){
        return;
    }
    if(root->data < max && root->data > min){
        validate(root->left , min , root->data);
        validate(root->right , root->data , max);
    }
    else {
        cout<<"false";
    }
}