CC = gcc
CFLAGS = -g

SRCDIR = src
OUTDIR = out

LIBDIR = src/lib
LIBFILES = $(wildcard $(LIBDIR)/*.c)

# --- Regras para compilar listas específicas ---

# Padrão genérico para compilar uma lista
# Ex: make lista-1, make lista-2, etc.
lista-%:
	@echo "Compilando a $@..."
	@echo ""

	$(eval LISTA_SRCDIR = $(SRCDIR)/$@)
	$(eval LISTA_OUTDIR = $(OUTDIR)/$@)

	@mkdir -p $(LISTA_OUTDIR)

	$(eval TARGETS = $(patsubst $(LISTA_SRCDIR)/%.c, $(LISTA_OUTDIR)/%, $(wildcard $(LISTA_SRCDIR)/*.c)))
	$(MAKE) $(TARGETS)

	@echo ""
	@echo "Compilação de $@ concluída."
	@echo ""

	@echo -ne $(foreach target, $(TARGETS),\
		"\bExecute: " && echo -nE "'$(target)' " && echo -ne "para testar.\n"\
	)


# Padrão genérico para compilar arquivos de C da pasta SRCDIR em binário na pasta OUTDIR
# Ex: make out/lista-x/exercicio -> Compilando exercicio.c para out/lista-x/exercicio
$(OUTDIR)/% : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $< $(LIBFILES) -I$(LIBDIR) -o $@

# --- Tasks Auxiliares ---

.PHONY: help
help:
	@echo "Uso:"
	@echo "  make lista-<nome_da_lista>   - Compila todos os arquivos .c da lista especificada (ex: make lista-1)"
	@echo "  make clean                   - Remove todos os arquivos compilados do diretório 'out/'"
	@echo "  make help                    - Exibe esta mensagem de ajuda"

.PHONY: clean
clean:
	@echo "Limpando diretórios de saída..."
	rm -rf $(OUTDIR)/*
	@echo "Limpeza concluída."