#include <iostream>

using namespace std;

// In each iteration from first element find the minimum val
// item in array after that and swap with current item
void selection_sort(int arr[], int len)
{
    for (int cur_item_index = 0; cur_item_index < len - 1; cur_item_index++)
    {
        int minIndex = cur_item_index;
        for (int next_item_index = cur_item_index + 1; next_item_index < len; next_item_index++)
        {
            if (arr[next_item_index] < arr[minIndex])
                minIndex = next_item_index;
        }
        // Swap current with minimum val item
        int temp = arr[cur_item_index];
        arr[cur_item_index] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void print_array(int arr[], int len)
{
    for (int cur_item_index = 0; cur_item_index < len; cur_item_index++)
        cout << arr[cur_item_index] << " ";
    cout << endl;
}

int main()
{
    int array_len;
    cin >> array_len;

    // Input numbers into array
    int arr[array_len];
    for (int i = 0; i < array_len; i++)
        cin >> arr[i];

    // sort array
    selection_sort(arr, array_len);

    // print sorted array
    print_array(arr, array_len);
    return 0;
}