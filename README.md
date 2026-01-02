# 🌱 Sensor de Umidade do Solo com ESP8266

Projeto simples de **sensor de umidade do solo** utilizando o **ESP8266 (NodeMCU)**, desenvolvido com foco em **aprendizado e prática** para iniciantes em eletrônica e IoT.

Este projeto realiza a leitura da umidade do solo através de um sensor analógico e exibe os valores no **Monitor Serial** da Arduino IDE.

---

## 📚 Objetivo do Projeto

- Aprender a utilizar o ESP8266
- Realizar leitura analógica com sensor de umidade do solo
- Entender o funcionamento básico de sensores
- Dar os primeiros passos em projetos de IoT

---

## 🧰 Componentes Utilizados

- ESP8266 (NodeMCU)
- Sensor de umidade do solo (YL-69 + módulo)
- Fios jumper

---

## 🔌 Ligações do Circuito

| Sensor | ESP8266 |
|------  |-------- |
| VCC    |   3V3   |
| GND    |   GND   |
| AO     |   A0    |

⚠️ **Atenção:** Utilize apenas a saída analógica (AO) do sensor.

---

## 🔍 Funcionamento

- O sensor mede a resistência elétrica do solo
- Solo seco → valor alto
- Solo úmido → valor baixo
- Os valores são exibidos no Monitor Serial a cada 2 segundos

---

## 🧠 Observações

Este projeto foi desenvolvido como estudo e hobby, sendo indicado para quem está começando na área de eletrônica, programação e Internet das Coisas.

---

## 📄 Licença

Este projeto é de livre uso para fins educacionais.
