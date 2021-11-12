''' UDPClient.py
usage: python UDPClient.py HOSTNAMEorIP PORT
Reads text from user, sends to server, and prints answer
Modified by Dale R. Thompson
10/16/17 converted to Python 3
'''
#Sebastian Vivo UAID 010249203

import sys

# Import socket library
from socket import *

# Set hostname or IP address from command line or default to localhost
# Set port number by converting argument string to integer or use default
# Use defaults
if sys.argv.__len__() != 3:
    serverName = 'localhost'
    serverPort = 5556
# Get from command line
else:
    serverName = sys.argv[1]
    serverPort = int(sys.argv[2])

# Choose SOCK_DGRAM, which is UDP
clientSocket = socket(AF_INET, SOCK_DGRAM)
command = 0
while 1:
    # Get message from user
    print("Welcome! (0)QUIT, (1)Deposit, (2)Withdraw, (3)Balance.")
    command = int(input("Please enter command:"))
    # Encode command and send to server
    commandBytes = str(command).encode('utf-8')
    clientSocket.sendto(commandBytes,(serverName, serverPort))

    if command == 1 or command == 2:
        amount = int(input("Please enter amount:"))
        # Encode amount and send to server
        amountBytes = str(amount).encode('utf-8')
        # Create UDP segment with message, hostname/IP, and port. Send it
        clientSocket.sendto(amountBytes,(serverName, serverPort))

    if command > 0 and command < 4:

        # Server work...

        # Wait for balance from server and decode
        balanceBytes, serverAddress = clientSocket.recvfrom(2048)
        balance = balanceBytes.decode('utf-8')
        print(balance)

    else:
        break

print("Closing Client...")
clientSocket.close()
