package nt222gp_assign2;

import java.util.Scanner;

public class Money {
	// Date members
	private int dollars;
	private int cents;
	
	// Constructor
	public Money(int d, int c) {
		dollars = d;
		cents = c;
	}
	public Money(int d) {
		dollars = d;
		cents = 0;
	}
	public Money() {}
	
	// Methods
	
	// get and set for dollar
	public int getDollars() {
		return dollars;
	}
	public void setDollars(int newD) {
		dollars = newD;
	}
	
	// get and set for cents
	public int getCents() {
		return cents;
	}
	public void setCents(int newC) {
		cents = newC;
	}
	
	
	// Addition of two objects and return an object with sum of
	// of the two objects' money
	public static Money add(Money n1, Money n2) {
		Money sum = new Money();
		
		sum.setDollars(n1.getDollars() + n2.getDollars());
		sum.setCents(n1.getCents()+n2.getCents());
		
		double sumC = (((n1.getCents()+n2.getCents())));
		double sumTot = (n1.getDollars()+n2.getDollars()) + (sumC/100);
		
		System.out.println("Adding money1 and money2: $" + sumTot);
		return sum;
	}
	
	// Subtraction of two objects and return an object
	public static Money diff(Money n3, Money n4) {
		Money diff = new Money();
		
		diff.setDollars(n4.getDollars() - n3.getDollars());
		diff.setCents(n4.getCents() - n3.getCents()); 
		
		double diffC = n4.getCents() - n3.getCents();
		double diffTot = (n4.getDollars() - n3.getDollars()) + (diffC/100);
		
		System.out.println("Subtracting money1 from money2: $" + diffTot);
		return diff;
	}
	
	
	public static void main(String[] args) {
		Money m1 = new Money();
		Money m2 = new Money();
		
		// Set money for obj 1
		String s1 = "$2,00";
		System.out.println("Money 1 is: " + s1);
		String dollars1 = s1.substring(s1.indexOf("$") + 1, s1.indexOf(","));
		m1.setDollars(Integer.parseInt(dollars1));
		String cents1 = s1.substring(s1.indexOf(",") + 1);
		m1.setCents(Integer.parseInt(cents1));
		
		// Set money for obj 2
		String s2 = "$5,05";
		System.out.println("Money 2 is: " + s2 + "\n");
		String dollars2 = s2.substring(s2.indexOf("$") + 1, s2.indexOf(","));
		m2.setDollars(Integer.parseInt(dollars2));
		String cents2 = s2.substring(s2.indexOf(",") + 1);
		m2.setCents(Integer.parseInt(cents2));
		
		
		// Print money
		System.out.println("Money1's dollars are: " + m1.getDollars());
		System.out.println("Money1's cents are: " + m1.getCents());
		System.out.println("Money2's dollars are: " + m2.getDollars());
		System.out.println("Money2's cents are: " + m2.getCents() + "\n");

		// add and subtract obj1 with obj2
		add(m1,m2);
		diff(m1,m2);

	}
	
}
