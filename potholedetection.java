import java.io.*;

class Sensor
{
public  int readinput() throws IOException         //to input data from input file (latitude,longitude,sensor value at that location) and passes it to class upload
 { 
  File file = new File("C:\\Users\\Jishnu\\Desktop\\gps.txt"); 
  BufferedReader rdr = new BufferedReader(new FileReader(file)); 
  String st; 	
  PrintStream o = new PrintStream(new File("C:\\Users\\Jishnu\\Desktop\\pwd.txt"));
	System.setOut(o); 
 while ((st = rdr.readLine()) != null)    				 //reads data from input file
 {  
	String lat=st.substring(0,9);                       // value of latitude
	String lon=st.substring(10,19);  					//value of longitude
	String val=st.substring(20,21); 					 //value of damage
	upload obj2 = new upload();							
	obj2.upload_damaged_to_pwd(val,lat,lon);			//passes the data to be checked(the road condition) to the function  upload_damaged_to_pwd() 
 }
 return 1;
  } 
}
class upload extends Sensor
{
	void  upload_damaged_to_pwd(String val2,String lat2,String lon2) throws FileNotFoundException //Writes the latitude,longitude of road which are damaged along with the intensity of damage to a file to be sent to pwd(public works department)
    { 	
	
		 int value=Integer.parseInt(val2);
		if(value>7)
		{ 
			System.out.println("need immediate maintainance!"+": "+val2+" "+lat2+" "+lon2);
		}
		else if(value>5)
		{	
			System.out.println("bad condition at: "+val2+" "+lat2+" "+lon2);
			
		}
		
	}

	
}

public class potholedetection
{
  public static void main(String[] args) throws Exception
  {
    Sensor obj =new Sensor();
	int s=obj.readinput();
  }
};
