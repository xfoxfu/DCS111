#include <stdio.h>
#include <stdlib.h>

void preorder(int *arr, int i, int n)
{
    if (i >= n || i < 0)
        return;
    printf("%d\n", arr[i]);
    preorder(arr, i * 2 + 1, n);
    preorder(arr, i * 2 + 2, n);
}
void inorder(int *arr, int i, int n)
{
    if (i >= n || i < 0)
        return;
    inorder(arr, i * 2 + 1, n);
    printf("%d\n", arr[i]);
    inorder(arr, i * 2 + 2, n);
}
void postorder(int *arr, int i, int n)
{
    if (i >= n || i < 0)
        return;
    postorder(arr, i * 2 + 1, n);
    postorder(arr, i * 2 + 2, n);
    printf("%d\n", arr[i]);
}
int main()
{
    // input
    int n;
    scanf("%d", &n);
    int *arr = calloc(n, sizeof(*arr));
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
    // output
    printf("Preorder\n");
    preorder(arr, 0, n);
    printf("Inorder\n");
    inorder(arr, 0, n);
    printf("Postorder\n");
    postorder(arr, 0, n);
    // clean up
    free(arr);
    return 0;
}