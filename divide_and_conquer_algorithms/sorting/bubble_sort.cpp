#include <iostream>

using namespace std;

// In each iteration compare consecutive pairs such that
// if next item > cur item, then swap so largest num bubbles to end of array
void bubble_sort(int arr[], int len)
{
    for (int cur_item_index = 1; cur_item_index < len; cur_item_index++)
    {
        for (int next_item_index = 0; next_item_index < len - cur_item_index; next_item_index++)
        {
            if (arr[next_item_index + 1] < arr[next_item_index])
            {
                // swap next item with cur item if next item > cur item
                int temp = arr[next_item_index];
                arr[next_item_index] = arr[next_item_index + 1];
                arr[next_item_index + 1] = temp;
            }
        }
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
    bubble_sort(arr, array_len);

    // print sorted array
    print_array(arr, array_len);
    return 0;
}