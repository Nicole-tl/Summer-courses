package nt222gp_assign3;

//Subclass of Employee
public class Faculty extends Employee{
	// Data members
	private String officeHours;
	private String rank;
	
	// Constructor
	public Faculty(String n, String ad, String ph, String em, String sal, String dH, String oH, String r) {
		// super() inserts variables to the superclass Employee constructor
		// and in Employee few variables will be implemented by its superclass
		super(n, ad, ph, em, sal, dH);  
		officeHours = oH;
		rank = r;
	}
	
	// Method
	public String toString() {
		// super.toString() calls the toString method from Employee
		String printString = super.toString() + "\n"
							+ "Office hours: " + officeHours + "\n"
							+ "Rank: " + rank;
		return printString;	
	}
}
