CC = gcc
CFLAGS = -g

SRCDIR = src
OUTDIR = out

LIBDIR = $(SRCDIR)/lib
LIBFILES = $(wildcard $(LIBDIR)/*.c)

EXERDIR = $(SRCDIR)/atividades
EXERCICIOS = $(patsubst $(EXERDIR)/%/, %, $(dir $(wildcard $(EXERDIR)/*/ )))

all:
	make $(EXERCICIOS)

# --- Regras para compilar listas e atividades específicas ---

# Padrão genérico para compilar uma lista
# Ex: make lista-1, make lista-2, make atividade-1-P2 e etc.
$(EXERCICIOS):
	@echo "Compilando a $@..."

	$(eval LISTA_SRCDIR = $(EXERDIR)/$@)
	$(eval LISTA_OUTDIR = $(OUTDIR)/$@)

	@mkdir -p $(LISTA_OUTDIR)

	$(eval TARGETS = $(patsubst $(LISTA_SRCDIR)/%.c, $(LISTA_OUTDIR)/%, $(wildcard $(LISTA_SRCDIR)/*.c)))
	$(MAKE) $(TARGETS)

	@echo ""
	@echo "Compilação de $@ concluída."
	@echo ""

	@echo "Para executar os programas compilados, use:"
	@echo "  cd $(LISTA_OUTDIR)"
	@echo "  ls"
	@echo "  ./<nome_do_programa>"
	@echo ""

# Padrão genérico para compilar arquivos de C da pasta SRCDIR em binário na pasta OUTDIR
# Ex: make out/lista-x/exercicio -> Compilando exercicio.c para out/lista-x/exercicio
$(OUTDIR)/% : $(EXERDIR)/%.c
	$(CC) $(CFLAGS) $< $(LIBFILES) -I$(LIBDIR) -o $@

# --- Tasks Auxiliares ---

.PHONY: help
help:
	@echo "Uso:"
	@echo "  make   					  - Compila todas as atividades"
	@echo "  make lista-<nome_da_lista>   - Compila todos os arquivos .c da lista especificada (ex: make lista-1)"
	@echo "  make clean                   - Remove todos os arquivos compilados do diretório 'out/'."
	@echo "  make help                    - Exibe esta mensagem de ajuda"

.PHONY: clean
clean:
	@echo "Limpando diretórios de saída..."
	rm -rf $(OUTDIR)/*
	@echo "Limpeza concluída."