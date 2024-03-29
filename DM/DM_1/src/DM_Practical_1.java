import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class DM_Practical_1 {

	FileReader fin;
	FileWriter fout;
	BufferedReader bin;
	BufferedWriter bout;
	String[] cols;
	ArrayList<String[]> dataList;
	String initalData[];
	String line = null;
	// ArrayList<String> col;

	public DM_Practical_1() throws IOException {
		intialData();
		fileRead();
		printData();
		fillMissing();
		printData();
		fileWrite();
	}

	private void printData() {
		for (String[] a : dataList) {
			for (String cols : a) {
				System.out.println(cols);
			}
		}
		
		// TODO Auto-generated method stub
		
	}

	private void fileRead() throws IOException {
		int i = 0;
		dataList = new ArrayList<>();
		fin = new FileReader(new File("assets/imports-85.data"));
		bin = new BufferedReader(fin);

		while ((line = bin.readLine()) != null) {
			cols = line.split(",");
			dataList.add(cols);

		}
		// TODO Auto-generated method stub
		
	}

	private void fileWrite() throws IOException {
		fout=new FileWriter(new File("assets/imports-85-1.data"));
		bout=new BufferedWriter(fout);
		for(String[]rows : dataList)
		{
			line=String.join(",",rows);
			bout.write(line+"\n");
		}
		bout.close();
		bin.close();
		fin.close();
		fout.close();
		// TODO Auto-generated method stub
		
	}

	private void fillMissing() {
		int j = 0;
		for (String[] rows : dataList) {
			int i = 0;
			for (String cols : rows) {
				//System.out.print(i + "\t" + cols);
				if (cols.contains("?"))
					dataList.get(j)[i] = initalData[i];
				i++;
			}
			//System.out.println();
			j++;
		}

	}

	private void intialData() {
		initalData = new String[26];
		initalData[1] = 46 + "";
		initalData[5] = "three";
		initalData[18] = 4.6f + "";
		initalData[19] = 4.6f + "";
		initalData[21] = 46 + "";
		initalData[22] = 46000 + "";
		initalData[25] = 46000 + "";
	}

	public static void main(String arg[]) throws IOException {
		new DM_Practical_1();
	}

}
