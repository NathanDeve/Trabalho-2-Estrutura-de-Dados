INSTRUÇÕES DE EXECUÇÃO (SEMINÁRIO AED-I)

Linguagem: C (Padrão C99)
Compilador: gcc

1. Para compilar o código que contém os algoritmos e o mini-experimento:
gcc ordenacao.c -o executavel -lm

(Nota: A flag -lm é incluída para compatibilidade futura com 'math.h', se necessário).

2. Para executar o mini-experimento (Roteiro 8):
./executavel

3. Para executar a demonstração ao vivo (Roteiro 3):
(Opcional, se você criar um 'demo.c' separado)
gcc demo.c -o demo
./demo