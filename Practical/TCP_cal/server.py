
import socket

host = "127.0.0.1"
port = 5000

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

server_socket.bind((host, port))
server_socket.listen(1)

print("Waiting for client connection...")

data, addr = server_socket.accept()
print("Connected to:", addr)

# Receive calculation request
message = data.recv(1024).decode()

# Separate numbers and operator
num1, operator, num2 = message.split()

num1 = float(num1)
num2 = float(num2)

# Perform calculation
if operator == '+':
    result = num1 + num2

elif operator == '-':
    result = num1 - num2

elif operator == '*':
    result = num1 * num2

elif operator == '/':
    if num2 == 0:
        result = "Cannot divide by zero"
    else:
        result = num1 / num2

else:
    result = "Invalid operator"

# Display result on server
print("Calculation:", num1, operator, num2)
print("Result:", result)

# Send result to client
data.send(str(result).encode())

data.close()
server_socket.close()
