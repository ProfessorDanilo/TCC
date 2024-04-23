import requests
import random
import time


# URL do formulário PHP
url = 'https://profdanilo.com.br/tcc/receber_dados.php'  # Substitua 'seusite.com' pela URL do seu site

try:
    while True:
        # Ler dados da porta serial
        temperatura = random.randint(7, 35)

        # Enviar dados para o servidor via requisição POST
        payload = {'temperatura': temperatura}  # Dados a serem enviados para o servidor
        response = requests.post(url, data=payload)

        # Verificar se a requisição foi bem sucedida
        if response.status_code == 200:
            print('Dados enviados com sucesso:', temperatura)
        else:
            print('Erro ao enviar dados:', response.text)
        time.sleep(5)

except KeyboardInterrupt:
    print("Falha ao enviar o arquivo")
