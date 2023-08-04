void reverse(int top, stack<int> &S){
    if(S.empty()){
        S.push(top);
        return;
    }
    int top1 = S.top();
    S.pop();
    reverse(top,S);
    S.push(top1);
}



void reverseStack(stack<int> &stack) {
    if(stack.empty()){
        return;
    }
    int top = stack.top();
    stack.pop();
    reverseStack(stack);
    reverse(top,stack);
    return;
}