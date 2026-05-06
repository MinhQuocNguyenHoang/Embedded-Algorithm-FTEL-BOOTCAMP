bool isValid(char* s) {
    char stack[10000];
    int top = -1;

    while(*s){
        if(*s=='(' || *s=='{' || *s=='['){
            stack[++top] = *s;
        }
        else{
            if(top < 0) return false;

            char c = stack[top--];

            if((*s==')' && c!='(') ||
               (*s=='}' && c!='{') ||
               (*s==']' && c!='['))
                return false;
        }
        s++;
    }

    return top==-1;
}