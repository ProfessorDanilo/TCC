# TCC

## Sistemas operacionais onde funcionou
Funcionou no Ubuntu e raspbery pi 4
Não funcionou no windows

## Biblioteca Heltec não funcionou
Infelizmente a biblioteca Heltec não funciou. Esta foi substituida por u8g2.h
Usando a frequência de 915 MHz
Parte do uso do OLed feita.
Pastas com OK no final foram concluídas para o emissor e para o receptor.

## Próximos passos
### Programar o sensor
LoRa ligado ao sensor programado, enviando sinal via rádio, apresentando valores no display.

### Programar o emissor e o receptor
Emissor e receptor programados. Receptor consegue receber sinal até aproximadamente 1 km.
Receptor recebe sinal, printa no display, envia via serial e exibe intensidade do sinal.
Pede-se comunicação quando o sinal fica em -119 (acho que é decibeis, mas não sei a referencia ainda)

### Concertar o sensor
O sensor está com defeito. Vou refazê-lo.

### Comunicação via python
Comunicação via python ok. Não funcionou no windows: constava que a biblioteca serial não opissui nada chamado Serial. Não encontrei o conflito. Mas rodou no Ubuntu.
Usando flask para atualizar página html.

### Desenvolver o dashboard
Ainda por fazer.
