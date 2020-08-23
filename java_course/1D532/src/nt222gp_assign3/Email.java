package nt222gp_assign3;

// Subclass of Message
public class Email extends Message {
	// Data members
	// these data is stored as string because then it would be more flexible 
	// wheather the user only writes the name or the email (with non-alpha. signs)
	private String sender;
	private String reciever;
	private String subject;
	
	// Constructor
	public Email(String s, String r, String sub, String t) {
		super(t);
		sender = s;
		reciever = r;
		subject = sub;
	}
	
	// Methods - set and get (mutator and accessor)
	public String getSender() {
		return sender;
	}
	public String getReciever() {
		return reciever;
	}
	public String getSubject() {
		return subject;
	}
	
	public void setSender(String s) {
		sender = s;
	}
	public void setReciever(String r) {
		reciever = r;
	}
	public void setSubject(String sub) {
	}
	
	// toString
	public String toString() {
		String printString = "From: " + getSender()
							+ "\n\nTo: " + getReciever()
							+ "\n\nSubject: " + getSubject()
							+ "\n\n" + super.toString();
		return printString;
	}
	
	// Encoding method - read the encode() from the class Message for more description
	public String encode() {
		String newText = "";
		String text = super.toString();
		for (int i = 0; i <= text.length()-1; i++) {
			char charact = text.charAt(i);
			int charValue = charact;
			boolean cap = (charValue >= 65 && charValue<=90);
			boolean low = (charValue >= 97 && charValue<=122);
			if (cap || low) {
				String encodeChar = String.valueOf( (char) (charValue + 1));
				newText = newText + encodeChar;
			}
			else {
				newText = newText + charact;
			}
			
		}
		return newText;
	}
}
