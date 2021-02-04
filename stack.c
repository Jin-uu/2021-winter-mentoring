#include "stack.h"
#include <string.h>

stack *stack_alloc(int cap)
{
    stack *new_stack = malloc(sizeof(stack));
    if(new_stack == NULL)
        return NULL;
    new_stack -> body = malloc(sizeof(element)*cap);
    new_stack -> capacity = cap;
    new_stack -> top = -1;
    return new_stack;
}

void stack_free(stack *this)
{
	free(this -> body);
    free(this);
}

bool stack_is_empty(stack *this)
{
    if(this -> top == -1)
        return true;
    else
        return false;
}

bool stack_is_full(stack *this)
{
    if(this -> top == this -> capacity -1)
        return true;
    else
        return false;
}

bool stack_expand(stack *this)
{
    if(stack_is_full(this) == false)
        return false;
	else
    {
        this -> body = realloc(this -> body, sizeof(element)*(this -> capacity)*2);
        this -> capacity *= 2;
        return true;
    }
}

bool stack_push(stack *this, element elem)
{
    if(stack_is_full(this) == true)
        stack_expand(this);
    else
    {
		this -> top++;
        this -> body[this -> top].number = elem.number;
		strcpy(this -> body[this -> top].name, elem.name);
    }       //성공실패 수정****
}

element *stack_top(stack *this)
{
    if(this -> top == -1)
        return NULL;
    else
        return &(this -> body[this -> top]);
}

bool stack_pop(stack *this)
{
    if(this -> top == -1)
        return false;
    else
    {
		strcpy(this -> body[this -> top].name, "deleted");
        this -> top--;
        return true;
    }
}

