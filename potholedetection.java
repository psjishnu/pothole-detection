import java.io.*;

class input
{
public  int readinput() throws IOException
 { 
 
  File file = new File("C:\\Users\\Jishnu\\Desktop\\gps.txt"); 
  
  BufferedReader rdr = new BufferedReader(new FileReader(file)); 
  String st; 
 while ((st = rdr.readLine()) != null)     //read from input file
 {   char[] chars=st.toCharArray();
	String lat=st.substring(0,9);                       // value of latitute
	System.out.println(lat);
	String lon=st.substring(10,19);  //value of longitude
	System.out.println(lon);
	String val=st.substring(20,21);  //value of pothole
//	 int a=Character.getNumericValue(val);
//	int b=Integer.parseInt(String.valueOf(lon));
	//int c=Integer.parseInt(String.valueOf(val));
	test obj2 = new test();
	obj2.eval(val,lat,lon);
 }
 return 1;
  } 
}
class test extends input
{
	void  eval(String aa,String lata,String lona) throws FileNotFoundException 
    { 
	
	
	//	FileWriter fstream = new FileWriter("C:\\Users\\Jishnu\\Desktop\\pwd.txt",true);
    //    BufferedWriter fbw = new BufferedWriter(fstream);		
	//		PrintStream o = new PrintStream(new File("C:\\Users\\Jishnu\\Desktop\\pwd.txt"));
	//		System.setOut(o); 
	//		System.out.append("  ");
		
		 int a=Integer.parseInt(aa);
		if(a>8)
		{
			
//			fbw.write(a);
	//		PrintStream o = new PrintStream(new File("C:\\Users\\Jishnu\\Desktop\\pwd.txt"));
	//		System.setOut(o); 
			System.out.println("need immediate maintainance!"+": "+aa+" "+lata+" "+lona);
		}
		else if(a>5)
		{	
	//		PrintStream o = new PrintStream(new File("C:\\Users\\Jishnu\\Desktop\\pwd.txt"));
	//		System.setOut(o);
	//		fbw.write(a);
			System.out.println("bad condition at: "+aa+" "+lata+" "+lona);
		}
	}

	
}

public class kkk
{
  public static void main(String[] args) throws Exception
  {
    input obj =new input();
	int s=obj.readinput();
  }
};
