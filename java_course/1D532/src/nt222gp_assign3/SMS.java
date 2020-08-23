package nt222gp_assign3;

// Subclass of Message
public class SMS extends Message {
	// Data members
	// recipientContactNo type: The type Int would not be a suitable type because it do not store more than 2147483647
	// and the recipient no. could be written with the country code (e.g. +46, +164...)
	// Then string would be more suitable when the digits will to be stored together with different signs.
	private String recipientContactNo;
	
	// Constructor
	public SMS(String s, String No) {
		super(s); 	// s implemented to text in the superclass Message
		recipientContactNo = No;	
	}
	
	// Method
	// accessor - same as get method
	public String accessor() {
		return recipientContactNo;
	}
	// mutator - same as set method
	public void mutator(String rCNo, String text) {
		recipientContactNo = rCNo;
		setText(text);
	}
	// toString - print the text message and the recipient contact no
	public String toString() {
		String printString = super.toString() + " - " + accessor();
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
