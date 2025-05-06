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

int search(int inorder[], int start, int end, int curr){
    for(int i = start; i<=end; i++){
        if(inorder[i] == curr){
            return i;
        }
    }

    return -1;
}

Node* buildtree(int preorder[], int inorder[], int st, int end){
    static int idx = 0;
    if(st > end){
        return NULL;
    }

    int curr = preorder[idx];
    idx++;
    Node* node = new Node(curr);
    if(st == end){
        return node;
    }

    int pos = search(inorder, st, end, curr);
    node->left = buildtree(preorder, inorder, st, pos-1);
    node->right = buildtree(preorder, inorder, pos+1, end);

    return node;
}

void inorderprint(Node* root){
    if(root == NULL){
        return;
    }
    inorderprint(root->left);
    cout << root->data << " ";
    inorderprint(root->right);
}

void solve()
{
    int preorder[] = {1,2,4,3,5};
    int inorder[] = {4,2,1,5,3};

    Node* root = buildtree(preorder, inorder, 0, 4);

    inorderprint(root);
    
}

// --- A world without rules and controls, without borders or boundaries ---

int main()
{
    Neo;//In a world of 1s and 0s...are you a zero, or The One? Reality is a thing of the past ---
    ll tc = 1; //cin >> tc;
    while(tc--) solve();
}