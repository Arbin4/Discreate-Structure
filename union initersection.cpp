#include <stdio.h>
 
void get_value(int arr[]);
void print_value(int arr[], int n);
void function_sort(int arr[]);
int find_intersection(int array1[], int array2[], int intersection_array[]);
int find_union(int array1[], int array2[], int union_array[]);
 
int main()
{
    int array1[5], array2[5], intersection_array[5], union_array[5*2];
    int num_elements;
 
    //input elements of Array1
    printf("\n Enter the elements of Array 1: ");
    get_value(array1);
    printf("\n\n Elements of Array 1: ");
    print_value(array1, 5);
 
    //input elements of Array2
    printf("\n\nEnter the elements of Array 2: ");
    get_value(array2);
    printf("\n\n Elements of Array 2: ");
    print_value(array2, 5);
 
    //Find Intersection
    num_elements = find_intersection(array1, array2, intersection_array);
    printf("\n\n Intersection is: ");
    print_value(intersection_array, num_elements);
 
    //Find Union
    num_elements = find_union(array1, array2, union_array);
    printf("\n\n Union is: ");
    print_value(union_array, num_elements);
    return 0;
}
 
void get_value(int arr[])
{
    int i, j;
    for (i = 0; i < 5; i++)
    {
        j = i + 1;
        printf("\n Enter element %d: ", j);
        scanf("%d", &arr[i]);
    }
}
 
void print_value(int arr[], int n)
{
    int i;
    printf("{ ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("}");
}
 

 
int find_intersection(int array1[], int array2[], int intersection_array[])
{
    int i = 0, j = 0, k = 0;
    while ((i < 5) && (j < 5))
    {
        if (array1[i] < array2[j])
        {
            i++;
        }
        else if (array1[i] > array2[j])
        {
            j++;
        }
        else
        {
            intersection_array[k] = array1[i];
            i++;
            j++;
            k++;
        }
    }
    return(k);
}
 
int find_union(int array1[], int array2[], int union_array[])
{
    int i = 0, j = 0, k = 0;
    while ((i < 5) && (j < 5))
    {
        if (array1[i] < array2[j])
        {
            union_array[k] = array1[i];
            i++;
            k++;
        }
        else if (array1[i] > array2[j])
        {
            union_array[k] = array2[j];
            j++;
            k++;
        }
        else
        {
            union_array[k] = array1[i];
            i++;
            j++;
            k++;
        }
    }
    if (i == 5)
    {
        while (j < 5)
        {
            union_array[k] = array2[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i < 5)
        {
            union_array[k] = array1[i];
            i++;
            k++;
        }
    }
    return(k);
}

