import java.io.*;
import java.util.List;
import java.util.Scanner;
import java.util.ArrayList;

public class Blowfish {
    static void getInput(ArrayList<String> input) {
        System.out.println("Enter the Message: ");
        Scanner sc = new Scanner(System.in);
        String temp = sc.nextLine();
        input.add(temp);
        return;
    }

    static void print(ArrayList<String> list) {

        for (String str : list) {
            System.out.println(str);        // OR list.get(i);
        }
        return;
    }

    void encipher() {
        return;
    }

    void decipher() {
        return;
    }

    public static void main(String args[]) {
        ArrayList<String> input = new ArrayList<String>();
        getInput(input);
        print(input);
        return;
    }
}
