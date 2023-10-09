package searching;

public class binary_search {
    public static void main(String[] args) {

        // int arr[] = { 2, 3, 6, 19, 23, 45, 90, 103, 185 };
        int arr[] = { 185, 19, 23, 25, 45, 67, 5, 4, 2, 1, -4, -8 };
        int index = orderAugnosticBinarySearch(arr, -4);
        if (index != -1)
            System.out.println("Index is " + index);
        else
            System.out.println("Target element not found");
    }

    static int increasingBinarySearch(int arr[], int target) {

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

    static int decreasingBinarySearch(int arr[], int target) {

        int start = 0;
        int end = arr.length - 1;

        while (start <= end) {
            int mid = start + ((end - start) / 2);
            if (target > arr[mid]) {
                end = mid - 1;
            } else if (target == arr[mid]) {
                return mid;
            } else {
                start = mid + 1;
            }
        }

        return -1;
    }

    /*
     * order-augnostic binary search -- wether i dont know if array is sorted in asc
     * or desc
     */
    static int orderAugnosticBinarySearch(int arr[], int target) {
        boolean isAsc;
        if (arr[0] < arr[arr.length - 1]) {
            isAsc = true;
        } else {
            isAsc = false;
        }

        int index = -1;
        if (isAsc) {
            System.out.println("Executing ascending order search");
            index = increasingBinarySearch(arr, target);
        } else {
            System.out.println("Executing descending order search");
            index = decreasingBinarySearch(arr, target);
        }

        return index;
    }

}