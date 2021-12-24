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
                cout << current->data << " ";
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

};


void test4_diameter() {
	BinaryTree tree(1);

	assert(tree.tree_diameter() == 0);

	tree.add( { 2 }, { 'L' });
	tree.add( { 3 }, { 'R' });

	assert(tree.tree_diameter() == 2);

	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	tree.add( { 3, 6, 15 }, { 'R', 'R', 'L' });

	tree.add( { 2, 5, 13 }, { 'L', 'R', 'L' });
	tree.add( { 3, 6, 12 }, { 'R', 'R', 'R' });
	tree.add( { 3, 14, 15 }, { 'R', 'L', 'L' });
	tree.add( { 3, 14, 16 }, { 'R', 'L', 'R' });

	assert(tree.tree_diameter() == 6);
}

void test5_boundry() {
	BinaryTree tree(1);

	tree.add( { 2, 4, 5, 6, 7, 9, 11 }, { 'L', 'L', 'R', 'R', 'L', 'L', 'R' });
	tree.add( { 2, 4, 5, 6, 8 }, { 'L', 'L', 'R', 'R', 'R' });
	tree.add( { 2, 4, 5, 6, 7, 10 }, { 'L', 'L', 'R', 'R', 'L', 'R' });
	tree.add( { 3 }, { 'R' });

	tree.traverse_left_boundary();
	// 1 2 4 5 6 7 9 11

	cout<<"\n";
	tree.print_inorder_iteratively();
}


int main() {
    BinaryTree tree("23+4*");
    tree.print_inorder_iteratively();

	cout << "\nbye\n";

	return 0;
}

