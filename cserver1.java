import java.net.*;

import java.io.*;

public class server1 

{

	public static void main( String args[]) throws Exception

	{

		ServerSocket srs = new ServerSocket(5050);

		System.out.println("Server is running...");

		Socket ss=srs.accept();

		System.out.println("connection establised");

BufferedReader kb = new BufferedReader(new 
InputStreamReader(System.in));

BufferedReader br = new BufferedReader(new 
InputStreamReader(ss.getInputStream()));

DataOutputStream dos = new DataOutputStream(ss.getOutputStream());

 

 while(true)

 {

  //System.out.println("server repeat as long as client not send null");

  String s2,s3; 

  while((s2=br.readLine())!=null)

  {

 	System.out.println("Client said : "+s2);

 	System.out.println("Enter text ");

    s3 = kb.readLine();

    //System.out.println("Answer send to client machine");

 	dos.writeBytes(s3+"\n");

  }

  System.out.println("Terminated..");

  ss.close(); 

  srs.close();

  dos.close();

  kb.close();

  System.exit(0);

  }

 }

}


