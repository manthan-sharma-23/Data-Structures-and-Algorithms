package search;

public class binary_search {
    public static void main(String[] args) {

        int arr[] = { 2, 3, 6, 19, 23, 45, 90, 103, 185 };
        int index = binarySearch(arr, 103);
        if (index != -1)
            System.out.println("Index is " + index);
        else
            System.out.println("Target element not found");
    }

    static int binarySearch(int arr[], int target) {

        int start = 0;
        int end = arr.length - 1;

        while (start <= end) {
            int mid = start + ((end - start) / 2);
            if (target > arr[mid]) {
                start = mid + 1;
            } else if (target == arr[mid]) {
                return mid;
            } else {
                end = mid - 1;
            }
        }

        return -1;
    }

}