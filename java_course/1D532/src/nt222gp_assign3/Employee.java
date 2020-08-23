package nt222gp_assign3;

public class Employee extends Person {
	// Data members
	private String salary;
	private String dateHired;
	
	// Constructor
	public Employee(String n, String ad, String ph, String em, String sal, String dH) {
		super(n, ad, ph, em); // Defined in the superclass Person
		salary = sal;
		dateHired = dH;
	}
	
	
	// Method toString
	public String toString() {
		// super.toString() - calls the method toString from the superclass Person
		String printString = super.toString() + "\n"
							+ "Salary: " + salary + "\n"
							+ "Date hired: " + dateHired;

		return printString;
	}
}
