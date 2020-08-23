package nt222gp_assign4;
import java.util.Scanner;

public class BankAccount {
	Scanner in = new Scanner(System.in);
	boolean correct;

	// Data members
	private String ID;
	private String accountNum;
	private String balance;
	
	// Constructor
	public BankAccount() {}
	public BankAccount(String addID, String addA, String addB) {
		ID = addID;
		accountNum = addA;
		balance = addB;
	}
	
	
	// Members methods
	// For costumer ID
	// setID - set costumer ID
	public void setID(String addID) {
		ID = addID;
	}
	// getID - get costumer ID
	public String getID() {
		return ID;
	}
	
	// checkID - Check if the ID is in correct format.
	// input: the entered customer ID
	// return: the correct ID
	public String checkID(String ID) {
		
		// TryCatch method to check that the customer ID:
		// - starts with a letter
		// - followed by three digits
		try {		
			// Boolean for correct customer ID:
			// l0 - checks the first character is a alphabet
			// l_len - checks that it is a variable of four character
			boolean l0 = (ID.charAt(0) >= 'a' && ID.charAt(0) <='z') 
					|| (ID.charAt(0) >= 'A' && ID.charAt(0) <='Z') ;
			boolean l_len = ID.length() == 4;

			// Check if l0 and l_len are correct
			if (!l0 || !l_len) {
				// If not then throw it to ID exception
				throw new IDException();
			}	
			
			// Check if the second to fourth character are numbers
			if (checkDigits(ID.substring(1)) == false) {
				// If any of them aren't numbers then throw it to ID exception
				throw new IDException();
			}
			
		} catch (IDException e) {
			
			// In the exception, remind user the format of the ID
			System.out.println("Incorrect Customer ID."
					+ " The Customer ID must start with"
					+ " a letter followed by three digits.");
			
			// do-while loop to ask for input until the correct format is implemented.
			// It will run until the boolean correct is true
			do {
				// Ask for input
				System.out.println("Input Again.");
				ID = in.next();
				correct = true; // initialize the boolean check (to be true)
				
				// Check the format agian
				boolean l0 = (ID.charAt(0) >= 'a' && ID.charAt(0) <='z') 
						|| (ID.charAt(0) >= 'A' && ID.charAt(0) <='Z') ;
				boolean l_len = ID.length() == 4;
				
				// if any of the check is not correct, then return false
				if (!l0 || !l_len) {
					correct = false;
				}
				if (checkDigits(ID.substring(1)) == false) {
					correct = false;
				}
			} while (!correct);	
		} 
		return ID; // Then return the ID	
	}
	
	// For Account No.
	// setAccount -  set account no.
	public void setAccount(String addA) {
		accountNum = addA;
	}
	// getAccount - get account no.
	public String getAccount() {
		return accountNum;
	}
	
	// Check account no.
	// The structure is similar to the customer ID
	// input: the entered account no.
	// return: the correct account no.
	public String checkAccount(String accountNum) {
		
		// TryCatch method to check that the account number contains 7 digits,
		// otherwise throw to NumberException
		try {
			
			// Check the length is seven
			if (accountNum.length() != 7) {
				throw new NumberException();
					}
			
			// Check if all are digits
			if (checkDigits(accountNum) == false) {
				throw new NumberException();
			}
			
		} catch (NumberException e) {
			
			System.out.println("Incorrect Account No. "
					+ "The Account number must be of seven digits.");
			
			do {
				System.out.println("Input again.");
				accountNum = in.next();
				correct = true;
				if (accountNum.length() != 7) {
					correct = false;
				}
				if (checkDigits(accountNum) == false) {
					correct = false;
				}
			} while(!correct);
		}
		return accountNum;	
	}
	
	// For balance
	// setBalance - set balance
	public void setBalance(String addB) {
		balance = addB;
	}
	// getBalance - get balance
	public String getBalance() {
		return balance;
	}
	// Check balance
	// The structure is similar to the customer ID
	// input: the entered balance
	// return: the correct balance
	public String checkBalance(String balance) {
		
		// TryCatch method to check the balance is larger or equal to 1000
		try {
			
			// Requirement: four number digits and at least 1000
			// b0 - variable length is larger or equal than 4
			// b1 - the first digit is from 1-9. Ensure it isn't 0100 kr
			boolean b0 = balance.length() >= 4;
			boolean b1 = balance.charAt(0) >= '1' && balance.charAt(0) <='9';
			
			// Check if the booleans are true
			if (!b0 || !b1) {
				// If false, then throw to Number Exception
				throw new NumberException();
			}
			// Check that all digits are numbers
			if (checkDigits(balance) == false) {
				throw new NumberException();
			}
			
		} catch (NumberException e) {
			
			System.out.println("Initial balance "
					+ "must be equal to or higher than 1000");
			correct = true;
			
			do {
				System.out.println("Input again.");
				balance = in.next();
				boolean b0 = balance.length() >= 4;
				boolean b1 = balance.charAt(0) >= '1' && balance.charAt(0) <='9';
				correct = true;
				
				if (!b0 || !b1) {
					correct = false;
				}
				if (checkDigits(balance) == false) {
					correct = false;
				}
				
			} while (!correct);
				
		}	
		return balance;
	}
	
	
	// checkDigits - Check that the input string are all digits
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
	
	
	// Main method
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		System.out.println("Hi");
		BankAccount newBankA = new BankAccount(); 		// Create a empty bank account object
		
		// Customer ID
		System.out.println("Enter customer ID: ");
		String prelID = in.next();						// Scan the prel. ID
		String newID = newBankA.checkID(prelID); 		// Throw to checkID method to return a correct ID
		newBankA.setID(newID);							// Save the ID to the obj.
		
		System.out.println("Enter account no : ");
		String prelAcc = in.next();						// Scan the prel. account no.
		String newAcc = newBankA.checkAccount(prelAcc); // Throw to checkAccount method to return a correct account no.
		newBankA.setAccount(newAcc);					// Save the account no. to the obj.
		
		System.out.println("Enter balance : ");			// Scan the prel. balance
		String prelBal = in.next();						// Throw to checkBalance method to return a correct balance
		String newBal = newBankA.checkBalance(prelBal);	// Save the balance to the obj.
		newBankA.setBalance(newBal);
		
		// Finish telling the user that the account is created
		System.out.println("Congratulations, "
			+ "your account has been create successfully!"); 
		
	}

}
