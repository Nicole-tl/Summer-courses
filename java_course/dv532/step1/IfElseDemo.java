/**
 * IfElseDemo.java
 * Author: Copied from https://docs.oracle.com/javase/tutorial/java/nutsandbolts/if.html
 */

package dv532.step1;

/*
 * A program that demonstrates use of the 
 * if else statements
 */

class IfElseDemo {
    public static void main(String[] args) {

        int testscore = 40;
        char grade;

        if (testscore >= 90) {
            grade = 'A';
        } else if (testscore >= 80) {
            grade = 'B';
        } else if (testscore >= 70) {
            grade = 'C';
        } else if (testscore >= 60) {
            grade = 'D';
        } else {
            grade = 'F';
        }
        System.out.println("Grade = " + grade);
    }
}