#include<iostream>
#include<assert.h>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;

struct Node{
    int data { };
    Node* next { };

    Node(int data): data(data){  }
    ~Node() {
		//To easily test your nodes are destructed
		cout << "Destroy value: " << data << "\n";
	}
};

bool debug_sort_data(const Node* n1, const Node* n2){
    return n1->data < n2->data;
}

class LinkedList{
private:
    Node* head { };
    Node* tail { };
    int length { };

    void delete_node(Node* item){
        debug_remove_node(item);
        delete item;
        length--;
    }
    Node* reverse_from(Node* node){ // time O(n) - memory O(n)
        if(node->next)
            reverse_from(node->next)->next = node;

        return node;
    }

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

public:
    LinkedList() {  }
	LinkedList(const LinkedList&) = delete;
	LinkedList &operator=(const LinkedList &another) = delete;
    ~LinkedList(){
        while(head){
            Node* current = head->next;
            length--;
            delete head;
            head = current;
        }
    }

	///////////////// Debugging Utilities ///////////////
	void debug_Print_node(Node* node, bool is_seperate = false) {
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
	void debug_Print_List(string msg = "") {
		if (msg != "")
			cout << msg << "\n";
		for (int i = 0; i < (int) debug_data.size(); ++i)
			debug_Print_node(debug_data[i]);
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
	////////////////////////////////////////////////////
    void Print(){
        Node *temp = head;
        while(temp != nullptr){
            cout << temp->data << " :" << &temp->next << " =>>| ";
            temp = temp->next;
        }
        cout << "null\n";

        temp = head;
        while(temp != nullptr){
            debug_Print_node(temp);
            temp = temp->next;
        }
        cout << "\n";
    }
    void insert_end(int value){ // time O(1) - memory O(1)
        Node* item = new Node(value);

        if(!head)
            head = tail = item;
        else{
            tail->next = item;
            tail = item;
        }
        debug_add_node(item);
        length++;
    }
    void insert_front(int value){ // time O(1) - memory O(1)
        Node* item = new Node(value);

        if(!head)
            head = tail = item;
        else{
            item->next = head;
            head = item;
        }
        debug_add_node(item);
        length++;
    }
    void delete_front(){ // time O(1) - memory O(1)

        Node* temp = head->next;
        delete_node(head);
        head = temp;

        if(length<=1)
            tail = head;

        debug_verify_data_integrity();
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
    Node* get_nth_back(int n){
        return get_nth(length - n + 1);
    }
    bool is_same1(const LinkedList &other){
        if(this->length!=other.length)
            return false;
        else{
            for(Node* curr_h=this->head, *other_h=other.head; curr_h; curr_h=curr_h->next, other_h=other_h->next)
                if(curr_h->data!=other_h->data)
                    return false;
        }

        return true;
    }
    bool is_same2(const LinkedList &other){
        Node* h1=this->head, *h2=other.head;

        while(h1&&h2){
            if(h1->data!=h2->data)
                return false;

            h1=h1->next, h2=h2->next;
        }

        return !h1&&!h2;
    }
    void delete_middle(Node* node){
        Node* to_delete = node->next;

        if(to_delete==tail){
            tail = node;
            tail->next = nullptr;
        }
        else
            node->next = node->next->next;

        delete_node(to_delete);
    }
    void delete_node_with_key(int value){
        if(length==0)
            cout << "Empty List\n";
        else if(head->data==value)
            delete_front();
        else{
            for(Node* cur=head, *prev { }; cur; prev=cur, cur=cur->next){
                if(cur->data == value){
                    delete_middle(prev);
                    break;
                }
            }
            cout << "There is no such a value\n";
        }
        debug_verify_data_integrity();
    }
    void swap_pairs(){
        for(Node* cur=head; cur&&cur->next; cur=cur->next->next)
            swap(cur->data, cur->next->data);
    }
    void Reverse(){ // memory O(n)
        reverse_from(head);
        swap(head,tail);
        tail->next = nullptr;
        reverse(debug_data.begin(), debug_data.end());
        debug_verify_data_integrity();
    }
    void Reverse2(){ // time O(n) - memory O(1)
        if(length<=1)
            return;

        tail = head;
        Node* prev = head;

        head = head->next;
        while(head){
            Node* next = head->next;
            head->next = prev;

            prev = head;
            head = next;
        }

        head = prev;
        tail->next = nullptr;

        reverse(debug_data.begin(), debug_data.end());
        debug_verify_data_integrity();

    }
    void delete_even_positions(){
        if(length<=1)
            return;
        Node* cur = head;
        while(cur && cur->next){ // time O(n/2) - memory O(1)
            Node* target = cur;
            cur = cur->next->next;
            delete_middle(target);
        }
        debug_verify_data_integrity();
    }
    void embed_after(Node* prev, int value){
        Node* item = new Node(value);

        item->next = prev->next;
        prev->next = item;
        length++;

        debug_add_node(item);
        sort(debug_data.begin(), debug_data.end(),debug_sort_data);
    }
    void insert_sorted(int value){
        if(!head || value<=head->data)
            insert_front(value);
        else if(value>=tail->data)
            insert_end(value);
        else{
            for(Node *cur=head, *prev{ }; cur; prev=cur,cur=cur->next){
                if(value<=cur->data){
                    embed_after(prev, value);
                    break;
                }
            }
        }
        debug_verify_data_integrity();
    }
    void swap_head_tail(){ // time O(n) - memory O(1)
        if(length<=1)
            return;

        if(length==2){
            swap(head,tail);
            head->next = tail;
            tail->next = nullptr;
            return;
        }

        Node* prev = get_nth(length-1);

        tail->next = head->next;

        prev->next = head;
        head->next = nullptr;

        swap(tail,head);

        swap(debug_data[0], debug_data[length-1]);
        debug_verify_data_integrity();
    }
    void left_rotate(int k){ // time O(n) - memory O(1)
        if(length<=1 || k%length==0)
            return;
        k%=length;

        Node* target = get_nth(k);
        tail->next = head;

        head = target->next;
        tail = target;

        target->next = nullptr;
        debug_verify_data_integrity();
    }
    void remove_duplicates_from_not_sorted(){ // time O(n^2) - memory O(1)
        if(length<2)
            return;

        for(Node *cur=head; cur; cur=cur->next){
            for(Node *prev=cur,*next=cur->next; next;){
                if(cur->data==next->data){
                    next=next->next; // move first
                    delete_middle(prev);
                    continue;
                }
                prev=next, next=next->next; // normal
            }
        }
        debug_verify_data_integrity();
    }
    void remove_last_ocurrence(int value){ // time O(n) - memory O(1)
        if(!length)
            return;

        Node* target { };
        for(Node *cur=head, *prev{ }; cur; prev=cur, cur=cur->next){
            if(cur->data == value){
                if(cur==head)
                    target = cur;
                else
                    target = prev;
            }
        }

        if(target){
            if(target==head)
                delete_front();
            else
                delete_middle(target);
            }
        else
            cout << "There is no such value.\n";

        debug_verify_data_integrity();
    }
    Node* move_to_end(Node* prev, Node* cur){ // maintain tail and return the valid cur
        Node* next = cur->next;
        tail->next = cur;

        if(prev)
            prev->next = next;
        else
            head = next; // was head

        tail=cur;
        tail->next = nullptr;
        return next;
    }
    void move_key_occurance_to_end(int value){ // time O(n) - memory O(1)
        if(length<=1)
            return;

        int len = length; // length steps only
        for(Node *cur=head, *prev{ }; len--;){
            if(cur->data==value)
                cur = move_to_end(prev, cur);
            else
                prev=cur, cur=cur->next; // normal step
        }
        debug_verify_data_integrity();
    }
    int Max(Node *cur=nullptr, bool first_call=true){ // time o(n) - memory O(n)
        if(first_call)
            return Max(head, false);

        if(cur==nullptr)
            return INT_MIN;

        return max(cur->data, Max(cur->next, false));
    }
    /// Problem #1: Arrange odd & even nodes
    void arrange_even_odd(){ // time O(n) - memory O(1)
        if(length<=2)
            return;

        Node* cur_odd = head;
        Node* first_even = head->next;

        while(cur_odd->next && cur_odd->next->next){
            Node* next_even = cur_odd->next;

            cur_odd->next = cur_odd->next->next;
            next_even->next = next_even->next->next;

            cur_odd = cur_odd->next;

            if(length%2==1)
                tail = next_even;
        }
        cur_odd->next = first_even;

        debug_verify_data_integrity();
    }
    /// Problem #2: Insert alternating
    void insert_alternate(LinkedList &another){ // time O(n) - memory O(1)
        if(!another.length)
            return;
        else if(!length){
            head = another.head;
            tail = another.tail;
            length = another.length;

            debug_data = another.debug_data;
        }
        else{
            Node* cur2 = another.head;
            for(Node* cur1 = head; cur1&&cur2;){
                Node* temp_cur2_next = cur2->next;

                cur2->next = cur1->next;
                cur1->next = cur2;

                cur2 = temp_cur2_next;

                debug_add_node(cur2);

                if(cur1==tail){
                    tail = another.tail;
                    cur1->next->next = cur2;
                    break;
                }
                cur1 = cur1->next->next;
            }

            length += another.length;
            another.head = another.tail = nullptr;
            another.length = 0;
            another.debug_data.clear();
            //debug_verify_data_integrity();
        }

    }

};

void test1() {
	cout << "\n\ntest1\n";
	LinkedList list1;

	list1.insert_end(1);
	list1.insert_end(2);
	list1.insert_end(3);

	LinkedList list2;

	list2.insert_end(4);
	list2.insert_end(5);

	list1.insert_alternate(list2);

	list1.Print();

	string expected = "1 4 2 5 3";
	string result = list1.debug_to_string();
	if (expected != result) {
		cout << "no match:\nExpected: " << expected << "\nResult  : " << result << "\n";
		assert(false);
	}
	list1.debug_Print_List("********");
}

void test2() {
	cout << "\n\ntest2\n";
	LinkedList list1;

	list1.insert_end(1);
	list1.insert_end(2);
	list1.insert_end(3);

	LinkedList list2;

	//list2.insert_end(4);

	list1.insert_alternate(list2);

	list1.Print();

	string expected = "1 2 3";
	string result = list1.debug_to_string();
	if (expected != result) {
		cout << "no match:\nExpected: " << expected << "\nResult  : " << result << "\n";
		assert(false);
	}
	list1.debug_Print_List("********");
}

void test3() {
	cout << "\n\ntest3\n";
	LinkedList list1;

	list1.insert_end(1);
	list1.insert_end(2);
	list1.insert_end(3);

	LinkedList list2;

	list2.insert_end(4);
	list2.insert_end(5);
	list2.insert_end(6);

	list1.insert_alternate(list2);

	list1.Print();

	string expected = "1 4 2 5 3 6";
	string result = list1.debug_to_string();
	if (expected != result) {
		cout << "no match:\nExpected: " << expected << "\nResult  : " << result << "\n";
		assert(false);
	}
	list1.debug_Print_List("********");
}

void test4() {
	cout << "\n\ntest4\n";
	LinkedList list1;

	list1.insert_end(1);
	list1.insert_end(2);
	list1.insert_end(3);

	LinkedList list2;

	list2.insert_end(4);
	list2.insert_end(5);
	list2.insert_end(6);
	list2.insert_end(7);

	list1.insert_alternate(list2);

	list1.Print();

	string expected = "1 4 2 5 3 6 7";
	string result = list1.debug_to_string();
	if (expected != result) {
		cout << "no match:\nExpected: " << expected << "\nResult  : " << result << "\n";
		assert(false);
	}
	list1.debug_Print_List("********");
}

void test5() {
	cout << "\n\ntest5\n";
	LinkedList list1;

	LinkedList list2;

	list2.insert_end(4);
	list2.insert_end(5);
	list2.insert_end(6);
	list2.insert_end(7);

	list1.insert_alternate(list2);

	list1.Print();

	string expected = "4 5 6 7";
	string result = list1.debug_to_string();
	if (expected != result) {
		cout << "no match:\nExpected: " << expected << "\nResult  : " << result << "\n";
		assert(false);
	}
	list1.debug_Print_List("********");
}

int main() {
	test1();
	test2();
	test3();
	test4();
	test5();

	cout << "\n\nNO RTE\n";		// must see it, otherwise RTE
	return 0;
}
