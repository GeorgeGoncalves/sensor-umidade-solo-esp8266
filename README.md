# 🌱 Sensor de Umidade do Solo com ESP8266 (Wi-Fi)

Projeto de **sensor de umidade do solo** utilizando **ESP8266 (NodeMCU)**, desenvolvido com foco em **aprendizado prático** em eletrônica, programação e Internet das Coisas (IoT).

O sistema realiza a leitura da umidade do solo, converte o valor para **porcentagem** e exibe os dados em uma **página web acessível via Wi-Fi**, com indicação visual do estado do solo.

---

## 🎯 Objetivo do Projeto

- Aprender a utilizar o ESP8266 com Wi-Fi
- Realizar leitura analógica de sensores
- Converter dados brutos em informação útil (%)
- Criar um servidor web simples com HTML e CSS
- Dar os primeiros passos em projetos de IoT

---

## 🧰 Componentes Utilizados

- ESP8266 (NodeMCU)
- Sensor de umidade do solo (YL-69 + módulo)
- Fios jumper

---

## ▶️ Como clonar e executar o projeto

### 1️⃣ Clonar o repositório

No terminal, execute:

```bash
git clone https://github.com/SEU_USUARIO/sensor-umidade-solo-esp8266.git
```

Depois, entre na pasta do projeto:

```bash
cd sensor-umidade-solo-esp8266
```

2️⃣ Abrir o projeto na Arduino IDE

- Abra a Arduino IDE

- Clique em Arquivo → Abrir

- Selecione o arquivo .ino do projeto

3️⃣ Configurar o Wi-Fi

No código, altere as linhas abaixo com o nome e a senha da sua rede Wi-fI:

const char* ssid = "SEU_WIFI";
const char* password = "SUA_SENHA";

4️⃣ Conectar o hardware

Faça as ligações do sensor de umidade:

| Sensor | ESP8266 |
|------  |-------- |
| VCC    |   3V3   |
| GND    |   GND   |
| AO     |   A0    |

5️⃣ Fazer upload do código

- Selecione a placa correta em Ferramentas → Placa (ex: NodeMCU 1.0)

- Selecione a porta correta

- Clique em Upload

6️⃣ Acessar o projeto no navegador

- Abra o Monitor Serial (9600 baud)

- Copie o IP exibido

- No navegador (mesma rede Wi-Fi), acesse:

http://IP_DO_ESP

Pronto 🎉
A página com a umidade do solo será exibida no navegador.

---

## 💻 Funcionamento do Sistema

1. O ESP8266 conecta à rede Wi-Fi
2. Cria um servidor web na porta 80
3. Lê o valor analógico do sensor de umidade
4. Converte o valor para porcentagem (0 a 100%)
5. Exibe as informações em uma página web

---

## 🌈 Classificação da Umidade do Solo

| Umidade (%) | Estado do Solo | Cor       |
|------------|--------------|------------- |
|   < 30%    |      Seco    | 🔴 Vermelho |
| 31% – 80%  | Normal | 🟤 Marrom (terra) |
| 81% – 100% | Úmido        |   🟢 Verde  |

---

## 📊 Conversão do Sensor

O valor lido pelo `analogRead()` varia de **0 a 1023**.  
Esse valor é convertido para porcentagem usando a função `map()`.

- Solo seco → valor alto
- Solo úmido → valor baixo

---

## 🌐 Interface Web

- Página acessível pelo navegador
- Exibição da umidade em porcentagem
- Cores dinâmicas conforme o estado do solo

---

## 🧠 Observações

Este projeto foi desenvolvido como estudo e hobby, sendo indicado para quem está começando na área de eletrônica, programação e Internet das Coisas.

---

## 📄 Licença

Este projeto é de livre uso para fins educacionais.
