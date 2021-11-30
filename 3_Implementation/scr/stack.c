/**
 * @file stack.c
 * @author Kavin Vignes
 * @brief 
 * @version 0.1
 * @date 2021-11-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "stack.h"

/**
 * @brief (Create a stack object with the given size)
 * 
 * @param s 
 * @return struct Stack* 
 */
struct Stack* create_stack(uint16_t s){
  struct Stack* stack = (struct Stack *) malloc(sizeof(struct Stack));
  stack ->size=s;
  stack ->top=-1;
  stack  -> data= (uint16_t*) malloc(stack-> size *sizeof(uint16_t));
  return stack;
}

/**
 * @brief (Adds item to the top of the stack)
 * 
 * @param stack 
 * @param item 
 */
void push(struct Stack* stack,uint16_t item){
  if(!is_full(stack)){
    stack->data[++stack->top]=item;
  }
  else
    return;
}

/**
 * @brief (Returns the top of the stack)
 * 
 * @param stack 
 * @return uint16_t 
 */
uint16_t peek(struct Stack* stack){
  if(!is_empty(stack)){
  return stack->data[stack->top];
  }
  return -1;
}

/**
 * @brief (Removes the item on the top of the stack)
 * 
 * @param stack 
 * @return uint16_t 
 */
uint16_t pop(struct Stack* stack){
  if(!is_empty(stack)){
    return stack->data[stack->top--];
  }
  return -1;
}

/**
 * @brief (Checks if the stack i empty)
 * 
 * @param stack 
 * @return uint8_t 
 */
uint8_t is_empty(struct Stack* stack){
  if(stack->top==-1)
    return IS_EMPTY;
  else
    return IS_NOT_EMPTY;
}

/**
 * @brief (Checks if the stack is full)
 * 
 * @param stack 
 * @return uint8_t 
 */
uint8_t is_full(struct Stack* stack){
  if(stack->top==stack->size)
    return IS_FULL;
  else
    return IS_NOT_FULL;
}
