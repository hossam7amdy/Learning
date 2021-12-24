#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

struct Node {
	int data { };
	Node* next { };
	Node(int data) : data(data) {}
	~Node() {
		cout << "Destroy value: " << data <<" at address "<< this<< "\n";
	}
};

class LinkedList {
private:
	Node *head { };
	Node *tail { };
	int length = 0;	// let's maintain how many nodes

    void delete_node(Node* node) {
		--length;
		debug_remove_node(node);
		delete node;
	}

	/////////////// Debug Utilities ///////////////////
    vector<Node*> debug_data;	// add/remove nodes you use
	void debug_add_node(Node* node) {
		debug_data.push_back(node);
	}
	void debug_remove_node(Node* node) {
		auto it = std::find(debug_data.begin(), debug_data.end(), node);
		if (it == debug_data.end())
			cout << "Node does not exist\n";
		else
			debug_data.erase(it);
	}
	void debug_print_address() {
		for (Node* cur = head; cur; cur = cur->next)
			cout << cur << "," << cur->data << "\t";
		cout << "\n";
	}

	void debug_print_node(Node* node, bool is_seperate = false) {
		if (is_seperate)
			cout << "Sep: ";
		if (node == nullptr) {
			cout << "nullptr\n";
			return;
		}
		cout << node->data << " ";
		if (node->next == nullptr)
			cout << "X ";
		else
			cout << node->next->data << " ";

		if (node == head)
			cout << "head\n";
		else if (node == tail)
			cout << "tail\n";
		else
			cout << "\n";
	}
	void debug_print_list(string msg = "") {
		if (msg != "")
			cout << msg << "\n";
		for (int i = 0; i < (int) debug_data.size(); ++i)
			debug_print_node(debug_data[i]);
		cout << "************\n"<<flush;
	}

	string debug_to_string() {
		if (length == 0)
			return "";
		ostringstream oss;
		for (Node* cur = head; cur; cur = cur->next) {
			oss << cur->data;
			if (cur->next)
				oss << " ";
		}
		return oss.str();
	}

	void debug_verify_data_integrity() {
		if (length == 0) {
			assert(head == nullptr);
			assert(tail == nullptr);
		} else {
			assert(head != nullptr);
			assert(tail != nullptr);
			if (length == 1)
				assert(head == tail);
			else
				assert(head != tail);
			assert(!tail->next);
		}
		int len = 0;
		for (Node* cur = head; cur; cur = cur->next, len++)
			assert(len < 10000);	// Consider infinite cycle?
		assert(length == len);
		assert(length == (int)debug_data.size());
	}
	////////////////////////////////////////////////////////////

public:
    LinkedList() { }
	LinkedList(const LinkedList&) = delete;
	LinkedList &operator=(const LinkedList &another) = delete;

    void print() {
		for (Node* cur = head; cur; cur = cur->next)
			cout << cur->data << " ";
		cout << "\n";
	}
	void add_node(int value) {
	    Node* item = new Node(value);
	    if(!head)
            head = tail = item;
        else{
            tail->next = item;
            tail = item;
        }
		++length;

		debug_add_node(item);
	}
    Node* get_nth(int n){
        n--; // Zero-Based
        if(0>n || n>length)
            return nullptr;

        Node* res = head;
        while(n--)
            res = res->next;
        return res;
    }
    int Search(int value){
        int idx = 0;
        for(Node* curr = head; curr; curr = curr->next, idx++)
            if(curr->data == value)
                return idx;

        return -1;
    }
	void delete_front(){
	    if(head){
            Node* curr = head;
            head = head->next;
            delete_node(curr);
	    }

        if(!head)
            tail = nullptr;

        debug_verify_data_integrity();
	}
	void delete_end(){
	    if(length==1){
            delete_front();
            return;
	    }

	    Node* previous = get_nth(length-1);

	    delete_node(tail);
	    tail = previous;
	    tail->next = nullptr;

	    debug_verify_data_integrity();
	}
	void delete_nth(int idx){
	    if(1>idx || idx>length)
            cout << "Invalid Node\n";

	    else if(idx==1)
            delete_front();

	    else{
	    Node* previous = get_nth(idx-1);
	    Node* target = previous->next;

	    previous->next = target->next;

	    if(target==tail)
            tail = previous;

        delete_node(target);
	    }

	    debug_verify_data_integrity();
	}
	void delete_node_with_value(int value){
	    int idx = Search(value);
	    if(idx == -1)
            cout << "There is no such value\n";
        else
            delete_nth(idx+1);

        debug_verify_data_integrity();
	}
};

int main(){
    LinkedList List;
    List.add_node(10);
    List.add_node(20);
    List.add_node(30);
    List.print();


    List.delete_node_with_value(30);
    List.delete_node_with_value(10);
    List.delete_node_with_value(20);

    List.print();

    return 0;
}