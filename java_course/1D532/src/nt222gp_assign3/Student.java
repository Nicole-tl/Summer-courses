package nt222gp_assign3;

// extends uses to define a subclass of a superclass (here. Person)
public class Student extends Person {
	// Data members
	private String status; // (freshman, sophomore, junior or senior)
	
	
	// Constructor
	public Student(String n, String ad, String ph, String em, String st) {
		super(n, ad, ph, em); // super is used to define the variables for the superclass
		status = st;
	}
	
	// Method
	public String toString() {
		// super.toString() - calls the method toString from the superclass Person
		String printString = super.toString() + "\n"
							+ "Status: " + status + "\n";
		return printString;
	}
}
