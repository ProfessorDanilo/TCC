from flask import Flask, render_template
import serial

app = Flask(__name__)


# Configuração da porta serial
port = 'COM9'  # Substitua pelo nome da porta COM do Arduino
baudrate = 9600

# Abre a porta serial
ser = serial.Serial(port, baudrate)

@app.route('/')
def index():
    # Lê os dados da porta serial
    #data = ser.readline().decode().strip()
    return render_template('index.html', data="teste")

if __name__ == '__main__':
    app.run(debug=True)
