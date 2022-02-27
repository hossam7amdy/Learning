#include<iostream>
#include<vector>
#include<cmath>
#include<stack>
#include<queue>
#include<assert.h>
using namespace std;



typedef int type;
class BinaryTree{
private:
    type data{ };
    BinaryTree* left{ };
    BinaryTree* right{ };

public:
    BinaryTree(const type &data):
        data(data){
    }
    BinaryTree(const string &postfix){
        stack<BinaryTree*> st;

        for(int i=0; i<(int)postfix.size(); i++){
            BinaryTree* cur = new BinaryTree(postfix[i]);

            if(!isdigit(postfix[i])){
                cur->right = st.top();
                st.pop();
                cur->left = st.top();
                st.pop();
            }
            st.push(cur);
        }
        BinaryTree* root = st.top();
        this->data = root->data;
        this->left = root->left;
        this->right = root->right;
    }
    void print_inOrder() {
        if (left)
            left->print_inOrder();
        cout << data << " ";
        if(right)
            right->print_inOrder();
    }
    void add(const vector<type> &data, const vector<char> &direction){
        assert((int)data.size() == (int)direction.size());
        BinaryTree* current = this;

        for(int i=0; i<(int)data.size(); i++){
            if(direction[i] == 'L'){
                if(!current->left)
                    current->left = new BinaryTree(data[i]);
                else
                    assert(current->left->data == data[i]);
                current = current->left;
            }else{
                if(!current->right)
                    current->right = new BinaryTree(data[i]);
                else
                    assert(current->right->data == data[i]);
                current = current->right;
            }
        }
    }

    void clear_nodes() {
        if(left){
            delete left;
            left = nullptr;
        }
        if(right){
            delete right;
            right = nullptr;
        }
    }
    ~BinaryTree(){
        //cout << "Node " << data << " deleted at address " << this << "\n";
        clear_nodes();
    }

    int tree_height(){
        int height = 0;
        if(left)
            height = 1 + left->tree_height();
        if(right)
            height = max(height, 1 + right->tree_height());

        return height;
    }
    void print_level(const int &level){
        if(level==0)
            cout << data << " ";
        else{
            if(left)
                left->print_level(level-1);
            if(right)
                right->print_level(level-1);
        }
    }
    void print_level_order_recursive(){ // time O(n^2)
        int h = tree_height();

        for(int i=0; i<=h; i++){
            cout << "Level " << i+1 << ": ";
            print_level(i);
            cout << "\n";
        }
    }

};


void test1() {
	BinaryTree tree(1);
	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	tree.add( { 3, 6, 15 }, { 'R', 'R', 'L' });

	tree.print_level_order_recursive();
	//cout << tree.tree_height();
	cout << "\n";
}

void test2() {
	BinaryTree tree(1);

	tree.add( { 2 }, { 'L' });
	tree.add( { 3 }, { 'R' });


	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	tree.add( { 3, 6, 15 }, { 'R', 'R', 'L' });


	tree.add( { 2, 5, 13 }, { 'L', 'R', 'L' });
	tree.add( { 3, 6, 12 }, { 'R', 'R', 'R' });
	tree.add( { 3, 14, 15 }, { 'R', 'L', 'L' });
	tree.add( { 3, 14, 16 }, { 'R', 'L', 'R' });

	tree.print_level_order_recursive();
	cout << "\n";
}

int main() {
    test1();
    //test2();

	cout << "bye\n";

	return 0;
}


