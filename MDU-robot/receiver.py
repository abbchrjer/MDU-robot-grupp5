import socket

host = "192.168.1.77"
port = 80

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((host, port))

while True:
    try:
        data = client.recv(1024)
        if data: 
            print(data.decode('utf-8'))
    except Exception as e:
        print(f"An error occurred: {str(e)}")