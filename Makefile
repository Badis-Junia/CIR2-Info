# Makefile pour le projet TDs
# Usage: make [target]

# Compilateur et flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic
LDFLAGS = 

# Répertoires
TD_DIRS = TD1 TD2 TD3 TD4
EXO_DIRS = EXO1 EXO2 EXO3 EXO4 EXO5 EXO6 EXO7 EXO8

# Cibles principales
.PHONY: all clean $(TD_DIRS)

all: $(TD_DIRS)

# Règles pour chaque TD
TD1:
	$(MAKE) -C TD1

TD2:
	$(MAKE) -C TD2

TD3:
	$(MAKE) -C TD3

TD4:
	$(MAKE) -C TD4

# Nettoyage
clean:
	for dir in $(TD_DIRS); do \
		$(MAKE) -C $$dir clean; \
	done
	rm -f *~

# Règle pour aider
help:
	@echo "Makefile pour le projet TDs"
	@echo "Cibles disponibles:"
	@echo "  all      : compile tous les TDs"
	@echo "  TD1      : compile seulement le TD1"
	@echo "  TD2      : compile seulement le TD2"
	@echo "  TD3      : compile seulement le TD3"
	@echo "  TD4      : compile seulement le TD4"
	@echo "  clean    : nettoie tous les fichiers compilés"
	@echo "  help     : affiche cette aide"
