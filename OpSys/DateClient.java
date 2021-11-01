/*
  Client program requesting current date from server.

  javac DateClient.java
  Usage: java DateClient HOSTNAME_OR_IP PORT
 */

import java.net.*;
import java.io.*;

public class DateClient
{
	public static void main(String argv[])  {
		try {
			// this could be changed to an IP name or address other than the localhost
			int port = Integer.parseInt(argv[1]);
			Socket sock = new Socket(argv[0], port);
			InputStream in = sock.getInputStream();
			BufferedReader bin = new BufferedReader(new InputStreamReader(in));

			String line;
			while( (line = bin.readLine()) != null)
				System.out.println(line);

			sock.close();
		}
		catch (IOException ioe) {
				System.err.println(ioe);
		}
	}
}
