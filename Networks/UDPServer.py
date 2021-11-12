''' UDPServer.py
usage: python UDPServer.py PORT
Reads in text, changes all letters to uppercase, and returns
the text to the client
Modified by Dale R. Thompson
10/16/17 converted to Python 3
'''
#Sebastian Vivo UAID 010249203

import sys

# Import socket library
from socket import *

# Set port number by converting argument string to integer
# If no arguments set a default port number
# Defaults
if sys.argv.__len__() != 2:
    serverPort = 5556
# Get port number from command line
else:
    serverPort = int(sys.argv[1])

print(serverPort)
# Choose SOCK_DGRAM, which is UDP
serverSocket = socket(AF_INET, SOCK_DGRAM)

# The SO_REUSEADDR flag tells the kernel to reuse a local socket
# in TIME_WAIT state, without waiting for its natural timeout to expire.
serverSocket.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)

# Start listening on specified port
serverSocket.bind(('', serverPort))

print("The server is ready to receive")
command = 0
balance = 100
amount = 0
# Forever, read in sentence, convert to uppercase, and send
while 1:
    # Return and decode command
    commandBytes, clientAddress = serverSocket.recvfrom(2048)
    command = int(commandBytes.decode('utf-8'))

    if command == 1 or command == 2:
        # Return data and address and decode amount
        amountBytes, clientAddress = serverSocket.recvfrom(2048)
        amount = int(amountBytes.decode('utf-8'))

    if command == 1:
        # Deposit into account
        balance = balance + amount

    elif command == 2:
        # Withdraw from account
        balance = balance - amount

    if command > 0 and command < 4:
        # Encode balance and send back to client
        balanceBytes = str(balance).encode('utf-8')
        serverSocket.sendto(balanceBytes, clientAddress)

    else:
        break

print("Closing Server...")
serverSocket.close()
