#include "stack.h"
#include <iostream>

using namespace std;

Stack::Stack() : m_elements(new int[10]), m_capacity(10), m_topIndex(0) {}

Stack::Stack(const Stack& other)
    : m_elements(new int[other.m_capacity]), m_capacity(other.m_capacity), m_topIndex(other.m_topIndex) {
    for (int i = 0; i < m_topIndex; ++i)
        m_elements[i] = other.m_elements[i];
}

Stack& Stack::operator=(const Stack& other) {
    if (this != &other) {
        delete[] m_elements;
        m_capacity = other.m_capacity;
        m_topIndex = other.m_topIndex;
        m_elements = new int[m_capacity];
        for (int i = 0; i < m_topIndex; ++i)
            m_elements[i] = other.m_elements[i];
    }
    return *this;
}

Stack::~Stack() {
    delete[] m_elements;
}

void Stack::resize() {
    m_capacity *= 2;
    int* newElements = new int[m_capacity];
    for (int i = 0; i < m_topIndex; ++i)
        newElements[i] = m_elements[i];
    delete[] m_elements;
    m_elements = newElements;
}

void Stack::push(int element) {
    if (m_topIndex == m_capacity)
        resize();
    m_elements[m_topIndex++] = element;
}

int Stack::pop() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    return m_elements[--m_topIndex];
}

bool Stack::isEmpty() const {
    return m_topIndex == 0;
}

void Stack::multiPop(int count) {
    for (int i = 0; i < count && !isEmpty(); ++i) {
        pop();
    }
}

void Stack::show() const {
    for (int i = 0; i < m_topIndex; ++i)
        cout << m_elements[i] << " ";
    cout << endl;
}

int Stack::sum(int index) {

    int sum = 0;
    for (int i = 0; i <= index; ++i) {

        sum += m_elements[i];

    }
    return sum;


}