package nt222gp_assign3;

public class Person {
	// Data members
	private String name;
	private String address;
	private String phone;
	private String email;
	
	// Constructor
	public Person(String n, String ad, String ph, String em) {
		name = n;
		address = ad;
		phone = ph;
		email = em;
	}
	
	// Method toString - returns a string with 
	// the data information of an Person object 
	public String toString() {
		String printString = "Name: " + name + "\n" 
							+ "Address: " + address+ "\n" 
							+ "Phone: " + phone+ "\n" 
							+ "Email: " + email;

		return printString;
	}
	
}
