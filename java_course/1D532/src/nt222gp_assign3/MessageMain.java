package nt222gp_assign3;

public class MessageMain {
	
	public static void main(String[] args) {
		// Message 
		Message m = new Message("How's your day?");
		System.out.println("Message:\n" + m.toString());
		System.out.println("Message:\n" + m.encode());

		// SMS
		System.out.println("\nSMS: ");
		SMS newSMS = new SMS("Hi, how are you?", "+46761234567");
		newSMS.setText("Hello, how are you?");
		System.out.println(newSMS.toString());
		System.out.println(newSMS.encode());
		
		//Email
		System.out.println("\nEmail: ");
		Email newEmail = new Email("abc@gmail.com",
				"dfg@gmail.com", 
				"Apartment rental", 
				"Hi, \nI would like to rent your appartment, can I get more information about it?");
		System.out.println("Get sender: " + newEmail.getSender());
		System.out.println(newEmail.toString());
		System.out.println(newEmail.encode());

	}

}
