package nt222gp_assign1;
import java.util.Scanner; // Scanner function to input the entered number (here)

public class Numbers {
	public static void main(String[] args) {
		// Create three integer variables
		int n1, n2, n3;
		
		// Define scanner as in
		Scanner in = new Scanner(System.in);
		
		// Print "Enter digits..." for user to enter three digits
		System.out.println("Enter a three-digit integer number: ");
		
		// Define the created integers as the entered digits
		n1 = in.nextInt();
		n2 = in.nextInt();
		n3 = in.nextInt();
		
		// Create a new integer called sum which is the sum of the 
		//three integers and print out the result.
		int sum = n1+n2+n3;
		System.out.println("Sum of the digits of the integer number is: " + sum);
		
		// Create a new integer called prod which is the product of
		// the three integers and print the result
		int prod = n1*n2*n3;
		System.out.println("Product of the digits of the integer number is: " + prod);
	}

}
