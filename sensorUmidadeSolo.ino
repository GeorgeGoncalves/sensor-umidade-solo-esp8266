// Biblioteca para conexão Wi-Fi no ESP8266
#include <ESP8266WiFi.h>

// Biblioteca que facilita a criação de servidor web
// Permite usar server.on(), rotas e respostas HTTP prontas
#include <ESP8266WebServer.h>

// Nome da rede Wi-Fi
const char* ssid = "NJG";

// Senha da rede Wi-Fi
const char* password = "floripa31";

// Cria um servidor web na porta 80 (porta padrão HTTP)
ESP8266WebServer server(80);

// Função responsável por responder quando alguém acessa "/"
void handleRoot() {

  // Lê o valor analógico do sensor de umidade
  // O valor varia de 0 a 1023
  int sensor = analogRead(A0);

  // Converte o valor para porcentagem (0 a 100%)
  // Solo seco → valor alto
  // Solo úmido → valor baixo
  int umidade = map(sensor, 1023, 0, 0, 100);

  // Variáveis que armazenam o estado do solo e a cor
  String statusSolo;
  String cor;

  // Define o status e a cor conforme a porcentagem
  if (umidade < 30) {
    statusSolo = "Seco";
    cor = "red";
  } else if (umidade <= 80) {
    statusSolo = "Normal";
    cor = "#8B4513";  // cor de terra (marrom)
  } else {
    statusSolo = "Úmido";
    cor = "green";
  }

  // Criação da página HTML
  String html = "<!DOCTYPE html><html><head>";

  // Define o padrão de caracteres (evita erro de acentuação)
  html += "<meta charset='UTF-8'>";

  // Título da página
  html += "<title>Umidade do Solo</title>";

  // Estilo CSS simples para melhorar a aparência
  html += "<style>";
  html += "body{font-family:Arial;text-align:center;background:#f2f2f2;}";
  html += ".card{background:#fff;padding:20px;margin:50px auto;width:300px;border-radius:10px;}";
  html += ".valor{font-size:40px;color:" + cor + ";}";
  html += "</style>";

  html += "</head><body>";

  // Conteúdo da página
  html += "<div class='card'>";
  
  // Imagem ilustrativa
  html += "<img src='data:image/png;base64,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' alt='Umidade' width='100'><br><br>";

  html += "<h1>Sensor de Umidade</h1>";
  html += "<p class='valor'>" + String(umidade) + "%</p>";
  html += "<p>Status do solo: <strong style='color:" + cor + ";'>" + statusSolo + "</strong></p>";
  html += "</div>";

  html += "</body></html>";

  // Envia a resposta HTTP para o navegador
  // Código 200 = OK
  server.send(200, "text/html", html);
}

void setup() {
  // Inicia a comunicação serial
  Serial.begin(9600);

  // Inicia a conexão com a rede Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Conectando ao WiFi");

  // Aguarda até a conexão ser estabelecida
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Confirma conexão e exibe o IP do ESP8266
  Serial.println("\nWiFi conectado!");
  Serial.print("IP do ESP: ");
  Serial.println(WiFi.localIP());

  // Define a rota principal "/"
  // Quando alguém acessar o IP, chama a função handleRoot()
  server.on("/", handleRoot);

  // Inicia o servidor web
  server.begin();
}

void loop() {
  // Mantém o servidor web funcionando
  // Essa função deve estar sempre no loop
  server.handleClient();
}
