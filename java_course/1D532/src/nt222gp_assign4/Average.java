package nt222gp_assign4;
import java.util.Scanner;


public class Average {
	Scanner in = new Scanner(System.in);
	
	// Data members
	int[] iArr; // Integer array
	
	// Constructor (no input argument, input an array, input size of the array)
	public Average() {
	}
	public Average(int[] i) {
		iArr = i;
	}
	public Average(int N) {
		iArr = new int[N];
	}

	
	// Methods
	// set and get the int array
	public void setIntArr(int[] i) {
		iArr = i;
	}
	public int[] getInt() {
		return iArr;
	}
	
	// Check digits
	public boolean checkDigits(String s) {
		boolean checkS;
		for (int i = 0; i<= s.length() -1; i++) {
			checkS = Character.isDigit(s.charAt(i));
			if (checkS == false) {
				return false;
			}
		}
		return true;
	}
	
	// Method setN sets N, the int array length
	// return N
	public int setN() {
		String N;
		boolean Nbool;
		
		try {
			// ask for array length
			System.out.println("How many numbers do you want to enter?");
			N = in.next();
			
			// if the user enters a non-positive value of N or a non-digit character -> throw to an exception
			if (checkDigits(N) != true ) {
				throw new ArrayIndexOutOfBoundsException();
			}
			else if (Integer.parseInt(N) <=0) {
				throw new ArrayIndexOutOfBoundsException();
			}
			
			// Otherwise return N
			return Integer.parseInt(N);
		}
		catch (ArrayIndexOutOfBoundsException e) {
	
			System.out.println("It should be a number, greater than 0.");
			// While-loop to run until the character N is a strictly positive number
			do {
				Nbool = true;
				System.out.println("Please enter again.");
				N = in.next();	
				
				if (checkDigits(N) != true ) {
					Nbool = false;
				}
				else if (Integer.parseInt(N) <=0) {
					Nbool = false;
				}
				
			} while(!Nbool);
		}
		return Integer.parseInt(N);
	}
	
	
	// Method setInt sets an integer in nth position
	// input: n (position index)
	
	public void setInt(int n) {
		
		String numb;
		boolean numbool;
		
		try {
			// Ask to enter an digit 
			System.out.println("Enter number " + n);
			numb = in.next();

			// Check if the digit is either a postive number
			// or a negative number, otherwise throw to the exception
			if (checkDigits(numb) != true && !numb.substring(0,1).equals("-")) {
				throw new NumberException();
			}
			else if (checkDigits(numb.substring(1)) != true 
					&& numb.substring(0,1).equals("-")) {
				throw new NumberException();
			}	
			
		}
		catch (NumberException e1) {
			
			System.out.println("You entered a non-numeric value which is not allowed.");
			// do-while to run until the user enters a valid number
			do {
				numbool = true;
				System.out.println("Please enter again.");
				numb = in.next();
				
				if (checkDigits(numb) != true && !numb.substring(0,1).equals("-")) {
					numbool = false;
				}
				else if (checkDigits(numb.substring(1)) != true 
						&& numb.substring(0,1).equals("-")) {
					numbool = false;
				}
			} while(!numbool);
		}
		
		// Insert the valid number in (n-1)th position in iArray
		iArr[n-1] = Integer.parseInt(numb);
	}
	
	// Calculate average
	public float calcAve() {
		// Float number to includes decimals
		float ave = 0;
		
		// sum of all elements in the array
		for (int i = 0; i<= iArr.length-1; i++) {
			ave += iArr[i];
		}
		// and devide it with its length
		return ave/=iArr.length;
	}
	
	// Main method
	public static void main(String[] args) {
		// Create a new Average object
		Average a = new Average();
		
		// Set size of the array
		int N = a.setN();
		a = new Average(N);
		
		// Set numbers of the array
		for (int n = 1; n <= N; n++) {
			a.setInt(n);
		}
	
		// calculate the average and print it with two decimals
		System.out.printf("Average of the entered numbers is %.2f", a.calcAve());
	}

}
