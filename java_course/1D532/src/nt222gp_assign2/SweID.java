package nt222gp_assign2;
import java.time.LocalDateTime;  
import java.time.format.DateTimeFormatter;


public class SweID {
	// Static method
	// getFirstPart - method to get the first part (YYMMDD) of the ID.
	// the input is the ID number in the format YYMMDD-XXXX
	public static String getFirstPart(String sweID) {
		return sweID.substring(0,6);
	}
	
	// getSecondPart - method to get the last four digits of the ID number
	public static String getSecondPart(String sweID) {
		return sweID.substring(7);
	}
	
	// isFemaleNumber - check if it a female ID number.
	// If it is a female ID then the second last digit is an even number.
	// Uses modulues to check if it is even, if the number 
	// divided by 2 and the rest is 0 then it is even.
	public static boolean isFemaleNumber(String sweID) {
		return (sweID.charAt(9) % 2 == 0);
	}
	
	// areEqual - ID comparsion, to compare two ID if they are equal
	// input: two string (ID)
	// uses .equals() for string to compare if two strings are equal.
	public static boolean areEqual(String sweID1, String sweID2) {
		return (sweID1.equals(sweID2));
	}
	
	// isCorrect - method to check if the input (ID) is correct
	public static boolean isCorrect(String sweID) {	
		// Checklist:
		// Year: <= 20 is ok
		// Month: <= 12 is ok
		// 		when year = 20 -> month <= 7
		// Day: if 2 == 28 or 29 days
		//		else if 1,3,5,7,8,10,12 == 31 days
		// 		else 4,6,9,11 == 30 days
		// 10th number - checksum
		
		// Define the variables 
		int year = Integer.parseInt("19" + sweID.substring(0,2)); 	// YY from input ID, assume input ID is between 1900 - 2020
		int month = Integer.parseInt(sweID.substring(2,4));			// MM from input ID
		int day = Integer.parseInt(sweID.substring(4,6));			// DD from input ID
		String ID_string = getFirstPart(sweID);						// YYMMDD from input ID
		int ID_birth = Integer.parseInt("19" + ID_string); 			// YYYYMMDD
		int[] days31 = new int[]{1,3,5,7,8,10,11};					// Int array with month that has 31 days
		int[] days30 = new int[]{4,6,9,12};							// Int array with month that has 30 days

		
		// Find today's date and convert it to int with the format (YYMMDD)
		LocalDateTime now = LocalDateTime.now();
        DateTimeFormatter formatter = DateTimeFormatter.BASIC_ISO_DATE;
        String dateTodayString = now.format(formatter);				// String type of today's date (YYMMDD)
        int dateToday = Integer.parseInt(dateTodayString);			// Convert to int type
        int yearToday = Integer.parseInt(dateTodayString.substring(0,4));

        
		// If-statement to check if the ID is before today's date
        // if it is after, then the person is not born yet
        // which is an unvalid ID number
		if (ID_birth >= dateToday) {
			System.out.println(sweID + "is not correct number (unvalid date, this date has not yet passed.)");
			return false;
		}
		
		
		// !Does not need, because the previous if-statement already check
		// if the ID is before today's date.!	
		// If-statement to check if it is before year 2020
		/*if (year > yearToday) {
			System.out.println(sweID + "is not correct number (unvalid year)");
			return false;
		}*/
		
				
		// If-statement to check that MM is less or equal to 12
		// (A year has 12 months)
		if (month > 12) {
			System.out.println(sweID + "is not correct number (unvalid month)");
			return false;
		}
		
		
		// If-statement for the day number depending on the month
		if (month == 2) {
			// Days in February
			// - if leap year if (2020-20YY) mod 4 is 0 : 29 days
			// - if not leap year : 28 days
			if ((yearToday-year) % 4 == 0 && day > 29) {
				// if leap year and DD is larger than 29 -> return false
				System.out.println(sweID + "is not correct number (unvalid days, Leap year has 29 days in Feb.)");
				return false;
			}
			else if ((yearToday-year) % 4 != 0 && day > 28) { 
				// if not leap year and DD is larger than 28 -> return false
				System.out.println(sweID + "is not correct number (unvalid days, Feb has 28 days except from the leap years.)");
				return false;	
			}
		}
		else if(month <= 12 && contains(days31, month) ) {
			// if in months with 31 days
			if (day > 31) {
				// if DD is larger than 31 -> return false
				System.out.println(sweID + "is not correct number (unvalid days.)");
				return false;
			}
		}
		else if (month <= 12 && contains(days30, month) ) {
			// if in months with 30 days
			if (day > 30) {
				// if DD is larger than 30 -> return false
				System.out.println(sweID + "is not correct number (unvalid days.)");
				return false;
			}
		}
		
	// Last digits - CHECKSUM
	// CheckSum algorithm can be found here:
	// https://en.wikipedia.org/wiki/Luhn_algorithm
	int sumInCheck = 0;
	String digitString;
	int digitInCheck;
	int lastDigit;
	String ID_nine = ID_string + getSecondPart(sweID); // YYMMDDXXXX from input ID
	
	for (int i=0; i <= ID_nine.length()-1; i++) {
		// Define digitString from ith digit in ID_nine
		// and then convert it to an int type.
		digitString = ID_nine.substring(i,i+1);		
		digitInCheck = Integer.parseInt(digitString);

		// For all digits in ith (odd number) position -> *1
		// For all digits in even number -> *2
		if (i%2 == 0) {
			digitInCheck = digitInCheck *2;
		}
		
		// If digitInCheck.length = 2, for example digitInCheck = 12
		// then the sum (1+2) will be added to the sumInCheck,
		// otherwise just add digitInCheck to sumInCheck.
		digitString = Integer.toString(digitInCheck);
		if (digitString.length() > 1) {
			int a = Integer.parseInt(digitString.substring(0,1));
			int b = Integer.parseInt(digitString.substring(1,2));
			sumInCheck += (a+b);
		}
		else {
			sumInCheck += digitInCheck;
		}
	}
	
	// Now after running through all nine digits, the last digit can be executed.
	// The last digit will be the first digit of the sumInCheck
	lastDigit = Integer.parseInt(Integer.toString(sumInCheck).substring(1));
	
	// If-statement to check if the tenth digit of the input ID 
	// is equal to the calcualted, if not then return false
	if ((10-lastDigit) != Integer.parseInt(sweID.substring(10,11))) {
		System.out.println(sweID + " is not correct number (unvalid last digit)");
		return false;
	}
	
	// If everything is correct then return true
	return true;
	}
	
	// contains - boolean function to check if an array contains a number
	public static boolean contains(int[] arr, int number) {
		for (int i = 0; i <= arr.length-1; i++) {
			if (arr[i] == number) {
				return true;
			}
		}
		return false;
	}
	
	
	// Main code
	public static void main(String[] args) {
		// Create two objects of SweID
		String sweID = "200229-0912";
		String sweID2 = "640123-8826";

		// Print the first part of the first obj.
		String first = getFirstPart(sweID);
		System.out.println(first);
		
		
		// Print the second part of the first obj.
		String second = getSecondPart(sweID);
		System.out.println(second);
		
		// Check the gender of the second obj.
		if (isFemaleNumber(sweID2)) {
			System.out.println(sweID2 + " is a correct female number");
		}
		else {
			System.out.println(sweID2 + " is a correct male number");
		}
		
		// Check if obj. one is equal to obj. two
		if (areEqual(sweID,sweID2)) {
			System.out.println("The IDs are identical.");
		}
		
		// Check if obj.1 has a correct ID.
		isCorrect(sweID);
		
	}
}
