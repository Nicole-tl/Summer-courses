/**
 * IterationsDemo.java
 * Author: Nadeem Abbas
 */
package dv532.step1;   // package declaration
 
/*
 * A program that demonstrates use of iteration statements
 */
import java.util.Scanner;

class IterationsDemo {
	public static void main(String args[]) {
		forLoop();
		whileLoop();
		doWhile();
	}

	public static void forLoop() {
		System.out.println("For loop is about to execute");
		for (int n = 1; n <= 5; n++)
			System.out.println("tick " + n);
		System.out.println("For loop Ended!");

	}

	public static void whileLoop() {
		int i=0, j=6;
		System.out.println("\nWhile loop is about to execute");
		System.out.println("value of i before while loop " + i);
		System.out.println("value of j before while loop " + j);
		// find midpoint between i and j
		while (i != j) {
			i++;
			j--;
		}
		System.out.println("i after while loop " + i);
		System.out.println("j after while loop " + j);
	}
		
	public static void doWhile() {
        Scanner in = new Scanner(System.in); //for console input
        int n=0, sum=0;       
       	System.out.println("\nA do-while loop will run now, keep on asking you to enter a number until you enter zero.");

        do {
        	System.out.print("Enter a number: ");
        	n=in.nextInt();
        	sum+=n;
        } while (n!=0);
        
        System.out.print("Sum of entered numbers: "+sum);
	}
	
}