import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.lang.Math;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("num1: ");
        int x = sc.nextInt();
        System.out.print("num2: ");
        int y = sc.nextInt();

        // System.out.println(x + " is an armstrong number: " + armstrong(x));
        // System.out.println(divisors(x));
        // System.out.println("isprime: "+prime(x));
        System.out.println("GCD("+x+","+y+"):"+gcd(x, y));

        sc.close();
    }

    public static boolean armstrong(int x) {
        int digits = (x == 0) ? 1 : 0;

        int og = x;
        int sum = 0;

        if (digits == 0) {
            int temp = x;
            while (temp != 0) {
                digits += 1;
                temp /= 10;
            }
        }

        while (x != 0) {
            int ls = x % 10;
            x = x / 10;
            sum = sum + (int) Math.pow(ls, digits);
        }

        return (og == sum);
    }

    public static ArrayList<Integer> divisors(int x){
        ArrayList<Integer> ls = new ArrayList<>();

        for(int i = 1; i <= (int)Math.sqrt(x); i++){
            if (x % i == 0) {
                ls.add(i);
                if ((x/i) != i) {
                    ls.add(x/i);
                }
            }
        }
        Collections.sort(ls);
        return ls;
    }

    public static boolean prime(int x){
        int count = 0;

        for(int i = 1; i*i <= x; i++){
            if (x % i == 0) {
                count += 1;

                if (x/i != i) {
                    count += 1;
                }
            }
        }

        return (count == 2);
    }

    public static int gcd(int x, int y){

        while(x > 0 && y > 0){
            if (x > y){
                x =  (x % y);
            }
            else{
                y =(y % x);
            }
        }

        if (x == 0) {
            return y;
        }
        else{
            return x;
        }
    }

    
}
