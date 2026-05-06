#include "history.h"
#include "common.h"
#include <stdio.h>

void SaveHistory(MatchHistory data) {
    FILE *file = fopen(HISTORY_FILE, "a");
    if (file == NULL) {
        TraceLog(LOG_WARNING, "HISTORY: Nao foi possivel abrir o arquivo de historico para escrita.");
        return;
    }
    fprintf(file, "%d,%d,%d,%ld\n", data.score, data.lines, data.level, data.timestamp);
    fclose(file);
    TraceLog(LOG_INFO, "HISTORY: Partida salva no historico.");
}