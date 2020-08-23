package nt222gp_assign4.stack;
import nt222gp_assign4.BankAccount;


public class StackImpl implements Stack {
	// Creates variables
	int topAcc = 0;						// Define the digit of the top account
	int arraySize = 1; 					// Initial array length
	private BankAccount[] bankArray; 	// Define an array of bank accounts
	
	// Constructor method
	public StackImpl() {
		bankArray = new BankAccount[arraySize];
	}
	
	
	// METHODS
	// Method print all bank ID from the array
	// !An extra function! 
	public void print() {
		for (int i = 0; i<= topAcc -1; i++) {
			System.out.println(bankArray[i].getID());
		}
	}
	
	// Method Size returns current number of account in stack
	public int size() {
		return topAcc;
	}
	
	// Method isEmpty returns true if no account in stack
	// i.e. if topAcc = 0 
	public boolean isEmpty() {
		if (topAcc == 0) {
			return true;
		}
		return false;
	}
	
	// Method push adds an account at the top of the stack.
	public void push(BankAccount account) {
		// if the bankArray become full -> resize with two times
		if (topAcc >= arraySize) {
			resize();
		}
		bankArray[topAcc++] = account;
	}
	
	// Method for resize the bankArray
	public void resize() {
		arraySize *= 2; 	// set new size
		BankAccount[] tmp = new BankAccount[arraySize]; // create a temporary bank account
		
		// Copy bankArray with tmp array
		for (int i = 0; i<=topAcc-1; i ++) {
			tmp[i] = bankArray[i];
		}
		
		bankArray = tmp;
	}
	
	
	// Method pop returns and removes an account at top, 
	// throws an exception if stack is empty.
	public BankAccount pop() {
		// try get the top account
		try {
			// if the array is empty throw to an exception
			if (isEmpty() == true) {
				throw new StackException();
			}
			
			// Get the last bank account from bankArray
			topAcc-= 1;
			BankAccount topAccount = bankArray[topAcc];

			// Remove the last bank account form bankArray;
			bankArray = removes(bankArray);
			return topAccount;
			
		} catch (StackException e) {
			System.out.println("The stack list is empty."
					+ " Please create some bank account and try pop method again later.");
			// Return an empty account
			BankAccount emptyBank = new BankAccount();
			return emptyBank;
		}
	}
	
	
	// Method Remove removes the top element from the array
	public BankAccount[] removes(BankAccount[] arr) {
		BankAccount[] newArr = new BankAccount[arr.length-1];
		
		for (int i = 0; i <= newArr.length-1; i++ ) {
			newArr[i] = arr[i];
		}
		return newArr;
	}
	
	// Method peak returns (without removing) top element, 
	// throws an exception if stack is empty.
	public BankAccount peek() {
		// try get the top account
		try {
			
			if (isEmpty() == true) {
				throw new StackException();
			}
		
			// Get the last bank account from bankArray
			BankAccount topAccount = bankArray[topAcc-1];
			return topAccount;
		
		} catch (StackException e) {
			System.out.println("The stack list is empty."
							+ " Please create some bank account and try pop method again later.");
			// Return an empty account
			BankAccount emptyBank = new BankAccount();
			return emptyBank;
		}	
	}
}







