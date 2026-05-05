#include "common.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Banco de dados de perguntas com múltiplas respostas válidas
static Question questionBank[] = {
    {"Qual e a saida de: printf(\"%d\", 5 + 3);", {"8"}, 1, 1},
    {"Qual funcao usamos para imprimir na tela em C?", {"printf", "printf()"}, 2, 1},
    {"Qual tipo de dado armazena numeros inteiros em C?", {"int"}, 1, 1},
    {"Em C, qual simbolo indica o final de uma instrucao?", {";", "ponto e virgula"}, 2, 1},
    {"Qual palavra inicia a funcao principal de um programa em C?", {"main", "main()"}, 2, 1},
    {"Qual simbolo usamos para comentario de uma linha em C?", {"//"}, 1, 1},
    {"Em C, qual palavra-chave usamos para criar uma condicao?", {"if"}, 1, 2},
    {"Qual e o resultado de: 2 + 2 * 3?", {"8"}, 1, 2},
    {"Qual palavra-chave e usada para repetir codigo em C?", {"for", "while", "do"}, 3, 2},
    {"Qual operador compara igualdade em C?", {"=="}, 1, 2},
    {"Qual palavra-chave sai de um loop em C?", {"break"}, 1, 2},
    {"Qual operador usamos para obter o endereco de uma variavel?", {"&"}, 1, 3},
    {"Qual palavra-chave define uma estrutura em C?", {"struct"}, 1, 3},
    {"Qual operador ternario representa if-else em C?", {"?"}, 1, 3}
};

static int bankSize = sizeof(questionBank) / sizeof(Question);

Question GetRandomQuestion(int level) {
    int count = 0;
    for(int i=0; i<bankSize; i++) if(questionBank[i].level <= level) count++;
    
    if (count == 0) return questionBank[0];

    int r = rand() % count;
    int current = 0;
    for(int i=0; i<bankSize; i++) {
        if(questionBank[i].level <= level) {
            if(current == r) return questionBank[i];
            current++;
        }
    }
    return questionBank[0];
}

// Função de Trim Robusta: Remove espaços APENAS no início e no fim
static char* trim(char* str) {
    char* end;
    // Leading spaces
    while(isspace((unsigned char)*str)) str++;
    if(*str == 0) return str;
    // Trailing spaces
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;
    end[1] = '\0';
    return str;
}

// Validação Case-Insensitive e Multi-Resposta (Preserva espaços internos)
bool ValidateAnswer(const char* user, const Question* q) {
    if (user == NULL || q == NULL) return false;

    char u_copy[128];
    strncpy(u_copy, user, 127);
    u_copy[127] = '\0';
    
    char* u_trimmed = trim(u_copy);
    
    for(int i = 0; i < q->answerCount; i++) {
        char c_copy[128];
        strncpy(c_copy, q->answers[i], 127);
        c_copy[127] = '\0';
        char* c_trimmed = trim(c_copy);
        
        // Comparação case-insensitive usando stricmp (Windows) ou strcasecmp (Linux)
        #ifdef _WIN32
        if (_stricmp(u_trimmed, c_trimmed) == 0) return true;
        #else
        if (strcasecmp(u_trimmed, c_trimmed) == 0) return true;
        #endif
    }
    
    return false;
}
