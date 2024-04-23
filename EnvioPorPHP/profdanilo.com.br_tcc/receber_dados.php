<?php
// Verificar se os dados foram enviados via POST
if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['temperatura'])) {
    // Receber os dados de temperatura
    $temperatura = $_POST['temperatura'];

    // Faça o que desejar com os dados, como salvar em um banco de dados ou arquivo

    // Exemplo: Salvar em um arquivo
    $arquivo = 'temperatura.txt';
    $dados = date('Y-m-d H:i:s') . ',' . $temperatura . "\n";
    file_put_contents($arquivo, $dados, FILE_APPEND);

    // Responder ao cliente que os dados foram recebidos com sucesso
    echo 'Dados recebidos com sucesso.';
} else {
    // Se os dados não foram recebidos corretamente, responder com erro
    http_response_code(400);
    echo 'Erro: Dados não recebidos.';
}
?>
