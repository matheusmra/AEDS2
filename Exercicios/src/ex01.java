 
public class ex01 {
    public static void main(String[] args) {
        int x = 10;
        System.out.println("Primeiro código em Java!");
        for (int i = 1; i <= 5; i++ ){
            System.out.println("i = " + i);
            if(i %2 == 0){
                System.out.println("O numero: " + i + " é par");
            }else{
                System.out.println("O numero: " + i + " é impar");
            }
        }
        System.out.print(x);
    }
}
