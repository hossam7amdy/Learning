#include<iostream>
#include<vector>
#include<cmath>
#include<stack>
#include<assert.h>
using namespace std;



typedef char type;
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

    void print_inorder_iteratively(){
        stack< pair<BinaryTree*, bool> > st;

        st.push(make_pair(this, false));

        while(!st.empty()){
            BinaryTree* current = st.top().first;
            bool is_done = st.top().second;

            st.pop();
            if(is_done)
                cout << current->data;
            else{
                if(current->right)
                    st.push(make_pair(current->right, false));

                st.push(make_pair(current, true));

                if(current->left)
                    st.push(make_pair(current->left, false));
            }
        }
    }

    void traverse_left_boundary(){
        cout << data << " ";
        if(left)
            left->traverse_left_boundary();
        else if(right)
            right->traverse_left_boundary();
    }

    int tree_height(){
        int res = 0;
        if(left)
            res = 1 + left->tree_height();
        if(right)
            res = max(res, 1 + right->tree_height());
        return res;
    }
    int tree_diameter(){
        int res = 0;
        if(this->left)
            res = 1 + this->left->tree_height();
        if(this->right)
            res += 1 + this->right->tree_height();
        return res;
    }

    bool is_just_num(){
        return !left && !right;
    }
    void print_inorder_expression(){
        if(left){
            if(!left->is_just_num())
                cout << "(";
            left->print_inorder_iteratively();
            if(!left->is_just_num())
                cout << ")";
        }
        cout << data;
        if(right){
            if(!right->is_just_num())
                cout << "(";
            right->print_inorder_iteratively();
            if(!right->is_just_num())
                cout << ")";
        }
    }

};


void test1() {
	BinaryTree root("51+");

	cout << "infix expression: ";
	root.print_inorder_expression();
	cout << "\n";
	// infix expression: 5+1

}

void test2() {
	BinaryTree root("51+2/");

	cout << "infix expression: ";
	root.print_inorder_expression();
	cout << "\n";
	// infix expression: (5+1)/2
}

void test3() {
	BinaryTree root("23+4*");

	cout << "infix expression: ";
	root.print_inorder_expression();
	cout << "\n";
	// infix expression: (2+3)*4
}


void test4() {
	BinaryTree root("534*2^+");

	cout << "infix expression: ";
	root.print_inorder_expression();
	cout << "\n";
	// infix expression: 5+((3*4)^2)
}

int main() {
	test1();
	test2();
	test3();
	test4();

	return 0;
}
