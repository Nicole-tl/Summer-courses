package nt222gp_assign4.stack;
import nt222gp_assign4.BankAccount;

public class StackMain {
	public static void main(String[] args) {
		// Creates four accounts
		BankAccount b1 = new BankAccount("a123", "1231392", "1000");
		BankAccount b2 = new BankAccount("k432", "8934222", "18388383");
		BankAccount b3 = new BankAccount("l213", "1432151", "10000");
		BankAccount b4 = new BankAccount("b342", "2421345", "1324");

	
		// Create a stack list
		StackImpl list = new StackImpl();
		
		// Check if empty
		System.out.println("Try isEmpty:");
		
		if (list.isEmpty() == true) {
			System.out.println("The list is empty. \n");
		}
		
		// push bank account to list
		list.push(b1);
		list.push(b2);
		list.push(b3);
		list.push(b4);

		// Return number account in stack
		//list.print();
		
		
		// pop bank account from list
		System.out.println("Try if push, pop and peek are correct:");

		BankAccount topAccount = list.pop();
		System.out.println("The bank account on the top is " + topAccount.getID() + ".");
		topAccount = list.pop();
		System.out.println("The bank account on next is " + topAccount.getID() + ".");
		
		
		// peak bank account from list
		topAccount = list.peek();
		System.out.println("The bank account on the top is " + topAccount.getID() 
						+ " (using peek method).");
		
		// Try out exception in pop and peek
		// First remove all other bank account first
		topAccount = list.pop();
		System.out.println("The bank account on the top is " + topAccount.getID() + ".");
		topAccount = list.pop();
		System.out.println("The bank account on the top is " + topAccount.getID() + ". \n");

		System.out.println("Try exceptions in pop and peek:");

		topAccount = list.pop();
		topAccount = list.peek();


	
	
	}
}
