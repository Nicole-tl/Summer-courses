package nt222gp_assign4;

// IDException for the ID
public class IDException extends Exception{
	public IDException() {
		super("ID Number Exception!");
	}
	
	public IDException(String message) {
		super(message);
	}
}
