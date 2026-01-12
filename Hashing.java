import java.util.HashMap;
import java.util.Scanner;

public class Hashing {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("array size: ");
        int x = sc.nextInt();

        System.out.println("enter array elements: ");
        int[] arr = new int[x];
        for(int i = 0; i < x; i++){
            arr[i] = sc.nextInt();
        }
        // hashnum(arr);
        // hashChar("bhardwaj");
        mapnum(arr);
        // mapChar("asdgearyiwag");


        sc.close();
    }

    public static void hashnum(int[] arr){
        Scanner sc = new Scanner(System.in);

        // precompute
        int[] hashtable = new int[13]; // consider hashtable can have numbers upto 12
        //  ==> in the main size of int can be atmost 10e6 and globally 10e7
        // not a Java rule, but a competitive programming guideline based on memory limits. 
        for(int i = 0; i < arr.length; i++){
            hashtable[arr[i]] += 1;
        }

        System.out.print("how many queries: ");
        int queries = sc.nextInt();

        while(queries > 0){
            System.out.print("num: ");
            int num = sc.nextInt();

            System.out.println(num + ": " +hashtable[num]);

            queries--;
        }

        sc.close();
    }

    // for a-z or A-Z to code for all character no need for - 'a/A' and size will be 256 based on ASCII no.
    public static void hashChar(String str){
        Scanner sc = new Scanner(System.in);

        int[] hash = new int[26];

        for(int i = 0; i < str.length(); i++){
            hash[str.charAt(i) - 'a']++;
        }

        System.out.print("how many queries: ");
        int queries = sc.nextInt();
        sc.nextLine();

        while(queries > 0){
            System.out.print("character: ");
            char ch = sc.next().charAt(0);

            System.out.println(ch + ": " +hash[ch - 'a']);

            queries--;
        }

        sc.close();
    }

    public static void mapnum(int[] arr){
        Scanner sc = new Scanner(System.in);

        // precompute
        HashMap<Integer, Integer> map = new HashMap<>();

        for(int i = 0; i < arr.length; i++){
            map.put(arr[i], map.getOrDefault(arr[i], 0) + 1);
        }

        System.out.print("how many queries: ");
        int queries = sc.nextInt();

        while(queries > 0){
            System.out.print("num: ");
            int num = sc.nextInt();

            System.out.println(num + ": " + map.getOrDefault(num,0));

            queries--;
        }

        sc.close();
    }

    public static void mapChar(String str){
        Scanner sc = new Scanner(System.in);

        HashMap<Character, Integer> map = new HashMap<>();

        for(int i = 0; i < str.length(); i++){
            map.put(str.charAt(i), map.getOrDefault(str.charAt(i), 0) + 1);
        }

        System.out.print("how many queries: ");
        int queries = sc.nextInt();

        while(queries > 0){
            System.out.print("num: ");
            char ch = sc.next().charAt(0);
            
            System.out.println(ch + ": "+ map.getOrDefault(ch, 0));

            queries--;
        }
        sc.close();
    }

}
