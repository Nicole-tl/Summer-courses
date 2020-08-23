/**
 * BreakContinueDemo.java
 * Author: Nadeem Abbas
 */

package dv532.step1;
/*
 * A program that demonstrates use of the 
 * break and continue statements
 */
class BreakContinueDemo {
   public static void main(String[] args) {
      
      for (int i = 1; i <= 20; ++i) {      
         if (i == 10) { //break the loop when i is equal to 10
            break;
         }  
         if (i% 2 == 0) { // continue the loop if i is an even number
             continue; 
          }
         System.out.println(i);
      }   
   }
}