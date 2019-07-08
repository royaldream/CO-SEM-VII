import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Enumeration;
import java.util.Hashtable;
import java.util.Scanner;
import java.util.Set;

import javax.print.attribute.HashAttributeSet;

public class DM_Practical_2 {

	int choice = 0;
	FileReader fin;
	FileWriter fout;
	BufferedReader bin;
	BufferedWriter bout;
	String[] cols;
	ArrayList<String[]> dataList;
	Double initalData[][];
	String line = null;
	int missingCol[];

	public DM_Practical_2() throws IOException {
		initalData = new Double[26][3];
		fileRead();
		Scanner s = new Scanner(System.in);
		System.out.println("Menu\n1 : Mean\n2 : Meaden\n3 : Mode\n0 : Exit\n");
		choice = s.nextInt();
		while (true) {
			if (choice == 0)
				break;
			fillMissing();
			printIntialData();
			fillMissingDatawithMean();
			// printData();
			fileWrite();
			choice = s.nextInt();
		}
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		new DM_Practical_2();
	}

	private void printIntialData() {
		for (Double a[] : initalData)
			System.out.println("Sum : " + a[0] + "\t NO :" + a[1] + " Mean : " + a[2]);
	}

	private void printData() {
		for (String[] a : dataList) {
			for (String cols : a) {
				System.out.println(cols);
			}
		}
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
		fout = new FileWriter(new File("assets/imports-85-2.data"));
		bout = new BufferedWriter(fout);
		for (String[] rows : dataList) {
			line = String.join(",", rows);
			bout.write(line + "\n");
		}
		bout.close();
		bin.close();
		fin.close();
		fout.close();
		// TODO Auto-generated method stub

	}

	private void fillMissing() {
		missingCol = new int[26];
		int j = 0;
		for (String[] rows : dataList) {
			int i = 0;
			for (String cols : rows) {
				// System.out.print(i + "\t" + cols);
				if (cols.contains("?"))
					missingCol[i] = 1;
				// dataList.get(j)[i] = initalData[i];
				i++;
			}
			// System.out.println();
			j++;
		}
		for (int i = 0; i < missingCol.length; i++) {
			if (missingCol[i] == 1) {
				calculateMissingData(i);
			}
		}
	}

	private void calculateMissingData(int i) {

		String mode[][] = null;
		//if (choice == 1 || choice == 2)
			if (i == 5)
				return;

		int j = 0;
		System.out.println("cols : " + i);
		double sum = 0, n = 0;
		for (String[] rows : dataList) {
			if (!rows[i].contains("?"))
				try {
					if (choice == 1)
						sum = sum + Double.parseDouble(rows[i]);
					// else if(choice == 3)
					// {
					// if()
					// mode[j][0]=rows[i];
					// mode[j][1]=String.valueOf(0);
					// }
					n++;
					j++;
					// System.out.println(rows[i]);
				} catch (Exception e) {
					// e.printStackTrace();
				}
			/*
			 * for (int key = 0; key < rows.length; key++) { }
			 */
		}
		// System.out.println(sum + " : " + n);

		intialData(i, sum, (double) n);

	}

	private void intialData(int index, double sum, double cnt) {
		if (choice == 1) {
			initalData[index][0] = sum;
			initalData[index][1] = cnt;
			initalData[index][2] = sum / cnt;
		} else if (choice == 2) {
			int i = dataList.size() / 2;
			if (dataList.size() % 2 == 0) {
				String[] cols = dataList.get(i);
				// System.out.println("size"+dataList.size()+" "+cols[index]+"
				// "+i+" "+index);
				Double a = Double.parseDouble(cols[index]);
				cols = dataList.get(i - 1);
				Double b = Double.parseDouble(cols[index]);
				// System.out.println("size"+dataList.size()+" "+cols[index]+"
				// "+i+" "+index);
				initalData[index][1] = (double) dataList.size();
				initalData[index][2] = (a + b) / 2;
				System.out.println(a + "\t" + b);
			} else {
				initalData[index][1] = (double) dataList.size();
				initalData[index][2] = Double.parseDouble(cols[i - 1]);
			}
		} else if (choice == 3) {
			int i = index;
			Hashtable<String, Integer> datas = new Hashtable<String, Integer>();
			// ArrayList<String> datas=new ArrayList<>();
			// ArrayList<Integer> mcounter=new ArrayList<Integer>();
			for (String[] rows : dataList) {
				if (!rows[i].contains("?")) {
					if (!datas.containsKey(rows[i])) {
						datas.put(rows[i], 0);

					} else {
						// System.out.println(datas.get(rows[i]));
						datas.replace(rows[i], datas.get(rows[i]), datas.get(rows[i]) + 1);
					}
				}
			}
			int maxValues = 0;
			for (String data : datas.keySet()) {
				if (datas.get(data) > maxValues) {
					System.out.println(maxValues);
					maxValues = datas.get(data);
					initalData[index][2] = Double.parseDouble(data);
				}
			}
		}
	}

	private void fillMissingDatawithMean() {
		int j = 0;
		for (String[] rows : dataList) {
			int i = 0;
			for (String cols : rows) {
				// System.out.print(i + "\t" + cols);
				if (cols.contains("?"))
					if (initalData[i][2] != null)
						dataList.get(j)[i] = String.valueOf(initalData[i][2]);
				i++;
			}
			// System.out.println();
			j++;
		}
	}

}
