<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Dados de Nível</title>
</head>
<body>
    <h1>Dados de Nível</h1>
    <table border="1">
        <thead>
            <tr>
                <th>Data e Hora</th>
                <th>Nível (°C)</th>
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
</body>
</html>