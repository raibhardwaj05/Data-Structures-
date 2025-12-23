import java.util.Scanner;

public class SelectionSort {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // System.out.print("num1: ");
        // int x = sc.nextInt();

        int[] nums = { 1, 75, 6, 4, 72, 9, 95, 2 };
        // selectionSort(nums);
        // bubbleSort(nums);
        insertionSort(nums);

        sc.close();
    }

    public static void showArray(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i] + " ");
        }
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

}
