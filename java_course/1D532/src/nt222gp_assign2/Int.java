package nt222gp_assign2;

public class Int {
	// Data Members
	private int number; // the integer
	
	// Constructors
	public Int(int n) {
		number= n;
	}
	public Int() {}
	
	// Member Methods
	// setNumber - Set number as the input
	public void setNumber(int newNumb) {
		number = newNumb;
	}
	// getNumber - return the data member number
	public int getNumber() {
		return number;
	}
	
	// toString - return "Int( #number )"
	public String toString() {
		return "Int(" + number + ")";
	}
	
	// plus - input an Int object and add their data member (number)
	// and return the sum.
	public Int plus(Int objAdd) {
		Int tempSum = new Int(number + objAdd.getNumber());
		return tempSum; 
	}
	
	// div - input an Int object and divide with this data member (number)
	// and return the quotient.
	public Int div(Int objDiv) {
		Int tempDiv = new Int(number / objDiv.getNumber());
		return tempDiv; 
	}
	
	// isLarger - return boolean if the input number is
	// larger than "the objects" number
	public boolean isLargerThan(Int objComp) {
		return (number >= objComp.getNumber());
	}
	
	// isEqual - return boolean if the input number is
	// equal than "the objects" number
	public boolean isEqualTo(Int objComp) {
		return number == objComp.getNumber();
	}

	
	// Main code
	public static void main(String[] args) {
		// Create two Int objects
		Int i1 = new Int(5);
		Int i2 = new Int(2);
		
		// Create an object sum and div
		// sum: calculated by 5 + 2
		// div: calculated by 5/2
		Int sum = i1.plus(i2);
		Int div = i1.div(i2);

		// Check if sum (7) is larger than i1 (5),
		// then print "Sum Int(7) is larger than Int(5)"
		if ( sum.isLargerThan(i1) ) {
			System.out.println("Sum "+ sum.toString()+ " is larger than " +i1.toString() );
		}
		
		// Check if div (5/2) is equal toi2 (2),
		// then print "Both are equal"
		// otherwise "They are not equal"
		if ( div.isEqualTo(i2) ) {
			System.out.println("Both are equal");
		}
		else {
			System.out.println("They are not equal");
		}
		
	}

	
}
