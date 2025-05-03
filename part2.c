#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int list[10] = {7, 12, 19, 3, 18, 4, 2, 6, 15, 8};
int list1[5] = {7, 12, 19, 3, 18};
int list2[5] = {4, 2, 6, 15, 8};
int final_list[10];
int size = 10;
int s = 10 / 2;

void *thread1(void *arg);
void *thread2(void *arg);
void *thread3(void *arg);

int main()
{
    // int size;
    // scanf("%d", &size);
    // if (size % 2 != 0) {
    //     printf("Size must be even.\n");
    //     return 1;
    // }
    // int* list = malloc(size * sizeof(int));
    // for (int i = 0; i < size; i++) {
    //     scanf("%d", &list[i]);
    // }
    // int s = size / 2;
    // int* list1 = malloc(s * sizeof(int));
    // for (int i = 0; i < s; i++) {
    //     list1[i] = list[i];
    // }
    pthread_t t1;
    pthread_t t2;
    pthread_t t3;
    pthread_create(&t1, NULL, thread1, NULL);
    pthread_join(t1, NULL);
    pthread_create(&t2, NULL, thread2, NULL);
    pthread_join(t2, NULL);
    pthread_create(&t3, NULL, thread3, NULL);
    pthread_join(t3, NULL);

    printf("frist list: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");
    printf("sorted list: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", final_list[i]);
    }
    return 0;
}

void *thread1(void *arg)
{
    for (int i = 0; i < s - 1; i++)
    {
        for (int j = 0; j < s - (1 + i); j++)
        {
            if (list1[j] > list1[j + 1])
            {
                int t = list1[j + 1];
                list1[j + 1] = list1[j];
                list1[j] = t;
            }
        }
    }
}

void *thread2(void *arg)
{
    for (int i = 0; i < s - 1; i++)
    {
        for (int j = 0; j < s - (1 + i); j++)
        {
            if (list2[j] > list2[j + 1])
            {
                int t = list2[j + 1];
                list2[j + 1] = list2[j];
                list2[j] = t;
            }
        }
    }
}

void *thread3(void *arg)
{
    int a = 0, b = 0;
    for (int k = 0; k < size; k++)
    {
        if (a < s && b < s)
        {
            if (list1[a] <= list2[b])
            {
                final_list[k] = list1[a];
                a++;
            }
            else
            {
                final_list[k] = list2[b];
                b++;
            }
        }
        else if (a < s)
        {
            final_list[k] = list1[a];
            a++;
        }
        else
        {
            final_list[k] = list2[b];
            b++;
        }
    }
}