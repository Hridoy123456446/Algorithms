#include <stdio.h>
// Structure to represent an activity
typedef struct {
    int start;
    int finish;
} Activity;

// Function to sort activities by finish time (using bubble sort)
void sortActivities(Activity arr[], int n) {
    for (int i = 0; i < n -1; i++) {
        for (int j = 0; j < n - i -1; j++) {
            if (arr[j].finish > arr[j+1].finish) {
                Activity temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void activitySelection(Activity arr[], int n) {
    sortActivities(arr, n);

    printf("Selected activities:\n");
    int last_finish = arr[0].finish;
    printf("Activity 1: Start = %d, Finish = %d\n", arr[0].start, arr[0].finish);

    for (int i = 1; i < n; i++) {
        if (arr[i].start >= last_finish) {
            printf("Activity %d: Start = %d, Finish = %d\n", i+1, arr[i].start, arr[i].finish);
            last_finish = arr[i].finish;
        }
    }
}

int main() {
    int n;
    printf("Enter number of activities: ");
    scanf("%d", &n);

    Activity arr[n];
    printf("Enter start and finish times of activities:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].finish);
    }

    activitySelection(arr, n);

    return 0;
}
