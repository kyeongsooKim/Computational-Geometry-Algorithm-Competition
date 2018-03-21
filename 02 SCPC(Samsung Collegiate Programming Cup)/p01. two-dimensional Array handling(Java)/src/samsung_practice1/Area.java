package samsung_practice1;

public class Area{
	private int[][] map;
	private int size;
	
	public Area (int size){
		this.size = size;
		map = new int[this.size][this.size];
	}
	
	public void initArea(){
		for (int i = 0; i < size; i++ ){
			for (int j = 0; j < size; j++ ){
				map[i][j] = 0; 
			}
		}
	}
	
	public int getValue(int i, int j){
		if ( i >= size || j>= size){
			System.out.println("Array index out of bounds");
			return -1;
		}
		return map[i][j];
	}
	
	public void setValue(int i, int j, int value){
		if ( i >= size || j>= size){
			System.out.println("Array index out of bounds");
		}
		else {
			map[i][j] = value;
		}
	}
	
	public int showSafeSpot(){
		int safeSpotCount = size * size;
		for (int i = 0; i < size; i++ ){
			for (int j = 0; j < size; j++ ){
				if (map[i][j] != 0)
					 safeSpotCount--;
			}
		}
		return safeSpotCount;
	}
	
	public void showAllArea(){
		for (int i = 0; i < size; i++ ){
			for (int j = 0; j < size; j++ ){
				if ( 'A' <= map[i][j] && map[i][j] <= 'C'){
					System.out.print((char)map[i][j] + " ");
				}
				else
					System.out.print(map[i][j] + " ");
			}
			System.out.println();
		}
		System.out.println();
	}
	
	public void getBomb(int i, int j, int bomb){
		switch(bomb){
		case 'C' : if ( i > 2) map[i-3][j] = 1;
				   if ( j > 2) map[i][j-3] = 1;
				   if ( i < size - 3) map[i + 3][j] = 1;
				   if ( j < size - 3) map[i][j + 3] = 1;
		case 'B' : if ( i > 1) map[i-2][j] = 1;
				   if ( j > 1) map[i][j-2] = 1;
				   if ( i < size - 2) map[i + 2][j] = 1;
				   if ( j < size - 2) map[i][j + 2] = 1;
		case 'A' : if ( i > 0) map[i-1][j] = 1;
				   if ( j > 0) map[i][j-1] = 1;
				   if ( i < size - 1) map[i + 1][j] = 1;
				   if ( j < size - 1) map[i][j + 1] = 1;
		}
		map[i][j] = bomb;
	}
}
