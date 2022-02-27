#include<iostream>
#include<vector>
#include<cmath>
#include<stack>
#include<queue>
#include<assert.h>
using namespace std;



typedef int type;

deque<type> traversal;

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
    /// my gentle code :(
    /*
    BinaryTree(deque<type> &preorder, deque<type> &inorder){

        deque<type> left_sub;
        deque<type> right_sub;

        while(inorder.front()!=preorder.front())
            left_sub.push_back(inorder.front()), inorder.pop_front();

        while(inorder.back()!=preorder.front())
            right_sub.push_front(inorder.back()), inorder.pop_back();

        data = preorder.front();
        preorder.pop_front();

        if(!left_sub.empty())
            left = new BinaryTree(preorder, left_sub);
        if(!right_sub.empty())
            right = new BinaryTree(preorder, right_sub);
    }
    */
    /// Dr's is always optimal :)
    BinaryTree(deque<type> &preorder, deque<type> &inorder, int inorder_start = 0, int inorder_end = -1){
        if(inorder_end==-1) // first call
            inorder_end = (int)inorder.size() - 1;

        data = preorder.front(); // current root
        preorder.pop_front();

        for(int split=inorder_start; split<=inorder_end; ++split){
            if(inorder[split] == data){
                if(inorder_start<split) // left exist
                    left = new BinaryTree(preorder, inorder, inorder_start, split - 1);
                if(split<inorder_end) // right exist
                    right = new BinaryTree(preorder, inorder, split + 1, inorder_end);
                break;
            }
        }
    }
    BinaryTree(queue< pair<int, bool> > &preorder_queue){
        pair<type, bool> p{preorder_queue.front()};
        preorder_queue.pop();

        data = p.first;


        if(!p.second){
            if(!preorder_queue.empty())
                left = new BinaryTree(preorder_queue);
            if(!preorder_queue.empty())
                right = new BinaryTree(preorder_queue);
        }
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

    void print_level_order_v1(){
        queue<BinaryTree*> que;
        que.push(this);

        while(!que.empty()){
            BinaryTree* cur = que.front();
            que.pop();

            cout << cur->data << " ";

            if(cur->left)
                que.push(cur->left);
            if(cur->right)
                que.push(cur->right);
        }
    }
    void print_inorder() {
		if (left)
			left->print_inorder();
		cout << data << " ";
		if (right)
			right->print_inorder();
	}
	void print_preorder() {
		cout << data << " ";
		if (left)
			left->print_preorder();
		if (right)
			right->print_preorder();
	}
    void print_postorder() {
		if (left)
			left->print_postorder();
		if (right)
			right->print_postorder();
        cout << data << " ";
	}

    // preorder pair of (value, is_leaf)
	void build_preorder(queue<pair<int, bool> > &preorder_queue) {
		preorder_queue.push(make_pair(data, !left && !right));

		if (left)
			left->build_preorder(preorder_queue);

		if (right)
			right->build_preorder(preorder_queue);
	}
};


void test1() {
    // 1 2 4 7 8 5 9 3 6 10
    deque<int> preorder;
    preorder.push_back(1);
    preorder.push_back(2);
    preorder.push_back(4);
    preorder.push_back(7);
    preorder.push_back(8);
    preorder.push_back(5);
    preorder.push_back(9);
    preorder.push_back(3);
    preorder.push_back(6);
    preorder.push_back(10);

    //7 4 8 2 5 9 1 3 10 6
    deque<int> inorder;
    inorder.push_back(7);
    inorder.push_back(4);
    inorder.push_back(8);
    inorder.push_back(2);
    inorder.push_back(5);
    inorder.push_back(9);
    inorder.push_back(1);
    inorder.push_back(3);
    inorder.push_back(10);
    inorder.push_back(6);

	BinaryTree tree(preorder,inorder);

	tree.print_preorder();
	cout << "\n";
    tree.print_postorder();
	cout << "\n";
	tree.print_inorder();
	cout << "\n";
	tree.print_level_order_v1();
	cout << "\n";
}

void test2() {
    queue< pair<int, bool>> preorder_que;
    preorder_que.push({1,0});
    preorder_que.push({2,1});
    preorder_que.push({3,1});

    BinaryTree tree(preorder_que);

    tree.print_preorder();
	cout << "\n";
    tree.print_postorder();
	cout << "\n";
    tree.print_inorder();
	cout << "\n";
    tree.print_level_order_v1();
	cout << "\n";
}

void test3_from_is_leaf() {
	BinaryTree tree(1);

	tree.add( { 2, 4 }, { 'L', 'L'});
	tree.add( { 3 }, { 'R'});


	tree.add( { 2, 5, 6 }, { 'L', 'R', 'L' });

	tree.add( { 2, 5, 7, 8, 10 }, { 'L', 'R', 'R', 'L', 'L' });

	tree.add( { 2, 5, 7, 8, 11 }, { 'L', 'R', 'R', 'L', 'R' });

	tree.add( { 2, 5, 7, 9 }, { 'L', 'R', 'R', 'R' });



	queue<pair<int, bool> > preorder_queue;
	tree.build_preorder(preorder_queue);
	tree.print_preorder();
	cout<<"\n";


	BinaryTree tree_created(preorder_queue);
	tree_created.print_preorder();

}

int main() {
    //test1();
    test2();
    test3_from_is_leaf();

	cout << "bye\n";

	return 0;
}


