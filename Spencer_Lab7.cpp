#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
	Node* left;
	Node* right;
	int data;
};

struct Node* newNode(int data) {
	Node* node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
};
void Preorder(Node *root) {

	if (root == NULL) {
		return;
	}
	cout << " " << root->data; 
	Preorder(root->left);    
	Preorder(root->right);    
}
void Inorder(Node *root) {
	if (root == NULL) {
		return;
	}
	Inorder(root->left);      
	cout << " " << root->data;  
	Inorder(root->right);
}
void Postorder(Node *root) {
	if (root == NULL) {
		return;
	}
	Postorder(root->left);    
	Postorder(root->right);   
	cout << " " << root->data; 
}

void BFS_tree(Node* root) {
	if (root == NULL)  return;
	queue<Node *> q;
	q.push(root);

	while (q.empty() == false){
		Node *node = q.front();
		cout << node->data << " ";
		q.pop();
		if (node->left != NULL)
			q.push(node->left);
		if (node->right != NULL)
			q.push(node->right);
	}

}
void printVector(const vector<int>& v, int i){
	for(int j = i; j<v.size(); j++)
		cout << v[j] << " ";
	cout << endl;
}
void allPath(Node* root, vector<int>& path, int k) {
	if (!root) {
		return;
	}
	path.push_back(root->data);
	allPath(root->left, path, k);
	allPath(root->right, path, k);
	int f = 0;
	for (int j = path.size() - 1; j >= 0; j--){
		f += path[j];
		if (f == k)
			printVector(path, j);
	}
	path.pop_back();
}






void sumPath(Node* root, int k) {
	vector<int> path;
	allPath(root, path, k);
}

int main() {
	struct Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	
	cout << "Inorder: ";
	Inorder(root);
	cout << '\n';
	cout << "Preorder: ";
	Preorder(root);
	cout << '\n';
	cout << "Postorder: ";
	Postorder(root);
	cout << '\n';
	cout << "BFS_tree: ";
	BFS_tree(root);
	cout << '\n';
	cout << "Sum Path: ";
	sumPath(root, 11);
}
