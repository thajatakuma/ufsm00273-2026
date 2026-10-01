# ufsm00273-2026

Desenvolvimento do robô móvel como parte da disciplina de Projeto Integrador em Engenharia de Computação I.

## 🛠️ Hardware

### Componentes

| Componente | Modelo |
|------------|--------|
| Microcontrolador | Raspberry Pi Pico |
| Driver de Motor | L298N |
| Motor | MDCR3-6V |
| LED | RGB (cátodo/ânodo comum) |
| Carregador de Bateria | TP4056 |

## 🎯 Funcionalidades

### API do Firmware

| Função | Descrição |
|--------|-----------|
| `MoverRodaEsquerda(velocidade)` | Move a roda esquerda (Motor A) |
| `MoverRodaDireita(velocidade)` | Move a roda direita (Motor B) |
| `LigarLed(r, g, b)` | Aciona o LED RGB |

### Comportamentos

- [x] Mover roda esquerda (frente/trás com velocidade variável)
- [x] Mover roda direita (frente/trás com velocidade variável)
- [x] Ligar LED RGB (controle de cor)
