//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

// Structure for the stack
struct MyStack {
    int arr[MAX];
    int top;
};

// Function to initialize the stack
void initStack(struct MyStack* stack) {
    stack->top = -1;
}

// Function to push an integer onto the stack
void push(struct MyStack* stack, int a);

// Function to pop an integer from the stack
int pop(struct MyStack* stack);

int main() {
    int T;
    scanf("%d", &T);
    getchar(); // Consume the newline character after reading T

    while (T--) {
        struct MyStack* sq = (struct MyStack*)malloc(sizeof(struct MyStack));
        initStack(sq);

        char input[1000];
        fgets(input, sizeof(input), stdin); // Read input line

        char* token = strtok(input, " ");
        int nums[1000], n = 0;

        // Parse the input
        while (token != NULL) {
            nums[n++] = atoi(token);
            token = strtok(NULL, " ");
        }

        int i = 0;
        while (i < n) {
            int QueryType = nums[i++];
            if (QueryType == 1) {
                int a = nums[i++];
                push(sq, a); // Push onto the stack
            } else if (QueryType == 2) {
                printf("%d ", pop(sq)); // Pop from the stack and print the value
            }
        }

        printf("\n~\n");

        free(sq); // Free allocated memory for the stack
    }

    return 0;
}

// } Driver Code Ends


// User function Template for C
void push(struct MyStack* stack, int a) {
    // code
    if (stack->top == MAX - 1) {
        // printf("Stack overflow\n");
        return;
    }
    stack->top++;
    stack->arr[stack->top] = a;
    
}

// Function to pop an item from the top of the stack
int pop(struct MyStack* stack) {
    // code
       if (stack->top == -1) {
        // printf("Stack underflow\n");
        return -1;
    } else {
        int x = stack->arr[stack->top];
        stack->arr[stack->top] = -1;
        stack->top--;
        return x;
    }
}