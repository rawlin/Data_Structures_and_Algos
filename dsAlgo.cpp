#include<bits/stdc++.h>
using namespace std;

class BST{

public:
    int data;
    BST *left,*right;
    BST();
    BST(int);
    BST* Insert(BST*,int);
    BST* deleteNode(BST*,int);
    BST* minValueNode(BST*);
    BST* preorderTraversal(BST*);
    BST* inorderTraversal(BST*);
    BST* postorderTraversal(BST*);
};

BST::BST():data(0),left(NULL),right() {}

BST::BST(int val) {
    data=val;
    left=right=NULL;
}

BST * BST::Insert(BST *root, int val) {
    if(!root){
        return new BST(val);
    }
    if(val<root->data){
        root->left=Insert(root->left,val);
    }else{
        root->right=Insert(root->right,val);
    }

    return root;

}

BST * BST::deleteNode(BST *root, int val) {
    if(root==NULL) return NULL;

    if(val<root->data){
        root->left=deleteNode(root->left,val);
    }else if(val>root->data){
        root->right=deleteNode(root->right,val);
    }else{
        if(root->left==NULL){
            BST *temp=root->right;
            free(root);
            return temp;
        }else if(root->right==NULL){
            BST *temp=root->left;
            free(root);
            return temp;
        }
        BST *temp=minValueNode(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
    return root;
}

BST * BST::minValueNode(BST *root) {
    BST *min=root;
    while(min&&min->left!=NULL){
        min=min->left;
    }
    return min;
}

BST * BST::preorderTraversal(BST *root) {
    if(root==NULL)
        return NULL;
    preorderTraversal(root->left);
    preorderTraversal(root->right);
    cout<<root->data<<" ";
}

BST * BST::inorderTraversal(BST *root) {
    if(root==NULL)
        return NULL;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

class BTree{
public:
    int data;
    BTree*left,*right;

};

BTree *newNode(int data) {
    BTree* root=new BTree();
    root->data=data;
    root->right=NULL;
    root->left=NULL;
    return root;
}

class Graph{

    int V;//No. of Vertices
    list<int> *adj;
    void DFSUtil(int v,vector<bool>&visited);
public:
    Graph(int V);
    void addEdge(int v,int w);
    void DFS(int v);
};

Graph::Graph(int V) {
    this->V=V;
    adj=new list<int>[V];
}
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}
void Graph::DFS(int v) {
    /*
     * time-O(V+E)
     * space-O(V)*/
    vector<bool> visited(V, false);
    DFSUtil(v,visited);
}
void Graph::DFSUtil(int v, vector<bool> &visited) {
    visited[v]=true;
    cout<<v<<" ";
    for(auto i=adj[v].begin();i!=adj[v].end();i++){
        if(!visited[*i]){
            DFSUtil(*i,visited);

        }
    }
}

class Node{
public:
    int data;
    Node* next,*prev;
    Node(int data);
    Node* deleteNode(int data);
    Node* setHeadFromList(Node* head,int val);
    Node* setTailFromList(Node* tail,int val);
    Node* setHead(Node* head,int val);
    Node* setTail(Node* tail,int val);
    bool searchList(Node *,int val);
    Node* deleteNodeWithVal(int data);
    Node* InsertBefore(Node*,int,int);
    Node* InsertAfter(Node*,int,int);



};
Node::Node(int data) {
    Node();
}


void TwoSumNumber1(vector<int> arr, int s);
void TwoSumNumber2(vector<int> arr, int s);
void ClosestValueInBST(BST*,int);
vector<int> BranchSums(BTree*);
void calculateBranchSum(BTree*,int,vector<int>&);

int main(){
    Node ll=new Node(1);
    return 0;
}

void TwoSumNumber1(vector<int> arr, int s) {
    /*
     * Q- Given an array of unique elements and a sum 's',find 2 numbers in the array that sum to 's'
     * @- Use hash-map to add traversed elements into it and check if s-n is in the hash-map
     * Time Complexity- O(n)
     * Space Complexity- O(n)
     * */
    unordered_map<int,bool> a;
    bool flag=false;
    for(int i=0;i<arr.size();i++){
        int num=s-arr[i];
        if(a.find(num)==a.end()){
            a[arr[i]]=true;
        }else{
            cout<<a.find(num)->first<<" "<<arr[i]<<endl;
            flag=true;
        }
    }
    if(flag==false){
        cout<<"No Pair of sums"<<endl;
    }

}

void TwoSumNumber2(vector<int> arr, int s) {
    /*
     * Q- Given an array of unique elements and a sum 's',find 2 numbers in the array that sum to 's'
     * @- Sort the array using an optimal sorting algo and use 2 ptrs pointing to 1st and last elmt and move left ptr until LeftPtr+RightPtr=val
     * Time Complexity- O(nlog(n))
     * Space Complexity- O(1)
     * */
    sort(arr.begin(),arr.end());
    arr.begin();
    int n=arr.size()-1;
    bool f= false;
    for(int i=0;i<=n;i++){
        if(arr[i]+arr[n]>s){
            n--;
        }else{
            if(arr[i]+arr[n]==s){
                cout<<arr[i]<<" "<<arr[n]<<endl;
                f=true;
            }
        }
    }
    if(!f){
        cout<<"No pairs";
    }
}

/*
 * Time-O(log(n))
 * Space- depth of tree
 */
int findClosestValueinBST(BST*root,int target,int closest){
    if(root==NULL){
        return closest;
    }
    if(abs(target-closest)>abs(target-root->data)){
        closest=root->data;
    }
    if(target<root->data){
        return findClosestValueinBST(root->left,target,closest);
    }else if(target>root->data){
        findClosestValueinBST(root->right,target,closest);
    }else{
        return closest;
    }
}
void ClosestValueInBST(BST*root,int n){

    int closest=root->data;
    BST* tempRoot=root;
    int diff=abs(closest-tempRoot->data);
    int ans=findClosestValueinBST(tempRoot,n,closest);
    cout<<ans<<endl;

}

vector<int> BranchSums(BTree* root){
    /*
     * O(n)-time @ O(n)-space*/
    int runningSum=0;
    BTree*troot=root;
    vector<int>list;
    calculateBranchSum(troot,runningSum,list);
    return list;
}
void calculateBranchSum(BTree*root,int runningSum,vector<int>&list){

    if(root==NULL){
        return;
    }
    int newRunningSum=runningSum+root->data;
    if(root->right==NULL&&root->left==NULL){
        list.push_back(newRunningSum);
        return;
    }
    calculateBranchSum(root->left,newRunningSum,list);
    calculateBranchSum(root->right,newRunningSum,list);
}
