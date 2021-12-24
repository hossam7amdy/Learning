#include<iostream>
#include<assert.h>
using namespace std;

template<class type>
class Stack{
private:
    type *Array{ };
    int length;
    const int capacity;
public:
    Stack(const int &capacity):
        capacity(capacity), length(-1) {
            Array = new type[capacity];
    }

    void push(const type &data){
        assert(!isFull());
        Array[++length] = data;
    }
    bool isEmpty(){
        return length == -1;
    }
    bool isFull(){
        return length == capacity-1;
    }
    type top(){
        assert(!isEmpty());
        return Array[length];
    }
    type pop(){
        assert(!isEmpty());
        return Array[length--];
    }
    void insert_at_bottom(const int &data){ // time O(n) = memory O(n)
        if(isEmpty())
            push(data);
        else{
            int cur = pop();

            insert_at_bottom(data);

            push(cur);
        }
    }
    void Reverse(){
        if(isEmpty())
            return;

        int cur = pop();
        Reverse();
        insert_at_bottom(cur);
    }
    void Display() const {
        for(int i=length; i>=0; i--)
            cout << Array[i] << " ";
        cout << "\n";
    }
    void DisplayReversed(){
        for(int i=0; i<=length; i++)
            cout << Array[i] << " ";
        cout << "\n";
    }
    ~Stack(){ // time O(n) - memory O(1)
        delete[] Array;
    }
};


int main(){
    Stack<int> st(10);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.Display();

    st.Reverse();
    st.Display();


    return 0;
}
