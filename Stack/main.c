#include <stdio.h>
#include <stack.h>

int main()
{
    Stack s = create_stack();
    push(1, s);
    push(2, s);
    push(3, s);
    print_stack(s);
    return 0;
}
