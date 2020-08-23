package nt222gp_assign1;
import java.util.Scanner;

public class IBNS {
	public static void main(String[] args) {
		// Create nine variable to save the nine entered digits
		int n1, n2, n3, n4, n5, n6, n7, n8, n9;
		String n0;
		// Define scanner as in.
		Scanner in = new Scanner(System.in);

		// Input the nine digits and save them as n1, n2...
		System.out.println("Enter the first 9 digits of an ISBN as integer (separanted by spaces): ");
		// Save the first digits as n0 with the type string
		n0 = in.next();	
		
		// If-statement:
		// if all nine digits are written in one line
		// then divide the n0 into substrings and save it to the n1,n2,n3... 
		// else if all digits are written in separately
		// then save the digits by using the nextInt()
		if (n0.length() == 9) {
			n1 = Integer.parseInt(n0.substring(0,1));
			n2 = Integer.parseInt(n0.substring(1,2));
			n3 = Integer.parseInt(n0.substring(2,3));
			n4 = Integer.parseInt(n0.substring(3,4));
			n5 = Integer.parseInt(n0.substring(4,5));
			n6 = Integer.parseInt(n0.substring(5,6));
			n7 = Integer.parseInt(n0.substring(6,7));
			n8 = Integer.parseInt(n0.substring(7,8));
			n9 = Integer.parseInt(n0.substring(8,9));
		}
		else { 
			n1 = Integer.parseInt(n0);
			n2 = in.nextInt();
			n3 = in.nextInt();
			n4 = in.nextInt();
			n5 = in.nextInt();
			n6 = in.nextInt();
			n7 = in.nextInt();
			n8 = in.nextInt();
			n9 = in.nextInt();
		}
	
		
		// Create tenth digit as the checksum of the other nine digits
		// The function is given from the instruction
		int n10 = (n1*1 + n2*2 + n3*3 + n4*4 + n5*5 + n6*6 + n7*7 + n8*8 + n9*9)%11 ;
		
		// A if-statement to denote the tenth variable as X 
		// if the tenth digit is equal to 10
		// otherwise the tenth variable is equal to the checksum
		if (n10 == 10){
			System.out.println("The ISBN-10 number is: " + n1+ n2+ n3+ n4+ n5+ n6+ n7+ n8+ n9 + "X");
		}
		else {
			System.out.println("The ISBN-10 number is: " + n1+ n2+ n3+ n4+ n5+ n6+ n7+ n8+ n9 + n10);
		}

	}
}
