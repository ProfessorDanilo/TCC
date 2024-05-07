<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Dados de Nível</title>
    <!-- Inclui a biblioteca Chart.js -->
    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
</head>
<body>
    <h1>Dados de Nível</h1>
    
    <!-- Dropdown para escolher o tipo de visualização -->
    <label for="tipo_visualizacao">Escolha o tipo de visualização:</label>
    <select id="tipo_visualizacao" onchange="mostrarVisualizacao()">
        <option value="tabela">Tabela</option>
        <option value="grafico">Gráfico</option>
    </select>
    
    <!-- Div para exibir a tabela -->
    <div id="tabela" style="display: block;">
        <table border="1">
            <thead>
                <tr>
                    <th>Data e Hora</th>
                    <th>Nível (%)</th>
                </tr>
            </thead>
            <tbody>
                <?php
                // Ler o conteúdo do arquivo nivel.txt e exibir na tabela
                $arquivo = 'nivel.txt';
                if (file_exists($arquivo)) {
                    $linhas = file($arquivo, FILE_IGNORE_NEW_LINES);
                    foreach ($linhas as $linha) {
                        list($dataHora, $nivel) = explode(',', $linha);
                        echo "<tr><td>$dataHora</td><td>$nivel</td></tr>";
                    }
                } else {
                    echo '<tr><td colspan="2">Nenhum dado disponível.</td></tr>';
                }
                ?>
            </tbody>
        </table>
    </div>
    
    <!-- Div para exibir o gráfico -->
    <div id="grafico" style="display: none;">
        <canvas id="graficoNivel"></canvas>
    </div>
    
    <!-- Script para mostrar a visualização selecionada -->
    <script>
        function mostrarVisualizacao() {
            var tipoVisualizacao = document.getElementById("tipo_visualizacao").value;
            if (tipoVisualizacao === "tabela") {
                document.getElementById("tabela").style.display = "block";
                document.getElementById("grafico").style.display = "none";
            } else if (tipoVisualizacao === "grafico") {
                document.getElementById("tabela").style.display = "none";
                document.getElementById("grafico").style.display = "block";
                // Chama a função para desenhar o gráfico
                desenharGrafico();
            }
        }
        
        function desenharGrafico() {
            // Obtém os dados do arquivo nivel.txt
            var dados = <?php echo json_encode($linhas); ?>;
            var tempos = [];
            var niveis = [];
            // Extrai os tempos e níveis dos dados
            for (var i = 0; i < dados.length; i++) {
                var partes = dados[i].split(",");
                tempos.push(partes[0]);
                niveis.push(parseFloat(partes[1]));
            }
            // Cria o gráfico usando Chart.js
            var ctx = document.getElementById('graficoNivel').getContext('2d');
            var grafico = new Chart(ctx, {
                type: 'line',
                data: {
                    labels: tempos,
                    datasets: [{
                        label: 'Nível (%)',
                        data: niveis,
                        backgroundColor: 'rgba(255, 99, 132, 0.2)',
                        borderColor: 'rgba(255, 99, 132, 1)',
                        borderWidth: 1
                    }]
                },
                options: {
                    scales: {
                        yAxes: [{
                            ticks: {
                                beginAtZero: true
                            }
                        }]
                    }
                }
            });
        }
    </script>
</body>
</html>
