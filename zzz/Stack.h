#ifndef STACK_H
#define STACK_H

class Stack {
private:
    int* m_elements;
    int m_capacity;
    int m_topIndex;

    void resize();

public:
    Stack();
    Stack(const Stack& other);
    Stack& operator=(const Stack& other);
    ~Stack();
    int sum(int index);
    void push(int element);
    int pop();
    bool isEmpty() const;
    void multiPop(int count);
    void show() const;
};

#endif
