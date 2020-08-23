package nt222gp_assign4.stack;
import nt222gp_assign4.BankAccount;

public interface Stack {
	int size(); 	// returns current number of elements
					// (accounts) in the stack
	
	boolean isEmpty(); 	// true if stack is empty
	
	void push(BankAccount account);	// Adds an account at the top of the 
									// stack.
	
	BankAccount pop();	// returns and removes an account at top, 
						// throws an exception if stack is empty.
	
	BankAccount peek();	// returns (without removing) top element, 
						// throws an exception if stack is empty.
}

