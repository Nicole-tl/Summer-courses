package nt222gp_assign1;
import java.util.Scanner;

public class SquareRoot {
	public static void main(String[] args) {
		// create variables
		// n - the entered positive number to find the square root
		// guess - calculated guess (n/2)
		// guess_old - calculated previous guess
		// r - from the instruction
		// type: double - to be able to have decimals
		double n; 					
		double guess, guess_old, r;
		
		// Define the scanner as in
		Scanner in = new Scanner(System.in);
		
		// Ask for the positive number to find the square root 
		System.out.println("This program estimate square roots.\n" + 
				"Enter an integer to estimate the square root of: ");
		n = in.nextDouble();
		
		// Make a guess as n/2
		guess = n/2;
		
		// Run the step 2-4 (from instructions) 
		// while the new guess differ 1% from the previous guess
		do {
			guess_old = guess; 			// define the old guess as current guess
			r = n/guess;				// step 2: update r
			guess = (guess + r)/2;		// step 3: set new guess
			System.out.println("Current guess: " + guess); // print the new guess

		} while (guess/guess_old <= 0.99);
		
		// Print the final guess with double number of two decimals
		System.out.printf("The estimated square root of %6.0f is %6.2f", n, guess);
		
	}

}
