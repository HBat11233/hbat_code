import java.util.Scanner;
class ScannerTest
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Input a inter:");
        int a = scanner.nextInt();
        System.out.printf("%d的平方是%d\n",a,a*a);
    }
}