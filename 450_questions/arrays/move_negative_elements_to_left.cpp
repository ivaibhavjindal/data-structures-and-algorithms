// https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/

void rearrange(int arr[], int n)
{
    int i = 0;     // left pointer
    int j = n - 1; // right pointer

    while (i < j)
    {
        // left pointer negative move one right
        if (arr[i] < 0)
            i++;
        // right pointer non negative move one left
        else if (arr[j] >= 0)
            j--;
        // right pointer negative
        else if (arr[j] < 0)
        {
            // swap left and right elements
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            i++; // move left pointer one right
            j--; // move right pointer one left
        }
    }
}
