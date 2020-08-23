package nt222gp_assign1;
import java.util.Scanner;

public class Days {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		// Create a integer n1 (today's day) 
		// and n2 (number for the future day)
		int n1,n2;
		// Create a (string)array of the weekdays
		String[] weekday = {"Sunday", "Monday", "Tuesday", "Wednesday","Thursday", "Friday", "Saturday"};
		
		// do-while loop to ask the user to enter correct number for today's day,
		// until it is a number between 0 to 6
		do {
			System.out.println("Enter today's day: ");
			n1 = in.nextInt();
			if (n1 <0 || n1>6) {
				System.out.print("Please enter a digit between 0-6. ");
			}
		
		} while (n1 <0 || n1>6);
		
		// Enter a number for the future day
		System.out.println("Enter the number for the future day: ");
		n2 = in.nextInt();
		
		// create two variable (type: string)
		String today, future;
		// define today as today's day
		today = weekday[n1];
		// calculate the weekday of the future day, that will be today + modulues of number to the future day
		future = weekday[n1+(n2%7)];
		// print todays day and the future day
		// printf is used to print a sentence and then add variable with %s (for strings)
		System.out.printf("Today is %s and the future day is %s", today, future);
		
	}

}
