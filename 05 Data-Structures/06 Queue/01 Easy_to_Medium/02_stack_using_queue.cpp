#include<iostream>
#include<assert.h>
using namespace std;

typedef int type;

class Queue{
private:
    int Front{ };
    int Rear { };
    int Size;
    int added_elements{ };
    type *Array;

    int next(int pos){
        ++pos;

        if(pos == Size)
            return 0;
        return pos;
    }
public:
    Queue(const int &Size):
        Size(Size){
            assert(Size>=0);
            Array = new type[Size];
    }
    ~Queue(){
        delete[] Array;
    }

    bool isFull(){
        return added_elements == Size;
    }
    bool isEmpty(){
        return added_elements == 0;
    }

    void inqueue(const type &value){
        assert(!isFull());

        Array[Rear] = value;
        Rear = next(Rear);
        added_elements++;
    }
    type dequeue(){
        assert(!isEmpty());

        type value = Array[Front];
        Front = next(Front);
        --added_elements;

        return value;
    }
    type Front_val(){
        assert(!isEmpty());
        return Array[Front];
    }

    void display(){
        //cout << "Front " << Front << " - rear " << Rear << "\t";
        if(isFull())
            cout << "Queue is Full\n";
        else if(isEmpty()){
            cout << "Queue is Empty\n";
            return;
        }
        for(int cur=Front, elements = 0; elements<added_elements; elements++, cur=next(cur))
            cout << Array[cur] << " ";
        cout << "\n";
    }
};

class Stack{
private:
    Queue q;
    int added_elements { };

    void insert_front(const int &value){
        int sz = added_elements;
        q.inqueue(value);
        while(sz--)
            q.inqueue(q.dequeue());

        added_elements++;
    }

public:
    Stack(const int &added_elements):
        q(added_elements){
    }

    void push(const int &value){
        insert_front(value);
    }
    int pop(){
        --added_elements;
        return q.dequeue();
    }
    int top(){
        return q.Front_val();
    }
    bool isEmpty(){
        return q.isEmpty();
    }
    bool isFull(){
        q.isFull();
    }
};

int main(){

	Stack stk(3);
	stk.push(10);
	stk.push(20);
	stk.push(30);

	while (!stk.isEmpty()){
		cout << stk.top() << " ";
		stk.pop();
	}

    // 30 20 10

    return 0;
}
