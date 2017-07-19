package samsung_practice1;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.FileReader;

public class practice1 {
	public static void main(String[] args){
		BufferedReader in;
		FileWriter out;
		
		String str;
		int testNum; //test case num
		
		int ptx = 0, pty = 0; // x and y coordinates
		
		
		try {
			in = new BufferedReader(new FileReader("input.txt"));
			out = new FileWriter("output.txt");
			
			testNum = Integer.valueOf(in.readLine());
			
			for (int i = 0; i <testNum; i++){
				Area area = new Area(Integer.valueOf(in.readLine()));
				area.initArea();
				str = in.readLine();
				String[] bombTypes = str.split(",");
				
				char bombType = 'A';
				for(String s : bombTypes){
					String[] bombsVar = s.split(" ");
					int flag = 0;
					for (int j=0; j < bombsVar.length; j++){
						if (j%2 == 0){
							ptx = Integer.valueOf(bombsVar[j]);
							flag++;
						}
						else{
							pty = Integer.valueOf(bombsVar[j]);
							flag++;
						}
						if  (flag == 2){
							area.getBomb(ptx, pty, bombType);
							flag = 0;
							ptx = 0;
							pty = 0;
						}
					}
					bombType++;
				}
				out.write("#" + (i+1) +" "+ area.showSafeSpot() + "\r\n");
				area.showAllArea();
			}
			
			in.close();
			out.close();
			
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
	      
	}
}
