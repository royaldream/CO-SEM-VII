import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;

public class DM_Practical_7 {
	private FileReader fin;
	private FileWriter fout;
	private BufferedReader bin;
	private BufferedWriter bout;
	private String[] cols;
	private ArrayList<String[]> dataList, classList, classNewList;
	private String line = null;
	private int Newmin = 0, Newmax = 100;

	public DM_Practical_7() {
		// TODO Auto-generated constructor stub
		try {
			fileRead();
			classFileEvalute();
			//Collections.sort(classNewList);
			printClassNewList();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

	private void printClassNewList() {
		// TODO Auto-generated method stub
		System.out.println("-------New Data--------");
		for (String[] a : classNewList) {
			for (String cols : a) {
				System.out.print(cols + " ");
			}
			System.out.println();
		}
	}

	private void classFileEvalute() {
		int flag = 0;
		classNewList = new ArrayList<>();
		for (String[] row : dataList) {

			if (flag != 0) {
				classList = new ArrayList<>();
				System.out.println(
						"---------------Class " + row[0] + "--------------\nRange : [" + row[1] + " , " + row[2] + "]");
				try {
					fin = new FileReader(new File("assets/Practical_7/" + row[0] + ".data"));
					bin = new BufferedReader(fin);

					try {
						while ((line = bin.readLine()) != null) {
							cols = line.split(",");
							classList.add(cols);
						}
						calculateClassData(row[1], row[2]);
						printData();

					} catch (IOException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				} catch (FileNotFoundException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}

			} else
				flag++;
		}
		// TODO Auto-generated method stub

	}

	private void calculateClassData(String min, String max) {
		Double v;
		for (String[] rows : classList) {
			v = (Double.valueOf(rows[1]) - Double.valueOf(min)) / (Double.valueOf(max) - Double.valueOf(min));
			v = v * (double) (Newmax - Newmin) + Double.valueOf(Newmin);
			rows[1]=String.valueOf(v);
			classNewList.add(rows);
		}

	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new DM_Practical_7();
	}

	private void fileRead() throws IOException {
		int i = 0;
		dataList = new ArrayList<>();
		fin = new FileReader(new File("assets/import_data_7.data"));
		bin = new BufferedReader(fin);

		while ((line = bin.readLine()) != null) {
			cols = line.split(",");
			dataList.add(cols);

		}
	}

	private void fileWrite() throws IOException {
		fout = new FileWriter(new File("assets/Practical_7/output_data.data"));
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

	private void printData() {
		for (String[] a : classList) {
			for (String cols : a) {
				System.out.print(cols + " ");
			}
			System.out.println();
		}
	}
}
