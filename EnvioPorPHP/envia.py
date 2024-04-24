import requests
import time
import serial

#porta de comunicação serial
port = '/dev/ttyUSB0'
#velocidade de comunicação serial
baudrate = 9600

# URL do formulário PHP
url = 'https://profdanilo.com.br/tcc/receber_nivel.php'  
contador = 0
try:
    while True:
        # Abre a porta serial
        ser = serial.Serial(port, baudrate)

        # Ler dados da porta serial
        data = ser.readline().decode().strip()
        time.sleep(1)
        ser.close()

        # Enviar dados para o servidor via requisição POST
        payload = {'nivel': data}  # Dados a serem enviados para o servidor
        response = requests.post(url, data=payload)

        # Verificar se a requisição foi bem sucedida
        if response.status_code == 200:
            contador += 1
            print('Dados enviados com sucesso (',contador,'):',  data)
        else:
            print('Erro ao enviar dados:', response.text)

except KeyboardInterrupt:    
    print("Falha ao enviar o arquivo")
