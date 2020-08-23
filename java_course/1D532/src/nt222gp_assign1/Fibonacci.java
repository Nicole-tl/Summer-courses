package nt222gp_assign1;

public class Fibonacci {
	public static void main(String[] args) {
		// Create and define the first Fibonacci numbers
		// a - first Fibonacci numbers
		// b - second Fibonacci numbers
		// sum - the sum of all odd Fibonacci numbers
		// next - the next Fibonacci number => second Fibonacci number
		int a = 1;
		int b = 2;
		int sum = 1;		
		int next = b;		
		
		// Print the first Fibonacci number
		System.out.print("The Fibonacci numbers: " + a);
		
		// do-while loop until it comes to one thousand
		do {
			// Print the next Fibonacci number
			System.out.print(", " + next);
			
			// If the next number is a odd numbers
			// add it to sum
			if (next % 2 == 1 ) {
				sum += next;
			}
			
			// Calculate next fibonacci number for next iteration
			next = a + b; 	// next fibonacci number is the sum of the two previous once 
			a = b;			// define the first as the second
			b = next;		// and define the second as the new fibonacci number
				
		} while (b < 1000);
		
		System.out.print("\n sum of the odd Fibonacci numbers: " + sum);
	}
}
