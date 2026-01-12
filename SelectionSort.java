import java.util.ArrayList;
import java.util.Scanner;

public class SelectionSort {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // System.out.print("num1: ");
        // int x = sc.nextInt();

        int[] nums = { 1, 75, 6, 4, 72, 9, 95, 2 };
        // selectionSort(nums);
        // bubbleSort(nums);
        // insertionSort(nums);
        // mergeSort(nums, 0, nums.length -1);
        // recursiveBubble(nums, nums.length - 1, 0);
        // recursiveInsertion(nums, 0);
        quickSort(nums, 0, nums.length - 1);

        showArray(nums);

        sc.close();
    }

    public static void showArray(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i] + " ");
        }
        System.out.println();
    }

    public static void selectionSort(int[] nums) {
        for (int i = 0; i < nums.length - 1; i++) {
            int mini = i;
            for (int j = i; j < nums.length; j++) {
                if (nums[mini] > nums[j]) {
                    int temp = nums[mini];
                    nums[mini] = nums[j];
                    nums[j] = temp;
                }
            }
        }

        showArray(nums);
    }

    public static void bubbleSort(int[] nums) {
        boolean swap = false;

        for (int i = nums.length - 1; i >= 1; i--) {
            for (int j = 0; j <= i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                    swap = true;
                }
            }
            if (!swap) {
                break;
            }

            showArray(nums);
            System.out.println();
        }

        System.out.print("final array: ");
        showArray(nums);
    }

    public static void recursiveBubble(int[] nums, int i, int j) {
        if (i < 1) {
            showArray(nums);
            return;
        }

        if (i == j) {
            recursiveBubble(nums, i - 1, 0);
            return;
        }

        if (j < i && nums[j] > nums[j + 1]) {
            int temp = nums[j];
            nums[j] = nums[j + 1];
            nums[j + 1] = temp;
        }

        recursiveBubble(nums, i, j + 1);
    }

    public static void insertionSort(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            int j = i;
            while (j > 0 && nums[j] < nums[j - 1]) {
                int temp = nums[j];
                nums[j] = nums[j - 1];
                nums[j - 1] = temp;
                j--;
            }

            showArray(nums);
            System.out.println();
        }

        System.out.print("final array: ");
        showArray(nums);
    }

    public static void merge(int[] nums, int st, int mid, int end) {
        int i = st;
        int j = mid + 1;

        ArrayList<Integer> list = new ArrayList<>();

        while (i <= mid && j <= end) {
            if (nums[i] < nums[j]) {
                list.add(nums[i]);
                i++;
            } else {
                list.add(nums[j]);
                j++;
            }
        }

        while (i <= mid) {
            list.add(nums[i]);
            i++;
        }

        while (j <= end) {
            list.add(nums[j]);
            j++;
        }

        for (int k = 0; k < list.size(); k++) {
            nums[k + st] = list.get(k);
        }

    }

    public static void mergeSort(int[] nums, int st, int end) {
        if (st < end) {
            int mid = st + (end - st) / 2;

            mergeSort(nums, st, mid);
            mergeSort(nums, mid + 1, end);

            merge(nums, st, mid, end);
        }

        showArray(nums);

    }

    public static void insert(int[] nums, int j) {
        if (j == 0 || nums[j] >= nums[j - 1]) {
            return;
        }

        int temp = nums[j];
        nums[j] = nums[j - 1];
        nums[j - 1] = temp;

        insert(nums, j - 1);

    }

    public static void recursiveInsertion(int[] nums, int i) {
        if (i == nums.length) {
            showArray(nums);
            return;
        }

        insert(nums, i);

        recursiveInsertion(nums, i + 1);
    }

    public static int pivot(int[] nums, int low, int high) {
        int pivot = nums[low];
        int i = low;
        int j = high;

        while (i < j) {
            while (i <= high && nums[i] <= pivot) {
                i++;
            }

            while (j >= low && nums[j] > pivot) {
                j--;
            }

            if (i >= j) {
                break;
            }

            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }

        int temp = nums[low];
        nums[low] = nums[j];
        nums[j] = temp;

        return j;
    }

    public static void quickSort(int[] nums, int low, int high) {
        if (low < high) {
            int partition_index = pivot(nums, low, high);

            quickSort(nums, low, partition_index - 1);
            quickSort(nums, partition_index + 1, high);
        }

    }
}
