package Estudos.QUIZ03;
import java.util.Scanner;
public class pesquisasequencial {
    public static boolean PesquisaSequencial(int[] vetor, int valor){
        boolean resp = false;
        for(int i = 0; i < vetor.length; i++){
            if(vetor[i] == valor){
                i = vetor.length;
                resp = true;
            }
        }
        return resp;
    }

    public static void main(String[] args){
        int[] vetor = {1,2,3,4,5,6,7,8,9,10};
        Scanner sc = new Scanner(System.in);
        System.out.print("Digite o valor a ser pesquisado: ");
        int valor = sc.nextInt();
        if(PesquisaSequencial(vetor, valor)){
            System.out.println("Valor encontrado!");
    }
}
}
