//ODD:Implement poly alphabetic subtitution cipher that constist of several cesaer in sequence bit differ shift value in / key from file.
package exam;

import java.io.*;

public class Exam {

	FileReader fin;
	FileWriter fout;
	BufferedReader buffIn;
	BufferedWriter buffout;
	String plain_Text, Key,cText,pText;
	char newKey[];
	public Exam() {
		try {

			fin = new FileReader(new File("assets/input.txt"));
			buffIn = new BufferedReader(fin);
			plain_Text = buffIn.readLine();
			Key = buffIn.readLine();
			
			System.out.println("Plain Text : "+plain_Text + "\nKey : " + Key);
			
			if(Key.length()<plain_Text.length())
			{
				int diff=plain_Text.length()-Key.length();
				for(int i=0;i<diff;i++)
				{
					Key+=Key.charAt(i%(Key.length()-1));
				}
			}
			newKey=Key.toCharArray();
			System.out.print("New Key : ");
			for(char a:newKey)
				System.out.print(a);
			encryption();
			decryption();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private void decryption() {
		// TODO Auto-generated method stub
		pText=new String();
		int i=0;
		System.out.println();
		for(char d:cText.toCharArray())
		{
			int p,k,c;
			p=(char)d;
			k=Key.charAt(i);
			c=Math.abs((26+p-k))%26+65;
			pText+=(char)c;
			i++;
			
//			System.out.println(k+"+"+p+"="+(char)c);
			
		}
		System.out.println("Plain Text :- "+pText);
	}

	private void encryption() {	
		cText=new String();
		int i=0;
		System.out.println();
		for(char d:plain_Text.toCharArray())
		{
			int p,k,c;
			p=(char)d;
			k=Key.charAt(i);
			c=(p+k-65-65)%26+65;
			cText+=(char)c;
			i++;
			
//			System.out.println(k+"+"+p+"="+(char)c);
		}
		System.out.println("Cipher Text :"+cText);
	}

	public static void main(String[] args) {
		new Exam();
	}

}
