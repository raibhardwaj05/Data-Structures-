import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class Arrays {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // System.out.print("num1: ");
        // int x = sc.nextInt();

        int[] nums = { 1, 2, 4, 5, 3, 4, 3, 2 };
        // System.out.println("array is sorted: " + sorted(nums));
        // showArray(nums);
        // removeDuplicates(nums);

        int[] nums1 = {1, 1, 2, 4, 4, 7};
        int[] nums2 = {1, 3, 4, 4, 4, 8};
        int[] result = union(nums1, nums2);
        showArray(result);

        sc.close();
    }

    public static void showArray(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i] + " ");
        }
        System.out.println();
    }

    public static boolean sorted(int[] nums) {
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i + 1] < nums[i]) {
                return false;
            }
        }

        return true;
    }

    public static void removeDuplicates(int[] nums) {
        HashSet<Integer> set = new HashSet<>();

        for (int i = 0; i < nums.length; i++) {
            set.add(nums[i]);
        }

        int j = 0;

        for (int i : set) {
            nums[j] = i;
            j++;
        }

        for (int i = j; i < nums.length; i++) {
            nums[i] = 0;
        }
    }

    public static int[] union(int[] nums1, int[] nums2) {
        ArrayList<Integer> list = new ArrayList<>();
        int i = 0, j = 0;
        while (i < nums1.length && j < nums2.length) {
            if (nums1[i] < nums2[j]) {
                if (!list.contains(nums1[i])) {
                    list.add(nums1[i]);
                }
                i++;
            } else if (nums1[i] > nums2[j]) {
                if (!list.contains(nums2[j])) {
                    list.add(nums2[j]);
                }
                j++;
            }

            else {
                if (!list.contains(nums2[j])) {
                    list.add(nums2[j]);
                }
                j++;
                i++;
            }
        }

        while (i < nums1.length) {
            if (!list.contains(nums1[i])) {
                list.add(nums1[i]);
            }
            i++;
        }

        while (j < nums2.length) {
            if (!list.contains(nums2[j])) {
                list.add(nums2[j]);
            }
            j++;
        }

        int[] result = new int[list.size()];
        for (int k = 0; k < list.size(); k++) {
            result[k] = list.get(k);
        }

        return result;
    }
}
