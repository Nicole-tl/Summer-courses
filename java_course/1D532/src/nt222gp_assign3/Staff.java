package nt222gp_assign3;

// Subclass of Employee
public class Staff extends Employee{
	// Data members
	private String title;
	
	
	// Constructor
	public Staff(String n, String ad, String ph, String em, String sal, String dH, String tit) {
		// super() inserts variables to the superclass Employee constructor
		// and in Employee few variables will be implemented by its superclass
		super(n, ad, ph, em, sal, dH);
		title = tit;
	}
	
	// Method
	public String toString() {
		// super.toString() calls the toString method from Employee
		String printString = super.toString() + "\n"
							+  "Title: " + title;
		return printString;
	}
}
