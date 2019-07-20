import java.awt.Choice;
import java.io.*;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;

public class DM_Practical_4 {
	FileInputStream fin;
	FileOutputStream fout;
	BufferedReader buffIn;
	BufferedOutputStream buffOut;
	String data;

	ArrayList<String> dataArray;
	int binSize, nobin;

	public DM_Practical_4() {
		try {
			fin = new FileInputStream(new File("assets/input.data"));
			buffIn = new BufferedReader(new InputStreamReader(fin));
			String[] cols;
			dataArray = new ArrayList<>();
			while ((data = buffIn.readLine()) != null) {

				cols = data.split(", ");
				dataArray.addAll(Arrays.asList(cols));
				// System.out.println(data);
			}
			/*
			 * for (String d : dataArray) { System.out.println(d); }
			 */
			System.out.println("With Sorted");
			{
				ArrayList<Integer> dta = new ArrayList<>();
				for (String d : dataArray)
					dta.add(Integer.valueOf(d));
				Collections.sort(dta);
				dataArray.clear();
				for (Integer i : dta) {
					dataArray.add(String.valueOf(i));
				}
			}
			// Collections.sort(dataArray);
			for (String d : dataArray) {
				System.out.println(d);
			}

			buffIn.close();
			fin.close();
		} catch (Exception e) {
			e.getMessage();
		}

		calculateBinSize();
		nobin = dataArray.size() / binSize;
		System.out.println("Total Size :" + dataArray.size() + "Bin Size :" + binSize);
		normlizeBins(0);
	}

	private void normlizeBins(int choice) {
		// ArrayList<Integer> meanArray = new ArrayList<>();
		int sum = 0;
		if (choice == 0) {
			for (int i = 0; i < nobin; i++) {
				for (int j = 0; j < binSize; j++) {
					// meanArray.add(Integer.valueOf(dataArray.get(i + j)));
					sum += Integer.valueOf(dataArray.get(i * binSize + j));
				}
				for (int k = 0; k < binSize; k++) {
					dataArray.set(i * binSize + k, String.valueOf((double) sum / (double) binSize));
				}
				sum = 0;
			}
		}
		for (String d : dataArray) {
			System.out.println(d);
		}
		// TODO Auto-generated method stub

	}

	private void calculateBinSize() {
		int min = dataArray.size();
		for (int i = 1; i < dataArray.size() / 2; i++) {
			if (dataArray.size() % i == 0) {
				if (min > Math.abs(dataArray.size() / i - i)) {
					min = Math.abs(dataArray.size() / i) - i;
					System.out.println("bin : " + binSize + "min : " + (Math.abs(dataArray.size() / i) - i));
					binSize = i;
				}
			}
		}
		// TODO Auto-generated method stub

	}

	public static void main(String[] args) {
		new DM_Practical_4();
	}
}
