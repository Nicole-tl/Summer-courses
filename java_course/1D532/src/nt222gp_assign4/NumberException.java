package nt222gp_assign4;

// NumberException when the digits hasn't the correct format
public class NumberException extends Exception{
	public NumberException() {
		super("Number Exception!");
	}
	
	public NumberException(String message) {
		super(message);
	}
}
