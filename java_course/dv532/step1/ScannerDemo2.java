/**
 * ScannerDemo2.java
 * Author: Copied from Absolute Java, Global Edition, 6/E by Walter J. Savitch, Chapter 2, page 111.
 */

package dv532.step1;
/*
 * A program that demonstrates use of the 
 * java.util.Scanner class for console input
 */

import java.util.Scanner;
public class ScannerDemo2 {
	public static void main(String[] args) {
		int n1, n2;
		Scanner in = new Scanner(System.in);
		
		System.out.println("Enter two whole numbers");
		System.out.println("separated by one or more spaces:");
		n1 = in.nextInt();
		n2 = in.nextInt();
		System.out.println("You entered " + n1 + " and " + n2);
		
//		System.out.println("Next enter two numbers.");
//		System.out.println("Decimal points are allowed.");
//		double d1, d2;
//		d1 = in.nextDouble();
//		d2 = in.nextDouble();
//		System.out.println("You entered " + d1 + " and " + d2);
//		
//		System.out.println("Next enter two words:");
//		String word1 = in.next();
//		String word2 = in.next();
//		System.out.println("You entered \"" + word1 + "\" and \"" + word2 + "\"");
		
//		String junk = in.nextLine(); // To get rid of '\n'
		System.out.println("Next enter a line of text:");
		String line = in.nextLine();
		System.out.println("You entered: \"" + line + "\"");
	}
}