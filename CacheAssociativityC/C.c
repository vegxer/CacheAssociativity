#include <stdio.h>
#include <malloc.h>
#include <intrin.h>


typedef unsigned long long ull;

struct Node
{
    struct Node* next;
};

struct Node* createList(int size);
void walk(struct Node* list, int size);
void deleteList(struct Node* node);


int main()
{
    int size;
    printf("Input max array size: ");
    scanf_s("%d", &size);

    for (int i = 1; i <= size; ++i)
    {
        struct Node* list = createList(i);
        ull startTime = __rdtsc();
        walk(list, i);
        ull endTime = __rdtsc();
        printf_s("Average time for %d elements: %llu ticks\n", i, endTime - startTime);
        deleteList(list);
    }

    return 0;
}


struct Node* createList(int size)
{
    if (size <= 0)
        return NULL;

    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* ptr = head;
    for (int i = 1; i < size; ++i)
    {
        ptr->next = (struct Node*)malloc(sizeof(struct Node));
        ptr = ptr->next;
    }
    ptr->next = NULL;
    return head;
}

void walk(struct Node* list, int size)
{
    struct Node* ptr;
    for (int i = 0; i < size; ++i)
    {
        ptr = list;
        for (int j = 0; j < i; ++j)
            ptr = ptr->next;
    }
}

void deleteList(struct Node* node)
{
    if (node == NULL)
        return;

    deleteList(node->next);
    free(node);
}
