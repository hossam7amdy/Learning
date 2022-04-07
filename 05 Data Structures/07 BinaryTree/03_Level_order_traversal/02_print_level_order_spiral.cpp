#include<iostream>
#include<vector>
#include<cmath>
#include<stack>
#include<deque>
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
    void print_level(const int &h){
        if(h==0)
            cout << data << " ";
        else{
            if(left)
                left->print_level(h-1);
            if(right)
                right->print_level(h-1);
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

    void print_level_order_spiral(){
        deque<BinaryTree*> dq_nodes;
        dq_nodes.push_back(this);

        int level = 0;
        bool forward_traverse = true;
        while(!dq_nodes.empty()){
            int sz = (int)dq_nodes.size();

            cout << "Level " << level << ": ";
            while(sz--){

                BinaryTree* cur = nullptr;

                if(forward_traverse){

                    cur = dq_nodes.front();
                    dq_nodes.pop_front();

                    if(cur->left)
                        dq_nodes.push_back(cur->left);

                    if(cur->right)
                        dq_nodes.push_back(cur->right);

                }else{

                    cur = dq_nodes.back();
                    dq_nodes.pop_back();

                    if(cur->right)
                        dq_nodes.push_front(cur->right);

                    if(cur->left)
                        dq_nodes.push_front(cur->left);
                }
                cout << cur->data << " ";
            }
            level++;
            forward_traverse = !forward_traverse;
            cout << "\n";
        }
    }

};

void test1_level_order_traversal_spiral() {
	BinaryTree tree(1);

	tree.add( { 2, 4, 8 }, { 'L', 'L', 'L' });
	tree.add( { 2, 4, 9 }, { 'L', 'L', 'R' });
	tree.add( { 2, 5, 10 }, { 'L', 'R', 'L' });
	tree.add( { 2, 5, 11 }, { 'L', 'R', 'R' });

	tree.add( { 3, 6, 12 }, { 'R', 'L', 'L' });
	tree.add( { 3, 6, 13 }, { 'R', 'L', 'R' });
	tree.add( { 3, 7, 14 }, { 'R', 'R', 'L' });
	tree.add( { 3, 7, 15 }, { 'R', 'R', 'R' });

	//tree.level_order_traversal_recursive();

	tree.print_level_order_spiral();
	// Level 0: 1
	// Level 1: 3 2
	// Level 2: 4 5 6 7
	// Level 3: 15 14 13 12 11 10 9 8
}

void test1() {
	BinaryTree tree(1);
	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	tree.add( { 3, 6, 15 }, { 'R', 'R', 'L' });

	tree.print_level_order_spiral();
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

	tree.print_level_order_spiral();
	cout << "\n";
}

int main() {
    test1_level_order_traversal_spiral();
    //test1();
    //test2();

	cout << "bye\n";

	return 0;
}


