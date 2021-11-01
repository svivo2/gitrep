    
/**
 * Time-of-day server listening to port 6013.
 * javac DateServer.java
 * Usage: java DateServer PORT_NUMBER
 *
 * Figure 3.19
 *
 * @author Gagne, Galvin, Silberschatz
 * Operating System Concepts  - Eighth Edition
 * Copyright John Wiley & Sons - 2008.
 */

import java.net.*;
import java.io.*;

public class DateServer
{
	public static void main(String[] args)  {
		try {
			// Use this line to hard code
			//int port = 6013;
			// Use this line for command line
			int port = Integer.parseInt(args[0]);
			ServerSocket sock = new ServerSocket(port);

			// now listen for connections
			while (true) {
				Socket client = sock.accept();
				// we have a connection

				PrintWriter pout = new PrintWriter(client.getOutputStream(), true);
				// write the Date to the socket
				pout.println(new java.util.Date().toString());

				// close the socket and resume listening for more connections
				client.close();
			}
		}
		catch (IOException ioe) {
				System.err.println(ioe);
		}
	}
}
