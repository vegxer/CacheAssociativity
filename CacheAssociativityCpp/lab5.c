#include <stdio.h>
#include <malloc.h>
#include <inttypes.h>

struct Node
{
    struct Node *next;
};

uint64_t rdtsc();
struct Node* createList(int size);
void walk(struct Node* list, int size);
void deleteList(struct Node* node);


int main()
{
    int size;
    printf("Input max array size: ");
    scanf("%d", &size);

    for (int i = 1; i <= size; ++i)
    {
        struct Node* list = createList(i);
        uint64_t startTime = rdtsc();
        walk(list, i);
        uint64_t endTime = rdtsc();
        printf("Average time for %d elements: ", i);
        printf("%" PRIu64 " ticks\n", endTime - startTime);
        deleteList(list);
    }
    
    return 0;
}


uint64_t rdtsc()
{
	unsigned int a, d;
	__asm__ __volatile__ ("rdtsc" : "=a" (a), "=d" (d));
	
	return ((uint64_t)d << 32) | a;
}

struct Node* createList(int size)
{
    if (size <= 0)
        return NULL;

    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* ptr = head;
    for (int i = 1; i < size; ++i)
        ptr = ptr->next;
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

