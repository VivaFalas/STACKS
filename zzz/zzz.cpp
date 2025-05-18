#include "Stack.h"
#include <iostream>

using namespace std;
int main() {
    Stack st;
    st.push(6);
    st.push(60);
    st.push(40);
    st.show();

    int a = st.sum(2);

    cout << a;


    return 0;
}