// Infix to prefix and postfix

// #include <ctype.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #define MAX 100
// typedef struct {
//   int top;
//   int items[MAX];
// } Stack;
// void initStack(Stack *s) { s->top = -1; }
// int isEmpty(Stack *s) { return (s->top == -1); }
// int isFull(Stack *s) { return (s->top == MAX - 1); }
// void push(Stack *s, int value) {
//   if (isFull(s)) {
//     printf("Stack is full");
//     exit(1);
//   }
//   s->items[++(s->top)] = value;
// }
// int pop(Stack *s) {
//   if (isEmpty(s)) {
//     printf("Stack is empty");
//     exit(1);
//   }
//   return s->items[(s->top)--];
// }
// int peek(Stack *s) {
//   if (isEmpty(s)) {
//     printf("Cant Peek ,No ELemnts ");
//     exit(1);
//   }
//   return s->items[s->top];
// }
// int isOperator(char c) { return c == '+' || c == '*' || c == '/' || c == '-';
// } int precedence(char op) {
//   switch (op) {
//   case '+':
//   case '-':
//     return 1;
//   case '*':
//   case '/':
//     return 2;
//   default:
//     return 0;
//   }
// }
// void infixToPostfix(char infix[], char postfix[]) {
//   Stack s;
//   initStack(&s);
//   int i, j = 0;
//   for (int i = 0; infix[i] != '\0'; i++) {
//     char token = infix[i];
//     if (isdigit(token)) {
//       postfix[j++] = token;
//     } else if (token == '(') {
//       while (!isEmpty(&s) && peek(&s) != '(') {
//         postfix[j++] = pop(&s);
//       }
//       pop(&s);
//     } else if (isOperator(token)) {
//       while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(token)) {
//         postfix[j++] = pop(&s);
//       }
//       push(&s, token);
//     }
//   }
//   while (!isEmpty(&s)) {
//     postfix[j++] = pop(&s);
//   }
//   postfix[j] = '\0';
// }
// int evaluatePostfix(char postfix[]) {
//   Stack s;
//   initStack(&s);
//   int i;
//   for (int i = 0; postfix[0] != '\0'; i++) {
//     char token = postfix[i];
//     if (isdigit(token)) {
//       push(&s, token - '0');
//     } else if (isOperator(token)) {
//       int op2 = pop(&s);
//       int op1 = pop(&s);
//       int result;
//       switch (token) {
//       case '+':
//         result = op1 + op2;
//         break;
//       case '-':
//         result = op1 - op2;
//         break;
//       case '*':
//         result = op1 * op2;
//         break;
//       case '/':
//         result = op1 / op2;
//         break;
//       }
//       push(&s, result);
//     }
//   }
//   return pop(&s);
// }

// void reverseString(char str[]){
//   int n = strlen(str);
//   for(int i=0;i<n/2;i++){
//     char temp = str[i];
//     str[i]=str[n-i-1];
//     str[n-i-1]=temp;
//   }
// }
// void infixToPrefix(char infix[],char prefix[]){
//   reverseString(infix);
//   for(int i=0;infix[i]!='\0';i++){
//     char token = infix[i];
//     if(token == '('){
//       infix[i]=')';
//     }else if(token == ')'){
//       infix[i]='(';
//     }
//   }
//   char postfix[MAX];
//   infixToPostfix(infix, postfix);
//   reverseString(postfix);
//   strcpy(prefix,postfix);
// }
// int main() {
//   char infix[MAX], postfix[MAX],prefix[MAX];
//   printf("Enter Infix : ");
//   scanf("%s", infix);

//   infixToPostfix(infix, postfix);
//   infixToPrefix(infix, prefix);

//   printf("Infix : %s \n ", infix);
//   printf("postfix : %s \n ", postfix);
//   printf("prefix : %s \n ", prefix);

//   printf("Result Of Postfix : %s \n ", evaluatePostfix(postfix));
//   return 0;
// }

// ----------------------------------------------------

// 2 stack

// #include <stdio.h>
// #include <stdlib.h>
// #define MAX 8
// typedef struct {
//   int data[MAX];
//   int top1;
//   int top2;
// } TS;
// void initStack(TS *ts) {
//   ts->top1 = -1;
//   ts->top2 = MAX;
// }
// int isFull(TS *ts) { return ts->top1 + 1 == ts->top2; }
// int isEmpty1(TS *ts) { return ts->top1 == -1; }
// int isEmpty2(TS *ts) { return ts->top2 == MAX; }

// void pushStack1(TS *ts, int value) {
//   if (isFull(ts)) {
//     printf("Stack1 IS FULL ");
//     exit(1);
//   }

//   ts->data[++(ts->top1)] = value;
// }
// void pushStack2(TS *ts, int value) {
//   if (isFull(ts)) {
//     printf("Stack2 Is FUll");
//     exit(1);
//   }
//   ts->data[--(ts->top2)] = value;
// }
// int popStack1(TS *ts) {
//   if (isEmpty1(ts)) {
//     printf("Stack 1 is Empty ");
//     exit(1);
//   }
//   return ts->data[(ts->top1)--];
// }
// int popStack2(TS *ts) {
//   if (isEmpty2(ts)) {
//     printf("Stack 2 is Empty ");
//     exit(1);
//   }
//   return ts->data[(ts->top2)++];
// }
// void displayStack1(TS *ts) {
//   printf("\n Elements Of Stack 1 : \n ");
//   for (int i = 0; i <= ts->top1; i++) {
//     printf("%d ", ts->data[i]);
//   }
// }
// void displayStack2(TS *ts) {
//   printf("\n Elements Of Stack 2 : \n ");
//   for (int i = MAX - 1; i >= ts->top2; i--) {
//     printf("%d ", ts->data[i]);
//   }
// }
// int main() {
//   TS ts;
//   initStack(&ts);

//   while (1) {
//     printf("Enter Your Choise : \n 1.Push Stack 1 \n 2.Push Stack 2 \n 3.Pop
//     "
//            "Stack 1 \n 4.Pop Stack 2 \n 5.Display Stack 1 \n 6.Display Stack
//            2 "
//            "\n 7.Exit \n");

//     int choise, value;
//     scanf("%d", choise);
//     switch (choise) {
//     case 1:
//       printf("Enter Value : ");
//       pushStack1(&ts, scanf("%d", value));
//       break;
//     case 2:
//       printf("Enter Value : ");
//       pushStack2(&ts, scanf("%d", value));
//       break;
//     case 3:
//       printf("Popped ELement : %d  ", popStack1(&ts));
//       break;
//     case 4:
//       printf("Popped ELement : %d  ", popStack2(&ts));
//       break;
//     case 5:
//       displayStack1(&ts);
//       break;
//     case 6:
//       displayStack2(&ts);
//     case 7:
//       exit(1);
//     }
//   }
// }

// ----------------------------------------------------

// Factorial and fabnacci

// #include <ctype.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #define MAX 100
// typedef struct {
//   int top;
//   int items[MAX];
// } Stack;
// void initStack(Stack *s) { s->top = -1; }
// int isEmpty(Stack *s) { return (s->top == -1); }
// int isFull(Stack *s) { return (s->top == MAX - 1); }
// void push(Stack *s, int value) {
//   if (isFull(s)) {
//     printf("Stack is full");
//     exit(1);
//   }
//   s->items[++(s->top)] = value;
// }
// int pop(Stack *s) {
//   if (isEmpty(s)) {
//     printf("Stack is empty");
//     exit(1);
//   }
//   return s->items[(s->top)--];
// }
// int peek(Stack *s) {
//   if (isEmpty(s)) {
//     printf("Cant Peek ,No ELemnts ");
//     exit(1);
//   }
//   return s->items[s->top];
// }
// int factorial(int n) {
//   Stack s;
//   initStack(&s);

//   int result = 1;
//   while (n > 0) {
//     push(&s, n);
//     n--;
//   }
//   while (!isEmpty(&s)) {
//     result *= pop(&s);
//   }
//   return result;
// }

// void fabonacci(int n) {
//   Stack s1, s2;
//   initStack(&s1);
//   initStack(&s2);

//   push(&s1, 0);

//   if (n > 1) {
//     push(&s2, 1);
//   }
//   printf("Fabanacci Series : 0 ");
//   if(n>1){
//     printf("1 ");
//   };

//   for(int i=2;i<n;i++){
//     int a = pop(&s1);
//     int b = pop(&s2);
//     int fab = a + b;

//     printf("%d ",fab);
//     push(&s1, b);
//     push(&s2,fab);
//   }
// }
// int main() {
//   printf("ENter A Number : ");
//   int n;
//   scanf("%d", n);

//   printf("Factorial Of Number Is : %d ", factorial(n));
//   printf("Fabonacci Series ");
//   fabonacci(n);
// }

// ----------------------------------------------------

// Circular Deque
// #include <stdio.h>
// #include <stdlib.h>

// #define MAX 5
// typedef struct {
//   int data[MAX];
//   int front, rear;
// } Deque;

// void initDeque(Deque *dq) {
//   dq->front = -1;
//   dq->rear = -1;
// }
// int isEmpty(Deque *dq) { return (dq->front == -1); }
// int isFull(Deque *dq) {
//   return ((dq->front == 0 && dq->rear == MAX - 1) ||
//           (dq->front == dq->rear + 1));
// }
// void insertFront(Deque *dq, int value) {
//   if (isFull(&dq)) {
//     printf("Deque is full");
//     return;
//   }
//   if (dq->front == -1) {
//     dq->front = 0;
//     dq->rear = 0;
//   } else if (dq->front == 0) {
//     dq->front = MAX - 1;
//   } else {
//     dq->front = dq->front - 1;
//   }

//   dq->data[dq->front] = value;
// }
// void insertRear(Deque *dq, int value) {
//   if (isFull(&dq)) {
//     printf("Deque is full");
//     return;
//   }
//   if (dq->front == -1) {
//     dq->front = 0;
//     dq->rear = 0;
//   } else if (dq->rear == (MAX - 1)) {
//     dq->rear = 0;
//   } else {
//     dq->rear += 1;
//   }
//   dq->data[dq->rear] = value;
// }
// void deleteFront(Deque *dq) {
//   if (isEmpty(&dq)) {
//     printf("Deque is Empty");
//     return;
//   }
//   if (dq->front == dq->rear) {
//     dq->front = dq->rear = -1;
//   } else if (dq->front == MAX - 1) {
//     dq->front = 0;
//   } else {
//     dq->front += 1;
//   }
// }
// void deleteRear(Deque *dq) {
//   if (isEmpty(&dq)) {
//     printf("Deque is Empty");
//     return;
//   }
//   if (dq->front == dq->rear) {
//     dq->front = dq->rear = -1;
//   } else if (dq->rear == 0) {
//     dq->rear = MAX - 1;
//   } else {
//     dq->rear -= 1;
//   }
// }
// void displayQueue(Deque *dq) {
//   if (isEmpty(&dq)) {
//     printf("Deque is Empty");
//     return;
//   }
//   printf("Elements Are : ");
//   int i = dq->front;
//   if (dq->front <= dq->rear) {
//     while (i <= dq->rear) {
//       printf("%d ", dq->data[i++]);
//     }
//   } else {
//     while (i < MAX - 1) {
//       printf("%d ", dq->data[i++]);
//     }
//     i = 0;
//     while (i < dq->rear) {
//       printf("%d ", dq->data[i++]);
//     }
//   }
//   printf("\n");
// }
// int main() {
//   Deque dq;
//   initDeque(&dq);
//   insertRear(&dq, 1);
//   insertRear(&dq, 3);
//   insertRear(&dq, 9);
//   insertFront(&dq, 66);
//   insertFront(&dq, 22);
//   insertFront(&dq, 44);
//   displayQueue(&dq);
//   return 0;
// }

// ----------------------------------------------------

// 2 Queues
// #include <stdio.h>
// #include <stdlib.h>
// #define MAX 8
// typedef struct {
//   int data[MAX];
//   int front1, front2;
//   int rear1, rear2;
// } TQ;
// void initQueues(TQ *tq) {
//   tq->front1 = -1;
//   tq->front2 = MAX;
//   tq->rear1 = -1;
//   tq->rear2 = MAX;
// }
// int isFullQ1(TQ *tq) { return tq->rear1 + 1 == tq->front2; }
// int isFullQ2(TQ *tq) { return tq->rear2 - 1 == tq->rear1; }

// int isEmptyQ1(TQ *tq) { return tq->front1 == -1; }
// int isEmptyQ2(TQ *tq) { return tq->front2 == MAX; }
// void addQueue1(TQ *tq, int value) {
//   if (isFullQ1(tq)) {
//     printf("Queue Is Full");
//     return;
//   }
//   if (tq->front1 == -1) {
//     tq->front1 = 0;
//     tq->rear1 = 0;
//   } else {
//     tq->rear1++;
//   }
//   tq->data[tq->rear1] = value;
// }
// void addQueue2(TQ *tq, int value) {
//   if (isFullQ2(tq)) {
//     printf("Q2 Full");
//     return;
//   }
//   if (tq->front2 == MAX) {
//     tq->front2 = MAX - 1;
//     tq->rear2 = MAX - 1;
//   } else {
//     tq->rear2--;
//   }
//   tq->data[tq->rear2] = value;
// }
// void deleteQ1(TQ *tq) {
//   if (isEmptyQ1(tq)) {
//     printf("Q1 Empty");
//   }
//   printf("Deleted :  %d ", tq->data[tq->front1]);
//   if (tq->front1 == tq->rear1) {
//     tq->front1 = tq->rear1 = -1;
//   } else {
//     tq->front1++;
//   }
// }
// void deleteQ2(TQ *tq) {
//   if (isEmptyQ2(tq)) {
//     printf("Q2 Empty");
//   }
//   printf("Deleted :  %d ", tq->data[tq->front2]);
//   if (tq->front2 == tq->rear2) {
//     tq->front2 = tq->rear2 = MAX;
//   } else {
//     tq->front2--;
//   }
// }
// void displayQ1(TQ *tq) {
//   if (isEmptyQ1(tq)) {
//     printf("Q1 Is EMpty");
//   }
//   printf("ELements In Q1 ");
//   for (int i = tq->front1; i <= tq->rear1; i++) {
//     printf("%d ", tq->data[i]);
//   }
//   printf("\n");
// }
// void displayQ2(TQ *tq) {
//   if (isEmptyQ2(tq)) {
//     printf("Q2 Is EMpty");
//   }
//   printf("ELements In Q2 ");
//   for (int i = tq->rear2; i >= tq->front2; i--) {
//     printf("%d ", tq->data[i]);
//   }
//   printf("\n");
// }
// int main() {
//   TQ tq;
//   initQueues(&tq);
//   addQueue1(&tq, 34);
//   addQueue1(&tq, 67);
//   addQueue1(&tq, 78);
//   addQueue2(&tq, 98);
//   addQueue2(&tq, 98);
//   printf("Deleted %d ");
//   deleteQ1(&tq);
//   printf("Deleted %d ");
//   deleteQ1(&tq);
//   printf("Deleted %d ");
//   deleteQ1(&tq);
//   displayQ1(&tq);
//   displayQ2(&tq);
//   return 0;
// }

// ----------------------------------------------------

// Addition Of 2 polynomials
// #include <stdio.h>
// #include <stdlib.h>
// typedef struct {
//   int coeff;
//   int exp;
//   struct Node *next;
// } Node;

// Node *createNode(int coeff, int exp) {
//   Node *newNode = (Node *)malloc(sizeof(Node));
//   newNode->coeff = coeff;
//   newNode->exp = exp;
//   newNode->next = NULL;
//   return newNode;
// }
// void insert(Node **head, int coeff, int exp) {
//   Node *newNode = createNode(coeff, exp);
//   if (*head == NULL) {
//     *head = newNode;
//   } else {
//     Node *temp = *head;
//     while (temp->next != NULL) {
//       temp = temp->next;
//     }
//     temp->next = newNode;
//   }
// }
// void display(Node *head) {
//   if (head == NULL) {
//     printf("0");
//     return;
//   }
//   Node *temp = head;
//   while (temp != NULL) {
//     printf("%d^%d ", temp->coeff, temp->exp);
//     temp = temp->next;
//     if (temp != NULL) {
//       printf(" + ");
//     }
//   }
//   printf("\n");
// }
// Node *addPolynomials(Node *poly1, Node *poly2) {
//   Node *result = NULL;
//   Node *p1 = poly1;
//   Node *p2 = poly2;

//   if (p1->exp > p2->exp) {
//     insert(&result, p1->coeff, p1->exp);
//     p1 = p1->next;
//   } else if (p2->exp > p1->exp) {
//     insert(&result, p2->coeff, p2->exp);
//     p2 = p2->next;
//   } else {
//     insert(&result, p1->coeff + p2->coeff, p1->exp);
//     p1 = p1->next;
//     p2 = p2->next;
//   }
//   while (p1 != NULL) {
//     insert(&result, p1->coeff, p1->exp);
//     p1 = p1->next;
//   }
//   while (p2 != NULL) {
//     insert(&result, p2->coeff, p2->exp);
//     p2 = p2->next;
//   }
//   return result;
// }
// int main() {
//   Node *poly1 = NULL;
//   Node *poly2 = NULL;
//   insert(&poly1, 3, 3);
//   insert(&poly1, 4, 2);
//   insert(&poly1, 2, 1);
//   insert(&poly1, 1, 0);

//   insert(&poly2, 4, 2);
//   insert(&poly2, 3, 1);
//   insert(&poly2, 1, 0);

//   Node* result = addPolynomials(poly1, poly2);
//   printf("Sum Of Polynomials: \n ");
//   display(result);
//   return 0;
// }

// ----------------------------------------------------

// Reverse Pointers

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct {
//   int data;
//   struct Node *next;
// } Node;

// Node *createNode(int data) {
//   Node *newNode = (Node *)malloc(sizeof(Node));
//   newNode->data = data;
//   newNode->next = NULL;
//   return newNode;
// }
// void insert(Node **head, int data) {
//   Node *newNode = createNode(data);
//   if (*head == NULL) {
//     *head = newNode;
//   } else {
//     Node *temp = *head;
//     while (temp->next != NULL) {
//       temp = temp->next;
//     }
//     temp->next = newNode;
//   }
// }
// void display(Node *head) {
//   if (head == NULL) {
//     printf("List Is Empty");
//     return;
//   }
//   Node *temp = head;
//   while (temp != NULL) {
//     printf("%d ", temp->data);
//     temp = temp->next;
//   }
// }
// void reverse(Node **head) {
//   Node *prev = NULL;
//   Node *next = NULL;
//   Node *current = *head;
//   while (current != NULL) {
//     next = current->next;
//     current->next = prev;
//     prev = current;
//     current = next;
//   }
//   *head = prev;
// }
// int main() {
//   Node *head = NULL;
//   insert(&head, 34);
//   insert(&head, 67);
//   insert(&head, 90);
//   insert(&head, 77);

//   printf("Before Reverse : \n ");
//   display(head);
//   printf("After The Reverse : \n ");
//   reverse(&head);
//   display(head);
//   return 0;
// }

// ----------------------------------------------------

// Merge lists
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *prev;
  struct Node *next;
} Node;

Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}
void insertAtBeginning(Node **head, int data) {
  Node *newNode = createNode(data);
  if (*head == NULL) {
    *head = newNode;
  } else {
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
  }
  printf("Element Insert At Begin");
}
void insertAtEnd(Node **head, int data) {
  Node *newNode = createNode(data);
  if (*head == NULL) {
    *head = newNode;
  } else {
    Node *temp = *head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
  }
}
void insertAfter(Node *prevNode, int data) {
  if (prevNode == NULL) {
    printf("Previous Node Cannot Be Null");
    return;
  }
  Node *newNode = createNode(data);
  newNode->next = prevNode->next;
  prevNode->next = newNode;
  newNode->prev = prevNode;
  if (newNode->next != NULL) {
    newNode->next->prev = newNode;
  }
}
void deleteBegin(Node **head) {
  if (*head == NULL) {
    printf("List Is Empty");
    return;
  }
  Node *temp = *head;
  *head = (*head)->next;
  if (*head != NULL) {
    (*head)->prev = NULL;
  }
  printf("Deleted At Beginning");
  free(temp);
}
void deleteEnd(Node **head) {
  if (*head == NULL) {
    printf("List Is Empty");
    return;
  }
  Node *temp = *head;
  if (temp->next == NULL) {
    *head = NULL;
  } else {
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->prev->next = NULL;
  }
  free(temp);
}

void deleteNode(Node **head, Node *del) {
  if (*head == NULL || del == NULL) {
    printf("List Is Empty Or Node To Be Deleted Is Null");
    return;
  }
  if (*head == del) {
    *head = del->next;
  }
  if (del->next != NULL) {
    del->next->prev = del->prev;
  }
  if (del->prev != NULL) {
      del->prev->next = del->next;
    }
  free(del);
}
void display(Node *head) {
  if (head == NULL) {
    printf("List is empty.\n");
    return;
  }
  Node *temp = head;
  while (temp != NULL) {
    printf("%d <-> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

Node *mergeSortedListes(Node *head1, Node *head2) {
  if (head1 == NULL)
    return head2;
  if (head2 == NULL)
    return head1;

  Node *mergedHead = NULL;
  Node *mergedTail = NULL;

  if (head1->data <= head2->data) {
    mergedHead = head1;
    head1 = head1->next;
  } else {
    mergedHead = head2;
    head2 = head2->next;
  }
  mergedTail = mergedHead;

  while (head1 != NULL && head2 != NULL) {
    if (head1->data <= head2->data) {
      mergedTail->next = head1;
      head1->prev = mergedTail;
      head1 = head1->next;
    } else {
      mergedTail->next = head2;
      head2->prev = mergedTail;
      head2 = head2->next;
    }
    mergedTail = mergedTail->next;
  }
  if (head1 != NULL) {
    mergedTail->next = head1;
    head1->prev = mergedTail;
  }
  if (head2 != NULL) {
    mergedTail->next = head2;
    head2->prev = mergedTail;
  }
  return mergedHead;
}
int main() {
  Node *head = NULL;
  printf("\n");
  insertAtBeginning(&head, 40);
  printf("\n");
  display(head);
  insertAtBeginning(&head, 20);
  printf("\n");
  display(head);

  insertAtEnd(&head, 80);
  printf("\nInsrted End \n");
  display(head);
  insertAtEnd(&head, 90);
  printf("\nInsrted End \n");
  display(head);

  printf("\n");
  insertAfter(head->next, 34);

  printf("\nInserted After \n");
  display(head);

  printf("\n Begin Delete \n");
  deleteBegin(&head);
  display(head);

  printf("\n End Deleted \n");
  deleteEnd(&head);
  display(head);

  printf("\n");
  printf("SPecific node \n");
  deleteNode(&head, head->next->next);
  display(head);

  Node *head2 = NULL;
  insertAtBeginning(&head2, 100);
  insertAtBeginning(&head2, 200);
  insertAtBeginning(&head2, 300);
  printf("\n After Merging : \n ");
  Node *merged = mergeSortedListes(head, head2);
  display(merged);
  return 0;
}

*/

// ----------------------------------------------------

// // Stack and Queue Operations on LL
// #include <stdio.h>
// #include <stdlib.h>
// typedef struct Node {
//   int data;
//   struct Node *prev;
//   struct Node *next;
// } Node;

// Node *createNode(int data) {
//   Node *newNode = (Node *)malloc(sizeof(Node));
//   newNode->data = data;
//   newNode->prev = NULL;
//   newNode->next = NULL;
//   return newNode;
// }
// void push(Node **head, int data) {
//   Node *newNode = createNode(data);
//   if (*head == NULL) {
//     *head = newNode;
//   } else {
//     newNode->next = *head;
//     (*head)->prev = newNode;
//     *head = newNode;
//   }
// }
// int pop(Node **head) {
//   if (*head == NULL) {
//     printf("Stack Is Empty");
//     return -1;
//   }
//   Node *temp = *head;
//   int popped = temp->data;
//   *head = (*head)->next;
//   if (*head != NULL) {
//     (*head)->prev = NULL;
//   }
//   free(temp);
//   return popped;
// }
// void display(Node *head) {
//   if (head == NULL) {
//     printf("Empty ...");
//     return;
//   }
//   Node *temp = head;
//   while (temp != NULL) {
//     printf("%d -> ", temp->data);
//     temp = temp->next;
//   }
// }
// void enqueue(Node **front, Node **rear, int data) {
//   Node *newNode = createNode(data);
//   if (*rear == NULL) {
//     *front = *rear = newNode;
//   } else {
//     (*rear)->next = newNode;
//     newNode->prev = *rear;
//     *rear = newNode;
//   }
// }

// void dequeue(Node **front, Node **rear) {
//   if (*front == NULL) {
//     printf("Queue Is Empty");
//     return;
//   }
//   Node *temp = *front;
//   int data = temp->data;
//   *front = (*front)->next;
//   if (*front == NULL) {
//     *rear = NULL;
//   } else {
//     (*front)->prev = NULL;
//   }
//   free(temp);
// }

// // Function to display the queue
// void displayQueue(Node *front) {
//   if (front == NULL) {
//     printf("Queue is empty.\n");
//     return;
//   }
//   Node *temp = front;
//   while (temp != NULL) {
//     printf("%d -> ", temp->data);
//     temp = temp->next;
//   }
//   printf("NULL\n");
// }
// int main() {
//   Node *head = NULL;
//   push(&head, 10);
//   push(&head, 20);
//   push(&head, 30);
//   push(&head, 50);
//   printf("ENter Push \n");
//   display(head);
//   printf("After POP \n");
//   pop(&head);
//   display(head);
//   printf("\n After Enqueue : \n");
//   Node *front = NULL;
//   Node *rear = NULL;
//   enqueue(&front, &rear, 1000);
//   enqueue(&front, &rear, 2000);
//   displayQueue(front);

//   printf("\n After DEqueue : \n");
//   dequeue(&front, &rear);
//   displayQueue(front);
//   return 0;
// }

// ----------------------------------------------------

// Binary Tree
/*
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
} Node;
Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->left = newNode->right = NULL;
  newNode->data = data;
  return newNode;
}
Node *insert(Node *root, int data) {
  if (root == NULL) {
    root = createNode(data);
    return root;
  }
  Node *current = root;
  Node *parent = NULL;
  while (current != NULL) {
    parent = current;
    if (data < current->data) {
      current = current->left;
    } else {
      current = current->right;
    }
  }
  if (data < parent->data) {
    parent->left = createNode(data);
  } else {
    parent->right = createNode(data);
  }
  return root;
}
// https://replit.com/@adityakurapati2/BST#main2.c
void preorderTraversal(Node *root) {
  if (root == NULL) {
    return;
  }
  Node *stack[100];
  int top = -1;
  stack[++top] = root;
  while (top >= 0) {
    Node *node = stack[top--];
    printf("%d ", node->data);
    if (node->right != NULL) {
      stack[++top] = node->right;
    }
    if (node->left != NULL) {
      stack[++top] = node->left;
    }
  }
}

void inorderTraversal(Node *root) {
  if (root == NULL) {
    return;
  }
  Node *stack[30];
  int top = -1;
  Node *currentNode = root;

  while (currentNode != NULL || top >= 0) {
    while (currentNode != NULL) {
      stack[++top] = currentNode;
      currentNode = currentNode->left;
    }
    currentNode = stack[top--];
    printf("%d ", currentNode->data);
    currentNode = currentNode->right;
  }
}
void postOrderTraversal(Node *root) {
  if (root == NULL) {
    return;
  }
  Node *stack1[20];
  Node *stack2[20];
  int top1 = -1;
  int top2 = -1;

  stack1[++top1] = root;
  while (top1 >= 0) {
    Node *node = stack1[top1--];
    stack2[++top2] = node;

    if (node->left != NULL) {
      stack1[++top1] = node->left;
    }
    if (node->right != NULL) {
      stack1[++top1] = node->right;
    }
  }
  while (top2 >= 0) {
    Node *node = stack2[top2--];
    printf("%d ", node->data);
  }
}
int countLeafNodes(Node *root) {
  if (root == NULL) {
    return 0;
  }

  Node *stack[100];
  int top = -1;
  stack[++top] = root;
  int leafNodes = 0;

  while (top >= 0) {
    Node *node = stack[top--];
    if (node->left == NULL && node->right == NULL) {
      leafNodes++;
    } else {
      if (node->right != NULL) {
        stack[++top] = node->right;
      }
      if (node->left != NULL) {
        stack[++top] = node->left;
      }
    }
  }
  return leafNodes;
}
int countTotalNodes(Node *root) {
  if (root == NULL) {
    return 0;
  }
  Node *stack[30];
  int top = -1;
  stack[++top] = root;
  int nodeCount = 0;

  while (top >= 0) {
    Node *node = stack[top--];
    nodeCount++;
    if (node->right != NULL) {
      stack[++top] = node->right;
    }
    if (node->left != NULL) {
      stack[++top] = node->left;
    }
  }
  return nodeCount;
}
int heightOfTree(Node *root) {
  if (root == NULL) {
    return 0;
  }

  Node *stack[30];
  int top = -1;
  stack[++top] = root;
  int height = 0;
  Node *lastNode = NULL;

  while (top >= 0) {
    Node *currentNode = stack[top--];
    if (lastNode == NULL || lastNode->left == currentNode ||
        lastNode->right == currentNode) {
      if (currentNode->left != NULL) {
        stack[++top] = currentNode->left;
      } else if (currentNode->right != NULL) {
        stack[++top] = currentNode->right;
      }
    } else if (currentNode->left == lastNode) {
      if (currentNode->right != NULL) {
        stack[++top] = currentNode->right;
      }
    } else {
      top--;
    }
    lastNode = currentNode;
    if (top + 1 > height) {
      height = top + 1;
    }
  }
  return height;
}

void mirrorImage(Node *root) {
  if (root == NULL) {
    return;
  }

  Node *stack[30];
  int top = -1;
  stack[++top] = root;

  while (top >= 0) {
    Node *node = stack[++top];

    Node *temp = node->left;
    node->left = node->right;
    node->right = temp;

    if (node->left != NULL) {
      stack[++top] = node->left;
    }
    if (node->right != NULL) {
      stack[++top] = node->right;
    }
  }
}

void levelOrderTraversal(Node *root) {
  if (root == NULL) {
    return;
  }
  Node *queue[20];
  int front = 0, rear = 0;
  queue[rear++] = root;

  while (front < rear) {
    Node *node = queue[front++];
    printf("%d ", node->data);

    if (node->left != NULL) {
      queue[rear++] = node->left;
    }
    if (node->right != NULL) {
      queue[rear++] = node->right;
    }
  }
}
void displayLeafNodes(Node *root) {
  if (root == NULL) {
    return;
  }

  Node *stack[20];
  int top = -1;
  stack[++top] = root;

  while (top >= 0) {
    Node *node = stack[top--];
    if (node->left == NULL && node->right == NULL) {
      printf("%d ", node->data);
    } else {
      if (node->right != NULL) {
        stack[++top] = node->right;
      }
      if (node->left != NULL) {
        stack[++top] = node->left;
      }
    }
  }
}
int main() {

  Node *root = NULL;
  root = insert(root, 50);
  root = insert(root, 40);
  root = insert(root, 70);
  root = insert(root, 60);
  root = insert(root, 20);
  root = insert(root, 23);

  printf("\n PREORDER Traversal : \n ");
  preorderTraversal(root);
  printf("\n Postorder Traversal : \n ");
  postOrderTraversal(root);
  printf("\n Level Order  Traversal : \n ");
  levelOrderTraversal(root);
  printf("\n Leaf Nodes  : \n ");
  displayLeafNodes(root);
  printf("\nLeaf Nodes : %d ", countLeafNodes(root));
  printf("\n Total Nodes : %d ", countTotalNodes(root));
  printf("\n Height Of Treee  : %d ", heightOfTree(root));

  mirrorImage(root);
  printf("After Mirror Image : \n");
  inorderTraversal(root);
  return 0;
}
*/

// ----------------------------------------------------

// BST

/*
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *left, *right;
} Node;

Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

Node *insert(Node *root, int data) {
  if (root == NULL) {
    return createNode(data);
  }
  if (data < root->data) {
    root->left = insert(root->left, data);
  } else if (data > root->data) {
    root->right = insert(root->right, data);
  }
  return root;
}

Node *findMin(Node *root) {
  while (root->left != NULL) {
    root = root->left;
  }
  return root;
}

Node *deleteNode(Node *root, int data) {
  if (root == NULL) {
    return root;
  }
  if (data < root->data) {
    root->left = deleteNode(root->left, data);
  } else if (data > root->data) {
    root->right = deleteNode(root->right, data);
  } else {
    if (root->left == NULL) {
      Node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      Node *temp = root->left;
      free(root);
      return temp;
    }

    Node *temp = findMin(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
  }
  return root;
}

Node *findNode(Node *root, int data) {
  if (root == NULL || root->data == data) {
    return root;
  }
  if (data < root->data) {
    return findNode(root->left, data);
  } else {
    return findNode(root->right, data);
  }
}

void levelOrderTraversal(Node *root) {
  if (root == NULL) {
    return;
  }

  Node *queue[20];
  int front = 0;
  int rear = 0;
  queue[rear++] = root;

  while (front < rear) {
    Node *node = queue[front++];
    printf("%d ", node->data);

    if (node->left != NULL) {
      queue[rear++] = node->left;
    }
    if (node->right != NULL) {
      queue[rear++] = node->right;
    }
  }
  printf("\n");
}

void mirrorImage(Node *root) {
  if (root == NULL) {
    return;
  }

  Node *temp;
  mirrorImage(root->left);
  mirrorImage(root->right);

  temp = root->left;
  root->left = root->right;
  root->right = temp;
}

int height(Node *root) {
  if (root == NULL) {
    return -1;
  }
  int leftHeight = height(root->left);
  int rightHeight = height(root->right);
  return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

void displayLeafNodes(Node *root) {
  if (root == NULL) {
    return;
  }
  Node *stack[10];
  int top = -1;
  stack[++top] = root;
  while (top >= 0) {
    Node *node = stack[top--];

    if (node->left == NULL && node->right == NULL) {
      printf("%d ", node->data);
    } else {
      if (node->left != NULL) {
        stack[++top] = node->left;
      }
      if (node->right != NULL) {
        stack[++top] = node->right;
      }
    }
  }
  printf("\n");
}

Node *deleteNodeNR(Node *root, int data) {
  if (root == NULL) {
    return root;
  }

  Node *current = root;
  Node *parent = NULL;
  while (current != NULL && current->data != data) {
    parent = current;
    if (data < current->data) {
      current = current->left;
    } else {
      current = current->right;
    }
  }
  if (current == NULL)
    return root;

  if (current->left == NULL || current->right == NULL) {
    Node *newCurr;
    if (current->left == NULL) {
      newCurr = current->right;
    } else {
      newCurr = current->left;
    }

    if (parent == NULL) {
      free(current);
      return newCurr;
    }

    if (current == parent->left) {
      parent->left = newCurr;
    } else {
      parent->right = newCurr;
    }
    free(current);
  } else {
    Node *p = NULL;
    Node *temp;
    temp = current->right;
    while (temp->left != NULL) {
      p = temp;
      temp = temp->left;
    }
    if (p != NULL) {
      p->left = temp->right;
    } else {
      current->right = temp->right;
    }
    current->data = temp->data;
    free(temp);
  }
  return root;
}

Node *MirrorWithoutDisturb(Node *root) {
  if (root == NULL) {
    return NULL;
  }
  Node *newRoot = createNode(root->data);
  newRoot->left = MirrorWithoutDisturb(root->left);
  newRoot->right = MirrorWithoutDisturb(root->right);
  return newRoot;
}
int main() {
  Node *root = NULL;
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 60);
  root = insert(root, 80);

  levelOrderTraversal(root);
  printf("\nAfter Delete \n");
  root = deleteNode(root, 80);
  levelOrderTraversal(root);
  printf("\nAfter Mirror Image \n");
  mirrorImage(root);
  levelOrderTraversal(root);
  printf("Leaf Nodes ");
  displayLeafNodes(root);
  printf("\nAfter Deletion \n");
  root = deleteNodeNR(root, 60);
  levelOrderTraversal(root);
  printf("\nAfter Mirror DUP \n");
  Node *newRoot = MirrorWithoutDisturb(root);
  levelOrderTraversal(newRoot);

  return 0;
}

*/

// ----------------------------------------------------
// EMployee BST

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Employee {
  int empId;
  char name[20];
  struct Employee *left, *right;
} Employee;

Employee *createEmployee(int id, const char *name) {
  Employee *newEmployee = (Employee *)malloc(sizeof(Employee));
  newEmployee->empId = id;
  strcpy(newEmployee->name, name);
  newEmployee->left = NULL;
  newEmployee->right = NULL;
  return newEmployee;
}

Employee *insert(Employee *root, int id, const char *name) {
  if (root == NULL) {
    return createEmployee(id, name);
  }
  Employee *current = root;
  Employee *parent = NULL;
  while (current != NULL) {
    parent = current;
    if (id < current->empId) {
      current = current->left;
    } else if (id > current->empId) {
      current = current->right;
    } else {
      // Employee ID already exists
      printf("Employee with ID %d already exists.\n", id);
      return root;
    }
  }
  if (id < parent->empId) {
    parent->left = createEmployee(id, name);
  } else {
    parent->right = createEmployee(id, name);
  }
  return root;
}

Employee *search(Employee *root, int id) {
  if (root == NULL) {
    return NULL;
  }
  if (root->empId == id) {
    return root;
  }
  if (id < root->empId) {
    return search(root->left, id);
  } else {
    return search(root->right, id);
  }
}

void inorderTraversal(Employee *root) {
  if (root == NULL) {
    return;
  }
  Employee *stack[20];
  int top = -1;
  Employee *current = root;
  while (current != NULL || top >= 0) {
    while (current != NULL) {
      stack[++top] = current;
      current = current->left;
    }
    current = stack[top--];
    printf("%d . %s\n", current->empId, current->name);
    current = current->right;
  }
}

void freeTree(Employee *root) {
  if (root == NULL) {
    return;
  }
  freeTree(root->left);
  freeTree(root->right);
  free(root);
}

int main() {
  Employee *root = NULL; // Initialize root pointer
  int choice, emp_id;
  char emp_name[20];

  Employee *emp;

  root = insert(root, 1, "Aditya");
  root = insert(root, 2, "Suresh");
  root = insert(root, 3, "Ganesh");
  root = insert(root, 44, "Swapnil");
  root = insert(root, 5, "Guru");

  printf("Employees:\n");
  inorderTraversal(root);

  while (1) {
    printf("\n\n1. Insert Employee");
    printf("\n2. Search Employee");
    printf("\n3. Display All Employees");
    printf("\n4. Exit\n");
    printf("Enter Your Choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter Employee ID and Name: ");
      scanf("%d", &emp_id);
      scanf("%19s", emp_name); // Limit input to prevent buffer overflow
      root = insert(root, emp_id, emp_name);
      break;
    case 2:
      printf("Enter Employee ID to Search: ");
      scanf("%d", &emp_id);
      emp = search(root, emp_id);
      if (emp != NULL) {
        printf("Employee Found: %d . %s\n", emp->empId, emp->name);
      } else {
        printf("Employee with ID %d not found.\n", emp_id);
      }
      break;
    case 3:
      printf("All Employees:\n");
      inorderTraversal(root);
      break;
    case 4:
      freeTree(root);
      exit(0);
    default:
      printf("Invalid Choice\n");
    }
  }
}

*/

// ----------------------------------------------------
// TBST
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *left, *right;
  int lthread, rthread;
} Node;

Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  newNode->lthread = newNode->rthread = 1;
  return newNode;
}
Node *insert(Node *root, int data) {
  Node *newNode = createNode(data);

  if (root == NULL) {
    return newNode;
  }
  Node *current = root;
  Node *parent = NULL;
  while (current != NULL) {
    parent = current;
    if (data < current->data) {
      if (current->lthread == 0) {
        current = current->left;
      } else {
        break;
      }
    } else {
      if (current->rthread == 0) {
        current = current->right;
      } else {
        break;
      }
    }
  }
  if (data < parent->data) {
    newNode->left = parent->left;
    newNode->right = parent;
    parent->lthread = 0;
    parent->left = newNode;
  } else {
    newNode->right = parent->right;
    newNode->left = parent;
    parent->right = newNode;
    parent->rthread = 0;
  }
  return root;
}

Node *leftMost(Node *node) {
  if (node == NULL) {
    return NULL;
  }
  while (node->lthread == 0) {
    node = node->left;
  }
  return node;
}
void preorderTraversal(Node *root) {
  if (root == NULL) {
    return;
  }
  Node *current = root;
  while (current != NULL) {
    printf("%d ", current->data);

    if (current->lthread == 0) {
      current = current->left;
    } else {
      while (current != NULL && current->rthread == 1) {
        current = current->right;
      }
      if (current != NULL) {
        current = current->right;
      }
    }
  }
  printf("\n");
}

void inorderTraversal(Node *root) {
  if (root == NULL) {
    return;
  }

  Node *current = leftMost(root);
  while (current != NULL) {
    printf("%d ", current->data);

    if (current->rthread == 0) {
      current = current->right;
    } else {
      current = leftMost(current->right);
    }
  }
}
int main() {
  Node *root = NULL;
  root = insert(root, 20);
  root = insert(root, 35);
  root = insert(root, 40);
  root = insert(root, 50);
  printf("Inorder Traversal \n ");
  inorderTraversal(root);
}

*/

// ----------------------------------------------------
// AVL TREE

/*
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *left, *right;
  int height;
} Node;

Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->left = newNode->right = NULL;
  newNode->data = data;
  newNode->height = 1;
  return newNode;
}
int height(Node *node) {
  if (node == NULL) {
    return 0;
  }
  return node->height;
}
int getBalance(Node *node) {
  if (node == NULL) {
    return 0;
  }
  return height(node->left) - height(node->right);
}
Node *leftRotate(Node *x) {
  Node *y = x->right;
  Node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;
  return y;
}
Node *rightRotate(Node *y) {
  Node *x = y->left;
  Node *T2 = x->right;

  x->right = y;
  y->left = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return x;
}
Node *insertNode(Node *node, int data) {
  if (node == NULL) {
    return createNode(data);
  }
  if (data < node->data) {
    node->left = insertNode(node->left, data);
  } else if (data > node->data) {
    node->right = insertNode(node->right, data);
  } else {
    return node;
  }

  node->height = 1 + max(height(node->left), height(node->right));
  int balance = getBalance(node);
  // LL
  if (balance > 1 && data < node->left->data) {
    return rightRotate(node);
  }
  // LR
  if (balance > 1 && data > node->left->data) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }
  // RR
  if (balance < -1 && data > node->right->data) {
    return leftRotate(node);
  }

  // RL
  if (balance < -1 && data < node->right->data) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }
  return node;
}
void levelOrderTraversal(Node *root) {
  if (root == NULL) {
    return;
  }
  Node *queue[20];
  int front = 0, rear = 0;
  queue[rear++] = root;
  while (front < rear) {
    Node *node = queue[front++];
    printf("%d ", node->data);

    if (node->left != NULL) {
      queue[rear++] = node->left;
    }
    if (node->right != NULL) {
      queue[rear++] = node->right;
    }
  }
}
int max(int a, int b) { return (a > b) ? a : b; }
int main() {
  Node *root = NULL;
  root = insertNode(root, 10);
  root = insertNode(root, 20);
  root = insertNode(root, 50);
  root = insertNode(root, 90);
  root = insertNode(root, 200);

  printf("Level Wise Traversal : \n");
  levelOrderTraversal(root);
  return 0;
}

*/

// ----------------------------------------------------
// Graphs

/*
#include <stdio.h>
#include <stdlib.h>
void createGraph(int adjMatrix[][100], int vertices, int edges);
void BFS(int adjMatrix[][100], int vertices, int startVertex);
void enqueue(int queue[], int *rear, int value);
int dequeue(int queue[], int *front, int *rear);
int isEmpty(int front, int rear);

int main() {
  int vertices, edges;
  printf("\nENter Number OF Vertices : ");
  scanf("%d", &vertices);
  printf("\nEnter Number Of Edges : ");
  scanf("%d", &edges);

  int adjMatrix[100][100] = {0};
  createGraph(adjMatrix, vertices, edges);

  int startVertex;
  printf("\n ENter The Start Verted : \n");
  scanf("%d", &startVertex);

  printf("\n BFS : \n");
  BFS(adjMatrix, vertices, startVertex);
  return 0;
}
void createGraph(int adjMatrix[][100], int vertices, int edges) {
  int i, u, v;
  for (int i = 0; i < edges; i++) {
    printf("Enter Edge(u,v) : ");
    scanf("%d %d", &u, &v);
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
  }
}

void BFS(int adjMatrix[][100], int vertices, int startVertex) {
  int visited[100] = {0};
  int queue[100];
  int front = -1, rear = -1;

  visited[startVertex] = 1;
  enqueue(queue, &rear, startVertex);
  while (!isEmpty(front, rear)) {
    int currentvertex = dequeue(queue, &front, &rear);
    printf("%d ", currentvertex);

    for (int i = 0; i < vertices; i++) {
      if (adjMatrix[currentvertex][i] == 1 && !visited[i]) {
        visited[i] = 1;
        enqueue(queue, &rear, i);
      }
    }
  }
}
void enqueue(int queue[], int *rear, int value) {
  if (*rear == 99) {
    printf("Queue OverFlow");
    return;
  }
  if (*rear == -1) {
    *rear = 0;
  } else {
    (*rear)++;
  }
  queue[*rear] = value;
}
int dequeue(int queue[], int *front, int *rear) {
  if (isEmpty(*front, *rear)) {
    printf("Queue UnderFlow");
    return -1;
  }
  if (*front == -1) {
    *front = 0;
  }
  int value = queue[*front];
  if (*front == *rear) {
    *front = *rear = -1;
  } else {
    (*front)++;
  }
  return value;
}
int isEmpty(int front, int rear) { return front == -1 && rear == -1; }

*/

// ----------------------------------------------------
// Adjacency Matrix BFS AND DFS
/*
#include <stdio.h>
#include <stdlib.h>

int queue[100], front = -1, rear = -1;
int stack[20],top=-1;
int isEmptystack(){
  return top==-1;
}
void push(int value){
  if(top==99){
    printf("Stack Overflow");
  }else{
    stack[++top]=value;
  }
}
int pop(){
  if(isEmptystack()){
    printf("Stack EMpty");
    return -1;
  }
  return stack[top--];
}
void createGraphMatrix(int adjMatrix[][100], int vertices, int edges) {
  int i, u, v;
  for (i = 0; i < edges; i++) {
    printf("Enter Edge(u,v) : ");
    scanf("%d %d", &u, &v);
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
  }
}
int isEmptyQ() { return front == -1 && rear == -1; }
void enqueueQ(int value) {
  if ((rear + 1) % 100 == front) {
    printf("Queue Overflow");
  }
  if (isEmptyQ()) {
    front = 0;
    rear = 0;
  } else {
    rear = (rear + 1) % 100;
  }
  queue[rear] = value;
}
int dequeueQ() {
  if (isEmptyQ()) {
    printf("Queue Underflow");
    return -1;
  } else {
    int data = queue[front];
    if (front == rear) {
      front = rear = -1;
    } else {
      front = (front + 1) % 100;
    }

    return data;
  }
}
void BFS(int adjMatrix[][100],int vertices,int start){
  int visited[100] ={0};
  int startVertex,u,i;

  u = startVertex;
  // printf("%c ",((char)startVertex+65));

  printf("%d ", startVertex);
  enqueueQ(u);
  visited[u]=1;

  while(!isEmptyQ()){
    u = dequeueQ();
    for(i=0;i<vertices;i++){
      if(adjMatrix[u][i]==1 && visited[i]==0){
        printf(" %d ",i);
        enqueueQ(i);
        visited[i]=1;
      }
    }
  }
}

void DFS(int adjMatrix[][100],int vertices,int start){
  int visited[100]={0};
  int u,i,startVertex=start;

  u = startVertex;
  printf("\nDFS : \n");
  printf("%d ",startVertex);
  visited[startVertex]=1;
  push(startVertex);

  while(!isEmptystack()){
    int found=0;
    for(i=0;i<vertices;i++){
      if(adjMatrix[u][i]==1 && visited[i]==0){
        printf("%d",i);
        push(i);
        visited[i]=1;\


        u = i;
        found=1;
        break;
      }
    }
    if(!found){
      u = pop();
    }
  }
}

int main(){
  int vertices,edges;
  printf("Enter Number Of Vertices and edges");
  scanf("%d %d",&vertices,&edges);
  int adjMatrix[vertices][vertices];
  createGraphMatrix(adjMatrix,vertices,edges);
  printf("\n BFS Traversal : \n ");
  BFS(adjMatrix,vertices,0);
  printf("\n DFS Traversal : \n ");
  DFS(adjMatrix,vertices,0);
}

*/

// ----------------------------------------------------
// Adjacency List BFS AND DFS

/*
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 8
typedef struct Node {
  int vertex;
  struct Node *next;
} Node;
typedef struct Graph {
  int numVertices;
  struct Node **adjLists;
} Graph;
typedef struct Queue {
  struct Node *front;
  struct Node *rear;
} Queue;
Node *createNode(int vertex) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->vertex = vertex;
  newNode->next = NULL;
  return newNode;
}
Graph *createGraph(int vertices) {
  Graph *graph = (Graph *)malloc(sizeof(Graph));
  graph->numVertices = vertices;
  graph->adjLists = (Node **)malloc(sizeof(Node *));
  for (int i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
  }
  return graph;
}
void addEdge(Graph *graph, int src, int dest) {
  Node *newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}
Queue *createQueue() {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  queue->front = queue->rear = NULL;
  return queue;
}
void enque(Queue *queue, int data) {
  Node *newNode = createNode(data);
  if (queue->rear == NULL) {
    queue->front = queue->rear = createNode(data);
    return;
  }
  queue->rear->next = newNode;
  queue->rear = newNode;
}
int dequeue(Queue *queue) {
  if (queue->front == NULL) {
    printf("EMpty QUeue");
    return -1;
  }
  Node *temp = queue->front;
  int vertex = temp->vertex;
  queue->front = queue->front->next;
  if (queue->front == NULL) {
    queue->rear = NULL;
  }
  free(temp);
  return vertex;
}
int isEmpty(Queue *queue) {
  return queue->front == NULL && queue->rear == NULL;
}

// ----------------------------------------------------
void BFS(Graph *graph, int start) {
  int *visited = (int *)malloc(graph->numVertices * sizeof(int));
  for (int i = 0; i < graph->numVertices; ++i) {
    visited[i] = 0;
  }
  Queue *queue = createQueue();
  visited[start] = 1;
  printf("%d ", start);
  enque(queue, start);

  while (!isEmpty(queue)) {
    int u = dequeue(queue);
    Node *temp = graph->adjLists[u];
    while (temp) {
      int adjVertex = temp->vertex;
      if (!visited[adjVertex]) {
        printf("%d ", adjVertex);
        visited[adjVertex] = 1;
        enque(queue, adjVertex);
      }
      temp = temp->next;
    }
  }
}

// ----------------------------------------------------
// DFS
typedef struct Stack {
  int items[MAX_VERTICES];
  int top;
} Stack;
Stack *createStack() {
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack->top = -1;
  return stack;
}
void push(Stack *stack, int value) {
  if (stack->top == MAX_VERTICES - 1) {
    printf("Stack Overflow");
  }
  stack->items[++stack->top] = value;
}
int pop(Stack *stack) {
  if (stack->top == -1) {
    printf("Stack Underflow");
    return -1;
  }
  return stack->items[stack->top--];
}
int isEmptyStack(Stack *stack) { return stack->top == -1; }
void DFS(Graph *graph, int start) {
  int *visited = (int *)malloc(sizeof(int));
  for (int i = 0; i < graph->numVertices; ++i) {
    visited[i] = 0;
  }

  Stack *stack = createStack();
  printf("%d ", start);
  visited[start] = 1;
  push(stack, start);

  while (!isEmptyStack(stack)) {
    int u = pop(stack);
    if (!visited[u]) {
      visited[u] = 1;
      printf("%d ", u);
    }
    Node *temp = graph->adjLists[u];
    while (temp) {
      int adjVertex = temp->vertex;
      if (!visited[adjVertex]) {
        push(stack, adjVertex);
      }
      temp = temp->next;
    }
  }
}
int main() {
  Graph *graph = createGraph(8);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 4);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 4);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 4);
  addEdge(graph, 3, 5);
  addEdge(graph, 4, 5);
  addEdge(graph, 4, 6);
  addEdge(graph, 5, 6);
  addEdge(graph, 6, 7);
  printf("BFS LIST : ");
  BFS(graph, 0);
  DFS(graph, 0);
}

*/

// WAP to implement Heap sort on 1D array of Student structure (contains
// student_name, student_roll_no, total_marks), with key as student_roll_no. And
// count the number of swap performed.

// ----------------------------------------------------
/* Heap Sort
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[20];
  int roll_no;
  int total_marks;
} Student;

void swap(Student *a, Student *b) {
  Student temp = *a;
  *a = *b;
  *b = temp;
}
void heapify(Student students[], int n, int i, int *swap_count) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && left > students[left].roll_no > largest) {
    largest = left;
  }
  if (right < n && students[right].roll_no > largest) {
    largest = right;
  }
  if (largest != i) {
    swap(&students[i], &students[largest]);
    (*swap_count)++;
    heapify(students, n, i, swap_count);
  }
}

void heap_sort(Student students[], int n, int *swap_count) {
  // Build The Heap
  for (int i = n / 2; i >= 0; i--) {
    heapify(students, n, i, swap_count);
  }

  for (int i = n - 1; i > 0; i--) {
    swap(&students[0], &students[i]);
    (*swap_count)++;
    heapify(students, n, i, swap_count);
  }
}

int main() {
  int n, swap_count = 0;

  printf("\n Enter The Number Of Students : \n");
  scanf("%d", &n);

  Student students[n];
  for (int i = 0; i < n; i++) {
    printf("\n Enter The Name Of Student : \n");
    scanf("%s", students[i].name);
    printf("\n Enter Students Id         : \n");
    scanf("%d", &students[i].roll_no);
    printf("\n Enter The Total Marks  : \n");
    scanf("%d", &students[i].total_marks);
  }

  heap_sort(students, n, &swap_count);

  printf("\n Totals Swaps : %d \n", swap_count);
  printf("\nHere Is The Sorted Data Of Students : \n ");
  for (int i = 0; i < n; i++) {
    printf("\n Name : %s", students[i].name);
    printf("\n Roll : %d", students[i].roll_no);
    printf("\n Total Marks  : %d", students[i].total_marks);
    printf("\n -----------------------------");
  }
  return 0;
}

*/

// ----------------------------------------------------
// Quick SOrt

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
  int emp_id;
  float emp_salary;
  char emp_name[20];
} Employee;

void swap(Employee *a, Employee *b) {
  Employee temp = *a;
  *a = *b;
  *b = temp;
}
int partitions(Employee employees[], int low, int high, int *swap_count) {
  int pivot = employees[high].emp_id;
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++) {
    if (employees[j].emp_id < pivot) {
      i++;
      swap(&employees[i], &employees[j]);
      (*swap_count)++;
    }
  }
  swap(&employees[i + 1], &employees[high]);
  (*swap_count)++;

  return (i + 1);
}
void quickSort(Employee employees[], int low, int high, int *swap_count) {
  if (low < high) {
    int pi = partitions(employees, low, high, swap_count);
    quickSort(employees, low, pi-1, swap_count);
    quickSort(employees, pi+1,high, swap_count);
  }
}

*/

// ----------------------------------------------------

// Find Misplaced Elements
/*
#include <stdio.h>
void findSwapppedElement(int arr[], int n) {
  int x = -1, y = -1;
  int prev = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] < prev) {
      if (x == -1) {
        x = i - 1;
        y = i;
      } else {
        y = i;
      }
    }
    prev = arr[i];
  }

  if (x != -1 && y != -1) {
    printf("Swapped Elemetns Are %d & %d : %d - %d ", arr[x], arr[y], x, y);
  } else {
    printf("No ELements Are Swaped ");
  }
}
int main() {
  int arr[] = {1, 4, 3, 5, 8, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  findSwapppedElement(arr, n);
}

*/

// ----------------------------------------------------
// Hashing

/*
#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10
typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct HashTable {
  int key;
  Node *chain;
} HashTable;

HashTable tableWithoutReplacement[TABLE_SIZE];
HashTable tableWithReplacement[TABLE_SIZE];

Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}
void initHashTable(HashTable table[]) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    table[i].key = -1;
    table[i].chain = NULL;
  }
}

int hashFunction(int key) { return key % TABLE_SIZE; }
int insertWithoutReplacement(int key) {
  int index = hashFunction(key);
  int collisions = 0;

  while (tableWithoutReplacement[index].key != -1) {
    index = (index + 1) % TABLE_SIZE;
    collisions++;
  }
  tableWithoutReplacement[index].key = key;
  tableWithoutReplacement[index].chain = createNode(key);
  return collisions;
}
int insertWithReplacement(int key) {
  int index = hashFunction(key);
  int collision = 0;
  while (tableWithReplacement[index].key != -1) {
    int currentKey = tableWithReplacement[index].key;
    if (hashFunction(currentKey) == index) {
      collision++;
      index = (index + 1) % TABLE_SIZE;
    } else {
      Node *oldChain = tableWithReplacement[index].chain;
      tableWithReplacement[index].key = key;
      tableWithReplacement[index].chain = createNode(key);

      key = currentKey;
      index = (index + 1) % TABLE_SIZE;

      while (tableWithReplacement[index].key != -1) {
        collision++;
        index = (index + 1) % TABLE_SIZE;
      }
      tableWithReplacement[index].key = key;
      tableWithReplacement[index].chain = oldChain;
      return collision;
    }
  }
  tableWithReplacement[index].key = key;
  tableWithReplacement[index].chain = createNode(key);
  return collision;
}
void displayTable(HashTable table[]) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    printf("%d | %d ", i, table[i].key);
    Node *temp = table[i].chain;
    while (temp != NULL) {
      printf("-> %d ", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
}
int main() {
  int keys[] = {10, 22, 31, 4, 15, 28, 17, 88, 59};
  int n = sizeof(keys) / sizeof(keys[0]);

  initHashTable(tableWithReplacement);
  initHashTable(tableWithoutReplacement);

  int collisionsWithoutReplacement = 0;
  int collisionsWithReplacement = 0;

  for (int i = 0; i < n; i++) {
    collisionsWithReplacement += insertWithReplacement(keys[i]);
    collisionsWithoutReplacement += insertWithoutReplacement(keys[i]);
    printf("\nAfter ADDING %d \n", keys[i]);
    printf("collisionsWithReplacement : %d \n", collisionsWithReplacement);
    printf("collisionsWithReplacement : %d \n", collisionsWithReplacement);
  }
  printf("\n With Replacement : \n");
  displayTable(tableWithReplacement);
  printf("\nWithout Replacement : \n");
  displayTable(tableWithoutReplacement);
}

*/

// ----------------------------------------------------
// Prims ALgorithm
/*
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int vertex, weight;
  struct Node *next;
} Node;

typedef struct Graph {
  int numVertices;
  Node **adjLists;
} Graph;

typedef struct Edge {
  int src, dest, weight;
} Edge;

typedef struct Subset {
  int parent;
  int rank;
} Subset;

Node *createNode(int vertex, int weight) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->vertex = vertex;
  newNode->weight = weight;
  newNode->next = NULL;
  return newNode;
}

Graph *createGraph(int vertices) {
  Graph *graph = (Graph *)malloc(sizeof(Graph));
  graph->numVertices = vertices;
  graph->adjLists = (Node **)malloc(vertices * sizeof(Node *));
  for (int i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
  }
  return graph;
}

void addEdge(Graph *graph, int src, int dest, int weight) {
  Node *newNode = createNode(dest, weight);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  newNode = createNode(src, weight);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}

int minKey(int key[], int mstSet[], int vertices) {
  int min = INT_MAX, minIndex;
  for (int v = 0; v < vertices; v++) {
    if (mstSet[v] == 0 && key[v] < min) {
      min = key[v], minIndex = v;
    }
  }
  return minIndex;
}

void printMST(int parent[], int vertices, Graph *graph) {
  printf("Edge \t Weight\n");
  for (int i = 1; i < vertices; i++) {
    Node *temp = graph->adjLists[i];
    while (temp != NULL) {
      if (temp->vertex == parent[i]) {
        printf("%d - %d \t%d\n", parent[i], i, temp->weight);
        break;
      }
      temp = temp->next;
    }
  }
}

void primsMST(Graph *graph) {
  int vertices = graph->numVertices;
  int keys[vertices];
  int mstSet[vertices];
  int parent[vertices];

  for (int i = 0; i < vertices; i++) {
    keys[i] = INT_MAX, mstSet[i] = 0;
  }
  keys[0] = 0;
  parent[0] = -1;

  for (int count = 0; count < vertices - 1; count++) {
    int u = minKey(keys, mstSet, vertices);
    mstSet[u] = 1;

    Node *temp = graph->adjLists[u];
    while (temp != NULL) {
      int v = temp->vertex;
      if (mstSet[v] == 0 && temp->weight < keys[v]) {
        parent[v] = u;
        keys[v] = temp->weight;
      }
      temp = temp->next;
    }
  }
  printMST(parent, vertices, graph);
}

// Kruskal's Algorithm Functions
int find(Subset subsets[], int i) {
  if (subsets[i].parent != i) {
    subsets[i].parent = find(subsets, subsets[i].parent);
  }
  return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y) {
  int rootx = find(subsets, x);
  int rooty = find(subsets, y);
  if (subsets[rootx].rank < subsets[rooty].rank) {
    subsets[rootx].parent = rooty;
  } else if (subsets[rootx].rank > subsets[rooty].rank) {
    subsets[rooty].parent = rootx;
  } else {
    subsets[rooty].parent = rootx;
    subsets[rootx].rank++;
  }
}

int compareEdges(const void *a, const void *b) {
  Edge *edgeA = (Edge *)a;
  Edge *edgeB = (Edge *)b;
  return edgeA->weight - edgeB->weight;
}

void kruskalMST(Graph *graph, Edge edges[], int edgeCount) {
  Edge result[graph->numVertices];
  int e = 0;
  int i = 0;

  qsort(edges, edgeCount, sizeof(Edge), compareEdges);

  Subset *subsets = (Subset *)malloc(graph->numVertices * sizeof(Subset));
  for (int v = 0; v < graph->numVertices; v++) {
    subsets[v].parent = v;
    subsets[v].rank = 0;
  }

  while (e < graph->numVertices - 1 && i < edgeCount) {
    Edge nextEdge = edges[i++];
    int x = find(subsets, nextEdge.src);
    int y = find(subsets, nextEdge.dest);

    if (x != y) {
      result[e++] = nextEdge;
      Union(subsets, x, y);
    }
  }

  printf("Edges in Kruskal's MST:\n");
  printf("Src - Dest \tWeight\n");
  for (i = 0; i < e; i++) {
    printf("%d - %d \t%d\n", result[i].src, result[i].dest, result[i].weight);
  }
  free(subsets);
}

// Dijkstra's Algorithm Functions
void dijkstra(Graph *graph, int src) {
  int vertices = graph->numVertices;
  int dist[vertices];
  int visited[vertices];

  for (int i = 0; i < vertices; i++) {
    dist[i] = INT_MAX;
    visited[i] = 0;
  }
  dist[src] = 0;

  for (int i = 0; i < vertices - 1; i++) {
    int u = minKey(dist, visited, vertices);
    visited[u] = 1;

    Node *temp = graph->adjLists[u];
    while (temp != NULL) {
      int v = temp->vertex;
      if (!visited[v] && dist[u] != INT_MAX &&
          dist[u] + temp->weight < dist[v]) {
        dist[v] = dist[u] + temp->weight;
      }
      temp = temp->next;
    }
  }

  printf("Vertex \tDistance from Source\n");
  for (int i = 0; i < vertices; i++) {
    printf("%d \t%d\n", i, dist[i]);
  }
}

int main() {
  Graph *graph = createGraph(6);
  addEdge(graph, 0, 1, 6);
  addEdge(graph, 0, 2, 5);
  addEdge(graph, 1, 2, 2);
  addEdge(graph, 1, 3, 6);
  addEdge(graph, 2, 3, 3);
  addEdge(graph, 2, 4, 8);
  addEdge(graph, 3, 4, 4);
  addEdge(graph, 3, 5, 9);
  addEdge(graph, 4, 5, 7);

  printf("Prim's MST:\n");
  primsMST(graph);

  Edge edges[] = {{0, 1, 6}, {0, 2, 5}, {1, 2, 2}, {1, 3, 6}, {2, 3, 3},
                  {2, 4, 8}, {3, 4, 4}, {3, 5, 9}, {4, 5, 7}};
  int edgeCount = sizeof(edges) / sizeof(edges[0]);

  printf("\nKruskal's MST:\n");
  kruskalMST(graph, edges, edgeCount);

  printf("\nDijkstra's Algorithm:\n");
  dijkstra(graph, 0);

  return 0;
}
*/
// ----------------------------------------------------
// Using Matrix
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct Graph {
  int numVertices;
  int **matrix;
} Graph;
typedef struct Subset {
  int parent;
  int rank;
} Subset;
typedef struct Edge {
  int src, dest, weight;
} Edge;

Graph *createGraph(int vertices) {
  Graph *graph = (Graph *)malloc(sizeof(Graph));
  graph->numVertices = vertices;

  graph->matrix = (int **)malloc(sizeof(int *));
  for (int i = 0; i < vertices; i++) {
    graph->matrix[i] = (int *)malloc(sizeof(int));
    for (int j = 0; j < vertices; j++) {
      graph->matrix[i][j] = 0;
    }
  }
}
void addEdge(Graph *graph, int src, int dest, int weight) {
  graph->matrix[src][dest] = weight;
  graph->matrix[dest][src] = weight;
}
void printGraph(Graph *graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    for (int j = 0; j < graph->numVertices; j++) {
      printf("%d ", graph->matrix[i][j]);
    }
    printf("\n");
  }
}
int minKey(int keys[], int mstSet[], int vertices) {
  int min = INT_MAX, minIndex;
  for (int v = 0; v < vertices; v++) {
    if (mstSet[v] == 0 && keys[v] < min) {
      min = keys[v];
      minIndex = v;
    }
  }
  return minIndex;
}
void prims(Graph *graph) {
  int vertices = graph->numVertices;
  int keys[vertices];
  int mstSet[vertices];
  int parent[vertices];

  for (int i = 0; i < vertices; i++) {
    mstSet[i] = 0;
    keys[i] = INT_MAX;
  }
  keys[0] = 0;
  parent[0] = -1;

  for (int i = 0; i < vertices; i++) {
    int u = minKey(keys, mstSet, vertices);
    mstSet[u] = 1;

    for (int v = 0; v < vertices; v++) {
      if (graph->matrix[u][v] && mstSet[v] == 0 &&
          graph->matrix[u][v] < keys[v]) {
        parent[v] = u;
        keys[v] = graph->matrix[u][v];
      }
    }
  }
  printf("Prims MST : \n ");
  for (int i = 0; i < vertices - 1; i++) {
    printf("%d - %d \t %d ", parent[i], i, graph->matrix[i][parent[i]]);
  }
}

// Krushkals Matrix
int find(Subset subset[], int i) {
  if (subset[i].parent != i) {
    subset[i].parent = find(subset, subset[i].parent);
  }
  return subset[i].parent;
}
void Union(Subset subset[], int x, int y) {
  int rootx = find(subset, x);
  int rooty = find(subset, y);
  if (subset[rootx].rank > subset[rooty].rank) {
    subset[rooty].parent = rooty;
  } else if (subset[rooty].rank > subset[rootx].rank) {
    subset[rootx].parent = rootx;
  } else {
    subset[rooty].parent = rootx;
    subset[rootx].rank++;
  }
}
int compareEdge(const void *a, const void *b) {
  Edge *edgea = (Edge *)a;
  Edge *edgeb = (Edge *)b;
  return edgea->weight > edgeb->weight;
}
void krushkals(Graph *g, Edge edges[], int ecount) {
  int e = 0, i = 0;
  Edge result[g->numVertices];

  qsort(edges, ecount, sizeof(Edge), compareEdge);

  Subset *subset = (Subset *)malloc(g->numVertices * sizeof(Subset));
  for (int v = 0; v < g->numVertices; v++) {
    subset[v].parent = v;
    subset[v].rank = 0;
  }
  while (e < g->numVertices && i < ecount) {
    Edge nextEdge = edges[i++];
    int x = find(subset, nextEdge.src);
    int y = find(subset, nextEdge.dest);
    if (x != y) {
      result[e++] = nextEdge;
      Union(subset, x, y);
    }
  }
  printf("Kruskal's MST:\n");
  printf("Src - Dest \tWeight\n");
  for (i = 0; i < e; i++) {
    printf("%d - %d \t%d\n", result[i].src, result[i].dest, result[i].weight);
  }
  free(subset);
}
void dijkastra(Graph *g, int src) {
  int vertices = g->numVertices;
  int visited[vertices];
  int dist[vertices];
  for (int i = 0; i < vertices; i++) {
    dist[i] = INT_MAX;
    visited[i] = 0;
  }
  dist[src] = 0;

  for (int i = 0; i < vertices; i++) {
    int u = minKey(dist, visited, vertices);
    visited[u] = 1;

    for (int v = 0; v < vertices; v++) {
      if (g->matrix[u][v] && visited[v] == 0 && dist[u] != INT_MAX &&
          dist[u] + g->matrix[u][v] < dist[v]) {
        dist[v] = dist[u] + g->matrix[u][v];
      }
    }
  }
  printf("Dijkstra's Algorithm:\n");
  printf("Vertex \tDistance from Source\n");
  for (int i = 0; i < vertices; i++) {
    printf("%d \t%d\n", i, dist[i]);
  }
}
int main() {
  Graph *g;
  addEdge(g, 1, 2, 4);
  addEdge(g, 1, 3, 2);
  addEdge(g, 2, 3, 3);
  addEdge(g, 2, 4, 4);
  addEdge(g, 3, 4, 5);
  addEdge(g, 3, 5, 6);
  addEdge(g, 4, 5, 7);
  addEdge(g, 4, 6, 8);
  addEdge(g, 5, 6, 9);
  addEdge(g, 5, 7, 10);
  addEdge(g, 6, 7, 11);
  addEdge(g, 6, 8, 12);

  prims(g);

  Edge edges[] = {{1, 2, 4}, {1, 3, 2},  {2, 3, 3},  {2, 4, 4},
                  {3, 4, 5}, {3, 5, 6},  {4, 5, 7},  {4, 6, 8},
                  {5, 6, 9}, {5, 7, 10}, {6, 7, 11}, {6, 8, 12}};
  krushkals(g, edges, 12);

  dijkastra(g, 0);
}