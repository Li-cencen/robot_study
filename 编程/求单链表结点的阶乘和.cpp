#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
struct Node {
    int Data; /* 存储结点数据 */
    PtrToNode Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

int FactorialSum(List L);

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int FactorialSum(List L) {
    int sum = 0;
    while (L != NULL) {
        sum += factorial(L->Data);
        L = L->Next;
    }
    return sum;
}

int main() {
    int N, i;
    List L, p;

    scanf("%d", &N);
    L = NULL;
    for (i = 0; i < N; i++) {
        p = (List)malloc(sizeof(struct Node));
        scanf("%d", &p->Data);
        p->Next = L;  L = p;
    }
    printf("%d\n", FactorialSum(L));

    // Free the allocated memory
    PtrToNode temp;
    while (L != NULL) {
        temp = L;
        L = L->Next;
        free(temp);
    }

    return 0;
}
