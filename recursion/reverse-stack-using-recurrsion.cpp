// https://www.codingninjas.com/studio/problems/reverse-stack-using-recursion_631875?leftPanelTabValue=SUBMISSION
// Category : Easy

    
void reverse(stack<int>& stack, vector<int>& temp) {
    int a = stack.top();
    stack.pop();
    temp.push_back(a);

    if ( !stack.empty() ) reverse(stack, temp);

    for (auto num: temp ) {
        stack.push(num);
    }
    temp.clear();
}

void reverseStack(stack<int> &stack) {
    vector<int> temp;
    reverse(stack, temp);
}