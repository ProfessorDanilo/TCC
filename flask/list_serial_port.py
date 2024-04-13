import serial.tools.list_ports

# Obtém uma lista de portas seriais disponíveis
ports = serial.tools.list_ports.comports()

# Itera sobre as portas seriais e imprime suas informações
for port in ports:
    print(f"Nome: {port.name}, Descrição: {port.description}, Localização: {port.device}")