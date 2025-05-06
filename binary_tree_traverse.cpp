#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define MOD 1000000007
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define Neo ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
void take(vector<ll>& vec) { for(auto& i : vec) cin >> i; }
 

ll gcd(ll a,ll b) { return __gcd(a,b); }
ll lcm(ll a,ll b) { return (a*b)/__gcd(a,b); }

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

void preorder( Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void solve()
{
    class Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
}

// --- A world without rules and controls, without borders or boundaries ---

int main()
{
    Neo;//In a world of 1s and 0s...are you a zero, or The One? Reality is a thing of the past ---
    ll tc = 1; //cin >> tc;
    while(tc--) solve();
}