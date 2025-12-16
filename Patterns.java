import java.util.*;

class Patterns {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter rows: ");

        int a = sc.nextInt();

        // pattern13(a);
        // pattern14(a);
        // pattern15(a);
        // pattern16(a);
        // pattern17(a);
        // pattern18(a);
        // pattern19(a);
        // pattern20(a);
        // pattern21(a);
        pattern22(a);

        sc.close();
    }

    public static void pattern13(int n) {
        int num = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print(num + " ");
                num += 1;
            }

            System.out.println();
        }
    }

    public static void pattern14(int n) {
        for (int i = 1; i <= n; i++) {
            char letter = 'A';
            for (int j = 1; j <= i; j++) {
                System.out.print(letter + " ");
                letter += 1;
            }
            System.out.println();
        }
    }

    public static void pattern15(int n) {
        for (int i = 0; i < n; i++) {
            char letter = 'A';
            for (int j = 0; j < (n - i); j++) {
                System.out.print(letter + " ");
                letter += 1;
            }
            System.out.println();
        }
    }

    public static void pattern16(int n) {
        char letter = 'A';
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print(letter + " ");

            }
            letter += 1;
            System.out.println();
        }
    }

    public static void pattern17(int n) {
        for (int i = 0; i < n; i++) {
            char ch = 'A';
            int breakpoint = (2 * i + 1) / 2;

            for (int k = 1; k <= (n - i - 1); k++) {
                System.out.print(" ");
            }

            for (int j = 1; j <= 2 * i + 1; j++) {
                System.out.print(ch);

                if (j <= breakpoint)
                    ch++;
                else
                    ch--;
            }

            for (int k = 1; k <= (n - i - 1); k++) {
                System.out.print(" ");
            }

            System.out.println();
        }
    }

    public static void pattern18(int n) {
        for (int i = 0; i < n; i++) {
            for (char j = (char) ('E' - i); j <= 'E'; j++) {
                System.out.print(j);
            }
            System.out.println();
        }
    }

    public static void pattern19(int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                System.out.print("*");
            }

            for (int j = 0; j < 2 * i; j++) {
                System.out.print(" ");
            }

            for (int j = 0; j < n - i; j++) {
                System.out.print("*");
            }

            System.out.println();
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i + 1; j++) {
                System.out.print("*");
            }

            for (int j = 0; j < 2 * n - 2 - 2 * i; j++) {
                System.out.print(" ");
            }

            for (int j = 0; j < i + 1; j++) {
                System.out.print("*");
            }

            System.out.println();
        }
    }

    public static void pattern20(int n) {
        for (int i = 0; i <= 2 * n; i++) {

            int stars = i < n ? i + 1 : 2 * n - i-1;
            int space = 2 * n - 2 * stars;

            for (int j = 0; j < stars; j++) {
                System.out.print("*");
            }

            for (int j = 0; j < space; j++) {
                System.out.print(" ");
            }

            for (int j = 0; j < stars; j++) {
                System.out.print("*");
            }

            System.out.println();
        }
    }

    public static void pattern21(int n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if (i == 0 || j == 0 || i == n-1 || j == n-1) {
                    System.out.print("*");
                }
                else{
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
    }

    public static void pattern22(int n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if (i == 0 || j == 0 || j == n-1 || i == n-1) System.out.print(n-3);
                else if (i == 1 || j == 1 || j == n-2 || i == n-2) System.out.print(n-4);
                else if (i == 2 || j == 2 || j == n-3 || i == n-3) System.out.print(n-5);
                else if (i == 3 || j == 3 || j == n-4 || i == n-4) System.out.print(n-6);
            }

            System.out.println();
        }
    }
}