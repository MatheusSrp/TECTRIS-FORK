#include "stats.h"
#include <math.h> // Para sqrtf e powf
#include <stdio.h> // Para sprintf

// Implementação das funções de estatísticas
float CalculateAverageScore(MatchHistory *history, int count) {
    if (count == 0) return 0.0f;
    long totalScore = 0;
    for (int i = 0; i < count; i++) {
        totalScore += history[i].score;
    }
    return (float)totalScore / count;
}
int CalculateBestScore(MatchHistory *history, int count) {
    if (count == 0) return 0;
    int best = history[0].score;
    for (int i = 1; i < count; i++) {
        if (history[i].score > best) {
        best = history[i].score;
        }
    }
    return best;
}
int CalculateWorstScore(MatchHistory *history, int count) {
    if (count == 0) return 0;
    int worst = history[0].score;
    for (int i = 1; i < count; i++) {
        if (history[i].score < worst) {
            worst = history[i].score;
        }
    }
    return worst;
}

float CalculateStandardDeviation(MatchHistory *history, int count,
float average) {
    if (count <= 1) return 0.0f;
    float sumOfSquaredDifferences = 0.0f;
    for (int i = 0; i < count; i++) {
        sumOfSquaredDifferences += powf(history[i].score - average, 2);
    }
    return sqrtf(sumOfSquaredDifferences / (count - 1));
}

// Funções recursivas (stubs - serão implementadas pelo Dev 3)
int RecursiveSum(int *arr, int n) { return 0; /* Implementar
recursivamente */ }
int RecursiveMax(int *arr, int n) { return 0; /* Implementar
recursivamente */ }
int RecursiveMin(int *arr, int n) { return 0; /* Implementar
recursivamente */ }
long RecursiveSquareSum(int *arr, int n) { return 0; /* Implementar
recursivamente */ }
// Função para gerar heurísticas (stub - será implementada pelo Dev 4)
void GenerateHeuristic(GameStats *stats) {
    sprintf(stats->heuristicMessage, "Analise de desempenho em andamento...");
}