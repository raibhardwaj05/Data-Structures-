import java.util.Arrays;
import java.util.Scanner;

public class Recursion {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("num1: ");
        int x = sc.nextInt();
        // System.out.print("num2: ");
        // int y = sc.nextInt();

        // sc.nextLine();
        // System.out.print("name: ");
        // String naam = sc.nextLine();

        // natural(x);
        // name(x, naam);

        // naturalreverse(x);
        // naturalLinear(1, x);
        // naturalBackTrack(x);
        // naturalreverseBackTrack(x);

        // System.out.println("total: "+ sum(x, 0));

        // System.out.println("factorial of "+x+": "+ factorial(x));

        // int[] a = {1, 2, 3, 4, 5};
        // reverseArray(a, 0, a.length - 1);

        // sc.nextLine();
        // System.out.print("name: ");
        // String naam = sc.nextLine();
        // System.out.println("palindrome: "+ palindrome(naam, 0, naam.length() - 1));

        for(int i = 0; i <x; i++){
            System.out.print(fibonacci(i) + " ");
        }

        sc.close();
    }

    public static int natural(int n){
        if(n == 50){
            System.out.println(n);
            return n;
        }

        System.out.println(n);

        return natural(n + 1);
    }

    public static int name(int n, String naam){
        if (n == 6) {
            return 0;
        }

        System.out.println(naam);

        return name((n + 1), naam);
    }

    public static int naturalreverse(int n){
        if(n == 1){
            System.out.println(n);
            return n;
        }

        System.out.println(n);

        return naturalreverse(n - 1);
    }

    public static int naturalLinear(int i, int n){
        if(i == n){
            System.out.print(i);
            return 0;
        }

        System.out.print(i+" ");

        return naturalLinear(i + 1, n);
    }

    public static void naturalBackTrack(int i){
        if (i < 1) {
            return;
        }

        naturalBackTrack(i - 1);
        System.out.println(i);
    }

    public static void naturalreverseBackTrack(int i){
        if(i > 5) return;

        naturalreverseBackTrack(i + 1);
        System.out.println(i);
    }

    public static int sum(int n, int total){
        if(n < 1) return total;

        return sum(n-1, total + n);
    }
    
    public static int factorial(int n){
        if(n < 1) return 1;

        return n * factorial(n-1);
    }

    public static void reverseArray(int[] a, int i, int j){
        if(i >= j){
            // for(int k = 0; k < a.length; k++){
            //     System.out.print(a[k] + " ");
            // }
            System.out.println(Arrays.toString(a));

            return;
        }

        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;

        reverseArray(a, i+1, j-1);
    }

    public static boolean palindrome(String str, int i, int j){
        if (i >= j) {
            return true;
        }

        if (str.charAt(i) != str.charAt(j)) {
            return false;
        }

        return palindrome(str, i+1, j-1);
    }

    public static int fibonacci(int n){
        if (n <= 1) {
            return n;
        }
        
        return fibonacci(n-1) + fibonacci(n - 2);
    }

}
