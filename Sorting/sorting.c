#include <stdio.h>
#include <time.h>

void MergeSort(int arr[], int left, int right);
void QuickSort(int arr[], int low, int high);
void merge(int arr[], int left, int mid, int right);

int main() {

    char choice;
    int n;
    // Take the array of numbers
    // Ask the user for the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Declare the array
    int arr[n];

    // Input elements in the array
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Ask the user which sorting algorithm to use
    printf("Choose sorting algorithm (q for Quick Sort, m for Merge Sort): ");
    scanf("%c", &choice);

    // Measure execution time
    clock_t start, end;
    double cpu_time_used;

    // Sort the array using the chosen algorithm
    if (choice == 'q') {
        start = clock();
        QuickSort(arr, 0, n - 1);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Sorted array using Quick Sort:\n");
    } 
    else if (choice == 'm') {
        start = clock();
        MergeSort(arr, 0, n - 1);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Sorted array using Merge Sort:\n");
    } 
    else {
        printf("Invalid choice!\n");
        return main();
    }

    // Display the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");

    // Display execution time
    printf("Execution time: %f seconds\n", cpu_time_used);

    return 0;
}

void merge(int arr[], int left, int mid, int right) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } 
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int left, int right) {

    if (left < right) {
        int mid = left + (right - left) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void QuickSort(int arr[], int low, int high) {

    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1;

        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}
