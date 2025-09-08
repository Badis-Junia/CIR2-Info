# Makefile pour TD1
# Usage: make [target]

# Compilateur et flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic
LDFLAGS = -lm  # Ajout de la bibliothèque mathématique

# Exécutables à construire
EXECUTABLES = TD1_1 TD1_2 TD1_3 TD1_4 TD1_5 TD1_7 TD1_8

# Sources
TD1_1_SRC = EXO1/main.c
TD1_2_SRC = EXO2/main.c
TD1_3_SRC = EXO3/main.c
TD1_4_SRC = EXO4/main.c
TD1_5_SRC = EXO5/main.c
TD1_7_SRC = EXO7/main.c
TD1_8_SRC = EXO8/main.c

.PHONY: all clean

all: $(EXECUTABLES)

# Règles de compilation
TD1_1: $(TD1_1_SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

TD1_2: $(TD1_2_SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

TD1_3: $(TD1_3_SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

TD1_4: $(TD1_4_SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

TD1_5: $(TD1_5_SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

TD1_7: $(TD1_7_SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

TD1_8: $(TD1_8_SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Nettoyage
clean:
	rm -f $(EXECUTABLES) *~
	for dir in EXO1 EXO2 EXO3 EXO4 EXO5 EXO6 EXO7 EXO8; do \
		rm -f $$dir/*~; \
	done

# Aide
help:
	@echo "Makefile pour TD1"
	@echo "Cibles disponibles:"
	@echo "  all    : compile tous les exercices"
	@echo "  TD1_1  : compile l'exercice 1"
	@echo "  TD1_2  : compile l'exercice 2"
	@echo "  ..."
	@echo "  clean  : nettoie tous les fichiers compilés"
