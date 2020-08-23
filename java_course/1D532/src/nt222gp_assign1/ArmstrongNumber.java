package nt222gp_assign1;
import java.util.Scanner;
import java.lang.Math;

public class ArmstrongNumber {
	public static void main(String[] args) {
		// Create variables
		String word, yes = "Y";
		int nS, nEnd;
		
		// Define scanner as in
		Scanner in = new Scanner(System.in);
		
		// do-while loop until the the user does not want to input next calculation
		do {
			// Ask user to enter the starting number and save it as the variable ns.
			System.out.println("Enter the starting number of the range : ");
			nS = in.nextInt();		
			
			// Ask user to enter the ending number and save it as the variable nEnd.
			System.out.println("Enter the ending number of the range : ");
			nEnd = in.nextInt();
		
			// For-loop to go through all the integers from the starting number to the ending number.
			for (int i = nS; i <= nEnd; ++i) {
				
				// The while loop to count the number of digits
				// the result of the variable count is the number of digits.
				// In the while loop it divide the ith number with 10 until it become zero point something.
				// For each iteration the count will be added with 1 until it stop iterate, which will be the number of digits.
				int count = 0, o = i;
				while(o != 0) {			
		            // o = o/10
		            o /= 10;
		            ++count;
		        }

				// Calculate the ArmstrongNumber
				int m, aNumb = 0;
				o = i;
				for (int ind = 1; ind <=count; ++ind) {
					m =(int) Math.pow((o % 10),count);
					o /= 10;
					aNumb = aNumb + m;
				}

				// Print if it is a armstrong number
				if (aNumb == i) {
					System.out.println(aNumb);
				}
			}
			// Ask if the user want to repeat the calculation
			System.out.println("Do you want to repeat? (Y/N) :");
			word = in.next();
		
		} while (word.equals(yes));
		
	}
}
