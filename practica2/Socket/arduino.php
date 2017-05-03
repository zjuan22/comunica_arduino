<?php

// $sock - Variável declarada para ciração do socket;
// socket_create - Função nativa do PHP para habilitar o novo socket;
// http://php.net/manual/pt_BR/function.socket-create.php - Tutorial completo sobre a função socket_create e seus parâmetros;
$sock = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);

// socket_connect - Função que irá conectar o web socket desenvolvido em PHP com o Arduino;
// Parâmetros do socket_connect - (Nome do scoket, IP do Arduino, Porta);
socket_connect($sock,"192.168.0.101", 99);

// Estrutura de seleção que receberá as requisições da interface web(index.html) e associar com o parâmetro do $_POST['estadoLed'];
//if ($_POST['estadoLed']=="lverde_ligado")
//{
//	// socket_write - Função nativa do PHP que enviará via socket o valor("1") para estrutura de seleção(switch (client.read()) do arduino,
//	// para acionamento do LED;
//    socket_write($sock, "0");
//}
//if ($_POST['estadoLed']=="lvermelho_ligado")
//{
//    socket_write($sock, "1");
//}
//if ($_POST['estadoLed']=="lverde_desligado")
//{
//    socket_write($sock, "9");
//}
//if ($_POST['estadoLed']=="lvermelho_desligado")
//{
//    socket_write($sock, "4");
//}
//echo 'Thank you '. ' ' . $_POST['vl_led1'] . ', says the PHP file';
//echo 'Thank you ';
//recojo el valor y lo saco por pantalla
if(isset($_POST["vl_led1"])){

    //echo "la edad recibida es: " .$_POST['edad'];
    echo "Number of selected passengers are:".$_POST["vl_led1"];
    //socket_write($sock, "1");
    //socket_write($sock, $_POST['vled1']);
    socket_write($sock, "1 ".$_POST['vl_led1']);

} 
else if(isset($_POST["foco"])){
      echo 'Thank you '. ' ' . $_POST['foco'] ;

//    echo "Number of selected passengers are:"]
    //echo "Number of selected passengers are:".$_POST["foco"]
//    //socket_write($sock, $_POST['vled1']);
      socket_write($sock, "2 ".$_POST['foco']);

}

else{
      Echo "Please slide the Slider Bar and Press Submit.";
}

// header - Função nativa do PHP que retorna a index.html após acionamento dos botões;
//header("Location: index.html");

// socket_close - Função nativa do PHP que encerra a conexão com o socket;

//echo "Reading response:\n\n";
//while ($out = socket_read($sock, 2048)) {
//    echo $out;
//}

socket_close($sock);

?>   
