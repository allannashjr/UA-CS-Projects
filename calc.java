import java.util.Scanner;
import java.text.DecimalFormat;

public class calc {
	private static DecimalFormat df2 = new DecimalFormat("#.##");
	public static void main(String args[]) {
		boolean testFail = true;
		
		do {
			//Scanner for String Variables
			Scanner testCalc = new Scanner(System.in);
	
			//Display the Menu
			System.out.println("------------------------");
			System.out.println(" Allan's ISP Calculator ");
			System.out.println("------------------------");
			System.out.println("    Addition(+)");
			System.out.println("    Subtraction(-)");
			System.out.println("    Multiplication(*)");
			System.out.println("    Division(/)");
			System.out.println("    Mod(%)");
			System.out.println("    Quit(q)");
			
			//Gets the User's Choice
			System.out.println("\nPlease Select a Choice");
			String choice = testCalc.nextLine();
			
			//
			calc2 testRun = new calc2();
			
			if(!choice.equals("+") && !choice.equals("-") && !choice.equals("*") && !choice.equals("/") && !choice.equals("%") && !choice.equals("q")) {
				System.out.println("\nPlease Retry With a Valid Option(+, -, *, /, %, or q)");
			}
			
			else {		
				if(choice.equals("q")) {
					System.out.println("\nExitting Program...");
					testFail = false;
				}
			
				else if(choice.equals("+")) {
					float a, b;
					double c;
					System.out.println("Enter Two Numbers");
					Scanner scan = new Scanner(System.in);
					if(!scan.hasNextFloat()) {
						System.out.println("Both Numbers Must Be Ints/Floats!");
					}
					
					else {
						a = scan.nextFloat();
						if(!scan.hasNextFloat()) {
							System.out.println("Both Numbers Must Be Ints/Floats!");
						}
						
						else {
							b = scan.nextFloat();
							c = testRun.add(a,b);
							System.out.println("Answer(Rounding to 2 Decimals): " + df2.format(c));
							System.out.println();
						}
					}
				}
				
				else if(choice.equals("-")) {
					float a, b;
					double c;
					System.out.println("Enter Two Numbers");
					Scanner scan1 = new Scanner(System.in);
					if(!scan1.hasNextFloat()) {
						System.out.println("Both Numbers Must Be Ints/Floats!");
					}
					
					else {
						a = scan1.nextFloat();
						if(!scan1.hasNextFloat()) {
							System.out.println("Both Numbers Must Be Ints/Floats!");
						}
						
						else {
							b = scan1.nextFloat();
							c = testRun.subtract(a,b);
							System.out.println("Answer(Rounding to 2 Decimals): " + df2.format(c));
							System.out.println();
						}
					}
				}
				
				else if(choice.equals("*")) {
					float a, b;
					double c;
					System.out.println("Enter Two Numbers");
					Scanner scan2 = new Scanner(System.in);
					if(!scan2.hasNextFloat()) {
						System.out.println("Both Numbers Must Be Ints/Floats!");
					}
					
					else {
						a = scan2.nextFloat();
						if(!scan2.hasNextFloat()) {
							System.out.println("Both Numbers Must Be Ints/Floats!");
						}
						
						else {
							b = scan2.nextFloat();
							c = testRun.multiply(a,b);
							System.out.println("Answer(Rounding to 2 Decimals): " + df2.format(c));
							System.out.println();
						}
					}
				}
				
				else if(choice.equals("/")) {
					float a, b;
					double c;
					System.out.println("Enter Two Numbers");
					Scanner scan3 = new Scanner(System.in);
					if(!scan3.hasNextFloat()) {
						System.out.println("Both Numbers Must Be Ints/Floats!");
					}
					
					else {
						a = scan3.nextFloat();
						if(!scan3.hasNextFloat()) {
							System.out.println("Both Numbers Must Be Ints/Floats!");
						}
						
						else {
							b = scan3.nextFloat();
							c = testRun.divide(a,b);
							System.out.println("Answer(Rounding to 2 Decimals): " + df2.format(c));
							System.out.println();
						}
					}
				}
				
				
				else if(choice.equals("%")) {
					int a, b, c;
					System.out.println("Enter Two Numbers");
					Scanner scan4 = new Scanner(System.in);
					if(!scan4.hasNextInt()) {
						System.out.println("Both Numbers Must Be Int's!");
					}
					
					else {
						a = scan4.nextInt();
						if(!scan4.hasNextInt()) {
							System.out.println("Both Numbers Must Be Int's!");
						}
						
						else {
							b = scan4.nextInt();
							c = testRun.mod(a,b);
							System.out.println("Answer:" + c);
							System.out.println();
						}
					}
				}
			}			
		} while(testFail);
	}
}