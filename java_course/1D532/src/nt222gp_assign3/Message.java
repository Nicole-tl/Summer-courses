package nt222gp_assign3;

public class Message {
	// Data members
	private String text;
	
	// Constructor
	public Message(String s) {
		text = s;
	}
	
	// Methods
	// toString - return text
	public String toString() {
		return text;	
	}
	// setText - set the text data
	public void setText(String s) {
		text = s;
	}
	
	// Encode the message as given from the instruction and return a new encoded text.
	// each letter should be replaced by the character after itself
	// and do nothing for the non-alphabetic characters (aswell for space)
	// It was changed by finding its ASCII value and add it with one.
	// The numbers of the character were found here: https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html
	public String encode() {
		String newText = "";
		for (int i = 0; i <= text.length()-1; i++) {
			char charact = text.charAt(i);
			int charValue = charact;
			
			boolean cap = (charValue >= 65 && charValue<=90); 	// With capslock
			boolean low = (charValue >= 97 && charValue<=122);	// Without capslock
			
			// If statement to check if the character is an alphabet
			// if yes -> encode
			// else -> do nothing
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
