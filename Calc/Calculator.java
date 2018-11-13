import java.util.Scanner;

public class Main {
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {

        double firstNum = getDouble();
        double secondNum = getDouble();
        char operation = getOperation();
        double result = calc(firstNum,secondNum,operation);
        System.out.println("The result is "+result);

    }

    public static double getDouble(){
        System.out.println("Please input a number:");
        double num;
        if (scanner.hasNextDouble()){
            num = scanner.nextDouble();
        } else{
            System.out.println("You made a mistake. Enter a digit:");
            scanner.next();
            num = getDouble();
        }
        return num;

    }
    public static char getOperation(){
        System.out.println("Enter the operation");
        char operation;
        if(scanner.hasNext()){
            operation = scanner.next().charAt(0);
        } else {
            System.out.println("You made a mistake. Please, try again");
            scanner.next();
            operation = getOperation();
        }
        return operation;
    }

    public static double calc(double firstNum, double secondNum, char operation){
        double result;
        switch (operation){
            case '+':
                result = firstNum + secondNum;
                break;
            case '-':
                result = firstNum - secondNum;
                break;
            case '*':
                result = firstNum * secondNum;
                break;
            case '/':
                result = firstNum / secondNum;
                break;
            default:
                System.out.println("Try again:");
                result = calc(firstNum, secondNum, getOperation());
        }
        return result;
    }


}
